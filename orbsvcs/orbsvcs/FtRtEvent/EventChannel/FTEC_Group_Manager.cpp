// $Id$

#include "FTEC_Group_Manager.h"
#include "ace/Synch_T.h"
#include "Replication_Service.h"
#include "Fault_Detector.h"
#include "IOGR_Maker.h"
#include "GroupInfoPublisher.h"

ACE_RCSID (EventChannel,
           TAO_FTEC_Group_Manager,
           "$Id$")


inline bool operator == (const TAO_String_Manager& lhs, const TAO_String_Manager& rhs)
{
    return strcmp(lhs.in(), rhs.in()) == 0;
}

inline bool operator == (const CosNaming::NameComponent& lhs, const CosNaming::NameComponent& rhs)
{
    if (lhs.id == rhs.id) {
        if (lhs.kind == rhs.kind)
          return true;
    }
    return false;
}

bool operator == (const FTRT::Location& lhs, const FTRT::Location& rhs)
{
    if (lhs.length() == rhs.length()) {
        for (unsigned i = 0; i < lhs.length(); ++i)
            if (!(lhs[i] == rhs[i]))
                return false;
        return true;
    }
    return false;
}

int find_by_location(const FTRT::ManagerInfoList& list,
                const FTRT::Location & location)
{
    unsigned i;
    for (i = 0; i < list.length(); ++i) {
        if (list[i].the_location == location) {
            return i;
        }
    }
    return i;
}

/*
void print(const FTRT::Location& location)
{
  ACE_DEBUG((LM_DEBUG, "{"));
  for (size_t i = 0; i < location.length(); ++i) {
    ACE_DEBUG((LM_DEBUG, "<%s,%s>", location[i].id.in(), location[i].kind.in()));
  }
  ACE_DEBUG((LM_DEBUG, "}"));
}
*/

struct TAO_FTEC_Group_Manager_Impl
{
  FTRT::ManagerInfoList info_list;
  unsigned my_position;
  FTRT::FaultListener_var listener;
};

TAO_FTEC_Group_Manager::TAO_FTEC_Group_Manager()
: impl_(new TAO_FTEC_Group_Manager_Impl)
{
  Fault_Detector::instance()->set_listener(this);
}

TAO_FTEC_Group_Manager::~TAO_FTEC_Group_Manager()
{
  delete impl_;
}

CORBA::Boolean TAO_FTEC_Group_Manager::start (
        FTRT::FaultListener_ptr listener,
        FTRT::Location_out cur
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ))
{
  impl_->listener = listener;
  ACE_NEW_RETURN(cur , FTRT::Location(Fault_Detector::instance()->my_location()), false);
  return true;
}


void TAO_FTEC_Group_Manager::create_group (
    const FTRT::ManagerInfoList & info_list,
    CORBA::ULong object_group_ref_version
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
{
  ACE_DEBUG((LM_DEBUG, "create_group\n"));
  IOGR_Maker::instance()->set_ref_version( object_group_ref_version );

  impl_->info_list = info_list;
  impl_->my_position = find_by_location(info_list,
    Fault_Detector::instance()->my_location());

  GroupInfoPublisherBase* publisher = GroupInfoPublisher::instance();

  publisher->update(impl_->info_list, impl_->my_position
                    ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  FtRtecEventChannelAdmin::EventChannel_var  successor
    = publisher->successor();

  if (!CORBA::is_nil(successor.in())) {
    successor->create_group(info_list, object_group_ref_version
                            ACE_ENV_ARG_PARAMETER);
    ACE_CHECK;
  }

  if (impl_->my_position > 0) {
    Fault_Detector* detector = Fault_Detector::instance();
    if ( detector->connect(impl_->info_list[impl_->my_position-1].the_location) == -1) {
      ACE_DEBUG((LM_DEBUG, "Cannot connect to predecesor\n"));
      ACE_THROW(FTRT::PredecessorUnreachable());
    }
  }
}

void TAO_FTEC_Group_Manager::join_group (
    const FTRT::ManagerInfo & info
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
{
  ACE_DEBUG((LM_DEBUG, "join group\n"));
  if (impl_->my_position == 0) {
    FTRTEC::Replication_Service* svc = FTRTEC::Replication_Service::instance();
    ACE_Write_Guard<FTRTEC::Replication_Service> lock(*svc);
    add_member(info, IOGR_Maker::instance()->increment_ref_version() );
  }
}

void TAO_FTEC_Group_Manager::add_member (
    const FTRT::ManagerInfo & info,
    CORBA::ULong object_group_ref_version
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
{
  ACE_DEBUG((LM_DEBUG, "add_member location = <%s>\n",
    (const char*)info.the_location[0].id));

  size_t pos = impl_->info_list.length();
  impl_->info_list.length(pos+1);
  impl_->info_list[pos] = info;

  IOGR_Maker::instance()->set_ref_version( object_group_ref_version );
  GroupInfoPublisherBase* publisher = GroupInfoPublisher::instance();
  publisher->update(impl_->info_list, impl_->my_position
                    ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  if (impl_->my_position < impl_->info_list.length()-2) 
  {
    // I am not the last of replica, tell my successor that
    // a new member has joined in.
    ACE_TRY {
      publisher->successor()->add_member(info, object_group_ref_version
        ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;
      return;
    } 
    ACE_CATCHANY {
      // Unable to send request to all the successors. 
      // Now this node become the last replica of the object group.
    }
    ACE_ENDTRY;

    // update the info list again
    impl_->info_list.length(impl_->my_position+2);
    impl_->info_list[impl_->my_position+1] = info;

    publisher->update(impl_->info_list, impl_->my_position
      ACE_ENV_ARG_PARAMETER);
 }


  // this is the last replica in the list
  // synchornize the state with the newly joined replica.
  FtRtecEventChannelAdmin::EventChannelState state;
  get_state(state ACE_ENV_ARG_PARAMETER);

  TAO_OutputCDR cdr;
  cdr << state;

  FTRT::State s;
  if (cdr.begin()->cont()) {
    ACE_Message_Block* blk;
    ACE_NEW_THROW_EX(blk, ACE_Message_Block, CORBA::NO_MEMORY());
    ACE_CDR::consolidate(blk, cdr.begin());
    s.replace(blk->length(), blk);
    blk->release();
  }
  else
    s.replace(cdr.begin()->length(), cdr.begin());

  ACE_DEBUG((LM_DEBUG, "Setting state\n"));
  info.ior->set_state(s ACE_ENV_ARG_PARAMETER);
  info.ior->create_group(impl_->info_list, object_group_ref_version);
  ACE_DEBUG((LM_DEBUG, "After create_group\n"));
}

template <class SEQ>
void remove_item(SEQ & seq, int position)
{
    int i = position;
    int len = seq.length()-1;
    for (;i < len; ++i)
        seq[i] = seq[i+1];
    seq.length(len);
}

void TAO_FTEC_Group_Manager::replica_crashed (
    const FTRT::Location & location
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
{
  ACE_DEBUG((LM_DEBUG, "TAO_FTEC_Group_Manager::replica_crashed\n"));
  FTRTEC::Replication_Service* svc = FTRTEC::Replication_Service::instance();
    ACE_Write_Guard<FTRTEC::Replication_Service> lock(*svc);
    remove_member(location, IOGR_Maker::instance()->increment_ref_version());
}

void TAO_FTEC_Group_Manager::remove_member (
    const FTRT::Location & crashed_location,
    CORBA::ULong object_group_ref_version
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
{
  // find my position of this EventChannel in the group
  unsigned  crashed_pos = find_by_location(impl_->info_list, crashed_location);
  if (crashed_pos >= impl_->info_list.length()) {
    return;
  }

  ACE_ASSERT(impl_->my_position != crashed_pos);
  remove_item(impl_->info_list, crashed_pos);

  if (impl_->my_position > crashed_pos)
    --impl_->my_position;

  GroupInfoPublisherBase* publisher = GroupInfoPublisher::instance();

  publisher->update(impl_->info_list, impl_->my_position
                    ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  FtRtecEventChannelAdmin::EventChannel_var successor =
    publisher->successor();

  IOGR_Maker::instance()->set_ref_version(object_group_ref_version);
  if (!CORBA::is_nil(successor.in())) {

    successor->remove_member(crashed_location,
                             object_group_ref_version
                             ACE_ENV_ARG_PARAMETER);
    ACE_CHECK;
  }

  ACE_DEBUG((LM_DEBUG, "2. my_position = %d, crashed_pos = %d\n", impl_->my_position, crashed_pos));
  if (impl_->my_position == crashed_pos && impl_->my_position > 0)
    Fault_Detector::instance()->connect(impl_->info_list[impl_->my_position-1].the_location);
}

void TAO_FTEC_Group_Manager::connection_closed()
{
  ACE_DEBUG((LM_DEBUG, "TAO_FTEC_Group_Manager::connection_closed\n"));
  ACE_ASSERT(impl_->my_position > 0);

  // do not use referere here, because the the value pointed by the pointer to
  // crashed_location will be repliaced by its successor.
  FTRT::Location crashed_location = impl_->info_list[impl_->my_position-1].the_location;

  if (impl_->my_position > 1) {
    ACE_TRY_NEW_ENV {
      TAO_IOP::TAO_IOR_Manipulation::IORList iors;
      iors.length(impl_->my_position-1);
      for (size_t i = 0; i < impl_->my_position-1; ++i)
        iors[i] = CORBA::Object::_duplicate(impl_->info_list[i].ior.in());

      CORBA::Object_var obj =
        IOGR_Maker::instance()->merge_iors(iors
        ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      FtRtecEventChannelAdmin::EventChannel_var primary =
        FtRtecEventChannelAdmin::EventChannel::_narrow(obj.in()
                                                       ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      primary->replica_crashed(crashed_location
                          ACE_ENV_ARG_PARAMETER);

      ACE_TRY_CHECK;
      return;
    }
    ACE_CATCHANY {
    }
    ACE_ENDTRY;
  }

  ACE_TRY_NEW_ENV {
    remove_member(crashed_location,
                  IOGR_Maker::instance()->increment_ref_version()
                  ACE_ENV_ARG_PARAMETER);
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY {
  }
  ACE_ENDTRY;

}



#include "Dynamic_Component_Activator.h"
#include "CIAO_common.h"
#include "ace/Log_Msg.h"
#include "ace/OS_NS_string.h"

ACE_RCSID (ciao,
           Dynamic_Component_Activator,
           "$Id$")

namespace CIAO
{
  Dynamic_Component_Activator::Dynamic_Component_Activator (CORBA::ORB_ptr o)
    : orb_ (CORBA::ORB::_duplicate (o))
  {
  }

  Dynamic_Component_Activator::~Dynamic_Component_Activator (void)
  {
  }

  PortableServer::Servant
  Dynamic_Component_Activator::incarnate (const PortableServer::ObjectId &oid,
                                PortableServer::POA_ptr
                                ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableServer::ForwardRequest))
  {
    // @@Jai, where i sth emutex used at all?
    Dynamic_Component_Servant_Base* servant = 0;
    PortableServer::ObjectId new_oid (oid);

    if (this->servant_map_.find (oid, servant) == 0)
      {
        return servant->create (new_oid);
      }

    return 0;
  }

  void
  Dynamic_Component_Activator::etherealize (
    const PortableServer::ObjectId &,
    PortableServer::POA_ptr ,
    PortableServer::Servant ,
    CORBA::Boolean ,
    CORBA::Boolean
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
  {
  }

  void Dynamic_Component_Activator::add_servant_map
    (PortableServer::ObjectId &oid,
     Dynamic_Component_Servant_Base* servant
     ACE_ENV_ARG_DECL)
  {
    this->servant_map_.bind (oid, servant);
  }

  void Dynamic_Component_Activator::delete_servant_map
    (PortableServer::ObjectId &oid
     ACE_ENV_ARG_DECL)
  {
    Dynamic_Component_Servant_Base* servant = 0;
    if (this->servant_map_.unbind (oid, servant) != 0)
      {
        ACE_DEBUG ((LM_DEBUG, "Invalid object reference\n"));
        return;
      }

    return;
  }

}

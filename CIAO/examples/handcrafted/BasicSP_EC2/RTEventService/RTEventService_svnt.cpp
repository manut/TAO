// $Id$
//
// ****              Code generated by the                 ****
// ****  Component Integrated ACE ORB (CIAO) CIDL Compiler ****
// CIAO has been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// CIDL Compiler has been developed by:
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about CIAO is available at:
//    http://www.cs.wustl.edu/~nanbor/projects/CIAO-src/docs/index.html

#include "RTEventService_svnt.h"
#include "Cookies.h"

namespace CIAO_GLUE_RtecEventChannelAdmin
{
  EventChannel_Servant::EventChannel_Servant (
  ::RtecEventChannelAdmin::CCM_EventChannel_ptr executor,
  ::Components::CCMContext_ptr c)
  : executor_ (::RtecEventChannelAdmin::CCM_EventChannel::_duplicate (executor)),
  ctx_ (::Components::CCMContext::_duplicate (c))
  {
  }

  EventChannel_Servant::~EventChannel_Servant (void)
  {
  }

  ::RtecEventChannelAdmin::ConsumerAdmin_ptr
  EventChannel_Servant::for_consumers (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    return this->executor_->for_consumers (
    ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  ::RtecEventChannelAdmin::SupplierAdmin_ptr
  EventChannel_Servant::for_suppliers (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    return this->executor_->for_suppliers (
    ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  void
  EventChannel_Servant::destroy (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    this->executor_->destroy (
    ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  RtecEventChannelAdmin::Observer_Handle
  EventChannel_Servant::append_observer (
  RtecEventChannelAdmin::Observer_ptr gw
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  CORBA::SystemException,
  RtecEventChannelAdmin::EventChannel::SYNCHRONIZATION_ERROR,
  RtecEventChannelAdmin::EventChannel::CANT_APPEND_OBSERVER
  ))
  {
    return this->executor_->append_observer (
    gw
    ACE_ENV_ARG_PARAMETER);
  }

  void
  EventChannel_Servant::remove_observer (
  RtecEventChannelAdmin::Observer_Handle gw
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  CORBA::SystemException,
  RtecEventChannelAdmin::EventChannel::SYNCHRONIZATION_ERROR,
  RtecEventChannelAdmin::EventChannel::CANT_REMOVE_OBSERVER
  ))
  {
    this->executor_->remove_observer (
    gw
    ACE_ENV_ARG_PARAMETER);
  }

  CORBA::Object_ptr
  EventChannel_Servant::_get_component (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ::Components::SessionContext_var sc =
    ::Components::SessionContext::_narrow (
    this->ctx_.in ()
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (CORBA::Object::_nil ());

    if (! CORBA::is_nil (sc.in ()))
    {
      return sc->get_CCM_object (
      ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    ::Components::EntityContext_var ec =
    ::Components::EntityContext::_narrow (
    this->ctx_.in ()
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (CORBA::Object::_nil ());

    if (! CORBA::is_nil (ec.in ()))
    {
      return ec->get_CCM_object (
      ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    ACE_THROW_RETURN (CORBA::INTERNAL (), 0);
  }

}

namespace CIAO_GLUE_BasicSP
{
  RTEventService_Context::RTEventService_Context (
  ::Components::CCMHome_ptr home,
  ::CIAO::Session_Container *c,
  RTEventService_Servant *sv)
  : home_ (::Components::CCMHome::_duplicate (home)),
  container_ (c),
  servant_ (sv)
  {
  }

  RTEventService_Context::~RTEventService_Context (void)
  {
  }

  // Operations from ::Components::CCMContext.

  ::Components::Principal_ptr
  RTEventService_Context::get_caller_principal (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (
    ::CORBA::NO_IMPLEMENT (),
    ::Components::Principal::_nil ());
  }

  ::Components::CCMHome_ptr
  RTEventService_Context::get_CCM_home (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    return ::Components::CCMHome::_duplicate (this->home_.in ());
  }

  CORBA::Boolean
  RTEventService_Context::get_rollback_only (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::IllegalState))
  {
    ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::Transaction::UserTransaction_ptr
  RTEventService_Context::get_user_transaction (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::IllegalState))
  {
    ACE_THROW_RETURN (
    ::CORBA::NO_IMPLEMENT (),
    ::Components::Transaction::UserTransaction::_nil ());
  }

  CORBA::Boolean
  RTEventService_Context::is_caller_in_role (
  const char *role
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_UNUSED_ARG (role);
    ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
  }

  void
  RTEventService_Context::set_rollback_only (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::IllegalState))
  {
    ACE_THROW (CORBA::NO_IMPLEMENT ());
  }

  // Operations from ::Components::SessionContext interface.

  CORBA::Object_ptr
  RTEventService_Context::get_CCM_object (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::IllegalState))
  {
    if (CORBA::is_nil (this->component_.in ()))
    {
      CORBA::Object_var obj =
      this->container_->get_objref (
      this->servant_
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (CORBA::Object::_nil ());

      this->component_ =
      ::BasicSP::RTEventService::_narrow (
      obj.in ()
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (CORBA::Object::_nil ());

      if (CORBA::is_nil (this->component_.in ()))
      {
        ACE_THROW_RETURN (
        ::CORBA::INTERNAL (),
        ::CORBA::Object::_nil ());
      }
    }

    return ::BasicSP::RTEventService::_duplicate (
    this->component_.in ());
  }

  // Operations for RTEventService receptacles and event sources,
  // defined in ::BasicSP::CCM_RTEventService_Context.


  RTEventService_Servant::RTEventService_Servant (
  ::BasicSP::CCM_RTEventService_ptr exe,
  ::Components::CCMHome_ptr h,
  ::CIAO::Session_Container *c)
  : executor_ (::BasicSP::CCM_RTEventService::_duplicate (exe)),
  container_ (c)
  {
    this->context_ = new RTEventService_Context (h, c, this);

    ACE_TRY_NEW_ENV
    {
      ::Components::SessionComponent_var scom =
      ::Components::SessionComponent::_narrow (
      exe
      ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (! ::CORBA::is_nil (scom.in ()))
      {
        scom->set_session_context (
        this->context_
        ACE_ENV_ARG_PARAMETER);
      }
    }
    ACE_CATCHANY
    {
    }
    ACE_ENDTRY;
  }

  RTEventService_Servant::~RTEventService_Servant (void)
  {
    ACE_TRY_NEW_ENV
    {
      ::Components::SessionComponent_var scom =
      ::Components::SessionComponent::_narrow (
      this->executor_.in ()
      ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (! ::CORBA::is_nil (scom.in ()))
      {
        scom->ccm_remove (ACE_ENV_SINGLE_ARG_PARAMETER);
      }
    }
    ACE_CATCHANY
    {
    }
    ACE_ENDTRY;

    this->context_->_remove_ref ();
  }

  ::RtecEventChannelAdmin::EventChannel_ptr
  RTEventService_Servant::provide_rt_event_channel (
  ACE_ENV_SINGLE_ARG_PARAMETER)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    if (::CORBA::is_nil (this->provide_rt_event_channel_.in ()))
    {
      ::RtecEventChannelAdmin::CCM_EventChannel_var fexe =
      this->executor_->get_rt_event_channel (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (::RtecEventChannelAdmin::EventChannel::_nil ());

      if (::CORBA::is_nil (fexe.in ()))
      {
        ACE_THROW_RETURN (
        ::CORBA::INTERNAL (),
        ::RtecEventChannelAdmin::EventChannel::_nil ());
      }

      CIAO_GLUE_RtecEventChannelAdmin::EventChannel_Servant *svt =
      new CIAO_GLUE_RtecEventChannelAdmin::EventChannel_Servant (
      fexe.in (),
      this->context_);
      PortableServer::ServantBase_var safe_servant (svt);

      ::CORBA::Object_var obj =
      this->container_->install_servant (
      svt
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::RtecEventChannelAdmin::EventChannel::_nil ());

      ::RtecEventChannelAdmin::EventChannel_var fo =
      ::RtecEventChannelAdmin::EventChannel::_narrow (
      obj.in ()
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::RtecEventChannelAdmin::EventChannel::_nil ());

      this->provide_rt_event_channel_ = fo;
    }

    return ::RtecEventChannelAdmin::EventChannel::_duplicate (this->provide_rt_event_channel_.in ());
  }

  // Operations for Navigation interface.

  CORBA::Object_ptr
  RTEventService_Servant::provide_facet (
  const char *name
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName))
  {
    if (name == 0)
    {
      ACE_THROW_RETURN (
      ::CORBA::BAD_PARAM (),
      ::CORBA::Object::_nil ());
    }

    if (ACE_OS::strcmp (name, "rt_event_channel") == 0)
    {
      return this->provide_rt_event_channel (ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    ACE_THROW_RETURN (
    ::Components::InvalidName (),
    ::CORBA::Object::_nil ());
  }

  ::Components::FacetDescriptions *
  RTEventService_Servant::get_all_facets (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::FacetDescriptions *
  RTEventService_Servant::get_named_facets (
  const ::Components::NameList &names
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  CORBA::Boolean
  RTEventService_Servant::same_component (
  CORBA::Object_ptr object_ref
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    if (::CORBA::is_nil (object_ref))
    {
      ACE_THROW_RETURN (::CORBA::BAD_PARAM (), 0);
    }

    ::CORBA::Object_var the_other =
    object_ref->_get_component (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN (0);

    ::CORBA::Object_var me =
    this->context_->get_CCM_object (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN (0);

    return me->_is_equivalent (
    the_other.in ()
    ACE_ENV_ARG_PARAMETER);
  }

  // Operations for Receptacles interface.

  ::Components::Cookie *
  RTEventService_Servant::connect (
  const char *name,
  ::CORBA::Object_ptr connection
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName,
  ::Components::InvalidConnection,
  ::Components::AlreadyConnected,
  ::Components::ExceededConnectionLimit))
  {
    if (name == 0)
    {
      ACE_THROW_RETURN (::Components::InvalidName (), 0);
    }

    ACE_THROW_RETURN (::Components::InvalidName (), 0);
  }

  CORBA::Object_ptr
  RTEventService_Servant::disconnect (
  const char *name,
  ::Components::Cookie *ck
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName,
  ::Components::InvalidConnection,
  ::Components::CookieRequired,
  ::Components::NoConnection))
  {
    if (name == 0)
    {
      ACE_THROW_RETURN (
      ::Components::InvalidName (),
      ::CORBA::Object::_nil ());
    }

    ACE_THROW_RETURN (
    ::Components::InvalidName (),
    ::CORBA::Object::_nil ());
  }

  ::Components::ConnectionDescriptions *
  RTEventService_Servant::get_connections (
  const char *name
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::ReceptacleDescriptions *
  RTEventService_Servant::get_all_receptacles (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::ReceptacleDescriptions *
  RTEventService_Servant::get_named_receptacles (
  const ::Components::NameList &names
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  // Operations for Events interface.

  ::Components::EventConsumerBase_ptr
  RTEventService_Servant::get_consumer (
  const char *sink_name
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName))
  {
    if (sink_name == 0)
    {
      ACE_THROW_RETURN (
      ::Components::InvalidName (),
      ::Components::EventConsumerBase::_nil ());
    }

    ACE_THROW_RETURN (
    ::Components::InvalidName (),
    ::Components::EventConsumerBase::_nil ());
  }

  ::Components::Cookie *
  RTEventService_Servant::subscribe (
  const char *publisher_name,
  ::Components::EventConsumerBase_ptr subscribe
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName,
  ::Components::InvalidConnection,
  ::Components::ExceededConnectionLimit))
  {
    if (publisher_name == 0)
    {
      ACE_THROW_RETURN (::Components::InvalidName (), 0);
    }

    ACE_THROW_RETURN (::Components::InvalidName (), 0);
  }

  ::Components::EventConsumerBase_ptr
  RTEventService_Servant::unsubscribe (
  const char *publisher_name,
  ::Components::Cookie *ck
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName,
  ::Components::InvalidConnection))
  {
    if (publisher_name == 0)
    {
      ACE_THROW_RETURN (
      ::Components::InvalidName (),
      ::Components::EventConsumerBase::_nil ());
    }

    ACE_THROW_RETURN (
    ::Components::InvalidName (),
    ::Components::EventConsumerBase::_nil ());
  }

  void
  RTEventService_Servant::connect_consumer (
  const char *emitter_name,
  ::Components::EventConsumerBase_ptr consumer
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName,
  ::Components::AlreadyConnected,
  ::Components::InvalidConnection))
  {
    ACE_THROW (::CORBA::NO_IMPLEMENT ());
  }

  ::Components::EventConsumerBase_ptr
  RTEventService_Servant::disconnect_consumer (
  const char *source_name
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName,
  ::Components::NoConnection))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::ConsumerDescriptions *
  RTEventService_Servant::get_all_consumers (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::ConsumerDescriptions *
  RTEventService_Servant::get_named_consumers (
  const ::Components::NameList &names
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::EmitterDescriptions *
  RTEventService_Servant::get_all_emitters (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::EmitterDescriptions *
  RTEventService_Servant::get_named_emitters (
  const ::Components::NameList &names
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::PublisherDescriptions *
  RTEventService_Servant::get_all_publishers (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::PublisherDescriptions *
  RTEventService_Servant::get_named_publishers (
  const ::Components::NameList &names
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  // Operations for CCMObject interface.

  CORBA::IRObject_ptr
  RTEventService_Servant::get_component_def (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (
    ::CORBA::NO_IMPLEMENT (),
    ::CORBA::IRObject::_nil ());
  }

  ::Components::CCMHome_ptr
  RTEventService_Servant::get_ccm_home (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    return this->context_->get_CCM_home (ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  ::Components::PrimaryKeyBase *
  RTEventService_Servant::get_primary_key (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::NoKeyAvailable))
  {
    ACE_THROW_RETURN (::Components::NoKeyAvailable (), 0);
  }

  void
  RTEventService_Servant::configuration_complete (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidConfiguration))
  {
    // CIAO to-do
  }

  void
  RTEventService_Servant::remove (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::RemoveFailure))
  {
    // CIAO to-do
  }

  ::Components::ComponentPortDescription *
  RTEventService_Servant::get_all_ports (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ::Components::ComponentPortDescription_var retv =
    new OBV_Components::ComponentPortDescription;

    ::Components::FacetDescriptions_var facets_desc =
    this->get_all_facets (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN (0);

    ::Components::ReceptacleDescriptions_var receptacle_desc =
    this->get_all_receptacles (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN (0);

    ::Components::ConsumerDescriptions_var consumer_desc =
    this->get_all_consumers (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN (0);

    ::Components::EmitterDescriptions_var emitter_desc =
    this->get_all_emitters (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN (0);

    ::Components::PublisherDescriptions_var publisher_desc =
    this->get_all_publishers (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN (0);

    retv->facets (facets_desc.in ());
    retv->receptacles (receptacle_desc.in ());
    retv->consumers (consumer_desc.in ());
    retv->emitters (emitter_desc.in ());
    retv->publishers (publisher_desc.in ());

    return retv._retn ();
  }

  CORBA::Object_ptr
  RTEventService_Servant::_get_component (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ::Components::SessionContext_var sc =
    ::Components::SessionContext::_narrow (
    this->context_
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (::CORBA::Object::_nil ());

    if (! ::CORBA::is_nil (sc.in ()))
    {
      return sc->get_CCM_object (ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    ::Components::EntityContext_var ec =
    ::Components::EntityContext::_narrow (
    this->context_
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (::CORBA::Object::_nil ());

    if (! ::CORBA::is_nil (ec.in ()))
    {
      return ec->get_CCM_object (ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    ACE_THROW_RETURN (
    ::CORBA::INTERNAL (),
    ::CORBA::Object::_nil ());
  }

  // CIAO-specific operations.

  void
  RTEventService_Servant::_ciao_activate (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ::Components::SessionComponent_var temp =
    ::Components::SessionComponent::_narrow (
    this->executor_.in ()
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK;

    if (! ::CORBA::is_nil (temp.in ()))
    {
      temp->ccm_activate (ACE_ENV_SINGLE_ARG_PARAMETER);
    }
  }

  void
  RTEventService_Servant::_ciao_passivate (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ::Components::SessionComponent_var temp =
    ::Components::SessionComponent::_narrow (
    this->executor_.in ()
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK;

    if (! ::CORBA::is_nil (temp.in ()))
    {
      temp->ccm_passivate (ACE_ENV_SINGLE_ARG_PARAMETER);
    }
  }

  // Supported operations.


  RTEventServiceHome_Servant::RTEventServiceHome_Servant (
  ::BasicSP::CCM_RTEventServiceHome_ptr exe,
  ::CIAO::Session_Container *c)
  : executor_ (::BasicSP::CCM_RTEventServiceHome::_duplicate (exe)),
  container_ (c)
  {
  }

  RTEventServiceHome_Servant::~RTEventServiceHome_Servant (void)
  {
  }

  // Operations for keyless home interface.

  ::Components::CCMObject_ptr
  RTEventServiceHome_Servant::create_component (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::CreateFailure))
  {
    return this->create (ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  // Operations for implicit home interface.

  ::BasicSP::RTEventService_ptr
  RTEventServiceHome_Servant::create (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::CreateFailure))
  {
    if (this->executor_.in () == 0)
    {
      ACE_THROW_RETURN (
      ::CORBA::INTERNAL (),
      ::BasicSP::RTEventService::_nil ());
    }

    Components::EnterpriseComponent_var _ciao_ec =
    this->executor_->create (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN (::BasicSP::RTEventService::_nil ());

    ::BasicSP::CCM_RTEventService_var _ciao_comp =
    ::BasicSP::CCM_RTEventService::_narrow (
    _ciao_ec.in ()
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (::BasicSP::RTEventService::_nil ());

    return this->_ciao_activate_component (
    _ciao_comp.in ()
    ACE_ENV_ARG_PARAMETER);
  }

  // Operations for CCMHome interface.

  ::CORBA::IRObject_ptr
  RTEventServiceHome_Servant::get_component_def (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (
    ::CORBA::NO_IMPLEMENT (),
    ::CORBA::IRObject::_nil ());
  }

  ::CORBA::IRObject_ptr
  RTEventServiceHome_Servant::get_home_def (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (
    ::CORBA::NO_IMPLEMENT (),
    ::CORBA::IRObject::_nil ());
  }

  void
  RTEventServiceHome_Servant::remove_component (
  ::Components::CCMObject_ptr comp
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::RemoveFailure))
  {
    ::BasicSP::RTEventService_var _ciao_comp =
    ::BasicSP::RTEventService::_narrow (
    comp
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK;

    if (CORBA::is_nil (_ciao_comp.in ()))
    {
      ACE_THROW (CORBA::INTERNAL ());
    }

    _ciao_comp->remove (ACE_ENV_ARG_PARAMETER);
    ACE_CHECK;

    this->_ciao_passivate_component (
    _ciao_comp.in ()
    ACE_ENV_ARG_PARAMETER);
  }

  // CIAO-specific operations.

  ::BasicSP::RTEventService_ptr
  RTEventServiceHome_Servant::_ciao_activate_component (
  ::BasicSP::CCM_RTEventService_ptr exe
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ::CORBA::Object_var hobj =
    this->container_->get_objref (
    this
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (::BasicSP::RTEventService::_nil ());

    ::Components::CCMHome_var home =
    ::Components::CCMHome::_narrow (
    hobj
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (::BasicSP::RTEventService::_nil ());

    RTEventService_Servant *svt =
    new RTEventService_Servant (
    exe,
    home.in (),
    this->container_);

    PortableServer::ServantBase_var safe (svt);
    PortableServer::ObjectId_var oid;

    CORBA::Object_var objref =
    this->container_->install_component (
    svt,
    oid.out ()
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (::BasicSP::RTEventService::_nil ());

    svt->_ciao_activate (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN (::BasicSP::RTEventService::_nil ());

    ::BasicSP::RTEventService_var ho =
    ::BasicSP::RTEventService::_narrow (
    objref.in ()
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (::BasicSP::RTEventService::_nil ());

    if (this->component_map_.bind (oid.in (), svt) == 0)
    {
      safe._retn ();
    }

    return ho._retn ();
  }

  void
  RTEventServiceHome_Servant::_ciao_passivate_component (
  ::BasicSP::RTEventService_ptr comp
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    PortableServer::ObjectId_var oid;

    this->container_->uninstall_component (
    comp,
    oid.out ()
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK;

    RTEventService_Servant *servant = 0;

    if (this->component_map_.unbind (oid.in (), servant) == 0)
    {
      PortableServer::ServantBase_var safe (servant);
      servant->_ciao_passivate (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;
    }
  }

  // Supported operations.


}

extern "C" RTEVENTSERVICE_SVNT_Export ::PortableServer::Servant
createRTEventServiceHome_Servant (
::Components::HomeExecutorBase_ptr p,
CIAO::Session_Container *c
ACE_ENV_ARG_DECL)
{
  if (p == 0)
  {
    return 0;
  }

  ::BasicSP::CCM_RTEventServiceHome_var x =
  ::BasicSP::CCM_RTEventServiceHome::_narrow (
  p
  ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  if (::CORBA::is_nil (x.in ()))
  {
    return 0;
  }

  return new
  ::CIAO_GLUE_BasicSP::RTEventServiceHome_Servant (
  x.in (),
  c);
}


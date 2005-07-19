#include "orbsvcs/Log/RTEventLogFactory_i.h"
#include "orbsvcs/Log/LogNotification.h"
#include "orbsvcs/Log/RTEventLogNotification.h"
#include "orbsvcs/Event/EC_ConsumerAdmin.h"
#include "orbsvcs/Event/EC_ProxySupplier.h"
#include "orbsvcs/Event/EC_ProxyConsumer.h"
#include "orbsvcs/Event/EC_Event_Channel.h"
#include "orbsvcs/ESF/ESF_Peer_Workers.h"
#include "orbsvcs/ESF/ESF_Peer_Admin.h"
#include "orbsvcs/ESF/ESF_Shutdown_Proxy.h"
#include "orbsvcs/Event/EC_ConsumerAdmin.h"
#include "orbsvcs/Event_Utilities.h"
#include "orbsvcs/Sched/Config_Scheduler.h"
#include "orbsvcs/Event/EC_Default_Factory.h"
#include "orbsvcs/Event/EC_Event_Channel.h"
#include "ace/OS_NS_stdio.h"

#include "ace/Auto_Ptr.h"

ACE_RCSID (Log,
           RTEventLogFactory_i,
           "$Id$")

TAO_RTEventLogFactory_i::TAO_RTEventLogFactory_i (void)
{
  // No-Op.
}

TAO_RTEventLogFactory_i::~TAO_RTEventLogFactory_i()
{
  // No-Op.
}

int
TAO_RTEventLogFactory_i::init (CORBA::ORB_ptr orb,
                               PortableServer::POA_ptr poa
                               ACE_ENV_ARG_DECL)
{
  TAO_LogMgr_i::init (orb, poa ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);
  
    
  PortableServer::POA_var defPOA =
    this->_default_POA (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);

  TAO_EC_Event_Channel_Attributes attr (defPOA.in (), defPOA.in ());

  this->impl = 0;
  ACE_NEW_THROW_EX (impl,
                    TAO_EC_Event_Channel (attr),
                    CORBA::NO_MEMORY ());
  ACE_CHECK_RETURN (-1);

  auto_ptr <TAO_EC_Event_Channel> ec (impl);

  impl->activate (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);

  PortableServer::ObjectId_var oidec = poa_->activate_object (ec.get ()
                                       ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);

  ec.release ();

  CORBA::Object_var objec =
    poa_->id_to_reference (oidec.in () ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);

  this->event_channel_ = RtecEventChannelAdmin::EventChannel::_narrow (objec.in ());


  this->consumer_admin_ = this->event_channel_->for_consumers(ACE_ENV_SINGLE_ARG_PARAMETER);

  ACE_NEW_THROW_EX (this->notifier_,
                    TAO_RTEventLogNotification(this->event_channel_.in ()),
                    CORBA::NO_MEMORY ());
  return 0;
}

RTEventLogAdmin::EventLogFactory_ptr
TAO_RTEventLogFactory_i::activate (ACE_ENV_SINGLE_ARG_DECL)
{
  RTEventLogAdmin::EventLogFactory_var v_return;

  PortableServer::ObjectId_var oid =
    this->factory_poa_->activate_object (this
					 ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (v_return._retn ());

  CORBA::Object_var obj =
    this->factory_poa_->id_to_reference (oid.in ()
					 ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (v_return._retn ());
  
  // narrow and store the result..
  this->log_mgr_ =
    DsLogAdmin::LogMgr::_narrow (obj.in ()
                                 ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (v_return._retn ());

  v_return =
    RTEventLogAdmin::EventLogFactory::_narrow (obj.in ()
                                          ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (RTEventLogAdmin::EventLogFactory::_nil ());

  return v_return._retn ();
}

RTEventLogAdmin::EventLog_ptr
TAO_RTEventLogFactory_i::create (
        DsLogAdmin::LogFullActionType full_action,
        CORBA::ULongLong max_size,
        const DsLogAdmin::CapacityAlarmThresholdList & thresholds,
        DsLogAdmin::LogId_out id_out
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DsLogAdmin::InvalidLogFullAction,
        DsLogAdmin::InvalidThreshold
      ))
{
  this->create_i (full_action,
		  max_size,
		  & thresholds,
		  id_out
		  ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (RTEventLogAdmin::EventLog::_nil ());
  DsLogAdmin::LogId id = id_out;

  DsLogAdmin::Log_var log =
    this->create_log_object (id
			     ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (RTEventLogAdmin::EventLog::_nil ());

  // narrow to EventLog
  RTEventLogAdmin::EventLog_var event_log = 
    RTEventLogAdmin::EventLog::_narrow (log);

  // @@ JTC - squelch exception?
  notifier_->object_creation (id ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (RTEventLogAdmin::EventLog::_nil ());

  return event_log._retn();
}

RTEventLogAdmin::EventLog_ptr
TAO_RTEventLogFactory_i::create_with_id (
        DsLogAdmin::LogId id,
        DsLogAdmin::LogFullActionType full_action,
        CORBA::ULongLong max_size,
        const DsLogAdmin::CapacityAlarmThresholdList & thresholds
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DsLogAdmin::LogIdAlreadyExists,
        DsLogAdmin::InvalidLogFullAction,
        DsLogAdmin::InvalidThreshold
      ))
{
  this->create_with_id_i (id,
			  full_action,
			  max_size,
			  & thresholds
			  ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (RTEventLogAdmin::EventLog::_nil ());

  DsLogAdmin::Log_var log =
    this->create_log_object (id
			 ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (RTEventLogAdmin::EventLog::_nil ());

  // narrow to EventLog
  RTEventLogAdmin::EventLog_var event_log = 
    RTEventLogAdmin::EventLog::_narrow (log);
  
  // @@ JTC - squelch exception?
  notifier_->object_creation (id ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (RTEventLogAdmin::EventLog::_nil ());

  return event_log._retn ();
}

PortableServer::ObjectId*
TAO_RTEventLogFactory_i::create_objectid (DsLogAdmin::LogId id)
{
  char buf[32]; 
  ACE_OS::sprintf(buf, "%lu", static_cast<unsigned long>(id)); 
 
  PortableServer::ObjectId_var oid = 
        PortableServer::string_to_ObjectId(buf);

  return oid._retn ();
}

DsLogAdmin::Log_ptr
TAO_RTEventLogFactory_i::create_log_reference (DsLogAdmin::LogId id
					       ACE_ENV_ARG_DECL)
{
  PortableServer::ObjectId_var oid =
    this->create_objectid (id);
  const char *intf =  
    "IDL:omg.org/RTEventLogAdmin:EventLog:1.0";
  
  CORBA::Object_var obj = 
    this->log_poa_->create_reference_with_id (oid.in (),
					      intf
					      ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (DsLogAdmin::Log::_nil ());
  
  RTEventLogAdmin::EventLog_var event_log = 
    RTEventLogAdmin::EventLog::_narrow (obj.in ()
					ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (DsLogAdmin::Log::_nil ());
  
  return event_log._retn(); 
}

DsLogAdmin::Log_ptr
TAO_RTEventLogFactory_i::create_log_object (DsLogAdmin::LogId id
					    ACE_ENV_ARG_DECL)
{
  TAO_RTEventLog_i* event_log_i;

  ACE_NEW_THROW_EX (event_log_i,
                    TAO_RTEventLog_i (this->orb_.in (),
				      this->log_poa_.in (),
                                      *this,
                                      this->log_mgr_.in (),
                                      this->notifier_,
                                      id
                                      ),
                    CORBA::NO_MEMORY ());

  ACE_CHECK_RETURN (RTEventLogAdmin::EventLog::_nil ());

  PortableServer::ServantBase_var safe_event_log_i = event_log_i;
  // Transfer ownership to POA.

  event_log_i->init (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (RTEventLogAdmin::EventLog::_nil ());

  //initialise the LogConsumer object
  event_log_i->activate (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (RTEventLogAdmin::EventLog::_nil ());

  // Obtain ObjectId
  PortableServer::ObjectId_var oid =
    this->create_objectid (id);

  // Register with the poa
  this->log_poa_->activate_object_with_id (oid.in (),
					   event_log_i
					   ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (RTEventLogAdmin::EventLog::_nil ());

  CORBA::Object_var obj =
    this->log_poa_->id_to_reference (oid.in ()
				     ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (RTEventLogAdmin::EventLog::_nil ());

  // Narrow
  RTEventLogAdmin::EventLog_var event_log =
    RTEventLogAdmin::EventLog::_narrow (obj.in ()
					ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (RTEventLogAdmin::EventLog::_nil ());

  return event_log._retn ();
}

RtecEventChannelAdmin::ProxyPushSupplier_ptr
TAO_RTEventLogFactory_i::obtain_push_supplier (
        ACE_ENV_SINGLE_ARG_DECL_NOT_USED
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ))
{
  return consumer_admin_->obtain_push_supplier();
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class auto_ptr <TAO_RTEventLog_i>;
template class ACE_Auto_Basic_Ptr<TAO_RTEventLog_i>;

#elif defined(ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#pragma instantiate auto_ptr <TAO_RTEventLog_i>
#pragma instantiate ACE_Auto_Basic_Ptr <TAO_RTEventLog_i>

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

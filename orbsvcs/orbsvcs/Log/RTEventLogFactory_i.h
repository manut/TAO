// -*- C++ -*-

//=============================================================================
/**
 *  @file   RTEventLogFactory_i.h
 *
 *  $Id$
 *
 *  Implements the Factory for NotifyLog Objects.
 *
 *
 *  @author David A. Hanvey <d.hanvey@qub.ac.uk>
 */
//=============================================================================

#ifndef TLS_RTEVENTLOGFACTORY_I_H
#define TLS_RTEVENTLOGFACTORY_I_H

#include /**/ "ace/pre.h"

#include "orbsvcs/RTEventLogAdminS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "orbsvcs/DsLogAdminS.h"
#include "orbsvcs/Log/LogMgr_i.h"
#include "orbsvcs/RtecEventChannelAdminS.h"
#include "orbsvcs/RtecSchedulerS.h"

#include "RTEventLog_i.h"
#include "rteventlog_export.h"

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

class TAO_RTEventLog_i;
class TAO_RTEventLogNotification;

/**
 * @class TAO_RTEventLogFactory_i
 *
 * @brief The TAO_RTEventLogFactory is a factory that is used to create RTEventLogs which are event-aware.
 */
class TAO_RTEventLog_Export TAO_RTEventLogFactory_i :
  public POA_RTEventLogAdmin::EventLogFactory,
  public TAO_LogMgr_i
{
public:
  //= Initialization and termination code.

  /// Constructor.
  TAO_RTEventLogFactory_i (void);

  /// Destructor.
  ~TAO_RTEventLogFactory_i ();

  /// Initialise the EventChannel and obtain a
  /// pointer to it.
  int
  init (CORBA::ORB_ptr orb,
        PortableServer::POA_ptr poa
        ACE_ENV_ARG_DECL);

  /// Activate this servant
  RTEventLogAdmin::EventLogFactory_ptr
  activate (ACE_ENV_SINGLE_ARG_DECL);

  /// Used to create a RTEventLog.
  RTEventLogAdmin::EventLog_ptr create (
        DsLogAdmin::LogFullActionType full_action,
        CORBA::ULongLong max_size,
        const DsLogAdmin::CapacityAlarmThresholdList & thresholds,
        DsLogAdmin::LogId_out id
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DsLogAdmin::InvalidLogFullAction,
        DsLogAdmin::InvalidThreshold
      ));

  /// Same as create (), but allows clients to specify the id.
  RTEventLogAdmin::EventLog_ptr create_with_id (
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
      ));

   // = Implementation of the RtecEventChannelAdmin::ConsumerAdmin methods.
  RtecEventChannelAdmin::ProxyPushSupplier_ptr obtain_push_supplier (
        ACE_ENV_SINGLE_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

protected:
  virtual PortableServer::ObjectId*
    create_objectid (DsLogAdmin::LogId id);
	
  virtual DsLogAdmin::Log_ptr
    create_log_object (DsLogAdmin::LogId id
		       ACE_ENV_ARG_DECL);
	
  virtual DsLogAdmin::Log_ptr
    create_log_reference (DsLogAdmin::LogId id
			  ACE_ENV_ARG_DECL);
	
  virtual PortableServer::ServantBase*
    create_log_servant (DsLogAdmin::LogId id
			ACE_ENV_ARG_DECL);

  /// Our object ref. after <active>ation.
  DsLogAdmin::LogMgr_var log_mgr_;

  /// The event channel used for log generated events.
  TAO_EC_Event_Channel *impl;

  /// The object used for log generated events.
  TAO_RTEventLogNotification* notifier_;

  /// EventChannel used to obtain the ConsumerAdmin.
  RtecEventChannelAdmin::EventChannel_var event_channel_;

  /// The ConsumerAdmin that the EventLogFactory supports.
  RtecEventChannelAdmin::ConsumerAdmin_var consumer_admin_;
};

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#include /**/ "ace/post.h"
#endif /* TAO_TLS_RTEVENTLOGFACTORY_I_H */

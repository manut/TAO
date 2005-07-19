// -*- C++ -*-

//=============================================================================
/**
 *  @file   LogMgr_i.h
 *
 *  $Id$
 *
 *  Implementation of the DsLogAdmin::LogMgr interface.
 *
 *  @author Matthew Braun <mjb2@cs.wustl.edu>
 *  @author Pradeep Gore <pradeep@cs.wustl.edu>
 *  @author David A. Hanvey <d.hanvey@qub.ac.uk>
 */
//=============================================================================

#ifndef TAO_TLS_LOGMGR_I_H
#define TAO_TLS_LOGMGR_I_H
#include /**/ "ace/pre.h"

#include "orbsvcs/DsLogAdminS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "orbsvcs/Log/Log_i.h"
#include "orbsvcs/Log/Log_Persistence_Strategy.h"
#include "log_serv_export.h"

/**
 * @class TAO_LogMgr_i
 * @brief Log Factory
 *
 * The implementation delegates operations to a dynamically loaded
 * Strategy class.
 */
class TAO_Log_Serv_Export TAO_LogMgr_i
  : public virtual POA_DsLogAdmin::LogMgr
{
public:

  // = Initialization and Termination Methods

  /// Constructor.
  TAO_LogMgr_i ();

  /// Destructor.
  virtual ~TAO_LogMgr_i ();

  /// Lists all log object references.
  DsLogAdmin::LogList *
    list_logs (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
                     CORBA::SystemException
                     ));

  /// Lists all log ids.
  DsLogAdmin::LogIdList *
    list_logs_by_id (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
                     CORBA::SystemException
                     ));

  /// Returns a reference to the log with the supplied id.
  DsLogAdmin::Log_ptr
    find_log (DsLogAdmin::LogId id
              ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
                     CORBA::SystemException
                     ));

  /// Returns true if log exists, otherwise false
  bool exists (DsLogAdmin::LogId id);
  
  /// Remove the given entry from the container.
  int remove (DsLogAdmin::LogId id);

  /// @brief Create ObjectId
  ///
  /// Create object id for log channel @ id.
  ///
  /// @param id log id
  ///
  /// @return object id
  ///
  virtual PortableServer::ObjectId* 
    create_objectid (DsLogAdmin::LogId id)			= 0;

  /// @brief Create log reference
  ///
  /// Create object reference for log channel @a id.
  ///
  /// @param id log id
  ///
  /// @return object reference
  ///
  virtual DsLogAdmin::Log_ptr 
    create_log_reference (DsLogAdmin::LogId id
			  ACE_ENV_ARG_DECL)			= 0;

  /// @brief Create log object
  ///
  /// Create and activate Log object for log channel @a id.
  ///
  /// @param id log id
  ///
  /// @return object reference
  ///
  virtual DsLogAdmin::Log_ptr 
    create_log_object (DsLogAdmin::LogId id
		       ACE_ENV_ARG_DECL)			= 0;

  /// @brief Get log record store 
  ///
  /// Get/Create a log record store for log channel @a id.
  ///
  /// @param id log id
  ///
  TAO_LogRecordStore*
    get_log_record_store (DsLogAdmin::LogId id
		          ACE_ENV_ARG_DECL);

protected:
  /// @brief Initialize
  ///
  /// Creates factory and log channel POAs, and obtains the LogStore
  /// from a dynamically loaded Log_Persistence_Strategy (if one was
  /// specified in the service config file, otherwise the default 
  /// Hash_Persistence_Strategy is used.)
  ///
  /// @param orb ORB
  /// @param poa Parent POA
  ///
  void init (CORBA::ORB_ptr orb,
	     PortableServer::POA_ptr poa
	     ACE_ENV_ARG_DECL);

  /// @brief Create log
  void create_i (DsLogAdmin::LogFullActionType full_action,
		 CORBA::ULongLong max_size,
		 const DsLogAdmin::CapacityAlarmThresholdList* thresholds,
		 DsLogAdmin::LogId_out id_out
		 ACE_ENV_ARG_DECL);

  /// @brief Create log
  void create_with_id_i (DsLogAdmin::LogId id,
			 DsLogAdmin::LogFullActionType full_action,
			 CORBA::ULongLong max_size,
			 const DsLogAdmin::CapacityAlarmThresholdList* thresholds
			 ACE_ENV_ARG_DECL);
  
  /// ORB.
  CORBA::ORB_var                orb_;

  /// POA.
  PortableServer::POA_var	poa_;

  /// Factory POA.
  PortableServer::POA_var	factory_poa_;

  /// Log POA.
  PortableServer::POA_var	log_poa_;

private:
  TAO_LogStore*			logstore_;
};

#include /**/ "ace/post.h"
#endif /* TAO_TLS_LOGMGR_I_H */

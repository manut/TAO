/* -*- C++ -*- */
/**
 *  @file Reconnection_Registry.h
 *
 *  $Id$
 *
 *  @author Dale Wilson <wilson_d@ociweb.com>
 *
 */

#ifndef TAO_NOTIFY_RECONNECTION_REGISTRY_H
#define TAO_NOTIFY_RECONNECTION_REGISTRY_H
#include /**/ <ace/pre.h>
#include /**/ <ace/config-all.h>

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "Topology_Object.h"

#include "orbsvcs/NotifyExtS.h"

#include "ace/Hash_Map_Manager_T.h"
#include "ace/Null_Mutex.h"

namespace TAO_Notify
{
  static const char REGISTRY_TYPE[] = "reconnect_registry";
  static const char RECONNECT_ID[] = "ReconnectId";
  static const char RECONNECT_IOR[] = "IOR";
  static const char REGISTRY_CALLBACK_TYPE[] = "reconnect_callback";

  /**
   * @class Reconnection_Registry
   *
   * @brief Implementation of ReconnectionRegistry
   *
   */
  class TAO_Notify_Serv_Export Reconnection_Registry
    : public Topology_Object
  {
    /// The registry consists of a map from ReconnectionID to stringified IOR
    typedef ACE_Hash_Map_Manager_Ex<NotifyExt::ReconnectionRegistry::ReconnectionID,
      ACE_CString,
      ACE_Hash<NotifyExt::ReconnectionRegistry::ReconnectionID>,
      ACE_Equal_To<NotifyExt::ReconnectionRegistry::ReconnectionID>,
      ACE_SYNCH_NULL_MUTEX> Reconnection_Registry_Type;

  public:

    /// Constructor
    Reconnection_Registry (Topology_Parent & parent);

    /// Destructor
    ~Reconnection_Registry ();

    //////////////////////////
    // During normal operation

    /// add a new callback to the registry
    ::NotifyExt::ReconnectionRegistry::ReconnectionID register_callback (
      ::NotifyExt::ReconnectionCallback_ptr callback
      ACE_ENV_ARG_DECL);

    ///
    void unregister_callback (::NotifyExt::ReconnectionRegistry::ReconnectionID id
      ACE_ENV_ARG_DECL);

    CORBA::Boolean is_alive (ACE_ENV_SINGLE_ARG_DECL);

    //////////////////////
    // During topology save
    virtual void save_persistent (Topology_Saver& saver ACE_ENV_ARG_DECL);

    ///////////////////////////////////////
    // During reload of persistent topology

    virtual Topology_Object* load_child (const ACE_CString & type,
      CORBA::Long id,
      const NVPList& attrs
      ACE_ENV_ARG_DECL);

    void send_reconnect (CosNotifyChannelAdmin::EventChannelFactory_ptr dest_factory
      ACE_ENV_ARG_DECL);

    void release (void);

  private:
    Reconnection_Registry_Type reconnection_registry_;
    ::NotifyExt::ReconnectionRegistry::ReconnectionID highest_id_;
  };
} // namespace TAO_Notify

#include /**/ <ace/post.h>
#endif /* TAO_NOTIFY_RECONNECTION_REGISTRY_H */

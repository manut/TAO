// -*- C++ -*-

//=============================================================================
/**
 *  @file     Client_Strategy_Factory.h
 *
 *  $Id$
 *
 *  @author  Chris Cleeland <cleeland@cs.wustl.edu>
 */
//=============================================================================


#ifndef TAO_CLIENT_STRATEGY_FACTORY_H
#define TAO_CLIENT_STRATEGY_FACTORY_H

#include /**/ "ace/pre.h"

#include /**/ "tao/TAO_Export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "tao/Versioned_Namespace.h"
#include "tao/Configurable_Refcount.h"

#include "ace/Service_Object.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL
class ACE_Lock;
ACE_END_VERSIONED_NAMESPACE_DECL

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

class TAO_Transport_Mux_Strategy;
class TAO_Wait_Strategy;
class TAO_Transport;
class TAO_ORB_Core;
class TAO_Connect_Strategy;

/**
 * @class TAO_Client_Strategy_Factory
 *
 * @brief Abstract factory used by the client to manufacture various
 * strategies used on the client-side.
 */
class TAO_Export TAO_Client_Strategy_Factory : public ACE_Service_Object
{
public:

  /// Destructor
  virtual ~TAO_Client_Strategy_Factory (void);

  /**
   * Create the lock for the stub and the profile
   */
  virtual ACE_Lock* create_profile_lock (void);

  /// Create the refcount for the profile
  virtual TAO_Configurable_Refcount create_profile_refcount (void);

  /// Create the correct client request muxing strategy.
  virtual TAO_Transport_Mux_Strategy *create_transport_mux_strategy (TAO_Transport *transport);

  /// Create the correct lock for request muxing strategy.
  virtual ACE_Lock *create_transport_mux_strategy_lock (void);

  /// Return the size of the reply dispatcher table
  virtual int reply_dispatcher_table_size (void) const;

  /// Create the correct client <wait_for_reply> strategy.
  virtual TAO_Wait_Strategy *create_wait_strategy (TAO_Transport *transport);

  /// Create the correct client <asynch_connect> strategy.
  virtual TAO_Connect_Strategy *create_connect_strategy (TAO_ORB_Core *);

  enum Connect_Strategy
  {
    TAO_BLOCKED_CONNECT,
    TAO_REACTIVE_CONNECT,
    TAO_LEADER_FOLLOWER_CONNECT
  };
  /// Return the selected connection strategy option.
  virtual Connect_Strategy connect_strategy (void) const;

  /// Does the client allow any form of callback?
  virtual int allow_callback (void);

  /// Create a lock to be used by the TAO_Fault_Tolerant_Service class
  /// to generate unique retention ids
  virtual ACE_Lock *create_ft_service_retention_id_lock (void);

  /// Cleanup options for wait strategy.
  /**
    * Only applicable to RW wait strategy
  */
  virtual bool use_cleanup_options (void) const;
};

TAO_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif /* TAO_CLIENT_STRATEGY_FACTORY_H */

//=============================================================================
/**
 *  @file   Notify_StructuredProxyPushSupplier_i.h
 *
 *  $Id$
 *
 * Implements the POA_CosNotifyChannelAdmin::StructuredProxyPushSupplier
 * interface.
 *
 *
 *  @author Pradeep Gore <pradeep@cs.wustl.edu>
 */
//=============================================================================

#ifndef TAO_NOTIFY_STRUCTUREDPROXYPUSHSUPPLIER_I_H
#define TAO_NOTIFY_STRUCTUREDPROXYPUSHSUPPLIER_I_H

#include "ace/pre.h"
#include "orbsvcs/CosNotifyChannelAdminS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "Notify_ProxySupplier_T.h"

class TAO_Notify_ConsumerAdmin_i;

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

/**
 * @class TAO_Notify_StructuredProxyPushSupplier_i
 *
 * @brief TAO_Notify_StructuredProxyPushSupplier_i
 *
 * Implements POA_CosNotifyChannelAdmin::StructuredProxyPushSupplier
 */
class TAO_Notify_Export TAO_Notify_StructuredProxyPushSupplier_i : public TAO_Notify_ProxySupplier<POA_CosNotifyChannelAdmin::StructuredProxyPushSupplier>
{

 public:
  /// Constructor
  TAO_Notify_StructuredProxyPushSupplier_i (TAO_Notify_ConsumerAdmin_i* consumer_admin);

  /// Destructor
  virtual ~TAO_Notify_StructuredProxyPushSupplier_i (void);

  virtual void connect_structured_push_consumer (
    CosNotifyComm::StructuredPushConsumer_ptr push_consumer
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException,
    CosEventChannelAdmin::AlreadyConnected,
    CosEventChannelAdmin::TypeError
  ));

  virtual void disconnect_structured_push_supplier (
    ACE_ENV_SINGLE_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ));

  /// Shutdown.
  virtual void shutdown (ACE_ENV_SINGLE_ARG_DECL);

 protected:
  // = Helper methods
  /// Shutdown
  void shutdown_i (ACE_ENV_SINGLE_ARG_DECL);

  /// Deliver the event to the consumer.
  virtual void dispatch_event_i (TAO_Notify_Event &event ACE_ENV_ARG_DECL);

  /// Deliver the update to the consumer.
  virtual void dispatch_update_i (CosNotification::EventTypeSeq added, CosNotification::EventTypeSeq removed ACE_ENV_ARG_DECL);

  // = Data Members
  /// The consumer that we're connect to.
  CosNotifyComm::StructuredPushConsumer_var push_consumer_;

 private:
  typedef TAO_Notify_ProxySupplier<POA_CosNotifyChannelAdmin::StructuredProxyPushSupplier>
    proxy_inherited;
};

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#include "ace/post.h"
#endif /* TAO_NOTIFY_STRUCTUREDPROXYPUSHSUPPLIER_I_H */

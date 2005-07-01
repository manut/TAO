/* -*- C++ -*- */
/**
 *  @file ProxySupplier.h
 *
 *  $Id$
 *
 *  @author Pradeep Gore <pradeep@oomworks.com>
 *
 *
 */

#ifndef TAO_Notify_PROXYSUPPLIER_H
#define TAO_Notify_PROXYSUPPLIER_H
#include /**/ "ace/pre.h"

#include "notify_serv_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "Event.h"
#include "Proxy.h"
#include "ConsumerAdmin.h"

#include "orbsvcs/CosEventChannelAdminC.h"

class TAO_Notify_Consumer;
class TAO_Notify_Method_Request_Dispatch_No_Copy;
/**
 * @class TAO_Notify_ProxySupplier
 *
 * @brief Base class for all the ProxySuppliers.
 *
 */
class TAO_Notify_Serv_Export TAO_Notify_ProxySupplier : public virtual TAO_Notify_Proxy
{
  friend class TAO_Notify_Consumer;

public:
  typedef TAO_Notify_Refcountable_Guard_T<TAO_Notify_ProxySupplier> Ptr;
  /// Constuctor
  TAO_Notify_ProxySupplier (void);

  /// Destructor
  virtual ~TAO_Notify_ProxySupplier ();

  /// Init
  virtual void init (TAO_Notify_ConsumerAdmin* consumer_admin ACE_ENV_ARG_DECL);

  /// Connect
  void connect (TAO_Notify_Consumer* consumer ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
                     CORBA::SystemException
                     , CosEventChannelAdmin::AlreadyConnected
                     ));
  /// Disconnect
  void disconnect (ACE_ENV_SINGLE_ARG_DECL);

  /// Dispatch Event to consumer
  virtual void deliver (TAO_Notify_Method_Request_Dispatch_No_Copy & request ACE_ENV_ARG_DECL);

  /// Override TAO_Notify_Container_T::shutdown  method
  virtual int shutdown (ACE_ENV_SINGLE_ARG_DECL);

  /// Destroy this object.
  virtual void destroy (ACE_ENV_SINGLE_ARG_DECL);

  /// Override, TAO_Notify_Proxy::qos_changed to apply MaxEventssPerConsumer QoS.
  virtual void qos_changed (const TAO_Notify_QoSProperties& qos_properties);

  /// Returns true if connected
  bool is_connected (void) const;

  /// Access the Consumer
  TAO_Notify_Consumer* consumer (void);

  /// The CA parent.
  TAO_Notify_ConsumerAdmin& consumer_admin (void);

private:
  ///= Data Members.
  /// The CA parent.
  TAO_Notify_ConsumerAdmin::Ptr consumer_admin_;

  /// The Consumer that we're connect to.
  ACE_Auto_Ptr<TAO_Notify_Consumer> consumer_;

  /// Access our Peer.
  virtual TAO_Notify_Peer* peer (void);
};

#if defined (__ACE_INLINE__)
#include "ProxySupplier.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* TAO_Notify_PROXYSUPPLIER_H */

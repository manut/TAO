// $Id$

#include "CEC_SupplierAdmin.h"
#include "CEC_ProxyPushConsumer.h"
#include "CEC_ProxyPushSupplier.h"
#include "CEC_EventChannel.h"

#if ! defined (__ACE_INLINE__)
#include "CEC_SupplierAdmin.i"
#endif /* __ACE_INLINE__ */

ACE_RCSID(CosEvent, CEC_SupplierAdmin, "$Id$")

TAO_CEC_SupplierAdmin::TAO_CEC_SupplierAdmin (TAO_CEC_EventChannel *ec)
  :  event_channel_ (ec)
{
  this->collection_ =
    this->event_channel_->create_proxy_push_consumer_collection ();

  // @@
  // @@ this->collection_->busy_hwm (this->event_channel_->busy_hwm ());
  // @@ this->collection_->max_write_delay (
  // @@           this->event_channel_->max_write_delay ()
  // @@ );

  this->default_POA_ =
    this->event_channel_->supplier_poa ();
}

TAO_CEC_SupplierAdmin::~TAO_CEC_SupplierAdmin (void)
{
  this->event_channel_->destroy_proxy_push_consumer_collection (this->collection_);
  this->collection_ = 0;
}

PortableServer::POA_ptr
TAO_CEC_SupplierAdmin::_default_POA (CORBA::Environment&)
{
  return PortableServer::POA::_duplicate (this->default_POA_.in ());
}

void
TAO_CEC_SupplierAdmin::connected (TAO_CEC_ProxyPushSupplier *supplier,
                                  CORBA::Environment &ACE_TRY_ENV)
{
  TAO_CEC_Connect_Supplier worker (supplier);
  this->collection_->for_each (&worker, ACE_TRY_ENV);
}

void
TAO_CEC_SupplierAdmin::reconnected (TAO_CEC_ProxyPushSupplier *supplier,
                                    CORBA::Environment &ACE_TRY_ENV)
{
  TAO_CEC_Reconnect_Supplier worker (supplier);
  this->collection_->for_each (&worker, ACE_TRY_ENV);
}

void
TAO_CEC_SupplierAdmin::disconnected (TAO_CEC_ProxyPushSupplier *supplier,
                                     CORBA::Environment &ACE_TRY_ENV)
{
  TAO_CEC_Disconnect_Supplier worker (supplier);
  this->collection_->for_each (&worker, ACE_TRY_ENV);
}

void
TAO_CEC_SupplierAdmin::connected (TAO_CEC_ProxyPushConsumer *consumer,
                                 CORBA::Environment &ACE_TRY_ENV)
{
  this->collection_->connected (consumer, ACE_TRY_ENV);
}

void
TAO_CEC_SupplierAdmin::reconnected (TAO_CEC_ProxyPushConsumer *consumer,
                                    CORBA::Environment &ACE_TRY_ENV)
{
  this->collection_->reconnected (consumer, ACE_TRY_ENV);
}

void
TAO_CEC_SupplierAdmin::disconnected (TAO_CEC_ProxyPushConsumer *consumer,
                                     CORBA::Environment &ACE_TRY_ENV)
{
  this->collection_->disconnected (consumer, ACE_TRY_ENV);
}

void
TAO_CEC_SupplierAdmin::shutdown (CORBA::Environment &ACE_TRY_ENV)
{
  TAO_CEC_Shutdown_Consumer worker;

  this->collection_->for_each (&worker, ACE_TRY_ENV);
  this->collection_->shutdown (ACE_TRY_ENV);
}

CosEventChannelAdmin::ProxyPushConsumer_ptr
TAO_CEC_SupplierAdmin::obtain_push_consumer (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_CEC_ProxyPushConsumer* consumer =
    this->event_channel_->create_proxy_push_consumer ();

  return consumer->_this (ACE_TRY_ENV);
}

CosEventChannelAdmin::ProxyPullConsumer_ptr
TAO_CEC_SupplierAdmin::obtain_pull_consumer (CORBA::Environment &)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // @@
  return CosEventChannelAdmin::ProxyPullConsumer::_nil ();
}

// ****************************************************************

void
TAO_CEC_Connect_Supplier::work (TAO_CEC_ProxyPushConsumer *consumer,
                                CORBA::Environment &ACE_TRY_ENV)
{
  consumer->connected (this->supplier_, ACE_TRY_ENV);
  ACE_CHECK;
  this->supplier_->connected (consumer, ACE_TRY_ENV);
  ACE_CHECK;
}

// ****************************************************************

void
TAO_CEC_Reconnect_Supplier::work (TAO_CEC_ProxyPushConsumer *consumer,
                                  CORBA::Environment &ACE_TRY_ENV)
{
  consumer->reconnected (this->supplier_, ACE_TRY_ENV);
  ACE_CHECK;
  this->supplier_->reconnected (consumer, ACE_TRY_ENV);
  ACE_CHECK;
}

// ****************************************************************

void
TAO_CEC_Disconnect_Supplier::work (TAO_CEC_ProxyPushConsumer *consumer,
                                   CORBA::Environment &ACE_TRY_ENV)
{
  consumer->disconnected (this->supplier_, ACE_TRY_ENV);
  ACE_CHECK;
  this->supplier_->disconnected (consumer, ACE_TRY_ENV);
  ACE_CHECK;
}

// ****************************************************************

void
TAO_CEC_Shutdown_Consumer::work (TAO_CEC_ProxyPushConsumer *consumer,
                                 CORBA::Environment &ACE_TRY_ENV)
{
  ACE_TRY
    {
      consumer->shutdown (ACE_TRY_ENV);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      // Ignore exceptions
    }
  ACE_ENDTRY;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class TAO_EC_Worker<TAO_CEC_ProxyPushConsumer>;

#elif defined(ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#pragma instantiate TAO_EC_Worker<TAO_CEC_ProxyPushConsumer>

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

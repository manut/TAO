// -*- C++ -*-

//=============================================================================
/**
 *  @file   FTEC_ProxyConsumer.h
 *
 *  $Id$
 *
 *  @author Huang-Ming Huang <hh1@cse.wustl.edu>
 */
//=============================================================================
#ifndef TAO_FTEC_PROXYCONSUMER_H
#define TAO_FTEC_PROXYCONSUMER_H

#include "orbsvcs/orbsvcs/Event/EC_Default_ProxyConsumer.h"
#include "ace/SString.h"
#include "orbsvcs/orbsvcs/FtRtecEventChannelAdminC.h"
#include "Request_Context_Repository.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class TAO_FTEC_ProxyPushConsumer : public TAO_EC_Default_ProxyPushConsumer
{
  typedef TAO_EC_Default_ProxyPushConsumer Inherited;
public:
  typedef RtecEventChannelAdmin::ProxyPushConsumer Interface;
  typedef FtRtecEventChannelAdmin::ProxyPushConsumerStat State;
  typedef POA_RtecEventChannelAdmin::ProxyPushConsumer_ptr Skeleton;

  TAO_FTEC_ProxyPushConsumer (TAO_EC_Event_Channel_Base* event_channel);

  virtual void activate (
     RtecEventChannelAdmin::ProxyPushConsumer_ptr &proxy
     ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));


    // = The RtecEventChannelAdmin::ProxyPushConsumer methods...
  virtual void connect_push_supplier (
                RtecEventComm::PushSupplier_ptr push_supplier,
                const RtecEventChannelAdmin::SupplierQOS& qos
                ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       RtecEventChannelAdmin::AlreadyConnected));
  virtual void disconnect_push_consumer (ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC ((CORBA::SystemException));

  const FtRtecEventChannelAdmin::ObjectId& id() const;
  void get_state(FtRtecEventChannelAdmin::ProxyPushConsumerStat& state);
  void set_state(const FtRtecEventChannelAdmin::ProxyPushConsumerStat& state
                 ACE_ENV_ARG_DECL);

  typedef void (FtRtecEventChannelAdmin::EventChannelFacade::*RollbackOperation)
    (const FtRtecEventChannelAdmin::ObjectId& ACE_ENV_ARG_DECL_WITH_DEFAULTS);

  static const RollbackOperation rollback_obtain;
private:
  FtRtecEventChannelAdmin::ObjectId_var object_id_;
};

#endif

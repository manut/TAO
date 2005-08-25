/* -*- C++ -*- */
/**
 *  @file   EC_TPC_ProxyConsumer.h
 *
 *  $Id$
 *
 *  @author Chris Cleeland <cleeland at ociweb.com >
 *
 */

#ifndef TAO_EC_TPC_PROXYCONSUMER_H
#define TAO_EC_TPC_PROXYCONSUMER_H
#include "ace/pre.h"

#include "EC_Default_ProxyConsumer.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class TAO_EC_Dispatching;
class TAO_EC_TPC_Dispatching;

/**
 * @class TAO_EC_TPC_ProxyPushConsumer
 *
 */
class TAO_RTEvent_Serv_Export TAO_EC_TPC_ProxyPushConsumer :
  public TAO_EC_Default_ProxyPushConsumer
{
public:
  TAO_EC_TPC_ProxyPushConsumer (TAO_EC_Event_Channel_Base* ec);
  virtual ~TAO_EC_TPC_ProxyPushConsumer (void);

  virtual void disconnect_push_consumer (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((CORBA::SystemException));

private:
  typedef TAO_EC_Default_ProxyPushConsumer BASECLASS;
  TAO_EC_TPC_Dispatching* tpc_dispatching ();
};

#include "ace/post.h"

#endif

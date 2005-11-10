// $Id$

#include "CEC_ConsumerControl.h"

ACE_RCSID (CosEvent,
           CEC_ConsumerControl,
           "$Id$")


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_CEC_ConsumerControl::TAO_CEC_ConsumerControl (void)
{
}

TAO_CEC_ConsumerControl::~TAO_CEC_ConsumerControl (void)
{
}

int
TAO_CEC_ConsumerControl::activate (void)
{
  return 0;
}

int
TAO_CEC_ConsumerControl::shutdown (void)
{
  return 0;
}

void
TAO_CEC_ConsumerControl::consumer_not_exist (TAO_CEC_ProxyPushSupplier *
                                             ACE_ENV_ARG_DECL_NOT_USED)
{
}

void
TAO_CEC_ConsumerControl::consumer_not_exist (TAO_CEC_ProxyPullSupplier *
                                             ACE_ENV_ARG_DECL_NOT_USED)
{
}

void
TAO_CEC_ConsumerControl::system_exception (TAO_CEC_ProxyPushSupplier *,
                                           CORBA::SystemException &
                                           ACE_ENV_ARG_DECL_NOT_USED)
{
}

bool
TAO_CEC_ConsumerControl::need_to_disconnect (PortableServer::ServantBase*)
{
  return true;
}

void
TAO_CEC_ConsumerControl::successful_transmission (PortableServer::ServantBase*)
{
}

TAO_ENDBEGIN_VERSIONED_NAMESPACE_DECL

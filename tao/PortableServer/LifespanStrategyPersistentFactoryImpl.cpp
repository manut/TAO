// $Id$

#include "LifespanStrategyPersistentFactoryImpl.h"
#include "ace/Dynamic_Service.h"
#include "LifespanStrategyPersistent.h"

ACE_RCSID (PortableServer,
           LifespanStrategyFactoryImpl,
           "$Id$")

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO
{
  namespace Portable_Server
  {
    LifespanStrategy*
    LifespanStrategyPersistentFactoryImpl::create (
      ::PortableServer::LifespanPolicyValue value)
    {
      LifespanStrategy* strategy = 0;

      switch (value)
      {
        case ::PortableServer::PERSISTENT :
        {
          ACE_NEW_RETURN (strategy, LifespanStrategyPersistent, 0);
          break;
        }
        case ::PortableServer::TRANSIENT :
        {
          ACE_ERROR ((LM_ERROR, "Incorrect type in LifespanStrategyPersistentFactoryImpl"));
          break;
        }
      }

      return strategy;
    }

    void
    LifespanStrategyPersistentFactoryImpl::destroy (
      LifespanStrategy *strategy
      ACE_ENV_ARG_DECL)
    {
      strategy->strategy_cleanup (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;

      delete strategy;
    }
  }
}

TAO_END_VERSIONED_NAMESPACE_DECL

ACE_STATIC_SVC_DEFINE (
  LifespanStrategyPersistentFactoryImpl,
  ACE_TEXT ("LifespanStrategyPersistentFactory"),
  ACE_SVC_OBJ_T,
  &ACE_SVC_NAME (LifespanStrategyPersistentFactoryImpl),
  ACE_Service_Type::DELETE_THIS | ACE_Service_Type::DELETE_OBJ,
  0)

ACE_FACTORY_NAMESPACE_DEFINE (
  ACE_Local_Service,
  LifespanStrategyPersistentFactoryImpl,
  TAO::Portable_Server::LifespanStrategyPersistentFactoryImpl)


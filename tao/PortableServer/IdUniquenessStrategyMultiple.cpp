// $Id$

#include "IdUniquenessStrategyMultiple.h"

ACE_RCSID (PortableServer,
           Id_Uniqueness_Strategy,
           "$Id$")


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO
{
  namespace Portable_Server
  {
    void
    IdUniquenessStrategyMultiple::strategy_init (
      TAO_Root_POA * /*poa*/
      ACE_ENV_ARG_DECL_NOT_USED)
    {
    }

    void
    IdUniquenessStrategyMultiple::strategy_cleanup(
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
    {
    }

    bool
    IdUniquenessStrategyMultiple::is_servant_activation_allowed (
      PortableServer::Servant /*servant*/,
      int & /*wait_occurred_restart_call*/)
    {
      // With the multiple id strategy we can always activate the servant
      // another time
      return true;
    }

    bool
    IdUniquenessStrategyMultiple::allow_multiple_activations (void) const
    {
      return true;
    }

    ::PortableServer::IdUniquenessPolicyValue
    IdUniquenessStrategyMultiple::type() const
    {
      return ::PortableServer::MULTIPLE_ID;
    }

  }
}

TAO_END_VERSIONED_NAMESPACE_DECL

ACE_FACTORY_NAMESPACE_DEFINE (
  ACE_Local_Service,
  IdUniquenessStrategyMultiple,
  TAO::Portable_Server::IdUniquenessStrategyMultiple)

ACE_STATIC_SVC_DEFINE (
  IdUniquenessStrategyMultiple,
  ACE_TEXT ("IdUniquenessStrategyMultiple"),
  ACE_SVC_OBJ_T,
  &ACE_SVC_NAME (IdUniquenessStrategyMultiple),
  ACE_Service_Type::DELETE_THIS | ACE_Service_Type::DELETE_OBJ,
  0)

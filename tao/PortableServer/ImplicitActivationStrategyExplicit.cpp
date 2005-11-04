// -*- C++ -*-

#include "ImplicitActivationStrategyExplicit.h"

ACE_RCSID (PortableServer,
           ImplicitActivationStrategyExplicit,
           "$Id$")

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO
{
  namespace Portable_Server
  {
    bool
    ImplicitActivationStrategyExplicit::allow_implicit_activation (void) const
    {
      return false;
    }
  }
}

TAO_END_VERSIONED_NAMESPACE_DECL


namespace TAO
{
  namespace Portable_Server
  {
    ACE_FACTORY_DEFINE (ACE_Local_Service, ImplicitActivationStrategyExplicit)

    ACE_STATIC_SVC_DEFINE (
        ImplicitActivationStrategyExplicit,
        ACE_TEXT ("ImplicitActivationStrategyExplicit"),
        ACE_SVC_OBJ_T,
        &ACE_SVC_NAME (ImplicitActivationStrategyExplicit),
        ACE_Service_Type::DELETE_THIS | ACE_Service_Type::DELETE_OBJ,
        0
      )
  }
}


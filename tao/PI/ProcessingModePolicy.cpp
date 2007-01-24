// $Id$

#include "tao/PI/ProcessingModePolicy.h"

#if TAO_HAS_INTERCEPTORS == 1

#include "tao/PortableInterceptorC.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_RCSID (tao,
           ProcessingModePolicy,
           "$Id$")

// Should this all be wrapped in #if (TAO_HAS_MINIMUM_POA == 0)?

TAO_ProcessingModePolicy::TAO_ProcessingModePolicy
                         (PortableInterceptor::ProcessingMode mode)
  : processing_mode_ (mode)
{
}

CORBA::Policy_ptr
TAO_ProcessingModePolicy::copy (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_ProcessingModePolicy *copy = 0;
  ACE_NEW_THROW_EX (copy,
                    TAO_ProcessingModePolicy (this->processing_mode_),
                    CORBA::NO_MEMORY ());

  return copy;
}

void
TAO_ProcessingModePolicy::destroy (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
}

PortableInterceptor::ProcessingMode
TAO_ProcessingModePolicy::processing_mode (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return processing_mode_;
}

CORBA::PolicyType
TAO_ProcessingModePolicy::policy_type (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return PortableInterceptor::PROCESSING_MODE_POLICY_TYPE;
}

TAO_END_VERSIONED_NAMESPACE_DECL

#endif  /* TAO_HAS_INTERCEPTORS == 1 */


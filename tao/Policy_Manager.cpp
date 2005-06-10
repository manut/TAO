// $Id$

#include "Policy_Manager.h"

#if (TAO_HAS_CORBA_MESSAGING == 1)

#if !defined (__ACE_INLINE__)
# include "tao/Policy_Manager.i"
#endif /* ! __ACE_INLINE__ */


ACE_RCSID (tao,
           Policy_Manager,
           "$Id$")


CORBA::PolicyList *
TAO_Policy_Manager::get_policy_overrides (const CORBA::PolicyTypeSeq & ts
                                          ACE_ENV_ARG_DECL)
     ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_GUARD_RETURN (TAO_SYNCH_MUTEX, ace_mon, this->mutex_, 0);
  return this->impl_.get_policy_overrides (ts ACE_ENV_ARG_PARAMETER);
}

void
TAO_Policy_Manager::set_policy_overrides (const CORBA::PolicyList & policies,
                                          CORBA::SetOverrideType set_add
                                          ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   CORBA::InvalidPolicies))
{
  ACE_GUARD (TAO_SYNCH_MUTEX, ace_mon, this->mutex_);
  this->impl_.set_policy_overrides (policies, set_add ACE_ENV_ARG_PARAMETER);
}

#endif /* TAO_HAS_CORBA_MESSAGING == 1 */

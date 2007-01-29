// $Id$

#include "tao/Messaging/Messaging_Policy_i.h"
#include "tao/Stub.h"
#include "tao/ORB_Core.h"
#include "tao/debug.h"
#include "tao/AnyTypeCode/Any.h"

#if ! defined (__ACE_INLINE__)
#include "tao/Messaging/Messaging_Policy_i.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID (Messaging,
           Messaging_Policy_i,
           "$Id$")

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

#if (TAO_HAS_RELATIVE_ROUNDTRIP_TIMEOUT_POLICY == 1)

TAO_RelativeRoundtripTimeoutPolicy::TAO_RelativeRoundtripTimeoutPolicy (
  const TimeBase::TimeT& relative_expiry)
  : ::CORBA::Object ()
  , ::CORBA::Policy ()
  , ::CORBA::LocalObject ()
  , Messaging::RelativeRoundtripTimeoutPolicy ()
  , TAO_Local_RefCounted_Object ()
  , relative_expiry_ (relative_expiry)
{
}

TAO_RelativeRoundtripTimeoutPolicy::TAO_RelativeRoundtripTimeoutPolicy (
  const TAO_RelativeRoundtripTimeoutPolicy &rhs)
  : ::CORBA::Object ()
  , ::CORBA::Policy ()
  , ::CORBA::LocalObject ()
  , Messaging::RelativeRoundtripTimeoutPolicy ()
  , TAO_Local_RefCounted_Object ()
  , relative_expiry_ (rhs.relative_expiry_)
{
}

TimeBase::TimeT
TAO_RelativeRoundtripTimeoutPolicy::relative_expiry (
    void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->relative_expiry_;
}

CORBA::PolicyType
TAO_RelativeRoundtripTimeoutPolicy::policy_type (
    void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return Messaging::RELATIVE_RT_TIMEOUT_POLICY_TYPE;
}

void
TAO_RelativeRoundtripTimeoutPolicy::hook (TAO_ORB_Core *orb_core,
                                          TAO_Stub *stub,
                                          bool &has_timeout,
                                          ACE_Time_Value &time_value)
{
  try
    {
      CORBA::Policy_var policy = 0;

      if (stub == 0)
        {
          policy =
            orb_core->get_cached_policy_including_current (
              TAO_CACHED_POLICY_RELATIVE_ROUNDTRIP_TIMEOUT
             );
        }
      else
        {
          policy =
            stub->get_cached_policy (TAO_CACHED_POLICY_RELATIVE_ROUNDTRIP_TIMEOUT
                                    );
        }

      if (CORBA::is_nil (policy.in ()))
        {
          has_timeout = false;
          return;
        }

      Messaging::RelativeRoundtripTimeoutPolicy_var p =
        Messaging::RelativeRoundtripTimeoutPolicy::_narrow (
          policy.in ()
         );

      TimeBase::TimeT t = p->relative_expiry ();
      TimeBase::TimeT seconds = t / 10000000u;
      TimeBase::TimeT microseconds = (t % 10000000u) / 10;
      time_value.set (ACE_U64_TO_U32 (seconds),
                      ACE_U64_TO_U32 (microseconds));

      // Set the flag once all operations complete successfully
      has_timeout = true;

      if (TAO_debug_level > 0)
        {
          ACE_DEBUG ((LM_DEBUG,
                      ACE_TEXT ("TAO (%P|%t) - Request timeout is <%dms>\n"),
                      time_value.msec ()));
        }
    }
  catch (const ::CORBA::Exception&)
    {
      // Ignore all exceptions...
    }
}

CORBA::Policy_ptr
TAO_RelativeRoundtripTimeoutPolicy::create (const CORBA::Any& val)
{
  // Future policy implementors: notice how the following code is
  // exception safe!

  TimeBase::TimeT value;
  if ((val >>= value) == 0)
    ACE_THROW_RETURN (CORBA::PolicyError (CORBA::BAD_POLICY_VALUE),
                      CORBA::Policy::_nil ());

  TAO_RelativeRoundtripTimeoutPolicy *tmp = 0;
  ACE_NEW_THROW_EX (tmp,
                    TAO_RelativeRoundtripTimeoutPolicy (value),
                    CORBA::NO_MEMORY (TAO::VMCID,
                                      CORBA::COMPLETED_NO));

  return tmp;
}

TAO_RelativeRoundtripTimeoutPolicy *
TAO_RelativeRoundtripTimeoutPolicy::clone (void) const
{
  TAO_RelativeRoundtripTimeoutPolicy *copy = 0;
  ACE_NEW_RETURN (copy,
                  TAO_RelativeRoundtripTimeoutPolicy (*this),
                  0);
  return copy;
}

CORBA::Policy_ptr
TAO_RelativeRoundtripTimeoutPolicy::copy (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Future policy implementors: notice how the following code is
  // exception safe!

  TAO_RelativeRoundtripTimeoutPolicy* tmp = 0;
  ACE_NEW_THROW_EX (tmp, TAO_RelativeRoundtripTimeoutPolicy (*this),
                    CORBA::NO_MEMORY (TAO::VMCID,
                                      CORBA::COMPLETED_NO));

  return tmp;
}

void
TAO_RelativeRoundtripTimeoutPolicy::destroy (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
}

TAO_Cached_Policy_Type
TAO_RelativeRoundtripTimeoutPolicy::_tao_cached_type (void) const
{
  return TAO_CACHED_POLICY_RELATIVE_ROUNDTRIP_TIMEOUT;
}

void
TAO_RelativeRoundtripTimeoutPolicy::set_time_value (ACE_Time_Value &time_value)
{
  TimeBase::TimeT t = this->relative_expiry_;
  TimeBase::TimeT seconds = t / 10000000u;
  TimeBase::TimeT microseconds = (t % 10000000u) / 10;
  time_value.set (ACE_U64_TO_U32 (seconds),
                  ACE_U64_TO_U32 (microseconds));

  if (TAO_debug_level > 0)
    {
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("TAO (%P|%t) - Request timeout is <%dms>\n"),
                  time_value.msec ()));
    }
}

#endif /* TAO_HAS_RELATIVE_ROUNDTRIP_TIMEOUT_POLICY == 1 */

// ****************************************************************

#if (TAO_HAS_SYNC_SCOPE_POLICY == 1)

TAO_Sync_Scope_Policy::TAO_Sync_Scope_Policy (Messaging::SyncScope synchronization)
  : ::CORBA::Object ()
  , ::CORBA::Policy ()
  , ::CORBA::LocalObject ()
  , Messaging::SyncScopePolicy ()
  , TAO_Local_RefCounted_Object ()
  , synchronization_ (synchronization)
{
}

TAO_Sync_Scope_Policy::TAO_Sync_Scope_Policy (const TAO_Sync_Scope_Policy &rhs)
  : ::CORBA::Object ()
  , ::CORBA::Policy ()
  , ::CORBA::LocalObject ()
  , Messaging::SyncScopePolicy ()
  , TAO_Local_RefCounted_Object ()
  , synchronization_ (rhs.synchronization_)
{
}

CORBA::PolicyType
TAO_Sync_Scope_Policy::policy_type (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return Messaging::SYNC_SCOPE_POLICY_TYPE;
}

void
TAO_Sync_Scope_Policy::hook (TAO_ORB_Core *orb_core,
                             TAO_Stub *stub,
                             bool &has_synchronization,
                             Messaging::SyncScope &scope)
{
  try
    {
      CORBA::Policy_var policy = 0;

      if (stub == 0)
        {
          policy =
            orb_core->get_cached_policy_including_current (
              TAO_CACHED_POLICY_SYNC_SCOPE
             );
        }
      else
        {
          policy =
            stub->get_cached_policy (TAO_CACHED_POLICY_SYNC_SCOPE
                                    );
        }

      if (CORBA::is_nil (policy.in ()))
        {
          has_synchronization = false;
          return;
        }
      Messaging::SyncScopePolicy_var p =
        Messaging::SyncScopePolicy::_narrow (policy.in ());

      if (CORBA::is_nil (p.in ()))
        throw ::CORBA::INTERNAL (
                CORBA::SystemException::_tao_minor_code (
                  TAO_POLICY_NARROW_CODE,
                  0),
                CORBA::COMPLETED_NO);

      has_synchronization = true;
      scope = p->synchronization ();
    }
  catch (const ::CORBA::Exception&)
    {
      // Ignore all exceptions...
    }
}

CORBA::Policy_ptr
TAO_Sync_Scope_Policy::create (const CORBA::Any& val
                               )
{
  Messaging::SyncScope synchronization;
  if ((val >>= synchronization) == 0)
    ACE_THROW_RETURN (CORBA::PolicyError (CORBA::BAD_POLICY_VALUE),
                      CORBA::Policy::_nil ());

  TAO_Sync_Scope_Policy *servant = 0;
  ACE_NEW_THROW_EX (servant,
                    TAO_Sync_Scope_Policy (synchronization),
                    CORBA::NO_MEMORY ());

  return servant;
}

TAO_Sync_Scope_Policy *
TAO_Sync_Scope_Policy::clone (void) const
{
  TAO_Sync_Scope_Policy *copy = 0;
  ACE_NEW_RETURN (copy,
                  TAO_Sync_Scope_Policy (*this),
                  0);
  return copy;
}

Messaging::SyncScope
TAO_Sync_Scope_Policy::synchronization (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->synchronization_;
}

CORBA::Policy_ptr
TAO_Sync_Scope_Policy::copy (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_Sync_Scope_Policy *servant = 0;
  ACE_NEW_THROW_EX (servant,
                    TAO_Sync_Scope_Policy (*this),
                    CORBA::NO_MEMORY ());

  return servant;
}

void
TAO_Sync_Scope_Policy::destroy (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
}
TAO_Cached_Policy_Type
TAO_Sync_Scope_Policy::_tao_cached_type (void) const
{
  return TAO_CACHED_POLICY_SYNC_SCOPE;
}

#endif /* TAO_HAS_SYNC_SCOPE_POLICY == 1 */

TAO_END_VERSIONED_NAMESPACE_DECL

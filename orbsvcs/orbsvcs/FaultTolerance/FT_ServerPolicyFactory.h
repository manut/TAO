// -*- C++ -*-

//=============================================================================
/**
 *  @file     FT_ServerPolicyFactory.h
 *
 *  $Id$
 *
 *  @author  Bala Natarajan <bala@cs.wustl.edu>
 */
//=============================================================================


#ifndef TAO_FT_SERVERPOLICY_FACTORY_H
#define TAO_FT_SERVERPOLICY_FACTORY_H

#include /**/ "ace/pre.h"

#include "tao/PI/PI.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/LocalObject.h"

// This is to remove "inherits via dominance" warnings from MSVC.
// MSVC is being a little too paranoid.
#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#include "orbsvcs/FaultTolerance/FT_ServerORB_export.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

/// Policy factory for all FTCORBA related policies.
class TAO_FT_ServerPolicyFactory
  : public PortableInterceptor::PolicyFactory
  , public TAO_Local_RefCounted_Object
{
public:

  virtual CORBA::Policy_ptr create_policy (CORBA::PolicyType type,
                                           const CORBA::Any &value)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     CORBA::PolicyError));
};

TAO_END_VERSIONED_NAMESPACE_DECL

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#include /**/ "ace/post.h"

#endif /* TAO_FT_POLICY_FACTORY_H */

// -*- C++ -*-

//=============================================================================
/**
 *  @file   RT_Current.h
 *
 *  $Id$
 *
 *  @author Carlos O'Ryan (coryan@cs.wustl.edu)
 */
//=============================================================================


#ifndef TAO_RT_CURRENT_H
#define TAO_RT_CURRENT_H
#include /**/ "ace/pre.h"

#include "tao/orbconf.h"

#if defined (TAO_HAS_CORBA_MESSAGING) && TAO_HAS_CORBA_MESSAGING != 0

#define TAO_RTCORBA_SAFE_INCLUDE
#include "RTCORBAC.h"
#undef TAO_RTCORBA_SAFE_INCLUDE

#include "tao/LocalObject.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

/**
 * @class TAO_RT_Current
 *
 * @brief RTCORBA::Current interface iplementation.
 *
 * Allows setting/getting the priority of the current thread.
 */
class TAO_RTCORBA_Export TAO_RT_Current
  : public RTCORBA::Current,
    public TAO_Local_RefCounted_Object
{
public:

  /// Default constructor.
  TAO_RT_Current (TAO_ORB_Core *orb_core);

  virtual RTCORBA::Priority the_priority (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void the_priority (RTCORBA::Priority the_priority
                             ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

protected:

  /// Protected destructor to enforce proper memory management of this
  /// reference counted object.
  virtual ~TAO_RT_Current (void);

private:

  /// ORB Core that owns us.
  TAO_ORB_Core *orb_core_;

};

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#endif /* TAO_HAS_CORBA_MESSAGING && TAO_HAS_CORBA_MESSAGING != 0 */

#include /**/ "ace/post.h"
#endif /* TAO_RT_CURRENT_H */

/* -*- C++ -*- */
//
// $Id$
//
// ================================================================
//
// = LIBRARY
//   TAO
//
// = FILENAME
//   PollableC.h
//
// = DESCRIPTION
//   Generated from Pollable.pidl
//   The code was generated by the IDL compiler and then hand-crafted
//   to reduce the includes interdependencies.
//
// ================================================================

#ifndef TAO_IDL_POLLABLES_H
#define TAO_IDL_POLLABLES_H
#include "ace/pre.h"

#include "tao/PollableC.h"

#if (TAO_HAS_CORBA_MESSAGING == 1) && (TAO_HAS_AMI_POLLER == 1)

#include "tao/POA_CORBA.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if 0
TAO_NAMESPACE  POA_CORBA
{

#if defined (ACE_HAS_USING_KEYWORD)
  // TIE class: Refer to CORBA v2.2, Section 20.34.4
  template <class T>
  class TAO_Export Pollable_tie : public Pollable
  {
  public:
    Pollable_tie (T &t);
    // the T& ctor
    Pollable_tie (T &t, PortableServer::POA_ptr poa);
    // ctor taking a POA
    Pollable_tie (T *tp, CORBA::Boolean release=1);
    // ctor taking pointer and an ownership flag
    Pollable_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release=1);
    // ctor with T*, ownership flag and a POA
    ~Pollable_tie (void);
    // dtor

    // TIE specific functions
    T *_tied_object (void);
    // return the underlying object
    void _tied_object (T &obj);
    // set the underlying object
    void _tied_object (T *obj, CORBA::Boolean release=1);
    // set the underlying object and the ownership flag
    CORBA::Boolean _is_owner (void);
    // do we own it
    void _is_owner (CORBA::Boolean b);
    // set the ownership

    // overridden ServantBase operations
    PortableServer::POA_ptr _default_POA (
        CORBA::Environment &ACE_TRY_ENV =
          CORBA::Environment::default_environment ()
      );
    CORBA::Boolean is_ready (
        CORBA::ULong timeout,
        CORBA::Environment &ACE_TRY_ENV =
          CORBA::Environment::default_environment ()
      );
    CORBA::PollableSet_ptr create_pollable_set (
        CORBA::Environment &ACE_TRY_ENV =
          CORBA::Environment::default_environment ()
      );
private:
    T *ptr_;
    PortableServer::POA_var poa_;
    CORBA::Boolean rel_;

    // copy and assignment are not allowed
    Pollable_tie (const Pollable_tie &);
    void operator= (const Pollable_tie &);
  };

#endif /* ACE_HAS_USING_KEYWORD */


#if defined (ACE_HAS_USING_KEYWORD)
  // TIE class: Refer to CORBA v2.2, Section 20.34.4
  template <class T>
  class TAO_Export DIIPollable_tie : public DIIPollable
  {
  public:
    DIIPollable_tie (T &t);
    // the T& ctor
    DIIPollable_tie (T &t, PortableServer::POA_ptr poa);
    // ctor taking a POA
    DIIPollable_tie (T *tp, CORBA::Boolean release=1);
    // ctor taking pointer and an ownership flag
    DIIPollable_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release=1);
    // ctor with T*, ownership flag and a POA
    ~DIIPollable_tie (void);
    // dtor

    // TIE specific functions
    T *_tied_object (void);
    // return the underlying object
    void _tied_object (T &obj);
    // set the underlying object
    void _tied_object (T *obj, CORBA::Boolean release=1);
    // set the underlying object and the ownership flag
    CORBA::Boolean _is_owner (void);
    // do we own it
    void _is_owner (CORBA::Boolean b);
    // set the ownership

    // overridden ServantBase operations
    PortableServer::POA_ptr _default_POA (
        CORBA::Environment &ACE_TRY_ENV =
          CORBA::Environment::default_environment ()
      );
    CORBA::Boolean is_ready (
        CORBA::ULong timeout,
        CORBA::Environment &ACE_TRY_ENV =
          CORBA::Environment::default_environment ()
      );
    CORBA::PollableSet_ptr create_pollable_set (
        CORBA::Environment &ACE_TRY_ENV =
          CORBA::Environment::default_environment ()
      );
private:
    T *ptr_;
    PortableServer::POA_var poa_;
    CORBA::Boolean rel_;

    // copy and assignment are not allowed
    DIIPollable_tie (const DIIPollable_tie &);
    void operator= (const DIIPollable_tie &);
  };

#endif /* ACE_HAS_USING_KEYWORD */


#if defined (ACE_HAS_USING_KEYWORD)
  // TIE class: Refer to CORBA v2.2, Section 20.34.4
  template <class T>
  class TAO_Export PollableSet_tie : public PollableSet
  {
  public:
    PollableSet_tie (T &t);
    // the T& ctor
    PollableSet_tie (T &t, PortableServer::POA_ptr poa);
    // ctor taking a POA
    PollableSet_tie (T *tp, CORBA::Boolean release=1);
    // ctor taking pointer and an ownership flag
    PollableSet_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release=1);
    // ctor with T*, ownership flag and a POA
    ~PollableSet_tie (void);
    // dtor

    // TIE specific functions
    T *_tied_object (void);
    // return the underlying object
    void _tied_object (T &obj);
    // set the underlying object
    void _tied_object (T *obj, CORBA::Boolean release=1);
    // set the underlying object and the ownership flag
    CORBA::Boolean _is_owner (void);
    // do we own it
    void _is_owner (CORBA::Boolean b);
    // set the ownership

    // overridden ServantBase operations
    PortableServer::POA_ptr _default_POA (
        CORBA::Environment &ACE_TRY_ENV =
          CORBA::Environment::default_environment ()
      );
    CORBA::DIIPollable_ptr create_dii_pollable (
        CORBA::Environment &ACE_TRY_ENV =
          CORBA::Environment::default_environment ()
      );
    void add_pollable (
        CORBA::Pollable_ptr potential,
        CORBA::Environment &ACE_TRY_ENV =
          CORBA::Environment::default_environment ()
      );
    CORBA::Pollable_ptr poll (
        CORBA::ULong timeout,
        CORBA::Environment &ACE_TRY_ENV =
          CORBA::Environment::default_environment ()
      );
    void remove (
        CORBA::Pollable_ptr potential,
        CORBA::Environment &ACE_TRY_ENV =
          CORBA::Environment::default_environment ()
      );
    CORBA::UShort number_left (
        CORBA::Environment &ACE_TRY_ENV =
          CORBA::Environment::default_environment ()
      );
private:
    T *ptr_;
    PortableServer::POA_var poa_;
    CORBA::Boolean rel_;

    // copy and assignment are not allowed
    PollableSet_tie (const PollableSet_tie &);
    void operator= (const PollableSet_tie &);
  };

#endif /* ACE_HAS_USING_KEYWORD */

}
TAO_NAMESPACE_CLOSE

#include "tao/PollableS_T.h"
#endif /* 0 */

#if defined (__ACE_INLINE__)
#include "tao/PollableS.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#endif /* TAO_HAS_CORBA_MESSAGING == 1 && TAO_HAS_AMI_POLLER == 1 */

#include "ace/post.h"
#endif /* ifndef */

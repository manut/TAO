/* -*- C++ -*- */
// $Id$


// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#ifndef TAO_IDL_DOMAINC_H
#define TAO_IDL_DOMAINC_H
#include "ace/pre.h"

#include "tao/corbafwd.h"
#include "tao/PolicyC.h"
#include "tao/Environment.h"
#include "tao/Any.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export
#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

class TAO_Export CORBA_DomainManager_var
{
public:
  CORBA_DomainManager_var (void); // default constructor
  CORBA_DomainManager_var (CORBA_DomainManager_ptr);
  CORBA_DomainManager_var (const CORBA_DomainManager_var &); // copy constructor
  ~CORBA_DomainManager_var (void); // destructor

  CORBA_DomainManager_var &operator= (CORBA_DomainManager_ptr);
  CORBA_DomainManager_var &operator= (const CORBA_DomainManager_var &);
  CORBA_DomainManager_ptr operator-> (void) const;

  operator const CORBA_DomainManager_ptr &() const;
  operator CORBA_DomainManager_ptr &();
  // in, inout, out, _retn
  CORBA_DomainManager_ptr in (void) const;
  CORBA_DomainManager_ptr &inout (void);
  CORBA_DomainManager_ptr &out (void);
  CORBA_DomainManager_ptr _retn (void);
  CORBA_DomainManager_ptr ptr (void) const;

private:
  CORBA_DomainManager_ptr ptr_;
};

class TAO_Export CORBA_DomainManager_out
{
public:
  CORBA_DomainManager_out (CORBA_DomainManager_ptr &);
  CORBA_DomainManager_out (CORBA_DomainManager_var &);
  CORBA_DomainManager_out (const CORBA_DomainManager_out &);
  CORBA_DomainManager_out &operator= (const CORBA_DomainManager_out &);
  CORBA_DomainManager_out &operator= (const CORBA_DomainManager_var &);
  CORBA_DomainManager_out &operator= (CORBA_DomainManager_ptr);
  operator CORBA_DomainManager_ptr &();
  CORBA_DomainManager_ptr &ptr (void);
  CORBA_DomainManager_ptr operator-> (void);

private:
  CORBA_DomainManager_ptr &ptr_;
};

class TAO_Export CORBA_DomainManager : public virtual CORBA_Object
{
public:
#if !defined(__GNUC__) || __GNUC__ > 2 || __GNUC_MINOR__ >= 8
  typedef CORBA_DomainManager_ptr _ptr_type;
  typedef CORBA_DomainManager_var _var_type;
#endif /* __GNUC__ */

  // the static operations
  static CORBA_DomainManager_ptr _duplicate (CORBA_DomainManager_ptr obj);
  static CORBA_DomainManager_ptr _narrow (
      CORBA::Object_ptr obj,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  static CORBA_DomainManager_ptr _unchecked_narrow (
      CORBA::Object_ptr obj,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  static CORBA_DomainManager_ptr _nil (void);
  static void _tao_any_destructor (void*);

  virtual CORBA::Policy_ptr get_domain_policy (
      CORBA::PolicyType policy_type,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  virtual CORBA::Boolean _is_a (
      const CORBA::Char *type_id,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  virtual const char* _interface_repository_id (void) const;

protected:
  CORBA_DomainManager (void);
  CORBA_DomainManager (TAO_Stub *objref,
      TAO_ServantBase *_tao_servant = 0,
      CORBA::Boolean _tao_collocated = 0
    );
  virtual ~CORBA_DomainManager (void);
private:
  CORBA_DomainManager (const CORBA_DomainManager &);
  void operator= (const CORBA_DomainManager &);
};

// *************************************************************
// DomainManagerList
// *************************************************************

class TAO_Export CORBA_DomainManagerList : public TAO_Unbounded_Object_Sequence<CORBA_DomainManager,CORBA_DomainManager_var>
{
public:
  CORBA_DomainManagerList (void); // default ctor
  CORBA_DomainManagerList (CORBA::ULong max); // uses max size
  CORBA_DomainManagerList (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA_DomainManager_ptr *buffer,
    CORBA::Boolean release=0
  );
  CORBA_DomainManagerList (const CORBA_DomainManagerList &); // copy ctor
  ~CORBA_DomainManagerList (void); // dtor
  static void _tao_any_destructor (void*);
};

typedef CORBA_DomainManagerList *CORBA_DomainManagerList_ptr;

// *************************************************************
// class CORBA::DomainManagerList_var
// *************************************************************

class TAO_Export CORBA_DomainManagerList_var
{
public:
  CORBA_DomainManagerList_var (void); // default constructor
  CORBA_DomainManagerList_var (CORBA_DomainManagerList *);
  CORBA_DomainManagerList_var (const CORBA_DomainManagerList_var &); // copy constructor
  ~CORBA_DomainManagerList_var (void); // destructor

  CORBA_DomainManagerList_var &operator= (CORBA_DomainManagerList *);
  CORBA_DomainManagerList_var &operator= (const CORBA_DomainManagerList_var &);
  CORBA_DomainManagerList *operator-> (void);
  const CORBA_DomainManagerList *operator-> (void) const;

  operator const CORBA_DomainManagerList &() const;
  operator CORBA_DomainManagerList &();
  operator CORBA_DomainManagerList &() const;

  TAO_Object_Manager<CORBA_DomainManager,CORBA_DomainManager_var> operator[] (CORBA::ULong slot);
  // in, inout, out, _retn
  const CORBA_DomainManagerList &in (void) const;
  CORBA_DomainManagerList &inout (void);
  CORBA_DomainManagerList *&out (void);
  CORBA_DomainManagerList *_retn (void);
  CORBA_DomainManagerList *ptr (void) const;

private:
  CORBA_DomainManagerList *ptr_;
};

class TAO_Export CORBA_DomainManagerList_out
{
public:
  CORBA_DomainManagerList_out (CORBA_DomainManagerList *&);
  CORBA_DomainManagerList_out (CORBA_DomainManagerList_var &);
  CORBA_DomainManagerList_out (const CORBA_DomainManagerList_out &);
  CORBA_DomainManagerList_out &operator= (const CORBA_DomainManagerList_out &);
  CORBA_DomainManagerList_out &operator= (CORBA_DomainManagerList *);
  operator CORBA_DomainManagerList *&();
  CORBA_DomainManagerList *&ptr (void);
  CORBA_DomainManagerList *operator-> (void);

  TAO_Object_Manager<CORBA_DomainManager,CORBA_DomainManager_var> operator[] (CORBA::ULong slot);

private:
  CORBA_DomainManagerList *&ptr_;
  // assignment from T_var not allowed
  void operator= (const CORBA_DomainManagerList_var &);
};

// *************************************************************
// ConstructionPolicy
// *************************************************************

#if ! defined (TAO_HAS_MINIMUM_CORBA)

class TAO_Export CORBA_ConstructionPolicy_var
{
public:
  CORBA_ConstructionPolicy_var (void); // default constructor
  CORBA_ConstructionPolicy_var (CORBA_ConstructionPolicy_ptr);
  CORBA_ConstructionPolicy_var (const CORBA_ConstructionPolicy_var &); // copy constructor
  ~CORBA_ConstructionPolicy_var (void); // destructor

  CORBA_ConstructionPolicy_var &operator= (CORBA_ConstructionPolicy_ptr);
  CORBA_ConstructionPolicy_var &operator= (const CORBA_ConstructionPolicy_var &);
  CORBA_ConstructionPolicy_ptr operator-> (void) const;

  operator const CORBA_ConstructionPolicy_ptr &() const;
  operator CORBA_ConstructionPolicy_ptr &();
  // in, inout, out, _retn
  CORBA_ConstructionPolicy_ptr in (void) const;
  CORBA_ConstructionPolicy_ptr &inout (void);
  CORBA_ConstructionPolicy_ptr &out (void);
  CORBA_ConstructionPolicy_ptr _retn (void);
  CORBA_ConstructionPolicy_ptr ptr (void) const;

private:
  CORBA_ConstructionPolicy_ptr ptr_;
};

class TAO_Export CORBA_ConstructionPolicy_out
{
public:
  CORBA_ConstructionPolicy_out (CORBA_ConstructionPolicy_ptr &);
  CORBA_ConstructionPolicy_out (CORBA_ConstructionPolicy_var &);
  CORBA_ConstructionPolicy_out (const CORBA_ConstructionPolicy_out &);
  CORBA_ConstructionPolicy_out &operator= (const CORBA_ConstructionPolicy_out &);
  CORBA_ConstructionPolicy_out &operator= (const CORBA_ConstructionPolicy_var &);
  CORBA_ConstructionPolicy_out &operator= (CORBA_ConstructionPolicy_ptr);
  operator CORBA_ConstructionPolicy_ptr &();
  CORBA_ConstructionPolicy_ptr &ptr (void);
  CORBA_ConstructionPolicy_ptr operator-> (void);

private:
  CORBA_ConstructionPolicy_ptr &ptr_;
};

class TAO_Export CORBA_ConstructionPolicy: public virtual CORBA_Policy
{
public:
#if !defined(__GNUC__) || __GNUC__ > 2 || __GNUC_MINOR__ >= 8
  typedef CORBA_ConstructionPolicy_ptr _ptr_type;
  typedef CORBA_ConstructionPolicy_var _var_type;
#endif /* __GNUC__ */

  // the static operations
  static CORBA_ConstructionPolicy_ptr _duplicate (CORBA_ConstructionPolicy_ptr obj);
  static CORBA_ConstructionPolicy_ptr _narrow (
      CORBA::Object_ptr obj,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  static CORBA_ConstructionPolicy_ptr _nil (void);
  static void _tao_any_destructor (void*);

  virtual void make_domain_manager (
      CORBA::InterfaceDef_ptr object_type,
      CORBA::Boolean constr_policy,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  virtual CORBA::Boolean _is_a (
      const CORBA::Char *type_id,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  virtual const char* _interface_repository_id (void) const;

protected:
  CORBA_ConstructionPolicy (void);
  CORBA_ConstructionPolicy (TAO_Stub *objref,
      TAO_ServantBase *_tao_servant = 0,
      CORBA::Boolean _tao_collocated = 0
    );
  virtual ~CORBA_ConstructionPolicy (void);
private:
  CORBA_ConstructionPolicy (const CORBA_ConstructionPolicy &);
  void operator= (const CORBA_ConstructionPolicy &);
};

// Any operators for interface CORBA_ConstructionPolicy
TAO_Export void operator<<= (CORBA::Any &,
                             CORBA_ConstructionPolicy_ptr);
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &,
                                       CORBA_ConstructionPolicy *&);

#ifndef __ACE_INLINE__

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &,
                                      const CORBA_ConstructionPolicy_ptr );
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &,
                                      CORBA_ConstructionPolicy_ptr &);

#endif /* __ACE_INLINE__ */

#endif /* ! defined (TAO_HAS_MINIMUM_CORBA) */




// Any operators for interface CORBA_DomainManager
TAO_Export void operator<<= (CORBA::Any &,
                             CORBA_DomainManager_ptr);
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &,
                                       CORBA_DomainManager *&);

// Any operators for interface CORBA_DomainManagerList
TAO_Export void operator<<= (CORBA::Any &,
                             const CORBA_DomainManagerList &); // copying version
TAO_Export void operator<<= (CORBA::Any &,
                             CORBA_DomainManagerList*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &,
                                       CORBA::DomainManagerList *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &,
                                       const CORBA::DomainManagerList *&);

#ifndef __ACE_INLINE__

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &,
                                      const CORBA_DomainManager_ptr );
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &,
                                      CORBA_DomainManager_ptr &);
TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &,
                                      const CORBA_DomainManagerList &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &,
                                      CORBA_DomainManagerList &);
#endif /* __ACE_INLINE__ */

#if defined (__ACE_INLINE__)
#include "tao/DomainC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#include "ace/post.h"
#endif /* TAO_IDL_DOMAINC_H */

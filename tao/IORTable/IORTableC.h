/* -*- C++ -*- $Id$ */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#ifndef _TAO_IDL_ORIG_IORTABLEC_H_
#define _TAO_IDL_ORIG_IORTABLEC_H_

#include "ace/pre.h"
#include "tao/corba.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "iortable_export.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_IORTable_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_IORTable_Export
#endif /* TAO_EXPORT_NESTED_CLASSES */

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

TAO_NAMESPACE  IORTable
{
  class Locator;

#if !defined (_IORTABLE_LOCATOR___PTR_CH_)
#define _IORTABLE_LOCATOR___PTR_CH_

typedef Locator *Locator_ptr;

#endif /* end #if !defined */


#if !defined (_IORTABLE_LOCATOR___VAR_CH_)
#define _IORTABLE_LOCATOR___VAR_CH_

  class TAO_IORTable_Export Locator_var : public TAO_Base_var
  {
  public:
    Locator_var (void); // default constructor
    Locator_var (Locator_ptr p) : ptr_ (p) {}
    Locator_var (const Locator_var &); // copy constructor
    ~Locator_var (void); // destructor

    Locator_var &operator= (Locator_ptr);
    Locator_var &operator= (const Locator_var &);
    Locator_ptr operator-> (void) const;

    operator const Locator_ptr &() const;
    operator Locator_ptr &();
    // in, inout, out, _retn
    Locator_ptr in (void) const;
    Locator_ptr &inout (void);
    Locator_ptr &out (void);
    Locator_ptr _retn (void);
    Locator_ptr ptr (void) const;

  private:
    Locator_ptr ptr_;
    // Unimplemented - prevents widening assignment.
    Locator_var (const TAO_Base_var &rhs);
    Locator_var &operator= (const TAO_Base_var &rhs);
  };


#endif /* end #if !defined */


#if !defined (_IORTABLE_LOCATOR___OUT_CH_)
#define _IORTABLE_LOCATOR___OUT_CH_

  class TAO_IORTable_Export Locator_out
  {
  public:
    Locator_out (Locator_ptr &);
    Locator_out (Locator_var &);
    Locator_out (const Locator_out &);
    Locator_out &operator= (const Locator_out &);
    Locator_out &operator= (const Locator_var &);
    Locator_out &operator= (Locator_ptr);
    operator Locator_ptr &();
    Locator_ptr &ptr (void);
    Locator_ptr operator-> (void);

  private:
    Locator_ptr &ptr_;
  };


#endif /* end #if !defined */


#if !defined (_IORTABLE_ALREADYBOUND_CH_)
#define _IORTABLE_ALREADYBOUND_CH_

  class TAO_IORTable_Export AlreadyBound : public CORBA::UserException
  {
  public:

    AlreadyBound (void); // default ctor
    AlreadyBound (const AlreadyBound &); // copy ctor
    ~AlreadyBound (void);
    static void _tao_any_destructor (void*);
    AlreadyBound &operator= (const AlreadyBound &);


    virtual void _raise (void);

    virtual void _tao_encode (
        TAO_OutputCDR &,
        CORBA::Environment &) const;
    virtual void _tao_decode (
        TAO_InputCDR &,
        CORBA::Environment &);

    static AlreadyBound *_downcast (CORBA::Exception *);


    // = TAO extension
    static CORBA::Exception *_alloc (void);
  }; // exception IORTable::AlreadyBound


#endif /* end #if !defined */


#if !defined (_IORTABLE_NOTFOUND_CH_)
#define _IORTABLE_NOTFOUND_CH_

  class TAO_IORTable_Export NotFound : public CORBA::UserException
  {
  public:

    NotFound (void); // default ctor
    NotFound (const NotFound &); // copy ctor
    ~NotFound (void);
    static void _tao_any_destructor (void*);
    NotFound &operator= (const NotFound &);


    virtual void _raise (void);

    virtual void _tao_encode (
        TAO_OutputCDR &,
        CORBA::Environment &) const;
    virtual void _tao_decode (
        TAO_InputCDR &,
        CORBA::Environment &);

    static NotFound *_downcast (CORBA::Exception *);


    // = TAO extension
    static CORBA::Exception *_alloc (void);
  }; // exception IORTable::NotFound


#endif /* end #if !defined */


#if !defined (_IORTABLE_TABLE___PTR_CH_)
#define _IORTABLE_TABLE___PTR_CH_

  class Table;
  typedef Table *Table_ptr;

#endif /* end #if !defined */


#if !defined (_IORTABLE_TABLE___VAR_CH_)
#define _IORTABLE_TABLE___VAR_CH_

  class TAO_IORTable_Export Table_var : public TAO_Base_var
  {
  public:
    Table_var (void); // default constructor
    Table_var (Table_ptr p) : ptr_ (p) {}
    Table_var (const Table_var &); // copy constructor
    ~Table_var (void); // destructor

    Table_var &operator= (Table_ptr);
    Table_var &operator= (const Table_var &);
    Table_ptr operator-> (void) const;

    operator const Table_ptr &() const;
    operator Table_ptr &();
    // in, inout, out, _retn
    Table_ptr in (void) const;
    Table_ptr &inout (void);
    Table_ptr &out (void);
    Table_ptr _retn (void);
    Table_ptr ptr (void) const;

  private:
    Table_ptr ptr_;
    // Unimplemented - prevents widening assignment.
    Table_var (const TAO_Base_var &rhs);
    Table_var &operator= (const TAO_Base_var &rhs);
  };


#endif /* end #if !defined */


#if !defined (_IORTABLE_TABLE___OUT_CH_)
#define _IORTABLE_TABLE___OUT_CH_

  class TAO_IORTable_Export Table_out
  {
  public:
    Table_out (Table_ptr &);
    Table_out (Table_var &);
    Table_out (const Table_out &);
    Table_out &operator= (const Table_out &);
    Table_out &operator= (const Table_var &);
    Table_out &operator= (Table_ptr);
    operator Table_ptr &();
    Table_ptr &ptr (void);
    Table_ptr operator-> (void);

  private:
    Table_ptr &ptr_;
  };


#endif /* end #if !defined */


#if !defined (_IORTABLE_TABLE_CH_)
#define _IORTABLE_TABLE_CH_

class TAO_IORTable_Export Table : public virtual CORBA_Object
  {
  public:
  #if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
    typedef Table_ptr _ptr_type;
    typedef Table_var _var_type;
  #endif /* ! __GNUC__ || g++ >= 2.8 */

    // the static operations
    static Table_ptr _duplicate (Table_ptr obj);
    static Table_ptr _narrow (
        CORBA::Object_ptr obj,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );
    static Table_ptr _unchecked_narrow (
        CORBA::Object_ptr obj,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );
    static Table_ptr _nil (void)
      {
        return (Table_ptr)0;
      }

    virtual void bind (
        const char * object_key,
        const char * IOR,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        IORTable::AlreadyBound
      )) = 0;

    virtual void rebind (
        const char * object_key,
        const char * IOR,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    virtual void unbind (
        const char * object_key,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        IORTable::NotFound
      )) = 0;

    virtual void set_locator (
        IORTable::Locator_ptr the_locator,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    virtual void *_tao_QueryInterface (ptr_arith_t type);

    virtual const char* _interface_repository_id (void) const;

  protected:
    Table (void);
    virtual ~Table (void);
  private:
    Table (const Table &);
    void operator= (const Table &);
  };


#endif /* end #if !defined */


#if !defined (_IORTABLE_LOCATOR___PTR_CH_)
#define _IORTABLE_LOCATOR___PTR_CH_

  class Locator;
  typedef Locator *Locator_ptr;

#endif /* end #if !defined */


#if !defined (_IORTABLE_LOCATOR___VAR_CH_)
#define _IORTABLE_LOCATOR___VAR_CH_

  class TAO_IORTable_Export Locator_var : public TAO_Base_var
  {
  public:
    Locator_var (void); // default constructor
    Locator_var (Locator_ptr p) : ptr_ (p) {}
    Locator_var (const Locator_var &); // copy constructor
    ~Locator_var (void); // destructor

    Locator_var &operator= (Locator_ptr);
    Locator_var &operator= (const Locator_var &);
    Locator_ptr operator-> (void) const;

    operator const Locator_ptr &() const;
    operator Locator_ptr &();
    // in, inout, out, _retn
    Locator_ptr in (void) const;
    Locator_ptr &inout (void);
    Locator_ptr &out (void);
    Locator_ptr _retn (void);
    Locator_ptr ptr (void) const;

  private:
    Locator_ptr ptr_;
    // Unimplemented - prevents widening assignment.
    Locator_var (const TAO_Base_var &rhs);
    Locator_var &operator= (const TAO_Base_var &rhs);
  };


#endif /* end #if !defined */


#if !defined (_IORTABLE_LOCATOR___OUT_CH_)
#define _IORTABLE_LOCATOR___OUT_CH_

  class TAO_IORTable_Export Locator_out
  {
  public:
    Locator_out (Locator_ptr &);
    Locator_out (Locator_var &);
    Locator_out (const Locator_out &);
    Locator_out &operator= (const Locator_out &);
    Locator_out &operator= (const Locator_var &);
    Locator_out &operator= (Locator_ptr);
    operator Locator_ptr &();
    Locator_ptr &ptr (void);
    Locator_ptr operator-> (void);

  private:
    Locator_ptr &ptr_;
  };


#endif /* end #if !defined */


#if !defined (_IORTABLE_LOCATOR_CH_)
#define _IORTABLE_LOCATOR_CH_

class TAO_IORTable_Export Locator : public virtual CORBA_Object
  {
  public:
  #if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
    typedef Locator_ptr _ptr_type;
    typedef Locator_var _var_type;
  #endif /* ! __GNUC__ || g++ >= 2.8 */

    // the static operations
    static Locator_ptr _duplicate (Locator_ptr obj);
    static Locator_ptr _narrow (
        CORBA::Object_ptr obj,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );
    static Locator_ptr _unchecked_narrow (
        CORBA::Object_ptr obj,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );
    static Locator_ptr _nil (void)
      {
        return (Locator_ptr)0;
      }

    virtual char * locate (
        const char * object_key,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        IORTable::NotFound
      )) = 0;

    virtual void *_tao_QueryInterface (ptr_arith_t type);

    virtual const char* _interface_repository_id (void) const;

  protected:
    Locator (void);
    virtual ~Locator (void);
  private:
    Locator (const Locator &);
    void operator= (const Locator &);
  };


#endif /* end #if !defined */


}
TAO_NAMESPACE_CLOSE // module IORTable

#if defined (__ACE_INLINE__)
#include "IORTableC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#include "ace/post.h"
#endif /* ifndef */

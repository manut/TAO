/* -*- C++ -*- */
// $Id$

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#ifndef _TAO_IDL_IORC_H_
#define _TAO_IDL_IORC_H_
#include "ace/pre.h"

#include "ace/OS.h"
#include "tao/corbafwd.h"
#include "tao/Environment.h"
#include "tao/CDR.h"
#include "tao/Object.h"
#include "tao/Sequence.h"
#include "tao/Exception.h"
#include "tao/Typecode.h"

#if defined (ACE_HAS_MINIMUM_IOSTREAMH_INCLUSION)
#include "ace/streams.h"
#endif /* ACE_HAS_MINIMUM_IOSTREAMH_INCLUSION */

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO 

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO 
#endif /* TAO_EXPORT_NESTED_CLASSES */

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

TAO_NAMESPACE  TAO_IOP
{

#if !defined (_TAO_IOP_TAO_IOR_MANIPULATION___PTR_CH_)
#define _TAO_IOP_TAO_IOR_MANIPULATION___PTR_CH_

  class TAO_IOR_Manipulation;
  typedef TAO_IOR_Manipulation *TAO_IOR_Manipulation_ptr;
  
#endif /* end #if !defined */


#if !defined (_TAO_IOP_TAO_IOR_MANIPULATION___VAR_CH_)
#define _TAO_IOP_TAO_IOR_MANIPULATION___VAR_CH_

  class  TAO_IOR_Manipulation_var : public TAO_Base_var
  {
  public:
    TAO_IOR_Manipulation_var (void); // default constructor
    TAO_IOR_Manipulation_var (TAO_IOR_Manipulation_ptr);
    TAO_IOR_Manipulation_var (const TAO_IOR_Manipulation_var &); // copy constructor
    ~TAO_IOR_Manipulation_var (void); // destructor
    
    TAO_IOR_Manipulation_var &operator= (TAO_IOR_Manipulation_ptr);
    TAO_IOR_Manipulation_var &operator= (const TAO_IOR_Manipulation_var &);
    TAO_IOR_Manipulation_ptr operator-> (void) const;
    
    operator const TAO_IOR_Manipulation_ptr &() const;
    operator TAO_IOR_Manipulation_ptr &();
    // in, inout, out, _retn 
    TAO_IOR_Manipulation_ptr in (void) const;
    TAO_IOR_Manipulation_ptr &inout (void);
    TAO_IOR_Manipulation_ptr &out (void);
    TAO_IOR_Manipulation_ptr _retn (void);
    TAO_IOR_Manipulation_ptr ptr (void) const;

  private:
    TAO_IOR_Manipulation_ptr ptr_;
    // Unimplemented - prevents widening assignment.
    TAO_IOR_Manipulation_var (const TAO_Base_var &rhs);
    TAO_IOR_Manipulation_var &operator= (const TAO_Base_var &rhs);
  };


#endif /* end #if !defined */


#if !defined (_TAO_IOP_TAO_IOR_MANIPULATION___OUT_CH_)
#define _TAO_IOP_TAO_IOR_MANIPULATION___OUT_CH_

  class  TAO_IOR_Manipulation_out
  {
  public:
    TAO_IOR_Manipulation_out (TAO_IOR_Manipulation_ptr &);
    TAO_IOR_Manipulation_out (TAO_IOR_Manipulation_var &);
    TAO_IOR_Manipulation_out (const TAO_IOR_Manipulation_out &);
    TAO_IOR_Manipulation_out &operator= (const TAO_IOR_Manipulation_out &);
    TAO_IOR_Manipulation_out &operator= (const TAO_IOR_Manipulation_var &);
    TAO_IOR_Manipulation_out &operator= (TAO_IOR_Manipulation_ptr);
    operator TAO_IOR_Manipulation_ptr &();
    TAO_IOR_Manipulation_ptr &ptr (void);
    TAO_IOR_Manipulation_ptr operator-> (void);
    
  private:
    TAO_IOR_Manipulation_ptr &ptr_;
  };


#endif /* end #if !defined */


#if !defined (_TAO_IOP_TAO_IOR_MANIPULATION_CH_)
#define _TAO_IOP_TAO_IOR_MANIPULATION_CH_

class  TAO_IOR_Manipulation : public virtual CORBA_Object
  {
  public:
  #if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
    typedef TAO_IOR_Manipulation_ptr _ptr_type;
    typedef TAO_IOR_Manipulation_var _var_type;
  #endif /* ! __GNUC__ || g++ >= 2.8 */

    // the static operations
    static TAO_IOR_Manipulation_ptr _duplicate (TAO_IOR_Manipulation_ptr obj);
    static TAO_IOR_Manipulation_ptr _narrow (
        CORBA::Object_ptr obj,
        CORBA::Environment &ACE_TRY_ENV = 
          TAO_default_environment ()
      );
    static TAO_IOR_Manipulation_ptr _unchecked_narrow (
        CORBA::Object_ptr obj,
        CORBA::Environment &ACE_TRY_ENV = 
          TAO_default_environment ()
      );
    static TAO_IOR_Manipulation_ptr _nil (void)
      {
        return (TAO_IOR_Manipulation_ptr)0;
      }

    static void _tao_any_destructor (void*);


#if !defined (_TAO_IOP_TAO_IOR_MANIPULATION_EMPTYPROFILELIST_CH_)
#define _TAO_IOP_TAO_IOR_MANIPULATION_EMPTYPROFILELIST_CH_

    class  EmptyProfileList : public CORBA::UserException
    {
    public:


    EmptyProfileList (void); // default ctor
    EmptyProfileList (const EmptyProfileList &); // copy ctor
    ~EmptyProfileList (void);
    static void _tao_any_destructor (void*);
    EmptyProfileList &operator= (const EmptyProfileList &);


    virtual void _raise (void);

    virtual void _tao_encode (
        TAO_OutputCDR &,
        CORBA::Environment &) const;
    virtual void _tao_decode (
        TAO_InputCDR &,
        CORBA::Environment &);

    static EmptyProfileList *_downcast (CORBA::Exception *);


    // = TAO extension
    static CORBA::Exception *_alloc (void);

  }; // exception TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList

    static CORBA::TypeCode_ptr _tc_EmptyProfileList;


#endif /* end #if !defined */


#if !defined (_TAO_IOP_TAO_IOR_MANIPULATION_NOTFOUND_CH_)
#define _TAO_IOP_TAO_IOR_MANIPULATION_NOTFOUND_CH_

  class  NotFound : public CORBA::UserException
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

}; // exception TAO_IOP::TAO_IOR_Manipulation::NotFound

static CORBA::TypeCode_ptr _tc_NotFound;


#endif /* end #if !defined */


#if !defined (_TAO_IOP_TAO_IOR_MANIPULATION_DUPLICATE_CH_)
#define _TAO_IOP_TAO_IOR_MANIPULATION_DUPLICATE_CH_

class  Duplicate : public CORBA::UserException
{
public:


Duplicate (void); // default ctor
Duplicate (const Duplicate &); // copy ctor
~Duplicate (void);
static void _tao_any_destructor (void*);
Duplicate &operator= (const Duplicate &);


virtual void _raise (void);

virtual void _tao_encode (
    TAO_OutputCDR &,
    CORBA::Environment &) const;
virtual void _tao_decode (
    TAO_InputCDR &,
    CORBA::Environment &);

static Duplicate *_downcast (CORBA::Exception *);


// = TAO extension
static CORBA::Exception *_alloc (void);

}; // exception TAO_IOP::TAO_IOR_Manipulation::Duplicate

static CORBA::TypeCode_ptr _tc_Duplicate;


#endif /* end #if !defined */


#if !defined (_TAO_IOP_TAO_IOR_MANIPULATION_INVALID_IOR_CH_)
#define _TAO_IOP_TAO_IOR_MANIPULATION_INVALID_IOR_CH_

class  Invalid_IOR : public CORBA::UserException
{
public:


Invalid_IOR (void); // default ctor
Invalid_IOR (const Invalid_IOR &); // copy ctor
~Invalid_IOR (void);
static void _tao_any_destructor (void*);
Invalid_IOR &operator= (const Invalid_IOR &);


virtual void _raise (void);

virtual void _tao_encode (
    TAO_OutputCDR &,
    CORBA::Environment &) const;
virtual void _tao_decode (
    TAO_InputCDR &,
    CORBA::Environment &);

static Invalid_IOR *_downcast (CORBA::Exception *);


// = TAO extension
static CORBA::Exception *_alloc (void);

}; // exception TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR

static CORBA::TypeCode_ptr _tc_Invalid_IOR;


#endif /* end #if !defined */


#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  
#if !defined (__TAO_UNBOUNDED_OBJECT_SEQUENCE_TAO_IOP_TAO_IOR_MANIPULATION_IORLIST_CH_)
#define __TAO_UNBOUNDED_OBJECT_SEQUENCE_TAO_IOP_TAO_IOR_MANIPULATION_IORLIST_CH_

  class _TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList : public TAO_Unbounded_Base_Sequence
  {
  public:
    // = Initialization and termination methods.
    
    _TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList (void);
    _TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList (CORBA::ULong maximum);
    _TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList (CORBA::ULong maximum,
      CORBA::ULong length,
      CORBA::Object* *value,
      CORBA::Boolean release = 0);
    _TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList(const _TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList &rhs);
    virtual ~_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList (void);
    _TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList &operator= (const _TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList &rhs);
    TAO_Object_Manager<CORBA::Object,CORBA::Object_var> operator[] (CORBA::ULong index) const;
    static CORBA::Object **allocbuf (CORBA::ULong nelems);
    static void freebuf (CORBA::Object **buffer);
    // The Base_Sequence functions, please see tao/Sequence.h
    virtual void _allocate_buffer (CORBA::ULong length);
    virtual void _deallocate_buffer (void);
    CORBA::Object* *get_buffer (CORBA::Boolean orphan = 0);
    const CORBA::Object* *get_buffer (void) const;
    virtual void _shrink_buffer (CORBA::ULong nl, CORBA::ULong ol);
    virtual void _downcast (
        void* target,
        CORBA_Object *src,
        CORBA_Environment &ACE_TRY_ENV = 
          TAO_default_environment ()
      );
    virtual CORBA_Object* _upcast (void *src) const;
    
  };

#endif /* end #if !defined */


#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 

#if !defined (_TAO_IOP_TAO_IOR_MANIPULATION_IORLIST_CH_)
#define _TAO_IOP_TAO_IOR_MANIPULATION_IORLIST_CH_

class IORList;
class IORList_var;

// *************************************************************
// IORList
// *************************************************************

class  IORList : public 
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Object_Sequence<CORBA::Object,CORBA::Object_var>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
{
public:
  IORList (void); // default ctor
  IORList (CORBA::ULong max); // uses max size
  IORList (
    CORBA::ULong max, 
    CORBA::ULong length, 
    CORBA::Object_ptr *buffer, 
    CORBA::Boolean release=0
  );
  IORList (const IORList &); // copy ctor
  ~IORList (void);
  static void _tao_any_destructor (void*);

#if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
  typedef IORList_var _var_type;
#endif /* ! __GNUC__ || g++ >= 2.8 */

};

#endif /* end #if !defined */


#if !defined (_TAO_IOP_TAO_IOR_MANIPULATION_IORLIST___VAR_CH_)
#define _TAO_IOP_TAO_IOR_MANIPULATION_IORLIST___VAR_CH_

// *************************************************************
// class TAO_IOP::TAO_IOR_Manipulation::IORList_var
// *************************************************************

class  IORList_var
{
public:
  IORList_var (void); // default constructor
  IORList_var (IORList *);
  IORList_var (const IORList_var &); // copy constructor
  ~IORList_var (void); // destructor
  
  IORList_var &operator= (IORList *);
  IORList_var &operator= (const IORList_var &);
  IORList *operator-> (void);
  const IORList *operator-> (void) const;
  
  operator const IORList &() const;
  operator IORList &();
  operator IORList &() const;
  operator IORList *&(); // variable-size base types only
  
  TAO_Object_Manager<CORBA::Object,CORBA::Object_var> operator[] (CORBA::ULong index);
  // in, inout, out, _retn 
  const IORList &in (void) const;
  IORList &inout (void);
  IORList *&out (void);
  IORList *_retn (void);
  IORList *ptr (void) const;

private:
  IORList *ptr_;
};


#endif /* end #if !defined */


#if !defined (_TAO_IOP_TAO_IOR_MANIPULATION_IORLIST___OUT_CH_)
#define _TAO_IOP_TAO_IOR_MANIPULATION_IORLIST___OUT_CH_

class  IORList_out
{
public:
  IORList_out (IORList *&);
  IORList_out (IORList_var &);
  IORList_out (const IORList_out &);
  IORList_out &operator= (const IORList_out &);
  IORList_out &operator= (IORList *);
  operator IORList *&();
  IORList *&ptr (void);
  IORList *operator-> (void);
  TAO_Object_Manager<CORBA::Object,CORBA::Object_var> operator[] (CORBA::ULong index);
  
private:
  IORList *&ptr_;
  // assignment from T_var not allowed
  void operator= (const IORList_var &);
};


#endif /* end #if !defined */

static CORBA::TypeCode_ptr _tc_IORList;

virtual CORBA::Object_ptr merge_iors (
    const TAO_IOP::TAO_IOR_Manipulation::IORList & iors,
    CORBA::Environment &ACE_TRY_ENV = 
      TAO_default_environment ()
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException,
    TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList,
    TAO_IOP::TAO_IOR_Manipulation::Duplicate,
    TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR
  ));

virtual CORBA::Object_ptr add_profiles (
    CORBA::Object_ptr ior1,
    CORBA::Object_ptr ior2,
    CORBA::Environment &ACE_TRY_ENV = 
      TAO_default_environment ()
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException,
    TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList,
    TAO_IOP::TAO_IOR_Manipulation::Duplicate,
    TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR
  ));

virtual CORBA::Object_ptr remove_profiles (
    CORBA::Object_ptr ior1,
    CORBA::Object_ptr ior2,
    CORBA::Environment &ACE_TRY_ENV = 
      TAO_default_environment ()
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException,
    TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR,
    TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList,
    TAO_IOP::TAO_IOR_Manipulation::NotFound
  ));

virtual CORBA::ULong is_in_ior (
    CORBA::Object_ptr ior1,
    CORBA::Object_ptr ior2,
    CORBA::Environment &ACE_TRY_ENV = 
      TAO_default_environment ()
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException,
    TAO_IOP::TAO_IOR_Manipulation::NotFound
  ));

virtual CORBA::ULong get_profile_count (
    CORBA::Object_ptr ior,
    CORBA::Environment &ACE_TRY_ENV = 
      TAO_default_environment ()
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException,
    TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList
  ));

virtual CORBA::Boolean _is_a (
    const CORBA::Char *type_id, 
    CORBA::Environment &ACE_TRY_ENV = 
      TAO_default_environment ()
  );
virtual void *_tao_QueryInterface (ptr_arith_t type);

virtual const char* _interface_repository_id (void) const;

protected:
  TAO_IOR_Manipulation (void);
  TAO_IOR_Manipulation (TAO_Stub *objref, 
      TAO_ServantBase *_tao_servant = 0, 
      CORBA::Boolean _tao_collocated = 0
    );
  virtual ~TAO_IOR_Manipulation (void);
private:
  TAO_IOR_Manipulation (const TAO_IOR_Manipulation &);
  void operator= (const TAO_IOR_Manipulation &);
};


#endif /* end #if !defined */

TAO_NAMESPACE_STORAGE_CLASS CORBA::TypeCode_ptr _tc_TAO_IOR_Manipulation;


}
TAO_NAMESPACE_CLOSE // module TAO_IOP

extern  TAO_IOP::TAO_IOR_Manipulation_ptr (*_TAO_collocation_TAO_IOP_TAO_IOR_Manipulation_Stub_Factory_function_pointer) (
    CORBA::Object_ptr obj
  );
// Any operators for interface TAO_IOP::TAO_IOR_Manipulation
 void operator<<= (CORBA::Any &, TAO_IOP::TAO_IOR_Manipulation_ptr);
 CORBA::Boolean operator>>= (const CORBA::Any &, TAO_IOP::TAO_IOR_Manipulation *&);
 void operator<<= (CORBA::Any &, const TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList &); // copying version
 void operator<<= (CORBA::Any &, TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList*); // noncopying version
 CORBA::Boolean operator>>= (const CORBA::Any &, TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList *&); // deprecated
 CORBA::Boolean operator>>= (const CORBA::Any &, const TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList *&);
 void operator<<= (CORBA::Any &, const TAO_IOP::TAO_IOR_Manipulation::NotFound &); // copying version
 void operator<<= (CORBA::Any &, TAO_IOP::TAO_IOR_Manipulation::NotFound*); // noncopying version
 CORBA::Boolean operator>>= (const CORBA::Any &, TAO_IOP::TAO_IOR_Manipulation::NotFound *&); // deprecated
 CORBA::Boolean operator>>= (const CORBA::Any &, const TAO_IOP::TAO_IOR_Manipulation::NotFound *&);
 void operator<<= (CORBA::Any &, const TAO_IOP::TAO_IOR_Manipulation::Duplicate &); // copying version
 void operator<<= (CORBA::Any &, TAO_IOP::TAO_IOR_Manipulation::Duplicate*); // noncopying version
 CORBA::Boolean operator>>= (const CORBA::Any &, TAO_IOP::TAO_IOR_Manipulation::Duplicate *&); // deprecated
 CORBA::Boolean operator>>= (const CORBA::Any &, const TAO_IOP::TAO_IOR_Manipulation::Duplicate *&);
 void operator<<= (CORBA::Any &, const TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR &); // copying version
 void operator<<= (CORBA::Any &, TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR*); // noncopying version
 CORBA::Boolean operator>>= (const CORBA::Any &, TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR *&); // deprecated
 CORBA::Boolean operator>>= (const CORBA::Any &, const TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR *&);
 void operator<<= (CORBA::Any &, const TAO_IOP::TAO_IOR_Manipulation::IORList &); // copying version
 void operator<<= (CORBA::Any &, TAO_IOP::TAO_IOR_Manipulation::IORList*); // noncopying version
 CORBA::Boolean operator>>= (const CORBA::Any &, TAO_IOP::TAO_IOR_Manipulation::IORList *&); // deprecated
 CORBA::Boolean operator>>= (const CORBA::Any &, const TAO_IOP::TAO_IOR_Manipulation::IORList *&);

#ifndef __ACE_INLINE__

 CORBA::Boolean operator<< (TAO_OutputCDR &, const TAO_IOP::TAO_IOR_Manipulation_ptr );
 CORBA::Boolean operator>> (TAO_InputCDR &, TAO_IOP::TAO_IOR_Manipulation_ptr &);
 CORBA::Boolean operator<< (TAO_OutputCDR &, const TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList &);
 CORBA::Boolean operator>> (TAO_InputCDR &, TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList &);

# if !defined (ACE_LACKS_IOSTREAM_TOTALLY)

 ostream& operator<< (ostream &, const TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList &);

# endif /* ACE_LACKS_IOSTREAM_TOTALLY */
 CORBA::Boolean operator<< (TAO_OutputCDR &, const TAO_IOP::TAO_IOR_Manipulation::NotFound &);
 CORBA::Boolean operator>> (TAO_InputCDR &, TAO_IOP::TAO_IOR_Manipulation::NotFound &);

# if !defined (ACE_LACKS_IOSTREAM_TOTALLY)

 ostream& operator<< (ostream &, const TAO_IOP::TAO_IOR_Manipulation::NotFound &);

# endif /* ACE_LACKS_IOSTREAM_TOTALLY */
 CORBA::Boolean operator<< (TAO_OutputCDR &, const TAO_IOP::TAO_IOR_Manipulation::Duplicate &);
 CORBA::Boolean operator>> (TAO_InputCDR &, TAO_IOP::TAO_IOR_Manipulation::Duplicate &);

# if !defined (ACE_LACKS_IOSTREAM_TOTALLY)

 ostream& operator<< (ostream &, const TAO_IOP::TAO_IOR_Manipulation::Duplicate &);

# endif /* ACE_LACKS_IOSTREAM_TOTALLY */
 CORBA::Boolean operator<< (TAO_OutputCDR &, const TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR &);
 CORBA::Boolean operator>> (TAO_InputCDR &, TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR &);

# if !defined (ACE_LACKS_IOSTREAM_TOTALLY)

 ostream& operator<< (ostream &, const TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR &);

# endif /* ACE_LACKS_IOSTREAM_TOTALLY */

#if !defined _TAO_CDR_OP_TAO_IOP_TAO_IOR_Manipulation_IORList_H_
#define _TAO_CDR_OP_TAO_IOP_TAO_IOR_Manipulation_IORList_H_

 CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const TAO_IOP::TAO_IOR_Manipulation::IORList &
  );
 CORBA::Boolean operator>> (
    TAO_InputCDR &,
    TAO_IOP::TAO_IOR_Manipulation::IORList &
  );

#endif /* _TAO_CDR_OP_TAO_IOP_TAO_IOR_Manipulation_IORList_H_ */


#endif /* __ACE_INLINE__ */


#if defined (__ACE_INLINE__)
#include "tao/IORC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#include "ace/post.h"
#endif /* ifndef */

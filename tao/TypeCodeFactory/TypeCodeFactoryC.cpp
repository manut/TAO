// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be/be_codegen.cpp:314

#include "TypeCodeFactory_Loader.h"
#include "tao/Sequence_T.h"
#include "tao/Typecode.h"
#include "tao/Any.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "TypeCodeFactoryC.inl"
#endif /* !defined INLINE */


// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:61

int CORBA::TypeCodeFactory::_tao_class_id = 0;

CORBA::TypeCodeFactory_ptr
tao_CORBA_TypeCodeFactory_duplicate (
    CORBA::TypeCodeFactory_ptr p
  )
{
  return CORBA::TypeCodeFactory::_duplicate (p);
}

void
tao_CORBA_TypeCodeFactory_release (
    CORBA::TypeCodeFactory_ptr p
  )
{
  CORBA::release (p);
}

CORBA::TypeCodeFactory_ptr
tao_CORBA_TypeCodeFactory_nil (
    void
  )
{
  return CORBA::TypeCodeFactory::_nil ();
}

CORBA::TypeCodeFactory_ptr
tao_CORBA_TypeCodeFactory_narrow (
    CORBA::Object *p
    ACE_ENV_ARG_DECL
  )
{
  return CORBA::TypeCodeFactory::_narrow (p ACE_ENV_ARG_PARAMETER);
}

CORBA::Object *
tao_CORBA_TypeCodeFactory_upcast (
    void *src
  )
{
  CORBA::TypeCodeFactory **tmp =
    ACE_static_cast (CORBA::TypeCodeFactory **, src);
  return *tmp;
}

// TAO_IDL - Generated from
// be/be_interface.cpp:721

// *************************************************************
// CORBA::TypeCodeFactory_var
// *************************************************************

CORBA::TypeCodeFactory_var::TypeCodeFactory_var (void)
  : ptr_ (TypeCodeFactory::_nil ())
{}

::CORBA::TypeCodeFactory_ptr
CORBA::TypeCodeFactory_var::ptr (void) const
{
  return this->ptr_;
}

CORBA::TypeCodeFactory_var::TypeCodeFactory_var (const ::CORBA::TypeCodeFactory_var &p)
  : TAO_Base_var (),
    ptr_ (TypeCodeFactory::_duplicate (p.ptr ()))
{}

CORBA::TypeCodeFactory_var::~TypeCodeFactory_var (void)
{
  CORBA::release (this->ptr_);
}

CORBA::TypeCodeFactory_var &
CORBA::TypeCodeFactory_var::operator= (TypeCodeFactory_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

CORBA::TypeCodeFactory_var &
CORBA::TypeCodeFactory_var::operator= (const ::CORBA::TypeCodeFactory_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = ::CORBA::TypeCodeFactory::_duplicate (p.ptr ());
  }
  return *this;
}

CORBA::TypeCodeFactory_var::operator const ::CORBA::TypeCodeFactory_ptr &() const // cast
{
  return this->ptr_;
}

CORBA::TypeCodeFactory_var::operator ::CORBA::TypeCodeFactory_ptr &() // cast
{
  return this->ptr_;
}

::CORBA::TypeCodeFactory_ptr
CORBA::TypeCodeFactory_var::operator-> (void) const
{
  return this->ptr_;
}

::CORBA::TypeCodeFactory_ptr
CORBA::TypeCodeFactory_var::in (void) const
{
  return this->ptr_;
}

::CORBA::TypeCodeFactory_ptr &
CORBA::TypeCodeFactory_var::inout (void)
{
  return this->ptr_;
}

::CORBA::TypeCodeFactory_ptr &
CORBA::TypeCodeFactory_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = ::CORBA::TypeCodeFactory::_nil ();
  return this->ptr_;
}

::CORBA::TypeCodeFactory_ptr
CORBA::TypeCodeFactory_var::_retn (void)
{
  // yield ownership of managed obj reference
  ::CORBA::TypeCodeFactory_ptr val = this->ptr_;
  this->ptr_ = ::CORBA::TypeCodeFactory::_nil ();
  return val;
}

::CORBA::TypeCodeFactory_ptr
CORBA::TypeCodeFactory_var::tao_duplicate (TypeCodeFactory_ptr p)
{
  return ::CORBA::TypeCodeFactory::_duplicate (p);
}

void
CORBA::TypeCodeFactory_var::tao_release (TypeCodeFactory_ptr p)
{
  CORBA::release (p);
}

::CORBA::TypeCodeFactory_ptr
CORBA::TypeCodeFactory_var::tao_nil (void)
{
  return ::CORBA::TypeCodeFactory::_nil ();
}

::CORBA::TypeCodeFactory_ptr
CORBA::TypeCodeFactory_var::tao_narrow (
    CORBA::Object *p
    ACE_ENV_ARG_DECL
  )
{
  return ::CORBA::TypeCodeFactory::_narrow (p ACE_ENV_ARG_PARAMETER);
}

CORBA::Object *
CORBA::TypeCodeFactory_var::tao_upcast (void *src)
{
  TypeCodeFactory **tmp =
    ACE_static_cast (TypeCodeFactory **, src);
  return *tmp;
}

// TAO_IDL - Generated from
// be/be_interface.cpp:1030

// *************************************************************
// CORBA::TypeCodeFactory_out
// *************************************************************

CORBA::TypeCodeFactory_out::TypeCodeFactory_out (TypeCodeFactory_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = ::CORBA::TypeCodeFactory::_nil ();
}

CORBA::TypeCodeFactory_out::TypeCodeFactory_out (TypeCodeFactory_var &p)
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = ::CORBA::TypeCodeFactory::_nil ();
}

CORBA::TypeCodeFactory_out::TypeCodeFactory_out (const ::CORBA::TypeCodeFactory_out &p)
  : ptr_ (ACE_const_cast (TypeCodeFactory_out &, p).ptr_)
{}

::CORBA::TypeCodeFactory_out &
CORBA::TypeCodeFactory_out::operator= (const ::CORBA::TypeCodeFactory_out &p)
{
  this->ptr_ = ACE_const_cast (TypeCodeFactory_out&, p).ptr_;
  return *this;
}

CORBA::TypeCodeFactory_out &
CORBA::TypeCodeFactory_out::operator= (const ::CORBA::TypeCodeFactory_var &p)
{
  this->ptr_ = ::CORBA::TypeCodeFactory::_duplicate (p.ptr ());
  return *this;
}

CORBA::TypeCodeFactory_out &
CORBA::TypeCodeFactory_out::operator= (TypeCodeFactory_ptr p)
{
  this->ptr_ = p;
  return *this;
}

CORBA::TypeCodeFactory_out::operator ::CORBA::TypeCodeFactory_ptr &() // cast
{
  return this->ptr_;
}

::CORBA::TypeCodeFactory_ptr &
CORBA::TypeCodeFactory_out::ptr (void)
{
  return this->ptr_;
}

::CORBA::TypeCodeFactory_ptr
CORBA::TypeCodeFactory_out::operator-> (void)
{
  return this->ptr_;
}

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:225

CORBA::TypeCodeFactory::TypeCodeFactory (void)
{}

CORBA::TypeCodeFactory::~TypeCodeFactory (void)
{}

void
CORBA::TypeCodeFactory::_tao_any_destructor (void *_tao_void_pointer)
{
  TypeCodeFactory *tmp = ACE_static_cast (TypeCodeFactory *, _tao_void_pointer);
  CORBA::release (tmp);
}

CORBA::TypeCodeFactory_ptr
CORBA::TypeCodeFactory::_narrow (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL
  )
{
  return TypeCodeFactory::_unchecked_narrow (obj ACE_ENV_ARG_PARAMETER);
}

CORBA::TypeCodeFactory_ptr
CORBA::TypeCodeFactory::_unchecked_narrow (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (obj))
    {
      return TypeCodeFactory::_nil ();
    }

  return
      ACE_reinterpret_cast (
          TypeCodeFactory_ptr,
          obj->_tao_QueryInterface (
              ACE_reinterpret_cast (
                  ptr_arith_t,
                  &TypeCodeFactory::_tao_class_id
                )
            )
        );
}

CORBA::TypeCodeFactory_ptr
CORBA::TypeCodeFactory::_duplicate (TypeCodeFactory_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }

  return obj;
}

void *CORBA::TypeCodeFactory::_tao_QueryInterface (ptr_arith_t type)
{
  void *retv = 0;

  if (type == ACE_reinterpret_cast (
              ptr_arith_t,
              &ACE_NESTED_CLASS (::CORBA, TypeCodeFactory)::_tao_class_id)
            )
    {
      retv = ACE_reinterpret_cast (void*, this);
    }
  else if (type == ACE_reinterpret_cast (
               ptr_arith_t,
               &CORBA::Object::_tao_class_id)
             )
    {
      retv =
        ACE_reinterpret_cast (
            void *,
            ACE_static_cast (CORBA::Object_ptr, this)
          );
    }

  if (retv != 0)
    {
      this->_add_ref ();
    }

  return retv;
}

const char* CORBA::TypeCodeFactory::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/TypeCodeFactory:1.0";
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_CORBA_TypeCodeFactory[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  38,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x6f6d672e),
  ACE_NTOHL (0x6f72672f),
  ACE_NTOHL (0x434f5242),
  ACE_NTOHL (0x412f5479),
  ACE_NTOHL (0x7065436f),
  ACE_NTOHL (0x64654661),
  ACE_NTOHL (0x63746f72),
  ACE_NTOHL (0x793a312e),
  ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/CORBA/TypeCodeFactory:1.0
  16,
  ACE_NTOHL (0x54797065),
  ACE_NTOHL (0x436f6465),
  ACE_NTOHL (0x46616374),
  ACE_NTOHL (0x6f727900),  // name = TypeCodeFactory
};

static CORBA::TypeCode _tc_TAO_tc_CORBA_TypeCodeFactory (
    CORBA::tk_objref,
    sizeof (_oc_CORBA_TypeCodeFactory),
    (char *) &_oc_CORBA_TypeCodeFactory,
    0,
    sizeof (CORBA::TypeCodeFactory)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_TypeCodeFactory,
    &_tc_TAO_tc_CORBA_TypeCodeFactory
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:52

// Copying version.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::TypeCodeFactory_ptr _tao_elem
  )
{
  _tao_any._tao_replace (
      CORBA::_tc_TypeCodeFactory,
      1,
      CORBA::TypeCodeFactory::_duplicate (_tao_elem),
      CORBA::TypeCodeFactory::_tao_any_destructor
    );

  _tao_any.contains_local (1);
}

// Non-copying version.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::TypeCodeFactory_ptr *_tao_elem
  )
{
  _tao_any._tao_replace (
      CORBA::_tc_TypeCodeFactory,
      1,
      *_tao_elem,
      CORBA::TypeCodeFactory::_tao_any_destructor
    );

  _tao_any.contains_local (1);
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::TypeCodeFactory_ptr &_tao_elem
  )
{
  ACE_TRY_NEW_ENV
  {
    _tao_elem = CORBA::TypeCodeFactory::_nil ();
    CORBA::TypeCode_var type = _tao_any.type ();

    CORBA::Boolean _tao_result =
      type->equivalent (
          CORBA::_tc_TypeCodeFactory
          ACE_ENV_ARG_PARAMETER
        );
    ACE_TRY_CHECK;

    if (!_tao_result)
      {
        return 0; // not equivalent
      }

    _tao_elem =
      ACE_reinterpret_cast (
          CORBA::TypeCodeFactory_ptr,
          ACE_const_cast (void *, _tao_any.value ())
        );

    return 1;
  }
  ACE_CATCHANY
  {
  }
  ACE_ENDTRY;

  _tao_elem = CORBA::TypeCodeFactory::_nil ();
  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
  template class TAO_Object_Manager<CORBA::TypeCodeFactory,CORBA::TypeCodeFactory_var>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO_Object_Manager<CORBA::TypeCodeFactory,CORBA::TypeCodeFactory_var>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

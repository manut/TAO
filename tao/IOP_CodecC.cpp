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
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be\be_codegen.cpp:323


#include "IOP_CodecC.h"
#include "tao/CDR.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "IOP_CodecC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:64

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for IOP::Codec.

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
IOP::Codec_ptr
TAO::Objref_Traits<IOP::Codec>::tao_duplicate (
    IOP::Codec_ptr p
  )
{
  return IOP::Codec::_duplicate (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Objref_Traits<IOP::Codec>::tao_release (
    IOP::Codec_ptr p
  )
{
  CORBA::release (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
IOP::Codec_ptr
TAO::Objref_Traits<IOP::Codec>::tao_nil (void)
{
  return IOP::Codec::_nil ();
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::Boolean
TAO::Objref_Traits<IOP::Codec>::tao_marshal (
    IOP::Codec_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return p->marshal (cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*IOP__TAO_Codec_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

IOP::Codec::InvalidTypeForEncoding::InvalidTypeForEncoding (void)
  : CORBA::UserException (
        "IDL:omg.org/IOP/Codec/InvalidTypeForEncoding:1.0",
        "InvalidTypeForEncoding"
      )
{
}

IOP::Codec::InvalidTypeForEncoding::~InvalidTypeForEncoding (void)
{
}

IOP::Codec::InvalidTypeForEncoding::InvalidTypeForEncoding (const ::IOP::Codec::InvalidTypeForEncoding &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

IOP::Codec::InvalidTypeForEncoding&
IOP::Codec::InvalidTypeForEncoding::operator= (const ::IOP::Codec::InvalidTypeForEncoding &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

void IOP::Codec::InvalidTypeForEncoding::_tao_any_destructor (void *_tao_void_pointer)
{
  InvalidTypeForEncoding *_tao_tmp_pointer =
    ACE_static_cast (InvalidTypeForEncoding*, _tao_void_pointer);
  delete _tao_tmp_pointer;
}

IOP::Codec::InvalidTypeForEncoding *
IOP::Codec::InvalidTypeForEncoding::_downcast (CORBA::Exception *_tao_excp)
{
  if (!ACE_OS::strcmp ("IDL:omg.org/IOP/Codec/InvalidTypeForEncoding:1.0", _tao_excp->_rep_id ()))
    {
      return ACE_dynamic_cast (InvalidTypeForEncoding *, _tao_excp);
    }
  else
    {
      return 0;
    }
}

CORBA::Exception *IOP::Codec::InvalidTypeForEncoding::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::IOP::Codec::InvalidTypeForEncoding, 0);
  return retval;
}

CORBA::Exception *
IOP::Codec::InvalidTypeForEncoding::_tao_duplicate (void) const
{
  CORBA::Exception *result;
  ACE_NEW_RETURN (
      result,
      ::IOP::Codec::InvalidTypeForEncoding (*this),
      0
    );
  return result;
}

void IOP::Codec::InvalidTypeForEncoding::_raise (void) const
{
  TAO_RAISE (*this);
}

void IOP::Codec::InvalidTypeForEncoding::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW (CORBA::MARSHAL ());
}

void IOP::Codec::InvalidTypeForEncoding::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
CORBA::TypeCode_ptr IOP::Codec::InvalidTypeForEncoding::_type (void) const
{
  ACE_DEBUG ((LM_DEBUG,
              ACE_LIB_TEXT ("This TAO-specific method is now")
              ACE_LIB_TEXT (" deprecated and will be removed")
              ACE_LIB_TEXT (" in future versions.\n")));
  
  return ::IOP::Codec::_tc_InvalidTypeForEncoding;
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

IOP::Codec::FormatMismatch::FormatMismatch (void)
  : CORBA::UserException (
        "IDL:omg.org/IOP/Codec/FormatMismatch:1.0",
        "FormatMismatch"
      )
{
}

IOP::Codec::FormatMismatch::~FormatMismatch (void)
{
}

IOP::Codec::FormatMismatch::FormatMismatch (const ::IOP::Codec::FormatMismatch &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

IOP::Codec::FormatMismatch&
IOP::Codec::FormatMismatch::operator= (const ::IOP::Codec::FormatMismatch &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

void IOP::Codec::FormatMismatch::_tao_any_destructor (void *_tao_void_pointer)
{
  FormatMismatch *_tao_tmp_pointer =
    ACE_static_cast (FormatMismatch*, _tao_void_pointer);
  delete _tao_tmp_pointer;
}

IOP::Codec::FormatMismatch *
IOP::Codec::FormatMismatch::_downcast (CORBA::Exception *_tao_excp)
{
  if (!ACE_OS::strcmp ("IDL:omg.org/IOP/Codec/FormatMismatch:1.0", _tao_excp->_rep_id ()))
    {
      return ACE_dynamic_cast (FormatMismatch *, _tao_excp);
    }
  else
    {
      return 0;
    }
}

CORBA::Exception *IOP::Codec::FormatMismatch::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::IOP::Codec::FormatMismatch, 0);
  return retval;
}

CORBA::Exception *
IOP::Codec::FormatMismatch::_tao_duplicate (void) const
{
  CORBA::Exception *result;
  ACE_NEW_RETURN (
      result,
      ::IOP::Codec::FormatMismatch (*this),
      0
    );
  return result;
}

void IOP::Codec::FormatMismatch::_raise (void) const
{
  TAO_RAISE (*this);
}

void IOP::Codec::FormatMismatch::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW (CORBA::MARSHAL ());
}

void IOP::Codec::FormatMismatch::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
CORBA::TypeCode_ptr IOP::Codec::FormatMismatch::_type (void) const
{
  ACE_DEBUG ((LM_DEBUG,
              ACE_LIB_TEXT ("This TAO-specific method is now")
              ACE_LIB_TEXT (" deprecated and will be removed")
              ACE_LIB_TEXT (" in future versions.\n")));
  
  return ::IOP::Codec::_tc_FormatMismatch;
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

IOP::Codec::TypeMismatch::TypeMismatch (void)
  : CORBA::UserException (
        "IDL:omg.org/IOP/Codec/TypeMismatch:1.0",
        "TypeMismatch"
      )
{
}

IOP::Codec::TypeMismatch::~TypeMismatch (void)
{
}

IOP::Codec::TypeMismatch::TypeMismatch (const ::IOP::Codec::TypeMismatch &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

IOP::Codec::TypeMismatch&
IOP::Codec::TypeMismatch::operator= (const ::IOP::Codec::TypeMismatch &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

void IOP::Codec::TypeMismatch::_tao_any_destructor (void *_tao_void_pointer)
{
  TypeMismatch *_tao_tmp_pointer =
    ACE_static_cast (TypeMismatch*, _tao_void_pointer);
  delete _tao_tmp_pointer;
}

IOP::Codec::TypeMismatch *
IOP::Codec::TypeMismatch::_downcast (CORBA::Exception *_tao_excp)
{
  if (!ACE_OS::strcmp ("IDL:omg.org/IOP/Codec/TypeMismatch:1.0", _tao_excp->_rep_id ()))
    {
      return ACE_dynamic_cast (TypeMismatch *, _tao_excp);
    }
  else
    {
      return 0;
    }
}

CORBA::Exception *IOP::Codec::TypeMismatch::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::IOP::Codec::TypeMismatch, 0);
  return retval;
}

CORBA::Exception *
IOP::Codec::TypeMismatch::_tao_duplicate (void) const
{
  CORBA::Exception *result;
  ACE_NEW_RETURN (
      result,
      ::IOP::Codec::TypeMismatch (*this),
      0
    );
  return result;
}

void IOP::Codec::TypeMismatch::_raise (void) const
{
  TAO_RAISE (*this);
}

void IOP::Codec::TypeMismatch::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW (CORBA::MARSHAL ());
}

void IOP::Codec::TypeMismatch::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
CORBA::TypeCode_ptr IOP::Codec::TypeMismatch::_type (void) const
{
  ACE_DEBUG ((LM_DEBUG,
              ACE_LIB_TEXT ("This TAO-specific method is now")
              ACE_LIB_TEXT (" deprecated and will be removed")
              ACE_LIB_TEXT (" in future versions.\n")));
  
  return ::IOP::Codec::_tc_TypeMismatch;
}

IOP::Codec::Codec (void)
{}

IOP::Codec::~Codec (void)
{}

void 
IOP::Codec::_tao_any_destructor (void *_tao_void_pointer)
{
  Codec *_tao_tmp_pointer =
    ACE_static_cast (Codec *, _tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

IOP::Codec_ptr
IOP::Codec::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return Codec::_nil ();
    }
  
  Codec_ptr proxy =
    dynamic_cast<Codec_ptr> (_tao_objref);
  
  return Codec::_duplicate (proxy);
}

IOP::Codec_ptr
IOP::Codec::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return Codec::_nil ();
    }
  
  Codec_ptr proxy =
    dynamic_cast<Codec_ptr> (_tao_objref);
  
  return Codec::_duplicate (proxy);
}

IOP::Codec_ptr
IOP::Codec::_duplicate (Codec_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

CORBA::Boolean
IOP::Codec::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/IOP/Codec:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
     )
    {
      return 1; // success using local knowledge
    }
  else
    {
      return 0;
    }
}

const char* IOP::Codec::_interface_repository_id (void) const
{
  return "IDL:omg.org/IOP/Codec:1.0";
}

CORBA::Boolean
IOP::Codec::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from 
// be\be_visitor_structure/structure_cs.cpp:66

void 
IOP::Encoding::_tao_any_destructor (
    void *_tao_void_pointer
  )
{
  Encoding *_tao_tmp_pointer =
    ACE_static_cast (Encoding *, _tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for IOP::CodecFactory.

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
IOP::CodecFactory_ptr
TAO::Objref_Traits<IOP::CodecFactory>::tao_duplicate (
    IOP::CodecFactory_ptr p
  )
{
  return IOP::CodecFactory::_duplicate (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Objref_Traits<IOP::CodecFactory>::tao_release (
    IOP::CodecFactory_ptr p
  )
{
  CORBA::release (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
IOP::CodecFactory_ptr
TAO::Objref_Traits<IOP::CodecFactory>::tao_nil (void)
{
  return IOP::CodecFactory::_nil ();
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::Boolean
TAO::Objref_Traits<IOP::CodecFactory>::tao_marshal (
    IOP::CodecFactory_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return p->marshal (cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*IOP__TAO_CodecFactory_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

IOP::CodecFactory::UnknownEncoding::UnknownEncoding (void)
  : CORBA::UserException (
        "IDL:omg.org/IOP/CodecFactory/UnknownEncoding:1.0",
        "UnknownEncoding"
      )
{
}

IOP::CodecFactory::UnknownEncoding::~UnknownEncoding (void)
{
}

IOP::CodecFactory::UnknownEncoding::UnknownEncoding (const ::IOP::CodecFactory::UnknownEncoding &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

IOP::CodecFactory::UnknownEncoding&
IOP::CodecFactory::UnknownEncoding::operator= (const ::IOP::CodecFactory::UnknownEncoding &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

void IOP::CodecFactory::UnknownEncoding::_tao_any_destructor (void *_tao_void_pointer)
{
  UnknownEncoding *_tao_tmp_pointer =
    ACE_static_cast (UnknownEncoding*, _tao_void_pointer);
  delete _tao_tmp_pointer;
}

IOP::CodecFactory::UnknownEncoding *
IOP::CodecFactory::UnknownEncoding::_downcast (CORBA::Exception *_tao_excp)
{
  if (!ACE_OS::strcmp ("IDL:omg.org/IOP/CodecFactory/UnknownEncoding:1.0", _tao_excp->_rep_id ()))
    {
      return ACE_dynamic_cast (UnknownEncoding *, _tao_excp);
    }
  else
    {
      return 0;
    }
}

CORBA::Exception *IOP::CodecFactory::UnknownEncoding::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::IOP::CodecFactory::UnknownEncoding, 0);
  return retval;
}

CORBA::Exception *
IOP::CodecFactory::UnknownEncoding::_tao_duplicate (void) const
{
  CORBA::Exception *result;
  ACE_NEW_RETURN (
      result,
      ::IOP::CodecFactory::UnknownEncoding (*this),
      0
    );
  return result;
}

void IOP::CodecFactory::UnknownEncoding::_raise (void) const
{
  TAO_RAISE (*this);
}

void IOP::CodecFactory::UnknownEncoding::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW (CORBA::MARSHAL ());
}

void IOP::CodecFactory::UnknownEncoding::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
CORBA::TypeCode_ptr IOP::CodecFactory::UnknownEncoding::_type (void) const
{
  ACE_DEBUG ((LM_DEBUG,
              ACE_LIB_TEXT ("This TAO-specific method is now")
              ACE_LIB_TEXT (" deprecated and will be removed")
              ACE_LIB_TEXT (" in future versions.\n")));
  
  return ::IOP::CodecFactory::_tc_UnknownEncoding;
}

IOP::CodecFactory::CodecFactory (void)
{}

IOP::CodecFactory::~CodecFactory (void)
{}

void 
IOP::CodecFactory::_tao_any_destructor (void *_tao_void_pointer)
{
  CodecFactory *_tao_tmp_pointer =
    ACE_static_cast (CodecFactory *, _tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

IOP::CodecFactory_ptr
IOP::CodecFactory::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return CodecFactory::_nil ();
    }
  
  CodecFactory_ptr proxy =
    dynamic_cast<CodecFactory_ptr> (_tao_objref);
  
  return CodecFactory::_duplicate (proxy);
}

IOP::CodecFactory_ptr
IOP::CodecFactory::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return CodecFactory::_nil ();
    }
  
  CodecFactory_ptr proxy =
    dynamic_cast<CodecFactory_ptr> (_tao_objref);
  
  return CodecFactory::_duplicate (proxy);
}

IOP::CodecFactory_ptr
IOP::CodecFactory::_duplicate (CodecFactory_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

CORBA::Boolean
IOP::CodecFactory::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/IOP/CodecFactory:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
     )
    {
      return 1; // success using local knowledge
    }
  else
    {
      return 0;
    }
}

const char* IOP::CodecFactory::_interface_repository_id (void) const
{
  return "IDL:omg.org/IOP/CodecFactory:1.0";
}

CORBA::Boolean
IOP::CodecFactory::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_cs.cpp:61

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const IOP::Encoding &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.format) &&
    (strm << CORBA::Any::from_octet (_tao_aggregate.major_version)) &&
    (strm << CORBA::Any::from_octet (_tao_aggregate.minor_version));
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    IOP::Encoding &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.format) &&
    (strm >> CORBA::Any::to_octet (_tao_aggregate.major_version)) &&
    (strm >> CORBA::Any::to_octet (_tao_aggregate.minor_version));
}

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1628

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Objref_Traits<
        IOP::Codec
      >;

  template class
    TAO_Objref_Var_T<
        IOP::Codec
      >;
  
  template class
    TAO_Objref_Out_T<
        IOP::Codec
      >;

  template class
    TAO_Fixed_Var_T<
        IOP::Encoding
      >;

  template class
    TAO_Var_Base_T<
        IOP::Encoding
      >;

  template class
    TAO::Objref_Traits<
        IOP::CodecFactory
      >;

  template class
    TAO_Objref_Var_T<
        IOP::CodecFactory
      >;
  
  template class
    TAO_Objref_Out_T<
        IOP::CodecFactory
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Objref_Traits< \
        IOP::Codec \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        IOP::Codec
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        IOP::Codec
      >

# pragma instantiate \
    TAO_Fixed_Var_T< \
        IOP::Encoding \
      >

# pragma instantiate \
    TAO_Var_Base_T< \
        IOP::Encoding \
      >

# pragma instantiate \
    TAO::Objref_Traits< \
        IOP::CodecFactory \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        IOP::CodecFactory
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        IOP::CodecFactory
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 


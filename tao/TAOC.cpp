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


#include "TAOC.h"
#include "tao/CDR.h"
#include "tao/Typecode.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "TAOC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:64

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from 
// be\be_visitor_structure/structure_cs.cpp:66

void 
TAO::BufferingConstraint::_tao_any_destructor (
    void *_tao_void_pointer
  )
{
  BufferingConstraint *_tao_tmp_pointer =
    ACE_static_cast (BufferingConstraint *, _tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for TAO::BufferingConstraintPolicy.

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
TAO::BufferingConstraintPolicy_ptr
TAO::Objref_Traits<TAO::BufferingConstraintPolicy>::tao_duplicate (
    TAO::BufferingConstraintPolicy_ptr p
  )
{
  return TAO::BufferingConstraintPolicy::_duplicate (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Objref_Traits<TAO::BufferingConstraintPolicy>::tao_release (
    TAO::BufferingConstraintPolicy_ptr p
  )
{
  CORBA::release (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
TAO::BufferingConstraintPolicy_ptr
TAO::Objref_Traits<TAO::BufferingConstraintPolicy>::tao_nil (void)
{
  return TAO::BufferingConstraintPolicy::_nil ();
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::Boolean
TAO::Objref_Traits<TAO::BufferingConstraintPolicy>::tao_marshal (
    TAO::BufferingConstraintPolicy_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return p->marshal (cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*TAO__TAO_BufferingConstraintPolicy_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

TAO::BufferingConstraintPolicy::BufferingConstraintPolicy (void)
{}

TAO::BufferingConstraintPolicy::~BufferingConstraintPolicy (void)
{}

void 
TAO::BufferingConstraintPolicy::_tao_any_destructor (void *_tao_void_pointer)
{
  BufferingConstraintPolicy *_tao_tmp_pointer =
    ACE_static_cast (BufferingConstraintPolicy *, _tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

TAO::BufferingConstraintPolicy_ptr
TAO::BufferingConstraintPolicy::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return BufferingConstraintPolicy::_nil ();
    }
  
  BufferingConstraintPolicy_ptr proxy =
    dynamic_cast<BufferingConstraintPolicy_ptr> (_tao_objref);
  
  return BufferingConstraintPolicy::_duplicate (proxy);
}

TAO::BufferingConstraintPolicy_ptr
TAO::BufferingConstraintPolicy::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return BufferingConstraintPolicy::_nil ();
    }
  
  BufferingConstraintPolicy_ptr proxy =
    dynamic_cast<BufferingConstraintPolicy_ptr> (_tao_objref);
  
  return BufferingConstraintPolicy::_duplicate (proxy);
}

TAO::BufferingConstraintPolicy_ptr
TAO::BufferingConstraintPolicy::_duplicate (BufferingConstraintPolicy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

CORBA::Boolean
TAO::BufferingConstraintPolicy::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Policy:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:tao/TAO/BufferingConstraintPolicy:1.0"
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

const char* TAO::BufferingConstraintPolicy::_interface_repository_id (void) const
{
  return "IDL:tao/TAO/BufferingConstraintPolicy:1.0";
}

CORBA::Boolean
TAO::BufferingConstraintPolicy::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_cs.cpp:61

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const TAO::BufferingConstraint &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.mode) &&
    (strm << _tao_aggregate.timeout) &&
    (strm << _tao_aggregate.message_count) &&
    (strm << _tao_aggregate.message_bytes);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    TAO::BufferingConstraint &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.mode) &&
    (strm >> _tao_aggregate.timeout) &&
    (strm >> _tao_aggregate.message_count) &&
    (strm >> _tao_aggregate.message_bytes);
}

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1628

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO_Fixed_Var_T<
        TAO::BufferingConstraint
      >;

  template class
    TAO_Var_Base_T<
        TAO::BufferingConstraint
      >;

  template class
    TAO::Objref_Traits<
        TAO::BufferingConstraintPolicy
      >;

  template class
    TAO_Objref_Var_T<
        TAO::BufferingConstraintPolicy
      >;
  
  template class
    TAO_Objref_Out_T<
        TAO::BufferingConstraintPolicy
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO_Fixed_Var_T< \
        TAO::BufferingConstraint \
      >

# pragma instantiate \
    TAO_Var_Base_T< \
        TAO::BufferingConstraint \
      >

# pragma instantiate \
    TAO::Objref_Traits< \
        TAO::BufferingConstraintPolicy \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        TAO::BufferingConstraintPolicy
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        TAO::BufferingConstraintPolicy
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 


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
// be\be_codegen.cpp:302


#include "CurrentC.h"
#include "tao/CDR.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "CurrentC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:65

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for CORBA::Current.

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::Current_ptr
TAO::Objref_Traits<CORBA::Current>::duplicate (
    CORBA::Current_ptr p
  )
{
  return CORBA::Current::_duplicate (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Objref_Traits<CORBA::Current>::release (
    CORBA::Current_ptr p
  )
{
  CORBA::release (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::Current_ptr
TAO::Objref_Traits<CORBA::Current>::nil (void)
{
  return CORBA::Current::_nil ();
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::Boolean
TAO::Objref_Traits<CORBA::Current>::marshal (
    CORBA::Current_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

CORBA::Current::Current (void)
{}

CORBA::Current::~Current (void)
{}

void 
CORBA::Current::_tao_any_destructor (void *_tao_void_pointer)
{
  Current *_tao_tmp_pointer =
    static_cast<Current *> (_tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

CORBA::Current_ptr
CORBA::Current::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return Current::_nil ();
    }
  
  Current_ptr proxy =
    dynamic_cast<Current_ptr> (_tao_objref);
  
  return Current::_duplicate (proxy);
}

CORBA::Current_ptr
CORBA::Current::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return Current::_nil ();
    }
  
  Current_ptr proxy =
    dynamic_cast<Current_ptr> (_tao_objref);
  
  return Current::_duplicate (proxy);
}

CORBA::Current_ptr
CORBA::Current::_duplicate (Current_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

CORBA::Boolean
CORBA::Current::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Current:1.0"
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

const char* CORBA::Current::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/Current:1.0";
}

CORBA::Boolean
CORBA::Current::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1629

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Objref_Traits<
        CORBA::Current
      >;

  template class
    TAO_Objref_Var_T<
        CORBA::Current
      >;
  
  template class
    TAO_Objref_Out_T<
        CORBA::Current
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Objref_Traits< \
        CORBA::Current \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        CORBA::Current
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        CORBA::Current
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

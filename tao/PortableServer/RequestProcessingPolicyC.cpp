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


#include "RequestProcessingPolicyC.h"
#include "tao/CDR.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "RequestProcessingPolicyC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:69

#if (TAO_HAS_MINIMUM_POA == 0)

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for PortableServer::RequestProcessingPolicy.

PortableServer::RequestProcessingPolicy_ptr
TAO::Objref_Traits<PortableServer::RequestProcessingPolicy>::duplicate (
    PortableServer::RequestProcessingPolicy_ptr p
  )
{
  return PortableServer::RequestProcessingPolicy::_duplicate (p);
}

void
TAO::Objref_Traits<PortableServer::RequestProcessingPolicy>::release (
    PortableServer::RequestProcessingPolicy_ptr p
  )
{
  CORBA::release (p);
}

PortableServer::RequestProcessingPolicy_ptr
TAO::Objref_Traits<PortableServer::RequestProcessingPolicy>::nil (void)
{
  return PortableServer::RequestProcessingPolicy::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<PortableServer::RequestProcessingPolicy>::marshal (
    PortableServer::RequestProcessingPolicy_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

PortableServer::RequestProcessingPolicy::RequestProcessingPolicy (void)
{}

PortableServer::RequestProcessingPolicy::~RequestProcessingPolicy (void)
{}

void 
PortableServer::RequestProcessingPolicy::_tao_any_destructor (void *_tao_void_pointer)
{
  RequestProcessingPolicy *_tao_tmp_pointer =
    static_cast<RequestProcessingPolicy *> (_tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

PortableServer::RequestProcessingPolicy_ptr
PortableServer::RequestProcessingPolicy::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return RequestProcessingPolicy::_nil ();
    }
  
  RequestProcessingPolicy_ptr proxy =
    dynamic_cast<RequestProcessingPolicy_ptr> (_tao_objref);
  
  return RequestProcessingPolicy::_duplicate (proxy);
}

PortableServer::RequestProcessingPolicy_ptr
PortableServer::RequestProcessingPolicy::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return RequestProcessingPolicy::_nil ();
    }
  
  RequestProcessingPolicy_ptr proxy =
    dynamic_cast<RequestProcessingPolicy_ptr> (_tao_objref);
  
  return RequestProcessingPolicy::_duplicate (proxy);
}

PortableServer::RequestProcessingPolicy_ptr
PortableServer::RequestProcessingPolicy::_duplicate (RequestProcessingPolicy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
PortableServer::RequestProcessingPolicy::_tao_release (RequestProcessingPolicy_ptr obj)
{
  CORBA::release (obj);
}

CORBA::Boolean
PortableServer::RequestProcessingPolicy::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Policy:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/PortableServer/RequestProcessingPolicy:2.3"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
    )
    {
      return true; // success using local knowledge
    }
  else
    {
      return false;
    }
}

const char* PortableServer::RequestProcessingPolicy::_interface_repository_id (void) const
{
  return "IDL:omg.org/PortableServer/RequestProcessingPolicy:2.3";
}

CORBA::Boolean
PortableServer::RequestProcessingPolicy::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_enum/cdr_op_cs.cpp:51

CORBA::Boolean operator<< (TAO_OutputCDR & strm, PortableServer::RequestProcessingPolicyValue _tao_enumerator)
{
  return strm << static_cast<CORBA::ULong> (_tao_enumerator);
}

CORBA::Boolean operator>> (TAO_InputCDR & strm, PortableServer::RequestProcessingPolicyValue & _tao_enumerator)
{
  CORBA::ULong _tao_temp = 0;
  CORBA::Boolean const _tao_success = strm >> _tao_temp;
  
  if (_tao_success)
    {
      _tao_enumerator = static_cast<PortableServer::RequestProcessingPolicyValue> (_tao_temp);
    }
  
  return _tao_success;
}

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1528

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Objref_Traits<
        PortableServer::RequestProcessingPolicy
      >;

  template class
    TAO_Objref_Var_T<
        PortableServer::RequestProcessingPolicy
      >;
  
  template class
    TAO_Objref_Out_T<
        PortableServer::RequestProcessingPolicy
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Objref_Traits< \
        PortableServer::RequestProcessingPolicy \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        PortableServer::RequestProcessingPolicy
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        PortableServer::RequestProcessingPolicy
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */

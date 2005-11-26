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
// be\be_codegen.cpp:277


#include "InterceptorC.h"
#include "tao/CDR.h"
#include "ace/OS_NS_string.h"

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:70

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for PortableInterceptor::Interceptor.

PortableInterceptor::Interceptor_ptr
TAO::Objref_Traits<PortableInterceptor::Interceptor>::duplicate (
    PortableInterceptor::Interceptor_ptr p
  )
{
  return PortableInterceptor::Interceptor::_duplicate (p);
}

void
TAO::Objref_Traits<PortableInterceptor::Interceptor>::release (
    PortableInterceptor::Interceptor_ptr p
  )
{
  CORBA::release (p);
}

PortableInterceptor::Interceptor_ptr
TAO::Objref_Traits<PortableInterceptor::Interceptor>::nil (void)
{
  return PortableInterceptor::Interceptor::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<PortableInterceptor::Interceptor>::marshal (
    PortableInterceptor::Interceptor_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return ::CORBA::Object::marshal (p, cdr);
}

PortableInterceptor::Interceptor::Interceptor (void)
{}

PortableInterceptor::Interceptor::~Interceptor (void)
{}

PortableInterceptor::Interceptor_ptr
PortableInterceptor::Interceptor::_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return Interceptor::_duplicate (
      dynamic_cast<Interceptor_ptr> (_tao_objref)
    );
}

PortableInterceptor::Interceptor_ptr
PortableInterceptor::Interceptor::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return Interceptor::_duplicate (
      dynamic_cast<Interceptor_ptr> (_tao_objref)
    );
}

PortableInterceptor::Interceptor_ptr
PortableInterceptor::Interceptor::_duplicate (Interceptor_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
PortableInterceptor::Interceptor::_tao_release (Interceptor_ptr obj)
{
  CORBA::release (obj);
}

::CORBA::Boolean
PortableInterceptor::Interceptor::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/PortableInterceptor/Interceptor:1.0"
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

const char* PortableInterceptor::Interceptor::_interface_repository_id (void) const
{
  return "IDL:omg.org/PortableInterceptor/Interceptor:1.0";
}

::CORBA::Boolean
PortableInterceptor::Interceptor::marshal (TAO_OutputCDR &)
{
  return false;
}

TAO_END_VERSIONED_NAMESPACE_DECL

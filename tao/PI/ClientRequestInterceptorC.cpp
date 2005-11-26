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


#include "ClientRequestInterceptorC.h"
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

// Traits specializations for PortableInterceptor::ClientRequestInterceptor.

PortableInterceptor::ClientRequestInterceptor_ptr
TAO::Objref_Traits<PortableInterceptor::ClientRequestInterceptor>::duplicate (
    PortableInterceptor::ClientRequestInterceptor_ptr p
  )
{
  return PortableInterceptor::ClientRequestInterceptor::_duplicate (p);
}

void
TAO::Objref_Traits<PortableInterceptor::ClientRequestInterceptor>::release (
    PortableInterceptor::ClientRequestInterceptor_ptr p
  )
{
  CORBA::release (p);
}

PortableInterceptor::ClientRequestInterceptor_ptr
TAO::Objref_Traits<PortableInterceptor::ClientRequestInterceptor>::nil (void)
{
  return PortableInterceptor::ClientRequestInterceptor::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<PortableInterceptor::ClientRequestInterceptor>::marshal (
    PortableInterceptor::ClientRequestInterceptor_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return ::CORBA::Object::marshal (p, cdr);
}

PortableInterceptor::ClientRequestInterceptor::ClientRequestInterceptor (void)
{}

PortableInterceptor::ClientRequestInterceptor::~ClientRequestInterceptor (void)
{}

PortableInterceptor::ClientRequestInterceptor_ptr
PortableInterceptor::ClientRequestInterceptor::_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return ClientRequestInterceptor::_duplicate (
      dynamic_cast<ClientRequestInterceptor_ptr> (_tao_objref)
    );
}

PortableInterceptor::ClientRequestInterceptor_ptr
PortableInterceptor::ClientRequestInterceptor::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return ClientRequestInterceptor::_duplicate (
      dynamic_cast<ClientRequestInterceptor_ptr> (_tao_objref)
    );
}

PortableInterceptor::ClientRequestInterceptor_ptr
PortableInterceptor::ClientRequestInterceptor::_duplicate (ClientRequestInterceptor_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
PortableInterceptor::ClientRequestInterceptor::_tao_release (ClientRequestInterceptor_ptr obj)
{
  CORBA::release (obj);
}

::CORBA::Boolean
PortableInterceptor::ClientRequestInterceptor::_is_a (
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
          "IDL:omg.org/PortableInterceptor/ClientRequestInterceptor:1.0"
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

const char* PortableInterceptor::ClientRequestInterceptor::_interface_repository_id (void) const
{
  return "IDL:omg.org/PortableInterceptor/ClientRequestInterceptor:1.0";
}

::CORBA::Boolean
PortableInterceptor::ClientRequestInterceptor::marshal (TAO_OutputCDR &)
{
  return false;
}

TAO_END_VERSIONED_NAMESPACE_DECL

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


#include "ServerRequestInterceptorC.h"
#include "tao/CDR.h"
#include "tao/ORB_Core.h"
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

// Traits specializations for PortableInterceptor::ServerRequestInterceptor.

PortableInterceptor::ServerRequestInterceptor_ptr
TAO::Objref_Traits<PortableInterceptor::ServerRequestInterceptor>::duplicate (
    PortableInterceptor::ServerRequestInterceptor_ptr p
  )
{
  return PortableInterceptor::ServerRequestInterceptor::_duplicate (p);
}

void
TAO::Objref_Traits<PortableInterceptor::ServerRequestInterceptor>::release (
    PortableInterceptor::ServerRequestInterceptor_ptr p
  )
{
  CORBA::release (p);
}

PortableInterceptor::ServerRequestInterceptor_ptr
TAO::Objref_Traits<PortableInterceptor::ServerRequestInterceptor>::nil (void)
{
  return PortableInterceptor::ServerRequestInterceptor::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<PortableInterceptor::ServerRequestInterceptor>::marshal (
    PortableInterceptor::ServerRequestInterceptor_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return ::CORBA::Object::marshal (p, cdr);
}

PortableInterceptor::ServerRequestInterceptor::ServerRequestInterceptor (void)
{}

PortableInterceptor::ServerRequestInterceptor::~ServerRequestInterceptor (void)
{}

PortableInterceptor::ServerRequestInterceptor_ptr
PortableInterceptor::ServerRequestInterceptor::_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return ServerRequestInterceptor::_duplicate (
      dynamic_cast<ServerRequestInterceptor_ptr> (_tao_objref)
    );
}

PortableInterceptor::ServerRequestInterceptor_ptr
PortableInterceptor::ServerRequestInterceptor::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return ServerRequestInterceptor::_duplicate (
      dynamic_cast<ServerRequestInterceptor_ptr> (_tao_objref)
    );
}

PortableInterceptor::ServerRequestInterceptor_ptr
PortableInterceptor::ServerRequestInterceptor::_duplicate (ServerRequestInterceptor_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
PortableInterceptor::ServerRequestInterceptor::_tao_release (ServerRequestInterceptor_ptr obj)
{
  CORBA::release (obj);
}

::CORBA::Boolean
PortableInterceptor::ServerRequestInterceptor::_is_a (
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
          "IDL:omg.org/PortableInterceptor/ServerRequestInterceptor:1.0"
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

const char* PortableInterceptor::ServerRequestInterceptor::_interface_repository_id (void) const
{
  return "IDL:omg.org/PortableInterceptor/ServerRequestInterceptor:1.0";
}

::CORBA::Boolean
PortableInterceptor::ServerRequestInterceptor::marshal (TAO_OutputCDR &)
{
  return false;
}

TAO_END_VERSIONED_NAMESPACE_DECL

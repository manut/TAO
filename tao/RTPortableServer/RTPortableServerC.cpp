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
// be\be_codegen.cpp:291


#include "RTPortableServer.h"
#include "tao/CDR.h"
#include "tao/ORB_Core.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:69

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for RTPortableServer::POA.

RTPortableServer::POA_ptr
TAO::Objref_Traits<RTPortableServer::POA>::duplicate (
    RTPortableServer::POA_ptr p
  )
{
  return RTPortableServer::POA::_duplicate (p);
}

void
TAO::Objref_Traits<RTPortableServer::POA>::release (
    RTPortableServer::POA_ptr p
  )
{
  CORBA::release (p);
}

RTPortableServer::POA_ptr
TAO::Objref_Traits<RTPortableServer::POA>::nil (void)
{
  return RTPortableServer::POA::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<RTPortableServer::POA>::marshal (
    RTPortableServer::POA_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

RTPortableServer::POA::POA (void)
{}

RTPortableServer::POA::~POA (void)
{}

void 
RTPortableServer::POA::_tao_any_destructor (void *_tao_void_pointer)
{
  POA *_tao_tmp_pointer =
    static_cast<POA *> (_tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

RTPortableServer::POA_ptr
RTPortableServer::POA::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return POA::_nil ();
    }
  
  POA_ptr proxy =
    dynamic_cast<POA_ptr> (_tao_objref);
  
  return POA::_duplicate (proxy);
}

RTPortableServer::POA_ptr
RTPortableServer::POA::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return POA::_nil ();
    }
  
  POA_ptr proxy =
    dynamic_cast<POA_ptr> (_tao_objref);
  
  return POA::_duplicate (proxy);
}

RTPortableServer::POA_ptr
RTPortableServer::POA::_duplicate (POA_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
RTPortableServer::POA::_tao_release (POA_ptr obj)
{
  CORBA::release (obj);
}

CORBA::Boolean
RTPortableServer::POA::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/PortableServer/POA:2.3"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/RTPortableServer/POA:1.0"
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

const char* RTPortableServer::POA::_interface_repository_id (void) const
{
  return "IDL:omg.org/RTPortableServer/POA:1.0";
}

CORBA::Boolean
RTPortableServer::POA::marshal (TAO_OutputCDR &)
{
  return false;
}

TAO_END_VERSIONED_NAMESPACE_DECL

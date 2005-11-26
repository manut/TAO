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


#include "Messaging_No_ImplC.h"
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

// Traits specializations for Messaging::RebindPolicy.

Messaging::RebindPolicy_ptr
TAO::Objref_Traits<Messaging::RebindPolicy>::duplicate (
    Messaging::RebindPolicy_ptr p
  )
{
  return Messaging::RebindPolicy::_duplicate (p);
}

void
TAO::Objref_Traits<Messaging::RebindPolicy>::release (
    Messaging::RebindPolicy_ptr p
  )
{
  CORBA::release (p);
}

Messaging::RebindPolicy_ptr
TAO::Objref_Traits<Messaging::RebindPolicy>::nil (void)
{
  return Messaging::RebindPolicy::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<Messaging::RebindPolicy>::marshal (
    Messaging::RebindPolicy_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return ::CORBA::Object::marshal (p, cdr);
}

Messaging::RebindPolicy::RebindPolicy (void)
{}

Messaging::RebindPolicy::~RebindPolicy (void)
{}

Messaging::RebindPolicy_ptr
Messaging::RebindPolicy::_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return RebindPolicy::_duplicate (
      dynamic_cast<RebindPolicy_ptr> (_tao_objref)
    );
}

Messaging::RebindPolicy_ptr
Messaging::RebindPolicy::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return RebindPolicy::_duplicate (
      dynamic_cast<RebindPolicy_ptr> (_tao_objref)
    );
}

Messaging::RebindPolicy_ptr
Messaging::RebindPolicy::_duplicate (RebindPolicy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
Messaging::RebindPolicy::_tao_release (RebindPolicy_ptr obj)
{
  CORBA::release (obj);
}

::CORBA::Boolean
Messaging::RebindPolicy::_is_a (
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
          "IDL:omg.org/Messaging/RebindPolicy:1.0"
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

const char* Messaging::RebindPolicy::_interface_repository_id (void) const
{
  return "IDL:omg.org/Messaging/RebindPolicy:1.0";
}

::CORBA::Boolean
Messaging::RebindPolicy::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from 
// be\be_visitor_structure/structure_cs.cpp:66

void 
Messaging::PriorityRange::_tao_any_destructor (
    void *_tao_void_pointer
  )
{
  PriorityRange *_tao_tmp_pointer =
    static_cast<PriorityRange *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for Messaging::RequestPriorityPolicy.

Messaging::RequestPriorityPolicy_ptr
TAO::Objref_Traits<Messaging::RequestPriorityPolicy>::duplicate (
    Messaging::RequestPriorityPolicy_ptr p
  )
{
  return Messaging::RequestPriorityPolicy::_duplicate (p);
}

void
TAO::Objref_Traits<Messaging::RequestPriorityPolicy>::release (
    Messaging::RequestPriorityPolicy_ptr p
  )
{
  CORBA::release (p);
}

Messaging::RequestPriorityPolicy_ptr
TAO::Objref_Traits<Messaging::RequestPriorityPolicy>::nil (void)
{
  return Messaging::RequestPriorityPolicy::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<Messaging::RequestPriorityPolicy>::marshal (
    Messaging::RequestPriorityPolicy_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return ::CORBA::Object::marshal (p, cdr);
}

Messaging::RequestPriorityPolicy::RequestPriorityPolicy (void)
{}

Messaging::RequestPriorityPolicy::~RequestPriorityPolicy (void)
{}

Messaging::RequestPriorityPolicy_ptr
Messaging::RequestPriorityPolicy::_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return RequestPriorityPolicy::_duplicate (
      dynamic_cast<RequestPriorityPolicy_ptr> (_tao_objref)
    );
}

Messaging::RequestPriorityPolicy_ptr
Messaging::RequestPriorityPolicy::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return RequestPriorityPolicy::_duplicate (
      dynamic_cast<RequestPriorityPolicy_ptr> (_tao_objref)
    );
}

Messaging::RequestPriorityPolicy_ptr
Messaging::RequestPriorityPolicy::_duplicate (RequestPriorityPolicy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
Messaging::RequestPriorityPolicy::_tao_release (RequestPriorityPolicy_ptr obj)
{
  CORBA::release (obj);
}

::CORBA::Boolean
Messaging::RequestPriorityPolicy::_is_a (
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
          "IDL:omg.org/Messaging/RequestPriorityPolicy:1.0"
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

const char* Messaging::RequestPriorityPolicy::_interface_repository_id (void) const
{
  return "IDL:omg.org/Messaging/RequestPriorityPolicy:1.0";
}

::CORBA::Boolean
Messaging::RequestPriorityPolicy::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for Messaging::ReplyPriorityPolicy.

Messaging::ReplyPriorityPolicy_ptr
TAO::Objref_Traits<Messaging::ReplyPriorityPolicy>::duplicate (
    Messaging::ReplyPriorityPolicy_ptr p
  )
{
  return Messaging::ReplyPriorityPolicy::_duplicate (p);
}

void
TAO::Objref_Traits<Messaging::ReplyPriorityPolicy>::release (
    Messaging::ReplyPriorityPolicy_ptr p
  )
{
  CORBA::release (p);
}

Messaging::ReplyPriorityPolicy_ptr
TAO::Objref_Traits<Messaging::ReplyPriorityPolicy>::nil (void)
{
  return Messaging::ReplyPriorityPolicy::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<Messaging::ReplyPriorityPolicy>::marshal (
    Messaging::ReplyPriorityPolicy_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return ::CORBA::Object::marshal (p, cdr);
}

Messaging::ReplyPriorityPolicy::ReplyPriorityPolicy (void)
{}

Messaging::ReplyPriorityPolicy::~ReplyPriorityPolicy (void)
{}

Messaging::ReplyPriorityPolicy_ptr
Messaging::ReplyPriorityPolicy::_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return ReplyPriorityPolicy::_duplicate (
      dynamic_cast<ReplyPriorityPolicy_ptr> (_tao_objref)
    );
}

Messaging::ReplyPriorityPolicy_ptr
Messaging::ReplyPriorityPolicy::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return ReplyPriorityPolicy::_duplicate (
      dynamic_cast<ReplyPriorityPolicy_ptr> (_tao_objref)
    );
}

Messaging::ReplyPriorityPolicy_ptr
Messaging::ReplyPriorityPolicy::_duplicate (ReplyPriorityPolicy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
Messaging::ReplyPriorityPolicy::_tao_release (ReplyPriorityPolicy_ptr obj)
{
  CORBA::release (obj);
}

::CORBA::Boolean
Messaging::ReplyPriorityPolicy::_is_a (
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
          "IDL:omg.org/Messaging/ReplyPriorityPolicy:1.0"
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

const char* Messaging::ReplyPriorityPolicy::_interface_repository_id (void) const
{
  return "IDL:omg.org/Messaging/ReplyPriorityPolicy:1.0";
}

::CORBA::Boolean
Messaging::ReplyPriorityPolicy::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for Messaging::RequestStartTimePolicy.

Messaging::RequestStartTimePolicy_ptr
TAO::Objref_Traits<Messaging::RequestStartTimePolicy>::duplicate (
    Messaging::RequestStartTimePolicy_ptr p
  )
{
  return Messaging::RequestStartTimePolicy::_duplicate (p);
}

void
TAO::Objref_Traits<Messaging::RequestStartTimePolicy>::release (
    Messaging::RequestStartTimePolicy_ptr p
  )
{
  CORBA::release (p);
}

Messaging::RequestStartTimePolicy_ptr
TAO::Objref_Traits<Messaging::RequestStartTimePolicy>::nil (void)
{
  return Messaging::RequestStartTimePolicy::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<Messaging::RequestStartTimePolicy>::marshal (
    Messaging::RequestStartTimePolicy_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return ::CORBA::Object::marshal (p, cdr);
}

Messaging::RequestStartTimePolicy::RequestStartTimePolicy (void)
{}

Messaging::RequestStartTimePolicy::~RequestStartTimePolicy (void)
{}

Messaging::RequestStartTimePolicy_ptr
Messaging::RequestStartTimePolicy::_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return RequestStartTimePolicy::_duplicate (
      dynamic_cast<RequestStartTimePolicy_ptr> (_tao_objref)
    );
}

Messaging::RequestStartTimePolicy_ptr
Messaging::RequestStartTimePolicy::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return RequestStartTimePolicy::_duplicate (
      dynamic_cast<RequestStartTimePolicy_ptr> (_tao_objref)
    );
}

Messaging::RequestStartTimePolicy_ptr
Messaging::RequestStartTimePolicy::_duplicate (RequestStartTimePolicy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
Messaging::RequestStartTimePolicy::_tao_release (RequestStartTimePolicy_ptr obj)
{
  CORBA::release (obj);
}

::CORBA::Boolean
Messaging::RequestStartTimePolicy::_is_a (
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
          "IDL:omg.org/Messaging/RequestStartTimePolicy:1.0"
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

const char* Messaging::RequestStartTimePolicy::_interface_repository_id (void) const
{
  return "IDL:omg.org/Messaging/RequestStartTimePolicy:1.0";
}

::CORBA::Boolean
Messaging::RequestStartTimePolicy::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for Messaging::RequestEndTimePolicy.

Messaging::RequestEndTimePolicy_ptr
TAO::Objref_Traits<Messaging::RequestEndTimePolicy>::duplicate (
    Messaging::RequestEndTimePolicy_ptr p
  )
{
  return Messaging::RequestEndTimePolicy::_duplicate (p);
}

void
TAO::Objref_Traits<Messaging::RequestEndTimePolicy>::release (
    Messaging::RequestEndTimePolicy_ptr p
  )
{
  CORBA::release (p);
}

Messaging::RequestEndTimePolicy_ptr
TAO::Objref_Traits<Messaging::RequestEndTimePolicy>::nil (void)
{
  return Messaging::RequestEndTimePolicy::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<Messaging::RequestEndTimePolicy>::marshal (
    Messaging::RequestEndTimePolicy_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return ::CORBA::Object::marshal (p, cdr);
}

Messaging::RequestEndTimePolicy::RequestEndTimePolicy (void)
{}

Messaging::RequestEndTimePolicy::~RequestEndTimePolicy (void)
{}

Messaging::RequestEndTimePolicy_ptr
Messaging::RequestEndTimePolicy::_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return RequestEndTimePolicy::_duplicate (
      dynamic_cast<RequestEndTimePolicy_ptr> (_tao_objref)
    );
}

Messaging::RequestEndTimePolicy_ptr
Messaging::RequestEndTimePolicy::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return RequestEndTimePolicy::_duplicate (
      dynamic_cast<RequestEndTimePolicy_ptr> (_tao_objref)
    );
}

Messaging::RequestEndTimePolicy_ptr
Messaging::RequestEndTimePolicy::_duplicate (RequestEndTimePolicy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
Messaging::RequestEndTimePolicy::_tao_release (RequestEndTimePolicy_ptr obj)
{
  CORBA::release (obj);
}

::CORBA::Boolean
Messaging::RequestEndTimePolicy::_is_a (
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
          "IDL:omg.org/Messaging/RequestEndTimePolicy:1.0"
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

const char* Messaging::RequestEndTimePolicy::_interface_repository_id (void) const
{
  return "IDL:omg.org/Messaging/RequestEndTimePolicy:1.0";
}

::CORBA::Boolean
Messaging::RequestEndTimePolicy::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for Messaging::ReplyStartTimePolicy.

Messaging::ReplyStartTimePolicy_ptr
TAO::Objref_Traits<Messaging::ReplyStartTimePolicy>::duplicate (
    Messaging::ReplyStartTimePolicy_ptr p
  )
{
  return Messaging::ReplyStartTimePolicy::_duplicate (p);
}

void
TAO::Objref_Traits<Messaging::ReplyStartTimePolicy>::release (
    Messaging::ReplyStartTimePolicy_ptr p
  )
{
  CORBA::release (p);
}

Messaging::ReplyStartTimePolicy_ptr
TAO::Objref_Traits<Messaging::ReplyStartTimePolicy>::nil (void)
{
  return Messaging::ReplyStartTimePolicy::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<Messaging::ReplyStartTimePolicy>::marshal (
    Messaging::ReplyStartTimePolicy_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return ::CORBA::Object::marshal (p, cdr);
}

Messaging::ReplyStartTimePolicy::ReplyStartTimePolicy (void)
{}

Messaging::ReplyStartTimePolicy::~ReplyStartTimePolicy (void)
{}

Messaging::ReplyStartTimePolicy_ptr
Messaging::ReplyStartTimePolicy::_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return ReplyStartTimePolicy::_duplicate (
      dynamic_cast<ReplyStartTimePolicy_ptr> (_tao_objref)
    );
}

Messaging::ReplyStartTimePolicy_ptr
Messaging::ReplyStartTimePolicy::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return ReplyStartTimePolicy::_duplicate (
      dynamic_cast<ReplyStartTimePolicy_ptr> (_tao_objref)
    );
}

Messaging::ReplyStartTimePolicy_ptr
Messaging::ReplyStartTimePolicy::_duplicate (ReplyStartTimePolicy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
Messaging::ReplyStartTimePolicy::_tao_release (ReplyStartTimePolicy_ptr obj)
{
  CORBA::release (obj);
}

::CORBA::Boolean
Messaging::ReplyStartTimePolicy::_is_a (
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
          "IDL:omg.org/Messaging/ReplyStartTimePolicy:1.0"
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

const char* Messaging::ReplyStartTimePolicy::_interface_repository_id (void) const
{
  return "IDL:omg.org/Messaging/ReplyStartTimePolicy:1.0";
}

::CORBA::Boolean
Messaging::ReplyStartTimePolicy::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for Messaging::ReplyEndTimePolicy.

Messaging::ReplyEndTimePolicy_ptr
TAO::Objref_Traits<Messaging::ReplyEndTimePolicy>::duplicate (
    Messaging::ReplyEndTimePolicy_ptr p
  )
{
  return Messaging::ReplyEndTimePolicy::_duplicate (p);
}

void
TAO::Objref_Traits<Messaging::ReplyEndTimePolicy>::release (
    Messaging::ReplyEndTimePolicy_ptr p
  )
{
  CORBA::release (p);
}

Messaging::ReplyEndTimePolicy_ptr
TAO::Objref_Traits<Messaging::ReplyEndTimePolicy>::nil (void)
{
  return Messaging::ReplyEndTimePolicy::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<Messaging::ReplyEndTimePolicy>::marshal (
    Messaging::ReplyEndTimePolicy_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return ::CORBA::Object::marshal (p, cdr);
}

Messaging::ReplyEndTimePolicy::ReplyEndTimePolicy (void)
{}

Messaging::ReplyEndTimePolicy::~ReplyEndTimePolicy (void)
{}

Messaging::ReplyEndTimePolicy_ptr
Messaging::ReplyEndTimePolicy::_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return ReplyEndTimePolicy::_duplicate (
      dynamic_cast<ReplyEndTimePolicy_ptr> (_tao_objref)
    );
}

Messaging::ReplyEndTimePolicy_ptr
Messaging::ReplyEndTimePolicy::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return ReplyEndTimePolicy::_duplicate (
      dynamic_cast<ReplyEndTimePolicy_ptr> (_tao_objref)
    );
}

Messaging::ReplyEndTimePolicy_ptr
Messaging::ReplyEndTimePolicy::_duplicate (ReplyEndTimePolicy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
Messaging::ReplyEndTimePolicy::_tao_release (ReplyEndTimePolicy_ptr obj)
{
  CORBA::release (obj);
}

::CORBA::Boolean
Messaging::ReplyEndTimePolicy::_is_a (
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
          "IDL:omg.org/Messaging/ReplyEndTimePolicy:1.0"
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

const char* Messaging::ReplyEndTimePolicy::_interface_repository_id (void) const
{
  return "IDL:omg.org/Messaging/ReplyEndTimePolicy:1.0";
}

::CORBA::Boolean
Messaging::ReplyEndTimePolicy::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for Messaging::RelativeRequestTimeoutPolicy.

Messaging::RelativeRequestTimeoutPolicy_ptr
TAO::Objref_Traits<Messaging::RelativeRequestTimeoutPolicy>::duplicate (
    Messaging::RelativeRequestTimeoutPolicy_ptr p
  )
{
  return Messaging::RelativeRequestTimeoutPolicy::_duplicate (p);
}

void
TAO::Objref_Traits<Messaging::RelativeRequestTimeoutPolicy>::release (
    Messaging::RelativeRequestTimeoutPolicy_ptr p
  )
{
  CORBA::release (p);
}

Messaging::RelativeRequestTimeoutPolicy_ptr
TAO::Objref_Traits<Messaging::RelativeRequestTimeoutPolicy>::nil (void)
{
  return Messaging::RelativeRequestTimeoutPolicy::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<Messaging::RelativeRequestTimeoutPolicy>::marshal (
    Messaging::RelativeRequestTimeoutPolicy_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return ::CORBA::Object::marshal (p, cdr);
}

Messaging::RelativeRequestTimeoutPolicy::RelativeRequestTimeoutPolicy (void)
{}

Messaging::RelativeRequestTimeoutPolicy::~RelativeRequestTimeoutPolicy (void)
{}

Messaging::RelativeRequestTimeoutPolicy_ptr
Messaging::RelativeRequestTimeoutPolicy::_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return RelativeRequestTimeoutPolicy::_duplicate (
      dynamic_cast<RelativeRequestTimeoutPolicy_ptr> (_tao_objref)
    );
}

Messaging::RelativeRequestTimeoutPolicy_ptr
Messaging::RelativeRequestTimeoutPolicy::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return RelativeRequestTimeoutPolicy::_duplicate (
      dynamic_cast<RelativeRequestTimeoutPolicy_ptr> (_tao_objref)
    );
}

Messaging::RelativeRequestTimeoutPolicy_ptr
Messaging::RelativeRequestTimeoutPolicy::_duplicate (RelativeRequestTimeoutPolicy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
Messaging::RelativeRequestTimeoutPolicy::_tao_release (RelativeRequestTimeoutPolicy_ptr obj)
{
  CORBA::release (obj);
}

::CORBA::Boolean
Messaging::RelativeRequestTimeoutPolicy::_is_a (
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
          "IDL:omg.org/Messaging/RelativeRequestTimeoutPolicy:1.0"
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

const char* Messaging::RelativeRequestTimeoutPolicy::_interface_repository_id (void) const
{
  return "IDL:omg.org/Messaging/RelativeRequestTimeoutPolicy:1.0";
}

::CORBA::Boolean
Messaging::RelativeRequestTimeoutPolicy::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from 
// be\be_visitor_structure/structure_cs.cpp:66

void 
Messaging::RoutingTypeRange::_tao_any_destructor (
    void *_tao_void_pointer
  )
{
  RoutingTypeRange *_tao_tmp_pointer =
    static_cast<RoutingTypeRange *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for Messaging::RoutingPolicy.

Messaging::RoutingPolicy_ptr
TAO::Objref_Traits<Messaging::RoutingPolicy>::duplicate (
    Messaging::RoutingPolicy_ptr p
  )
{
  return Messaging::RoutingPolicy::_duplicate (p);
}

void
TAO::Objref_Traits<Messaging::RoutingPolicy>::release (
    Messaging::RoutingPolicy_ptr p
  )
{
  CORBA::release (p);
}

Messaging::RoutingPolicy_ptr
TAO::Objref_Traits<Messaging::RoutingPolicy>::nil (void)
{
  return Messaging::RoutingPolicy::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<Messaging::RoutingPolicy>::marshal (
    Messaging::RoutingPolicy_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return ::CORBA::Object::marshal (p, cdr);
}

Messaging::RoutingPolicy::RoutingPolicy (void)
{}

Messaging::RoutingPolicy::~RoutingPolicy (void)
{}

Messaging::RoutingPolicy_ptr
Messaging::RoutingPolicy::_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return RoutingPolicy::_duplicate (
      dynamic_cast<RoutingPolicy_ptr> (_tao_objref)
    );
}

Messaging::RoutingPolicy_ptr
Messaging::RoutingPolicy::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return RoutingPolicy::_duplicate (
      dynamic_cast<RoutingPolicy_ptr> (_tao_objref)
    );
}

Messaging::RoutingPolicy_ptr
Messaging::RoutingPolicy::_duplicate (RoutingPolicy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
Messaging::RoutingPolicy::_tao_release (RoutingPolicy_ptr obj)
{
  CORBA::release (obj);
}

::CORBA::Boolean
Messaging::RoutingPolicy::_is_a (
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
          "IDL:omg.org/Messaging/RoutingPolicy:1.0"
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

const char* Messaging::RoutingPolicy::_interface_repository_id (void) const
{
  return "IDL:omg.org/Messaging/RoutingPolicy:1.0";
}

::CORBA::Boolean
Messaging::RoutingPolicy::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for Messaging::MaxHopsPolicy.

Messaging::MaxHopsPolicy_ptr
TAO::Objref_Traits<Messaging::MaxHopsPolicy>::duplicate (
    Messaging::MaxHopsPolicy_ptr p
  )
{
  return Messaging::MaxHopsPolicy::_duplicate (p);
}

void
TAO::Objref_Traits<Messaging::MaxHopsPolicy>::release (
    Messaging::MaxHopsPolicy_ptr p
  )
{
  CORBA::release (p);
}

Messaging::MaxHopsPolicy_ptr
TAO::Objref_Traits<Messaging::MaxHopsPolicy>::nil (void)
{
  return Messaging::MaxHopsPolicy::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<Messaging::MaxHopsPolicy>::marshal (
    Messaging::MaxHopsPolicy_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return ::CORBA::Object::marshal (p, cdr);
}

Messaging::MaxHopsPolicy::MaxHopsPolicy (void)
{}

Messaging::MaxHopsPolicy::~MaxHopsPolicy (void)
{}

Messaging::MaxHopsPolicy_ptr
Messaging::MaxHopsPolicy::_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return MaxHopsPolicy::_duplicate (
      dynamic_cast<MaxHopsPolicy_ptr> (_tao_objref)
    );
}

Messaging::MaxHopsPolicy_ptr
Messaging::MaxHopsPolicy::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return MaxHopsPolicy::_duplicate (
      dynamic_cast<MaxHopsPolicy_ptr> (_tao_objref)
    );
}

Messaging::MaxHopsPolicy_ptr
Messaging::MaxHopsPolicy::_duplicate (MaxHopsPolicy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
Messaging::MaxHopsPolicy::_tao_release (MaxHopsPolicy_ptr obj)
{
  CORBA::release (obj);
}

::CORBA::Boolean
Messaging::MaxHopsPolicy::_is_a (
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
          "IDL:omg.org/Messaging/MaxHopsPolicy:1.0"
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

const char* Messaging::MaxHopsPolicy::_interface_repository_id (void) const
{
  return "IDL:omg.org/Messaging/MaxHopsPolicy:1.0";
}

::CORBA::Boolean
Messaging::MaxHopsPolicy::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for Messaging::QueueOrderPolicy.

Messaging::QueueOrderPolicy_ptr
TAO::Objref_Traits<Messaging::QueueOrderPolicy>::duplicate (
    Messaging::QueueOrderPolicy_ptr p
  )
{
  return Messaging::QueueOrderPolicy::_duplicate (p);
}

void
TAO::Objref_Traits<Messaging::QueueOrderPolicy>::release (
    Messaging::QueueOrderPolicy_ptr p
  )
{
  CORBA::release (p);
}

Messaging::QueueOrderPolicy_ptr
TAO::Objref_Traits<Messaging::QueueOrderPolicy>::nil (void)
{
  return Messaging::QueueOrderPolicy::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<Messaging::QueueOrderPolicy>::marshal (
    Messaging::QueueOrderPolicy_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return ::CORBA::Object::marshal (p, cdr);
}

Messaging::QueueOrderPolicy::QueueOrderPolicy (void)
{}

Messaging::QueueOrderPolicy::~QueueOrderPolicy (void)
{}

Messaging::QueueOrderPolicy_ptr
Messaging::QueueOrderPolicy::_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return QueueOrderPolicy::_duplicate (
      dynamic_cast<QueueOrderPolicy_ptr> (_tao_objref)
    );
}

Messaging::QueueOrderPolicy_ptr
Messaging::QueueOrderPolicy::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return QueueOrderPolicy::_duplicate (
      dynamic_cast<QueueOrderPolicy_ptr> (_tao_objref)
    );
}

Messaging::QueueOrderPolicy_ptr
Messaging::QueueOrderPolicy::_duplicate (QueueOrderPolicy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
Messaging::QueueOrderPolicy::_tao_release (QueueOrderPolicy_ptr obj)
{
  CORBA::release (obj);
}

::CORBA::Boolean
Messaging::QueueOrderPolicy::_is_a (
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
          "IDL:omg.org/Messaging/QueueOrderPolicy:1.0"
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

const char* Messaging::QueueOrderPolicy::_interface_repository_id (void) const
{
  return "IDL:omg.org/Messaging/QueueOrderPolicy:1.0";
}

::CORBA::Boolean
Messaging::QueueOrderPolicy::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_cs.cpp:61

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Messaging::PriorityRange &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.min) &&
    (strm << _tao_aggregate.max);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    Messaging::PriorityRange &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.min) &&
    (strm >> _tao_aggregate.max);
}

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_cs.cpp:61

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Messaging::RoutingTypeRange &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.min) &&
    (strm << _tao_aggregate.max);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    Messaging::RoutingTypeRange &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.min) &&
    (strm >> _tao_aggregate.max);
}

TAO_END_VERSIONED_NAMESPACE_DECL

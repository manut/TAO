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


#include "Messaging_RT_PolicyC.h"
#include "tao/Typecode.h"
#include "tao/Any_Impl_T.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "Messaging_RT_PolicyC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:64

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_Messaging_Timeout[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  34,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x4d657373), 
  ACE_NTOHL (0x6167696e), 
  ACE_NTOHL (0x672f5469), 
  ACE_NTOHL (0x6d656f75), 
  ACE_NTOHL (0x743a312e), 
  ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/Messaging/Timeout:1.0
    8,
  ACE_NTOHL (0x54696d65), 
  ACE_NTOHL (0x6f757400),  // name = Timeout
    CORBA::tk_alias, // typecode kind for typedefs
  56, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    31,
    ACE_NTOHL (0x49444c3a), 
    ACE_NTOHL (0x6f6d672e), 
    ACE_NTOHL (0x6f72672f), 
    ACE_NTOHL (0x54696d65), 
    ACE_NTOHL (0x42617365), 
    ACE_NTOHL (0x2f54696d), 
    ACE_NTOHL (0x65543a31), 
    ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/TimeBase/TimeT:1.0
        6,
    ACE_NTOHL (0x54696d65), 
    ACE_NTOHL (0x54000000),  // name = TimeT
        CORBA::tk_ulonglong,


};

static CORBA::TypeCode _tc_TAO_tc_Messaging_Timeout (
    CORBA::tk_alias,
    sizeof (_oc_Messaging_Timeout),
    (char *) &_oc_Messaging_Timeout,
    0,
    sizeof (Messaging::Timeout)
  );

namespace Messaging
{
  ::CORBA::TypeCode_ptr _tc_Timeout =
    &_tc_TAO_tc_Messaging_Timeout;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for Messaging::RelativeRoundtripTimeoutPolicy.

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
Messaging::RelativeRoundtripTimeoutPolicy_ptr
TAO::Objref_Traits<Messaging::RelativeRoundtripTimeoutPolicy>::tao_duplicate (
    Messaging::RelativeRoundtripTimeoutPolicy_ptr p
  )
{
  return Messaging::RelativeRoundtripTimeoutPolicy::_duplicate (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Objref_Traits<Messaging::RelativeRoundtripTimeoutPolicy>::tao_release (
    Messaging::RelativeRoundtripTimeoutPolicy_ptr p
  )
{
  CORBA::release (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
Messaging::RelativeRoundtripTimeoutPolicy_ptr
TAO::Objref_Traits<Messaging::RelativeRoundtripTimeoutPolicy>::tao_nil (void)
{
  return Messaging::RelativeRoundtripTimeoutPolicy::_nil ();
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::Boolean
TAO::Objref_Traits<Messaging::RelativeRoundtripTimeoutPolicy>::tao_marshal (
    Messaging::RelativeRoundtripTimeoutPolicy_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return p->marshal (cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*Messaging__TAO_RelativeRoundtripTimeoutPolicy_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

Messaging::RelativeRoundtripTimeoutPolicy::RelativeRoundtripTimeoutPolicy (void)
{}

Messaging::RelativeRoundtripTimeoutPolicy::~RelativeRoundtripTimeoutPolicy (void)
{}

void 
Messaging::RelativeRoundtripTimeoutPolicy::_tao_any_destructor (void *_tao_void_pointer)
{
  RelativeRoundtripTimeoutPolicy *_tao_tmp_pointer =
    ACE_static_cast (RelativeRoundtripTimeoutPolicy *, _tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

Messaging::RelativeRoundtripTimeoutPolicy_ptr
Messaging::RelativeRoundtripTimeoutPolicy::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return RelativeRoundtripTimeoutPolicy::_nil ();
    }
  
  RelativeRoundtripTimeoutPolicy_ptr proxy =
    dynamic_cast<RelativeRoundtripTimeoutPolicy_ptr> (_tao_objref);
  
  return RelativeRoundtripTimeoutPolicy::_duplicate (proxy);
}

Messaging::RelativeRoundtripTimeoutPolicy_ptr
Messaging::RelativeRoundtripTimeoutPolicy::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return RelativeRoundtripTimeoutPolicy::_nil ();
    }
  
  RelativeRoundtripTimeoutPolicy_ptr proxy =
    dynamic_cast<RelativeRoundtripTimeoutPolicy_ptr> (_tao_objref);
  
  return RelativeRoundtripTimeoutPolicy::_duplicate (proxy);
}

Messaging::RelativeRoundtripTimeoutPolicy_ptr
Messaging::RelativeRoundtripTimeoutPolicy::_duplicate (RelativeRoundtripTimeoutPolicy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

CORBA::Boolean
Messaging::RelativeRoundtripTimeoutPolicy::_is_a (
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
          "IDL:omg.org/Messaging/RelativeRoundtripTimeoutPolicy:1.0"
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

const char* Messaging::RelativeRoundtripTimeoutPolicy::_interface_repository_id (void) const
{
  return "IDL:omg.org/Messaging/RelativeRoundtripTimeoutPolicy:1.0";
}

CORBA::Boolean
Messaging::RelativeRoundtripTimeoutPolicy::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_Messaging_RelativeRoundtripTimeoutPolicy[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  57,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x4d657373), 
  ACE_NTOHL (0x6167696e), 
  ACE_NTOHL (0x672f5265), 
  ACE_NTOHL (0x6c617469), 
  ACE_NTOHL (0x7665526f), 
  ACE_NTOHL (0x756e6474), 
  ACE_NTOHL (0x72697054), 
  ACE_NTOHL (0x696d656f), 
  ACE_NTOHL (0x7574506f), 
  ACE_NTOHL (0x6c696379), 
  ACE_NTOHL (0x3a312e30), 
  ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/Messaging/RelativeRoundtripTimeoutPolicy:1.0
    31,
  ACE_NTOHL (0x52656c61), 
  ACE_NTOHL (0x74697665), 
  ACE_NTOHL (0x526f756e), 
  ACE_NTOHL (0x64747269), 
  ACE_NTOHL (0x7054696d), 
  ACE_NTOHL (0x656f7574), 
  ACE_NTOHL (0x506f6c69), 
  ACE_NTOHL (0x63790000),  // name = RelativeRoundtripTimeoutPolicy
  };

static CORBA::TypeCode _tc_TAO_tc_Messaging_RelativeRoundtripTimeoutPolicy (
    CORBA::tk_objref,
    sizeof (_oc_Messaging_RelativeRoundtripTimeoutPolicy),
    (char *) &_oc_Messaging_RelativeRoundtripTimeoutPolicy,
    0,
    sizeof (Messaging::RelativeRoundtripTimeoutPolicy)
  );

namespace Messaging
{
  ::CORBA::TypeCode_ptr _tc_RelativeRoundtripTimeoutPolicy =
    &_tc_TAO_tc_Messaging_RelativeRoundtripTimeoutPolicy;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<Messaging::RelativeRoundtripTimeoutPolicy>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<Messaging::RelativeRoundtripTimeoutPolicy>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<Messaging::RelativeRoundtripTimeoutPolicy>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    Messaging::RelativeRoundtripTimeoutPolicy_ptr _tao_elem
  )
{
  Messaging::RelativeRoundtripTimeoutPolicy_ptr _tao_objptr =
    Messaging::RelativeRoundtripTimeoutPolicy::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    Messaging::RelativeRoundtripTimeoutPolicy_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<Messaging::RelativeRoundtripTimeoutPolicy>::insert (
      _tao_any,
      Messaging::RelativeRoundtripTimeoutPolicy::_tao_any_destructor,
      Messaging::_tc_RelativeRoundtripTimeoutPolicy,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    Messaging::RelativeRoundtripTimeoutPolicy_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<Messaging::RelativeRoundtripTimeoutPolicy>::extract (
        _tao_any,
        Messaging::RelativeRoundtripTimeoutPolicy::_tao_any_destructor,
        Messaging::_tc_RelativeRoundtripTimeoutPolicy,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1633

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Objref_Traits<
        Messaging::RelativeRoundtripTimeoutPolicy
      >;

  template class
    TAO_Objref_Var_T<
        Messaging::RelativeRoundtripTimeoutPolicy
      >;
  
  template class
    TAO_Objref_Out_T<
        Messaging::RelativeRoundtripTimeoutPolicy
      >;

  template class
    TAO::Any_Impl_T<
        Messaging::RelativeRoundtripTimeoutPolicy
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Objref_Traits< \
        Messaging::RelativeRoundtripTimeoutPolicy \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        Messaging::RelativeRoundtripTimeoutPolicy
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        Messaging::RelativeRoundtripTimeoutPolicy
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        Messaging::RelativeRoundtripTimeoutPolicy \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 


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

#include "RequestProcessingPolicyC.h"
#include "tao/Null_RefCount_Policy.h"
#include "tao/TypeCode_Constants.h"
#include "tao/Alias_TypeCode.h"
#include "tao/TypeCode_Non_Default_Case.h"
#include "tao/Enum_TypeCode.h"
#include "tao/Objref_TypeCode.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Any_Impl_T.h"
#include "tao/Any_Basic_Impl_T.h"

#if (TAO_HAS_MINIMUM_POA == 0)

// TAO_IDL - Generated from
// be\be_visitor_typecode/enum_typecode.cpp:34

static TAO::TypeCode::Enumerator<char const *> const _tao_enumerators_PortableServer_RequestProcessingPolicyValue[] =
  {
    "USE_ACTIVE_OBJECT_MAP_ONLY",
    "USE_DEFAULT_SERVANT",
    "USE_SERVANT_MANAGER"

  };

static TAO::TypeCode::Enum<char const *,
                           TAO::TypeCode::Enumerator<char const *> const *,
                           TAO::Null_RefCount_Policy>
  _tao_tc_PortableServer_RequestProcessingPolicyValue (
    "IDL:omg.org/PortableServer/RequestProcessingPolicyValue:2.3",
    "RequestProcessingPolicyValue",
    _tao_enumerators_PortableServer_RequestProcessingPolicyValue,
    3);

namespace PortableServer
{
  ::CORBA::TypeCode_ptr const _tc_RequestProcessingPolicyValue =
    &_tao_tc_PortableServer_RequestProcessingPolicyValue;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:73

static TAO::TypeCode::Objref<char const *,
                             CORBA::tk_local_interface,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableServer_RequestProcessingPolicy (
    "IDL:omg.org/PortableServer/RequestProcessingPolicy:2.3",
    "RequestProcessingPolicy");

namespace PortableServer
{
  ::CORBA::TypeCode_ptr const _tc_RequestProcessingPolicy =
    &_tao_tc_PortableServer_RequestProcessingPolicy;
}



// TAO_IDL - Generated from
// be\be_visitor_enum/any_op_cs.cpp:52

void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::RequestProcessingPolicyValue _tao_elem
  )
{
  TAO::Any_Basic_Impl_T<PortableServer::RequestProcessingPolicyValue>::insert (
      _tao_any,
      PortableServer::_tc_RequestProcessingPolicyValue,
      _tao_elem
    );
}

CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::RequestProcessingPolicyValue &_tao_elem
  )
{
  return
    TAO::Any_Basic_Impl_T<PortableServer::RequestProcessingPolicyValue>::extract (
        _tao_any,
        PortableServer::_tc_RequestProcessingPolicyValue,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::RequestProcessingPolicy>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::RequestProcessingPolicy>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::RequestProcessingPolicy>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::RequestProcessingPolicy_ptr _tao_elem
  )
{
  PortableServer::RequestProcessingPolicy_ptr _tao_objptr =
    PortableServer::RequestProcessingPolicy::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::RequestProcessingPolicy_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableServer::RequestProcessingPolicy>::insert (
      _tao_any,
      PortableServer::RequestProcessingPolicy::_tao_any_destructor,
      PortableServer::_tc_RequestProcessingPolicy,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::RequestProcessingPolicy_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableServer::RequestProcessingPolicy>::extract (
        _tao_any,
        PortableServer::RequestProcessingPolicy::_tao_any_destructor,
        PortableServer::_tc_RequestProcessingPolicy,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Basic_Impl_T<
        PortableServer::RequestProcessingPolicyValue
      >;

  template class
    TAO::Any_Impl_T<
        PortableServer::RequestProcessingPolicy
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Basic_Impl_T< \
        PortableServer::RequestProcessingPolicyValue \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        PortableServer::RequestProcessingPolicy \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */

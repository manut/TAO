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

#include "IdAssignmentPolicyC.h"
#include "tao/Null_RefCount_Policy.h"
#include "tao/TypeCode_Constants.h"
#include "tao/Alias_TypeCode.h"
#include "tao/Enum_TypeCode.h"
#include "tao/Objref_TypeCode.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Any_Impl_T.h"
#include "tao/Any_Basic_Impl_T.h"

// TAO_IDL - Generated from
// be/be_visitor_typecode/enum_typecode.cpp:34

static char const * const _tao_enumerators_PortableServer_IdAssignmentPolicyValue[] =
  {
    "USER_ID",
    "SYSTEM_ID"
    
  };

static TAO::TypeCode::Enum<char const *,
                           char const * const *,
                           TAO::Null_RefCount_Policy>
  _tao_tc_PortableServer_IdAssignmentPolicyValue (
    "IDL:omg.org/PortableServer/IdAssignmentPolicyValue:2.3",
    "IdAssignmentPolicyValue",
    _tao_enumerators_PortableServer_IdAssignmentPolicyValue,
    2);
  
namespace PortableServer
{
  ::CORBA::TypeCode_ptr const _tc_IdAssignmentPolicyValue =
    &_tao_tc_PortableServer_IdAssignmentPolicyValue;
}



// TAO_IDL - Generated from
// be/be_visitor_typecode/objref_typecode.cpp:73

static TAO::TypeCode::Objref<char const *,
                             CORBA::tk_local_interface,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableServer_IdAssignmentPolicy (
    "IDL:omg.org/PortableServer/IdAssignmentPolicy:2.3",
    "IdAssignmentPolicy");
  
namespace PortableServer
{
  ::CORBA::TypeCode_ptr const _tc_IdAssignmentPolicy =
    &_tao_tc_PortableServer_IdAssignmentPolicy;
}



// TAO_IDL - Generated from
// be/be_visitor_enum/any_op_cs.cpp:52

void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::IdAssignmentPolicyValue _tao_elem
  )
{
  TAO::Any_Basic_Impl_T<PortableServer::IdAssignmentPolicyValue>::insert (
      _tao_any,
      PortableServer::_tc_IdAssignmentPolicyValue,
      _tao_elem
    );
}

CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::IdAssignmentPolicyValue &_tao_elem
  )
{
  return
    TAO::Any_Basic_Impl_T<PortableServer::IdAssignmentPolicyValue>::extract (
        _tao_any,
        PortableServer::_tc_IdAssignmentPolicyValue,
        _tao_elem 
      );
}

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::IdAssignmentPolicy>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return true;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::IdAssignmentPolicy>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::IdAssignmentPolicy>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::IdAssignmentPolicy_ptr _tao_elem
  )
{
  PortableServer::IdAssignmentPolicy_ptr _tao_objptr =
    PortableServer::IdAssignmentPolicy::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::IdAssignmentPolicy_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableServer::IdAssignmentPolicy>::insert (
      _tao_any,
      PortableServer::IdAssignmentPolicy::_tao_any_destructor,
      PortableServer::_tc_IdAssignmentPolicy,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::IdAssignmentPolicy_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableServer::IdAssignmentPolicy>::extract (
        _tao_any,
        PortableServer::IdAssignmentPolicy::_tao_any_destructor,
        PortableServer::_tc_IdAssignmentPolicy,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Basic_Impl_T<
        PortableServer::IdAssignmentPolicyValue
      >;

  template class
    TAO::Any_Impl_T<
        PortableServer::IdAssignmentPolicy
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Basic_Impl_T< \
        PortableServer::IdAssignmentPolicyValue \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        PortableServer::IdAssignmentPolicy \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

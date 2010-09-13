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

#include "RT_ProtocolPropertiesA.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/Objref_TypeCode_Static.h"
#include "tao/CDR.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/AnyTypeCode/Any_Impl_T.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_RTCORBA_ProtocolProperties (
    ::CORBA::tk_local_interface,
    "IDL:omg.org/RTCORBA/ProtocolProperties:1.0",
    "ProtocolProperties");

namespace RTCORBA
{
  ::CORBA::TypeCode_ptr const _tc_ProtocolProperties =
    &_tao_tc_RTCORBA_ProtocolProperties;
}



// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:51

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  template<>
  ::CORBA::Boolean
  Any_Impl_T<RTCORBA::ProtocolProperties>::to_object (
      ::CORBA::Object_ptr &_tao_elem
    ) const
  {
    _tao_elem = ::CORBA::Object::_duplicate (this->value_);
    return true;
  }
}

namespace TAO
{
  template<>
  ::CORBA::Boolean
  Any_Impl_T<RTCORBA::ProtocolProperties>::marshal_value (TAO_OutputCDR &)
  {
    return false;
  }

  template<>
  ::CORBA::Boolean
  Any_Impl_T<RTCORBA::ProtocolProperties>::demarshal_value (TAO_InputCDR &)
  {
    return false;
  }
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace RTCORBA
{


  /// Copying insertion.
  void
  operator<<= (
      ::CORBA::Any &_tao_any,
      ProtocolProperties_ptr _tao_elem)
  {
    ProtocolProperties_ptr _tao_objptr =
      ProtocolProperties::_duplicate (_tao_elem);
    _tao_any <<= &_tao_objptr;
  }

  /// Non-copying insertion.
  void
  operator<<= (
      ::CORBA::Any &_tao_any,
      ProtocolProperties_ptr *_tao_elem)
  {
    TAO::Any_Impl_T<ProtocolProperties>::insert (
        _tao_any,
        ProtocolProperties::_tao_any_destructor,
        _tc_ProtocolProperties,
        *_tao_elem);
  }

  ::CORBA::Boolean
  operator>>= (
      const ::CORBA::Any &_tao_any,
      ProtocolProperties_ptr &_tao_elem)
  {
    return
      TAO::Any_Impl_T<ProtocolProperties>::extract (
          _tao_any,
          ProtocolProperties::_tao_any_destructor,
          _tc_ProtocolProperties,
          _tao_elem);
  }
}

#else


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



/// Copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    RTCORBA::ProtocolProperties_ptr _tao_elem)
{
  RTCORBA::ProtocolProperties_ptr _tao_objptr =
    RTCORBA::ProtocolProperties::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

/// Non-copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    RTCORBA::ProtocolProperties_ptr *_tao_elem)
{
  TAO::Any_Impl_T<RTCORBA::ProtocolProperties>::insert (
      _tao_any,
      RTCORBA::ProtocolProperties::_tao_any_destructor,
      RTCORBA::_tc_ProtocolProperties,
      *_tao_elem);
}

::CORBA::Boolean
operator>>= (
    const ::CORBA::Any &_tao_any,
    RTCORBA::ProtocolProperties_ptr &_tao_elem)
{
  return
    TAO::Any_Impl_T<RTCORBA::ProtocolProperties>::extract (
        _tao_any,
        RTCORBA::ProtocolProperties::_tao_any_destructor,
        RTCORBA::_tc_ProtocolProperties,
        _tao_elem);
}

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

TAO_END_VERSIONED_NAMESPACE_DECL



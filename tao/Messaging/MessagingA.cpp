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

#include "Messaging.h"
#include "tao/Null_RefCount_Policy.h"
#include "tao/TypeCode_Constants.h"
#include "tao/Alias_TypeCode.h"
#include "tao/Objref_TypeCode.h"
#include "tao/Value_TypeCode.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Any_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/value_typecode.cpp:32

static TAO::TypeCode::Value_Field<char const *> _tao_fields_Messaging_ExceptionHolder[] =
  {
    { "is_system_exception", &CORBA::_tc_boolean, CORBA::PUBLIC_MEMBER },
    { "byte_order", &CORBA::_tc_boolean, CORBA::PUBLIC_MEMBER },
    { "marshaled_exception", &CORBA::_tc_OctetSeq, CORBA::PUBLIC_MEMBER }

  };

static TAO::TypeCode::Value<char const *,
                            TAO::TypeCode::Value_Field<char const *> const *,
                            CORBA::tk_value,
                            TAO::Null_RefCount_Policy> const
  _tao_tc_Messaging_ExceptionHolder (
    "IDL:omg.org/Messaging/ExceptionHolder:1.0",
    "ExceptionHolder",
    CORBA::VM_NONE,
    &CORBA::tk_null,
    _tao_fields_Messaging_ExceptionHolder,
    3);

namespace Messaging
{
  ::CORBA::TypeCode_ptr const _tc_ExceptionHolder =
    &_tao_tc_Messaging_ExceptionHolder;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:73

static TAO::TypeCode::Objref<char const *,
                             CORBA::tk_objref,
                             TAO::Null_RefCount_Policy>
  _tao_tc_Messaging_ReplyHandler (
    "IDL:omg.org/Messaging/ReplyHandler:1.0",
    "ReplyHandler");

namespace Messaging
{
  ::CORBA::TypeCode_ptr const _tc_ReplyHandler =
    &_tao_tc_Messaging_ReplyHandler;
}



// TAO_IDL - Generated from
// be\be_visitor_valuetype/any_op_cs.cpp:57

template<>
CORBA::Boolean
TAO::Any_Impl_T<Messaging::ExceptionHolder>::to_value (
    CORBA::ValueBase *&_tao_elem
  ) const
{
  CORBA::add_ref (this->value_);
  _tao_elem = this->value_;
  return 1;
}
// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    Messaging::ExceptionHolder *_tao_elem
  )
{
  CORBA::add_ref (_tao_elem);
  _tao_any <<= &_tao_elem;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    Messaging::ExceptionHolder **_tao_elem
  )
{
  TAO::Any_Impl_T<Messaging::ExceptionHolder>::insert (
      _tao_any,
      Messaging::ExceptionHolder::_tao_any_destructor,
      Messaging::_tc_ExceptionHolder,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    Messaging::ExceptionHolder *&_tao_elem
  )
{
  return
    TAO::Any_Impl_T<Messaging::ExceptionHolder>::extract (
        _tao_any,
        Messaging::ExceptionHolder::_tao_any_destructor,
        Messaging::_tc_ExceptionHolder,
        _tao_elem
      );
}



// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Impl_T<Messaging::ReplyHandler>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    Messaging::ReplyHandler_ptr _tao_elem
  )
{
  Messaging::ReplyHandler_ptr _tao_objptr =
    Messaging::ReplyHandler::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    Messaging::ReplyHandler_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<Messaging::ReplyHandler>::insert (
      _tao_any,
      Messaging::ReplyHandler::_tao_any_destructor,
      Messaging::_tc_ReplyHandler,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    Messaging::ReplyHandler_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<Messaging::ReplyHandler>::extract (
        _tao_any,
        Messaging::ReplyHandler::_tao_any_destructor,
        Messaging::_tc_ReplyHandler,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Impl_T<
        Messaging::ExceptionHolder
      >;

  template class
    TAO::Any_Impl_T<
        Messaging::ReplyHandler
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Impl_T< \
        Messaging::ExceptionHolder \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        Messaging::ReplyHandler \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

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

#include "POAManagerC.h"
#include "tao/Null_RefCount_Policy.h"
#include "tao/TypeCode_Constants.h"
#include "tao/Alias_TypeCode.h"
#include "tao/TypeCode_Enumerator.h"
#include "tao/Enum_TypeCode.h"
#include "tao/Objref_TypeCode.h"
#include "tao/Struct_TypeCode.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Any_Impl_T.h"
#include "tao/Any_Dual_Impl_T.h"
#include "tao/Any_Basic_Impl_T.h"

// TAO_IDL - Generated from
// be/be_visitor_typecode/struct_typecode.cpp:34

static TAO::TypeCode::Struct_Field<char const *>  * const _tao_fields_PortableServer_POAManager_AdapterInactive = 0;
static TAO::TypeCode::Struct<char const *,
                             TAO::TypeCode::Struct_Field<char const *> const *,
                             CORBA::tk_except,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableServer_POAManager_AdapterInactive (
    "IDL:omg.org/PortableServer/POAManager/AdapterInactive:2.3",
    "AdapterInactive",
    _tao_fields_PortableServer_POAManager_AdapterInactive,
    0);

::CORBA::TypeCode_ptr const PortableServer::POAManager::_tc_AdapterInactive =
  &_tao_tc_PortableServer_POAManager_AdapterInactive;

// TAO_IDL - Generated from
// be/be_visitor_typecode/enum_typecode.cpp:34

static TAO::TypeCode::Enumerator<char const *> const _tao_enumerators_PortableServer_POAManager_State[] =
  {
    { "HOLDING" },
    { "ACTIVE" },
    { "DISCARDING" },
    { "INACTIVE" }

  };

static TAO::TypeCode::Enum<char const *,
                           TAO::TypeCode::Enumerator<char const *> const *,
                           TAO::Null_RefCount_Policy>
  _tao_tc_PortableServer_POAManager_State (
    "IDL:omg.org/PortableServer/POAManager/State:2.3",
    "State",
    _tao_enumerators_PortableServer_POAManager_State,
    4);

::CORBA::TypeCode_ptr const PortableServer::POAManager::_tc_State =
  &_tao_tc_PortableServer_POAManager_State;

// TAO_IDL - Generated from
// be/be_visitor_typecode/objref_typecode.cpp:73

static TAO::TypeCode::Objref<char const *,
                             CORBA::tk_local_interface,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableServer_POAManager (
    "IDL:omg.org/PortableServer/POAManager:2.3",
    "POAManager");

namespace PortableServer
{
  ::CORBA::TypeCode_ptr const _tc_POAManager =
    &_tao_tc_PortableServer_POAManager;
}



// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::POAManager>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::POAManager>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::POAManager>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POAManager_ptr _tao_elem
  )
{
  PortableServer::POAManager_ptr _tao_objptr =
    PortableServer::POAManager::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POAManager_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableServer::POAManager>::insert (
      _tao_any,
      PortableServer::POAManager::_tao_any_destructor,
      PortableServer::_tc_POAManager,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::POAManager_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableServer::POAManager>::extract (
        _tao_any,
        PortableServer::POAManager::_tao_any_destructor,
        PortableServer::_tc_POAManager,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be/be_visitor_exception/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POAManager::AdapterInactive>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POAManager::AdapterInactive>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableServer::POAManager::AdapterInactive &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POAManager::AdapterInactive>::insert_copy (
      _tao_any,
      PortableServer::POAManager::AdapterInactive::_tao_any_destructor,
      PortableServer::POAManager::_tc_AdapterInactive,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POAManager::AdapterInactive *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POAManager::AdapterInactive>::insert (
      _tao_any,
      PortableServer::POAManager::AdapterInactive::_tao_any_destructor,
      PortableServer::POAManager::_tc_AdapterInactive,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::POAManager::AdapterInactive *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableServer::POAManager::AdapterInactive *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableServer::POAManager::AdapterInactive *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableServer::POAManager::AdapterInactive>::extract (
        _tao_any,
        PortableServer::POAManager::AdapterInactive::_tao_any_destructor,
        PortableServer::POAManager::_tc_AdapterInactive,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be/be_visitor_enum/any_op_cs.cpp:52



template<>
CORBA::Boolean
TAO::Any_Basic_Impl_T<PortableServer::POAManager::State>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Basic_Impl_T<PortableServer::POAManager::State>::demarshal_value (TAO_InputCDR &)
{
  return false;
}void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POAManager::State _tao_elem
  )
{
  TAO::Any_Basic_Impl_T<PortableServer::POAManager::State>::insert (
      _tao_any,
      PortableServer::POAManager::_tc_State,
      _tao_elem
    );
}

CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::POAManager::State &_tao_elem
  )
{
  return
    TAO::Any_Basic_Impl_T<PortableServer::POAManager::State>::extract (
        _tao_any,
        PortableServer::POAManager::_tc_State,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Dual_Impl_T<
        PortableServer::POAManager::AdapterInactive
      >;

  template class
    TAO::Any_Basic_Impl_T<
        PortableServer::POAManager::State
      >;

  template class
    TAO::Any_Impl_T<
        PortableServer::POAManager
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        PortableServer::POAManager::AdapterInactive \
      >

# pragma instantiate \
    TAO::Any_Basic_Impl_T< \
        PortableServer::POAManager::State \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        PortableServer::POAManager \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

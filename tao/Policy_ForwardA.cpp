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

#include "Policy_ForwardC.h"
#include "tao/Null_RefCount_Policy.h"
#include "tao/TypeCode_Constants.h"
#include "tao/Alias_TypeCode.h"
#include "tao/TypeCode_Non_Default_Case.h"
#include "tao/Enum_TypeCode.h"
#include "tao/Sequence_TypeCode.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Any_Dual_Impl_T.h"
#include "tao/Any_Basic_Impl_T.h"

// TAO_IDL - Generated from
// be/be_visitor_typecode/alias_typecode.cpp:31

static TAO::TypeCode::Alias<char const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_PolicyType (
    "IDL:omg.org/CORBA/PolicyType:1.0",
    "PolicyType",
    &CORBA::_tc_ulong);
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_PolicyType =
    &_tao_tc_CORBA_PolicyType;
}



// TAO_IDL - Generated from
// be/be_visitor_typecode/alias_typecode.cpp:31



// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:743

namespace TAO
{
  namespace TypeCode
  {
    TAO::TypeCode::Sequence<TAO::Null_RefCount_Policy>
      CORBA_PolicyList_0 (
        CORBA::tk_sequence,
        &CORBA::_tc_Policy,
        0U);
      
    ::CORBA::TypeCode_ptr const tc_CORBA_PolicyList_0 =
      &CORBA_PolicyList_0;
    
  }
}

static TAO::TypeCode::Alias<char const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_PolicyList (
    "IDL:omg.org/CORBA/PolicyList:1.0",
    "PolicyList",
    &TAO::TypeCode::tc_CORBA_PolicyList_0);
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_PolicyList =
    &_tao_tc_CORBA_PolicyList;
}



// TAO_IDL - Generated from
// be/be_visitor_typecode/alias_typecode.cpp:31



// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:743



// TAO_IDL - Generated from
// be/be_visitor_typecode/alias_typecode.cpp:31

static TAO::TypeCode::Alias<char const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_PolicyType (
    "IDL:omg.org/CORBA/PolicyType:1.0",
    "PolicyType",
    &CORBA::_tc_ulong);
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_PolicyType =
    &_tao_tc_CORBA_PolicyType;
}

namespace TAO
{
  namespace TypeCode
  {
    TAO::TypeCode::Sequence<TAO::Null_RefCount_Policy>
      CORBA_PolicyTypeSeq_0 (
        CORBA::tk_sequence,
        &CORBA::_tc_PolicyType,
        0U);
      
    ::CORBA::TypeCode_ptr const tc_CORBA_PolicyTypeSeq_0 =
      &CORBA_PolicyTypeSeq_0;
    
  }
}

static TAO::TypeCode::Alias<char const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_PolicyTypeSeq (
    "IDL:omg.org/CORBA/PolicyTypeSeq:1.0",
    "PolicyTypeSeq",
    &TAO::TypeCode::tc_CORBA_PolicyTypeSeq_0);
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_PolicyTypeSeq =
    &_tao_tc_CORBA_PolicyTypeSeq;
}



// TAO_IDL - Generated from
// be/be_visitor_typecode/enum_typecode.cpp:34

static TAO::TypeCode::Enumerator<char const *> const _tao_enumerators_CORBA_SetOverrideType[] =
  {
    "SET_OVERRIDE",
    "ADD_OVERRIDE"
    
  };

static TAO::TypeCode::Enum<char const *,
                           TAO::TypeCode::Enumerator<char const *> const *,
                           TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_SetOverrideType (
    "IDL:omg.org/CORBA/SetOverrideType:1.0",
    "SetOverrideType",
    _tao_enumerators_CORBA_SetOverrideType,
    2);
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_SetOverrideType =
    &_tao_tc_CORBA_SetOverrideType;
}



// TAO_IDL - Generated from 
// be/be_visitor_sequence/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::PolicyList &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::PolicyList>::insert_copy (
      _tao_any,
      CORBA::PolicyList::_tao_any_destructor,
      TAO::TypeCode::tc_CORBA_PolicyList_0,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::PolicyList *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::PolicyList>::insert (
      _tao_any,
      CORBA::PolicyList::_tao_any_destructor,
      TAO::TypeCode::tc_CORBA_PolicyList_0,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::PolicyList *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const CORBA::PolicyList *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::PolicyList *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::PolicyList>::extract (
        _tao_any,
        CORBA::PolicyList::_tao_any_destructor,
        TAO::TypeCode::tc_CORBA_PolicyList_0,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be/be_visitor_sequence/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::PolicyTypeSeq &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::PolicyTypeSeq>::insert_copy (
      _tao_any,
      CORBA::PolicyTypeSeq::_tao_any_destructor,
      TAO::TypeCode::tc_CORBA_PolicyTypeSeq_0,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::PolicyTypeSeq *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::PolicyTypeSeq>::insert (
      _tao_any,
      CORBA::PolicyTypeSeq::_tao_any_destructor,
      TAO::TypeCode::tc_CORBA_PolicyTypeSeq_0,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::PolicyTypeSeq *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const CORBA::PolicyTypeSeq *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::PolicyTypeSeq *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::PolicyTypeSeq>::extract (
        _tao_any,
        CORBA::PolicyTypeSeq::_tao_any_destructor,
        TAO::TypeCode::tc_CORBA_PolicyTypeSeq_0,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be/be_visitor_enum/any_op_cs.cpp:52

void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::SetOverrideType _tao_elem
  )
{
  TAO::Any_Basic_Impl_T<CORBA::SetOverrideType>::insert (
      _tao_any,
      CORBA::_tc_SetOverrideType,
      _tao_elem
    );
}

CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::SetOverrideType &_tao_elem
  )
{
  return
    TAO::Any_Basic_Impl_T<CORBA::SetOverrideType>::extract (
        _tao_any,
        CORBA::_tc_SetOverrideType,
        _tao_elem 
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Dual_Impl_T<
        CORBA::PolicyList
      >;

  template class
    TAO::Any_Dual_Impl_T<
        CORBA::PolicyTypeSeq
      >;

  template class
    TAO::Any_Basic_Impl_T<
        CORBA::SetOverrideType
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        CORBA::PolicyList \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        CORBA::PolicyTypeSeq \
      >

# pragma instantiate \
    TAO::Any_Basic_Impl_T< \
        CORBA::SetOverrideType \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

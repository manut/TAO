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

#include "Messaging_PolicyValueC.h"
#include "tao/Typecode.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const Messaging::PolicyValue &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<Messaging::PolicyValue>::insert_copy (
      _tao_any,
      Messaging::PolicyValue::_tao_any_destructor,
      Messaging::_tc_PolicyValue,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    Messaging::PolicyValue *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<Messaging::PolicyValue>::insert (
      _tao_any,
      Messaging::PolicyValue::_tao_any_destructor,
      Messaging::_tc_PolicyValue,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    Messaging::PolicyValue *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast (
      const Messaging::PolicyValue *&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const Messaging::PolicyValue *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<Messaging::PolicyValue>::extract (
        _tao_any,
        Messaging::PolicyValue::_tao_any_destructor,
        Messaging::_tc_PolicyValue,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_sequence/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const Messaging::PolicyValueSeq &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<Messaging::PolicyValueSeq>::insert_copy (
      _tao_any,
      Messaging::PolicyValueSeq::_tao_any_destructor,
      Messaging::_tc_PolicyValueSeq,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    Messaging::PolicyValueSeq *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<Messaging::PolicyValueSeq>::insert (
      _tao_any,
      Messaging::PolicyValueSeq::_tao_any_destructor,
      Messaging::_tc_PolicyValueSeq,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    Messaging::PolicyValueSeq *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast (
      const Messaging::PolicyValueSeq *&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const Messaging::PolicyValueSeq *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<Messaging::PolicyValueSeq>::extract (
        _tao_any,
        Messaging::PolicyValueSeq::_tao_any_destructor,
        Messaging::_tc_PolicyValueSeq,
        _tao_elem
      );
}



#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Dual_Impl_T<
        Messaging::PolicyValue
      >;

  template class
    TAO::Any_Dual_Impl_T<
        Messaging::PolicyValueSeq
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        Messaging::PolicyValue \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        Messaging::PolicyValueSeq \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */


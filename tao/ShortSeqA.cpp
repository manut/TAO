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

#include "ShortSeqC.h"
#include "tao/Typecode.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from 
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::ShortSeq &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ShortSeq>::insert_copy (
      _tao_any,
      CORBA::ShortSeq::_tao_any_destructor,
      CORBA::_tc_ShortSeq,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ShortSeq *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ShortSeq>::insert (
      _tao_any,
      CORBA::ShortSeq::_tao_any_destructor,
      CORBA::_tc_ShortSeq,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::ShortSeq *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast (
      const CORBA::ShortSeq *&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::ShortSeq *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::ShortSeq>::extract (
        _tao_any,
        CORBA::ShortSeq::_tao_any_destructor,
        CORBA::_tc_ShortSeq,
        _tao_elem
      );
}



#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Dual_Impl_T<
        CORBA::ShortSeq
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        CORBA::ShortSeq \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 


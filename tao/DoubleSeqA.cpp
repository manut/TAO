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

#include "DoubleSeqC.h"
#include "tao/Typecode.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_CORBA_DoubleSeq[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  32,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f446f), 
  ACE_NTOHL (0x75626c65), 
  ACE_NTOHL (0x5365713a), 
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/DoubleSeq:1.0
    10,
  ACE_NTOHL (0x446f7562), 
  ACE_NTOHL (0x6c655365), 
  ACE_NTOHL (0x71000000),  // name = DoubleSeq
    CORBA::tk_sequence, // typecode kind
  12, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_double,

    0U,

};

static CORBA::TypeCode _tc_TAO_tc_CORBA_DoubleSeq (
    CORBA::tk_alias,
    sizeof (_oc_CORBA_DoubleSeq),
    (char *) &_oc_CORBA_DoubleSeq,
    0,
    sizeof (CORBA::DoubleSeq)
  );

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_DoubleSeq =
    &_tc_TAO_tc_CORBA_DoubleSeq;
}

// TAO_IDL - Generated from 
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::DoubleSeq &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::DoubleSeq>::insert_copy (
      _tao_any,
      CORBA::DoubleSeq::_tao_any_destructor,
      CORBA::_tc_DoubleSeq,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::DoubleSeq *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::DoubleSeq>::insert (
      _tao_any,
      CORBA::DoubleSeq::_tao_any_destructor,
      CORBA::_tc_DoubleSeq,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::DoubleSeq *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const CORBA::DoubleSeq *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::DoubleSeq *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::DoubleSeq>::extract (
        _tao_any,
        CORBA::DoubleSeq::_tao_any_destructor,
        CORBA::_tc_DoubleSeq,
        _tao_elem
      );
}



#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Dual_Impl_T<
        CORBA::DoubleSeq
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        CORBA::DoubleSeq \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */


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
// be\be_codegen.cpp:291


#include "CONV_FRAMEC.h"
#include "tao/CDR.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:70

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from 
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_CONV_FRAME_CODESETIDSEQ_CS_)
#define _CONV_FRAME_CODESETIDSEQ_CS_

CONV_FRAME::CodeSetIdSeq::CodeSetIdSeq (void)
{}

CONV_FRAME::CodeSetIdSeq::CodeSetIdSeq (
    CORBA::ULong max
  )
  : TAO_Unbounded_Sequence<
        CONV_FRAME::CodeSetId
      >
    (max)
{}

CONV_FRAME::CodeSetIdSeq::CodeSetIdSeq (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA::ULong * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        CONV_FRAME::CodeSetId
      >
    (max, length, buffer, release)
{}

CONV_FRAME::CodeSetIdSeq::CodeSetIdSeq (
    const CodeSetIdSeq &seq
  )
  : TAO_Unbounded_Sequence<
        CONV_FRAME::CodeSetId
      >
    (seq)
{}

CONV_FRAME::CodeSetIdSeq::~CodeSetIdSeq (void)
{}

void CONV_FRAME::CodeSetIdSeq::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  CodeSetIdSeq * _tao_tmp_pointer =
    static_cast<CodeSetIdSeq *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from 
// be\be_visitor_structure/structure_cs.cpp:66

void 
CONV_FRAME::CodeSetComponent::_tao_any_destructor (
    void *_tao_void_pointer
  )
{
  CodeSetComponent *_tao_tmp_pointer =
    static_cast<CodeSetComponent *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from 
// be\be_visitor_structure/structure_cs.cpp:66

void 
CONV_FRAME::CodeSetComponentInfo::_tao_any_destructor (
    void *_tao_void_pointer
  )
{
  CodeSetComponentInfo *_tao_tmp_pointer =
    static_cast<CodeSetComponentInfo *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from 
// be\be_visitor_structure/structure_cs.cpp:66

void 
CONV_FRAME::CodeSetContext::_tao_any_destructor (
    void *_tao_void_pointer
  )
{
  CodeSetContext *_tao_tmp_pointer =
    static_cast<CodeSetContext *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_CONV_FRAME_CodeSetIdSeq_CPP_
#define _TAO_CDR_OP_CONV_FRAME_CodeSetIdSeq_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CONV_FRAME::CodeSetIdSeq &_tao_sequence
  )
{
  const CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      return strm.write_ulong_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
    }
  
  return false;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CONV_FRAME::CodeSetIdSeq &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len;
  
  if (strm >> _tao_seq_len)
    {
      // Add a check to the length of the sequence
      // to make sure it does not exceed the length
      // of the stream. (See bug 58.)
      if (_tao_seq_len > strm.length ())
        {
          return false;
        }
      
      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);
      
      // If length is 0 we return true.
      if (0 >= _tao_seq_len) 
        {
          return true;
        }
      
      // Retrieve all the elements.
      return strm.read_ulong_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
    
    }
  
  return false;
}

#endif /* _TAO_CDR_OP_CONV_FRAME_CodeSetIdSeq_CPP_ */

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_cs.cpp:61

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CONV_FRAME::CodeSetComponent &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.native_code_set) &&
    (strm << _tao_aggregate.conversion_code_sets);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CONV_FRAME::CodeSetComponent &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.native_code_set) &&
    (strm >> _tao_aggregate.conversion_code_sets);
}

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_cs.cpp:61

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CONV_FRAME::CodeSetComponentInfo &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.ForCharData) &&
    (strm << _tao_aggregate.ForWcharData);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CONV_FRAME::CodeSetComponentInfo &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.ForCharData) &&
    (strm >> _tao_aggregate.ForWcharData);
}

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_cs.cpp:61

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CONV_FRAME::CodeSetContext &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.char_data) &&
    (strm << _tao_aggregate.wchar_data);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CONV_FRAME::CodeSetContext &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.char_data) &&
    (strm >> _tao_aggregate.wchar_data);
}

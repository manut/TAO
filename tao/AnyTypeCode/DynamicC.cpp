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


#include "DynamicC.h"
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

#if !defined (_DYNAMIC_PARAMETERLIST_CS_)
#define _DYNAMIC_PARAMETERLIST_CS_

Dynamic::ParameterList::ParameterList (void)
{}

Dynamic::ParameterList::ParameterList (
    CORBA::ULong max
  )
  : TAO_Unbounded_Sequence<
        Dynamic::Parameter
      >
    (max)
{}

Dynamic::ParameterList::ParameterList (
    CORBA::ULong max,
    CORBA::ULong length,
    Dynamic::Parameter * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        Dynamic::Parameter
      >
    (max, length, buffer, release)
{}

Dynamic::ParameterList::ParameterList (
    const ParameterList &seq
  )
  : TAO_Unbounded_Sequence<
        Dynamic::Parameter
      >
    (seq)
{}

Dynamic::ParameterList::~ParameterList (void)
{}

void Dynamic::ParameterList::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  ParameterList * _tao_tmp_pointer =
    static_cast<ParameterList *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */


// TAO_IDL - Generated from
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_DYNAMIC_EXCEPTIONLIST_CS_)
#define _DYNAMIC_EXCEPTIONLIST_CS_

Dynamic::ExceptionList::ExceptionList (void)
{}

Dynamic::ExceptionList::ExceptionList (
    CORBA::ULong max
  )
  : TAO_Unbounded_Object_Sequence<
        CORBA::TypeCode,
        CORBA::TypeCode_var
      >
    (max)
{}

Dynamic::ExceptionList::ExceptionList (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA::TypeCode_ptr * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Object_Sequence<
        CORBA::TypeCode,
        CORBA::TypeCode_var
      >
    (max, length, buffer, release)
{}

Dynamic::ExceptionList::ExceptionList (
    const ExceptionList &seq
  )
  : TAO_Unbounded_Object_Sequence<
        CORBA::TypeCode,
        CORBA::TypeCode_var
      >
    (seq)
{}

Dynamic::ExceptionList::~ExceptionList (void)
{}

void Dynamic::ExceptionList::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  ExceptionList * _tao_tmp_pointer =
    static_cast<ExceptionList *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_Dynamic_ParameterList_CPP_
#define _TAO_CDR_OP_Dynamic_ParameterList_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Dynamic::ParameterList &_tao_sequence
  )
{
  const CORBA::ULong _tao_seq_len = _tao_sequence.length ();

  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      CORBA::Boolean _tao_marshal_flag = true;

      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm << _tao_sequence[i]);
        }

      return _tao_marshal_flag;
    }

  return false;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    Dynamic::ParameterList &_tao_sequence
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
      CORBA::Boolean _tao_marshal_flag = true;

      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm >> _tao_sequence[i]);
        }

      return _tao_marshal_flag;

    }

  return false;
}

#endif /* _TAO_CDR_OP_Dynamic_ParameterList_CPP_ */


// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_Dynamic_ExceptionList_CPP_
#define _TAO_CDR_OP_Dynamic_ExceptionList_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Dynamic::ExceptionList &_tao_sequence
  )
{
  const CORBA::ULong _tao_seq_len = _tao_sequence.length ();

  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      CORBA::Boolean _tao_marshal_flag = true;

      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag =
            TAO::Objref_Traits<CORBA::TypeCode>::marshal (
                _tao_sequence[i].in (), strm
              );
        }

      return _tao_marshal_flag;
    }

  return false;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    Dynamic::ExceptionList &_tao_sequence
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
      CORBA::Boolean _tao_marshal_flag = true;

      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm >> _tao_sequence[i].out ());
        }

      return _tao_marshal_flag;

    }

  return false;
}

#endif /* _TAO_CDR_OP_Dynamic_ExceptionList_CPP_ */

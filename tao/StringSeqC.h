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
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:151

#ifndef _TAO_IDL_ORIG_STRINGSEQC_H_
#define _TAO_IDL_ORIG_STRINGSEQC_H_

#include /**/ "ace/pre.h"

#include "Sequence.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_Export
#endif /* TAO_EXPORT_NESTED_CLASSES */

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_ch.cpp:48

namespace CORBA
{
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_CORBA_STRINGSEQ_CH_)
#define _CORBA_STRINGSEQ_CH_
  
  class StringSeq;
  
  typedef
    TAO_MngSeq_Var_T<
        StringSeq,
        TAO_SeqElem_String_Manager
      >
    StringSeq_var;
  
  typedef
    TAO_MngSeq_Out_T<
        StringSeq,
        StringSeq_var,
        TAO_SeqElem_String_Manager
      >
    StringSeq_out;
  
  class TAO_Export StringSeq
    : public
        TAO_Unbounded_String_Sequence
  {
  public:
    StringSeq (void);
    StringSeq (CORBA::ULong max);
    StringSeq (
        CORBA::ULong max,
        CORBA::ULong length,
        char ** buffer, 
        CORBA::Boolean release = 0
      );
    StringSeq (const StringSeq &);
    ~StringSeq (void);
    
    static void _tao_any_destructor (void *);
    
    typedef StringSeq_var _var_type;
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_StringSeq;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_CORBA_WSTRINGSEQ_CH_)
#define _CORBA_WSTRINGSEQ_CH_
  
  class WStringSeq;
  
  typedef
    TAO_MngSeq_Var_T<
        WStringSeq,
        TAO_SeqElem_WString_Manager
      >
    WStringSeq_var;
  
  typedef
    TAO_MngSeq_Out_T<
        WStringSeq,
        WStringSeq_var,
        TAO_SeqElem_WString_Manager
      >
    WStringSeq_out;
  
  class TAO_Export WStringSeq
    : public
        TAO_Unbounded_WString_Sequence
  {
  public:
    WStringSeq (void);
    WStringSeq (CORBA::ULong max);
    WStringSeq (
        CORBA::ULong max,
        CORBA::ULong length,
        CORBA::WChar ** buffer, 
        CORBA::Boolean release = 0
      );
    WStringSeq (const WStringSeq &);
    ~WStringSeq (void);
    
    static void _tao_any_destructor (void *);
    
    typedef WStringSeq_var _var_type;
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_WStringSeq;

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_ch.cpp:66

} // module CORBA

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_traits.cpp:48

// Traits specializations.
namespace TAO
{
};

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const CORBA::StringSeq &); // copying version
TAO_Export void operator<<= (CORBA::Any &, CORBA::StringSeq*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA::StringSeq *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const CORBA::StringSeq *&);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const CORBA::WStringSeq &); // copying version
TAO_Export void operator<<= (CORBA::Any &, CORBA::WStringSeq*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA::WStringSeq *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const CORBA::WStringSeq *&);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ch.cpp:70

#if !defined _TAO_CDR_OP_CORBA_StringSeq_H_
#define _TAO_CDR_OP_CORBA_StringSeq_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::StringSeq &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::StringSeq &
  );

#endif /* _TAO_CDR_OP_CORBA_StringSeq_H_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ch.cpp:70

#if !defined _TAO_CDR_OP_CORBA_WStringSeq_H_
#define _TAO_CDR_OP_CORBA_WStringSeq_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::WStringSeq &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::WStringSeq &
  );

#endif /* _TAO_CDR_OP_CORBA_WStringSeq_H_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:969

#if defined (__ACE_INLINE__)
#include "StringSeqC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"
#endif /* ifndef */


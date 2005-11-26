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
// be\be_codegen.cpp:153

#ifndef _TAO_IDL_ORIG_PI_FORWARDA_H_
#define _TAO_IDL_ORIG_PI_FORWARDA_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/AnyTypeCode/TAO_AnyTypeCode_Export.h"
#include "tao/AnyTypeCode/AnyTypeCode_methods.h"
#include "tao/ORB.h"
#include "tao/Environment.h"

#include "tao/OctetSeqC.h"
#include "tao/StringSeqC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_AnyTypeCode_Export

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:48

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace PortableInterceptor
{

  // TAO_IDL - Generated from
  // be\be_visitor_typedef/typedef_ch.cpp:413

  typedef char * ServerId;
  typedef CORBA::String_var ServerId_var;
  typedef CORBA::String_out ServerId_out;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_ServerId;

  // TAO_IDL - Generated from
  // be\be_visitor_typedef/typedef_ch.cpp:413

  typedef char * ORBId;
  typedef CORBA::String_var ORBId_var;
  typedef CORBA::String_out ORBId_out;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_ORBId;

  // TAO_IDL - Generated from
  // be\be_visitor_typedef/typedef_ch.cpp:472

  typedef CORBA::StringSeq AdapterName;
  typedef CORBA::StringSeq_var AdapterName_var;
  typedef CORBA::StringSeq_out AdapterName_out;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_AdapterName;

  // TAO_IDL - Generated from
  // be\be_visitor_typedef/typedef_ch.cpp:472

  typedef CORBA::OctetSeq ObjectId;
  typedef CORBA::OctetSeq_var ObjectId_var;
  typedef CORBA::OctetSeq_out ObjectId_out;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_ObjectId;

  // TAO_IDL - Generated from
  // be\be_visitor_typedef/typedef_ch.cpp:379

  typedef CORBA::Long AdapterManagerId;
  typedef CORBA::Long_out AdapterManagerId_out;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_AdapterManagerId;

  // TAO_IDL - Generated from
  // be\be_visitor_typedef/typedef_ch.cpp:379

  typedef CORBA::Short AdapterState;
  typedef CORBA::Short_out AdapterState_out;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_AdapterState;

  // TAO_IDL - Generated from
  // be\be_visitor_typedef/typedef_ch.cpp:379

  typedef CORBA::ULong SlotId;
  typedef CORBA::ULong_out SlotId_out;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_SlotId;

  // TAO_IDL - Generated from
  // be\be_visitor_typedef/typedef_ch.cpp:379

  typedef CORBA::Short ReplyStatus;
  typedef CORBA::Short_out ReplyStatus_out;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_ReplyStatus;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module PortableInterceptor

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:61

// Traits specializations.
namespace TAO
{
}

// TAO_IDL - Generated from
// be\be_codegen.cpp:955

TAO_END_VERSIONED_NAMESPACE_DECL

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */



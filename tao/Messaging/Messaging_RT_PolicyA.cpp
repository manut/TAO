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

#include "Messaging_RT_PolicyA.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/Objref_TypeCode_Static.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/CDR.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/AnyTypeCode/Any_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_Messaging_Timeout (
    ::CORBA::tk_alias,
    "IDL:omg.org/Messaging/Timeout:1.0",
    "Timeout",
    &TimeBase::_tc_TimeT);
  
namespace Messaging
{
  ::CORBA::TypeCode_ptr const _tc_Timeout =
    &_tao_tc_Messaging_Timeout;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_Messaging_RelativeRoundtripTimeoutPolicy (
    ::CORBA::tk_local_interface,
    "IDL:omg.org/Messaging/RelativeRoundtripTimeoutPolicy:1.0",
    "RelativeRoundtripTimeoutPolicy");
  
namespace Messaging
{
  ::CORBA::TypeCode_ptr const _tc_RelativeRoundtripTimeoutPolicy =
    &_tao_tc_Messaging_RelativeRoundtripTimeoutPolicy;
}



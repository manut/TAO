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
// be/be_codegen.cpp:848

#ifndef _TAO_IDL_ORIG_TIMEBASEA_ANYOP_H_
#define _TAO_IDL_ORIG_TIMEBASEA_ANYOP_H_

#include /**/ "ace/pre.h"

// TAO_IDL - Generated from
// be/be_visitor_structure/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const TimeBase::UtcT &); // copying version
TAO_Export void operator<<= (CORBA::Any &, TimeBase::UtcT*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, TimeBase::UtcT *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const TimeBase::UtcT *&);

// TAO_IDL - Generated from
// be/be_visitor_structure/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const TimeBase::IntervalT &); // copying version
TAO_Export void operator<<= (CORBA::Any &, TimeBase::IntervalT*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, TimeBase::IntervalT *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const TimeBase::IntervalT *&);

#include /**/ "ace/post.h"

#endif /* ifndef */


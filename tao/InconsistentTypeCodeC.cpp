/* -*- C++ -*- */
// $Id$
// ======================================================================
//
// = LIBRARY
//    TAO
//
// = FILENAME
//    InconsistentTypeCode.cpp
//
// = AUTHOR
//
// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO ORB and the TAO IDL Compiler have been developed by Washington
// University Computer Science's Distributed Object Computing Group.
//
// Information on TAO is available at
//                 http://www.cs.wustl.edu/~schmidt/TAO.html
//
//
// Modified by Jeff Parsons <jp4@cs.wustl.edu>
//
// ======================================================================

#include "tao/InconsistentTypeCodeC.h"

// default constructor
CORBA_ORB_InconsistentTypeCode::CORBA_ORB_InconsistentTypeCode (void)
: CORBA_UserException (CORBA::ORB::_tc_InconsistentTypeCode)
{
}

// destructor - all members are of self managing types
CORBA_ORB_InconsistentTypeCode::~CORBA_ORB_InconsistentTypeCode (void)
{
}

// copy constructor
CORBA_ORB_InconsistentTypeCode::CORBA_ORB_InconsistentTypeCode (
    const CORBA_ORB_InconsistentTypeCode &_tao_excp
  )
  : CORBA_UserException (_tao_excp._type ())
{
}

// assignment operator
CORBA_ORB_InconsistentTypeCode&
CORBA_ORB_InconsistentTypeCode::operator= (
    const CORBA_ORB_InconsistentTypeCode &_tao_excp
  )
{
  this->CORBA_UserException::operator= (_tao_excp);
  return *this;
}

// narrow
CORBA_ORB_InconsistentTypeCode* 
CORBA_ORB_InconsistentTypeCode::_narrow (CORBA::Exception *exc)
{
  if (!ACE_OS::strcmp ("IDL:omg.org/CORBA/ORB/InconsistentTypeCode:1.0", 
                       exc->_id ())) // same type
    return ACE_dynamic_cast (CORBA_ORB_InconsistentTypeCode*, 
                             exc);
  else
    return 0;
}


void CORBA_ORB_InconsistentTypeCode::_raise ()
{
  TAO_RAISE(*this);
}

// TAO extension - the _alloc method
CORBA::Exception *CORBA_ORB_InconsistentTypeCode::_alloc (void)
{
  return new CORBA_ORB_InconsistentTypeCode;
}


// -*- c++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//
// = FILENAME
//    clnt.h
//
// = DESCRIPTION
//
// = AUTHORS
//   Michael Kircher
//
// ============================================================================

#include "ace/Get_Opt.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/corba.h"
#include "any_testC.h"
#include "NavWeapC.h"

class Any_Test_Client
  // = TITLE
  //
  // = DESCRIPTION
{
public:
  // = Constructor and destructor.
  Any_Test_Client (void);
  ~Any_Test_Client (void);

  int run (void);
  // Execute client example code.

  int init (int argc, char **argv);
  // Initialize the client communication endpoint with server.

private:

  CORBA::ORB_var orb_;
  // Remember our orb: this needs to be declared before any member that
  // depends on it so it is constructed before and destroyed after them.

  Navigation navigation_;
  // Navigation data structure.

  Weapons weapons_;
  // Weapons data structure.

  Any_Test_ptr any_test_ptr_;
  //  Reverse_ptr reverse_ptr_;

  int argc_;
  // # of arguments on the command line.

  char **argv_;
  // arguments from command line.

  CORBA::Environment env_;
  // Environment variable

};

// -*- c++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/tests/IDL_Cubit
//
// = FILENAME
//    Cubit_Server.h
//
// = DESCRIPTION
//      This class implements a simple "cube" CORBA server for the Cubit
//      example using skeletons generated by the TAO ORB IDL compiler.
//
// = AUTHORS
//    Nagarajan Surendran (naga@cs.wustl.edu)
//
// ============================================================================

#ifndef _CUBIT_SERVER_H
#define _CUBIT_SERVER_H

#include "ace/Get_Opt.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Log_Msg.h"
#include "tao/TAO.h"
#include "Cubit_Client.h"
#include "Cubit_i.h"

class Cubit_Server
{
  // = TITLE
  //   Defines a Cubit Server class that implements the functionality
  //   of a server process as an object.
  //
  // = DESCRIPTION
  //   The interface is quite simple. A server program has to call
  //   init to initialize the cubit_server's state and then call run
  //   to run the orb.
public:
  // = Initialization and termination methods.
  Cubit_Server (void);
  // Default constructor

  ~Cubit_Server (void);
  // Destructor

  int init (int argc,
            char **argv,
            CORBA::Environment& env);
  // Initialize the Cubit_Server state - parsing arguments and ...

  int run (CORBA::Environment& env);
  // Run the orb

private:
  int parse_args (void);
  // Parses the commandline arguments.

  FILE* ior_output_file_;
  // File to output the cubit factory IOR.

  TAO_ORB_Manager orb_manager_;
  // The ORB manager.

  Cubit_Factory_i *factory_impl_;
  // Implementation object of the cubit factory.

  CORBA::String_var factory_id_;
  // Id of the factory.

  int argc_;
  // Number of commandline arguments.

  char **argv_;
  // commandline arguments.
};

#endif /* _CUBIT_SERVER_H */

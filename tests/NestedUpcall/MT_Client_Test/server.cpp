// -*- c++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/tests/NestedUpCalls/MT_Client_Test
//
// = FILENAME
//    server.cpp
//
// = DESCRIPTION
//    This class implements a simple server for the 
//    Nested Upcalls - MT_Client test.
//
// = AUTHORS
//    Michael Kircher
//
// ============================================================================

#include "server.h"

MT_Object_Server::MT_Object_Server (void)
  : ior_output_file_ (0)
{
}

int
MT_Object_Server::parse_args (void)
{
  ACE_Get_Opt get_opts (argc_, argv_, "do:m");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'd':  // debug flag.
        TAO_debug_level++;
        break;
      case 'o': // output the IOR to a file.
        this->ior_output_file_ = ACE_OS::fopen (get_opts.optarg, "w");
        if (this->ior_output_file_ == 0)
          ACE_ERROR_RETURN ((LM_ERROR,
                             "Unable to open %s for writing: %p\n",
                             get_opts.optarg), -1);
        break;
      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s"
                           " [-d]"
                           " [-o] <ior_output_file>"
                           "\n",
                           argv_ [0]),
                          1);
      }

  // Indicates successful parsing of command line.
  return 0;
}

int
MT_Object_Server::init (int argc,
                       char** argv,
                       CORBA::Environment& env)
{
  // Call the init of TAO_ORB_Manager to create a child POA
  // under the root POA.
  this->orb_manager_.init_child_poa (argc,
                                     argv,
                                     "child_poa",
                                     env);

  TAO_CHECK_ENV_RETURN (env,-1);
  this->argc_ = argc;
  this->argv_ = argv;

  this->parse_args ();
  // ~~ check for the return value here

  CORBA::String_var str;
  str = this->orb_manager_.activate_under_child_poa ("MT_Object",
                                                     &this->mT_Object_Impl_,
                                                     env);
  ACE_DEBUG ((LM_DEBUG,
              "The IOR is: <%s>\n",
              str.in ()));

  if (this->ior_output_file_)
    {
      ACE_OS::fprintf (this->ior_output_file_,
                       "%s",
                       str.in ());
      ACE_OS::fclose (this->ior_output_file_);
    }


  return 0;
}


int
MT_Object_Server::run (CORBA::Environment& env)
{
  if (this->orb_manager_.run (env) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "NestedUpCalls_Server::run"),
                      -1);
  return 0;
}

MT_Object_Server::~MT_Object_Server (void)
{
}

int
main (int argc, char *argv[])
{
  MT_Object_Server MT_Object_Server;

  ACE_DEBUG ((LM_DEBUG,
              "\n \t NestedUpCalls.Triangle_Test: Object A Server \n \n"));
  TAO_TRY
    {
      if (MT_Object_Server.init (argc,argv,TAO_TRY_ENV) == -1)
        return 1;
      else
        {
          MT_Object_Server.run (TAO_TRY_ENV);
          TAO_CHECK_ENV;
        }
    }
  TAO_CATCH (CORBA::SystemException, sysex)
    {
      ACE_UNUSED_ARG (sysex);
      TAO_TRY_ENV.print_exception ("System Exception");
      return -1;
    }
  TAO_CATCH (CORBA::UserException, userex)
    {
      ACE_UNUSED_ARG (userex);
      TAO_TRY_ENV.print_exception ("User Exception");
      return -1;
    }
  TAO_ENDTRY;
  return 0;
}

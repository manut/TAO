// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/tests/NestedUpCalls/Triangle_Test
//
// = FILENAME
//    server_A.cpp
//
// = DESCRIPTION
//    This class implements a simple server for the
//    Nested Upcalls - Triangle test.
//
// = AUTHORS
//    Michael Kircher
//
// ============================================================================

#include "server_A.h"
#include "tao/debug.h"

ACE_RCSID(Triangle_Test, server_A, "$Id$")

Object_A_Server::Object_A_Server (void)
  : ior_output_file_ (0)
{
}

int
Object_A_Server::parse_args (void)
{
  ACE_Get_Opt get_opts (argc_, argv_, "do:");
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
Object_A_Server::init (int argc,
                       char** argv,
                       CORBA::Environment& ACE_TRY_ENV)
{
  // Call the init of TAO_ORB_Manager to create a child POA
  // under the root POA.
  this->orb_manager_.init_child_poa (argc,
                                     argv,
                                     "child_poa",
                                     ACE_TRY_ENV);

  ACE_CHECK_RETURN (-1);
  this->argc_ = argc;
  this->argv_ = argv;

  this->parse_args ();
  // ~~ check for the return value here

  CORBA::String_var str  =
    this->orb_manager_.activate_under_child_poa ("object_A",
                                                 &this->object_A_i_,
                                                 ACE_TRY_ENV);
  ACE_CHECK_RETURN (-1);

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
Object_A_Server::run (CORBA::Environment& ACE_TRY_ENV)
{
  int r = this->orb_manager_.run (ACE_TRY_ENV);
  ACE_CHECK_RETURN (-1);

  if (r == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "NestedUpCalls_Server::run"),
                      -1);
  return 0;}


Object_A_Server::~Object_A_Server (void)
{
}

int
main (int argc, char *argv[])
{
  Object_A_Server object_A_Server;

  ACE_DEBUG ((LM_DEBUG,
              "\n \t NestedUpCalls.Triangle_Test: Object A Server \n \n"));

  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
    {
      if (object_A_Server.init (argc,argv, ACE_TRY_ENV) == -1)
        return 1;
      else
        {
          object_A_Server.run (ACE_TRY_ENV);
          ACE_TRY_CHECK;
        }
    }
  ACE_CATCH (CORBA::SystemException, sysex)
    {
      ACE_PRINT_EXCEPTION (sysex, "System Exception");
      return -1;
    }
  ACE_CATCH (CORBA::UserException, userex)
    {
      ACE_PRINT_EXCEPTION (userex, "User Exception");
      return -1;
    }
  ACE_ENDTRY;
  return 0;
}

// $Id$

#include "NodeManager_Impl.h"
#include "orbsvcs/CosNamingC.h"
#include "tao/IORTable/IORTable.h"
#include "ace/SString.h"
#include "ace/Read_Buffer.h"
#include "ace/Get_Opt.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_unistd.h"
#include "ace/os_include/os_netdb.h"
#include "ciao/Server_init.h"
#include "ciao/CIAO_common.h"

const char *ior_file_name_ = "nodedaemon.ior";
char *default_svcconf_ = 0;
char *svcconf_config_ = 0;
char *nodeapp_location_ = 0;
char *nodeapp_options_ = 0;
int write_to_ior_ = 0;
int register_with_ns_ = 0;
int nodeapp_loc_ = 0;
int spawn_delay = 1;

int
parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, "o:c:m:s:d:na:");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'o':  // get the file name to write to
       ior_file_name_ = get_opts.opt_arg ();
       write_to_ior_ = 1;
      break;

      case 'c':  // get the default svc.conf filename
        default_svcconf_ = get_opts.opt_arg ();
      break;

      case 'm':  // get the svc.conf map configuration filename
        svcconf_config_ = get_opts.opt_arg ();
      break;

      case 's': //get the location to spawn the NodeApplication
        nodeapp_location_ = get_opts.opt_arg ();
        nodeapp_loc_ = 1;
      break;

      case 'a': // Nodeapplication arguments
        nodeapp_options_ = get_opts.opt_arg ();
        break;

      case 'd': //get the spawn delay argument
        spawn_delay = ACE_OS::atoi (get_opts.opt_arg ());
      break;

      case 'n':
        register_with_ns_ = 1;
      break;

      case '?':  // display help for use of the server.
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s\n"
                           "-o <ior_output_file>\n"
                           "-c <svc.conf file>\n"
                           "-n <use naming service>\n"
                           "-s <NodeApplication executable path>\n"
                           "-a <arguments to NodeApplication>\n"
                           "-d <spawn delay for nodeapplication>\n"
                           "\n",
                           argv [0]),
                          -1);
      }

  return 0;
}

int
write_IOR(const char* ior)
{
  FILE* ior_output_file_ =
    ACE_OS::fopen (ior_file_name_, "w");

  if (ior_output_file_)
    {
      ACE_OS::fprintf (ior_output_file_,
                       "%s",
                       ior);
      ACE_OS::fclose (ior_output_file_);
    }

  return 0;
}

bool
register_with_ns (const char * name_context,
                  CORBA::ORB_ptr orb,
                  CIAO::NodeManager_ptr obj
                  ACE_ENV_ARG_DECL)
{
  // Naming Service related operations
  CORBA::Object_var naming_context_object =
    orb->resolve_initial_references ("NameService"
                                     ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (false);

  CosNaming::NamingContext_var naming_context =
    CosNaming::NamingContext::_narrow (naming_context_object.in ());

  // Initialize the Naming Sequence
  CosNaming::Name name (1);
  name.length (1);
  name[0].id = name_context;

  // Register the servant with the Naming Service
  naming_context->bind (name, obj);

  return true;
}

int
main (int argc, char *argv[])
{
  ACE_TRY_NEW_ENV
    {
      // Initialize orb
      // @@TODO: Add error checking. There is absoluteley none.
      CORBA::ORB_var orb = CORBA::ORB_init (argc,
                                            argv,
                                            ""
                                            ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      CIAO::Server_init (orb.in ());

      if (parse_args (argc, argv) != 0)
        return -1;

      // Check if NodeApplication executable location has been
      // specified
      if (! nodeapp_loc_)
        {
          ACE_DEBUG ((LM_DEBUG, "Use -s <NodeApplicationPath> to specify \
                                 executable path\n"));
          exit (1);
        }

      // Get reference to Root POA.
      CORBA::Object_var obj
        = orb->resolve_initial_references ("RootPOA"
                                           ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      PortableServer::POA_var poa
        = PortableServer::POA::_narrow (obj.in ()
                                        ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      CORBA::Object_var table_object =
        orb->resolve_initial_references ("IORTable"
                                         ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      IORTable::Table_var adapter =
        IORTable::Table::_narrow (table_object.in () ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (CORBA::is_nil (adapter.in ()))
          ACE_ERROR_RETURN ((LM_ERROR, "Nil IORTable\n"), -1);

      // Create and install the CIAO NodeManager servant
      CIAO::NodeManager_Impl *node_manager_servant = 0;
      ACE_NEW_RETURN (node_manager_servant,
                      CIAO::NodeManager_Impl("NodeManager",
                                             orb.in (),
                                             poa.in (),
                                             nodeapp_location_,
                                             nodeapp_options_,
                                             spawn_delay),
                      -1);

      PortableServer::ServantBase_var safe_daemon (node_manager_servant);
      
      node_manager_servant->init ();
      
      // Implicit activation
      CIAO::NodeManager_var node_manager =
        node_manager_servant->_this ();

      CORBA::String_var str =
        orb->object_to_string (node_manager.in ()
                               ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      adapter->bind ("NodeManager",
                     str.in ()
                     ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (write_to_ior_)
        write_IOR (str.in ());
      else if (register_with_ns_)
        {
          char name [MAXHOSTNAMELEN + 1];
          if (ACE_OS::hostname (name, 100) == -1)
            {
              ACE_ERROR ((LM_ERROR,
                          "gethostname call failed! \n"));
              exit (1);
            }

          // Register this name with the Naming Service
          (void) register_with_ns (name,
                                   orb.in (),
                                   node_manager.in ()
                                   ACE_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;
        }

      ACE_DEBUG ((LM_INFO, "CIAO_NodeManager IOR: %s\n", str.in ()));

      // Activate POA manager
      PortableServer::POAManager_var mgr
        = poa->the_POAManager (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      mgr->activate (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // Here start the Monitor
/*
      MonitorController* monitor_controller
              = new MonitorController (orb);

      ACE_DEBUG ((LM_DEBUG , "Before Activate"));
       monitor_controller->activate ();
      ACE_DEBUG ((LM_DEBUG , "After Activate"));
*/

      // Finishing Deployment part
      ACE_DEBUG ((LM_DEBUG,
                  "CIAO_NodeManager is running...\n"));

      // Run the main event loop for the ORB.
      orb->run (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      poa->destroy (1, 1 ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      orb->destroy (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "CIAO_NodeManager::main\t\n");
      return 1;
    }
  ACE_ENDTRY;

  ACE_DEBUG ((LM_DEBUG,
              "CIAO_NodeManager has closed\n"));
  return 0;
}

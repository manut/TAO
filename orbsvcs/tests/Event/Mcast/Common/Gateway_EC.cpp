// $Id$

#include "Gateway_EC.h"
#include "orbsvcs/orbsvcs/Event/EC_Default_Factory.h"
#include "orbsvcs/orbsvcs/Event/ECG_Mcast_Gateway.h"
#include "orbsvcs/orbsvcs/Event/EC_Lifetime_Utils_T.h"
#include "ace/Get_Opt.h"
#include "ace/Dynamic_Service.h"
#include "ace/OS_NS_stdio.h"

Gateway_EC::Gateway_EC (void)
  : ec_ior_file_ ("gateway-ec.ior")
{
}

int
Gateway_EC::check_for_nil (CORBA::Object_ptr obj, const char *message)
{
  if (CORBA::is_nil (obj))
    ACE_ERROR_RETURN ((LM_ERROR,
                       "ERROR: Object reference <%s> is nil\n",
                       message),
                      -1);
  else
    return 0;
}

int
Gateway_EC::parse_args (int argc, char *argv [])
{
  ACE_Get_Opt get_opt (argc, argv, "i:");
  int opt;

  while ((opt = get_opt ()) != EOF)
    {
      switch (opt)
        {
        case 'i':
          this->ec_ior_file_ = get_opt.optarg;
          break;

        case '?':
        default:
          ACE_DEBUG ((LM_DEBUG,
                      "Usage: %s "
                      "-i ior_file_name"
                      "\n",
                      argv[0]));
          return -1;
        }
    }

  return 0;
}

void
Gateway_EC::write_ior_file (CORBA::ORB_ptr orb,
                            RtecEventChannelAdmin::EventChannel_ptr ec
                            ACE_ENV_ARG_DECL)
{
  // Write EC ior to a file.
  CORBA::String_var str;
  str = orb->object_to_string (ec ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  FILE *output_file= ACE_OS::fopen (this->ec_ior_file_, "w");
  if (output_file == 0)
    {
      ACE_ERROR ((LM_ERROR,
                  "Cannot open output file for writing IOR: %s",
                  this->ec_ior_file_));
      ACE_THROW (CORBA::INTERNAL ());
    }

  ACE_OS::fprintf (output_file, "%s", str.in ());
  ACE_OS::fclose (output_file);
}

int
Gateway_EC::run (int argc, char ** argv)
{
  // Event Channel Configuration.
  TAO_EC_Default_Factory::init_svcs ();
  // Mcast gateway configuration.
  TAO_ECG_Mcast_Gateway::init_svcs ();

  TAO_EC_ORB_Holder orb_destroyer;

  ACE_TRY_NEW_ENV
    {
      // Initialize ORB and POA, POA Manager, parse args.
      CORBA::ORB_var orb =
        CORBA::ORB_init (argc, argv, "" ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      orb_destroyer.init (orb);

      if (parse_args (argc, argv) == -1)
        return -1;

      CORBA::Object_var obj =
        orb->resolve_initial_references ("RootPOA" ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      PortableServer::POA_var poa =
        PortableServer::POA::_narrow (obj.in () ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      if (check_for_nil (poa.in (), "POA") == -1)
        return -1;
      PortableServer::POAManager_var manager =
        poa->the_POAManager (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
      manager->activate (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // Set up EC.
      TAO_EC_Servant_Var<EC_Wrapper> ec_wrapper (EC_Wrapper::create ());
      if (!ec_wrapper.in ())
        return -1;

      if (ec_wrapper->init (orb.in (),
                            poa.in ()) != 0)
        return -1;

      RtecEventChannelAdmin::EventChannel_var ec;
      TAO_EC_Object_Deactivator ec_deactivator;
      activate (ec,
                poa.in (),
                ec_wrapper.in (),
                ec_deactivator
                ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      ec_wrapper->set_deactivator (ec_deactivator);

      this->write_ior_file (orb.in (), ec.in () ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // Set up multicast components.
      // Obtain mcast gateway from service configurator.
      TAO_ECG_Mcast_Gateway * gateway = 0;
      gateway =
        ACE_Dynamic_Service<TAO_ECG_Mcast_Gateway>::instance ("ECG_Mcast_Gateway");

      if (!gateway)
        {
          ACE_TRY_THROW (CORBA::INTERNAL ());
          ACE_TRY_CHECK;
        }
      gateway->run (orb.in (), ec.in () ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // Run server.
      orb->run (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Unexpected Exception in Gateway EC:");
    }
  ACE_ENDTRY;

  return 0;
}

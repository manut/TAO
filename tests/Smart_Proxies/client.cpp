// $Id$

#include "ace/Get_Opt.h"
#include "testC.h"
#include "Smart_Proxy_Impl.h"

ACE_RCSID(Smart_Proxy, client, "$Id$")

const char *ior = "file://test.ior";

int
parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, "i");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'i':
        ior = ACE_OS::strdup (get_opts.optarg);
      break;
      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s "
                           "-i "
                           "\n",
                           argv [0]),
                          -1);
      }
  return 0;
}


int
main (int argc, char *argv[])
{
  ACE_TRY_NEW_ENV
    {
      CORBA::ORB_var orb =
        CORBA::ORB_init (argc, argv, "", ACE_TRY_ENV);
      ACE_TRY_CHECK;

      if (parse_args (argc, argv) != 0)
        return 1;
      
       CORBA::Object_var object =
        orb->string_to_object (ior, ACE_TRY_ENV);
      ACE_TRY_CHECK;

      // For using the smart proxy:
      // Its necessary to allocate the user_defined smart factory on
      // the heap as the smart proxy generated classes take care of 
      // destroying the object. This way it a win situation
      // for the application developer who doesnt have to 
      // make sure to destoy it and also for the smart proxy
      // designer who now can manage the lifetime of the object
      // much surely.
	  smart_test_factory *test_factory = 0;
      ACE_NEW_RETURN (test_factory, 
                      smart_test_factory,
                      -1);
      
      // This was done for using the default proxy.
      test_var server =
        test::_narrow (object.in (), ACE_TRY_ENV);
      ACE_TRY_CHECK;
      
      if (CORBA::is_nil (server.in ()))
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "Object reference <%s> is nil\n",
                             ior),
                            1);
        }
      
      server->method (0);

      server->shutdown (ACE_TRY_ENV);

      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Client side exception:");
      return 1;
    }
  ACE_ENDTRY;

   return 0;
}

// $Id$

#include "ace/Get_Opt.h"
#include "Logging_Service.h"
#include "orbsvcs/Log/BasicLogFactory_i.h"

Logging_Service::Logging_Service (void)
  : basic_log_factory_name_ ("BasicLogFactory")
{
  // No-Op.
}

Logging_Service::~Logging_Service (void)
{
  // No-Op.
}

void
Logging_Service::init_ORB  (int& argc, char *argv []
                             TAO_ENV_ARG_DECL)
{
  this->orb_ = CORBA::ORB_init (argc,
                                argv,
                                ""
                                TAO_ENV_ARG_PARAMETER);
  ACE_CHECK;

  CORBA::Object_var poa_object  =
    this->orb_->resolve_initial_references("RootPOA"
                                           TAO_ENV_ARG_PARAMETER);
  ACE_CHECK;

  this->poa_ =
    PortableServer::POA::_narrow (poa_object.in ()
                                  TAO_ENV_ARG_PARAMETER);
  ACE_CHECK;

  PortableServer::POAManager_var poa_manager =
    this->poa_->the_POAManager (TAO_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  poa_manager->activate (TAO_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;
}

void
Logging_Service::startup (int argc, char *argv[]
                          TAO_ENV_ARG_DECL)
{
  ACE_DEBUG ((LM_DEBUG,
              "\nStarting up the Telecom Log Service...\n"));

  // initalize the ORB.
  this->init_ORB (argc, argv
                  TAO_ENV_ARG_PARAMETER);
  ACE_CHECK;

  // Resolve the naming service.
  this->resolve_naming_service (TAO_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  // Activate the basic log factory
  // CORBA::Object_var obj =
  DsLogAdmin::BasicLogFactory_var obj =
    this->basic_log_factory_.activate (this->poa_.in ()
                                       TAO_ENV_ARG_PARAMETER);
  ACE_CHECK;
  ACE_ASSERT (!CORBA::is_nil (obj.in ()));

  CORBA::String_var str =
    this->orb_->object_to_string (obj.in () TAO_ENV_ARG_PARAMETER);
  ACE_CHECK;

  ACE_DEBUG ((LM_DEBUG,
              "The Basic Log Factory IOR is <%s>\n", str.in ()));

  // Register the Basic Log Factory
  ACE_ASSERT(!CORBA::is_nil (this->naming_.in ()));

  CosNaming::Name name (1);
  name.length (1);
  name[0].id = CORBA::string_dup (this->basic_log_factory_name_);

  this->naming_->rebind (name,
                         obj.in ()
                         TAO_ENV_ARG_PARAMETER);
  ACE_CHECK;

  ACE_DEBUG ((LM_DEBUG,
              "Registered with the naming service as: %s\n",
              this->basic_log_factory_name_));
}

void
Logging_Service::resolve_naming_service (TAO_ENV_SINGLE_ARG_DECL)
{
  CORBA::Object_var naming_obj =
    this->orb_->resolve_initial_references ("NameService"
                                            TAO_ENV_ARG_PARAMETER);
  ACE_CHECK;

  // Need to check return value for errors.
  if (CORBA::is_nil (naming_obj.in ()))
    ACE_THROW (CORBA::UNKNOWN ());

  this->naming_ =
    CosNaming::NamingContext::_narrow (naming_obj.in ()
                                       TAO_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

int
Logging_Service::run (void)
{
  ACE_DEBUG ((LM_DEBUG, "%s: Running the Telecom Log Service\n", __FILE__));

  TAO_ENV_DECLARE_NEW_ENV;
  ACE_TRY
    {
      this->orb_->run (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      return -1;
    }
  ACE_ENDTRY;

  return 0;
}

void
Logging_Service::shutdown (TAO_ENV_SINGLE_ARG_DECL)
{
  // Deactivate.
  PortableServer::ObjectId_var oid =
    this->poa_->servant_to_id (&this->basic_log_factory_
                               TAO_ENV_ARG_PARAMETER);
  ACE_CHECK;

  // deactivate from the poa.
  this->poa_->deactivate_object (oid.in ()
                                 TAO_ENV_ARG_PARAMETER);
  ACE_CHECK;

  // Unbind from the naming service.
  CosNaming::Name name (1);
  name.length (1);
  name[0].id = CORBA::string_dup (this->basic_log_factory_name_);

  this->naming_->unbind (name
                         TAO_ENV_ARG_PARAMETER);

  // shutdown the ORB.
  if (!CORBA::is_nil (this->orb_.in ()))
    this->orb_->shutdown ();
}

int
main (int argc, char *argv[])
{
  Logging_Service service;

  ACE_TRY_NEW_ENV
    {
      service.startup (argc,
                       argv
                       TAO_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (service.run () == -1)
        {
          service.shutdown ();
          ACE_ERROR_RETURN ((LM_ERROR,
                             "Failed to run the Telecom Log Service.\n"),
                            1);
        }
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Failed to start the Telecom Log Service\n");
      return 1;
    }
  ACE_ENDTRY;

  service.shutdown ();

  return 0;
}

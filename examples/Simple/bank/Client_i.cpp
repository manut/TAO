// $Id$

#include "ace/Get_Opt.h"
#include "ace/Read_Buffer.h"
#include "Client_i.h"

ACE_RCSID(Bank, Client_i, "$Id$")

// Constructor.

Client_i::Client_i (void)
  : ior_ (0),
    loop_count_ (10),
    shutdown_ (0),
    server_ ()
{
}

// Reads the Server factory ior from a file

int
Client_i::read_ior (char *filename)
{
  // Open the file for reading.
  ACE_HANDLE f_handle = ACE_OS::open (filename, 0);

  if (f_handle == ACE_INVALID_HANDLE)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "Unable to open %s for writing: %p\n",
                       filename),
                      -1);

  ACE_Read_Buffer ior_buffer (f_handle);
  char *data = ior_buffer.read ();

  if (data == 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "Unable to read ior: %p\n"),
                      -1);

  this->ior_ = ACE_OS::strdup (data);
  ior_buffer.alloc ()->free (data);

  ACE_OS::close (f_handle);

  return 0;
}

// Parses the command line arguments and returns an error status.

int
Client_i::parse_args (void)
{
  ACE_Get_Opt get_opts (argc_, argv_, "dn:b:o:f:xk:");
  int c;
  int result;

  while ((c = get_opts ()) != -1)
    // ACE_DEBUG((LM_DEBUG,"bal =1%c",c
    //		   ));
    switch (c)
      {
      case 'd':  // debug flag
        TAO_debug_level++;
        break;
      case 'n':  // loop count
	this->loop_count_ = (u_int) ACE_OS::atoi (get_opts.optarg);
        break;
      case 'b':  // initial balance
	this->initial_balance_ = (float) ACE_OS::atoi (get_opts.optarg);
	ACE_DEBUG((LM_DEBUG,"bal = %f",
			    initial_balance_));
      break;
      case 'o': // Name of the account holder.
	this->account_holder_name_ = ACE_OS::strdup (get_opts.optarg);
	break;
      case 'k':  // ior provide on command line
        this->ior_ = ACE_OS::strdup (get_opts.optarg);
        break;
      case 'f': // read the IOR from the file.
        result = this->read_ior (get_opts.optarg);
        if (result < 0)
          ACE_ERROR_RETURN ((LM_ERROR,
                             "Unable to read ior from %s : %p\n",
                             get_opts.optarg),
                            -1);
        break;
      case 'x':
        this->shutdown_ = 1;
        break;
      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s"
                           " [-d]"
			   " [-b Initial Balance]"
			   " [-o Account Holder's Name]"
                           " [-n loopcount]"
                           " [-f ior-file]"
                           " [-k ior]"
                           " [-x]"
                           "\n",
                           this->argv_ [0]),
                          -1);
      }

  // Indicates successful parsing of command line.
  return 0;
}

void
Client_i::deposit (CORBA::Float deposit_amount,
		   CORBA::Environment &env)
{
  server_->deposit (deposit_amount,
		    this->env_);
}

void
Client_i::withdraw (CORBA::Float withdrawl_amount)
{
  TAO_TRY
    {
      server_->withdraw (withdrawl_amount,
			 TAO_TRY_ENV);
      TAO_CHECK_ENV;
    }
  TAO_CATCHANY
    {
      Bank::Account::Overdraft_ptr except =
	Bank::Account::Overdraft::_narrow
	(TAO_TRY_ENV.exception ());

      ACE_DEBUG ((LM_DEBUG,
		  "exception%s",
		  (char *) except->reason));
    }
  TAO_ENDTRY;
}

Bank::Account_ptr
Client_i::open (const char *name,
		CORBA::Float initial_balance,
		CORBA::Environment &env)
{
  return this->accountmanager_server_->open (name,
					     initial_balance,
					     env);
}

void
Client_i::close (Bank::Account_ptr account,
		 CORBA::Environment &env)
{
  this->accountmanager_server_->close (account,
				       env);
}

CORBA::Float
Client_i::balance (CORBA::Environment &env)
{
  return server_->balance (env);
}

// Call the remote methods on the Account and AccountManager
// interface.

CORBA::Float
Client_i::check_accounts (void)
{
  TAO_TRY
    {
      this->server_ = this->open (this->account_holder_name_,
				  this->initial_balance_,
				  this->env_);
      TAO_CHECK_ENV;

      CORBA::Float my_balance = this->balance (this->env_);

      ACE_ASSERT (this->initial_balance_ == my_balance);

      this->deposit (100.00, this->env_);
      TAO_CHECK_ENV;

      my_balance = this->balance (this->env_);

      ACE_ASSERT (my_balance == this->initial_balance_ + 100.00);

      this->withdraw (50.00);

      my_balance = this->balance (this->env_);
      TAO_CHECK_ENV;

      ACE_ASSERT (my_balance == initial_balance_ + 50.00);

      ACE_DEBUG ((LM_DEBUG,
		  "%s\n",
		  this->server_->name()
		  ));

      TAO_CHECK_ENV;

      // Make sure we get back the same object reference!

      //ACE_ASSERT (server2->_is_equivalent (server_.in (),
      //				   TAO_TRY_ENV));
      //TAO_CHECK_ENV;

      //this->deposit (150.00, this->env_);
      //TAO_CHECK_ENV;

      //my_balance = this->balance (this->env_);
      //TAO_CHECK_ENV;

      //ACE_ASSERT (my_balance = this->initial_balance_ + 200.00);

      // Following assertion checks if we get back a DIFFERENT object
      // reference for a different account.

      // ACE_ASSERT (server_->_is_equivalent (server.in (),
      //				   TAO_TRY_ENV) == FALSE);
      //TAO_CHECK_ENV;

      // Close the Account.

      this->close (server_.in (),
		   this->env_);
      TAO_CHECK_ENV;

    }
  TAO_CATCHANY
    {
      if (this->env_.exception () != 0)
	this->env_.print_exception ("from Client_i::balance");
    }
  TAO_ENDTRY;

  return 0;
}

// Execute client example code.

int
Client_i::run (void)
{
  u_int i;

  this->check_accounts ();

  TAO_TRY
    {
      if (this->shutdown_)
      this->accountmanager_server_->shutdown (TAO_TRY_ENV);
      TAO_CHECK_ENV;
    }
  TAO_CATCHANY
    {
      ACE_DEBUG ((LM_DEBUG,
		  "Unable to shut down the server\n"));
    }
  TAO_ENDTRY;

return 0;

}

Client_i::~Client_i (void)
{
  ACE_OS::free (this->ior_);
}

int
Client_i::obtain_initial_references (void)
{
  TAO_TRY
    {
      // Initialize the naming services.
      if (my_name_client_.init (orb_.in (), argc_, argv_) != 0)
	ACE_ERROR_RETURN ((LM_ERROR,
			   " (%P|%t) Unable to initialize "
			   "the TAO_Naming_Client. \n"),
			  -1);

      CosNaming::Name account_manager_name (1);
      account_manager_name.length (1);
      account_manager_name[0].id =
      CORBA::string_dup ("AccountManager");

      CORBA::Object_var account_manager_obj =
        my_name_client_->resolve (account_manager_name,
				  TAO_TRY_ENV);
      TAO_CHECK_ENV;

      this->accountmanager_server_ =
        Bank::AccountManager::_narrow (account_manager_obj.in (),
				       TAO_TRY_ENV);
      TAO_CHECK_ENV;
    }
  TAO_CATCHANY
    {
      TAO_TRY_ENV.print_exception ("Bank::obtain_initial_references");
      return -1;
    }
  TAO_ENDTRY;

  return 0;
}

// This method uses the IOR if specified on the command line or in a
// file, else it uses the Naming Service

int
Client_i::init (int argc, char **argv)
{
  this->argc_ = argc;
  this->argv_ = argv;

  TAO_TRY
    {
      // Retrieve the ORB.
      this->orb_ = CORBA::ORB_init (this->argc_,
                                    this->argv_,
                                    0,
                                    TAO_TRY_ENV);
      TAO_CHECK_ENV;

      // Parse command line and verify parameters.
      if (this->parse_args () == -1)
        return -1;

      if (this->ior_)
	{
	  // An ior is specified for the client through a commandline
	  // option or a file.

	  CORBA::Object_var server_object =
	  this->orb_->string_to_object (this->ior_,
					TAO_TRY_ENV);
	  TAO_CHECK_ENV;

	  if (CORBA::is_nil (server_object.in ()))
	    ACE_ERROR_RETURN ((LM_ERROR,
			       "invalid ior <%s>\n",
			       this->ior_),
			      -1);

	  this->accountmanager_server_ =
	    Bank::AccountManager::_narrow (server_object.in (),
					   TAO_TRY_ENV);

	  ACE_DEBUG ((LM_DEBUG,
		      "Using the IOR provided\n"));
	  TAO_CHECK_ENV;
	}
      else
	{ // No IOR specified. Use the Naming Service
	  ACE_DEBUG((LM_DEBUG,
		     "Using the Naming Service\n"));

	  this->obtain_initial_references ();
	  TAO_CHECK_ENV;
	}
    }
  TAO_CATCHANY
    {
      TAO_TRY_ENV.print_exception ("Client_i::init");
      return -1;
    }
  TAO_ENDTRY;

  return 0;
}

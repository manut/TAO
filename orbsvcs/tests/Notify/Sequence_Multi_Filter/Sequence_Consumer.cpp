// $Id$

// ******************************************************************
// Include Section
// ******************************************************************

#include "ace/Get_Opt.h"

#include "orbsvcs/CosNotifyCommC.h"
#include "orbsvcs/CosNamingC.h"
#include "Notify_Sequence_Push_Consumer.h"
#include "goC.h"

#include "Notify_Test_Client.h"

// ******************************************************************
// Data Section
// ******************************************************************

static const char* ior = "file://supplier.ior";
static int done = 0;
static CORBA::Short discard_policy = CosNotification::FifoOrder;
static unsigned int low = 2;  // 10
static unsigned int high = 4; // 13
static CORBA::Boolean filter = 1;
static const char* constraintString = "Number == 10";

// ******************************************************************
// Subroutine Section
// ******************************************************************

class Consumer_Client : public Notify_Test_Client
{
public:
  virtual int parse_args (int argc, char* argv[]);
};

int
Consumer_Client::parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, "k:l:h:d:c:");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'k':
        ior = get_opts.optarg;
        break;

      case 'l':
        low = ACE_OS::atoi (get_opts.optarg);
        break;

      case 'h':
        high = ACE_OS::atoi (get_opts.optarg);
        break;

      case 'd':
      {
        const char* discard = get_opts.optarg;
        if (ACE_OS::strcmp(discard, "fifo") == 0)
          {
            discard_policy = CosNotification::FifoOrder;
          }
        else if (ACE_OS::strcmp(discard, "priority") == 0)
          {
            discard_policy = CosNotification::PriorityOrder;
          }
        else if (ACE_OS::strcmp(discard, "lifo") == 0)
          {
            discard_policy = CosNotification::LifoOrder;
          }
        else
          {
            ACE_ERROR_RETURN ((LM_ERROR,
                               "Unknown discard policy: %s\n",
                               discard_policy),
                              -1);
          }
        break;
      }
      case 'c':
        constraintString = get_opts.optarg;
        break;
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s "
                           "-k <ior> "
                           "-l <low expected events> "
                           "-h <high expected events> "
                           "-d <fifo|priority|lifo> "
                           "-c <constraint string> "
                           "\n",
                           argv [0]),
                          -1);
      }
  // Indicates sucessful parsing of the command line
  return 0;
}


static CosNotifyChannelAdmin::ConsumerAdmin_ptr
create_consumeradmin (CosNotifyChannelAdmin::EventChannel_ptr ec
                      TAO_ENV_ARG_DECL)
{
  CosNotifyChannelAdmin::AdminID adminid = 0;
  CosNotifyChannelAdmin::ConsumerAdmin_var admin =
    ec->new_for_consumers (CosNotifyChannelAdmin::OR_OP,
                           adminid
                           TAO_ENV_ARG_PARAMETER);

  ACE_CHECK_RETURN (0);

  // Setup the CA to receive all type of events
  CosNotification::EventTypeSeq added(1);
  CosNotification::EventTypeSeq removed (0);
  added.length (1);
  removed.length (0);

  added[0].domain_name =  CORBA::string_dup ("*");
  added[0].type_name = CORBA::string_dup ("*");

  admin->subscription_change (added, removed TAO_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  return CosNotifyChannelAdmin::ConsumerAdmin::_duplicate (admin.in ());
}


static void
create_consumers (CosNotifyChannelAdmin::ConsumerAdmin_ptr admin,
                  Notify_Test_Client* client
                  TAO_ENV_ARG_DECL)
{
  // startup the first consumer
  Notify_Sequence_Push_Consumer* consumer_1;
  ACE_NEW_THROW_EX (consumer_1,
                    Notify_Sequence_Push_Consumer ("consumer1",
                                                   discard_policy,
                                                   low,
                                                   high,
                                                   done),
                    CORBA::NO_MEMORY ());
  consumer_1->init(client->root_poa () TAO_ENV_ARG_PARAMETER);
  ACE_CHECK;

  consumer_1->connect (admin TAO_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

// ******************************************************************
// Main Section
// ******************************************************************

int main (int argc, char* argv[])
{
  int status = 0;
  ACE_TRY_NEW_ENV
    {
      Consumer_Client client;

      status = client.init (argc, argv TAO_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (status == 0)
        {
          CosNotifyChannelAdmin::EventChannel_var ec =
            client.create_event_channel ("MyEventChannel", 1
                                         TAO_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;

          CORBA::ORB_ptr orb = client.orb ();
          CORBA::Object_var object =
                              orb->string_to_object (ior TAO_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;

          sig_var sig = sig::_narrow (object.in () TAO_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;

          if (CORBA::is_nil (sig.in ()))
            {
              ACE_ERROR_RETURN ((LM_ERROR,
                                 "Object reference <%s> is nil\n",
                                 ior),
                                1);
            }

          CosNotifyChannelAdmin::ConsumerAdmin_var admin =
            create_consumeradmin (ec.in () TAO_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;


          if (filter)
            {
              CosNotifyFilter::FilterFactory_var ffact =
                ec->default_filter_factory (TAO_ENV_SINGLE_ARG_PARAMETER);
              ACE_TRY_CHECK;

              CosNotifyFilter::Filter_var filter =
                ffact->create_filter ("TCL" TAO_ENV_ARG_PARAMETER);
              ACE_TRY_CHECK;

              if(CORBA::is_nil(filter.in()))
                {
                  ACE_ERROR ((LM_ERROR,
                              " (%P|%t) Consumer unable to initialize filter.\n"));
                  return 1;
                }

              CosNotifyFilter::ConstraintExpSeq constraint_list (1);
              constraint_list.length(1);

              constraint_list[0].event_types.length (0);
              constraint_list[0].constraint_expr = CORBA::string_dup(constraintString);

              filter->add_constraints (constraint_list TAO_ENV_ARG_PARAMETER);
              ACE_TRY_CHECK;

              admin->add_filter(filter.in());
            }

          CosNotification::EventTypeSeq added (1);

          CosNotification::EventTypeSeq removed (0);

          added.length(1);
          removed.length(0);

          added[0].domain_name = CORBA::string_dup("*");
          added[0].type_name = CORBA::string_dup ("*");

          admin->subscription_change (added, removed TAO_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;

          if (!CORBA::is_nil (admin.in ()))
            {
              create_consumers(admin.in (), &client TAO_ENV_ARG_PARAMETER);
              ACE_TRY_CHECK;

              // Tell the supplier to go
              sig->go (TAO_ENV_SINGLE_ARG_PARAMETER);
              ACE_TRY_CHECK;

              unsigned int try_count = 0;
              unsigned int try_max = (high - low) * 2;
              while (done <= 1)
                {
                  // See if we can get any more events
                  if (done)
                    {
                      ACE_OS::sleep (3);
                      try_count++;
                      if (try_count >= try_max)
                        break;
                    }
                  if (orb->work_pending ())
                    {
                      orb->perform_work ();
                    }
                }
            }
        }
    }
  ACE_CATCH (CORBA::Exception, e)
    {
      ACE_PRINT_EXCEPTION (e,
                           "Consumer exception: ");
      status = 1;
    }
  ACE_ENDTRY;

  return status;
}

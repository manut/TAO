// $Id$

#include "ECM_Consumer.h"
#include "ECM_Data.h"

#include "orbsvcs/Event_Utilities.h"
#include "orbsvcs/Event_Service_Constants.h"
#include "orbsvcs/Time_Utilities.h"
#include "orbsvcs/CosNamingC.h"

#include "tao/Timeprobe.h"
#include "tao/ORB_Core.h"

#include "ace/Get_Opt.h"
#include "ace/Auto_Ptr.h"
#include "ace/Sched_Params.h"

ACE_RCSID(EC_Custom_Marshal, ECM_Consumer, "$Id$")

int
main (int argc, char *argv [])
{
  Driver driver;
  return driver.run (argc, argv);
}

// ****************************************************************

Driver::Driver (void)
  : n_consumers_ (1),
    event_count_ (100),
    event_a_ (ACE_ES_EVENT_UNDEFINED),
    event_b_ (ACE_ES_EVENT_UNDEFINED + 1),
    pid_file_name_ (0),
    recv_count_ (0)
{
}

// ****************************************************************

int
Driver::run (int argc, char* argv[])
{
  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
    {
      CORBA::ORB_var orb =
        CORBA::ORB_init (argc, argv, "" ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      CORBA::Object_var poa_object =
        orb->resolve_initial_references("RootPOA" ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (CORBA::is_nil (poa_object.in ()))
        ACE_ERROR_RETURN ((LM_ERROR,
                           " (%P|%t) Unable to initialize the POA.\n"),
                          1);

      PortableServer::POA_var root_poa =
        PortableServer::POA::_narrow (poa_object.in () ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      PortableServer::POAManager_var poa_manager =
        root_poa->the_POAManager (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (this->parse_args (argc, argv))
        return 1;

      ACE_DEBUG ((LM_DEBUG,
                  "Execution parameters:\n"
                  "  consumers = <%d>\n"
                  "  event count = <%d>\n"
                  "  supplier Event A = <%d>\n"
                  "  supplier Event B = <%d>\n"
                  "  pid file name = <%s>\n",

                  this->n_consumers_,
                  this->event_count_,
                  this->event_a_,
                  this->event_b_,

                  this->pid_file_name_?this->pid_file_name_:"nil") );

      if (this->pid_file_name_ != 0)
        {
          FILE* pid = ACE_OS::fopen (this->pid_file_name_, "w");
          if (pid != 0)
            {
              ACE_OS::fprintf (pid, "%ld\n",
                               ACE_static_cast (long, ACE_OS::getpid ()));
              ACE_OS::fclose (pid);
            }
        }

      int min_priority =
        ACE_Sched_Params::priority_min (ACE_SCHED_FIFO);
        // Enable FIFO scheduling, e.g., RT scheduling class on Solaris.

      if (ACE_OS::sched_params (ACE_Sched_Params (ACE_SCHED_FIFO,
                                                  min_priority,
                                                  ACE_SCOPE_PROCESS)) != 0)
        {
          if (ACE_OS::last_error () == EPERM)
            ACE_DEBUG ((LM_DEBUG,
                        "%s: user is not superuser, "
                        "so remain in time-sharing class\n", argv[0]));
          else
            ACE_ERROR ((LM_ERROR,
                        "%s: ACE_OS::sched_params failed\n", argv[0]));
        }

      if (ACE_OS::thr_setprio (min_priority) == -1)
        {
          ACE_ERROR ((LM_ERROR, "(%P|%t) main thr_setprio failed,"
                      "no real-time features\n"));
        }

      CORBA::Object_var naming_obj =
        orb->resolve_initial_references ("NameService"
                                         ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (CORBA::is_nil (naming_obj.in ()))
        ACE_ERROR_RETURN ((LM_ERROR,
                           " (%P|%t) Unable to get the Naming Service.\n"),
                          1);

      CosNaming::NamingContext_var naming_context =
        CosNaming::NamingContext::_narrow (naming_obj.in () ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      CosNaming::Name name (1);
      name.length (1);
      name[0].id = CORBA::string_dup ("EventService");

      CORBA::Object_var ec_obj =
        naming_context->resolve (name ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      RtecEventChannelAdmin::EventChannel_var channel;
      if (CORBA::is_nil (ec_obj.in ()))
        channel = RtecEventChannelAdmin::EventChannel::_nil ();
      else
        channel = RtecEventChannelAdmin::EventChannel::_narrow (ec_obj.in ()
                                                                ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      poa_manager->activate (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      this->connect_consumers (channel.in () ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      ACE_DEBUG ((LM_DEBUG, "connected consumer(s)\n"));

      ACE_DEBUG ((LM_DEBUG, "running the test\n"));
      orb->run (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      ACE_DEBUG ((LM_DEBUG, "event loop finished\n"));

      this->disconnect_consumers (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      channel->destroy (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCH (CORBA::SystemException, sys_ex)
    {
      ACE_PRINT_EXCEPTION (sys_ex, "SYS_EX");
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION, "NON SYS EX");
    }
  ACE_ENDTRY;
  return 0;
}

void
Driver::push_consumer (void* /* consumer_cookie */,
                       ACE_hrtime_t /* arrival */,
                       const RtecEventComm::EventSet& events
                       ACE_ENV_ARG_DECL_NOT_USED)
{
  // int ID =
  //   (ACE_reinterpret_cast(Test_Consumer**,consumer_cookie)
  //    - this->consumers_);
  //
  // ACE_DEBUG ((LM_DEBUG, "(%t) events received by consumer %d\n", ID));

  if (events.length () == 0)
    {
      // ACE_DEBUG ((LM_DEBUG, "no events\n"));
      return;
    }

  ACE_GUARD (TAO_SYNCH_MUTEX, ace_mon, this->recv_count_mutex_);

  this->recv_count_ += events.length ();

  int x = this->event_count_ / 10;
  if (this->recv_count_ % x == 0)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "ECM_Consumer (%P|%t): %d events received\n",
                  this->recv_count_));
    }

  if (this->recv_count_ >= this->event_count_)
    {
      TAO_ORB_Core_instance ()->orb ()->shutdown ();
    }

  // ACE_DEBUG ((LM_DEBUG, "%d event(s)\n", events.length ()));

  for (u_int i = 0; i < events.length (); ++i)
    {
      const RtecEventComm::Event& e = events[i];

      if (e.data.payload.mb () == 0)
        {
          ACE_DEBUG ((LM_DEBUG, "No data in event[%d]\n", i));
          continue;
        }

      // @@ TODO this is a little messy, infortunately we have to
      // extract the first byte to determine the byte order, the CDR
      // cannot do it for us because in certain cases the byte order
      // is not in the encapsulation. Maybe we need another
      // constructor for the InputCDR streams (but there are too many
      // already!)?

      // Note that there is no copying
      int byte_order = e.data.payload[0];

      ACE_Message_Block* mb =
        ACE_Message_Block::duplicate (e.data.payload.mb ());
      mb->rd_ptr (1); // skip the byte order

      TAO_InputCDR cdr (mb, byte_order);

      ECM_IDLData::Info info;
      cdr >> info;

      ECM_Data other;
      cdr >> other;

      if (!cdr.good_bit ())
        ACE_ERROR ((LM_ERROR, "Problem demarshalling C++ data\n"));

      ACE_Message_Block::release (mb);

      CORBA::ULong n = info.trajectory.length ();
      // ACE_DEBUG ((LM_DEBUG, "Payload contains <%d> elements\n", n));
      // ACE_DEBUG ((LM_DEBUG, "Inventory <%s> contains <%d> elements\n",
      // other.description.in (),
      // other.inventory.current_size ()));

      for (CORBA::ULong j = 0; j < n; ++j)
        {
          ECM_IDLData::Point& p = info.trajectory[j];
          if (p.x != j || p.y != j*j)
            {
              ACE_DEBUG ((LM_DEBUG,
                          "invalid data in trajectory[%d] = (%f,%f)\n",
                          j, p.x, p.y));
            }
        }
    }
}

void
Driver::connect_consumers (RtecEventChannelAdmin::EventChannel_ptr channel
                           ACE_ENV_ARG_DECL)
{
  for (int i = 0; i < this->n_consumers_; ++i)
    {
      char buf[BUFSIZ];
      ACE_OS::sprintf (buf, "consumer_%02d", i);

      ACE_NEW (this->consumers_[i],
               Test_Consumer (this, this->consumers_ + i));

      this->consumers_[i]->connect (this->event_a_,
                                    this->event_b_,
                                    channel
                                    ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
}

void
Driver::disconnect_consumers (ACE_ENV_SINGLE_ARG_DECL)
{
  for (int i = 0; i < this->n_consumers_; ++i)
    {
      this->consumers_[i]->disconnect (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;
    }
}

int
Driver::parse_args (int argc, char *argv [])
{
  ACE_Get_Opt get_opt (argc, argv, "dc:n:h:p:");
  int opt;

  while ((opt = get_opt ()) != EOF)
    {
      switch (opt)
        {
        case 'c':
          this->n_consumers_ = ACE_OS::atoi (get_opt.opt_arg ());
          break;

        case 'n':
          this->event_count_ = ACE_OS::atoi (get_opt.opt_arg ());
          break;

        case 'h':
          {
            char* aux;
                char* arg = ACE_OS::strtok_r (get_opt.opt_arg (), ",", &aux);

            this->event_a_ = ACE_ES_EVENT_UNDEFINED + ACE_OS::atoi (arg);
                arg = ACE_OS::strtok_r (0, ",", &aux);
            this->event_b_ = ACE_ES_EVENT_UNDEFINED + ACE_OS::atoi (arg);
          }
          break;

        case 'p':
          this->pid_file_name_ = get_opt.opt_arg ();
          break;

        case '?':
        default:
          ACE_DEBUG ((LM_DEBUG,
                      "Usage: %s "
                      "[ORB options] "
                      "-s <global|local> "
                      "-a (send data in events) "
                      "-h <args> "
                      "-p <pid file name> "
                      "\n",
                      argv[0]));
          return -1;
        }
    }

  if (this->event_count_ <= 0)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "%s: event count (%d) is out of range, "
                  "reset to default (%d)\n",
                  argv[0], this->event_count_,
                  100));
      this->event_count_ = 100;
    }

  if (this->n_consumers_ <= 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "%s: number of consumers or "
                         "suppliers out of range\n", argv[0]), -1);
    }

  return 0;
}

// ****************************************************************

Test_Consumer::Test_Consumer (Driver *driver, void *cookie)
  : driver_ (driver),
    cookie_ (cookie)
{
}

void
Test_Consumer::connect (int event_a,
                        int event_b,
                        RtecEventChannelAdmin::EventChannel_ptr ec
                        ACE_ENV_ARG_DECL)
{
  ACE_ConsumerQOS_Factory qos;
  qos.start_disjunction_group ();
  qos.insert_type (ACE_ES_EVENT_SHUTDOWN, 0);
  qos.insert_type (event_a, 0);
  qos.insert_type (event_b, 0);

  // = Connect as a consumer.
  RtecEventChannelAdmin::ConsumerAdmin_var consumer_admin =
    ec->for_consumers (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  this->supplier_proxy_ =
    consumer_admin->obtain_push_supplier (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  RtecEventComm::PushConsumer_var objref = this->_this (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  this->supplier_proxy_->connect_push_consumer (objref.in (),
                                                qos.get_ConsumerQOS ()
                                                ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

}

void
Test_Consumer::disconnect (ACE_ENV_SINGLE_ARG_DECL)
{
  if (CORBA::is_nil (this->supplier_proxy_.in ()))
    return;

  RtecEventChannelAdmin::ProxyPushSupplier_var proxy =
    this->supplier_proxy_._retn ();

  proxy->disconnect_push_supplier (ACE_ENV_SINGLE_ARG_PARAMETER);
}

void
Test_Consumer::push (const RtecEventComm::EventSet& events
                     ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_hrtime_t arrival = ACE_OS::gethrtime ();
  this->driver_->push_consumer (this->cookie_, arrival, events ACE_ENV_ARG_PARAMETER);
}

void
Test_Consumer::disconnect_push_consumer (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((CORBA::SystemException))
{
}

// ****************************************************************

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
#elif defined(ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

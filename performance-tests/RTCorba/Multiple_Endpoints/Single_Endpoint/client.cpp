// $Id$

#include "../testC.h"
#include "tao/rtcorbafwd.h"
#include "tao/Priority_Mapping.h"
#include "ace/Get_Opt.h"
#include "ace/Task.h"
#include "ace/Stats.h"
#include "ace/High_Res_Timer.h"
#include "ace/Sched_Params.h"

ACE_RCSID(Latency, client, "$Id$")

class Client : public ACE_Task_Base
{
  // = TITLE
  //   Run the client thread
  //
  // = DESCRIPTION
  //   Use the ACE_Task_Base class to run the client threads.
  //
public:
  Client (void);
  // ctor

  void set (Test_ptr server, int niterations, int id, CORBA::ORB_ptr);
  // Set the test attributes.

  void accumulate_into (ACE_Throughput_Stats &throughput) const;
  // Accumulate the throughput statistics into <throughput>

  void dump_stats (const char* msg, ACE_UINT32 gsf);
  // Output the accumulated statistics.

  // = The ACE_Task_Base methods....
  virtual int svc (void);

private:
  CORBA::ORB_ptr orb_;

  Test_var server_;
  // The server.

  int niterations_;
  // The number of iterations on each client thread.

  int id_;
  // The index into array for this thread.

  ACE_Throughput_Stats throughput_;
  // Keep throughput statistics on a per-thread basis
};

// ****************************************************************

const char *ior = "file://test.ior";
int nthreads = 0;
int niterations = 1000;
int period = -1;
const int MAX_THREADS = 128;
Client client[MAX_THREADS];
int priorities[MAX_THREADS];

int
parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, "i:t:n:p:");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'i':
        ior = get_opts.optarg;
        break;
      case 't':
        if (nthreads < MAX_THREADS)
          {
            priorities[nthreads] = ACE_OS::atoi (get_opts.optarg);
            nthreads++;
          }
        break;
      case 'n':
        niterations = ACE_OS::atoi (get_opts.optarg);
        break;
      case 'p':
        period = ACE_OS::atoi (get_opts.optarg);
        break;
      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s "
                           "-i <ior> "
                           "-t <priority> "
                           "-n <niterations> "
                           "-p <period>"
                           "\n",
                           argv [0]),
                          -1);
      }
  // Indicates sucessful parsing of the command line
  return 0;
}

int
main (int argc, char *argv[])
{
  int policy = ACE_SCHED_FIFO;
  int flags  = THR_SCHED_FIFO|THR_NEW_LWP|THR_JOINABLE|THR_BOUND;
  int priority =
    ACE_Sched_Params::priority_max (policy);

  // Enable FIFO scheduling, e.g., RT scheduling class on Solaris.
  if (ACE_OS::sched_params (ACE_Sched_Params (policy,
                                              priority,
                                              ACE_SCOPE_PROCESS)) != 0)
    {
      if (ACE_OS::last_error () == EPERM)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "client (%P|%t): user is not superuser, "
                      "test runs in time-shared class\n"));
          policy = ACE_SCHED_OTHER;
          flags = THR_NEW_LWP|THR_JOINABLE;
        }
      else
        ACE_ERROR ((LM_ERROR,
                    "server (%P|%t): sched_params failed\n"));
    }

  ACE_TRY_NEW_ENV
    {
      ACE_UINT32 gsf = ACE_High_Res_Timer::global_scale_factor ();

      CORBA::ORB_var orb =
        CORBA::ORB_init (argc, argv, "", ACE_TRY_ENV);
      ACE_TRY_CHECK;

      if (parse_args (argc, argv) != 0)
        return 1;

      CORBA::Object_var object =
        orb->string_to_object (ior, ACE_TRY_ENV);
      ACE_TRY_CHECK;

      Test_var server =
        Test::_narrow (object.in (), ACE_TRY_ENV);
      ACE_TRY_CHECK;

      if (CORBA::is_nil (server.in ()))
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "Object reference <%s> is nil\n",
                             ior),
                            1);
        }

      RTCORBA::PriorityMapping *pm =
        orb->orb_core ()->priority_mapping ();
      for (int i = 0; i != nthreads; ++i)
        {
          client[i].set (server.in (), niterations, i, orb.in ());

          CORBA::Short native_priority = 0;
          pm->to_native (priorities[i], native_priority);

          if (client[i].activate (flags,
                                  1, 1,
                                  native_priority) != 0)
            ACE_ERROR_RETURN ((LM_ERROR,
                               "Cannot activate client threads\n"),
                              1);
        }

      ACE_Thread_Manager::instance ()->wait ();

      ACE_DEBUG ((LM_DEBUG, "Threads finished\n"));

      ACE_Throughput_Stats throughput;

      for (int j = 0; j != nthreads; ++j)
        {
          client[j].accumulate_into (throughput);

          char buf[64];
          ACE_OS::sprintf (buf, "Thread (index= %d)", j);
          client[j].dump_stats (buf, gsf);
        }
      throughput.dump_results ("Aggregated", gsf);

      server->shutdown ("", ACE_TRY_ENV);
      ACE_TRY_CHECK;

    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Catched exception:");
      return 1;
    }
  ACE_ENDTRY;

  return 0;
}

// ****************************************************************

Client::Client (void)
{
}

void
Client::set (Test_ptr server,
             int niterations,
             int id,
             CORBA::ORB_ptr orb)
{
  this->server_ = Test::_duplicate (server);
  this->niterations_ = niterations;
  this->id_ = id;
  orb_ = orb;
}

int
Client::svc (void)
{
  ACE_hthread_t current;
  ACE_Thread::self (current);

  int native_priority;
  ACE_Thread::getprio (current, native_priority);

  ACE_DEBUG ((LM_DEBUG,
              "Thread (%t): index = %d corba_priority = %d"
              " actual native priority = %d\n",
              this->id_,
              priorities[this->id_],
              native_priority));

 ACE_TRY_NEW_ENV
    {
      // Try to make sure every thread gets its own connection.
      for (int j = 0; j < 100; ++j)
        {
          /*    CORBA::PolicyList_var pols;
          server_->_validate_connection (pols.out (),
                                         ACE_TRY_ENV);
          */

          server_->test_method (this->id_,
                                ACE_TRY_ENV);
          ACE_TRY_CHECK;
        }

      ACE_hrtime_t throughput_base = ACE_OS::gethrtime ();

      for (int i = 0; i < this->niterations_; ++i)
        {
          // Record current time.
          ACE_hrtime_t latency_base = ACE_OS::gethrtime ();

          // Invoke method.
          server_->test_method (this->id_,
                                ACE_TRY_ENV);
          ACE_TRY_CHECK;

          // Grab timestamp again.
          ACE_hrtime_t now = ACE_OS::gethrtime ();

	  if (period != -1)
	    {
	      ACE_Time_Value tv (0, period * 1000);
	      ACE_OS::sleep (tv);
	    }

          // Skip the first sample (prime).
          if (i != 0)
            {
              // Record statistics.
              this->throughput_.sample (now - throughput_base,
                                        now - latency_base);
            }
          else
            throughput_base = ACE_OS::gethrtime ();
        }
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Single_Endpoint::client: exception raised");
    }
  ACE_ENDTRY;
  return 0;
}

void
Client::accumulate_into (ACE_Throughput_Stats &throughput) const
{
  throughput.accumulate (this->throughput_);
}

void
Client::dump_stats (const char* msg, ACE_UINT32 gsf)
{
  this->throughput_.dump_results (msg, gsf);
}

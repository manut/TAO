// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/tests
//
// = FILENAME
//    client.cpp
//
// = AUTHOR
//    Andy Gokhale, Brian Mendel, Sumedh Mungee, and Sergio Flores-Gaitan
//
// ============================================================================

#include "client.h"

int
initialize (void)
{
#if defined (VXWORKS)
#if defined (VME_DRIVER)
  STATUS status = vmeDrv ();
  if (status != OK)
    printf ("ERROR on call to vmeDrv()\n");
  status = vmeDevCreate ("/vme");
  if (status != OK)
    printf ("ERROR on call to vmeDevCreate()\n");
#endif /* defined (VME_DRIVER) */
#endif /* defined (VXWORKS) */

  // Make sure we've got plenty of socket handles.  This call will
  // use the default maximum.
  ACE::set_handle_limit ();

  return 0;
}

int
do_priority_inversion_test (Task_State &ts)
{
  // Create the clients.
  Client high_priority_client (&ts);
  Client low_priority_client (&ts);

  // Create the daemon thread in its own <ACE_Thread_Manager>.
  ACE_Thread_Manager thr_mgr;

  Util_Thread util_thread (&ts, &thr_mgr);

  // The minimum priority thread is the utilization thread.
  ACE_Sched_Priority priority =
    ACE_Sched_Params::priority_min (ACE_SCHED_FIFO,
                                    ACE_SCOPE_THREAD);

  // First activate the Utilization thread.  It will wait until all
  // threads have finished binding.
  util_thread.activate (THR_BOUND,
                        1,
                        0,
                        priority);

  // Now activate the high priority client.
  priority = ACE_THR_PRI_FIFO_DEF;

  if (high_priority_client.activate (THR_BOUND | ACE_SCHED_FIFO,
                                     1,
                                     0,
                                     priority) == -1)
    ACE_ERROR ((LM_ERROR,
                "%p; priority is %d\n",
                "activate failed",
                priority));

  u_int i;

  // Drop the priority, so that the priority of clients will increase
  // with increasing client number.
  for (i = 0; i < ts.thread_count_; i++)
    priority = ACE_Sched_Params::previous_priority (ACE_SCHED_FIFO,
                                                    priority,
                                                    ACE_SCOPE_THREAD);

  ACE_DEBUG ((LM_DEBUG,
              "Creating %d clients with low priority of %d\n",
              ts.thread_count_ - 1,
              priority));

  for (i = 0; i < ts.thread_count_ - 1; i++)
    {
      // The first thread starts at the lowest priority of all the low
      // priority clients.
      if (low_priority_client.activate (THR_BOUND,
                                        1,
                                        1,
                                        priority) == -1)
        ACE_ERROR ((LM_ERROR,
                    "%p; priority is %d\n",
                    "activate failed",
                    priority));

      // Get the next higher priority.
      priority = ACE_Sched_Params::next_priority (ACE_SCHED_FIFO,
						  priority,
						  ACE_SCOPE_THREAD);
    }

  // Wait for all the threads to exit (except the utilization thread).
  ACE_Thread_Manager::instance ()->wait ();
#if defined (VXWORKS)
  ACE_OS::printf ("Test done.\n"
                  "High priority client latency : %d usec\n"
                  "Low priority client latency : %d usec\n",
                  high_priority_client.get_high_priority_latency (),
                  low_priority_client.get_low_priority_latency ());
#elif defined (CHORUS)
  ACE_OS::printf ("Test done.\n"
                  "High priority client latency : %u usec\n"
                  "Low priority client latency : %u usec\n",
                  high_priority_client.get_high_priority_latency (),
                  low_priority_client.get_low_priority_latency ());

  // output the latency values to a file, tab separated, to import it
  // to Excel to calculate jitter, in the mean time we come up with
  // the sqrt() function.
  FILE *latency_file_handle = 0;
  char latency_file[BUFSIZ];
  char buffer[BUFSIZ];

  sprintf (latency_file,
	   "cb%d%s%d.txt",
	   ACE_OS::getpid (),
	   ts.use_sysbench_ == 1? "SB": "__",
	   ts.thread_count_);
  ACE_DEBUG ((LM_DEBUG,
              "--->Output file for latency data is \"%s\"\n",
              latency_file));

  latency_file_handle = ACE_OS::fopen (latency_file, "w");

  // @@ What does this loop do?
  for (u_int j = 0; j < ts.start_count_; j ++)
    {
      sprintf (buffer,
               "%s #%d",
               j == 0 ? "High Priority": "Low Priority",
               j);

      for (u_int i = 0; i < ts.loop_count_; i ++)
	{
	  sprintf (buffer + ACE_OS::strlen (buffer),
                   "\t%u\n", ts.global_jitter_array_[j][i]);
	  ACE_OS::fputs (buffer,
                         latency_file_handle);
	  buffer[0] = 0;
	}
    }

  ACE_OS::fclose (latency_file_handle);

#else /* !defined (CHORUS) */
  ACE_DEBUG ((LM_DEBUG, "Test done.\n"
              "High priority client latency : %f msec, jitter: %f msec\n"
              "Low priority client latency : %f msec, jitter: %f msec\n",
              high_priority_client.get_high_priority_latency (),
              high_priority_client.get_high_priority_jitter (),
              low_priority_client.get_low_priority_latency (),
              low_priority_client.get_low_priority_jitter ()));
#endif /* !defined (VXWORKS) && !defined (CHORUS) */

  // signal the utilization thread to finish with its work..
  util_thread.done_ = 1;

  // This will wait for the utilization thread to finish.
  thr_mgr.wait ();

#if defined (ACE_LACKS_FLOATING_POINT)
  ACE_DEBUG ((LM_DEBUG,
              "(%t) utilization task performed %u computations\n",
              util_thread.get_number_of_computations ()));
#else
  ACE_DEBUG ((LM_DEBUG,
              "(%t) utilization task performed %g computations\n",
              util_thread.get_number_of_computations ()));
#endif /* ! ACE_LACKS_FLOATING_POINT */

  return 0;
}

int
do_thread_per_rate_test (Task_State &ts)
{
  // First activate the high priority client.
    Client CB_40Hz_client (&ts);
    Client CB_20Hz_client (&ts);
    Client CB_10Hz_client (&ts);
    Client CB_5Hz_client (&ts);
    Client CB_1Hz_client (&ts);

    ACE_Sched_Priority priority = ACE_THR_PRI_FIFO_DEF;

    ACE_DEBUG ((LM_DEBUG,
                "Creating 40 Hz client with priority %d\n",
                priority));
    if (CB_40Hz_client.activate (THR_BOUND, 1, 0, priority) == -1)
      ACE_ERROR ((LM_ERROR,
                  "%p\n",
                  "activate failed"));

    priority = ACE_Sched_Params::previous_priority (ACE_SCHED_FIFO,
                                                    priority,
                                                    ACE_SCOPE_THREAD);
    ACE_DEBUG ((LM_DEBUG,
                "Creating 20 Hz client with priority %d\n",
                priority));
    if (CB_20Hz_client.activate (THR_BOUND, 1, 0, priority) == -1)
      ACE_ERROR ((LM_ERROR,
                  "%p\n",
                  "activate failed"));

    priority = ACE_Sched_Params::previous_priority (ACE_SCHED_FIFO,
                                                    priority,
                                                    ACE_SCOPE_THREAD);
    ACE_DEBUG ((LM_DEBUG,
                "Creating 10 Hz client with priority %d\n",
                priority));
    if (CB_10Hz_client.activate (THR_BOUND, 1, 0, priority) == -1)
      ACE_ERROR ((LM_ERROR,
                  "%p\n",
                  "activate failed"));

    priority = ACE_Sched_Params::previous_priority (ACE_SCHED_FIFO,
                                                    priority,
                                                    ACE_SCOPE_THREAD);
    ACE_DEBUG ((LM_DEBUG,
                "Creating 5 Hz client with priority %d\n",
                priority));
    if (CB_5Hz_client.activate (THR_BOUND, 1, 0, priority) == -1)
      ACE_ERROR ((LM_ERROR,
                  "%p\n",
                  "activate failed"));

    priority = ACE_Sched_Params::previous_priority (ACE_SCHED_FIFO,
                                                    priority,
                                                    ACE_SCOPE_THREAD);
    ACE_DEBUG ((LM_DEBUG,
                "Creating 1 Hz client with priority %d\n",
                priority));
    if (CB_1Hz_client.activate (THR_BOUND, 1, 0, priority) == -1)
      ACE_ERROR ((LM_ERROR,
                  "%p\n",
                  "activate failed"));

    // Wait for all the threads to exit.
    ACE_Thread_Manager::instance ()->wait ();

    ACE_DEBUG ((LM_DEBUG,
                "Test done.\n"
                "40Hz client latency : %d usec\n"
                "20Hz client latency : %d usec\n"
                "10Hz client latency : %d usec\n"
                "5Hz client latency : %d usec\n"
                "1Hz client latency : %d usec\n",
                CB_40Hz_client.get_latency (0),
                CB_20Hz_client.get_latency (1),
                CB_10Hz_client.get_latency (2),
                CB_5Hz_client.get_latency (3),
                CB_1Hz_client.get_latency (4)));
    return 0;
}

// This is the main routine of the client, where we create a high
// priority and a low priority client. we then activate the clients
// with the appropriate priority threads, and wait for them to
// finish. After they aer done, we compute the latency and jitter
// metrics and print them.

int
main (int argc, char *argv [])
{
#if defined (ACE_HAS_THREADS)
#if defined (FORCE_ARGS)
  int argc = 7;
  char *argv[] = {"main",
                  "-d",
                  "3",   // Data Type
                  "-t",
                  "10",   // Thread Count
                  "-h",
                  "mv2604d"};  // Host name
#endif   /* defined (FORCE_ARGS) */
  initialize ();

  Task_State ts (argc, argv);
  if (ts.thread_per_rate_ == 0)
    do_priority_inversion_test (ts);
  else
    do_thread_per_rate_test (ts);
#else
  ACE_DEBUG ((LM_DEBUG,
              "Test not run.  This platform doesn't seem to have threads.\n"));
#endif /* ACE_HAS_THREADS */

  return 0;
}

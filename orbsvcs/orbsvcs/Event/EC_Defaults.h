/* -*- C++ -*- */
// $Id$
//
// ============================================================================
//
// = LIBRARY
//   ORBSVCS Real-time Event Channel
//
// = FILENAME
//   EC_Defaults
//
// = DESCRIPTION
//   In this file we set the compile time defaults for the event
//   channel.
//
// = AUTHOR
//   Carlos O'Ryan (coryan@cs.wustl.edu)
//
// = CREDITS
//   Based on previous work by Tim Harrison (harrison@cs.wustl.edu)
//   and other members of the DOC group.
//   More details can be found in:
//   http://www.cs.wustl.edu/~schmidt/oopsla.ps.gz
//   http://www.cs.wustl.edu/~schmidt/JSAC-98.ps.gz
//
//
// ============================================================================

#ifndef TAO_EC_DEFAULTS_H
#define TAO_EC_DEFAULTS_H

#ifndef TAO_EC_ENABLE_DEBUG_MESSAGES
#define TAO_EC_ENABLE_DEBUG_MESSAGES 0
#endif /* TAO_EC_ENABLE_DEBUG_MESSAGES */

// Any of the definitions below can be overriden in the config.h file
// or the compilation line.

// Control consumer and supplier reconnections
#ifndef  TAO_EC_DEFAULT_CONSUMER_RECONNECT
# define TAO_EC_DEFAULT_CONSUMER_RECONNECT 0
#endif /*  TAO_EC_DEFAULT_CONSUMER_RECONNECT */

#ifndef TAO_EC_DEFAULT_SUPPLIER_RECONNECT
#define TAO_EC_DEFAULT_SUPPLIER_RECONNECT 0
#endif /* TAO_EC_DEFAULT_SUPPLIER_RECONNECT */

// Control callbacks when proxies are disconnected
#ifndef TAO_EC_DEFAULT_DISCONNECT_CALLBACKS
# define TAO_EC_DEFAULT_DISCONNECT_CALLBACKS 0
#endif /* TAO_EC_DEFAULT_DISCONNECT_CALLBACKS */

// Control the maximum degree of concurrency tolerated by the EC, some
// kind of limit is required to avoid starvation of delayed write
// operations.
#ifndef TAO_EC_DEFAULT_BUSY_HWM
# define TAO_EC_DEFAULT_BUSY_HWM 1024
#endif /* TAO_EC_DEFAULT_BUSY_HWM */

#ifndef TAO_EC_DEFAULT_MAX_WRITE_DELAY
# define TAO_EC_DEFAULT_MAX_WRITE_DELAY 2048
#endif /* TAO_EC_DEFAULT_MAX_WRITE_DELAY */

// The defaults for the default factory.
// The TAO_EC_Default_Factory is a run-time configurable factory for
// the event channel.  Using the service configurator the user can
// specify what strategies should the factory produce.
// This macros control the default values for those strategies.
//
#ifndef TAO_EC_DEFAULT_DISPATCHING
# define TAO_EC_DEFAULT_DISPATCHING 0         /* reactive */
#endif /* TAO_EC_DEFAULT_DISPATCHING */

#ifndef TAO_EC_DEFAULT_CONSUMER_FILTER
# define TAO_EC_DEFAULT_CONSUMER_FILTER 1     /* type, disj. conj. timers */
#endif /* TAO_EC_DEFAULT_CONSUMER_FILTER */

#ifndef TAO_EC_DEFAULT_SUPPLIER_FILTER
# define TAO_EC_DEFAULT_SUPPLIER_FILTER 1     /* per supplier */
#endif /* TAO_EC_DEFAULT_SUPPLIER_FILTER */

#ifndef TAO_EC_DEFAULT_TIMEOUT
# define TAO_EC_DEFAULT_TIMEOUT 0             /* reactive */
#endif /* TAO_EC_DEFAULT_TIMEOUT */

#ifndef TAO_EC_DEFAULT_OBSERVER
# define TAO_EC_DEFAULT_OBSERVER 0            /* null */
#endif /* TAO_EC_DEFAULT_OBSERVER */

#ifndef TAO_EC_DEFAULT_SCHEDULING
# define TAO_EC_DEFAULT_SCHEDULING 0          /* null */
#endif /* TAO_EC_DEFAULT_SCHEDULING */

#ifndef TAO_EC_DEFAULT_CONSUMER_COLLECTION
# define TAO_EC_DEFAULT_CONSUMER_COLLECTION 0x101 /* copy-on-read MT-safe */
#endif /* TAO_EC_DEFAULT_CONSUMER_COLLECTION */

#ifndef TAO_EC_DEFAULT_SUPPLIER_COLLECTION
# define TAO_EC_DEFAULT_SUPPLIER_COLLECTION 0x101 /* copy-on-read MT-safe */
#endif /* TAO_EC_DEFAULT_SUPPLIER_COLLECTION */

#ifndef TAO_EC_DEFAULT_CONSUMER_LOCK
# define TAO_EC_DEFAULT_CONSUMER_LOCK 1       /* thread */
#endif /* TAO_EC_DEFAULT_CONSUMER_LOCK */

#ifndef TAO_EC_DEFAULT_SUPPLIER_LOCK
# define TAO_EC_DEFAULT_SUPPLIER_LOCK 1       /* thread */
#endif /* TAO_EC_DEFAULT_SUPPLIER_LOCK */

#ifndef TAO_EC_DEFAULT_DISPATCHING_THREADS
# define TAO_EC_DEFAULT_DISPATCHING_THREADS 1 /* */
#endif /* TAO_EC_DEFAULT_DISPATCHING_THREADS */

#ifndef TAO_EC_DEFAULT_DISPATCHING_THREADS_FLAGS
# define TAO_EC_DEFAULT_DISPATCHING_THREADS_FLAGS THR_NEW_LWP|THR_SCHED_FIFO
#endif /* TAO_EC_DEFAULT_DISPATCHING_THREADS */

#ifndef TAO_EC_DEFAULT_DISPATCHING_THREADS_PRIORITY
# define TAO_EC_DEFAULT_DISPATCHING_THREADS_PRIORITY 0 /* */
#endif /* TAO_EC_DEFAULT_DISPATCHING_THREADS_PRIORITY */

#ifndef TAO_EC_DEFAULT_DISPATCHING_THREADS_FORCE_ACTIVE
# define TAO_EC_DEFAULT_DISPATCHING_THREADS_FORCE_ACTIVE 1
#endif /* TAO_EC_DEFAULT_DISPATCHING_THREADS_FORCE_ACTIVE */

#ifndef TAO_EC_DEFAULT_ORB_ID
# define TAO_EC_DEFAULT_ORB_ID "" /* */
#endif /* TAO_EC_DEFAULT_ORB_ID */

#ifndef TAO_EC_DEFAULT_CONSUMER_CONTROL
# define TAO_EC_DEFAULT_CONSUMER_CONTROL 0 /* null */
#endif /* TAO_EC_DEFAULT_CONSUMER_CONTROL */

#ifndef TAO_EC_DEFAULT_SUPPLIER_CONTROL
# define TAO_EC_DEFAULT_SUPPLIER_CONTROL 0 /* null */
#endif /* TAO_EC_DEFAULT_SUPPLIER_CONTROL */

#ifndef TAO_EC_DEFAULT_CONSUMER_CONTROL_PERIOD
# define TAO_EC_DEFAULT_CONSUMER_CONTROL_PERIOD 5000000 /* usecs */
#endif /* TAO_EC_DEFAULT_CONSUMER_CONTROL_PERIOD */

#ifndef TAO_EC_DEFAULT_SUPPLIER_CONTROL_PERIOD
# define TAO_EC_DEFAULT_SUPPLIER_CONTROL_PERIOD 5000000 /* usecs */
#endif /* TAO_EC_DEFAULT_SUPPLIER_CONTROL_PERIOD */

#endif /* TAO_EC_DEFAULTS_H */

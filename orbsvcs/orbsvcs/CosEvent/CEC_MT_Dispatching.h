/* -*- C++ -*- */
// $Id$
//
// ============================================================================
//
// = LIBRARY
//   ORBSVCS Cos Event Channel
//
// = FILENAME
//   CEC_MT_Dispatching
//
// = AUTHOR
//   Carlos O'Ryan (coryan@cs.wustl.edu)
//
// ============================================================================

#ifndef TAO_CEC_MT_DISPATCHING_H
#define TAO_CEC_MT_DISPATCHING_H
#include "ace/pre.h"

#include "CEC_Dispatching.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "CEC_Dispatching_Task.h"

class TAO_CEC_EventChannel;

class TAO_Event_Export TAO_CEC_MT_Dispatching : public TAO_CEC_Dispatching
{
  // = TITLE
  //   Dispatching strategy that minimizes mt inversion.
  //
  // = DESCRIPTION
  //   This strategy uses a single queue, serviced by one or more
  //   threads.  It's main purpose is to decouple the suppliers from
  //   the client execution time, specially in the collocated case.
  //
public:
  TAO_CEC_MT_Dispatching (int nthreads,
                         int thread_creation_flags,
                         int thread_priority,
                         int force_activate);
  // Constructor
  // It will create <nthreads> servicing threads...

  // = The EC_Dispatching methods.
  virtual void activate (void);
  virtual void shutdown (void);
  virtual void push (TAO_CEC_ProxyPushSupplier* proxy,
                     const CORBA::Any & event,
                     CORBA::Environment& env);
  virtual void push_nocopy (TAO_CEC_ProxyPushSupplier* proxy,
                            CORBA::Any& event,
                            CORBA::Environment& env);

private:
  ACE_Thread_Manager thread_manager_;
  // Use our own thread manager.

  int nthreads_;
  // The number of active tasks

  int thread_creation_flags_;
  // The flags (THR_BOUND, THR_NEW_LWP, etc.) used to create the
  // dispatching threads.

  int thread_priority_;
  // The priority of the dispatching threads.

  int force_activate_;
  // If activation at the requested priority fails then we fallback on
  // the defaults for thread activation.

  TAO_CEC_Dispatching_Task task_;
  // The dispatching task

  ACE_SYNCH_MUTEX lock_;
  // Synchronize access to internal data

  int active_;
  // Are the threads running?
};

#if defined (__ACE_INLINE__)
#include "CEC_MT_Dispatching.i"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"
#endif /* TAO_CEC_MT_DISPATCHING_H */

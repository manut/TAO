// This may look like C, but it's really -*- C++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//     TAO
//
// = FILENAME
//     Wait_Strategy.h
//
// = DESCRIPTION
//     Classes to strategize waiting for reply.
//
// = AUTHOR
//     Alexander Babu Arulanthu <alex@cs.wustl.edu>
//
// ============================================================================

#ifndef TAO_WAIT_STRATEGY_H
#define TAO_WAIT_STRATEGY_H
#include "ace/pre.h"

#include "tao/corbafwd.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class TAO_ORB_Core;
class TAO_Transport;
class TAO_Transport_Mux_Strategy;

class TAO_Export TAO_Wait_Strategy
{
  // = TITLE
  //
  //    Strategy for waiting for the reply.
  //
  // = DESCRIPTION
  //

public:
  TAO_Wait_Strategy (TAO_Transport *transport);
  // Constructor.

  virtual ~TAO_Wait_Strategy (void);
  // Destructor.

  virtual int sending_request (TAO_ORB_Core *orb_core,
                               int two_way);
  // The user is going to send a request, prepare any internal
  // variables because the reply may arrive *before* the user calls
  // wait.

  virtual int wait (ACE_Time_Value *max_wait_time,
                    int &reply_received) = 0;
  // Base class virtual method. Wait till the <reply_received> flag is
  // true or the time expires.

  virtual int handle_input (void) = 0;
  // Handle the input.

  virtual int register_handler (void) = 0;
  // Register the handler with the Reactor if it makes sense for the
  // strategy.

  virtual ACE_SYNCH_CONDITION *leader_follower_condition_variable (void);
  // Return the TSS leader follower condition variable used in the
  // Wait Strategy. Muxed Leader Follower implementation returns a
  // valid condition variable, others return 0.

protected:
  TAO_Transport *transport_;
  // Transport object.
};

// @@ Alex: we should consider moving these classes to separate files,
//    that can minimize the footprint of systems that use only one of
//    the strategies....(coryan).

// *********************************************************************

class TAO_Export TAO_Wait_On_Reactor : public TAO_Wait_Strategy
{
  // = TITLE
  //
  //    Wait on the Reactor. Happens in s Single Threaded client
  //    environment.
  //
  // = DESCRIPTION
  //

public:
  TAO_Wait_On_Reactor (TAO_Transport *transport);
  // Constructor.

  virtual ~TAO_Wait_On_Reactor (void);
  // Destructor.

  // = Documented in TAO_Wait_Strategy.

  virtual int wait (ACE_Time_Value *max_wait_time,
                    int &reply_received);
  virtual int handle_input (void);
  virtual int register_handler (void);

private:
  // int reply_received_;
  // This flag indicates if a *complete* reply has been received. Used
  // to exit the event loop.
};

// *********************************************************************

class TAO_Export TAO_Wait_On_Leader_Follower : public TAO_Wait_Strategy
{
  // = TITLE
  //
  //    Wait according to the Leader-Follower model. Leader does the
  //    event loop of the Reactor and the Followers wait on the
  //    condition variable.
  //
  // = DESCRIPTION
  //

public:
  TAO_Wait_On_Leader_Follower (TAO_Transport *transport);
  // Constructor.

  virtual ~TAO_Wait_On_Leader_Follower (void);
  // Destructor.
  
  // = Documented in TAO_Wait_Strategy.

  // virtual int sending_request (TAO_ORB_Core *orb_core,
  //                              int two_way);
  
  // virtual int wait (ACE_Time_Value *max_wait_time,
  //                   int &reply_received);

  // virtual int handle_input (void);
  
  virtual int register_handler (void);
};

// *********************************************************************

class TAO_Export TAO_Exclusive_Wait_On_Leader_Follower : public TAO_Wait_On_Leader_Follower
{
  // = TITLE
  //
  //    Wait according to the Leader-Follower model. Leader does the
  //    event loop of the Reactor and the Followers wait on the
  //    condition variable.
  //
  // = DESCRIPTION
  //    
  //     This is strategy is to work with the Exclusive Transport Mux
  //     Strategy. This was the original implementation of Leader
  //     Follower before Muxed Transport was introduced. Here the
  //     state variables such as Condition Variable etc are kept in
  //     the <Wait Strategy> which is a per Transport object.

public:
  TAO_Exclusive_Wait_On_Leader_Follower (TAO_Transport *transport);
  // Constructor.

  virtual ~TAO_Exclusive_Wait_On_Leader_Follower (void);
  // Destructor.
  
  // = Documented in TAO_Wait_Strategy.

  virtual int sending_request (TAO_ORB_Core *orb_core,
                               int two_way);
  virtual int wait (ACE_Time_Value *max_wait_time,
                    int &reply_received);
  virtual int handle_input (void);
  // virtual int register_handler (void);

protected:
  ACE_SYNCH_CONDITION* cond_response_available (void);
  // Return the cond_response_available, initializing it if
  // necessary.

  void wake_up (void);
  // Helper method to wake us up when we are a follower...

protected:
  ACE_thread_t calling_thread_;
  // the thread ID of the thread we were running in.

  ACE_SYNCH_CONDITION* cond_response_available_;
  // wait on reponse if the leader-follower model is active.

  int expecting_response_;
  // State flag which, if non-zero, indicates that we were expecting
  // respose. Otherwise, any input received is unexpected.

  int reply_received_;
  // This flag indicates if a *complete* reply was received. Until
  // that happens we block on the leader/follower condition variable
  // or the reactor event loop.
};

// *********************************************************************

class TAO_Export TAO_Muxed_Wait_On_Leader_Follower : public TAO_Wait_On_Leader_Follower
{
  // = TITLE
  //
  //    Wait according to the Leader-Follower model. Leader does the
  //    event loop of the Reactor and the Followers wait on the
  //    condition variable.
  //
  // = DESCRIPTION
  //
  //    This impelementation is to work with the Muxed Transport
  //    Mechanism. Here the state variables such as <Condition
  //    Variable> etc cannot be kept in the Wait Strategy, since the
  //    Wait Strategy is per Transport object and here the Transport
  //    is Muxed and hence there are multiple threads running in the
  //    same Transport context. 

public:
  TAO_Muxed_Wait_On_Leader_Follower (TAO_Transport *transport);
  // Constructor.

  virtual ~TAO_Muxed_Wait_On_Leader_Follower (void);
  // Destructor.
  
  // = Documented in TAO_Wait_Strategy.
  
  virtual int sending_request (TAO_ORB_Core *orb_core,
                               int two_way);

  virtual int wait (ACE_Time_Value *max_wait_time,
                    int &reply_received);

  virtual int handle_input (void);

  // virtual int register_handler (void);

  virtual ACE_SYNCH_CONDITION *leader_follower_condition_variable (void);
  // TSS Leader follower condition variable.
};

// *********************************************************************

class TAO_Export TAO_Wait_On_Read :  public TAO_Wait_Strategy
{
  // = TITLE
  //
  // = DESCRIPTION
  //   Simply block on read() to wait for the reply.
  //

public:
  TAO_Wait_On_Read (TAO_Transport *transport);
  // Constructor.

  virtual ~TAO_Wait_On_Read (void);
  // Destructor.

  // = Documented in TAO_Wait_Strategy.

  virtual int wait (ACE_Time_Value *max_wait_time,
                    int &reply_received);
  virtual int handle_input (void);
  virtual int register_handler (void);
};

#include "ace/post.h"
#endif /* TAO_WAIT_STRATEGY_H */

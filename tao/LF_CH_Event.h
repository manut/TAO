// -*- C++ -*-

//=============================================================================
/**
 *  @file LF_CH_Event.h
 *
 *  $Id$
 *
 *  @author Balachandran Natarajan <bala@cs.wustl.edu>
 */
//=============================================================================
#ifndef TAO_LF_CH_EVENT_H
#define TAO_LF_CH_EVENT_H
#include "ace/pre.h"

#include "LF_Event.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

/**
 * @class TAO_LF_CH_Event
 *
 * @brief Use the Leader/Follower loop to wait for one specific event
 * in the invocation path.
 *
 * Concrete event types and manipulation class which is used for
 * connection handleing purposes.
 */
class TAO_Export TAO_LF_CH_Event: public TAO_LF_Event
{
public:
  /// Constructor
  TAO_LF_CH_Event (void);

  /// Destructor
  virtual ~TAO_LF_CH_Event (void);

  /// Return 1 if the condition was satisfied successfully, 0 if it
  /// has not
  int successful (void) const;

  /// Return 1 if an error was detected while waiting for the
  /// event
  int error_detected (void) const;
  //@}

  /// Reset the state, irrespective of the previous states
  void reset_state (int new_state);


private:
  /// Validate and change the state
  /*
   * This concrete class uses the following states declared in the
   * class TAO_LF_Event to transition states
   *
   * LFS_IDLE                  - The event is created, and is in
   *                             initial  state.
   *
   * LFS_CONNECTION_WAIT       - The event is waiting for connection
   *                             completion and it can transition to
   *                             any of the following states, all the
   *                             states are final.
   *
   * LFS_SUCCESS               - The event, connection establishment, has
   *                             completed successfully.
   *
   * LFS_TIMEOUT               - The event has timed out.
   *
   * LFS_CONNECTION_CLOSE_WAIT - A temporary state before complete
   *                             connection closure. An event
   *                             handler in this state is supposed to
   *                             be getting ready for closure.
   *
   * LFS_CONNECTION_CLOSED     - The connection was closed since
   *                             an error occured while trying to
   *                             establish connection
   *
   *  Event State Diagram
   *  -------------------
   *                             |----> CLOSED <-|
   *                             |       ^       |
   *                             |       |       |
   *   IDLE ---> CONNECTION_WAIT-|       |     CLOSE_WAIT
   *                             |       |       ^
   *                             |       |       |
   *                             |----> SUCESS--->
   *
   * Timeouts can occur while waiting for connections or during
   * CLOSE_WAIT state.
   *
   */
  virtual void state_changed_i (int new_state);

  /// Check whether we have reached the final state..
  virtual int is_state_final (void);

  /// Set the state irrespective of anything.
  virtual void set_state (int new_state);

private:

  /// The previous state that the LF_CH_Event was in
  int prev_state_;
};

#if defined (__ACE_INLINE__)
# include "LF_Invocation_Event.inl"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"
#endif  /* TAO_LF_CH_EVENT_H */

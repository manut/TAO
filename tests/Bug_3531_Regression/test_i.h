// $Id$

#ifndef TAO_BUG_2494_REGRESSION_TEST_I_H
#define TAO_BUG_2494_REGRESSION_TEST_I_H

#include "testS.h"
#include "ace/Synch.h"

class Simple_Server_i : public POA_Simple_Server, public ACE_Event_Handler
{
  // = TITLE
  //   Simpler Server implementation
  //
  // = DESCRIPTION
  //   Implements the Simple_Server interface in test.idl
  //
public:
  Simple_Server_i (CORBA::ORB_ptr orb);
  // ctor

  // = The Simple_Server methods.
  char *test_method (Simple_Server_ptr objref);

  virtual void client_done ();

  void shutdown ();

  virtual int handle_timeout (const ACE_Time_Value &current_time,
                              const void *act = 0);

private:
  CORBA::ORB_var orb_;
  // The ORB
  ACE_Thread_Mutex           lock_;
  ACE_Condition_Thread_Mutex cond_;
  bool                       timer_registed_;
};

#if defined(__ACE_INLINE__)
#include "test_i.inl"
#endif /* __ACE_INLINE__ */

#endif /* TAO_BUG_2494_REGRESSION_TEST_I_H */

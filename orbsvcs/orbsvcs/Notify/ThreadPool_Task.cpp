// $Id$

#include "ThreadPool_Task.h"

#if ! defined (__ACE_INLINE__)
#include "ThreadPool_Task.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(RT_Notify, TAO_NS_ThreadPool_Task, "$Id$")

#include "tao/debug.h"
#include "Properties.h"
#include "AdminProperties.h"

TAO_NS_ThreadPool_Task::TAO_NS_ThreadPool_Task (void)
  : buffering_strategy_ (0), shutdown_ (0)
{
}

TAO_NS_ThreadPool_Task::~TAO_NS_ThreadPool_Task ()
{
  delete this->buffering_strategy_;
}

int
TAO_NS_ThreadPool_Task::init (int argc, char **argv)
{
  return this->ACE_Task<ACE_NULL_SYNCH>::init (argc, argv);
}

TAO_NS_Timer*
TAO_NS_ThreadPool_Task::timer (void)
{
  return &this->timer_;
}

void
TAO_NS_ThreadPool_Task::init (const NotifyExt::ThreadPoolParams& tp_params, TAO_NS_AdminProperties_var& admin_properties  ACE_ENV_ARG_DECL)
{
  ACE_NEW_THROW_EX (this->buffering_strategy_,
                    TAO_NS_Buffering_Strategy (*msg_queue (), admin_properties, 1),
                    CORBA::NO_MEMORY ());

  long flags = THR_NEW_LWP | THR_JOINABLE;

  flags |=
    TAO_NS_PROPERTIES::instance()->scope_policy () |
    TAO_NS_PROPERTIES::instance()->sched_policy ();

  // Become an active object.
  if (this->ACE_Task <ACE_NULL_SYNCH>::activate (flags,
                                            tp_params.static_threads,
                                            0,
                                            ACE_THR_PRI_OTHER_DEF) == -1)
    {
      if (TAO_debug_level > 0)
        {
          if (ACE_OS::last_error () == EPERM)
            ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("Insufficient privilege.\n")));
          else
            ACE_DEBUG ((LM_ERROR,
                        ACE_TEXT ("(%t) task activation at priority %d failed\n")
                        ACE_TEXT ("exiting!\n%a"),
                        tp_params.default_priority));
        }

        ACE_THROW (CORBA::BAD_PARAM ());
    }
}

void
TAO_NS_ThreadPool_Task::exec (TAO_NS_Method_Request& method_request)
{
  TAO_NS_Method_Request& request_copy = *method_request.copy ();

  if (this->buffering_strategy_->enqueue (request_copy) == -1)
    {
      if (TAO_debug_level > 0)
        ACE_DEBUG ((LM_DEBUG, "NS_ThreadPool_Task (%P|%t) - "
                    "failed to enqueue\n"));
    }
}

int
TAO_NS_ThreadPool_Task::svc (void)
{
  TAO_NS_Method_Request* method_request;

  while (!shutdown_)
    {
      ACE_TRY_NEW_ENV
        {
          ACE_Time_Value* dequeue_blocking_time = 0;
          ACE_Time_Value earliest_time;

          if (!this->timer_.timer_queue_->is_empty ())
            {
              earliest_time = this->timer_.timer_queue_->earliest_time ();
              dequeue_blocking_time = &earliest_time;
            }

          // Dequeue 1 item
          int result = buffering_strategy_->dequeue (method_request, dequeue_blocking_time);

          if (result > 0)
            {
              method_request->execute (ACE_ENV_SINGLE_ARG_PARAMETER);
              ACE_TRY_CHECK;

              ACE_Message_Block::release (method_request);
            }
          else if (errno == ETIME)
            {
              this->timer_.timer_queue_->expire ();
            }
          else if (result == -1)
            {
              if (TAO_debug_level > 0)
                ACE_DEBUG ((LM_DEBUG, "ThreadPool_Task dequeue failed\n"));
            }
        }
      ACE_CATCHANY
        {
          ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                               "ThreadPool_Task (%P|%t) exception in method request\n");
        }
      ACE_ENDTRY;
    } /* while */

  return 0;
}

void
TAO_NS_ThreadPool_Task::shutdown (void)
{
  this->shutdown_ = 1;

  this->buffering_strategy_->shutdown ();

  return;
}

int
TAO_NS_ThreadPool_Task::close (u_long /*flags*/)
{
  if (this->thr_count () == 0)
    delete this;

  return 0;
}

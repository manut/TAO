// $Id$

#include "tao/Leader_Follower_Flushing_Strategy.h"
#include "tao/LF_Follower.h"
#include "tao/Leader_Follower.h"
#include "tao/Transport.h"
#include "tao/Queued_Message.h"
#include "tao/ORB_Core.h"

ACE_RCSID (tao,
           Leader_Follower_Flushing_Strategy,
           "$Id$")


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

int
TAO_Leader_Follower_Flushing_Strategy::schedule_output (TAO_Transport *transport)
{
  return transport->schedule_output_i ();
}

int
TAO_Leader_Follower_Flushing_Strategy::cancel_output (
    TAO_Transport *transport
  )
{
  return transport->cancel_output_i ();
}

int
TAO_Leader_Follower_Flushing_Strategy::flush_message (
    TAO_Transport *transport,
    TAO_Queued_Message *msg,
    ACE_Time_Value *max_wait_time
  )
{
  TAO_Leader_Follower &leader_follower =
    transport->orb_core ()->leader_follower ();
  return leader_follower.wait_for_event (msg, transport, max_wait_time);
}

int
TAO_Leader_Follower_Flushing_Strategy::flush_transport (
    TAO_Transport *transport
  )
{
  // @todo This is not the right way to do this....

  try
    {
      TAO_ORB_Core *orb_core = transport->orb_core ();

      while (!transport->queue_is_empty ())
        {
          int result = orb_core->run (0, 1);

          if (result == -1)
            return -1;
        }
    }
  catch ( ::CORBA::Exception&)
    {
      return -1;
    }

  return 0;
}

TAO_END_VERSIONED_NAMESPACE_DECL

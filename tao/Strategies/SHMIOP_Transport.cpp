// This may look like C, but it's really -*- C++ -*-
// $Id$

#include "SHMIOP_Transport.h"

#if defined (TAO_HAS_SHMIOP) && (TAO_HAS_SHMIOP != 0)

ACE_RCSID (Strategies, SHMIOP_Transport, "$Id$")

#include "SHMIOP_Connect.h"
#include "SHMIOP_Profile.h"
#include "tao/Timeprobe.h"
#include "tao/CDR.h"
#include "tao/Transport_Mux_Strategy.h"
#include "tao/Wait_Strategy.h"
#include "tao/Sync_Strategies.h"
#include "tao/Stub.h"
#include "tao/ORB_Core.h"
#include "tao/debug.h"

#include "tao/GIOP_Message_Lite.h"
#include "tao/GIOP_Message_Connectors.h"

#if !defined (__ACE_INLINE__)
# include "SHMIOP_Transport.i"
#endif /* ! __ACE_INLINE__ */

#if defined (ACE_ENABLE_TIMEPROBES)

static const char *TAO_Transport_Timeprobe_Description[] =
  {
    "SHMIOP_Transport::send - start",
    "SHMIOP_Transport::send - end",

    "SHMIOP_Transport::receive - start",
    "SHMIOP_Transport::receive - end",

    "SHMIOP_Client_Transport::start_request - start",
    "SHMIOP_Client_Transport::start_request - end"
  };

enum
  {
    TAO_SHMIOP_TRANSPORT_SEND_START = 1200,
    TAO_SHMIOP_TRANSPORT_SEND_END,

    TAO_SHMIOP_TRANSPORT_RECEIVE_START,
    TAO_SHMIOP_TRANSPORT_RECEIVE_END,

    TAO_SHMIOP_CLIENT_TRANSPORT_START_REQUEST_START,
    TAO_SHMIOP_CLIENT_TRANSPORT_START_REQUEST_END
  };


// Setup Timeprobes
ACE_TIMEPROBE_EVENT_DESCRIPTIONS (TAO_Transport_Timeprobe_Description,
                                  TAO_SHMIOP_TRANSPORT_SEND_START);

#endif /* ACE_ENABLE_TIMEPROBES */

TAO_SHMIOP_Transport::TAO_SHMIOP_Transport (TAO_ORB_Core *orb_core)
  : TAO_Transport (TAO_TAG_SHMEM_PROFILE,
                   orb_core)
{
}

TAO_SHMIOP_Transport::~TAO_SHMIOP_Transport (void)
{
}



ACE_HANDLE
TAO_SHMIOP_Transport::handle (void)
{
  return this->service_handler ()->get_handle ();
}


ACE_Event_Handler *
TAO_SHMIOP_Transport::event_handler (void)
{
  return this->service_handler ();
}

// ****************************************************************

TAO_SHMIOP_Server_Transport::
    TAO_SHMIOP_Server_Transport (TAO_SHMIOP_Server_Connection_Handler *handler,
                                 TAO_ORB_Core* orb_core)
  : TAO_SHMIOP_Transport (orb_core),
    message_state_ (orb_core),
    handler_ (handler)
{
}

TAO_SHMIOP_Server_Transport::~TAO_SHMIOP_Server_Transport (void)
{
}

int
TAO_SHMIOP_Server_Transport::idle (void)
{
  return this->handler_->make_idle();
}

TAO_SHMIOP_SVC_HANDLER *
TAO_SHMIOP_Server_Transport::service_handler (void)
{
  return this->handler_;
}

void
TAO_SHMIOP_Server_Transport::close_connection (void)
{
  this->service_handler ()->handle_close ();
  this->handler_->purge_entry ();
}

// ****************************************************************

TAO_SHMIOP_Client_Transport::
    TAO_SHMIOP_Client_Transport (TAO_SHMIOP_Client_Connection_Handler *handler,
                                 TAO_ORB_Core *orb_core)
  :  TAO_SHMIOP_Transport (orb_core),
     handler_ (handler),
     client_mesg_factory_ (0),
     orb_core_ (orb_core),
     lite_flag_ (0),
     params_ ()
{
}

TAO_SHMIOP_Client_Transport::~TAO_SHMIOP_Client_Transport (void)
{
  delete this->client_mesg_factory_;
}

int
TAO_SHMIOP_Client_Transport::idle (void)
{
  return this->handler_->make_idle();
}


void
TAO_SHMIOP_Client_Transport::start_request (TAO_ORB_Core * /*orb_core*/,
                                            TAO_Target_Specification & /*spec */,
                                            TAO_OutputCDR &output,
                                            CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_FUNCTION_PP_TIMEPROBE (TAO_SHMIOP_CLIENT_TRANSPORT_START_REQUEST_START);

  if (this->client_mesg_factory_->write_protocol_header
      (TAO_PLUGGABLE_MESSAGE_REQUEST,
       output) == 0)
    ACE_THROW (CORBA::MARSHAL ());
}

void
TAO_SHMIOP_Client_Transport::start_locate (TAO_ORB_Core * /*orb_core*/,
                                           TAO_Target_Specification &spec,
                                           TAO_Operation_Details &opdetails,
                                           TAO_OutputCDR &output,
                                           CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // See this is GIOP way of doing this..But anyway SHMIOP will be tied
  // up with GIOP.
  if (this->client_mesg_factory_->write_protocol_header
      (TAO_PLUGGABLE_MESSAGE_LOCATEREQUEST,
       output) == 0)
    ACE_THROW (CORBA::MARSHAL ());

  if (this->client_mesg_factory_->write_message_header (opdetails,
                                                        TAO_PLUGGABLE_MESSAGE_LOCATE_REQUEST_HEADER,
                                                        spec,
                                                        output) == 0)
    ACE_THROW (CORBA::MARSHAL ());
}

int
TAO_SHMIOP_Client_Transport::send_request (TAO_Stub *stub,
                                           TAO_ORB_Core *orb_core,
                                           TAO_OutputCDR &stream,
                                           int two_way,
                                           ACE_Time_Value *max_wait_time)
{
  if (this->ws_->sending_request (orb_core,
                                  two_way) == -1)
    return -1;

  if (this->client_mesg_factory_->send_message (this,
                                                stream,
                                                max_wait_time,
                                                stub,
                                                two_way) == -1)
    return -1;
  return this->idle_after_send ();
}

// Return 0, when the reply is not read fully, 1 if it is read fully.
// @@ This code should go in the TAO_Transport class is repeated for
//    each transport!!
int
TAO_SHMIOP_Client_Transport::handle_client_input (int /* block */,
                                                  ACE_Time_Value *max_wait_time)
{

  // Notice that the message_state is only modified in one thread at a
  // time because the reactor does not call handle_input() for the
  // same Event_Handler in two threads at the same time.

  // Get the message state from the Transport Mux Strategy.
  TAO_GIOP_Message_State* message_state =
    this->tms_->get_message_state ();

  if (message_state == 0)
    {
      if (TAO_debug_level > 0)
        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("TAO (%P|%t) SHMIOP_Transport::handle_client_input -")
                    ACE_TEXT (" nil message state\n")));
      this->tms_->connection_closed ();
      return -1;
    }

  int result = this->client_mesg_factory_->handle_input (this,
                                                         this->orb_core_,
                                                         *message_state,
                                                         max_wait_time);
  if (result == -1)
    {
      if (TAO_debug_level > 0)
        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("TAO (%P|%t) - %p\n"),
                    ACE_TEXT ("SHMIOP_Transport::handle_client_input, handle_input")));
      this->tms_->connection_closed ();
      return -1;
    }
  if (result == 0)
    return result;

  // OK, the complete message is here...

  result = this->client_mesg_factory_->parse_reply (*message_state,
                                                    this->params_);

  if (result == -1)
    {
      if (TAO_debug_level > 0)
        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("TAO (%P|%t) - %p\n"),
                    ACE_TEXT ("SHMIOP_Transport::handle_client_input, parse reply")));
      message_state->reset ();
      this->tms_->connection_closed ();
      return -1;
    }

  result =
    this->tms_->dispatch_reply (this->params_.request_id_,
                                this->params_.reply_status_,
                                message_state->giop_version,
                                this->params_.svc_ctx_,
                                message_state);

  if (result == -1)
    {
      if (TAO_debug_level > 0)
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("TAO (%P|%t) : SHMIOP_Client_Transport::")
                    ACE_TEXT ("handle_client_input - ")
                    ACE_TEXT ("dispatch reply failed\n")));
      message_state->reset ();
      this->tms_->connection_closed ();
      return -1;
    }

  if (result == 0)
    {
      message_state->reset ();
      return 0;
    }

  // This is a NOOP for the Exclusive request case, but it actually
  // destroys the stream in the muxed case.
  this->tms_->destroy_message_state (message_state);

  return result;
}

int
TAO_SHMIOP_Client_Transport::register_handler (void)
{
  // @@ It seems like this method should go away, the right reactor is
  //    picked at object creation time.
  ACE_Reactor *r = this->orb_core ()->reactor ();
  if (r == this->service_handler ()->reactor ())
    return 0;

  // About to be registered with the reactor, so bump the ref
  // count
  this->handler_->incr_ref_count ();

  // Set the flag in the Connection Handler
  this->handler_->is_registered (1);

  // Register the handler with the reactor
  return  r->register_handler (this->handler_,
                               ACE_Event_Handler::READ_MASK);
}


int
TAO_SHMIOP_Client_Transport::messaging_init (CORBA::Octet major,
                                             CORBA::Octet minor)
{
  if (this->client_mesg_factory_ == 0)
    {
      if (this->lite_flag_)
        {
          ACE_NEW_RETURN  (this->client_mesg_factory_,
                           TAO_GIOP_Message_Lite (this->orb_core_),
                           -1);
        }
      else if (major == TAO_DEF_GIOP_MAJOR)
        {
          if (minor > TAO_DEF_GIOP_MINOR)
            minor = TAO_DEF_GIOP_MINOR;
          switch (minor)
            {
            case 0:
              ACE_NEW_RETURN  (this->client_mesg_factory_,
                               TAO_GIOP_Message_Connector_10,
                               0);
              break;
            case 1:
              ACE_NEW_RETURN  (this->client_mesg_factory_,
                           TAO_GIOP_Message_Connector_11,
                           0);
              break;
            case 2:
              ACE_NEW_RETURN  (this->client_mesg_factory_,
                               TAO_GIOP_Message_Connector_12,
                               0);
              break;
            default:
              if (TAO_debug_level > 0)
                {
                  ACE_ERROR_RETURN ((LM_ERROR,
                                     ACE_TEXT ("(%N|%l|%p|%t) No matching minor version number \n")),
                                    0);
                }
            }
        }
      else
        {
          if (TAO_debug_level > 0)
            {
              ACE_ERROR_RETURN ((LM_ERROR,
                                 ACE_TEXT ("(%N|%l|%p|%t) No matching major version number \n")),
                                0);
            }
        }
    }

  return 1;
}

CORBA::Boolean
TAO_SHMIOP_Client_Transport::send_request_header (TAO_Operation_Details &opdetails,
                                                  TAO_Target_Specification &spec,
                                                  TAO_OutputCDR & msg)
{
  // We are going to pass on this request to the underlying messaging
  // layer. It should take care of this request
    CORBA::Boolean retval =
      this->client_mesg_factory_->write_message_header (opdetails,
                                                        TAO_PLUGGABLE_MESSAGE_REQUEST_HEADER,
                                                        spec,
                                                        msg);

  return retval;
}


TAO_SHMIOP_SVC_HANDLER *
TAO_SHMIOP_Client_Transport::service_handler (void)
{
  return this->handler_;
}

void
TAO_SHMIOP_Client_Transport::close_connection (void)
{
  this->service_handler ()->handle_close ();

  this->handler_->purge_entry ();
}

// *********************************************************************

ssize_t
TAO_SHMIOP_Transport::send (TAO_Stub *stub,
                            int two_way,
                            const ACE_Message_Block *message_block,
                            const ACE_Time_Value *max_wait_time)
{
  if (stub == 0 || two_way)
    {
      return this->send (message_block,
                         max_wait_time);
    }
  else
    {
      TAO_Sync_Strategy &sync_strategy = stub->sync_strategy ();

      return sync_strategy.send (*this,
                                 *stub,
                                 message_block,
                                 max_wait_time);
    }
}

ssize_t
TAO_SHMIOP_Transport::send (const ACE_Message_Block *message_block,
                            const ACE_Time_Value *max_wait_time,
                            size_t *)
{
  TAO_FUNCTION_PP_TIMEPROBE (TAO_SHMIOP_TRANSPORT_SEND_START);
  return this->service_handler ()->peer ().send (message_block,
                                                 max_wait_time);
}

ssize_t
TAO_SHMIOP_Transport::send (const u_char *buf,
                            size_t len,
                            const ACE_Time_Value *max_wait_time)
{
  TAO_FUNCTION_PP_TIMEPROBE (TAO_SHMIOP_TRANSPORT_SEND_START);

  return this->service_handler ()->peer ().send (buf,
                                                 len,
                                                 max_wait_time);
}

ssize_t
TAO_SHMIOP_Transport::recv (char *buf,
                            size_t len,
                            const ACE_Time_Value *max_wait_time)
{
  TAO_FUNCTION_PP_TIMEPROBE (TAO_SHMIOP_TRANSPORT_RECEIVE_START);

  return this->service_handler ()->peer ().recv (buf,
                                                 len,
                                                 max_wait_time);
}

// Default action to be taken for send request.
int
TAO_SHMIOP_Transport::send_request (TAO_Stub *,
                                    TAO_ORB_Core *  /* orb_core */,
                                    TAO_OutputCDR & /* stream   */,
                                    int             /* twoway   */,
                                    ACE_Time_Value * /* max_wait_time */)
{
  return -1;
}

CORBA::Boolean
TAO_SHMIOP_Transport::send_request_header (TAO_Operation_Details & /**/,
                                           TAO_Target_Specification & /*spec */ ,
                                           TAO_OutputCDR & /*msg*/)
{
  // We should never be here. So return an error.
  return 0;
}


#endif /* TAO_HAS_SHMIOP && TAO_HAS_SHMIOP != 0 */

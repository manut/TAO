// -*- C++ -*-
// $Id$

#include "Transport.h"

#include "Exception.h"
#include "ORB_Core.h"
#include "Client_Strategy_Factory.h"
#include "Wait_Strategy.h"
#include "Transport_Mux_Strategy.h"
#include "Stub.h"
#include "Sync_Strategies.h"
#include "Connection_Handler.h"

#if !defined (__ACE_INLINE__)
# include "Transport.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(tao, Transport, "$Id$")

// Constructor.
TAO_Transport::TAO_Transport (CORBA::ULong tag,
                              TAO_ORB_Core *orb_core)
  : ACE_Refcountable (1)
  , tag_ (tag)
  , orb_core_ (orb_core)
  , cache_map_entry_ (0)
  , buffering_queue_ (0)
  , buffering_timer_id_ (0)
  , bidirectional_flag_ (-1)
{
  TAO_Client_Strategy_Factory *cf =
    this->orb_core_->client_factory ();

  // Create WS now.
  this->ws_ = cf->create_wait_strategy (this);

  // Create TMS now.
  this->tms_ = cf->create_transport_mux_strategy (this);
}

TAO_Transport::~TAO_Transport (void)
{
  delete this->ws_;
  this->ws_ = 0;

  delete this->tms_;
  this->tms_ = 0;

  delete this->buffering_queue_;
}

ssize_t
TAO_Transport::send_or_buffer (TAO_Stub *stub,
                               int two_way,
                               const ACE_Message_Block *message_block,
                               const ACE_Time_Value *max_wait_time)
{
  if (stub == 0 || two_way)
    return this->send (message_block, max_wait_time);

  TAO_Sync_Strategy &sync_strategy = stub->sync_strategy ();

  return sync_strategy.send (*this,
                             *stub,
                             message_block,
                             max_wait_time);
}

ssize_t
TAO_Transport::send_buffered_messages (const ACE_Time_Value *max_wait_time)
{
  // Make sure we have a buffering queue and there are messages in it.
  if (this->buffering_queue_ == 0 ||
      this->buffering_queue_->is_empty ())
    return 1;

  // Get the first message from the queue.
  ACE_Message_Block *queued_message = 0;
  ssize_t result = this->buffering_queue_->peek_dequeue_head (queued_message);

  // @@ What to do here on failures?
  ACE_ASSERT (result != -1);

  // Actual network send.
  size_t bytes_transferred = 0;
  result = this->send (queued_message,
                       max_wait_time,
                       &bytes_transferred);

  // Cannot send completely: timed out.
  if (result == -1 &&
      errno == ETIME)
    {
      if (bytes_transferred > 0)
        {
          // If successful in sending some of the data, reset the
          // queue appropriately.
          this->reset_queued_message (queued_message,
                                      bytes_transferred);

          // Indicate some success.
          return bytes_transferred;
        }

      // Since we queue up the message, this is not an error.  We can
      // try next time around.
      return 1;
    }

  // EOF or other errors.
  if (result == -1 ||
      result == 0)
    {
      this->dequeue_all ();
      return -1;
    }

  // If successful in sending data, reset the queue appropriately.
  this->reset_queued_message (queued_message,
                              bytes_transferred);

  // Everything was successfully delivered.
  return result;
}

void
TAO_Transport::reset_sent_message (ACE_Message_Block *message_block,
                                   size_t bytes_delivered)
{
  this->reset_message (message_block,
                       bytes_delivered,
                       0);
}

void
TAO_Transport::reset_queued_message (ACE_Message_Block *message_block,
                                     size_t bytes_delivered)
{
  this->reset_message (message_block,
                       bytes_delivered,
                       1);
}

void
TAO_Transport::reset_message (ACE_Message_Block *message_block,
                              size_t bytes_delivered,
                              int queued_message)
{
  while (bytes_delivered != 0)
    {
      // Our current message block chain.
      ACE_Message_Block *current_message_block = message_block;

      int completely_delivered_current_message_block_chain = 0;

      while (current_message_block != 0 &&
             bytes_delivered != 0)
        {
          size_t current_message_block_length =
            current_message_block->length ();

          int completely_delivered_current_message_block =
            bytes_delivered >= current_message_block_length;

          size_t adjustment_size =
            ACE_MIN (current_message_block_length, bytes_delivered);

          // Reset according to send size.
          current_message_block->rd_ptr (adjustment_size);

          // If queued message, adjust the queue.
          if (queued_message)
            // Hand adjust <message_length>.
            this->buffering_queue_->message_length (
              this->buffering_queue_->message_length () - adjustment_size);

          // Adjust <bytes_delivered>.
          bytes_delivered -= adjustment_size;

          if (completely_delivered_current_message_block)
            {
              // Next message block in the continuation chain.
              current_message_block = current_message_block->cont ();

              if (current_message_block == 0)
                completely_delivered_current_message_block_chain = 1;
            }
        }

      if (completely_delivered_current_message_block_chain)
        {
          // Go to the next message block chain.
          message_block = message_block->next ();

          // If queued message, adjust the queue.
          if (queued_message)
            // Release this <current_message_block>.
            this->dequeue_head ();
        }
    }
}

int
TAO_Transport::idle_after_send (void)
{
  return this->tms ()->idle_after_send ();
}

int
TAO_Transport::idle_after_reply (void)
{
  return this->tms ()->idle_after_reply ();
}

TAO_SYNCH_CONDITION *
TAO_Transport::leader_follower_condition_variable (void)
{
  return this->wait_strategy ()->leader_follower_condition_variable ();
}

int
TAO_Transport::tear_listen_point_list (TAO_InputCDR &)
{
  ACE_NOTSUP_RETURN(-1);
}

int
TAO_Transport::reactor_signalling (void)
{
  return 0;
}

void
TAO_Transport::connection_handler_closing (void)
{
  this->transition_handler_state ();

  // purge_entry on the Transport_Cache
  if (this->cache_map_entry_ != 0) {
    this->orb_core_->transport_cache ().purge_entry (this->cache_map_entry_);
  }

  // This should be the last thing we do here
  TAO_Transport::release(this);
}

TAO_Connection_Handler*
TAO_Transport::connection_handler (void) const
{
  return 0;
}

TAO_Transport*
TAO_Transport::_duplicate(TAO_Transport* transport)
{
  if (transport != 0) {
    transport->increment();
#if 0
ACE_hthread_t self;
ACE_OS::thr_self(self);
printf("DEBUG: Thread == %2d %s (%x) storing %8x TAO_Transport::_duplicate count == %d\n", self, what, who, transport, transport->refcount());
#endif
  }
  return transport;
}

void
TAO_Transport::release(TAO_Transport* transport)
{
  if (transport != 0) {
    int count = transport->decrement();
#if 0
ACE_hthread_t self;
ACE_OS::thr_self(self);
printf("DEBUG: Thread == %2d %s (%x) releasing %8x TAO_Transport::release count == %d\n", self, what, who, transport, count);
#endif
    if (count == 0) {
      delete transport;
    }
    else if (count < 0) {
      ACE_DEBUG ((LM_DEBUG,
                  "Refrence count in TAO_Transport::release "
                  "is less than zero: %d\n", count));
      ACE_OS::abort ();
    }
  }
}

int
TAO_Transport::recache_transport (TAO_Transport_Descriptor_Interface *desc)
{
  // First purge our entry
  if (this->cache_map_entry_ != 0) {
    this->orb_core_->transport_cache ().purge_entry (this->cache_map_entry_);
  }

  // Then add ourselves to the cache
  return this->orb_core_->transport_cache ().cache_transport (desc,
                                                              this);
}

void
TAO_Transport::mark_invalid (void)
{
  if (this->cache_map_entry_)
    this->cache_map_entry_->int_id_.recycle_state
      (ACE_RECYCLABLE_PURGABLE_BUT_NOT_IDLE);
}

int
TAO_Transport::make_idle (void)
{
  return this->orb_core_->transport_cache ().make_idle (this->cache_map_entry_);
}

void
TAO_Transport::close_connection (void)
{
  // Call handle close on the connection handler.
  // The event handler is as common as we can get
  if (this->event_handler () != 0) {
    this->event_handler ()->handle_close (ACE_INVALID_HANDLE,
                                          ACE_Event_Handler::ALL_EVENTS_MASK);
  }

  // Purge the entry
  if (this->cache_map_entry_ != 0) {
    this->orb_core_->transport_cache ().purge_entry (this->cache_map_entry_);
    this->cache_map_entry_ = 0;
  }
}

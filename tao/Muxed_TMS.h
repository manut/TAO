// This may look like C, but it's really -*- C++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//     TAO
//
// = AUTHOR
//     Alexander Babu Arulanthu <alex@cs.wustl.edu>
//
// ============================================================================

#ifndef TAO_MUXED_TMS_H
#define TAO_MUXED_TMS_H
#include "ace/pre.h"

#include "tao/Transport_Mux_Strategy.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Functor.h"
#include "ace/Hash_Map_Manager.h"

class TAO_Export TAO_Muxed_TMS : public TAO_Transport_Mux_Strategy
{
  // = DESCRIPTION
  //   Using this strategy a single connection can have multiple
  //   outstanding requests.
  //   @@ Can the performance of the demuxer be made more predictable,
  //   for example, using the request id as an active demux key?
  //   NOTE: check the OMG resolutions about bidirectional
  //   connections, it is possible that the request ids can only
  //   assume even or odd values.
  //

public:
  TAO_Muxed_TMS (TAO_Transport *transport);
  // Constructor.

  virtual ~TAO_Muxed_TMS (void);
  // Destructor.

  virtual CORBA::ULong request_id (void);
  // Generate and return an unique request id for the current
  // invocation.

  // = Please read the documentation in the TAO_Transport_Mux_Strategy
  //   class.
  virtual int bind_dispatcher (CORBA::ULong request_id,
                               TAO_Reply_Dispatcher *rh);
  virtual void unbind_dispatcher (CORBA::ULong request_id);
  virtual int dispatch_reply (CORBA::ULong request_id,
                              CORBA::ULong reply_status,
                              const TAO_GIOP_Version& version,
                              IOP::ServiceContextList& reply_ctx,
                              TAO_GIOP_Message_State* message_state);
  virtual TAO_GIOP_Message_State *get_message_state (void);
  virtual void destroy_message_state (TAO_GIOP_Message_State *);
  virtual int idle_after_send (void);
  virtual int idle_after_reply (void);
  virtual void connection_closed (void);

protected:
  ACE_SYNCH_MUTEX lock_;
  // Lock to protect the state of this class

  CORBA::ULong request_id_generator_;
  // Used to generate a different request_id on each call to
  // request_id().

  typedef ACE_Hash_Map_Manager_Ex <CORBA::ULong,
                                   TAO_Reply_Dispatcher *,
                                   ACE_Hash <CORBA::ULong>,
                                   ACE_Equal_To <CORBA::ULong>,
                                   ACE_Null_Mutex> REQUEST_DISPATCHER_TABLE;

  REQUEST_DISPATCHER_TABLE dispatcher_table_;
  // Table of <Request ID, Reply Dispatcher> pairs.

  TAO_ORB_Core *orb_core_;
  // Keep track of the orb core pointer. We need to this to create the
  // Reply Dispatchers.

  TAO_GIOP_Message_State *message_state_;
  // Message state where the current input message is being read. This
  // is created at start of each incoming message. When that message
  // is read, the message is processed and for the next message a new
  // message state is created.

  // @@ Having members of type TAO_GIOP* indicates that we
  // (Transport_Mux_Strategy) are aware of the underlying messaging
  // protocol. But for the present let us close our eyes till we are
  // able to iterate on a use case - Bala.
};

#include "ace/post.h"
#endif /* MUXED_TMS_H */

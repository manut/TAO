// -*- C++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//     TAO
//
// = FILENAME
//     GIOP_Message_Acceptors.h
//
// = DESCRIPTION
//   Implementation interface for the Server side of GIOP classes.  
//
// = AUTHOR
//     Balachandran Natarajan <bala@cs.wustl.edu>
//
// ============================================================================
#ifndef TAO_GIOP_MESSAGE_ACCEPTORS
#include "ace/pre.h"
#define TAO_GIOP_MESSAGE_ACCEPTORS

#include "tao/GIOP_Message_Base.h"
#include "tao/GIOP_Utils.h"
#include "tao/GIOP_Message_Accept_State.h"
#include "tao/ORB_Core.h"
#include "tao/debug.h"

class TAO_Export TAO_GIOP_Message_Acceptors:
  public TAO_GIOP_Message_Base
{
  // = TITLE
  //   TAO_GIOP_Message_Acceptors
  // = DESCRIPTION
  //   This class provides a comprehensive set of interfaces for the
  //   server side of the GIOP classes. 
  
public:

  TAO_GIOP_Message_Acceptors (TAO_ORB_Core *orb_core);
  // Ctor

  int process_connector_messages (TAO_Transport *transport,
                                  TAO_ORB_Core *orb_core,
                                  TAO_InputCDR &input,
                                  CORBA::Octet message_type);
  // Processes the messages from the connectors so that they can be
  // passed on to the appropriate states.
  
  int parse_reply (TAO_Message_State_Factory &mesg_state,
                   TAO_Pluggable_Connector_Params &params);
private:
  
  int process_connector_request (TAO_Transport *transport,
                                 TAO_ORB_Core* orb_core,
                                 TAO_InputCDR &input);
  // A request was received on the server side. <transport> is the
  // source of the message (and thus where the  replies should be
  // sent). <orb_core> is the ORB that received the message <input>
  // contains the message <output> can be used to store any responses
  // <request_id> and <response_required> are set as part of the
  // message processing.


  int process_connector_locate (TAO_Transport *transport,
                                TAO_ORB_Core* orb_core,
                                TAO_InputCDR &input);
  // A LocateRequest was received on the server side. <transport> is
  // the source of the message (and thus where the replies should be
  // sent). <orb_core> is the ORB that received the message <input>
  // contains the message <output> can be used to store any responses
  // <request_id> and <response_required> are set as part of the
  // message processing.

  CORBA::Octet major_version (void);
  CORBA::Octet minor_version (void);
  
  CORBA::Boolean make_reply (CORBA::ULong request_id,
                             TAO_OutputCDR &output);
  // This would prepare a version specific reply to the
  // messages from the client. The type of reply would be context
  // sensitive. Only the common stuff for all the replies to be
  // sent would be handled.
  
  int make_send_locate_reply (TAO_Transport *transport,
                              TAO_GIOP_Locate_Request_Header &request,
                              TAO_GIOP_Locate_Status_Msg &status);
  // As on date 1.1 & 1.2 seem to have similar headers. Til an
  // unmanageable difference comes let them be implemented here. 

  int send_reply_exception (TAO_Transport *transport,
                            TAO_ORB_Core* orb_core,
                            CORBA::ULong request_id,
                            CORBA::Exception *x);
  // We must send a LocateReply through <transport>, this request
  // resulted in some kind of exception.
  
  int validate_version (TAO_GIOP_Message_State *state);
  
  void set_state (CORBA::Octet def_major,
                  CORBA::Octet def_minor);
  
  TAO_GIOP_Message_Accept_State *accept_state_;
  // This indicates the strategy that we are using for this request
  
  TAO_GIOP_Message_Accept_Impl implementations_;
  // Different strategies that we know
  
  TAO_OutputCDR output_;
  // The output CDR stream
  
  char repbuf_[ACE_CDR::DEFAULT_BUFSIZE];
  // A buffer that we will use to initialise the CDR stream

  // Quoting Carlos,
  // Remember that the same connection could receive multiple
  // requests concurrently.  Currently the ORB cannot do this, but we
  // want to do it in the future....
 
  // The above will not work for the case that Carlos mentions, but
  // till then we can have it here. This gets us better performance.
  
  ////////////////////////////////////////////////////
  // Inherited methods. Should not be here in the first place? 
  ////////////////////////////////////////////////////
  CORBA::Boolean 
  write_request_header (const TAO_Operation_Details &opdetails,
                        TAO_Target_Specification &spec,
                        TAO_OutputCDR &msg);

  CORBA::Boolean
  write_locate_request_header (CORBA::ULong request_id,
                               TAO_Target_Specification &spec,
                               TAO_OutputCDR &msg);
  ///////////////////////////////////////////////////
};

#if defined (__ACE_INLINE__)
# include "tao/GIOP_Message_Acceptors.i"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"
#endif /*TAO_GIOP_MESSAGE_ACCEPTORS*/

// -*- C++ -*-
// $Id$


// ============================================================================
//
// = LIBRARY
//   TAO
//
// = FILENAME
//   Protocol_Factory.h
//
// = AUTHOR
//   Fred Kuhns <fredk@cs.wustl.edu>
//
// ============================================================================

#ifndef TAO_PROTOCOL_FACTORY_H
#define TAO_PROTOCOL_FACTORY_H
#include "ace/pre.h"

#include "corbafwd.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Service_Object.h"

class TAO_Acceptor;
class TAO_Connector;
class ACE_CString;

class TAO_Export TAO_Protocol_Factory : public ACE_Service_Object
{
public:
  TAO_Protocol_Factory (CORBA::ULong tag);
  virtual ~TAO_Protocol_Factory (void);

  virtual int init (int argc, char *argv[]);
  // Initialization hook.

  CORBA::ULong tag (void) const;
  // The protocol tag, each concrete class will have a specific tag
  // value.

  virtual int match_prefix (const ACE_CString &prefix);
  // Verify prefix is a match

  virtual const char *prefix (void) const;
  // Returns the prefix used by the protocol.

  virtual char options_delimiter (void) const;
  // Return the character used to mark where an endpoint ends and
  // where its options begin.

  // Factory methods
  virtual TAO_Acceptor  *make_acceptor (void);
  // Create an acceptor

  virtual TAO_Connector *make_connector  (void);
  // Create a connector

  virtual int requires_explicit_endpoint (void) const = 0;
  // Some protocols should not create a default endpoint unless the
  // user specifies a -ORBEndpoint option. For example, local IPC
  // (aka UNIX domain sockets) is unable to remove the rendesvouz
  // point if the server crashes.  For those protocols is better to
  // create the endpoint only if the user requests one.

private:
  CORBA::ULong tag_;
  // IOP protocol tag.
};

#include "ace/post.h"
#endif /* TAO_PROTOCOL_FACTORY_H */

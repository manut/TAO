// $Id$
//
// ============================================================================
//
// = LIBRARY
//    TAO
//
// = FILENAME
//    Forwarding_Servant.h
//
// = DESCRIPTION
//    A DSI implementation of a forwarding servant.
//
// = AUTHOR
//    Irfan Pyarali <irfan@cs.wustl.edu>
//
// ============================================================================

#ifndef TAO_FORWARDING_SERVANT_H
#define TAO_FORWARDING_SERVANT_H
#include "ace/pre.h"

#include "tao/orbconf.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (TAO_HAS_MINIMUM_CORBA)

#include "tao/Servant_Base.h"
#include "tao/ORB.h"

class TAO_Forwarding_Servant : public TAO_DynamicImplementation
{
public:

  TAO_Forwarding_Servant (CORBA::Object_ptr forward_to,
                          const char *interface_repository_id_);
  // Constructor

  virtual void invoke (CORBA::ServerRequest_ptr request,
                       CORBA_Environment &ACE_TRY_ENV =
                           TAO_default_environment ());
  // The <invoke> method receives requests issued to any CORBA object
  // incarnated by the DSI servant and performs the processing
  // necessary to execute the request.

  virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &oid,
                                                  PortableServer::POA_ptr poa,
                                                  CORBA_Environment &ACE_TRY_ENV = TAO_default_environment ());
  // The <_primary_interface> method receives an ObjectId value and a
  // POA_ptr as input parameters and returns a valid RepositoryId
  // representing the most-derived interface for that oid.

protected:
  CORBA::Object_var forward_to_;
  // Forward all requests to this object

  CORBA::String_var interface_repository_id_;
  // Here is the interface we support
};

#endif /* TAO_HAS_MINIMUM_CORBA */

#include "ace/post.h"
#endif /* TAO_FORWARDING_SERVANT_H */

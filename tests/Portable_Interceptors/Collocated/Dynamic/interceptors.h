// -*- C++ -*-
//
// $Id$

#ifndef TAO_INTERCEPTORS_H
#define TAO_INTERCEPTORS_H
#include /**/ "ace/pre.h"

#include "tao/PI/PI.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/PI_Server/PI_Server.h"
#include "tao/PortableInterceptorC.h"
#include "tao/LocalObject.h"

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

class Echo_Client_Request_Interceptor
  : public virtual PortableInterceptor::ClientRequestInterceptor,
    public virtual TAO_Local_RefCounted_Object
{
  // = Client-side echo interceptor.  For checking interceptor visually only.
public:

  Echo_Client_Request_Interceptor (void);
  // ctor.
  virtual ~Echo_Client_Request_Interceptor ();
  // dtor.

  virtual char * name (void)
    ACE_THROW_SPEC ((CORBA::SystemException));
  // Canonical name of the interceptor.

  virtual void destroy (void)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void send_poll (
      PortableInterceptor::ClientRequestInfo_ptr)
      ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void send_request (PortableInterceptor::ClientRequestInfo_ptr ri)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableInterceptor::ForwardRequest));

  virtual void receive_other (
        PortableInterceptor::ClientRequestInfo_ptr
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        PortableInterceptor::ForwardRequest
        ));

  virtual void receive_reply (PortableInterceptor::ClientRequestInfo_ptr ri)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void receive_exception (
      PortableInterceptor::ClientRequestInfo_ptr ri)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableInterceptor::ForwardRequest));

  // Some identifiers that are used for error checking
  static CORBA::ULong client_interceptor_check_;
private:
  const char *myname_;
};

class Echo_Server_Request_Interceptor
  : public PortableInterceptor::ServerRequestInterceptor,
    public virtual TAO_Local_RefCounted_Object
{
  // = Server-side echo interceptor.  For checking interceptor visually only.
public:
  Echo_Server_Request_Interceptor (void);
  // cotr.
  ~Echo_Server_Request_Interceptor ();
  // dotr.

  virtual char * name (void)
    ACE_THROW_SPEC ((CORBA::SystemException));
  // Canonical name of the interceptor.

  virtual void destroy (void)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void receive_request_service_contexts (
        PortableInterceptor::ServerRequestInfo_ptr)
    ACE_THROW_SPEC ((
      CORBA::SystemException,
      PortableInterceptor::ForwardRequest
      ));

  virtual void receive_request (PortableInterceptor::ServerRequestInfo_ptr ri)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableInterceptor::ForwardRequest));

  virtual void send_reply (PortableInterceptor::ServerRequestInfo_ptr ri)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void send_exception (PortableInterceptor::ServerRequestInfo_ptr ri)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableInterceptor::ForwardRequest));

  virtual void send_other (
        PortableInterceptor::ServerRequestInfo_ptr
        )
    ACE_THROW_SPEC ((
      CORBA::SystemException,
      PortableInterceptor::ForwardRequest
      ));

  // Some identifiers that are used for error checking
  static CORBA::ULong server_interceptor_check_;

private:
  const char *myname_;
};

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#include /**/ "ace/post.h"
#endif /* TAO_INTERCEPTORS_H */

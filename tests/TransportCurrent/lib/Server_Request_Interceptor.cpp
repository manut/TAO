// -*- C++ -*-

#include "ace/Log_Msg.h"

ACE_RCSID (Current_Test_Lib,
           Server_Request_Interceptor,
           "$Id$")

#include "Server_Request_Interceptor.h"
#include "Server_ORBInitializer.h"

namespace Test
{

  Server_Request_Interceptor::Server_Request_Interceptor (const char* orbid, TEST test)
    : request_count_ (0)
    , orb_id_ (::CORBA::string_dup (orbid))
    , test_ (test)
  {
  }

  Server_Request_Interceptor::~Server_Request_Interceptor (void)
  {
  }

  void
  Server_Request_Interceptor::test_transport_current (const ACE_TCHAR* amethod)
    ACE_THROW_SPEC ((CORBA::SystemException))
  {
    CORBA::String_var name (this->name ());
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%s (%P|%t) Test accessing Transport Current from %s\n"),
                name.in (),
                amethod));

    ++this->request_count_;

     if (TAO_debug_level >=1)
       ACE_DEBUG ((LM_DEBUG,
                   ACE_TEXT ("%s (%P|%t) Getting the ORB\n"),
                   name.in ()));

    int tmpargc = 0;
    CORBA::ORB_var orb = CORBA::ORB_init (tmpargc,
                                          0,
                                          this->orb_id_.in ());
    if (TAO_debug_level >=1)
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("%s (%P|%t) Resolving the TC\n"),
                  name.in ()));

   CORBA::Object_var tcobject =
     orb->resolve_initial_references ("TAO::Transport::Current");

   // Run the test function
   (*this->test_) (orb.in ());

   ACE_DEBUG ((LM_DEBUG,
               ACE_TEXT ("%s (%P|%t) Success - Transport Current from %s\n"),
               name.in (),
               amethod));
  }

  /// queries the status of the test
  bool
  Server_Request_Interceptor::self_test (void)
  {
    return true;
  }


  char *
  Server_Request_Interceptor::name (void)
    ACE_THROW_SPEC ((CORBA::SystemException))
  {
    return CORBA::string_dup ("SRI   ");
  }

  void
  Server_Request_Interceptor::destroy (void)
    ACE_THROW_SPEC ((CORBA::SystemException))
  {
  }

  void
  Server_Request_Interceptor::receive_request_service_contexts (PortableInterceptor::ServerRequestInfo_ptr)
    ACE_THROW_SPEC ((CORBA::SystemException, PortableInterceptor::ForwardRequest))
  {
    test_transport_current ("receive_request_service_contexts");
  }

  void
  Server_Request_Interceptor::receive_request (PortableInterceptor::ServerRequestInfo_ptr)
    ACE_THROW_SPEC ((CORBA::SystemException, PortableInterceptor::ForwardRequest))
  {
    test_transport_current ("receive_request");
  }

  void
  Server_Request_Interceptor::send_reply (PortableInterceptor::ServerRequestInfo_ptr)
    ACE_THROW_SPEC ((CORBA::SystemException))
  {
    test_transport_current ("send_reply");
  }

  void
  Server_Request_Interceptor::send_exception (PortableInterceptor::ServerRequestInfo_ptr)
    ACE_THROW_SPEC ((CORBA::SystemException, PortableInterceptor::ForwardRequest))
  {
    test_transport_current ("send_exception");
  }

  void
  Server_Request_Interceptor::send_other (PortableInterceptor::ServerRequestInfo_ptr)
    ACE_THROW_SPEC ((CORBA::SystemException, PortableInterceptor::ForwardRequest))
  {
    test_transport_current ("send_other");
  }

} /* namespace Test */

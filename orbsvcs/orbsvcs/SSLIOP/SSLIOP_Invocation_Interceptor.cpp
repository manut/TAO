#include "SSLIOP_Invocation_Interceptor.h"

#include "orbsvcs/SecurityLevel2C.h"

#include "tao/ORB_Constants.h"
#include "tao/PortableServer/PS_CurrentC.h"
#include "tao/debug.h"

#if defined(SSLIOP_DEBUG_PEER_CERTIFICATE)
#include <openssl/x509.h>   // @@ For debugging code below
#endif /* DEBUG_PEER_CERTIFICATES */

ACE_RCSID (SSLIOP,
           SSLIOP_Invocation_Interceptor,
           "$Id$")


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO::SSLIOP::Server_Invocation_Interceptor::Server_Invocation_Interceptor (
   ::SSLIOP::Current_ptr current,
   ::Security::QOP qop)
  : ssliop_current_ (::SSLIOP::Current::_duplicate (current)),
    qop_ (qop)
{
}

TAO::SSLIOP::Server_Invocation_Interceptor::~Server_Invocation_Interceptor (
  void)
{
}

char *
TAO::SSLIOP::Server_Invocation_Interceptor::name (
    ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return CORBA::string_dup ("TAO::SSLIOP::Server_Invocation_Interceptor");
}

void
TAO::SSLIOP::Server_Invocation_Interceptor::destroy (
    ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
}


void
TAO::SSLIOP::Server_Invocation_Interceptor::receive_request_service_contexts (
                                              PortableInterceptor::ServerRequestInfo_ptr /*ri*/
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableInterceptor::ForwardRequest))
{
  // The current upcall is not being performed through an SSL
  // connection.  If server is configured to disallow insecure
  // invocations then throw a CORBA::NO_PERMISSION exception.
  // @@ TODO: Once the SecurityManager is implemented, query it
  //          for the current object's
  //          SecureInvocationPolicy of type
  //          SecTargetSecureInvocationPolicy so that we can
  //          accept or reject requests on a per-object basis
  //          instead on a per-endpoint basis.
  CORBA::Boolean const no_ssl =
    this->ssliop_current_->no_context (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  if (TAO_debug_level >= 3)
    ACE_DEBUG ((LM_DEBUG, "SSLIOP (%P|%t) Interceptor (context), ssl=%d\n", !(no_ssl)));

  if (no_ssl && this->qop_ != ::Security::SecQOPNoProtection)
    ACE_THROW (CORBA::NO_PERMISSION ());

#if defined(DEBUG_PEER_CERTIFICATES)
  ACE_TRY
    {
      // If the request was not made through an SSL connection, then
      // this method will throw the SSLIOP::Current::NoContext
      // exception.  Otherwise, it will return a DER encoded X509
      // certificate.
      ::SSLIOP::ASN_1_Cert_var cert =
        this->ssliop_current_->get_peer_certificate (
          ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // @@ The following debugging code works but I don't think that
      //    we should include it since it dumps alot of information,
      //    i.e. prints two lines of information per request.
      if (TAO_debug_level > 1)
        {
          CORBA::Octet *der_cert = cert->get_buffer ();

          X509 *peer = ::d2i_X509 (0, &der_cert, cert->length ());
          if (peer != 0)
            {
              char buf[BUFSIZ] = { 0 };

              ::X509_NAME_oneline (::X509_get_subject_name (peer),
                                   buf,
                                   BUFSIZ);

              ACE_DEBUG ((LM_DEBUG,
                          "(%P|%t) Certificate subject: %s\n",
                          buf));

              ::X509_NAME_oneline (::X509_get_issuer_name (peer),
                                   buf,
                                   BUFSIZ);

              ACE_DEBUG ((LM_DEBUG,
                          "(%P|%t) Certificate issuer: %s\n",
                          buf));


              ::X509_free (peer);
            }
        }
    }
  ACE_CATCH (::SSLIOP::Current::NoContext, exc)
    {
      // The current upcall is not being performed through an SSL
      // connection.  If server is configured to disallow insecure
      // invocations then throw a CORBA::NO_PERMISSION exception.
      // @@ TODO: Once the SecurityManager is implemented, query it
      //          for the current object's
      //          SecureInvocationPolicy of type
      //          SecTargetSecureInvocationPolicy so that we can
      //          accept or reject requests on a per-object basis
      //          instead on a per-endpoint basis.
      if (this->qop_ != ::Security::SecQOPNoProtection)
        ACE_THROW (CORBA::NO_PERMISSION ());
    }
  ACE_ENDTRY;
  ACE_CHECK;
#endif /* DEBUG_PEER_CERTIFICATES */
}


void
TAO::SSLIOP::Server_Invocation_Interceptor::receive_request (
    PortableInterceptor::ServerRequestInfo_ptr ri
    ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableInterceptor::ForwardRequest))
{
  ACE_TRY
  {
    // I would much rather avoid exceptions here, however the
    // ServerRequestInfo provides no other means of getting the
    // effective POA policies (as of CORBA 3.0.3)
    CORBA::Policy_var policy =
      ri->get_server_policy (Security::SecQOPPolicy
                             ACE_ENV_ARG_PARAMETER);
    ACE_TRY_CHECK;

    SecurityLevel2::QOPPolicy_var qop_policy =
      SecurityLevel2::QOPPolicy::_narrow (policy.in ()
                                          ACE_ENV_ARG_PARAMETER);
    ACE_CHECK;

    CORBA::Boolean no_ssl =
      this->ssliop_current_->no_context (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK;

    Security::QOP qop = qop_policy->qop();

    if (TAO_debug_level >= 3)
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT("SSLIOP (%P|%t) Interceptor, ")
                  ACE_TEXT("server policy qop=%x, ssl context=%d\n"),
                  qop, !(no_ssl)));

    // If the active policy requires stronger security guarantees
    // than SecQOPNoProtection and this invocation is not within
    // a secure channel then it cannot proceed.
    if (no_ssl && qop > ::Security::SecQOPNoProtection)
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT("SSLIOP (%P|%t) No SSL context and a server policy")
                  ACE_TEXT(" mandates higher QoP (0x%x), than NoProtection\n"),
                  qop, this->qop_));

      ACE_THROW (CORBA::NO_PERMISSION ());
    }
  }
  ACE_CATCH (CORBA::INV_POLICY, ex)
  {
    // No policy specific set, i.e. assume same as this->qop_
    if (ex.minor () == (CORBA::OMGVMCID | 3))
    {
      if (TAO_debug_level >= 3)
      {
        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT("SSLIOP (%P|%t) No explicit")
                    ACE_TEXT(" server security policy was set.\n")));
      }
      return;
    }

    // If a policy for the given type was not registered via
    // register_policy_factory, this operation (get_server_policy)
    // will raise INV_POLICY with a standard minor code of 3.
    // Anything else gets re-thrown.
    ACE_RE_THROW;
  }
  ACE_ENDTRY;
}

void
TAO::SSLIOP::Server_Invocation_Interceptor::send_reply (
    PortableInterceptor::ServerRequestInfo_ptr /* ri */
    ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
}

void
TAO::SSLIOP::Server_Invocation_Interceptor::send_exception (
    PortableInterceptor::ServerRequestInfo_ptr /* ri */
    ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableInterceptor::ForwardRequest))
{
}

void
TAO::SSLIOP::Server_Invocation_Interceptor::send_other (
    PortableInterceptor::ServerRequestInfo_ptr /* ri */
    ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableInterceptor::ForwardRequest))
{
}

TAO_END_VERSIONED_NAMESPACE_DECL

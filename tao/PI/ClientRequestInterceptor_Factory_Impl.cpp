/* -*- C++ -*- */

// =================================================================
/**
 * @file ClientRequestInterceptor_Factory_Impl.cpp
 *
 * $Id$
 *
 * @author Johnny Willemsen  <jwillemsen@remedy.nl>
 *
 */
// =================================================================

#include "ClientRequestInterceptor_Factory_Impl.h"
#include "ClientRequestInterceptor_Adapter_Impl.h"

#include "tao/ORB.h"
#include "tao/debug.h"

ACE_RCSID (PI,
           PolicyFactory_Loader,
           "$Id$")

TAO::ClientRequestInterceptor_Adapter*
TAO_ClientRequestInterceptor_Adapter_Factory_Impl::create (void)
//    TAO::ClientRequestInterceptor_List::TYPE & interceptors,
  //  TAO::Invocation_Base *invocation)
{
  TAO::ClientRequestInterceptor_Adapter_Impl* obj = 0;
  ACE_NEW_RETURN (obj,
                  TAO::ClientRequestInterceptor_Adapter_Impl ,//(interceptors, invocation),
                  0);
  return obj;
}

ACE_STATIC_SVC_DEFINE (TAO_ClientRequestInterceptor_Adapter_Factory_Impl,
                       ACE_TEXT ("ClientRequestInterceptor_Adapter_Factory"),
                       ACE_SVC_OBJ_T,
                       &ACE_SVC_NAME (TAO_ClientRequestInterceptor_Adapter_Factory_Impl),
                       ACE_Service_Type::DELETE_THIS | ACE_Service_Type::DELETE_OBJ,
                       0)
ACE_FACTORY_DEFINE (TAO_PI, TAO_ClientRequestInterceptor_Adapter_Factory_Impl)

// -*- C++ -*-

//=============================================================================
/**
 *  @file   FT_ProxyAdmin_T.h
 *
 *  $Id$
 *
 *  @author Huang-Ming Huang <hh1@cse.wustl.edu>
 */
//=============================================================================
#ifndef FT_PROXYADMIN_H
#define FT_PROXYADMIN_H

#include "FT_ProxyAdmin_Base.h"
#include "../Utils/ScopeGuard.h"
#include "Request_Context_Repository.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

template <class EC_PROXY_ADMIN, class Proxy,
          class ProxyInterface, class State>
class FT_ProxyAdmin : public FT_ProxyAdmin_Base
{
public:
  typedef typename ProxyInterface::_ptr_type ProxyInterface_ptr;
  typedef typename ProxyInterface::_var_type ProxyInterface_var;

  FT_ProxyAdmin(EC_PROXY_ADMIN* admin,
              PortableServer::POA_var poa);

  ProxyInterface_ptr
      obtain_proxy (ACE_ENV_SINGLE_ARG_DECL_NOT_USED);

  /// this is used for updating the state
  void obtain_proxy (const FtRtecEventChannelAdmin::Operation& op
                    ACE_ENV_ARG_DECL);

  void get_state(State& state ACE_ENV_ARG_DECL);
  void set_state(const State& state ACE_ENV_ARG_DECL);
private:
  EC_PROXY_ADMIN* admin_;
};

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "FT_ProxyAdmin_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("FT_ProxyAdmin_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif

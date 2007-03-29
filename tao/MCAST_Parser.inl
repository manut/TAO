// -*- C++ -*-
//
// $Id$

#if defined ACE_HAS_IP_MULTICAST

#include "tao/default_ports.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
TAO_MCAST_Parser::TAO_MCAST_Parser (void)
  : mcast_address_ ()
  , mcast_port_ (TAO_DEFAULT_NAME_SERVER_REQUEST_PORT)
  , mcast_nic_ ()
  , mcast_ttl_ (1)
  , service_name_ ()
{
}

TAO_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_IP_MULTICAST */

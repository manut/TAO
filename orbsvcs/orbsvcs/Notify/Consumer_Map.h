/* -*- C++ -*- */
/**
 *  @file Consumer_Map.h
 *
 *  $Id$
 *
 *  @author Pradeep Gore <pradeep@oomworks.com>
 *
 *
 */

#ifndef TAO_Notify_CONSUMER_MAP_H
#define TAO_Notify_CONSUMER_MAP_H
#include /**/ "ace/pre.h"

#include "notify_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include "Event_Map_T.h"
#include "ProxySupplier.h"

/**
 * @class TAO_Notify_Consumer_Map
 *
 * @brief The Event Map for Consumers.
 *
 */

typedef TAO_Notify_Event_Map_T<TAO_Notify_ProxySupplier, TAO_SYNCH_RW_MUTEX> TAO_Notify_Consumer_Map;

#include /**/ "ace/post.h"
#endif /* TAO_Notify_CONSUMER_MAP_H */

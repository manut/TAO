/**
 * @file EC_Channel_Destroyer.h
 *
 * @author Marina Spivak <marina@atdesk.com>
 *
 * $Id$
 */
#ifndef EC_CHANNEL_DESTROYER__H_
#define EC_CHANNEL_DESTROYER__H_

#include /**/ "event_serv_export.h"
#include "EC_Event_Channel_Base.h"
#include "ace/Auto_Functor.h"

/**
 * @struct TAO_EC_Channel_Destroyer_Functor
 *
 * @brief Implements a functor for the TAO_EC_Channel_Destroyer class.
 */
struct TAO_RTEvent_Serv_Export TAO_EC_Channel_Destroyer_Functor
{
  typedef  TAO_EC_Event_Channel_Base * argument;

  /// Destroy @c event_channel
  void operator() (TAO_EC_Event_Channel_Base * event_channel)
    ACE_THROW_SPEC (());
};

/**
 * @class TAO_EC_Channel_Destroyer
 *
 * @brief Helper class to destroy event channel.
 *
 */
typedef ACE_Utils::Auto_Functor<
            TAO_EC_Event_Channel_Base,
            TAO_EC_Channel_Destroyer_Functor>
        TAO_EC_Channel_Destroyer;


#endif // EC_CHANNEL_DESTROYER__H_

// $Id$

#include "Subscription_Change_Worker.h"

#include "Proxy.h"

ACE_RCSID(Notify, TAO_Subscription_Change_Worker, "$Id$")

TAO_Notify_Subscription_Change_Worker::TAO_Notify_Subscription_Change_Worker (const CosNotification::EventTypeSeq & added, const CosNotification::EventTypeSeq & removed)
:added_ (added), removed_ (removed)
{
}

TAO_Notify_Subscription_Change_Worker::~TAO_Notify_Subscription_Change_Worker ()
{
}

void
TAO_Notify_Subscription_Change_Worker::work (TAO_Notify_Proxy* proxy ACE_ENV_ARG_DECL)
{
  proxy->admin_types_changed (this->added_, this->removed_ ACE_ENV_ARG_PARAMETER);
}

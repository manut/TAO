// $Id$
// ==========================================================================
//
// = LIBRARY
//   Orbsvcs
//
// = FILENAME
//   Notify_Resource_Manager.h
//
// = DESCRIPTION
//   Internal "observer" interfaces for Notify.
//
// = AUTHOR
//    Pradeep Gore <pradeep@cs.wustl.edu>
//
// ==========================================================================

#ifndef TAO_NOTIFY_LISTENERS_H
#define TAO_NOTIFY_LISTENERS_H
#include "ace/pre.h"

#include "Notify_Types.h"

class TAO_Notify_EventListener
{
  // = TITLE
  //   TAO_Notify_EventListener
  //
  // = DESCRIPTION
  //   An entities interested in receiving events can implement this interface
  //   and subscribe with the Event Manager. During subscription, the Listener
  //   must specify what kind of events it is interested in.
  //
 public:
  virtual void dispatch_event (TAO_Notify_Event &event, CORBA::Environment &ACE_TRY_ENV) = 0;
  // Callback methods to supply the event to the listener.
};

class TAO_Notify_UpdateListener
{
 public:
  // = TITLE
  //   TAO_Notify_UpdateListener
  //
  // = DESCRIPTION
  //   All entities interested in receiving subscription and publication
  //   change messages can implement this interface and register it with
  //   the Event Manager to receive updates.
  //
  virtual void dispatch_update (TAO_Notify_EventType_List& added, TAO_Notify_EventType_List& removed, CORBA::Environment &ACE_TRY_ENV) = 0;
  // Callback method to supply updates.
};

#include "ace/post.h"
#endif /* TAO_NOTIFY_LISTENERS_H */

/* -*- C++ -*- */
/**
 *  @file Reactive_Task.h
 *
 *  $Id$
 *
 *  @author Pradeep Gore <pradeep@oomworks.com>
 *
 *
 */

#ifndef TAO_NS_REACTIVE_TASK_H
#define TAO_NS_REACTIVE_TASK_H
#include "ace/pre.h"

#include "notify_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "Worker_Task.h"

/**
 * @class TAO_NS_Reactive_Task
 *
 * @brief A reactive worker task. Simply executes the command in the caller's context.
 *
 */
class TAO_Notify_Export TAO_NS_Reactive_Task : public TAO_NS_Worker_Task
{
public:
  /// Constuctor
  TAO_NS_Reactive_Task (void);

  /// Destructor
  ~TAO_NS_Reactive_Task ();

  /// Exec the request.
  virtual void exec (TAO_NS_Method_Request& method_request);
};

#if defined (__ACE_INLINE__)
#include "Reactive_Task.inl"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"
#endif /* TAO_NS_REACTIVE_TASK_H */

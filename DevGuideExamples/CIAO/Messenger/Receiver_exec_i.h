// $Id$
//
// ****              Code generated by the                 ****
// ****  Component Integrated ACE ORB (CIAO) CIDL Compiler ****
// CIAO has been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// CIDL Compiler has been developed by:
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about CIAO is available at:
//    http://www.dre.vanderbilt.edu/CIAO

#ifndef CIAO_RECEIVER_EXEC_H
#define CIAO_RECEIVER_EXEC_H

#include /**/ "ace/pre.h"

#include "Receiver_svnt.h"
#include "Receiver_exec_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/LocalObject.h"

namespace CIDL_Receiver_Impl
{
  class RECEIVER_EXEC_Export Receiver_exec_i
  : public virtual Receiver_Exec,
  public virtual TAO_Local_RefCounted_Object
  {
    public:
    Receiver_exec_i (void);
    virtual ~Receiver_exec_i (void);

    // Supported or inherited operations.

    // Attribute operations.

    // Port operations.

    virtual void
    push_message_consumer (
    ::Message *ev);

    // Operations from Components::SessionComponent

    virtual void
    set_session_context (
    ::Components::SessionContext_ptr ctx);

    virtual void
    ciao_preactivate ();

    virtual void
    ciao_postactivate ();

    virtual void
    ccm_activate ();

    virtual void
    ccm_passivate ();

    virtual void
    ccm_remove ();

    protected:
    Receiver_Context *context_;
  };

  class RECEIVER_EXEC_Export ReceiverHome_exec_i
  : public virtual ReceiverHome_Exec,
  public virtual TAO_Local_RefCounted_Object
  {
    public:
    ReceiverHome_exec_i (void);
    virtual ~ReceiverHome_exec_i (void);

    // Supported or inherited operations.

    // Home operations.

    // Factory and finder operations.

    // Attribute operations.

    // Implicit operations.

    virtual ::Components::EnterpriseComponent_ptr
    create ();
  };

  extern "C" RECEIVER_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_ReceiverHome_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* CIAO_RECEIVER_EXEC_H */


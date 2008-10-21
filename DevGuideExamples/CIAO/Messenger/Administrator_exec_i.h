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

#ifndef CIAO_ADMINISTRATOR_EXEC_H
#define CIAO_ADMINISTRATOR_EXEC_H

#include /**/ "ace/pre.h"

#include "Administrator_svnt.h"
#include "Administrator_exec_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/LocalObject.h"
#include <ace/Task.h>

namespace CIDL_Administrator_Impl
{
  class ADMINISTRATOR_EXEC_Export Administrator_exec_i
  : public virtual Administrator_Exec,
  public virtual ACE_Task_Base,
  public virtual TAO_Local_RefCounted_Object
  {
    public:
    Administrator_exec_i (void);
    virtual ~Administrator_exec_i (void);

    // Supported or inherited operations.

    // Attribute operations.

    // Port operations.

    // Operations from Components::SessionComponent

    virtual void
    set_session_context (
    ::Components::SessionContext_ptr ctx);

    virtual void
    ccm_activate ();

    virtual void
    ccm_passivate ();

    virtual void
    ccm_remove ();

    virtual void
    ciao_preactivate ();

    virtual void
    ciao_postactivate ();

    protected:
    Administrator_Context *context_;

  public:
    // Overridden from ACE_Task_Base
    int svc();

  private:
    void startPublishing();
    void stopPublishing();
    void changePublicationPeriod();
    void changePublicationText();
  };

  class ADMINISTRATOR_EXEC_Export AdministratorHome_exec_i
  : public virtual AdministratorHome_Exec,
  public virtual TAO_Local_RefCounted_Object
  {
    public:
    AdministratorHome_exec_i (void);
    virtual ~AdministratorHome_exec_i (void);

    // Supported or inherited operations.

    // Home operations.

    // Factory and finder operations.

    // Attribute operations.

    // Implicit operations.

    virtual ::Components::EnterpriseComponent_ptr
    create ();
  };

  extern "C" ADMINISTRATOR_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_AdministratorHome_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* CIAO_ADMINISTRATOR_EXEC_H */


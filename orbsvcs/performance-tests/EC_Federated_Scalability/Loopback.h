/**
 * @file Loopback.h
 *
 * $Id$
 *
 */

#ifndef ECFS_LOOPBACK_H
#define ECFS_LOOPBACK_H

#include "ControlS.h"
#include "Servant_var.h"
#include "Loopback_Consumer.h"
#include "Loopback_Supplier.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

/**
 * @class ECFS_Loopback
 *
 * @brief Implement the Control::Loopback interface
 *
 */
class ECFS_Loopback
 : public virtual POA_Control::Loopback
 , public virtual PortableServer::RefCountServantBase
{
public:
  /// Constructor
  ECFS_Loopback (void);

  /// Initialize the loopback
  void init (CORBA::Long experiment_id,
             RtecEventChannelAdmin::EventChannel_ptr ec
             ACE_ENV_ARG_DECL);

  //@{
  /** @name The Control::Loopback methods
   */
  virtual void destroy (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));
  //@}

private:
  /// Keep a reference to the loopback consumer
  Servant_var<ECFS_Loopback_Consumer> consumer_;

  /// Keep a reference to the loopback supplier
  Servant_var<ECFS_Loopback_Supplier> supplier_;
};

#endif /* ECFS_LOOPBACK_H */

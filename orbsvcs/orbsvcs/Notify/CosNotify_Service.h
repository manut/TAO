/* -*- C++ -*- */
/**
 *  @file CosNotify_Service.h
 *
 *  $Id$
 *
 *  @author Pradeep Gore <pradeep@oomworks.com>
 *
 *
 */

#ifndef TAO_Notify_COSNOTIFY_SERVICE_H
#define TAO_Notify_COSNOTIFY_SERVICE_H
#include /**/ "ace/pre.h"

#include "notify_serv_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "Service.h"
#include "Builder.h"
#include "Factory.h"

class TAO_Notify_Properties;
class TAO_Notify_EventChannelFactory;

/**
 * @class TAO_CosNotify_Service
 *
 * @brief A service object for creating the  Notify Service Factory.
 *
 */
class TAO_Notify_Serv_Export TAO_CosNotify_Service : public TAO_Notify_Service
{
public:
  /// Constuctor
  TAO_CosNotify_Service (void);

  /// Destructor
  virtual ~TAO_CosNotify_Service ();

  /// Init the service from configurator
  virtual int init (int argc, ACE_TCHAR *argv[]);

  /// Init the service from driver
  virtual void init_service (CORBA::ORB_ptr orb ACE_ENV_ARG_DECL);

  virtual int fini (void);

  /// Create the Channel Factory.
  virtual CosNotifyChannelAdmin::EventChannelFactory_ptr create (PortableServer::POA_ptr default_POA ACE_ENV_ARG_DECL);

  /// Called by the factory when it is destroyed.
  virtual void remove (TAO_Notify_EventChannelFactory* ecf ACE_ENV_ARG_DECL);

protected:
  /// Init the data members
  virtual void init_i (CORBA::ORB_ptr orb ACE_ENV_ARG_DECL);

private:

  /// Create the Factory for Notify objects.
  virtual TAO_Notify_Factory* create_factory (ACE_ENV_SINGLE_ARG_DECL);

  /// Create the Builder for Notify objects.
  virtual TAO_Notify_Builder* create_builder (ACE_ENV_SINGLE_ARG_DECL);

  /// Set thread options on <qos>.
  void set_threads (CosNotification::QoSProperties &qos, int threads);

  TAO_Notify_Factory& factory();

  /// Service component for building NS participants.
  TAO_Notify_Builder& builder();

  /// Service component for object factory operations.
  ACE_Auto_Ptr< TAO_Notify_Factory > factory_;

  /// Service component for building NS participants.
  ACE_Auto_Ptr< TAO_Notify_Builder > builder_;
};

ACE_STATIC_SVC_DECLARE (TAO_CosNotify_Service)
ACE_FACTORY_DECLARE (TAO_Notify_Serv, TAO_CosNotify_Service)

ACE_STATIC_SVC_DECLARE (TAO_Notify_Default_EMO_Factory_OLD)

#include /**/ "ace/post.h"
#endif /* TAO_Notify_COSNOTIFY_SERVICE_H */

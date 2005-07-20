// $Id$

#include "Default_Factory.h"

ACE_RCSID (Notify,
           TAO_Notify_Default_Factory,
           "$Id$")

#include "EventChannelFactory.h"
#include "EventChannel.h"
#include "Admin.h"
#include "Proxy.h"
#include "SupplierAdmin.h"
#include "ConsumerAdmin.h"
#include "Structured/StructuredProxyPushConsumer.h"
#include "Structured/StructuredProxyPushSupplier.h"
#include "Any/ProxyPushConsumer.h"
#include "Any/ProxyPushSupplier.h"
#include "Any/CosEC_ProxyPushConsumer.h"
#include "Any/CosEC_ProxyPushSupplier.h"
#include "Sequence/SequenceProxyPushConsumer.h"
#include "Sequence/SequenceProxyPushSupplier.h"
#include "Supplier.h"

#include "orbsvcs/ESF/ESF_Proxy_List.h"
#include "orbsvcs/ESF/ESF_Copy_On_Write.h"

template <class PROXY>
class COW_Collection_Default_Factory
{
public:
  typedef ACE_TYPENAME TAO_ESF_Proxy_List<PROXY>::Iterator PROXY_ITER;
  typedef TAO_ESF_Copy_On_Write<PROXY, TAO_ESF_Proxy_List<PROXY>,PROXY_ITER, ACE_SYNCH> COLLECTION;
  typedef TAO_ESF_Proxy_Collection<PROXY> BASE_COLLECTION;

  void create (BASE_COLLECTION* &collection ACE_ENV_ARG_DECL)
  {
    ACE_NEW_THROW_EX (collection,
                      COLLECTION (),
                      CORBA::INTERNAL ());
  }
};

TAO_Notify_Default_Factory::TAO_Notify_Default_Factory (void)
{
}

TAO_Notify_Default_Factory::~TAO_Notify_Default_Factory ()
{
}

void
TAO_Notify_Default_Factory::create (TAO_Notify_ProxySupplier_Collection* &collection ACE_ENV_ARG_DECL)
{
  COW_Collection_Default_Factory<TAO_Notify_ProxySupplier> f;
  f.create (collection ACE_ENV_ARG_PARAMETER);
}

void
TAO_Notify_Default_Factory::create (TAO_Notify_ProxyConsumer_Collection* &collection ACE_ENV_ARG_DECL)
{
  COW_Collection_Default_Factory<TAO_Notify_ProxyConsumer> f;
  f.create (collection ACE_ENV_ARG_PARAMETER);
}

void
TAO_Notify_Default_Factory::create (TAO_Notify_EventChannel_Collection* &collection ACE_ENV_ARG_DECL)
{
  COW_Collection_Default_Factory<TAO_Notify_EventChannel> f;
  f.create (collection ACE_ENV_ARG_PARAMETER);
}

void
TAO_Notify_Default_Factory::create (TAO_Notify_ConsumerAdmin_Collection* &collection ACE_ENV_ARG_DECL)
{
  COW_Collection_Default_Factory<TAO_Notify_ConsumerAdmin> f;
  f.create (collection ACE_ENV_ARG_PARAMETER);
}

void
TAO_Notify_Default_Factory::create (TAO_Notify_SupplierAdmin_Collection* &collection ACE_ENV_ARG_DECL)
{
  COW_Collection_Default_Factory<TAO_Notify_SupplierAdmin> f;
  f.create (collection ACE_ENV_ARG_PARAMETER);
}

void
TAO_Notify_Default_Factory::create (TAO_Notify_Proxy_Collection* &collection ACE_ENV_ARG_DECL)
{
  COW_Collection_Default_Factory<TAO_Notify_Proxy> f;
  f.create (collection ACE_ENV_ARG_PARAMETER);
}

void
TAO_Notify_Default_Factory::create (TAO_Notify_EventChannelFactory*& factory ACE_ENV_ARG_DECL)
{
  ACE_NEW_THROW_EX (factory,
                    TAO_Notify_EventChannelFactory (),
                    CORBA::NO_MEMORY ());
}

void
TAO_Notify_Default_Factory::create (TAO_Notify_EventChannel*& channel ACE_ENV_ARG_DECL)
{
  ACE_NEW_THROW_EX (channel,
                    TAO_Notify_EventChannel (),
                    CORBA::NO_MEMORY ());
}


void
TAO_Notify_Default_Factory::create (TAO_Notify_SupplierAdmin*& admin ACE_ENV_ARG_DECL)
{
  ACE_NEW_THROW_EX (admin,
                    TAO_Notify_SupplierAdmin (),
                    CORBA::NO_MEMORY ());
}

void
TAO_Notify_Default_Factory::create (TAO_Notify_ConsumerAdmin*& admin ACE_ENV_ARG_DECL)
{
  ACE_NEW_THROW_EX (admin,
                    TAO_Notify_ConsumerAdmin (),
                    CORBA::NO_MEMORY ());
}

void
TAO_Notify_Default_Factory::create (TAO_Notify_StructuredProxyPushConsumer*& proxy ACE_ENV_ARG_DECL)
{
  ACE_NEW_THROW_EX (proxy,
                    TAO_Notify_StructuredProxyPushConsumer (),
                    CORBA::NO_MEMORY ());
}

void
TAO_Notify_Default_Factory::create (TAO_Notify_StructuredProxyPushSupplier*& proxy ACE_ENV_ARG_DECL)
{
  ACE_NEW_THROW_EX (proxy,
                    TAO_Notify_StructuredProxyPushSupplier (),
                    CORBA::NO_MEMORY ());
}

void
TAO_Notify_Default_Factory::create (TAO_Notify_ProxyPushConsumer*& proxy ACE_ENV_ARG_DECL)
{
  ACE_NEW_THROW_EX (proxy,
                    TAO_Notify_ProxyPushConsumer (),
                    CORBA::NO_MEMORY ());
}

void
TAO_Notify_Default_Factory::create (TAO_Notify_ProxyPushSupplier*& proxy ACE_ENV_ARG_DECL)
{
  ACE_NEW_THROW_EX (proxy,
                    TAO_Notify_ProxyPushSupplier (),
                    CORBA::NO_MEMORY ());
}

void
TAO_Notify_Default_Factory::create (TAO_Notify_CosEC_ProxyPushConsumer*& proxy ACE_ENV_ARG_DECL)
{
  ACE_NEW_THROW_EX (proxy,
                    TAO_Notify_CosEC_ProxyPushConsumer (),
                    CORBA::NO_MEMORY ());
}

void
TAO_Notify_Default_Factory::create (TAO_Notify_CosEC_ProxyPushSupplier*& proxy ACE_ENV_ARG_DECL)
{
  ACE_NEW_THROW_EX (proxy,
                    TAO_Notify_CosEC_ProxyPushSupplier (),
                    CORBA::NO_MEMORY ());
}

void
TAO_Notify_Default_Factory::create (TAO_Notify_SequenceProxyPushConsumer*& proxy ACE_ENV_ARG_DECL)
{
  ACE_NEW_THROW_EX (proxy,
                    TAO_Notify_SequenceProxyPushConsumer (),
                    CORBA::NO_MEMORY ());
}

void
TAO_Notify_Default_Factory::create (TAO_Notify_SequenceProxyPushSupplier*& proxy ACE_ENV_ARG_DECL)
{
  ACE_NEW_THROW_EX (proxy,
                    TAO_Notify_SequenceProxyPushSupplier (),
                    CORBA::NO_MEMORY ());
}

ACE_FACTORY_DEFINE (TAO_Notify_Serv, TAO_Notify_Default_Factory)


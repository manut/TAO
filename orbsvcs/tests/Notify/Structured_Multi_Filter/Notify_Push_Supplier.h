// $Id$
#ifndef NOTIFY_PUSH_SUPPLIER_H
#define NOTIFY_PUSH_SUPPLIER_H

#include "Notify_StructuredPushSupplier.h"


class Notify_Push_Supplier: public TAO_Notify_StructuredPushSupplier
{
public:
  void connect (CosNotifyChannelAdmin::SupplierAdmin_ptr supplier_admin,
                CosNotifyChannelAdmin::EventChannel_ptr notify_channel,
                CORBA::Boolean isFilter
                TAO_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));
};

#endif /* NOTIFY_PUSH_SUPPLIER_H */

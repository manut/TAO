// $Id$

#include "Notify_AdminProperties.h"

#if ! defined (__ACE_INLINE__)
#include "Notify_AdminProperties.i"
#endif /* __ACE_INLINE__ */

ACE_RCSID(Notify, Notify_AdminProperties, "$Id$")

TAO_Notify_AdminProperties::TAO_Notify_AdminProperties (void)
  : max_queue_length_ (0),
    max_consumers_ (0),
    max_suppliers_ (0),
    reject_new_events_ (0)
{
}

TAO_Notify_AdminProperties::~TAO_Notify_AdminProperties ()
{
}

CosNotification::AdminProperties*
TAO_Notify_AdminProperties::get_admin (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  CORBA::Long property_count = 4; //The spec has 4 properties, so far.

  CosNotification::AdminProperties_var admin;

  ACE_NEW_THROW_EX (admin,
                    CosNotification::AdminProperties (property_count),
                    CORBA::NO_MEMORY ());
  admin->length (property_count);

  (*admin)[0].name =
  CORBA::string_dup (CosNotification::MaxQueueLength);
  (*admin)[0].value <<= (CORBA::Long)max_queue_length_;

  (*admin)[1].name =
  CORBA::string_dup (CosNotification::MaxConsumers);
  (*admin)[1].value <<= (CORBA::Long)max_consumers_;

  (*admin)[2].name =
  CORBA::string_dup (CosNotification::MaxSuppliers);
  (*admin)[2].value <<= (CORBA::Long)max_suppliers_;

  (*admin)[3].name =
  CORBA::string_dup (CosNotification::RejectNewEvents);
  (*admin)[3].value <<= CORBA::Any::from_boolean (reject_new_events_);

  return admin._retn ();
}

void
TAO_Notify_AdminProperties::set_admin (const CosNotification::AdminProperties & admin, CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((
                   CORBA::SystemException,
                   CosNotification::UnsupportedAdmin
                   ))
{
  for (CORBA::ULong i = 0; i < admin.length (); ++i)
    {
      if (ACE_OS::strcmp (admin[i].name,
                          CosNotification::MaxQueueLength) == 0)
        {
          admin[i].value >>= max_queue_length_;
        }
      else if (ACE_OS::strcmp (admin[i].name,
                               CosNotification::MaxSuppliers) == 0)
        {
          admin[i].value >>= this->max_suppliers_;
        }
      else if (ACE_OS::strcmp (admin[i].name,
                               CosNotification::MaxConsumers) == 0)
        {
          admin[i].value >>= this->max_consumers_;
        }
      else if (ACE_OS::strcmp (admin[i].name,
                               CosNotification::RejectNewEvents) == 0)
        {
          admin[i].value >>= CORBA::Any::to_boolean (this->reject_new_events_);
        }
      else
        ACE_THROW (CosNotification::UnsupportedAdmin ());
    }
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class ACE_Atomic_Op<ACE_Thread_Mutex,int>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#pragma instantiate ACE_Atomic_Op<ACE_Thread_Mutex,int>

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

//
// $Id$
//

#include "Stock_i.h"
#include <orbsvcs/Event_Utilities.h>

Quoter_Stock_i::Quoter_Stock_i (const char *symbol,
                                const char *full_name,
                                CORBA::Double price)
  :  supplier_personality_ (this)
{
  this->data_.symbol = symbol;
  this->data_.full_name = full_name;
  this->data_.price = price;
}

char *
Quoter_Stock_i::symbol () throw (CORBA::SystemException)
{
  return CORBA::string_dup (this->data_.symbol.in ());
}

char *
Quoter_Stock_i::full_name () throw (CORBA::SystemException)
{
  return CORBA::string_dup (this->data_.full_name.in ());
}

CORBA::Double
Quoter_Stock_i::price () throw (CORBA::SystemException)
{
  return this->data_.price;
}

void
Quoter_Stock_i::set_price (CORBA::Double new_price)
  throw (CORBA::SystemException)
{
  this->data_.price = new_price;
  if (CORBA::is_nil (this->consumer_proxy_.in ()))
    return;

  // Create the event
  RtecEventComm::EventSet event (1);
  event.length (1);
  RtecEventComm::Event &e = event[0];

  // Initialize the header
  const char *symbol = this->data_.symbol;
  e.header.type = int(symbol[0]) << 24;
  e.header.type |= int(symbol[1]) << 16;
  e.header.type |= int(symbol[2]) << 8;
  e.header.type |= int(symbol[3]);
  e.header.source = 1;

  // Initialize the payload
  e.data.any_value <<= this->data_;

  // Push it
  this->consumer_proxy_->push (event);
}

void
Quoter_Stock_i::disconnect_push_supplier (CORBA::Environment&)
  throw (CORBA::SystemException)
{
  // Forget about the consumer it is not there anymore
  this->consumer_proxy_ =
    RtecEventChannelAdmin::ProxyPushConsumer::_nil ();
}

void
Quoter_Stock_i::connect (RtecEventChannelAdmin::SupplierAdmin_ptr supplier_admin)
{
  this->consumer_proxy_ =
    supplier_admin->obtain_push_consumer ();
  RtecEventComm::PushSupplier_var supplier =
    this->supplier_personality_._this ();

   const char *symbol = this->data_.symbol;
   CORBA::ULong type = int(symbol[0]) << 24;
   type |= int(symbol[1]) << 16;
   type |= int(symbol[2]) << 8;
   type |= int(symbol[3]);

   CORBA::ULong source = 1;
   ACE_SupplierQOS_Factory publications;
   publications.insert (source, type, 0, 1);

   this->consumer_proxy_->connect_push_supplier (supplier.in (),
                                                 publications.get_SupplierQOS ());
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class POA_RtecEventComm::PushSupplier_tie<Quoter_Stock_i>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#pragma instantiate POA_RtecEventComm::PushSupplier_tie<Quoter_Stock_i>

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

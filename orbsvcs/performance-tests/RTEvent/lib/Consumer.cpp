/**
 * @file Consumer.cpp
 *
 * $Id$
 *
 * @author Carlos O'Ryan <coryan@uci.edu>
 */

#include "Consumer.h"
#include "Implicit_Deactivator.h"
#include "orbsvcs/orbsvcs/Event_Service_Constants.h"
#include "ace/OS_NS_unistd.h"

ACE_RCSID (TAO_PERF_RTEC, 
           Consumer, 
           "$Id$")

Consumer::Consumer (CORBA::Long experiment_id,
                    CORBA::Long event_type,
                    CORBA::ULong iterations,
                    CORBA::Long workload_in_usecs,
                    ACE_UINT32 gsf,
                    PortableServer::POA_ptr poa)
  : experiment_id_ (experiment_id)
  , event_type_ (event_type)
  , sample_history_ (iterations)
  , workload_in_usecs_ (workload_in_usecs)
  , gsf_ (gsf)
  , default_POA_ (PortableServer::POA::_duplicate (poa))
{
}

void
Consumer::connect (RtecEventChannelAdmin::EventChannel_ptr ec
                   ACE_ENV_ARG_DECL)
{
  RtecEventChannelAdmin::ConsumerAdmin_var consumer_admin =
    ec->for_consumers (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  {
    ACE_GUARD (TAO_SYNCH_MUTEX, ace_mon, this->mutex_);
    if (!CORBA::is_nil (this->proxy_supplier_.in ()))
      return;

    this->proxy_supplier_ =
      consumer_admin->obtain_push_supplier (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK;
  }

  RtecEventComm::PushConsumer_var consumer =
    this->_this (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  RtecEventChannelAdmin::ConsumerQOS consumer_qos;
  consumer_qos.is_gateway = 0;
  consumer_qos.dependencies.length (2);
  RtecEventComm::EventHeader& h0 =
    consumer_qos.dependencies[0].event.header;
  h0.type   = ACE_ES_DISJUNCTION_DESIGNATOR;
  h0.source = 1;

  RtecEventComm::EventHeader& h1 =
    consumer_qos.dependencies[1].event.header;
  h1.type   = this->event_type_;
  h1.source = this->experiment_id_;

  this->proxy_supplier_->connect_push_consumer (consumer.in (),
                                                consumer_qos
                                                ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

void
Consumer::disconnect (ACE_ENV_SINGLE_ARG_DECL)
{
  RtecEventChannelAdmin::ProxyPushSupplier_var proxy;
  {
    ACE_GUARD (TAO_SYNCH_MUTEX, ace_mon, this->mutex_);
    if (CORBA::is_nil (this->proxy_supplier_.in ()))
      return;
    proxy = this->proxy_supplier_._retn ();
  }

  Implicit_Deactivator deactivator (this
                                    ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  ACE_TRY {
    proxy->disconnect_push_supplier (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_TRY_CHECK;
  } ACE_CATCHANY {
  } ACE_ENDTRY;
}

ACE_Sample_History &
Consumer::sample_history (void)
{
  return this->sample_history_;
}

void
Consumer::push (const RtecEventComm::EventSet &events
                ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_hrtime_t now = ACE_OS::gethrtime ();

  ACE_hrtime_t creation;
  ORBSVCS_Time::TimeT_to_hrtime (creation,
                                 events[0].header.creation_time);

  while (this->workload_in_usecs_ > 0)
    {
      ACE_hrtime_t elapsed = ACE_OS::gethrtime () - now;
      if (elapsed > this->gsf_ * this->workload_in_usecs_)
        break;
      ACE_OS::sleep (0);
    }

  ACE_GUARD (TAO_SYNCH_MUTEX, ace_mon, this->mutex_);
  if (sample_history_.max_samples () == sample_history_.sample_count ())
    return;
  this->sample_history_.sample (now - creation);
}

void
Consumer::disconnect_push_consumer (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_GUARD (TAO_SYNCH_MUTEX, ace_mon, this->mutex_);
  this->proxy_supplier_ =
    RtecEventChannelAdmin::ProxyPushSupplier::_nil ();
}

PortableServer::POA_ptr
Consumer::_default_POA (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return PortableServer::POA::_duplicate (this->default_POA_.in ());
}

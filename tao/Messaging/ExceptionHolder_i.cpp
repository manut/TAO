// -*- C++ -*-
// $Id$

#include "tao/Messaging/ExceptionHolder_i.h"

ACE_RCSID (Messaging,
           ExceptionHolder_i,
           "$Id$")

#if !defined (TAO_HAS_DEPRECATED_EXCEPTION_HOLDER)

#include "tao/Messaging/Messaging.h"

namespace TAO
{
  ExceptionHolder::ExceptionHolder (
      ::CORBA::Boolean is_system_exception,
      ::CORBA::Boolean byte_order,
      const ::CORBA::OctetSeq &marshaled_exception,
      ::TAO::Exception_Data* data,
      ::CORBA::ULong exceptions_count) :
        ::OBV_Messaging::ExceptionHolder (),
        ::CORBA::DefaultValueRefCountBase (),
        data_ (data),
        count_ (exceptions_count)
  {
    this->is_system_exception (is_system_exception);
    this->byte_order (byte_order);
    this->marshaled_exception (marshaled_exception);
  }

  ExceptionHolder::~ExceptionHolder ()
  {
  }

  void ExceptionHolder::raise_exception (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
    )
    {
      TAO_Messaging_Helper::exception_holder_raise (
        this->data_,
        this->count_,
        this->marshaled_exception ().get_buffer (),
        this->marshaled_exception ().length (),
        this->byte_order (),
        this->is_system_exception ()
        ACE_ENV_ARG_PARAMETER);
      }

  void ExceptionHolder::raise_exception_with_list (
      const ::Dynamic::ExceptionList & ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    {
      // todo convert exceptionlist to something we can really use.
      this->raise_exception (ACE_ENV_SINGLE_ARG_PARAMETER);
    }
}

#endif

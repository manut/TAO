// $Id$

#include "ClientRequestInfo.h"

#if TAO_HAS_INTERCEPTORS == 1


ACE_RCSID (tao,
           ClientRequestInfo,
           "$Id$")

#include "Any.h"
#include "PolicyC.h"
#include "PortableInterceptorC.h"
#include "PICurrent.h"
#include "Invocation_Base.h"
#include "Stub.h"
#include "ORB_Core.h"
#include "Profile.h"
#include "debug.h"
#include "Service_Context.h"

TAO_ClientRequestInfo::TAO_ClientRequestInfo (TAO::Invocation_Base *inv)
  : invocation_ (inv),
    caught_exception_ (0),
    reply_status_ (-1),
    rs_pi_current_ (),
    copy_callback_ ()
{
  this->setup_picurrent ();
}

void
TAO_ClientRequestInfo::setup_picurrent (void)
{
  // Retrieve the thread scope current (no TSS access incurred yet).
  TAO::PICurrent *pi_current =
    this->invocation_->orb_core ()->pi_current ();

  // If the slot count is zero, then there is nothing to copy.
  // Prevent any copying (and hence TSS accesses) from occurring.
  if (pi_current != 0 && pi_current->slot_count () != 0)
    {
      // Retrieve the thread scope current.
      TAO::PICurrent_Impl *tsc = pi_current->tsc ();

      // Logically copy the TSC's slot table to the RSC.
      this->rs_pi_current_.lc_slot_table (tsc);

      // PICurrent will potentially have to call back on the request
      // scope current so that it can deep copy the contents of the
      // thread scope current if the contents of the thread scope
      // current are about to be modified.  It is necessary to do this
      // deep copy once in order to completely isolate the request
      // scope current from the thread scope current.  This is only
      // necessary, if the thread scope current is modified after its
      // contents have been *logically* copied to the request scope
      // current.
      this->copy_callback_.src_and_dst (tsc, &this->rs_pi_current_);
      tsc->copy_callback (&this->copy_callback_);
    }
}

IOP::ServiceContext *
TAO_ClientRequestInfo::get_service_context_i (
    TAO_Service_Context &service_context_list,
    IOP::ServiceId id
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  IOP::ServiceContext_var service_context;

  if (service_context_list.get_context (id, service_context.out ()) != 0)
    {
      // Found.
      return service_context._retn ();
    }
  else
    {
      // Not found.
      ACE_THROW_RETURN (CORBA::BAD_PARAM (CORBA::OMGVMCID | 26,
                                          CORBA::COMPLETED_NO),
                        0);
    }
}

CORBA::Object_ptr
TAO_ClientRequestInfo::target (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->check_validity (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (CORBA::Object::_nil ());

  return CORBA::Object::_duplicate (this->invocation_->target ());
}

CORBA::Object_ptr
TAO_ClientRequestInfo::effective_target (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->check_validity (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (CORBA::Object::_nil ());

  return CORBA::Object::_duplicate (this->invocation_->effective_target ());
}

IOP::TaggedProfile *
TAO_ClientRequestInfo::effective_profile (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->check_validity (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  IOP::TaggedProfile *tagged_profile = 0;
  ACE_NEW_THROW_EX (tagged_profile,
                    IOP::TaggedProfile,
                    CORBA::NO_MEMORY (
                      CORBA::SystemException::_tao_minor_code (
                        TAO::VMCID,
                        ENOMEM),
                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (0);

  IOP::TaggedProfile_var safe_tagged_profile = tagged_profile;

  TAO_Stub *stub =
    this->invocation_->effective_target ()->_stubobj ();

  IOP::TaggedProfile *ep =
    stub->profile_in_use ()->create_tagged_profile ();

  if (ep == 0)
    {
      ACE_THROW_RETURN (CORBA::BAD_PARAM (CORBA::OMGVMCID | 28,
                                          CORBA::COMPLETED_NO),
                                          0);
    }

  // @@BAD_PARAM exception
  tagged_profile->tag = ep->tag;
  tagged_profile->profile_data = ep->profile_data;  // Deep copy

  return safe_tagged_profile._retn ();
}

// Use at own risk. There is no way currently of extracting an
// exception from an Any. This method is in place just to be compliant
// with the spec.
CORBA::Any *
TAO_ClientRequestInfo::received_exception (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->check_validity (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  if (this->reply_status_ != PortableInterceptor::SYSTEM_EXCEPTION
      && this->reply_status_ != PortableInterceptor::USER_EXCEPTION)
    {
      ACE_THROW_RETURN (CORBA::BAD_INV_ORDER (CORBA::OMGVMCID | 14,
                                              CORBA::COMPLETED_NO), 0);
    }

  // The spec says that if it is a user exception which can't be
  // inserted then the UNKNOWN exception needs to be thrown with minor
  // code 1.

  CORBA::Any * temp = 0;

  ACE_NEW_THROW_EX (temp,
                    CORBA::Any,
                    CORBA::NO_MEMORY (
                      CORBA::SystemException::_tao_minor_code (
                        TAO::VMCID,
                        ENOMEM),
                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (0);

  CORBA::Any_var caught_exception = temp;

  if (this->caught_exception_ != 0)
    *temp <<= *(this->caught_exception_);

  return caught_exception._retn ();
}

char *
TAO_ClientRequestInfo::received_exception_id (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->check_validity (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  if (this->reply_status_ != PortableInterceptor::SYSTEM_EXCEPTION
      && this->reply_status_ != PortableInterceptor::USER_EXCEPTION)
    {
      ACE_THROW_RETURN (CORBA::BAD_INV_ORDER (CORBA::OMGVMCID | 14,
                                              CORBA::COMPLETED_NO),
                        0);
    }

  return CORBA::string_dup (this->caught_exception_->_rep_id ());
}

IOP::TaggedComponent *
TAO_ClientRequestInfo::get_effective_component (
    IOP::ComponentId id
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->check_validity (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  TAO_Stub *stub =
    this->invocation_->effective_target ()->_stubobj ();

  TAO_Tagged_Components &ecs =
    stub->profile_in_use ()->tagged_components ();

  IOP::MultipleComponentProfile &components = ecs.components ();

  const CORBA::ULong len = components.length ();
  for (CORBA::ULong i = 0; i < len; ++i)
    {
      if (components[i].tag == id)
        {
          IOP::TaggedComponent *tagged_component = 0;

          // Only allocate a sequence if we have a tagged component
          // that matches the given IOP::ComponentId.
          ACE_NEW_THROW_EX (tagged_component,
                            IOP::TaggedComponent,
                            CORBA::NO_MEMORY (
                              CORBA::SystemException::_tao_minor_code (
                                TAO::VMCID,
                                ENOMEM),
                              CORBA::COMPLETED_NO));
          ACE_CHECK_RETURN (0);

          IOP::TaggedComponent_var safe_tagged_component =
            tagged_component;

          (*tagged_component) = components[i];  // Deep copy

          return safe_tagged_component._retn ();
        }
    }

  // No tagged component was found that matched the given
  // IOP::ComponentId.
  ACE_THROW_RETURN (CORBA::BAD_PARAM (CORBA::OMGVMCID | 28,
                                      CORBA::COMPLETED_NO),
                    0);
}

IOP::TaggedComponentSeq *
TAO_ClientRequestInfo::get_effective_components (
    IOP::ComponentId id
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->check_validity (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  TAO_Stub *stub =
    this->invocation_->target ()->_stubobj ();

  TAO_Tagged_Components &ecs =
    stub->profile_in_use ()->tagged_components ();

  IOP::MultipleComponentProfile &components = ecs.components ();

  IOP::TaggedComponentSeq *tagged_components = 0;
  IOP::TaggedComponentSeq_var safe_tagged_components;

  const CORBA::ULong len = components.length ();
  for (CORBA::ULong i = 0; i < len; ++i)
    {
      if (components[i].tag == id)
        {
          if (tagged_components == 0)
            {
              // Only allocate a sequence if we have tagged components
              // to place into the sequence.
              ACE_NEW_THROW_EX (tagged_components,
                                IOP::TaggedComponentSeq,
                                CORBA::NO_MEMORY (
                                  CORBA::SystemException::_tao_minor_code (
                                    TAO::VMCID,
                                    ENOMEM),
                                  CORBA::COMPLETED_NO));
              ACE_CHECK_RETURN (0);

              safe_tagged_components = tagged_components;
            }

          const CORBA::ULong old_len = safe_tagged_components->length ();
          safe_tagged_components->length (old_len + 1);

          safe_tagged_components[old_len] = components[i];  // Deep copy
        }
    }

  if (tagged_components == 0)
    {
      // No tagged component sequence was allocated, meaning no tagged
      // components were found that matched the given
      // IOP::ComponentId.
      ACE_THROW_RETURN (CORBA::BAD_PARAM (CORBA::OMGVMCID | 28,
                                          CORBA::COMPLETED_NO),
                        0);
    }

  return safe_tagged_components._retn ();
}

CORBA::Policy_ptr
TAO_ClientRequestInfo::get_request_policy (CORBA::PolicyType type
                                           ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->check_validity (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (CORBA::Policy::_nil ());

  // @@ Do we need to look anywhere else for the request policies?

#if TAO_HAS_CORBA_MESSAGING == 1
  return this->invocation_->target ()->_get_policy (type
                                                    ACE_ENV_ARG_PARAMETER);
#else
  ACE_UNUSED_ARG (type);

  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (
                      CORBA::SystemException::_tao_minor_code (
                        TAO::VMCID,
                        ENOTSUP),
                      CORBA::COMPLETED_NO),
                    0);
#endif  /* TAO_HAS_CORBA_MESSAGING == 1 */
}

void
TAO_ClientRequestInfo::add_request_service_context (
    const IOP::ServiceContext & service_context,
    CORBA::Boolean replace
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->check_validity (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  // Get the service context from the list
  TAO_Service_Context &service_context_list =
    this->invocation_->request_service_context ();

  if (service_context_list.set_context (service_context, replace) == 0)
    {
      ACE_THROW (CORBA::BAD_INV_ORDER (CORBA::OMGVMCID | 15,
                                       CORBA::COMPLETED_NO));
    }
}

CORBA::ULong
TAO_ClientRequestInfo::request_id (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->check_validity (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  // @todo We may have to worry about AMI once we support interceptors
  //       in AMI requests since the Invocation object no longer
  //       exists once an AMI request has been made.  In that case,
  //       the reply dispatcher address should be used.

  // The request ID must be unique across all outstanding requests.
  // To avoid synchronization overhead, the address of this Invocation
  // object is used as the request ID.  This guarantees that the
  // request ID is unique without being forced to acquire a lock.
  //
  // For 64-bit platforms, we right shift 8 bits and then use the
  // lower 32 bits of that shifted value.  Rather than losing the
  // upper 32 bits of significant digits by taking the lower 32 bits,
  // we only lose the upper 24 by doing the shift.  Basically, the
  // resulting request ID will comprised of bits 8 through 39.  This is
  // made possible by the fact that this Invocation object is large
  // enough to increase the likelihood that those bits (0 through 39)
  // are unique.  In particular, this->buffer_ is 512 bytes
  // (ACE_CDR::DEFAULT_BUFSIZE) long by default; implying that
  // dropping the lower 8 bits of the this Invocation object's 64 bit
  // address (i.e. 256 bytes) is not a problem.

  CORBA::ULong id = 0;

  // Note that we reinterpret_cast to an "unsigned long" instead of
  // CORBA::ULong since we need to first cast to an integer large
  // enough to hold an address to avoid compile-time warnings on some
  // 64-bit platforms.

  // 32 bit address
  if (sizeof (this) == 4)
    id =
      static_cast<CORBA::ULong> (
        reinterpret_cast<ptrdiff_t> (this->invocation_));

  // 64 bit address -- bits 8 through 39  (see notes above!)
  // In this case, we make sure this object is large enough to safely
  // do the right shift.  This is necessary since the size of the
  // buffer that makes this object is configurable.
  else if (sizeof (this) == 8
           && sizeof (*(this->invocation_)) > 256 /* 2 << 8 */)
    id =
      (static_cast<CORBA::ULong> (
         reinterpret_cast<ptrdiff_t> (this->invocation_)) >> 8) & 0xFFFFFFFFu;

  // 64 bit address -- lower 32 bits
  else if (sizeof (this) == 8)
    id =
      static_cast<CORBA::ULong> (
        reinterpret_cast<ptrdiff_t> (this->invocation_)) & 0xFFFFFFFFu;

  // @@ The following request ID generator prevents the
  //    PortableInterceptor::ClientRequestInterceptor::send_request()
  //    interception point from occuring before the call to connect,
  //    thus preventing us from adding an optimization that itself
  //    prevents a connection from being unnecessarily performed.
  //    Thus, the ClientRequestInfo object is forced to have its own
  //    request ID generator in order to make it possible to implement
  //    the above optimization.
  //
  //    Ideally, this request ID generator should go away, especially
  //    since it adds a lock to the critical path.
  //   else    // Fallback
  //     id = this->invocation_->request_id ();

  else
    {
      if (TAO_debug_level > 0)
        ACE_ERROR ((LM_ERROR,
                    "(%P|%t) ClientRequestInfo::request_id() failed\n"
                    "(%P|%t) since its request ID generator is not\n"
                    "(%P|%t) supported on this platform.\n"));

      ACE_THROW_RETURN (CORBA::INTERNAL (), 0);
    }

  return id;
}

char *
TAO_ClientRequestInfo::operation (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->check_validity (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  return CORBA::string_dup (this->invocation_->operation_name ());
}

Dynamic::ParameterList *
TAO_ClientRequestInfo::arguments (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->check_validity (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  return this->invocation_->arguments (ACE_ENV_SINGLE_ARG_PARAMETER);
}

Dynamic::ExceptionList *
TAO_ClientRequestInfo::exceptions (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->check_validity (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  return this->invocation_->exceptions (ACE_ENV_SINGLE_ARG_PARAMETER);
}

Dynamic::ContextList *
TAO_ClientRequestInfo::contexts (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->check_validity (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  ACE_THROW_RETURN (CORBA::BAD_INV_ORDER (CORBA::OMGVMCID | 14,
                                          CORBA::COMPLETED_NO),
                    0);
}

Dynamic::RequestContext *
TAO_ClientRequestInfo::operation_context (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->check_validity (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  ACE_THROW_RETURN (CORBA::BAD_INV_ORDER (CORBA::OMGVMCID | 14,
                                          CORBA::COMPLETED_NO),
                    0);
}

CORBA::Any *
TAO_ClientRequestInfo::result (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->check_validity (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  return this->invocation_->result (ACE_ENV_SINGLE_ARG_PARAMETER);
}

CORBA::Boolean
TAO_ClientRequestInfo::response_expected (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->check_validity (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  return this->invocation_->response_expected ();
}

Messaging::SyncScope
TAO_ClientRequestInfo::sync_scope (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->check_validity (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  return this->invocation_->sync_scope ();
}

PortableInterceptor::ReplyStatus
TAO_ClientRequestInfo::reply_status (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->check_validity (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (PortableInterceptor::SYSTEM_EXCEPTION);

  if (this->reply_status_ == -1)
    {
      // A reply hasn't been received yet.
      ACE_THROW_RETURN (CORBA::BAD_INV_ORDER (CORBA::OMGVMCID | 14,
                                              CORBA::COMPLETED_NO),
                        -1);
    }

  return this->reply_status_;
}

CORBA::Object_ptr
TAO_ClientRequestInfo::forward_reference (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->check_validity (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (CORBA::Object::_nil ());

  if (this->reply_status_ != PortableInterceptor::LOCATION_FORWARD)
    {
      ACE_THROW_RETURN (CORBA::BAD_INV_ORDER (CORBA::OMGVMCID | 14,
                                              CORBA::COMPLETED_NO),
                        CORBA::Object::_nil ());
    }

  // TAO::Invocation_Base::forward_reference() already duplicates the
  // reference before returning it so there is no need to duplicate it
  // here.
  return this->invocation_->forwarded_reference ();
}

CORBA::Any *
TAO_ClientRequestInfo::get_slot (PortableInterceptor::SlotId id
                                 ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableInterceptor::InvalidSlot))
{
  this->check_validity (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  return this->rs_pi_current_.get_slot (id
                                        ACE_ENV_ARG_PARAMETER);
}

IOP::ServiceContext *
TAO_ClientRequestInfo::get_request_service_context (
    IOP::ServiceId id
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->check_validity (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  // Get the service context from the list
  TAO_Service_Context &service_context_list =
    this->invocation_->request_service_context ();

  return this->get_service_context_i (service_context_list,
                                      id
                                      ACE_ENV_ARG_PARAMETER);
}

IOP::ServiceContext *
TAO_ClientRequestInfo::get_reply_service_context (
    IOP::ServiceId id
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->check_validity (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  // Get the service context from the list
  TAO_Service_Context &service_context_list =
    this->invocation_->reply_service_context ();

  return this->get_service_context_i (service_context_list,
                                      id
                                      ACE_ENV_ARG_PARAMETER);
}

void
TAO_ClientRequestInfo::reply_status (TAO::Invocation_Status invoke_status)
{
  switch (invoke_status)
    {
    case TAO::TAO_INVOKE_SUCCESS:
      this->reply_status_ = PortableInterceptor::SUCCESSFUL;
      break;
    case TAO::TAO_INVOKE_RESTART:
      if (this->invocation_->is_forwarded ())
        this->reply_status_ = PortableInterceptor::LOCATION_FORWARD;
      else
        this->reply_status_ = PortableInterceptor::TRANSPORT_RETRY;
      break;
    case TAO::TAO_INVOKE_USER_EXCEPTION:
      this->reply_status_ = PortableInterceptor::USER_EXCEPTION;
      break;
    case TAO::TAO_INVOKE_SYSTEM_EXCEPTION:
      this->reply_status_ = PortableInterceptor::SYSTEM_EXCEPTION;
      break;
    default:
      this->reply_status_ = PortableInterceptor::UNKNOWN;
      break;
    }
}

void
TAO_ClientRequestInfo::exception (CORBA::Exception *exception)
{
  if (CORBA::SystemException::_downcast (exception) != 0)
    this->reply_status_ = PortableInterceptor::SYSTEM_EXCEPTION;
  else if (CORBA::UserException::_downcast (exception) != 0)
    this->reply_status_ = PortableInterceptor::USER_EXCEPTION;

  // @@ Is it possible for both of the above downcasts to fail?

  this->caught_exception_ = exception;
}

void
TAO_ClientRequestInfo::forward_reference (
  PortableInterceptor::ForwardRequest &)
{
  // Note that we're converting the ForwardRequest exception in to a
  // LOCATION_FORWARD reply, so we do not set the exception status.
  //
  // The forward object reference is not handled here.  Rather, it is
  // handled by the TAO::Invocation_Base object so that its profiles
  // can be added to the list of forward profiles.

  this->reply_status_ = PortableInterceptor::LOCATION_FORWARD;
}

void
TAO_ClientRequestInfo::check_validity (ACE_ENV_SINGLE_ARG_DECL)
{
  if (this->invocation_ == 0)
    ACE_THROW (CORBA::BAD_INV_ORDER (CORBA::OMGVMCID | 14,
                                     CORBA::COMPLETED_NO));
}

#endif /* TAO_HAS_INTERCEPTORS == 1 */

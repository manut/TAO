// $Id$

#ifndef TAO_FIXED_TYPECODE_CPP
#define TAO_FIXED_TYPECODE_CPP

#include "tao/Fixed_TypeCode.h"

#ifndef __ACE_INLINE__
# include "tao/Fixed_TypeCode.inl"
#endif  /* !__ACE_INLINE__ */


template <class RefCountPolicy>
bool
TAO::TypeCode::Fixed<RefCountPolicy>::tao_marshal (TAO_OutputCDR & cdr) const
{
  // A tk_fixed TypeCode has a "simple" parameter list type (see
  // Table 15-2 in Section 15.3.5.1 "TypeCode" in the CDR section of
  // the CORBA specification), meaning that its parameter(s) must be
  // marshaled immediately following the TCKind.  No CDR encapsulation
  // is to be created.

  return (cdr << this->digits_) && (cdr << this->scale_);
}

template <class RefCountPolicy>
void
TAO::TypeCode::Fixed<RefCountPolicy>::tao_duplicate (void)
{
  this->RefCountPolicy::add_ref ();
}

template <class RefCountPolicy>
void
TAO::TypeCode::Fixed<RefCountPolicy>::tao_release (void)
{
  this->RefCountPolicy::remove_ref ();
}

template <class RefCountPolicy>
CORBA::Boolean
TAO::TypeCode::Fixed<RefCountPolicy>::equal_i (CORBA::TypeCode_ptr tc
                                               ACE_ENV_ARG_DECL) const
{
  // The following call won't throw since CORBA::TypeCode::equal() has
  // already established the kind of tc is the same as our kind.
  CORBA::UShort const tc_digits =
    tc->fixed_digits (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  CORBA::UShort const tc_scale =
    tc->fixed_scale (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  return (this->digits_ == tc_digits
          && this->scale_ == tc_scale);
}

template <class RefCountPolicy>
CORBA::Boolean
TAO::TypeCode::Fixed<RefCountPolicy>::equivalent_i (CORBA::TypeCode_ptr tc
                                                    ACE_ENV_ARG_DECL) const
{
  // We could refactor this code to the CORBA::TypeCode::equivalent()
  // method but doing so would force us to determine the unaliased
  // kind of this TypeCode.  Since we already know the unaliased kind
  // of this TypeCode, choose to optimize away the additional kind
  // unaliasing operation rather than save space.

  CORBA::TCKind const tc_kind =
    TAO::unaliased_kind (tc
                         ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  // Call kind_i() instead of using CORBA::tk_fixed directly since a
  // subclass, such as WFixed_TypeCode, can use this equivalent_i()
  // implementation.
  CORBA::TCKind const this_kind =
    this->kind_i (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  if (tc_kind != this_kind)
    return 0;

  // Since TCKind comparisons must be performed before equal_i() is
  // called, we can also call it to determine equivalence of
  // tk_fixed TypeCodes.
  return this->equal_i (tc
                        ACE_ENV_ARG_PARAMETER);
}

template <class RefCountPolicy>
CORBA::TCKind
TAO::TypeCode::Fixed<RefCountPolicy>::kind_i (
  ACE_ENV_SINGLE_ARG_DECL_NOT_USED) const
{
  return CORBA::tk_fixed;
}

template <class RefCountPolicy>
CORBA::TypeCode_ptr
TAO::TypeCode::Fixed<RefCountPolicy>::get_compact_typecode_i (
  ACE_ENV_SINGLE_ARG_DECL_NOT_USED) const
{
  // Already compact since tk_fixed TypeCodes have no name or member
  // names, meaning that we can simply call _duplicate() on this
  // TypeCode.


  // @@ There is a potential problem here if this TypeCode is a static
  //    and const since it may have been placed in read-only memory by
  //    the compiler.  A const_cast<> can return undefined results in
  //    that case.

  CORBA::TypeCode_ptr mutable_tc =
    const_cast<TAO::TypeCode::Fixed<RefCountPolicy> *> (this);

  return CORBA::TypeCode::_duplicate (mutable_tc);
}

template <class RefCountPolicy>
CORBA::UShort
TAO::TypeCode::Fixed<RefCountPolicy>::fixed_digits_i (
  ACE_ENV_SINGLE_ARG_DECL_NOT_USED) const
{
  return this->digits_;
}

template <class RefCountPolicy>
CORBA::UShort
TAO::TypeCode::Fixed<RefCountPolicy>::fixed_scale_i (
  ACE_ENV_SINGLE_ARG_DECL_NOT_USED) const
{
  return this->scale_;
}


#endif  /* TAO_FIXED_TYPECODE_CPP */

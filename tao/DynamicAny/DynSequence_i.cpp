/* -*- C++ -*- */
// $Id$

// ===================================================================
//
// = LIBRARY
//    TAO
//
// = FILENAME
//    DynSequence_i.cpp
//
// = AUTHOR
//    Jeff Parsons <parsons@cs.wustl.edu>
//
// ===================================================================

#include "DynSequence_i.h"

#include "DynAnyFactory.h"
#include "tao/Marshal.h"

ACE_RCSID(DynamicAny, DynSequence_i, "$Id$")

// Constructors and destructor.

TAO_DynSequence_i::TAO_DynSequence_i (void)
{
}

TAO_DynSequence_i::~TAO_DynSequence_i (void)
{
}

void
TAO_DynSequence_i::init (const CORBA::Any& any,
                         CORBA::Environment &ACE_TRY_ENV)
{
  this->type_ = any.type ();
  this->current_index_ = 0;

  ACE_TRY
    {
      int tk =
        TAO_DynAnyFactory::unalias (this->type_.in (),
                               ACE_TRY_ENV);
      ACE_TRY_CHECK;

      // The type will be correct if this constructor called from a
      // factory function, but it could also be called by the user,
      // so.....
      if (tk == CORBA::tk_sequence)
        {
          // Get the CDR stream of the argument.
          ACE_Message_Block *mb = any._tao_get_cdr ();

          TAO_InputCDR cdr (mb,
                            any._tao_byte_order ());

          CORBA::ULong length;

          // If the any is a sequence, first 4 bytes of cdr hold the
          // length.
          cdr.read_ulong (length);

          // Resize the array.
          this->da_members_.size (length);

          // Get the type of the sequence elments.
          CORBA::TypeCode_var field_tc =
            this->get_element_type (ACE_TRY_ENV);
          ACE_TRY_CHECK;

          for (CORBA::ULong i = 0; i < length; i++)
            {
              // This Any constructor is a TAO extension.
              CORBA::Any field_any (field_tc.in (),
                                   0,
                                   cdr.byte_order (),
                                   cdr.start ());

              // This recursive step will call the correct constructor
              // based on the type of field_any.
              this->da_members_[i] =
                TAO_DynAnyFactory::make_dyn_any (field_any,
                                              ACE_TRY_ENV);
              ACE_TRY_CHECK;

              // Move to the next field in the CDR stream.
              (void) TAO_Marshal_Object::perform_skip (field_tc.in (),
                                                       &cdr,
                                                       ACE_TRY_ENV);
              ACE_TRY_CHECK;
            }
        }
      else
        ACE_THROW (DynamicAny::DynAnyFactory::InconsistentTypeCode ());
    }
  ACE_CATCHANY
    {
    }
  ACE_ENDTRY;
}

// Can't set the length from just the typecode, so we'll
// do it upon initialization.

void
TAO_DynSequence_i::init (CORBA_TypeCode_ptr tc,
                         CORBA::Environment &ACE_TRY_ENV)
{
  this->type_ = CORBA::TypeCode::_duplicate (tc);
  this->current_index_ = 0;
  ACE_TRY
    {
      // Need to check if called by user.
      int tk = TAO_DynAnyFactory::unalias (tc,
                                      ACE_TRY_ENV);
      ACE_TRY_CHECK;
      if (tk != CORBA::tk_sequence)
        ACE_THROW (DynamicAny::DynAnyFactory::InconsistentTypeCode ());
    }
  ACE_CATCHANY
    {
      // Do nothing
    }
  ACE_ENDTRY;
}

// ****************************************************************

TAO_DynSequence_i *
TAO_DynSequence_i::_narrow (CORBA::Object_ptr obj,
                       CORBA::Environment &)
{
  if (CORBA::is_nil (obj))
    return 0;

  return ACE_reinterpret_cast (TAO_DynSequence_i*,
             obj->_tao_QueryInterface (ACE_reinterpret_cast(ptr_arith_t,
                                           &TAO_DynSequence_i::_narrow))
             );
}

void*
TAO_DynSequence_i::_tao_QueryInterface (ptr_arith_t type)
{
  ptr_arith_t mytype =
    ACE_reinterpret_cast(ptr_arith_t,
                         &TAO_DynSequence_i::_narrow);
  if (type == mytype)
    {
      this->_add_ref ();
      return this;
    }
  return this->ACE_NESTED_CLASS (DynamicAny, DynAny::_tao_QueryInterface) (type);
}

// ****************************************************************

CORBA::TypeCode_ptr
TAO_DynSequence_i::get_element_type (CORBA::Environment& ACE_TRY_ENV)
{
  CORBA::TypeCode_var element_type =
    CORBA::TypeCode::_duplicate (this->type_.in ());

  // Strip away aliases (if any) on top of the outer type
  CORBA::TCKind kind = element_type->kind (ACE_TRY_ENV);
  ACE_CHECK_RETURN (CORBA_TypeCode::_nil ());

  while (kind != CORBA::tk_sequence)
    {
      element_type = element_type->content_type (ACE_TRY_ENV);
      ACE_CHECK_RETURN (CORBA_TypeCode::_nil ());

      kind = element_type->kind (ACE_TRY_ENV);
      ACE_CHECK_RETURN (CORBA_TypeCode::_nil ());
    }

  // Return the content type.
  CORBA::TypeCode_ptr retval = element_type->content_type (ACE_TRY_ENV);
  ACE_CHECK_RETURN (CORBA_TypeCode::_nil ());

  return retval;
}

// Functions specific to DynSequence

CORBA::ULong
TAO_DynSequence_i::get_length (CORBA::Environment &)
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ))
{
  return this->da_members_.size ();
}

void
TAO_DynSequence_i::set_length (CORBA::ULong length,
                               CORBA::Environment &)
    ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::InvalidValue
    ))
{
  this->da_members_.size (length);
}

DynamicAny::AnySeq *
TAO_DynSequence_i::get_elements (CORBA::Environment& ACE_TRY_ENV)
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ))
{
  CORBA::ULong length = this->da_members_.size ();

  if (length == 0)
    return 0;

  DynamicAny::AnySeq *elements;
  ACE_NEW_THROW_EX (elements,
                    DynamicAny::AnySeq (length),
                    CORBA::NO_MEMORY ());
  ACE_CHECK_RETURN (0);

  // We must do this explicitly.
  elements->length (length);

  // Initialize each Any.
  for (CORBA::ULong i = 0; i < length; i++)
    {
      CORBA::Any_var temp =
        this->da_members_[i]->to_any (ACE_TRY_ENV);

      ACE_CHECK_RETURN (0);

      (*elements)[i] = temp.in ();
    }

  return elements;
}

void
TAO_DynSequence_i::set_elements (const DynamicAny::AnySeq& value,
                                 CORBA::Environment& ACE_TRY_ENV)
    ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  CORBA::ULong length = value.length ();
  CORBA::ULong size = this->da_members_.size ();

  if (size == 0)
    {
      // Resize the array, it hasn't yet been initialized.
      this->da_members_.size (length);
    }
  else if (size != length)
    {
      ACE_THROW (DynamicAny::DynAny::InvalidValue ());
    }

  CORBA::TypeCode_var element_type =
    this->get_element_type (ACE_TRY_ENV);
  ACE_CHECK;

  CORBA::TypeCode_var value_tc;

  for (CORBA::ULong i = 0; i < length; i++)
    {
      // Check each arg element for type match.
      value_tc = value[i].type ();
      CORBA::Boolean equal = value_tc->equal (element_type.in (),
                                              ACE_TRY_ENV);
      ACE_CHECK;

      if (equal)
        {
          if (!CORBA::is_nil (this->da_members_[i].in ()))
            {
              this->da_members_[i]->destroy (ACE_TRY_ENV);
              ACE_CHECK;
            }

          this->da_members_[i] =
            TAO_DynAnyFactory::make_dyn_any (value[i],
                                          ACE_TRY_ENV);
          ACE_CHECK;
        }
      else
        {
          ACE_THROW (DynamicAny::DynAny::InvalidValue ());
        }
    }
}

DynamicAny::DynAnySeq *
TAO_DynSequence_i::get_elements_as_dyn_any (
      CORBA::Environment &
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ))
{
  return 0;
}

void
TAO_DynSequence_i::set_elements_as_dyn_any (
      const DynamicAny::DynAnySeq &,
      CORBA::Environment &
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
}

// ****************************************************************

CORBA::TypeCode_ptr
TAO_DynSequence_i::type (CORBA::Environment &)
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ))
{
  return CORBA::TypeCode::_duplicate (this->type_.in ());
}

void
TAO_DynSequence_i::assign (DynamicAny::DynAny_ptr dyn_any,
                           CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch
      ))
{
  // *dyn_any->to_any raises Invalid if arg is bad.
  CORBA_TypeCode_ptr tc = dyn_any->type (ACE_TRY_ENV);
  ACE_CHECK;

  CORBA::Boolean equal = this->type_.in ()->equal (tc,
                                                   ACE_TRY_ENV);
  ACE_CHECK;

  if (equal)
    {
      CORBA::Any_ptr any_ptr = dyn_any->to_any (ACE_TRY_ENV);
      ACE_CHECK;

      this->from_any (*any_ptr,
                      ACE_TRY_ENV);
      ACE_CHECK;
    }
  else
    {
      ACE_THROW (DynamicAny::DynAny::TypeMismatch ());
    }
}

void
TAO_DynSequence_i::from_any (const CORBA::Any& any,
                             CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA::TypeCode_var tc = any.type ();
  CORBA::Boolean equal = this->type_.in ()->equal (tc.in (),
                                                   ACE_TRY_ENV);
  ACE_CHECK;

  if (equal)
    {
      // Get the CDR stream of the argument.
      ACE_Message_Block *mb = any._tao_get_cdr ();

      TAO_InputCDR cdr (mb,
                        any._tao_byte_order ());

      CORBA::ULong arg_length;

      // If the any is a sequence, first 4 bytes of cdr hold the
      // length.
      cdr.read_ulong (arg_length);

      CORBA::ULong length = this->da_members_.size ();

      if (length == 0)
        {
          // Resize the array, it hasn't yet been initialized.
          this->da_members_.size (arg_length);
        }
      else if (length != arg_length)
        {
          ACE_THROW (DynamicAny::DynAny::TypeMismatch ());
        }

      CORBA::TypeCode_var field_tc =
        this->get_element_type (ACE_TRY_ENV);
      ACE_CHECK;

      for (CORBA::ULong i = 0;
           i < arg_length;
           i++)
        {
          // This Any constructor is a TAO extension.
          CORBA::Any field_any (field_tc.in (),
                               0,
                               cdr.byte_order (),
                               cdr.start ());

          if (!CORBA::is_nil (this->da_members_[i].in ()))
            {
              this->da_members_[i]->destroy (ACE_TRY_ENV);
              ACE_CHECK;
            }

          this->da_members_[i] =
            TAO_DynAnyFactory::make_dyn_any (field_any,
                                          ACE_TRY_ENV);
          ACE_CHECK;

          // Move to the next field in the CDR stream.
          (void) TAO_Marshal_Object::perform_skip (field_tc.in (),
                                                   &cdr,
                                                   ACE_TRY_ENV);
          ACE_CHECK;
        }
    }
  else
    {
      ACE_THROW (DynamicAny::DynAny::TypeMismatch ());
    }
}

CORBA::Any_ptr
TAO_DynSequence_i::to_any (CORBA::Environment& ACE_TRY_ENV)
      ACE_THROW_SPEC ((
                       CORBA::SystemException
      ))
{
  TAO_OutputCDR out_cdr;

  out_cdr.write_ulong (this->da_members_.size ());

  CORBA_TypeCode_var field_tc = this->get_element_type (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);

  for (CORBA::ULong i = 0; i < this->da_members_.size (); i++)
    {
      // @@@ (JP) This is a workaround until we implement the default
      // intial values defined in CORBA 2.3.1.
      if (!this->da_members_[i].in ())
        {
          ACE_THROW_RETURN (CORBA::BAD_INV_ORDER (),
                            0);
        }

      // Recursive step
      CORBA::Any_var field_any =
        this->da_members_[i]->to_any (ACE_TRY_ENV);
      ACE_CHECK_RETURN (0);

      ACE_Message_Block *field_mb =
        field_any->_tao_get_cdr ();

      TAO_InputCDR field_cdr (field_mb,
                              field_any->_tao_byte_order ());

      (void) TAO_Marshal_Object::perform_append (field_tc.in (),
                                                 &field_cdr,
                                                 &out_cdr,
                                                 ACE_TRY_ENV);
      ACE_CHECK_RETURN (0);
    }

  TAO_InputCDR in_cdr (out_cdr);

  CORBA::Any* retval;

  CORBA_TypeCode_ptr tc = this->type (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);

  ACE_NEW_THROW_EX (retval,
                    CORBA::Any (tc,
                               0,
                               in_cdr.byte_order (),
                               in_cdr.start ()),
                    CORBA::NO_MEMORY ());
  ACE_CHECK_RETURN (0);

  return retval;
}

CORBA::Boolean
TAO_DynSequence_i::equal (
    DynamicAny::DynAny_ptr,
    CORBA::Environment &ACE_TRY_ENV
  )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ))
{
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
}

void
TAO_DynSequence_i::destroy (CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ))
{
  // Do a deep destroy
  for (CORBA::ULong i = 0;
       i < this->da_members_.size ();
       i++)
    {
      if (!CORBA::is_nil (this->da_members_[i].in ()))
        {
          this->da_members_[i]->destroy (ACE_TRY_ENV);
          ACE_CHECK;
        }
    }
}

DynamicAny::DynAny_ptr
TAO_DynSequence_i::copy (CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ))
{
  CORBA::Any_ptr a = this->to_any (ACE_TRY_ENV);
  ACE_CHECK_RETURN (DynamicAny::DynAny::_nil ());

  DynamicAny::DynAny_ptr retval = TAO_DynAnyFactory::make_dyn_any (*a,
                                                          ACE_TRY_ENV);
  ACE_CHECK_RETURN (DynamicAny::DynAny::_nil ());

  return retval;
}

// The insert-primitive and get-primitive functions are required
// by the spec of all types of DynAny, although if the top level
// members aren't primitive types, these functions aren't too helpful.
// Also, while not mentioned in the spec, the example code seems to
// indicate that next() is called in the body of each of these, and
// it has been so implemented here.

// Insert functions

void
TAO_DynSequence_i::insert_boolean (CORBA::Boolean value,
                                   CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
  ACE_CHECK;

  CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
  ACE_CHECK;

  if (kind == CORBA::tk_boolean)
    {
      DynamicAny::DynAny_ptr dp = this->current_component (ACE_TRY_ENV);
      ACE_CHECK;

      dp->insert_boolean (value,
                          ACE_TRY_ENV);
      ACE_CHECK;

      this->next (ACE_TRY_ENV);
      ACE_CHECK;
    }
  else
    {
      ACE_THROW (DynamicAny::DynAny::InvalidValue ());
    }
}

void
TAO_DynSequence_i::insert_octet (CORBA::Octet value,
                                 CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
  ACE_CHECK;

  CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
  ACE_CHECK;

  if (kind == CORBA::tk_octet)
    {
      DynamicAny::DynAny_ptr dp = this->current_component (ACE_TRY_ENV);
      ACE_CHECK;

      dp->insert_octet (value,
                        ACE_TRY_ENV);
      ACE_CHECK;

      this->next (ACE_TRY_ENV);
      ACE_CHECK;
    }
  else
    {
      ACE_THROW (DynamicAny::DynAny::InvalidValue ());
    }
}

void
TAO_DynSequence_i::insert_char (CORBA::Char value,
                                CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
  ACE_CHECK;

  CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
  ACE_CHECK;

  if (kind == CORBA::tk_char)
    {
      DynamicAny::DynAny_ptr dp = this->current_component (ACE_TRY_ENV);
      ACE_CHECK;

      dp->insert_char (value,
                       ACE_TRY_ENV);
      ACE_CHECK;

      this->next (ACE_TRY_ENV);
      ACE_CHECK;
    }
  else
    {
      ACE_THROW (DynamicAny::DynAny::InvalidValue ());
    }
}

void
TAO_DynSequence_i::insert_short (CORBA::Short value,
                                 CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
  ACE_CHECK;

  CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
  ACE_CHECK;

  if (kind == CORBA::tk_short)
    {
      DynamicAny::DynAny_ptr dp = this->current_component (ACE_TRY_ENV);
      ACE_CHECK;

      dp->insert_short (value,
                        ACE_TRY_ENV);
      ACE_CHECK;

      this->next (ACE_TRY_ENV);
      ACE_CHECK;
    }
  else
    {
      ACE_THROW (DynamicAny::DynAny::InvalidValue ());
    }
}

void
TAO_DynSequence_i::insert_ushort (CORBA::UShort value,
                                  CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
  ACE_CHECK;

  CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
  ACE_CHECK;

  if (kind == CORBA::tk_ushort)
    {
      DynamicAny::DynAny_ptr dp = this->current_component (ACE_TRY_ENV);
      ACE_CHECK;

      dp->insert_ushort (value,
                         ACE_TRY_ENV);
      ACE_CHECK;

      this->next (ACE_TRY_ENV);
      ACE_CHECK;
    }
  else
    {
      ACE_THROW (DynamicAny::DynAny::InvalidValue ());
    }
}

void
TAO_DynSequence_i::insert_long (CORBA::Long value,
                                CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
  ACE_CHECK;

  CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
  ACE_CHECK;

  if (kind == CORBA::tk_long)
    {
      DynamicAny::DynAny_ptr dp = this->current_component (ACE_TRY_ENV);
      ACE_CHECK;

      dp->insert_long (value,
                       ACE_TRY_ENV);
      ACE_CHECK;

      this->next (ACE_TRY_ENV);
      ACE_CHECK;
    }
  else
    {
      ACE_THROW (DynamicAny::DynAny::InvalidValue ());
    }
}

void
TAO_DynSequence_i::insert_ulong (CORBA::ULong value,
                                 CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
  ACE_CHECK;

  CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
  ACE_CHECK;

  if (kind == CORBA::tk_ulong)
    {
      DynamicAny::DynAny_ptr dp = this->current_component (ACE_TRY_ENV);
      ACE_CHECK;

      dp->insert_ulong (value,
                        ACE_TRY_ENV);
      ACE_CHECK;

      this->next (ACE_TRY_ENV);
      ACE_CHECK;
    }
  else
    {
      ACE_THROW (DynamicAny::DynAny::InvalidValue ());
    }
}

void
TAO_DynSequence_i::insert_float (CORBA::Float value,
                                 CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
  ACE_CHECK;

  CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
  ACE_CHECK;

  if (kind == CORBA::tk_float)
    {
      DynamicAny::DynAny_ptr dp = this->current_component (ACE_TRY_ENV);
      ACE_CHECK;

      dp->insert_float (value,
                        ACE_TRY_ENV);
      ACE_CHECK;

      this->next (ACE_TRY_ENV);
      ACE_CHECK;
    }
  else
    {
      ACE_THROW (DynamicAny::DynAny::InvalidValue ());
    }
}

void
TAO_DynSequence_i::insert_double (CORBA::Double value,
                                  CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
  ACE_CHECK;

  CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
  ACE_CHECK;

  if (kind == CORBA::tk_double)
    {
      DynamicAny::DynAny_ptr dp = this->current_component (ACE_TRY_ENV);
      ACE_CHECK;

      dp->insert_double (value,
                         ACE_TRY_ENV);
      ACE_CHECK;

      this->next (ACE_TRY_ENV);
      ACE_CHECK;
    }
  else
    {
      ACE_THROW (DynamicAny::DynAny::InvalidValue ());
    }
}

void
TAO_DynSequence_i::insert_string (const char * value,
                                  CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
  ACE_CHECK;

  CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
  ACE_CHECK;

  if (kind == CORBA::tk_string)
    {
      DynamicAny::DynAny_ptr dp = this->current_component (ACE_TRY_ENV);
      ACE_CHECK;

      dp->insert_string (value,
                         ACE_TRY_ENV);
      ACE_CHECK;

      this->next (ACE_TRY_ENV);
      ACE_CHECK;
    }
  else
    {
      ACE_THROW (DynamicAny::DynAny::InvalidValue ());
    }
}

void
TAO_DynSequence_i::insert_reference (CORBA::Object_ptr value,
                                     CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
  ACE_CHECK;

  CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
  ACE_CHECK;

  if (kind == CORBA::tk_objref)
    {
      DynamicAny::DynAny_ptr dp = this->current_component (ACE_TRY_ENV);
      ACE_CHECK;

      dp->insert_reference (value,
                            ACE_TRY_ENV);
      ACE_CHECK;

      this->next (ACE_TRY_ENV);
      ACE_CHECK;
    }
  else
    {
      ACE_THROW (DynamicAny::DynAny::InvalidValue ());
    }
}

void
TAO_DynSequence_i::insert_typecode (CORBA::TypeCode_ptr value,
                                    CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
  ACE_CHECK;

  CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
  ACE_CHECK;

  if (kind == CORBA::tk_TypeCode)
    {
      DynamicAny::DynAny_ptr dp = this->current_component (ACE_TRY_ENV);
      ACE_CHECK;

      dp->insert_typecode (value,
                           ACE_TRY_ENV);
      ACE_CHECK;

      this->next (ACE_TRY_ENV);
      ACE_CHECK;
    }
  else
    {
      ACE_THROW (DynamicAny::DynAny::InvalidValue ());
    }
}

void
TAO_DynSequence_i::insert_longlong (CORBA::LongLong value,
                                    CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
  ACE_CHECK;

  CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
  ACE_CHECK;

  if (kind == CORBA::tk_longlong)
    {
      DynamicAny::DynAny_ptr dp = this->current_component (ACE_TRY_ENV);
      ACE_CHECK;

      dp->insert_longlong (value,
                           ACE_TRY_ENV);
      ACE_CHECK;

      this->next (ACE_TRY_ENV);
      ACE_CHECK;
    }
  else
    {
      ACE_THROW (DynamicAny::DynAny::InvalidValue ());
    }
}

void
TAO_DynSequence_i::insert_ulonglong (CORBA::ULongLong value,
                                     CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
  ACE_CHECK;

  CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
  ACE_CHECK;

  if (kind == CORBA::tk_ulonglong)
    {
      DynamicAny::DynAny_ptr dp = this->current_component (ACE_TRY_ENV);
      ACE_CHECK;

      dp->insert_ulonglong (value,
                            ACE_TRY_ENV);
      ACE_CHECK;

      this->next (ACE_TRY_ENV);
      ACE_CHECK;
    }
  else
    {
      ACE_THROW (DynamicAny::DynAny::InvalidValue ());
    }
}

void
TAO_DynSequence_i::insert_longdouble (
        CORBA::LongDouble,
        CORBA::Environment &ACE_TRY_ENV
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  ACE_THROW (CORBA::NO_IMPLEMENT ());
}

void
TAO_DynSequence_i::insert_wchar (CORBA::WChar value,
                                 CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
  ACE_CHECK;

  CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
  ACE_CHECK;

  if (kind == CORBA::tk_wchar)
    {
      DynamicAny::DynAny_ptr dp = this->current_component (ACE_TRY_ENV);
      ACE_CHECK;

      dp->insert_wchar (value,
                        ACE_TRY_ENV);
      ACE_CHECK;

      this->next (ACE_TRY_ENV);
      ACE_CHECK;
    }
  else
    {
      ACE_THROW (DynamicAny::DynAny::InvalidValue ());
    }
}

void
TAO_DynSequence_i::insert_wstring (
        const CORBA::WChar *,
        CORBA::Environment &ACE_TRY_ENV
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  ACE_THROW (CORBA::NO_IMPLEMENT ());
}

void
TAO_DynSequence_i::insert_any (const CORBA::Any& value,
                               CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
  ACE_CHECK;

  CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
  ACE_CHECK;

  if (kind == CORBA::tk_any)
    {
      DynamicAny::DynAny_ptr dp = this->current_component (ACE_TRY_ENV);
      ACE_CHECK;

      dp->insert_any (value,
                      ACE_TRY_ENV);
      ACE_CHECK;

      this->next (ACE_TRY_ENV);
      ACE_CHECK;
    }
  else
    {
      ACE_THROW (DynamicAny::DynAny::InvalidValue ());
    }
}

void
TAO_DynSequence_i::insert_dyn_any (
        DynamicAny::DynAny_ptr,
        CORBA::Environment &ACE_TRY_ENV
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  ACE_THROW (CORBA::NO_IMPLEMENT ());
}

#ifdef TAO_HAS_VALUETYPE
void
TAO_DynSequence_i::insert_val (
        CORBA::ValueBase_ptr,
        CORBA::Environment &ACE_TRY_ENV
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  ACE_THROW (CORBA::NO_IMPLEMENT ());
}
#endif /* TAO_HAS_VALUETYPE */

// ****************************************************************

// If the current component has not been intialized, these
// raise Invalid, which is not required by the spec, but which
// seems like a courteous thing to do.

CORBA::Boolean
TAO_DynSequence_i::get_boolean (CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA::Boolean val = 0;
  DynamicAny::DynAny_ptr dp = this->da_members_[this->current_index_].in ();

  if (dp)
    {
      CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      if (kind == CORBA::tk_boolean)
        {
          val = dp->get_boolean (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);

          this->next (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);
        }
      else
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            val);
        }
    }
  else
    {
      ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                        val);
    }

  return val;
}

CORBA::Octet
TAO_DynSequence_i::get_octet (CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA::Octet val = 0;
  DynamicAny::DynAny_ptr dp =
    this->da_members_[this->current_index_].in ();

  if (dp)
    {
      CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      if (kind == CORBA::tk_octet)
        {
          val = dp->get_octet (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);

          this->next (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);
        }
      else
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            val);
        }
    }
  else
    {
      ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                        val);
    }

  return val;
}

CORBA::Char
TAO_DynSequence_i::get_char (CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA::Char val = 0;
  DynamicAny::DynAny_ptr dp =
    this->da_members_[this->current_index_].in ();

  if (dp)
    {
      CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      if (kind == CORBA::tk_char)
        {
          val = dp->get_char (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);

          this->next (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);
        }
      else
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            val);
        }
    }
  else
    {
      ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                        val);
    }

  return val;
}

CORBA::Short
TAO_DynSequence_i::get_short (CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA::Short val = 0;
  DynamicAny::DynAny_ptr dp =
    this->da_members_[this->current_index_].in ();

  if (dp)
    {
      CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      if (kind == CORBA::tk_short)
        {
          val = dp->get_short (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);

          this->next (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);
        }
      else
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            val);
        }
    }
  else
    {
      ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                        val);
    }

  return val;
}

CORBA::UShort
TAO_DynSequence_i::get_ushort (CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA::UShort val = 0;
  DynamicAny::DynAny_ptr dp =
    this->da_members_[this->current_index_].in ();

  if (dp)
    {
      CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      if (kind == CORBA::tk_ushort)
        {
          val = dp->get_ushort (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);

          this->next (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);
        }
      else
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            val);
        }
    }
  else
    {
      ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                        val);
    }

  return val;
}

CORBA::Long
TAO_DynSequence_i::get_long (CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA::Long val = 0;
  DynamicAny::DynAny_ptr dp =
    this->da_members_[this->current_index_].in ();

  if (dp)
    {
      CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      if (kind == CORBA::tk_long)
        {
          val = dp->get_long (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);

          this->next (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);
        }
      else
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            val);
        }
    }
  else
    {
      ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                        val);
    }

  return val;
}

CORBA::ULong
TAO_DynSequence_i::get_ulong (CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA::ULong val = 0;
  DynamicAny::DynAny_ptr dp =
    this->da_members_[this->current_index_].in ();

  if (dp)
    {
      CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      if (kind == CORBA::tk_ulong)
        {
          val = dp->get_ulong (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);

          this->next (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);
        }
      else
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            val);
        }
    }
  else
    {
      ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                        val);
    }

  return val;
}

CORBA::Float
TAO_DynSequence_i::get_float (CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA::Float val = 0;
  DynamicAny::DynAny_ptr dp =
    this->da_members_[this->current_index_].in ();

  if (dp)
    {
      CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      if (kind == CORBA::tk_float)
        {
          val = dp->get_float (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);

          this->next (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);
        }
      else
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            val);
        }
    }
  else
    {
      ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                        val);
    }

  return val;
}

CORBA::Double
TAO_DynSequence_i::get_double (CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA::Double val = 0;
  DynamicAny::DynAny_ptr dp =
    this->da_members_[this->current_index_].in ();

  if (dp)
    {
      CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      if (kind == CORBA::tk_double)
        {
          val = dp->get_double (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);

          this->next (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);
        }
      else
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            val);
        }
    }
  else
    {
      ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                        val);
    }

  return val;
}

char *
TAO_DynSequence_i::get_string (CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA::Char *val = 0;
  DynamicAny::DynAny_ptr dp =
    this->da_members_[this->current_index_].in ();

  if (dp)
    {
      CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      if (kind == CORBA::tk_string)
        {
          val = dp->get_string (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);

          this->next (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);
        }
      else
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            val);
        }
    }
  else
    {
      ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                        val);
    }

  return val;
}

CORBA::Object_ptr
TAO_DynSequence_i::get_reference (CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA_Object_ptr val = 0;
  DynamicAny::DynAny_ptr dp =
    this->da_members_[this->current_index_].in ();

  if (dp)
    {
      CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      if (kind == CORBA::tk_objref)
        {
          val = dp->get_reference (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);

          this->next (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);
        }
      else
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            val);
        }
    }
  else
    {
      ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                        val);
    }

  return val;
}

CORBA::TypeCode_ptr
TAO_DynSequence_i::get_typecode (CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA_TypeCode_ptr val = 0;
  DynamicAny::DynAny_ptr dp =
    this->da_members_[this->current_index_].in ();

  if (dp)
    {
      CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      if (kind == CORBA::tk_TypeCode)
        {
          val = dp->get_typecode (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);

          this->next (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);
        }
      else
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            val);
        }
    }
  else
    {
      ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                        val);
    }

  return val;
}

CORBA::LongLong
TAO_DynSequence_i::get_longlong (CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
#if defined (ACE_LACKS_LONGLONG_T)
  CORBA::LongLong val = {0, 0};
#else  /* ! ACE_LACKS_LONGLONG_T */
  CORBA::LongLong val = 0;
#endif /* ! ACE_LACKS_LONGLONG_T */

  DynamicAny::DynAny_ptr dp =
    this->da_members_[this->current_index_].in ();

  if (dp)
    {
      CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      if (kind == CORBA::tk_longlong)
        {
          val = dp->get_longlong (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);

          this->next (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);
        }
      else
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            val);
        }
    }
  else
    {
      ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                        val);
    }

  return val;
}

CORBA::ULongLong
TAO_DynSequence_i::get_ulonglong (CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA::ULongLong val = 0;
  DynamicAny::DynAny_ptr dp =
    this->da_members_[this->current_index_].in ();

  if (dp)
    {
      CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      if (kind == CORBA::tk_ulonglong)
        {
          val = dp->get_ulonglong (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);

          this->next (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);
        }
      else
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            val);
        }
    }
  else
    {
      ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                        val);
    }

  return val;
}

CORBA::LongDouble
TAO_DynSequence_i::get_longdouble (
        CORBA::Environment &ACE_TRY_ENV
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA::LongDouble ret = ACE_CDR_LONG_DOUBLE_INITIALIZER;
  ACE_UNUSED_ARG (ret);
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), ret);
}

CORBA::WChar
TAO_DynSequence_i::get_wchar (CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA::WChar val = 0;
  DynamicAny::DynAny_ptr dp =
    this->da_members_[this->current_index_].in ();

  if (dp)
    {
      CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      if (kind == CORBA::tk_wchar)
        {
          val = dp->get_wchar (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);

          this->next (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);
        }
      else
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            val);
        }
    }
  else
    {
      ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                        val);
    }

  return val;
}

CORBA::WChar *
TAO_DynSequence_i::get_wstring (
        CORBA::Environment &ACE_TRY_ENV
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
}

CORBA::Any_ptr
TAO_DynSequence_i::get_any (CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  CORBA::Any_ptr val = 0;
  DynamicAny::DynAny_ptr dp =
    this->da_members_[this->current_index_].in ();

  if (dp)
    {
      CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      CORBA::TCKind kind = tc->kind (ACE_TRY_ENV);
      ACE_CHECK_RETURN (val);

      if (kind == CORBA::tk_any)
        {
          val = dp->get_any (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);

          this->next (ACE_TRY_ENV);
          ACE_CHECK_RETURN (val);
        }
      else
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            val);
        }
    }
  else
    {
      ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                        val);
    }

  return val;
}

DynamicAny::DynAny_ptr
TAO_DynSequence_i::get_dyn_any (
        CORBA::Environment &ACE_TRY_ENV
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), DynamicAny::DynAny::_nil ());
}

#ifdef TAO_HAS_VALUETYPE
CORBA::ValueBase_ptr
TAO_DynSequence_i::get_val (
        CORBA::Environment &ACE_TRY_ENV
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ))
{
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
}
#endif /* TAO_HAS_VALUETYPE */

// ****************************************************************

CORBA::Boolean
TAO_DynSequence_i::seek (CORBA::Long slot,
                         CORBA::Environment &)
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ))
{
  if (slot < 0 || slot >= (CORBA::Long) this->da_members_.size ())
    return 0;

  this->current_index_ = slot;
  return 1;
}

void
TAO_DynSequence_i::rewind (CORBA::Environment &)
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ))
{
  this->current_index_ = 0;
}

CORBA::Boolean
TAO_DynSequence_i::next (CORBA::Environment &)
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ))
{
  CORBA::Long size = (CORBA::Long) this->da_members_.size ();

  if (size == 0 || this->current_index_ + 1 == size)
    return 0;

  ++this->current_index_;
  return 1;
}

CORBA::ULong
TAO_DynSequence_i::component_count (
        CORBA::Environment &ACE_TRY_ENV
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ))
{
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
}

DynamicAny::DynAny_ptr
TAO_DynSequence_i::current_component (CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch
      ))
{
  if (this->da_members_.size () == 0)
    {
      return DynamicAny::DynAny::_nil ();
    }

  if (!this->da_members_[this->current_index_].in ())
    {
      CORBA_TypeCode_var tc = this->get_element_type (ACE_TRY_ENV);
      ACE_CHECK_RETURN (DynamicAny::DynAny::_nil ());

      this->da_members_[this->current_index_] =
        TAO_DynAnyFactory::make_dyn_any (tc.in (),
                                      ACE_TRY_ENV);
      ACE_CHECK_RETURN (DynamicAny::DynAny::_nil ());
    }

  return DynamicAny::DynAny::_duplicate (
             this->da_members_[this->current_index_].in ()
           );
}

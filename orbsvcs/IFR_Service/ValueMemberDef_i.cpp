/* -*- C++ -*- */
// $Id$

#include "Repository_i.h"
#include "ValueMemberDef_i.h"

ACE_RCSID(IFR_Service, ValueMemberDef_i, "$Id$")

TAO_ValueMemberDef_i::TAO_ValueMemberDef_i (
    TAO_Repository_i *repo,
    ACE_Configuration_Section_Key section_key
  )
  : TAO_IRObject_i (repo, section_key),
    TAO_Contained_i (repo, section_key)
{
}

TAO_ValueMemberDef_i::~TAO_ValueMemberDef_i (void)
{
}

CORBA::DefinitionKind
TAO_ValueMemberDef_i::def_kind (TAO_ENV_SINGLE_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  return CORBA::dk_ValueMember;
}

void
TAO_ValueMemberDef_i::destroy (TAO_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_WRITE_GUARD;

  this->destroy_i (TAO_ENV_SINGLE_ARG_PARAMETER);
}

void
TAO_ValueMemberDef_i::destroy_i (TAO_ENV_SINGLE_ARG_DECL_NOT_USED /* TAO_ENV_SINGLE_ARG_PARAMETER */)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
}

CORBA_Contained::Description *
TAO_ValueMemberDef_i::describe (TAO_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_READ_GUARD_RETURN (0);

  return this->describe_i (TAO_ENV_SINGLE_ARG_PARAMETER);
}

CORBA_Contained::Description *
TAO_ValueMemberDef_i::describe_i (TAO_ENV_SINGLE_ARG_DECL_NOT_USED /* TAO_ENV_SINGLE_ARG_PARAMETER */)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
  return 0;
}

CORBA::TypeCode_ptr
TAO_ValueMemberDef_i::type (TAO_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_READ_GUARD_RETURN (CORBA::TypeCode::_nil ());

  return this->type_i (TAO_ENV_SINGLE_ARG_PARAMETER);
}

CORBA::TypeCode_ptr
TAO_ValueMemberDef_i::type_i (TAO_ENV_SINGLE_ARG_DECL_NOT_USED /* TAO_ENV_SINGLE_ARG_PARAMETER */)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
  return 0;
}

CORBA_IDLType_ptr
TAO_ValueMemberDef_i::type_def (TAO_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_READ_GUARD_RETURN (CORBA_IDLType::_nil ());

  return this->type_def_i (TAO_ENV_SINGLE_ARG_PARAMETER);
}

CORBA_IDLType_ptr
TAO_ValueMemberDef_i::type_def_i (TAO_ENV_SINGLE_ARG_DECL_NOT_USED /* TAO_ENV_SINGLE_ARG_PARAMETER */)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
  return 0;
}

void
TAO_ValueMemberDef_i::type_def (CORBA_IDLType_ptr type_def
                                TAO_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_WRITE_GUARD;

  this->type_def_i (type_def
                    TAO_ENV_ARG_PARAMETER);
}

void
TAO_ValueMemberDef_i::type_def_i (CORBA_IDLType_ptr /* type_def */
                                  TAO_ENV_ARG_DECL_NOT_USED /* TAO_ENV_SINGLE_ARG_PARAMETER */)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
}

CORBA::Visibility
TAO_ValueMemberDef_i::access (TAO_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_READ_GUARD_RETURN (0);

  return this->access_i (TAO_ENV_SINGLE_ARG_PARAMETER);
}

CORBA::Visibility
TAO_ValueMemberDef_i::access_i (TAO_ENV_SINGLE_ARG_DECL_NOT_USED /* TAO_ENV_SINGLE_ARG_PARAMETER */ )
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
  return 0;
}

void
TAO_ValueMemberDef_i::access (CORBA::Visibility access
                              TAO_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_WRITE_GUARD;

  this->access (access
                TAO_ENV_ARG_PARAMETER);
}

void
TAO_ValueMemberDef_i::access_i (CORBA::Visibility /* access */
                                TAO_ENV_ARG_DECL_NOT_USED /* TAO_ENV_SINGLE_ARG_PARAMETER */ )
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
}


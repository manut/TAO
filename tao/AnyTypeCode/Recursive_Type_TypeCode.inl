// -*- C++ -*-
//
// $Id$

template <class TypeCodeBase, typename TypeCodeType, typename MemberArrayType>
ACE_INLINE
TAO::TypeCode::Recursive_Type<TypeCodeBase,
                              TypeCodeType,
                              MemberArrayType>::Recursive_Type (
  CORBA::TCKind kind,
  char const * id,
  char const * name,
  MemberArrayType const & fields,
  CORBA::ULong nfields)
  : TypeCodeBase (kind, id, name, fields, nfields)
  , lock_ ()
  , in_recursion_ (false)
{
  // ACE_ASSERT (kind != CORBA::tk_except);
}

template <class TypeCodeBase, typename TypeCodeType, typename MemberArrayType>
ACE_INLINE
TAO::TypeCode::Recursive_Type<TypeCodeBase,
                              TypeCodeType,
                              MemberArrayType>::Recursive_Type (
  char const * id,
  char const * name,
#if defined (__BORLANDC__) && (__BORLANDC__ < 0x572)
  TypeCodeType discriminant_type,
#else
  TypeCodeType const & discriminant_type,
#endif
  MemberArrayType const & cases,
  CORBA::ULong ncases,
  CORBA::Long default_index)
  : TypeCodeBase (id,
                  name,
                  discriminant_type,
                  cases,
                  ncases,
                  default_index)
  , lock_ ()
  , in_recursion_ (false)
{
}

template <class TypeCodeBase, typename TypeCodeType, typename MemberArrayType>
ACE_INLINE
TAO::TypeCode::Recursive_Type<TypeCodeBase,
                              TypeCodeType,
                              MemberArrayType>::Recursive_Type (
  CORBA::TCKind kind,
  char const * id,
  char const * name,
  CORBA::ValueModifier modifier,
#if defined (__BORLANDC__) && (__BORLANDC__ < 0x572)
  TypeCodeType concrete_base,
#else
  TypeCodeType const & concrete_base,
#endif
  MemberArrayType const & fields,
  CORBA::ULong nfields)
  : TypeCodeBase (kind,
                  id,
                  name,
                  modifier,
                  concrete_base,
                  fields,
                  nfields)
  , lock_ ()
  , in_recursion_ (false)
{
}

template <class TypeCodeBase, typename TypeCodeType, typename MemberArrayType>
ACE_INLINE
TAO::TypeCode::Recursive_Type<TypeCodeBase,
                              TypeCodeType,
                              MemberArrayType>::Recursive_Type (
  CORBA::TCKind kind,
  char const * id)
  : TypeCodeBase (kind, id)
  , lock_ ()
  , in_recursion_ (false)
{
//   ACE_ASSERT (kind == CORBA::tk_struct
//               || kind == CORBA::tk_union
//               || kind == CORBA::tk_value
//               || kind == CORBA::tk_event);
}

template <class TypeCodeBase, typename TypeCodeType, typename MemberArrayType>
ACE_INLINE void
TAO::TypeCode::Recursive_Type<TypeCodeBase,
                              TypeCodeType,
                              MemberArrayType>::struct_parameters (
  char const * name,
  MemberArrayType const & fields,
  CORBA::ULong nfields)
{
  this->base_attributes_.name (name);
  this->fields_  = fields;
  this->nfields_ = nfields;
}

template <class TypeCodeBase, typename TypeCodeType, typename MemberArrayType>
ACE_INLINE void
TAO::TypeCode::Recursive_Type<TypeCodeBase,
                              TypeCodeType,
                              MemberArrayType>::union_parameters (
  char const * name,
#if defined (__BORLANDC__) && (__BORLANDC__ < 0x572)
  TypeCodeType discriminant_type,
#else
  TypeCodeType const & discriminant_type,
#endif
  MemberArrayType const & cases,
  CORBA::ULong ncases,
  CORBA::Long default_index)
{
  this->base_attributes_.name (name);
  this->discriminant_type_ = discriminant_type;
  this->cases_             = cases;
  this->ncases_            = ncases;
  this->default_index_     = default_index;
}

template <class TypeCodeBase, typename TypeCodeType, typename MemberArrayType>
ACE_INLINE void
TAO::TypeCode::Recursive_Type<TypeCodeBase,
                              TypeCodeType,
                              MemberArrayType>::valuetype_parameters (
  char const * name,
  CORBA::ValueModifier modifier,
#if defined (__BORLANDC__) && (__BORLANDC__ < 0x572)
  TypeCodeType concrete_base,
#else
  TypeCodeType const & concrete_base,
#endif
  MemberArrayType const & fields,
  CORBA::ULong nfields)
{
  this->base_attributes_.name (name);
  this->type_modifier_ = modifier;
  this->concrete_base_ = concrete_base;
  this->fields_        = fields;
  this->nfields_       = nfields;
}

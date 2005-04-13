// -*- C++ -*-
//
// $Id$

template <typename StringType,
          typename TypeCodeType,
          class CaseArrayType,
          class RefCountPolicy>
ACE_INLINE
TAO::TypeCode::Union<StringType,
                     TypeCodeType,
                     CaseArrayType,
                     RefCountPolicy>::Union (
  char const * id,
  char const * name,
  TypeCodeType const & discriminant_type,
  CaseArrayType const & cases,
  CORBA::ULong ncases,
  CORBA::Long default_index)
  : CORBA::TypeCode (CORBA::tk_union)
  , RefCountPolicy ()
  , base_attributes_ (id, name)
  , discriminant_type_ (discriminant_type)
  , default_index_ (default_index)
  , ncases_ (ncases)
  , cases_ (cases)
{
}

template <typename StringType,
          typename TypeCodeType,
          typename CaseArrayType,
          class RefCountPolicy>
ACE_INLINE CORBA::ULong
TAO::TypeCode::Union<StringType,
                     TypeCodeType,
                     CaseArrayType,
                     RefCountPolicy>::case_count (void) const
{
  return this->ncases_;
}

template <typename StringType,
          typename TypeCodeType,
          typename CaseArrayType,
          class RefCountPolicy>
ACE_INLINE typename TAO::TypeCode::Union<StringType,
                                         TypeCodeType,
                                         CaseArrayType,
                                         RefCountPolicy>::case_type const &
TAO::TypeCode::Union<StringType,
                     TypeCodeType,
                     CaseArrayType,
                     RefCountPolicy>::the_case (CORBA::ULong index) const
{
  return *this->cases_[index];
}

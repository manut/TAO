// This may look like C, but it's really -*- C++ -*-

//=============================================================================
/**
 *  @file    TypeCodeFactory_Adapter_Impl.h
 *
 *  $Id$
 *
 *  @author  Jeff Parsons <parsons@cs.wustl.edu>
 */
//=============================================================================


#ifndef TAO_TYPECODEFACTORY_ADAPTER_IMPL_H
#define TAO_TYPECODEFACTORY_ADAPTER_IMPL_H
#include /**/ "ace/pre.h"

#include "typecodefactory_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/TypeCodeFactory_Adapter.h"
#include "ace/Service_Config.h"
#include "tao/default_environment.h"

/**
 * @class TAO_TypeCodeFactory_Adapter_Impl
 *
 * @brief TAO_TypeCodeFactory_Adapter_Impl.
 *
 * Class that adapts the CORBA::ORB create_*_tc functions
 * to use the TypeCodeFactory. This is the derived class
 * that contains the actual implementations.
 */
class TAO_TypeCodeFactory_Export TAO_TypeCodeFactory_Adapter_Impl
  : public TAO_TypeCodeFactory_Adapter
{
public:
  virtual ~TAO_TypeCodeFactory_Adapter_Impl (void);

  virtual CORBA::TypeCode_ptr create_struct_tc (
      const char *id,
      const char *name,
      const CORBA::StructMemberSeq &members
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)

    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_union_tc (
      const char *id,
      const char *name,
      CORBA::TypeCode_ptr discriminator_type,
      const CORBA::UnionMemberSeq &members
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)

    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_enum_tc (
      const char *id,
      const char *name,
      const CORBA::EnumMemberSeq &members
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)

    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_alias_tc (
      const char *id,
      const char *name,
      CORBA::TypeCode_ptr original_type
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)

    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_exception_tc (
      const char *id,
      const char *name,
      const CORBA::StructMemberSeq &members
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)

    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_interface_tc (
      const char *id,
      const char *name
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)

    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_string_tc (
      CORBA::ULong bound
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)

    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_wstring_tc (
      CORBA::ULong bound
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)

    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_fixed_tc (
      CORBA::UShort digits,
      CORBA::UShort scale
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)

    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_sequence_tc (
      CORBA::ULong bound,
      CORBA::TypeCode_ptr element_type
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)

    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_array_tc (
      CORBA::ULong length,
      CORBA::TypeCode_ptr element_type
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)

    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_value_tc (
      const char *id,
      const char *name,
      CORBA::ValueModifier type_modifier,
      CORBA::TypeCode_ptr concrete_base,
      const CORBA::ValueMemberSeq &members
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)

    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_value_box_tc (
      const char *id,
      const char *name,
      CORBA::TypeCode_ptr boxed_type
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)

    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_native_tc (
      const char *id,
      const char *name
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)

    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_recursive_tc (
      const char *id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)

    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_abstract_interface_tc (
      const char *id,
      const char *name
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)

    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_local_interface_tc (
      const char *id,
      const char *name
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)

    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_component_tc (
      const char *id,
      const char *name
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_home_tc (
      const char *id,
      const char *name
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::TypeCode_ptr create_event_tc (
      const char *id,
      const char *name,
      CORBA::ValueModifier type_modifier,
      CORBA::TypeCode_ptr concrete_base,
      const CORBA::ValueMemberSeq &members
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((CORBA::SystemException));

  /**
   * @name TAO-specific TypeCode factory methods.
   *
   * Factory methods that has no corresponding TypeCodeFactory IDL,
   * i.e. they are specific to TAO.
   */
  //@{
  /// Extract a TypeCode @a tc from the given CDR stream @a cdr.
  virtual bool extract_typecode (TAO_InputCDR & cdr,
                                 CORBA::TypeCode_ptr & tc);

  /// Create an enumeration TypeCode.
  virtual CORBA::TypeCode_ptr create_enum_tc (
    char const * id,
    char const * name,
    ACE_Array_Base<CORBA::String_var> const & enumerators,
    CORBA::ULong ncases
    ACE_ENV_ARG_DECL);

  /// Create a structure or exception TypeCode.
  virtual CORBA::TypeCode_ptr create_struct_except_tc (
    CORBA::TCKind,
    char const * id,
    char const * name,
    ACE_Array_Base<
      TAO::TypeCode::Struct_Field<CORBA::String_var,
                                  CORBA::TypeCode_var> > const & fields,
    CORBA::ULong nfields
    ACE_ENV_ARG_DECL);

  /// Create a union TypeCode.
  virtual CORBA::TypeCode_ptr create_union_tc (
    char const * id,
    char const * name,
    CORBA::TypeCode_ptr discriminant_type,
    ACE_Array_Base<TAO::TypeCode::Case<CORBA::String_var,
                                       CORBA::TypeCode_var> > const & cases,
    CORBA::ULong ncases,
    CORBA::Long default_index,
    char const * default_case_name,
    CORBA::TypeCode_ptr default_case_type
    ACE_ENV_ARG_DECL);

  /// Create a valuetype or eventtype TypeCode.
  virtual CORBA::TypeCode_ptr create_value_event_tc (
    CORBA::TCKind,
    char const * id,
    char const * name,
    CORBA::ValueModifier modifier,
    CORBA::TypeCode_ptr concrete_base,
    ACE_Array_Base<
      TAO::TypeCode::Value_Field<CORBA::String_var,
                                 CORBA::TypeCode_var> > const & fields,
    CORBA::ULong nfields
    ACE_ENV_ARG_DECL);
  //@}


  /// Used to force the initialization of the ORB code.
  static int Initializer (void);
};

ACE_STATIC_SVC_DECLARE (TAO_TypeCodeFactory_Adapter_Impl)
ACE_FACTORY_DECLARE (TAO_TypeCodeFactory, TAO_TypeCodeFactory_Adapter_Impl)

#if defined(ACE_HAS_BROKEN_STATIC_CONSTRUCTORS)

typedef int (*TAO_Module_Initializer) (void);

static TAO_Module_Initializer
TAO_Requires_TypeCodeFactory_Initializer =
  &TAO_TypeCodeFactory_Adapter_Impl::Initializer;

#else

static int
TAO_Requires_TypeCodeFactory_Initializer =
  TAO_TypeCodeFactory_Adapter_Impl::Initializer ();

#endif /* ACE_HAS_BROKEN_STATIC_CONSTRUCTORS */

#include /**/ "ace/post.h"
#endif /* TAO_TYPECODEFACTORY_ADAPTER_IMPL_H */

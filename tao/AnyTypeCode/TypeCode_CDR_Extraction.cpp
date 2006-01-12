// $Id$

#include "TypeCode_CDR_Extraction.h"

#include "TypeCode_Constants.h"
#include "True_RefCount_Policy.h"

#include "Alias_TypeCode.h"
#include "Enum_TypeCode.h"
#include "Fixed_TypeCode.h"
#include "Objref_TypeCode.h"
#include "Sequence_TypeCode.h"
#include "String_TypeCode.h"
#include "Struct_TypeCode.h"
#include "Union_TypeCode.h"
#include "Value_TypeCode.h"
#include "Any.h"

#include "Recursive_Type_TypeCode.h"

#include "TypeCode_Case_T.h"
#include "TypeCode_Struct_Field.h"
#include "TypeCode_Value_Field.h"

#include "tao/CDR.h"

#include "ace/Array_Base.h"
#include "ace/Value_Ptr.h"


ACE_RCSID (tao,
           TypeCode_CDR_Extraction,
           "$Id$")

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO
{
  namespace TypeCodeFactory
  {
    // An array of TC_Info objects is used instead of a map of
    // repository IDs to TypeCodes since it is presumed that the
    // number of directly or indirectly embedded types in a TypeCode
    // capable of holding another TypeCode will be small enough to
    // make traversing a list faster than performing a map lookup.
    // Use a simple array also reduces static and run-time footprint.

    struct TC_Info
    {
      /// Constructor.
      TC_Info (void) : id (0), type () {}

      /// Repository ID.
      char const * id;

      /// TypeCode
      CORBA::TypeCode_ptr type;
    };

    typedef ACE_Array_Base<TC_Info> TC_Info_List;
  }
}

namespace
{
  bool start_cdr_encap_extraction (TAO_InputCDR & cdr)
  {
    CORBA::Boolean byte_order;

    // Don't bother demarshaling the encapsulation length.  Prefer
    // speed over early error checking.  Any CDR length related
    // failures will be detected when demarshaling the remainder of
    // the complex parameter list TypeCode.

    if (!(cdr.skip_ulong () // Skip encapsulation length.
          && cdr >> TAO_InputCDR::to_boolean (byte_order)))
      return false;

    cdr.reset_byte_order (byte_order);

    return true;
  }

  // ---------------------------------------------------------

  CORBA::ULong const TYPECODE_INDIRECTION = 0xffffffff;

  // ---------------------------------------------------------

  // Use an ACE::Value_Ptr to provide exception safety and proper
  // copying semantics.
  typedef ACE::Value_Ptr<TAO::TypeCode::Case<CORBA::String_var, CORBA::TypeCode_var> > union_elem_type;
  typedef ACE_Array_Base<union_elem_type> union_case_array_type;

  // ------------------------------------------------------------

  /// Demarshal a TypeCode.
  bool tc_demarshal (TAO_InputCDR & cdr,
                     CORBA::TypeCode_ptr & tc,
                     TAO::TypeCodeFactory::TC_Info_List & infos);

  /// Demarshal an indirected TypeCode.
  bool tc_demarshal_indirection (TAO_InputCDR & cdr,
                                 CORBA::TypeCode_ptr & tc,
                                 TAO::TypeCodeFactory::TC_Info_List & infos);

  bool find_recursive_tc (char const * id,
                          CORBA::TypeCode_ptr & tc,
                          TAO::TypeCodeFactory::TC_Info_List & infos)
  {
    // See comments above for rationale behind using an array instead
    // of a map.

    size_t const len = infos.size ();

    for (size_t i = 0; i < len; ++i)
      {
        TAO::TypeCodeFactory::TC_Info & info = infos[i];

        if (ACE_OS::strcmp (info.id, id) == 0)
          {
            tc = info.type;
            return true;
          }
      }

    return false;
  }
}

bool
TAO::TypeCodeFactory::tc_null_factory (CORBA::TCKind,
                                       TAO_InputCDR &,
                                       CORBA::TypeCode_ptr & tc,
                                       TC_Info_List &)
{
  tc = CORBA::TypeCode::_duplicate (CORBA::_tc_null);

  return true;
}

bool
TAO::TypeCodeFactory::tc_void_factory (CORBA::TCKind,
                                       TAO_InputCDR &,
                                       CORBA::TypeCode_ptr & tc,
                                       TC_Info_List &)
{
  tc = CORBA::TypeCode::_duplicate (CORBA::_tc_void);

  return true;
}

bool
TAO::TypeCodeFactory::tc_short_factory (CORBA::TCKind,
                                        TAO_InputCDR &,
                                        CORBA::TypeCode_ptr & tc,
                                        TC_Info_List &)
{
  tc = CORBA::TypeCode::_duplicate (CORBA::_tc_short);

  return true;
}

bool
TAO::TypeCodeFactory::tc_long_factory (CORBA::TCKind,
                                       TAO_InputCDR &,
                                       CORBA::TypeCode_ptr & tc,
                                       TC_Info_List &)
{
  tc = CORBA::TypeCode::_duplicate (CORBA::_tc_long);

  return true;
}

bool
TAO::TypeCodeFactory::tc_ushort_factory (CORBA::TCKind,
                                         TAO_InputCDR &,
                                         CORBA::TypeCode_ptr & tc,
                                         TC_Info_List &)
{
  tc = CORBA::TypeCode::_duplicate (CORBA::_tc_ushort);

  return true;
}

bool
TAO::TypeCodeFactory::tc_ulong_factory (CORBA::TCKind,
                                        TAO_InputCDR &,
                                        CORBA::TypeCode_ptr & tc,
                                        TC_Info_List &)
{
  tc = CORBA::TypeCode::_duplicate (CORBA::_tc_ulong);

  return true;
}

bool
TAO::TypeCodeFactory::tc_float_factory (CORBA::TCKind,
                                        TAO_InputCDR &,
                                        CORBA::TypeCode_ptr & tc,
                                        TC_Info_List &)
{
  tc = CORBA::TypeCode::_duplicate (CORBA::_tc_float);

  return true;
}

bool
TAO::TypeCodeFactory::tc_double_factory (CORBA::TCKind,
                                         TAO_InputCDR &,
                                         CORBA::TypeCode_ptr & tc,
                                         TC_Info_List &)
{
  tc = CORBA::TypeCode::_duplicate (CORBA::_tc_double);

  return true;
}

bool
TAO::TypeCodeFactory::tc_boolean_factory (CORBA::TCKind,
                                          TAO_InputCDR &,
                                          CORBA::TypeCode_ptr & tc,
                                          TC_Info_List &)
{
  tc = CORBA::TypeCode::_duplicate (CORBA::_tc_boolean);

  return true;
}

bool
TAO::TypeCodeFactory::tc_char_factory (CORBA::TCKind,
                                       TAO_InputCDR &,
                                       CORBA::TypeCode_ptr & tc,
                                       TC_Info_List &)
{
  tc = CORBA::TypeCode::_duplicate (CORBA::_tc_char);

  return true;
}

bool
TAO::TypeCodeFactory::tc_octet_factory (CORBA::TCKind,
                                        TAO_InputCDR &,
                                        CORBA::TypeCode_ptr & tc,
                                        TC_Info_List &)
{
  tc = CORBA::TypeCode::_duplicate (CORBA::_tc_octet);

  return true;
}

bool
TAO::TypeCodeFactory::tc_any_factory (CORBA::TCKind,
                                      TAO_InputCDR &,
                                      CORBA::TypeCode_ptr & tc,
                                      TC_Info_List &)
{
  tc = CORBA::TypeCode::_duplicate (CORBA::_tc_any);

  return true;
}

bool
TAO::TypeCodeFactory::tc_TypeCode_factory (CORBA::TCKind,
                                           TAO_InputCDR &,
                                           CORBA::TypeCode_ptr & tc,
                                           TC_Info_List &)
{
  tc = CORBA::TypeCode::_duplicate (CORBA::_tc_TypeCode);

  return true;
}

bool
TAO::TypeCodeFactory::tc_Principal_factory (CORBA::TCKind,
                                            TAO_InputCDR &,
                                            CORBA::TypeCode_ptr & tc,
                                            TC_Info_List &)
{
  tc = CORBA::TypeCode::_duplicate (CORBA::_tc_Principal);

  return true;
}

bool
TAO::TypeCodeFactory::tc_objref_factory (CORBA::TCKind kind,
                                         TAO_InputCDR & cdr,
                                         CORBA::TypeCode_ptr & tc,
                                         TC_Info_List &)
{
  // The remainder of a tk_objref TypeCode is encoded in a CDR
  // encapsulation.
  if (!start_cdr_encap_extraction (cdr))
    return false;

  // Extract the repository ID and name.
  CORBA::String_var id;
  if (!(cdr >> TAO_InputCDR::to_string (id.out (), 0)))
    return false;

  static char const Object_id[]    = "IDL:omg.org/CORBA/Object:1.0";
  static char const CCMObject_id[] = "IDL:omg.org/CORBA/CCMObject:1.0";
  static char const CCMHome_id[]   = "IDL:omg.org/CORBA/CCMHome:1.0";

  char const * tc_constant_id = "";

  switch (kind)
    {
    case CORBA::tk_component:
      tc_constant_id = CCMObject_id;
      break;
    case CORBA::tk_home:
      tc_constant_id = CCMHome_id;
      break;
    case CORBA::tk_objref:
      tc_constant_id = Object_id;
      break;
    default:
      break;
    }

  if (ACE_OS::strcmp (id.in (),  // len >= 0!!!
                      tc_constant_id) == 0)
    {
      if (!cdr.skip_string ())  // No need to demarshal the name.
        return false;

      CORBA::TypeCode_ptr tc_constant = CORBA::TypeCode::_nil ();
      switch (kind)
        {
        case CORBA::tk_component:
          tc_constant = CORBA::_tc_Component;
          break;
        case CORBA::tk_home:
          tc_constant = CORBA::_tc_Home;
          break;
        case CORBA::tk_objref:
          tc_constant = CORBA::_tc_Object;
          break;
        default:
          break;
        }

      // No need to create a TypeCode.  Just use the TypeCode
      // constant.
      tc =
        CORBA::TypeCode::_duplicate (tc_constant);
    }
  else
    {
      CORBA::String_var name;

      if (!(cdr >> TAO_InputCDR::to_string (name.out (), 0)))
        return false;

      typedef TAO::TypeCode::Objref<CORBA::String_var,
                                    TAO::True_RefCount_Policy> typecode_type;

      ACE_NEW_RETURN (tc,
                      typecode_type (kind,
                                     id.in (),
                                     name.in ()),
                      false);
    }

  return true;
}

bool
TAO::TypeCodeFactory::tc_struct_factory (CORBA::TCKind kind,
                                         TAO_InputCDR & cdr,
                                         CORBA::TypeCode_ptr & tc,
                                         TC_Info_List & infos)
{
  ACE_ASSERT (kind == CORBA::tk_struct || kind == CORBA::tk_except);

  // The remainder of a tk_struct/tk_except TypeCode is encoded in
  // a CDR encapsulation.
  if (!start_cdr_encap_extraction (cdr))
    return false;

  // Extract the repository ID, name and number of fields.
  CORBA::String_var id, name;
  CORBA::ULong nfields;

  if (!(cdr >> TAO_InputCDR::to_string (id.out (), 0)
        && cdr >> TAO_InputCDR::to_string (name.out (), 0)
        && cdr >> nfields))
    return false;

  typedef ACE_Array_Base<TAO::TypeCode::Struct_Field<CORBA::String_var,
                                                     CORBA::TypeCode_var> >
    member_array_type;

  member_array_type fields (nfields);

  for (CORBA::ULong i = 0; i < nfields; ++i)
    {
      if (!(cdr >> TAO_InputCDR::to_string (fields[i].name.out (), 0)
            && tc_demarshal (cdr, fields[i].type.out (), infos)))
        return false;
    }

  typedef TAO::TypeCode::Struct<
    CORBA::String_var,
    CORBA::TypeCode_var,
    member_array_type,
    TAO::True_RefCount_Policy> typecode_type;


  // Check if struct TypeCode is recursive.
  if (kind == CORBA::tk_struct && find_recursive_tc (id.in (), tc, infos))
    {
      // Set remaining parameters.

      typedef TAO::TypeCode::Recursive_Type<typecode_type,
                                            CORBA::TypeCode_var,
                                            member_array_type>
        recursive_typecode_type;

      recursive_typecode_type * const rtc =
        dynamic_cast<recursive_typecode_type *> (tc);

      ACE_ASSERT (rtc);

      rtc->struct_parameters (name.in (),
                              fields,
                              nfields);
    }
  else
    {
      ACE_NEW_RETURN (tc,
                      typecode_type (kind,
                                     id.in (),
                                     name.in (),
                                     fields,     // Will be copied.
                                     nfields),
                      false);
    }

  return true;
}

bool
TAO::TypeCodeFactory::tc_union_factory (CORBA::TCKind /* kind */,
                                        TAO_InputCDR & cdr,
                                        CORBA::TypeCode_ptr & tc,
                                        TC_Info_List & infos)
{
  // The remainder of a tk_enum TypeCode is encoded in a CDR
  // encapsulation.

  if (!start_cdr_encap_extraction (cdr))
    return false;

  // Extract the repository ID, name, discriminant type, default index
  // and case count.
  CORBA::String_var id, name;
  CORBA::TypeCode_var discriminant_type;
  CORBA::Long default_index = -1;
  CORBA::ULong ncases = 0;  // Just 'n case :-)

  if (!(cdr >> TAO_InputCDR::to_string (id.out (), 0)
        && cdr >> TAO_InputCDR::to_string (name.out (), 0)
        && cdr >> discriminant_type.out ())) // No need to use tc_demarshal()
    return false;

  ACE_DECLARE_NEW_CORBA_ENV;
  CORBA::TCKind const discriminant_kind =
    discriminant_type->kind (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (false);

  // Check for valid discriminant type.
  if (!(discriminant_kind == CORBA::tk_enum
        || discriminant_kind == CORBA::tk_ulong
        || discriminant_kind == CORBA::tk_long
        || discriminant_kind == CORBA::tk_ushort
        || discriminant_kind == CORBA::tk_short
        || discriminant_kind == CORBA::tk_char
        || discriminant_kind == CORBA::tk_boolean
        || discriminant_kind == CORBA::tk_longlong
        || discriminant_kind == CORBA::tk_ulonglong))
    return false;

  if (!(cdr >> default_index
        && default_index >= -1
        && cdr >> ncases))
    return false;

  typedef union_elem_type       elem_type;
  typedef union_case_array_type case_array_type;

  case_array_type cases (ncases);

  for (CORBA::ULong i = 0; i < ncases; ++i)
    {
      elem_type & member = cases[i];

      TAO::TypeCode::Case<CORBA::String_var, CORBA::TypeCode_var> * the_case;

      // Ugly.  *sigh*
      switch (discriminant_kind)
        {
        case CORBA::tk_enum:  // Enumerators are encoded as unsigned longs.
        case CORBA::tk_ulong:
          {
            CORBA::ULong label;
            if (!(cdr >> label))
              return false;

            typedef TypeCode::Case_T<CORBA::ULong,
                                     CORBA::String_var,
                                     CORBA::TypeCode_var> case_type;

            ACE_NEW_RETURN (the_case,
                            case_type (label),
                            false);
          }
          break;
        case CORBA::tk_long:
          {
            CORBA::Long label;
            if (!(cdr >> label))
              return false;

            typedef TypeCode::Case_T<CORBA::Long,
                                     CORBA::String_var,
                                     CORBA::TypeCode_var> case_type;

            ACE_NEW_RETURN (the_case,
                            case_type (label),
                            false);
          }
          break;
        case CORBA::tk_ushort:
          {
            CORBA::UShort label;
            if (!(cdr >> label))
              return false;

            typedef TypeCode::Case_T<CORBA::UShort,
                                     CORBA::String_var,
                                     CORBA::TypeCode_var> case_type;

            ACE_NEW_RETURN (the_case,
                            case_type (label),
                            false);
          }
          break;
        case CORBA::tk_short:
          {
            CORBA::Short label;
            if (!(cdr >> label))
              return false;

            typedef TypeCode::Case_T<CORBA::Short,
                                     CORBA::String_var,
                                     CORBA::TypeCode_var> case_type;

            ACE_NEW_RETURN (the_case,
                            case_type (label),
                            false);
          }
          break;
        case CORBA::tk_char:
          {
            CORBA::Char label;
            if (!(cdr >> CORBA::Any::to_char (label)))
              return false;

            typedef TypeCode::Case_T<CORBA::Char,
                                     CORBA::String_var,
                                     CORBA::TypeCode_var> case_type;

            ACE_NEW_RETURN (the_case,
                            case_type (label),
                            false);
          }
          break;
        case CORBA::tk_boolean:
          {
            CORBA::Boolean label;
            if (!(cdr >> CORBA::Any::to_boolean (label)))
              return false;

            typedef TypeCode::Case_T<CORBA::Boolean,
                                     CORBA::String_var,
                                     CORBA::TypeCode_var> case_type;

            ACE_NEW_RETURN (the_case,
                            case_type (label),
                            false);
          }
          break;
        case CORBA::tk_longlong:
          {
            CORBA::LongLong label;
            if (!(cdr >> label))
              return false;

            typedef TypeCode::Case_T<CORBA::LongLong,
                                     CORBA::String_var,
                                     CORBA::TypeCode_var> case_type;

            ACE_NEW_RETURN (the_case,
                            case_type (label),
                            false);
          }
          break;
#if !defined (ACE_LACKS_LONGLONG_T)
        case CORBA::tk_ulonglong:
          {
            CORBA::ULongLong label;
            if (!(cdr >> label))
              return false;

            typedef TypeCode::Case_T<CORBA::ULongLong,
                                     CORBA::String_var,
                                     CORBA::TypeCode_var> case_type;

            ACE_NEW_RETURN (the_case,
                            case_type (label),
                            false);
          }
          break;
#endif  /* !ACE_LACKS_LONGLONG_T */
        default:
          return false;
        }

      elem_type case_value (the_case);
      member.swap (case_value);  // Exception-safe

      CORBA::String_var the_name;
      CORBA::TypeCode_var the_type;

      if (!(cdr >> TAO_InputCDR::to_string (the_name.out (), 0)
            && tc_demarshal (cdr, the_type.out (), infos)))
        return false;

      member->name (the_name.in ());
      member->type (the_type.in ());
    }

  typedef TAO::TypeCode::Union<CORBA::String_var,
                               CORBA::TypeCode_var,
                               case_array_type,
                               TAO::True_RefCount_Policy> typecode_type;

  // Check if union TypeCode is recursive.
  if (find_recursive_tc (id.in (), tc, infos))
    {
      // Set remaining parameters.

      typedef TAO::TypeCode::Recursive_Type<typecode_type,
                                            CORBA::TypeCode_var,
                                            case_array_type>
        recursive_typecode_type;

      recursive_typecode_type * const rtc =
        dynamic_cast<recursive_typecode_type *> (tc);

      ACE_ASSERT (rtc);

      rtc->union_parameters (name.in (),
                             discriminant_type,
                             cases,     // Will be copied.
                             ncases,
                             default_index);
    }
  else
    {
      ACE_NEW_RETURN (tc,
                      typecode_type (id.in (),
                                     name.in (),
                                     discriminant_type,
                                     cases,     // Will be copied.
                                     ncases,
                                     default_index),
                      false);
    }

  return true;
}

bool
TAO::TypeCodeFactory::tc_enum_factory (CORBA::TCKind /* kind */,
                                       TAO_InputCDR & cdr,
                                       CORBA::TypeCode_ptr & tc,
                                       TC_Info_List &)
{
  // The remainder of a tk_enum TypeCode is encoded in a CDR
  // encapsulation.

  if (!start_cdr_encap_extraction (cdr))
    return false;

  // Extract the repository ID, name and number of fields.
  CORBA::String_var id, name;
  CORBA::ULong nenumerators;

  if (!(cdr >> TAO_InputCDR::to_string (id.out (), 0)
        && cdr >> TAO_InputCDR::to_string (name.out (), 0)
        && cdr >> nenumerators))
    return false;

  ACE_Array_Base<CORBA::String_var> enumerators (nenumerators);

  for (CORBA::ULong i = 0; i < nenumerators; ++i)
    {
      if (!(cdr >> TAO_InputCDR::to_string (enumerators[i].out (), 0)))
        return false;
    }

  typedef TAO::TypeCode::Enum<
    CORBA::String_var,
    ACE_Array_Base<CORBA::String_var>,
    TAO::True_RefCount_Policy> typecode_type;

  ACE_NEW_RETURN (tc,
                  typecode_type (id.in (),
                                 name.in (),
                                 enumerators,     // Will be copied.
                                 nenumerators),
                  false);

  return true;
}

bool
TAO::TypeCodeFactory::tc_string_factory (CORBA::TCKind kind,
                                         TAO_InputCDR & cdr,
                                         CORBA::TypeCode_ptr & tc,
                                         TC_Info_List &)
{
  // A tk_string/tk_wstring TypeCode has a simple parameter list,
  // i.e. it is not encoded in a CDR encapsulation.

  CORBA::ULong bound;
  if (!(cdr >> bound))
    return false;

  if (bound == 0)
    {
      // Just use the TypeCode constant.
      if (kind == CORBA::tk_string)
        tc = CORBA::TypeCode::_duplicate (CORBA::_tc_string);
      else if (kind == CORBA::tk_wstring)
        tc = CORBA::TypeCode::_duplicate (CORBA::_tc_wstring);
      else
        return false;

      return true;
    }

  typedef TAO::TypeCode::String<TAO::True_RefCount_Policy> typecode_type;

  ACE_NEW_RETURN (tc,
                  typecode_type (kind, bound),
                  false);

  return true;
}

bool
TAO::TypeCodeFactory::tc_sequence_factory (CORBA::TCKind kind,
                                           TAO_InputCDR & cdr,
                                           CORBA::TypeCode_ptr & tc,
                                           TC_Info_List & infos)
{
  ACE_ASSERT (kind == CORBA::tk_sequence || kind == CORBA::tk_array);

  // The remainder of a tk_sequence TypeCode is encoded in a CDR
  // encapsulation.

  if (!start_cdr_encap_extraction (cdr))
    return false;

  // Extract the repository ID, name and content type.
  CORBA::TypeCode_var content_type;
  CORBA::ULong length;

  if (!(tc_demarshal (cdr, content_type.out (), infos)
        && cdr >> length))
    return false;

  typedef TAO::TypeCode::Sequence<
    CORBA::TypeCode_var,
    TAO::True_RefCount_Policy> typecode_type;

  ACE_NEW_RETURN (tc,
                  typecode_type (kind, content_type, length),
                  false);

  return true;
}

bool
TAO::TypeCodeFactory::tc_array_factory (CORBA::TCKind kind,
                                        TAO_InputCDR & cdr,
                                        CORBA::TypeCode_ptr & tc,
                                        TC_Info_List & infos)
{
  return tc_sequence_factory (kind, cdr, tc, infos);
}

bool
TAO::TypeCodeFactory::tc_alias_factory (CORBA::TCKind kind,
                                        TAO_InputCDR & cdr,
                                        CORBA::TypeCode_ptr & tc,
                                        TC_Info_List & infos)
{
  // The remainder of a tk_alias or tk_value_box TypeCode is encoded
  // in a CDR encapsulation.

  if (!start_cdr_encap_extraction (cdr))
    return false;

  // Extract the repository ID, name and content type.
  CORBA::String_var id, name;
  CORBA::TypeCode_var content_type;
  if (!(cdr >> TAO_InputCDR::to_string (id.out (), 0)
        && cdr >> TAO_InputCDR::to_string (name.out (), 0)
        && tc_demarshal (cdr, content_type.out (), infos)))
    return false;

  typedef TAO::TypeCode::Alias<
    CORBA::String_var,
    CORBA::TypeCode_var,
    TAO::True_RefCount_Policy> typecode_type;

  ACE_NEW_RETURN (tc,
                  typecode_type (kind,
                                 id.in (),
                                 name.in (),
                                 content_type),
                  false);

  return true;
}

bool
TAO::TypeCodeFactory::tc_except_factory (CORBA::TCKind kind,
                                         TAO_InputCDR & cdr,
                                         CORBA::TypeCode_ptr & tc,
                                         TC_Info_List & infos)
{
  return tc_struct_factory (kind, cdr, tc, infos);
}

bool
TAO::TypeCodeFactory::tc_longlong_factory (CORBA::TCKind,
                                           TAO_InputCDR &,
                                           CORBA::TypeCode_ptr & tc,
                                           TC_Info_List &)
{
  tc = CORBA::TypeCode::_duplicate (CORBA::_tc_longlong);

  return true;
}

bool
TAO::TypeCodeFactory::tc_ulonglong_factory (CORBA::TCKind,
                                            TAO_InputCDR &,
                                            CORBA::TypeCode_ptr & tc,
                                            TC_Info_List &)
{
  tc = CORBA::TypeCode::_duplicate (CORBA::_tc_ulonglong);

  return true;
}

bool
TAO::TypeCodeFactory::tc_longdouble_factory (CORBA::TCKind,
                                             TAO_InputCDR &,
                                             CORBA::TypeCode_ptr & tc,
                                             TC_Info_List &)
{
  tc = CORBA::TypeCode::_duplicate (CORBA::_tc_longdouble);

  return true;
}

bool
TAO::TypeCodeFactory::tc_wchar_factory (CORBA::TCKind,
                                        TAO_InputCDR &,
                                        CORBA::TypeCode_ptr & tc,
                                        TC_Info_List &)
{
  tc = CORBA::TypeCode::_duplicate (CORBA::_tc_wchar);

  return true;
}

bool
TAO::TypeCodeFactory::tc_wstring_factory (CORBA::TCKind kind,
                                          TAO_InputCDR & cdr,
                                          CORBA::TypeCode_ptr & tc,
                                          TC_Info_List & infos)
{
  return tc_string_factory (kind, cdr, tc, infos);
}

bool
TAO::TypeCodeFactory::tc_fixed_factory (CORBA::TCKind,
                                        TAO_InputCDR & cdr,
                                        CORBA::TypeCode_ptr & tc,
                                        TC_Info_List &)
{
  // A tk_fixed TypeCode has a simple parameter list, i.e. it is not
  // encoded in a CDR encapsulation.

  CORBA::UShort digits, scale;
  if (!(cdr >> digits && cdr >> scale))
    return false;

  typedef TAO::TypeCode::Fixed<TAO::True_RefCount_Policy> typecode_type;

  ACE_NEW_RETURN (tc,
                  typecode_type (digits, scale),
                  false);

  return true;
}

bool
TAO::TypeCodeFactory::tc_value_factory (CORBA::TCKind kind,
                                        TAO_InputCDR & cdr,
                                        CORBA::TypeCode_ptr & tc,
                                        TC_Info_List & infos)
{
  // The remainder of a tk_value/tk_event TypeCode is encoded in a
  // CDR encapsulation

  if (!start_cdr_encap_extraction (cdr))
    return false;

  // Extract the repository ID, name and number of fields.
  CORBA::String_var id;
  if (!(cdr >> TAO_InputCDR::to_string (id.out (), 0)))
    return false;

//   if (ACE_OS::strcmp (id.in (), "IDL:omg.org/CORBA/ValueBase:1.0") == 0)
//     {
//       // No need to create a TypeCode.  Just use the TypeCode
//       // constant.
//       tc = CORBA::TypeCode::_duplicate (CORBA::_tc_ValueBase);

//       return true;
//     }
//   else if (ACE_OS::strcmp (id.in (),
//                            "IDL:omg.org/CORBA/EventBase:1.0") == 0)
//     {
//       // No need to create a TypeCode.  Just use the TypeCode
//       // constant.
//       tc = CORBA::TypeCode::_duplicate (CORBA::_tc_EventBase);

//       return true;
//     }

  CORBA::String_var name;
  CORBA::ValueModifier type_modifier;
  CORBA::TypeCode_var concrete_base;
  CORBA::ULong nfields;

  if (!(cdr >> TAO_InputCDR::to_string (name.out (), 0)
        && cdr >> type_modifier
        && cdr >> concrete_base.out ()
        && cdr >> nfields))
    return false;

  typedef ACE_Array_Base<TAO::TypeCode::Value_Field<CORBA::String_var,
                                                    CORBA::TypeCode_var> >
    member_array_type;

  member_array_type fields (nfields);

  for (CORBA::ULong i = 0; i < nfields; ++i)
    {
      TAO::TypeCode::Value_Field<CORBA::String_var,
                                 CORBA::TypeCode_var> & field = fields[i];

      if (!(cdr >> TAO_InputCDR::to_string (field.name.out (), 0)
            && tc_demarshal (cdr, field.type.out (), infos)
            && cdr >> field.visibility))
        return false;
    }

  typedef TAO::TypeCode::Value<
    CORBA::String_var,
    CORBA::TypeCode_var,
    member_array_type,
    TAO::True_RefCount_Policy> typecode_type;

  // Check if valuetype/eventtype TypeCode is recursive.
  if (find_recursive_tc (id.in (), tc, infos))
    {
      // Set remaining parameters.

      typedef TAO::TypeCode::Recursive_Type<typecode_type,
                                            CORBA::TypeCode_var,
                                            member_array_type>
        recursive_typecode_type;

      recursive_typecode_type * const rtc =
        dynamic_cast<recursive_typecode_type *> (tc);

      ACE_ASSERT (rtc);

      rtc->valuetype_parameters (name.in (),
                                 type_modifier,
                                 concrete_base,
                                 fields,     // Will be copied.
                                 nfields);
    }
  else
    {
      ACE_NEW_RETURN (tc,
                      typecode_type (kind,
                                     id.in (),
                                     name.in (),
                                     type_modifier,
                                     concrete_base,
                                     fields,     // Will be copied.
                                     nfields),
                      false);
    }

  return true;
}

bool
TAO::TypeCodeFactory::tc_value_box_factory (CORBA::TCKind kind,
                                            TAO_InputCDR & cdr,
                                            CORBA::TypeCode_ptr & tc,
                                            TC_Info_List & infos)
{
  return tc_alias_factory (kind, cdr, tc, infos);
}

bool
TAO::TypeCodeFactory::tc_native_factory (CORBA::TCKind,
                                         TAO_InputCDR & cdr,
                                         CORBA::TypeCode_ptr & tc,
                                         TC_Info_List & infos)
{
  return tc_objref_factory (CORBA::tk_native, cdr, tc, infos);
}

bool
TAO::TypeCodeFactory::tc_abstract_interface_factory (CORBA::TCKind,
                                                     TAO_InputCDR & cdr,
                                                     CORBA::TypeCode_ptr & tc,
                                                     TC_Info_List & infos)
{
  return tc_objref_factory (CORBA::tk_abstract_interface, cdr, tc, infos);
}

bool
TAO::TypeCodeFactory::tc_local_interface_factory (CORBA::TCKind,
                                                  TAO_InputCDR & cdr,
                                                  CORBA::TypeCode_ptr & tc,
                                                  TC_Info_List & infos)
{
  return tc_objref_factory (CORBA::tk_local_interface, cdr, tc, infos);
}

bool
TAO::TypeCodeFactory::tc_component_factory (CORBA::TCKind,
                                            TAO_InputCDR & cdr,
                                            CORBA::TypeCode_ptr & tc,
                                            TC_Info_List & infos)
{
  return tc_objref_factory (CORBA::tk_component, cdr, tc, infos);
}

bool
TAO::TypeCodeFactory::tc_home_factory (CORBA::TCKind,
                                       TAO_InputCDR & cdr,
                                       CORBA::TypeCode_ptr & tc,
                                       TC_Info_List & infos)
{
  return tc_objref_factory (CORBA::tk_home, cdr, tc, infos);
}

bool
TAO::TypeCodeFactory::tc_event_factory (CORBA::TCKind kind,
                                        TAO_InputCDR & cdr,
                                        CORBA::TypeCode_ptr & tc,
                                        TC_Info_List & infos)
{
  return tc_value_factory (kind, cdr, tc, infos);
}

// ---------------------------------------------------------------

namespace
{
  bool
  tc_demarshal (TAO_InputCDR & cdr,
                CORBA::TypeCode_ptr & tc,
                TAO::TypeCodeFactory::TC_Info_List & infos)
  {
    // ULong since we need to detect indirected TypeCodes, too.

    CORBA::ULong kind;
    if (!(cdr >> kind)
        || (kind >= static_cast<CORBA::ULong> (CORBA::TAO_TC_KIND_COUNT)
            && kind != TYPECODE_INDIRECTION))
      return false;

    if (kind == TYPECODE_INDIRECTION)
      return tc_demarshal_indirection (cdr, tc, infos);

    using namespace TAO::TypeCodeFactory;

    static factory const factory_map[] =
      {
        tc_null_factory,
        tc_void_factory,
        tc_short_factory,
        tc_long_factory,
        tc_ushort_factory,
        tc_ulong_factory,
        tc_float_factory,
        tc_double_factory,
        tc_boolean_factory,
        tc_char_factory,
        tc_octet_factory,
        tc_any_factory,
        tc_TypeCode_factory,
        tc_Principal_factory,
        tc_objref_factory,
        tc_struct_factory,
        tc_union_factory,
        tc_enum_factory,
        tc_string_factory,
        tc_sequence_factory,
        tc_array_factory,
        tc_alias_factory,
        tc_except_factory,
        tc_longlong_factory,
        tc_ulonglong_factory,
        tc_longdouble_factory,
        tc_wchar_factory,
        tc_wstring_factory,
        tc_fixed_factory,
        tc_value_factory,
        tc_value_box_factory,
        tc_native_factory,
        tc_abstract_interface_factory,
        tc_local_interface_factory,
        tc_component_factory,
        tc_home_factory,
        tc_event_factory
      };

    return factory_map[kind] (static_cast<CORBA::TCKind> (kind),
                              cdr,
                              tc,
                              infos);
  }

  bool
  tc_demarshal_indirection (TAO_InputCDR & cdr,
                            CORBA::TypeCode_ptr & tc,
                            TAO::TypeCodeFactory::TC_Info_List & infos)
  {
    CORBA::Long offset;

    if (!(cdr >> offset) || offset >= -4)
      {
        // Offsets must be negative since they point back to a
        // TypeCode found earlier in the CDR stream.  They must be
        // less than -4 since an offset of -4 points back to the
        // indirection TypeCode itself, meaning that it would be
        // self-indirecting.
        return false;
      }

//     ACE_Message_Block * const mb =
//       const_cast<ACE_Message_Block *> (cdr.start ());

//     TAO_InputCDR indir_stream (mb->rd_ptr () + offset - 4,
    TAO_InputCDR indir_stream (cdr.rd_ptr () + offset - sizeof (CORBA::Long),
                               (-offset) + sizeof (CORBA::Long),
                               cdr.byte_order ());

    if (!indir_stream.good_bit ())
      {
        return false;
      }

    CORBA::TCKind kind;
    if (!(indir_stream >> kind)

        // Indirected TypeCode must point to top-level TypeCode.
        || static_cast<CORBA::ULong> (kind) == TYPECODE_INDIRECTION

        // Only struct, union and valuetype TypeCodes may be recursive.
        || !(kind == CORBA::tk_struct
             || kind == CORBA::tk_union
             || kind == CORBA::tk_value
             || kind == CORBA::tk_event)

        // Currently all recursive TypeCodes have complex parameter
        // lists, meaning they are encoded as CDR encapsulations.
        || !start_cdr_encap_extraction (indir_stream))
      {
        return false;
      }

    /**
     * @todo Recursive TypeCode demarshaling is currently suboptimal
     *       due to redundant demarshaling of TypeCode parameters,
     *       such as repository ID, and excessive
     *       allocations/copying.
     */

    CORBA::String_var id;
    if (!(indir_stream >> TAO_InputCDR::to_string (id.out (), 0)))
      return false;

    // Don't bother demarshaling the rest of the parameters.  They will
    // be handled by the top-level TypeCode demarshaling call.

    switch (kind)
      {
      case CORBA::tk_struct:
        {
          typedef ACE_Array_Base<
            TAO::TypeCode::Struct_Field<
              CORBA::String_var,
              CORBA::TypeCode_var> > member_array_type;

          typedef TAO::TypeCode::Struct<
            CORBA::String_var,
            CORBA::TypeCode_var,
            member_array_type,
            TAO::True_RefCount_Policy> typecode_type;

          typedef TAO::TypeCode::Recursive_Type<typecode_type,
                                                CORBA::TypeCode_var,
                                                member_array_type>
            recursive_typecode_type;

          ACE_NEW_RETURN (tc,
                          recursive_typecode_type (kind,
                                                   id.in ()),
                          false);
        }
        break;
      case CORBA::tk_union:
        {
          typedef union_case_array_type member_array_type;

          typedef TAO::TypeCode::Union<
            CORBA::String_var,
            CORBA::TypeCode_var,
            member_array_type,
            TAO::True_RefCount_Policy> typecode_type;

          typedef TAO::TypeCode::Recursive_Type<typecode_type,
                                                CORBA::TypeCode_var,
                                                member_array_type>
            recursive_typecode_type;

          ACE_NEW_RETURN (tc,
                          recursive_typecode_type (kind,
                                                   id.in ()),
                          false);
        }
        break;
      case CORBA::tk_value:
      case CORBA::tk_event:
        {
          typedef ACE_Array_Base<
            TAO::TypeCode::Value_Field<
              CORBA::String_var,
              CORBA::TypeCode_var> > member_array_type;

          typedef TAO::TypeCode::Value<
            CORBA::String_var,
            CORBA::TypeCode_var,
            member_array_type,
            TAO::True_RefCount_Policy> typecode_type;

          typedef TAO::TypeCode::Recursive_Type<typecode_type,
                                                CORBA::TypeCode_var,
                                                member_array_type>
            recursive_typecode_type;

          ACE_NEW_RETURN (tc,
                          recursive_typecode_type (kind,
                                                   id.in ()),
                          false);
        }
        break;
      default:
        return false;  // We should never get here.
      };

    size_t const old_size = infos.size ();
    if (infos.size (old_size + 1) == -1)  // Incremental growth -- *sigh*
      return false;

    TAO::TypeCodeFactory::TC_Info & info = infos[old_size];

    ACE_DECLARE_NEW_CORBA_ENV;
    info.id = tc->id (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN (false);  // Should never throw!

    info.type = tc;

    return true;
  }
}

// ----------------------------------------------------------------

CORBA::Boolean
operator>> (TAO_InputCDR & cdr,
            CORBA::TypeCode_ptr & tc)
{
  TAO::TypeCodeFactory::TC_Info_List infos;

  return tc_demarshal (cdr, tc, infos);
}

TAO_END_VERSIONED_NAMESPACE_DECL

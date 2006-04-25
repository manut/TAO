// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// .\be\be_codegen.cpp:153

#ifndef _TAO_IDL_STRINGVALUEC_H_
#define _TAO_IDL_STRINGVALUEC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Valuetype/valuetype_export.h"
#include "tao/Valuetype/ValueBase.h"
#include "tao/CDR.h"
#include "tao/Valuetype/Valuetype_Adapter_Impl.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Environment.h"
#include "tao/Valuetype/Value_VarOut_T.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Valuetype_Export

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// c:\projects\ace_cvs\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:48

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace CORBA
{

  // TAO_IDL - Generated from
  // c:\projects\ace_cvs\ace_wrappers\tao\tao_idl\be\be_visitor_valuebox/valuebox_ch.cpp:52

#if !defined (_CORBA_STRINGVALUE_CH_)
#define _CORBA_STRINGVALUE_CH_

  class StringValue;

  typedef
    TAO_Value_Var_T<
        StringValue
      >
    StringValue_var;

  typedef
    TAO_Value_Out_T<
        StringValue
      >
    StringValue_out;

  class TAO_Valuetype_Export StringValue
    : public virtual CORBA::DefaultValueRefCountBase
  {
  public:

    static StringValue* _downcast (CORBA::ValueBase *);
    CORBA::ValueBase * _copy_value (void);

    virtual const char* _tao_obv_repository_id (void) const;
    virtual void _tao_obv_truncatable_repo_ids (Repository_Id_List &) const;

    static const char* _tao_obv_static_repository_id (void);

    static CORBA::Boolean _tao_unmarshal (
        TAO_InputCDR &,
        StringValue *&
      );



    // TAO_IDL - Generated from
    // c:\projects\ace_cvs\ace_wrappers\tao\tao_idl\be\be_visitor_valuebox/valuebox_ch.cpp:403

    // constructors
    StringValue (void);
    StringValue (CORBA::Char * val);
    StringValue (const CORBA::Char * val);
    StringValue (const CORBA::String_var& var);
    StringValue (const StringValue& val);
    // assignment operators
    StringValue& operator= (CORBA::Char * val);

    StringValue& operator= (const CORBA::Char * val);

    StringValue& operator= (const CORBA::String_var& var);

    // accessor
    const CORBA::Char * _value (void) const;

    // modifiers
    void _value (CORBA::Char * val);
    void _value (const CORBA::Char * val);
    void _value (const CORBA::String_var& var);

    // access to the boxed value for method signatures
    const CORBA::Char * _boxed_in (void) const;
    CORBA::Char *& _boxed_inout (void);
    CORBA::Char *& _boxed_out (void);
    // allows access and modification using a slot.
    char & operator[] (CORBA::ULong slot);

    // allows only accessing thru a slot.
    char operator[] (CORBA::ULong slot) const;

  private:
    CORBA::String_var _pd_value;


    // TAO_IDL - Generated from
    // c:\projects\ace_cvs\ace_wrappers\tao\tao_idl\be\be_visitor_valuebox/valuebox_ch.cpp:115

  protected:
    virtual ~StringValue (void);
    virtual CORBA::Boolean _tao_marshal_v (TAO_OutputCDR &) const;
    virtual CORBA::Boolean _tao_unmarshal_v (TAO_InputCDR &);

  private:
    void operator= (const StringValue & val);

  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // c:\projects\ace_cvs\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:44

  extern TAO_Valuetype_Export ::CORBA::TypeCode_ptr const _tc_StringValue;

  // TAO_IDL - Generated from
  // c:\projects\ace_cvs\ace_wrappers\tao\tao_idl\be\be_visitor_valuebox/valuebox_ch.cpp:52

#if !defined (_CORBA_WSTRINGVALUE_CH_)
#define _CORBA_WSTRINGVALUE_CH_

  class WStringValue;

  typedef
    TAO_Value_Var_T<
        WStringValue
      >
    WStringValue_var;

  typedef
    TAO_Value_Out_T<
        WStringValue
      >
    WStringValue_out;

  class TAO_Valuetype_Export WStringValue
    : public virtual CORBA::DefaultValueRefCountBase
  {
  public:

    static WStringValue* _downcast (CORBA::ValueBase *);
    CORBA::ValueBase * _copy_value (void);

    virtual const char* _tao_obv_repository_id (void) const;
    virtual void _tao_obv_truncatable_repo_ids (Repository_Id_List &) const;

    static const char* _tao_obv_static_repository_id (void);

    static CORBA::Boolean _tao_unmarshal (
        TAO_InputCDR &,
        WStringValue *&
      );



    // TAO_IDL - Generated from
    // c:\projects\ace_cvs\ace_wrappers\tao\tao_idl\be\be_visitor_valuebox/valuebox_ch.cpp:403

    // constructors
    WStringValue (void);
    WStringValue (CORBA::WChar * val);
    WStringValue (const CORBA::WChar * val);
    WStringValue (const CORBA::WString_var& var);
    WStringValue (const WStringValue& val);
    // assignment operators
    WStringValue& operator= (CORBA::WChar * val);

    WStringValue& operator= (const CORBA::WChar * val);

    WStringValue& operator= (const CORBA::WString_var& var);

    // accessor
    const CORBA::WChar * _value (void) const;

    // modifiers
    void _value (CORBA::WChar * val);
    void _value (const CORBA::WChar * val);
    void _value (const CORBA::WString_var& var);

    // access to the boxed value for method signatures
    const CORBA::WChar * _boxed_in (void) const;
    CORBA::WChar *& _boxed_inout (void);
    CORBA::WChar *& _boxed_out (void);
    // allows access and modification using a slot.
    CORBA::WChar & operator[] (CORBA::ULong slot);

    // allows only accessing thru a slot.
    CORBA::WChar operator[] (CORBA::ULong slot) const;

  private:
    CORBA::WString_var _pd_value;


    // TAO_IDL - Generated from
    // c:\projects\ace_cvs\ace_wrappers\tao\tao_idl\be\be_visitor_valuebox/valuebox_ch.cpp:115

  protected:
    virtual ~WStringValue (void);
    virtual CORBA::Boolean _tao_marshal_v (TAO_OutputCDR &) const;
    virtual CORBA::Boolean _tao_unmarshal_v (TAO_InputCDR &);

  private:
    void operator= (const WStringValue & val);

  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // c:\projects\ace_cvs\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:44

  extern TAO_Valuetype_Export ::CORBA::TypeCode_ptr const _tc_WStringValue;

// TAO_IDL - Generated from
// c:\projects\ace_cvs\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:66

} // module CORBA

// TAO_IDL - Generated from
// .\be\be_visitor_traits.cpp:61

// Traits specializations.
namespace TAO
{
}

// TAO_IDL - Generated from
// c:\projects\ace_cvs\ace_wrappers\tao\tao_idl\be\be_visitor_valuebox/any_op_ch.cpp:53

TAO_Valuetype_Export void operator<<= (CORBA::Any &, CORBA::StringValue *); // copying
TAO_Valuetype_Export void operator<<= (CORBA::Any &, CORBA::StringValue **); // non-copying
TAO_Valuetype_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA::StringValue *&);

// TAO_IDL - Generated from
// c:\projects\ace_cvs\ace_wrappers\tao\tao_idl\be\be_visitor_valuebox/any_op_ch.cpp:53

TAO_Valuetype_Export void operator<<= (CORBA::Any &, CORBA::WStringValue *); // copying
TAO_Valuetype_Export void operator<<= (CORBA::Any &, CORBA::WStringValue **); // non-copying
TAO_Valuetype_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA::WStringValue *&);

// TAO_IDL - Generated from
// c:\projects\ace_cvs\ace_wrappers\tao\tao_idl\be\be_visitor_valuebox/cdr_op_ch.cpp:50

TAO_Valuetype_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const CORBA::StringValue *);
TAO_Valuetype_Export CORBA::Boolean operator>> (TAO_InputCDR &, CORBA::StringValue *&);

// TAO_IDL - Generated from
// c:\projects\ace_cvs\ace_wrappers\tao\tao_idl\be\be_visitor_valuebox/cdr_op_ch.cpp:50

TAO_Valuetype_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const CORBA::WStringValue *);
TAO_Valuetype_Export CORBA::Boolean operator>> (TAO_InputCDR &, CORBA::WStringValue *&);

// TAO_IDL - Generated from
// .\be\be_codegen.cpp:955

TAO_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "tao/Valuetype/StringValueC.inl"
#endif /* defined INLINE */

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */

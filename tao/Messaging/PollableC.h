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
// be\be_codegen.cpp:154

#ifndef _TAO_IDL_POLLABLEC_H_
#define _TAO_IDL_POLLABLEC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "messaging_export.h"
#include "tao/AnyTypeCode/AnyTypeCode_methods.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Environment.h"
#include "tao/Object.h"
#include "tao/Objref_VarOut_T.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Messaging_Export

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:49

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace CORBA
{
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:646

#if !defined (_CORBA_POLLABLESET__VAR_OUT_CH_)
#define _CORBA_POLLABLESET__VAR_OUT_CH_
  
  class PollableSet;
  typedef PollableSet *PollableSet_ptr;
  
  typedef
    TAO_Objref_Var_T<
        PollableSet
      >
    PollableSet_var;
  
  typedef
    TAO_Objref_Out_T<
        PollableSet
      >
    PollableSet_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:646

#if !defined (_CORBA_POLLABLE__VAR_OUT_CH_)
#define _CORBA_POLLABLE__VAR_OUT_CH_
  
  class Pollable;
  typedef Pollable *Pollable_ptr;
  
  typedef
    TAO_Objref_Var_T<
        Pollable
      >
    Pollable_var;
  
  typedef
    TAO_Objref_Out_T<
        Pollable
      >
    Pollable_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_CORBA_POLLABLE_CH_)
#define _CORBA_POLLABLE_CH_
  
  class TAO_Messaging_Export Pollable
    : public virtual ::CORBA::Object
  {
  public:
    typedef Pollable_ptr _ptr_type;
    typedef Pollable_var _var_type;
    
    // The static operations.
    static Pollable_ptr _duplicate (Pollable_ptr obj);
    
    static void _tao_release (Pollable_ptr obj);
    
    static Pollable_ptr _narrow (
        ::CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static Pollable_ptr _unchecked_narrow (
        ::CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static Pollable_ptr _nil (void)
    {
      return static_cast<Pollable_ptr> (0);
    }
    
    
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::Boolean is_ready (
        ::CORBA::ULong timeout
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::PollableSet_ptr create_pollable_set (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_interface/interface_ch.cpp:210
    
    virtual ::CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    Pollable (void);
    
    virtual ~Pollable (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    Pollable (const Pollable &);
    
    void operator= (const Pollable &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_Messaging_Export ::CORBA::TypeCode_ptr const _tc_Pollable;
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:646

#if !defined (_CORBA_DIIPOLLABLE__VAR_OUT_CH_)
#define _CORBA_DIIPOLLABLE__VAR_OUT_CH_
  
  class DIIPollable;
  typedef DIIPollable *DIIPollable_ptr;
  
  typedef
    TAO_Objref_Var_T<
        DIIPollable
      >
    DIIPollable_var;
  
  typedef
    TAO_Objref_Out_T<
        DIIPollable
      >
    DIIPollable_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_CORBA_DIIPOLLABLE_CH_)
#define _CORBA_DIIPOLLABLE_CH_
  
  class TAO_Messaging_Export DIIPollable
    : public virtual ::CORBA::Pollable
  {
  public:
    typedef DIIPollable_ptr _ptr_type;
    typedef DIIPollable_var _var_type;
    
    // The static operations.
    static DIIPollable_ptr _duplicate (DIIPollable_ptr obj);
    
    static void _tao_release (DIIPollable_ptr obj);
    
    static DIIPollable_ptr _narrow (
        ::CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static DIIPollable_ptr _unchecked_narrow (
        ::CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static DIIPollable_ptr _nil (void)
    {
      return static_cast<DIIPollable_ptr> (0);
    }
    
    
    
    // TAO_IDL - Generated from
    // be\be_visitor_interface/interface_ch.cpp:210
    
    virtual ::CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    DIIPollable (void);
    
    virtual ~DIIPollable (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    DIIPollable (const DIIPollable &);
    
    void operator= (const DIIPollable &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_Messaging_Export ::CORBA::TypeCode_ptr const _tc_DIIPollable;
  
  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_CORBA_POLLABLESET_CH_)
#define _CORBA_POLLABLESET_CH_
  
  class TAO_Messaging_Export PollableSet
    : public virtual ::CORBA::Object
  {
  public:
    typedef PollableSet_ptr _ptr_type;
    typedef PollableSet_var _var_type;
    
    // The static operations.
    static PollableSet_ptr _duplicate (PollableSet_ptr obj);
    
    static void _tao_release (PollableSet_ptr obj);
    
    static PollableSet_ptr _narrow (
        ::CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static PollableSet_ptr _unchecked_narrow (
        ::CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static PollableSet_ptr _nil (void)
    {
      return static_cast<PollableSet_ptr> (0);
    }
    
    
    
    // TAO_IDL - Generated from
    // be\be_visitor_exception/exception_ch.cpp:53

#if !defined (_CORBA_POLLABLESET_NOPOSSIBLEPOLLABLE_CH_)
#define _CORBA_POLLABLESET_NOPOSSIBLEPOLLABLE_CH_
    
    class TAO_Messaging_Export NoPossiblePollable : public ::CORBA::UserException
    {
    public:
      
      NoPossiblePollable (void);
      NoPossiblePollable (const NoPossiblePollable &);
      ~NoPossiblePollable (void);

      NoPossiblePollable &operator= (const NoPossiblePollable &);
      
      static void _tao_any_destructor (void *);
      
      static NoPossiblePollable *_downcast ( ::CORBA::Exception *);
      static const NoPossiblePollable *_downcast ( ::CORBA::Exception const *);
      
      static ::CORBA::Exception *_alloc (void);
      
      virtual ::CORBA::Exception *_tao_duplicate (void) const;

      virtual void _raise (void) const;

      virtual void _tao_encode (
          TAO_OutputCDR &
          ACE_ENV_ARG_DECL
        ) const;
      
      virtual void _tao_decode (
          TAO_InputCDR &
          ACE_ENV_ARG_DECL
        );
      
      virtual ::CORBA::TypeCode_ptr _tao_type (void) const;
    };
    
    // TAO_IDL - Generated from
    // be\be_visitor_typecode/typecode_decl.cpp:49
    
    static ::CORBA::TypeCode_ptr const _tc_NoPossiblePollable;

#endif /* end #if !defined */
    
    // TAO_IDL - Generated from
    // be\be_visitor_exception/exception_ch.cpp:53

#if !defined (_CORBA_POLLABLESET_UNKNOWNPOLLABLE_CH_)
#define _CORBA_POLLABLESET_UNKNOWNPOLLABLE_CH_
    
    class TAO_Messaging_Export UnknownPollable : public ::CORBA::UserException
    {
    public:
      
      UnknownPollable (void);
      UnknownPollable (const UnknownPollable &);
      ~UnknownPollable (void);

      UnknownPollable &operator= (const UnknownPollable &);
      
      static void _tao_any_destructor (void *);
      
      static UnknownPollable *_downcast ( ::CORBA::Exception *);
      static const UnknownPollable *_downcast ( ::CORBA::Exception const *);
      
      static ::CORBA::Exception *_alloc (void);
      
      virtual ::CORBA::Exception *_tao_duplicate (void) const;

      virtual void _raise (void) const;

      virtual void _tao_encode (
          TAO_OutputCDR &
          ACE_ENV_ARG_DECL
        ) const;
      
      virtual void _tao_decode (
          TAO_InputCDR &
          ACE_ENV_ARG_DECL
        );
      
      virtual ::CORBA::TypeCode_ptr _tao_type (void) const;
    };
    
    // TAO_IDL - Generated from
    // be\be_visitor_typecode/typecode_decl.cpp:49
    
    static ::CORBA::TypeCode_ptr const _tc_UnknownPollable;

#endif /* end #if !defined */
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::DIIPollable_ptr create_dii_pollable (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void add_pollable (
        ::CORBA::Pollable_ptr potential
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::Pollable_ptr get_ready_pollable (
        ::CORBA::ULong timeout
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException,
        ::CORBA::PollableSet::NoPossiblePollable
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void remove (
        ::CORBA::Pollable_ptr potential
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException,
        ::CORBA::PollableSet::UnknownPollable
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::UShort number_left (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_interface/interface_ch.cpp:210
    
    virtual ::CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    PollableSet (void);
    
    virtual ~PollableSet (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    PollableSet (const PollableSet &);
    
    void operator= (const PollableSet &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_Messaging_Export ::CORBA::TypeCode_ptr const _tc_PollableSet;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:78

} // module CORBA

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:61

// Traits specializations.
namespace TAO
{

#if !defined (_CORBA_POLLABLE__TRAITS_)
#define _CORBA_POLLABLE__TRAITS_
  
  template<>
  struct TAO_Messaging_Export Objref_Traits< ::CORBA::Pollable>
  {
    static ::CORBA::Pollable_ptr duplicate (
        ::CORBA::Pollable_ptr
      );
    static void release (
        ::CORBA::Pollable_ptr
      );
    static ::CORBA::Pollable_ptr nil (void);
    static ::CORBA::Boolean marshal (
        ::CORBA::Pollable_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */

#if !defined (_CORBA_DIIPOLLABLE__TRAITS_)
#define _CORBA_DIIPOLLABLE__TRAITS_
  
  template<>
  struct TAO_Messaging_Export Objref_Traits< ::CORBA::DIIPollable>
  {
    static ::CORBA::DIIPollable_ptr duplicate (
        ::CORBA::DIIPollable_ptr
      );
    static void release (
        ::CORBA::DIIPollable_ptr
      );
    static ::CORBA::DIIPollable_ptr nil (void);
    static ::CORBA::Boolean marshal (
        ::CORBA::DIIPollable_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */

#if !defined (_CORBA_POLLABLESET__TRAITS_)
#define _CORBA_POLLABLESET__TRAITS_
  
  template<>
  struct TAO_Messaging_Export Objref_Traits< ::CORBA::PollableSet>
  {
    static ::CORBA::PollableSet_ptr duplicate (
        ::CORBA::PollableSet_ptr
      );
    static void release (
        ::CORBA::PollableSet_ptr
      );
    static ::CORBA::PollableSet_ptr nil (void);
    static ::CORBA::Boolean marshal (
        ::CORBA::PollableSet_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}

// TAO_IDL - Generated from
// be\be_codegen.cpp:1040

TAO_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ifndef */



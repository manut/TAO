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
// .\be\be_codegen.cpp:186

#ifndef _TAO_IDL_MUF_SCHEDULINGC_H_
#define _TAO_IDL_MUF_SCHEDULINGC_H_

#include /**/ "ace/pre.h"

#include "tao/ORB.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "Kokyu_dsrt_schedulers_export.h"
#include "tao/CDR.h"
#include "tao/Environment.h"
#include "tao/Object.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/VarOut_T.h"

#include "tao/RTScheduling/RTSchedulerC.h"
#include "tao/RTCORBA/RTCORBA_includeC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO Kokyu_DSRT_Schedulers_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO Kokyu_DSRT_Schedulers_Export
#endif /* TAO_EXPORT_NESTED_CLASSES */

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from 
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_root/root_ch.cpp:63

namespace TAO
{
  class Collocation_Proxy_Broker;
  
  template<typename T> class Narrow_Utils;
  template<typename T> class AbstractBase_Narrow_Utils;
}

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:48

namespace MUF_Scheduling
{
  
  // TAO_IDL - Generated from
  // .\be\be_type.cpp:258
  
  struct SchedulingParameter;
  
  typedef
    TAO_Fixed_Var_T<
        SchedulingParameter
      >
    SchedulingParameter_var;
  
  typedef
    SchedulingParameter &
    SchedulingParameter_out;
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/structure_ch.cpp:52
  
  struct Kokyu_DSRT_Schedulers_Export SchedulingParameter
  {
    typedef SchedulingParameter_var _var_type;
    
    static void _tao_any_destructor (void *);
    TimeBase::TimeT deadline;
    TimeBase::TimeT estimated_initial_execution_time;
    CORBA::Long criticality;
  };
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_SchedulingParameter;
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:611

#if !defined (_MUF_SCHEDULING_SCHEDULINGPARAMETERPOLICY__VAR_OUT_CH_)
#define _MUF_SCHEDULING_SCHEDULINGPARAMETERPOLICY__VAR_OUT_CH_
  
  class SchedulingParameterPolicy;
  typedef SchedulingParameterPolicy *SchedulingParameterPolicy_ptr;
  
  typedef
    TAO_Objref_Var_T<
        SchedulingParameterPolicy
      >
    SchedulingParameterPolicy_var;
  
  typedef
    TAO_Objref_Out_T<
        SchedulingParameterPolicy
      >
    SchedulingParameterPolicy_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_MUF_SCHEDULING_SCHEDULINGPARAMETERPOLICY_CH_)
#define _MUF_SCHEDULING_SCHEDULINGPARAMETERPOLICY_CH_
  
  class Kokyu_DSRT_Schedulers_Export SchedulingParameterPolicy
    : public virtual CORBA::Policy
  {
  public:
    typedef SchedulingParameterPolicy_ptr _ptr_type;
    typedef SchedulingParameterPolicy_var _var_type;
    
    // The static operations.
    static SchedulingParameterPolicy_ptr _duplicate (SchedulingParameterPolicy_ptr obj);
    
    static SchedulingParameterPolicy_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static SchedulingParameterPolicy_ptr _nil (void)
    {
      return (SchedulingParameterPolicy_ptr)0;
    }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // w:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::MUF_Scheduling::SchedulingParameter value (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // w:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void value (
        const MUF_Scheduling::SchedulingParameter & value
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // w:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:185
    
    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    SchedulingParameterPolicy (void);
    
    virtual ~SchedulingParameterPolicy (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    SchedulingParameterPolicy (const SchedulingParameterPolicy &);
    
    void operator= (const SchedulingParameterPolicy &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_SchedulingParameterPolicy;
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:611

#if !defined (_MUF_SCHEDULING_SCHEDULER__VAR_OUT_CH_)
#define _MUF_SCHEDULING_SCHEDULER__VAR_OUT_CH_
  
  class Scheduler;
  typedef Scheduler *Scheduler_ptr;
  
  typedef
    TAO_Objref_Var_T<
        Scheduler
      >
    Scheduler_var;
  
  typedef
    TAO_Objref_Out_T<
        Scheduler
      >
    Scheduler_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_MUF_SCHEDULING_SCHEDULER_CH_)
#define _MUF_SCHEDULING_SCHEDULER_CH_
  
  class Kokyu_DSRT_Schedulers_Export Scheduler
    : public virtual RTScheduling::Scheduler
  {
  public:
    typedef Scheduler_ptr _ptr_type;
    typedef Scheduler_var _var_type;
    
    // The static operations.
    static Scheduler_ptr _duplicate (Scheduler_ptr obj);
    
    static Scheduler_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static Scheduler_ptr _nil (void)
    {
      return (Scheduler_ptr)0;
    }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // w:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::MUF_Scheduling::SchedulingParameterPolicy_ptr create_scheduling_parameter (
        const MUF_Scheduling::SchedulingParameter & value
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // w:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:185
    
    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    Scheduler (void);
    
    virtual ~Scheduler (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    Scheduler (const Scheduler &);
    
    void operator= (const Scheduler &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_Scheduler;

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:66

} // module MUF_Scheduling

// TAO_IDL - Generated from
// .\be\be_visitor_traits.cpp:50

// Traits specializations.
namespace TAO
{

#if !defined (_MUF_SCHEDULING_SCHEDULINGPARAMETERPOLICY__TRAITS_CH_)
#define _MUF_SCHEDULING_SCHEDULINGPARAMETERPOLICY__TRAITS_CH_
  
  ACE_TEMPLATE_SPECIALIZATION
  struct Kokyu_DSRT_Schedulers_Export Objref_Traits<MUF_Scheduling::SchedulingParameterPolicy>
  {
    static MUF_Scheduling::SchedulingParameterPolicy_ptr tao_duplicate (
        MUF_Scheduling::SchedulingParameterPolicy_ptr
      );
    static void tao_release (
        MUF_Scheduling::SchedulingParameterPolicy_ptr
      );
    static MUF_Scheduling::SchedulingParameterPolicy_ptr tao_nil (void);
    static CORBA::Boolean tao_marshal (
        MUF_Scheduling::SchedulingParameterPolicy_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */

#if !defined (_MUF_SCHEDULING_SCHEDULER__TRAITS_CH_)
#define _MUF_SCHEDULING_SCHEDULER__TRAITS_CH_
  
  ACE_TEMPLATE_SPECIALIZATION
  struct Kokyu_DSRT_Schedulers_Export Objref_Traits<MUF_Scheduling::Scheduler>
  {
    static MUF_Scheduling::Scheduler_ptr tao_duplicate (
        MUF_Scheduling::Scheduler_ptr
      );
    static void tao_release (
        MUF_Scheduling::Scheduler_ptr
      );
    static MUF_Scheduling::Scheduler_ptr tao_nil (void);
    static CORBA::Boolean tao_marshal (
        MUF_Scheduling::Scheduler_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
};

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/any_op_ch.cpp:52

Kokyu_DSRT_Schedulers_Export void operator<<= (CORBA::Any &, const MUF_Scheduling::SchedulingParameter &); // copying version
Kokyu_DSRT_Schedulers_Export void operator<<= (CORBA::Any &, MUF_Scheduling::SchedulingParameter*); // noncopying version
Kokyu_DSRT_Schedulers_Export CORBA::Boolean operator>>= (const CORBA::Any &, MUF_Scheduling::SchedulingParameter *&); // deprecated
Kokyu_DSRT_Schedulers_Export CORBA::Boolean operator>>= (const CORBA::Any &, const MUF_Scheduling::SchedulingParameter *&);

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/any_op_ch.cpp:52

Kokyu_DSRT_Schedulers_Export void operator<<= (CORBA::Any &, MUF_Scheduling::SchedulingParameterPolicy_ptr); // copying
Kokyu_DSRT_Schedulers_Export void operator<<= (CORBA::Any &, MUF_Scheduling::SchedulingParameterPolicy_ptr *); // non-copying
Kokyu_DSRT_Schedulers_Export CORBA::Boolean operator>>= (const CORBA::Any &, MUF_Scheduling::SchedulingParameterPolicy_ptr &);

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/any_op_ch.cpp:52

Kokyu_DSRT_Schedulers_Export void operator<<= (CORBA::Any &, MUF_Scheduling::Scheduler_ptr); // copying
Kokyu_DSRT_Schedulers_Export void operator<<= (CORBA::Any &, MUF_Scheduling::Scheduler_ptr *); // non-copying
Kokyu_DSRT_Schedulers_Export CORBA::Boolean operator>>= (const CORBA::Any &, MUF_Scheduling::Scheduler_ptr &);

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/cdr_op_ch.cpp:53

Kokyu_DSRT_Schedulers_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const MUF_Scheduling::SchedulingParameter &);
Kokyu_DSRT_Schedulers_Export CORBA::Boolean operator>> (TAO_InputCDR &, MUF_Scheduling::SchedulingParameter &);

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// .\be\be_codegen.cpp:1050

#if defined (__ACE_INLINE__)
#include "MUF_SchedulingC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */


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
// be\be_codegen.cpp:153

#ifndef _TAO_IDL_ORIG_ADAPTERACTIVATORC_H_
#define _TAO_IDL_ORIG_ADAPTERACTIVATORC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "portableserver_export.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Environment.h"
#include "tao/Object.h"
#include "tao/Objref_VarOut_T.h"

#include "tao/PortableServer/PS_ForwardC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_PortableServer_Export

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:48

#if (TAO_HAS_MINIMUM_POA == 0)

namespace PortableServer
{
  // TAO_IDL - Generated from
  // be\be_interface.cpp:598

#if !defined (_PORTABLESERVER_ADAPTERACTIVATOR__VAR_OUT_CH_)
#define _PORTABLESERVER_ADAPTERACTIVATOR__VAR_OUT_CH_
  
  class AdapterActivator;
  typedef AdapterActivator *AdapterActivator_ptr;
  
  typedef
    TAO_Objref_Var_T<
        AdapterActivator
      >
    AdapterActivator_var;
  
  typedef
    TAO_Objref_Out_T<
        AdapterActivator
      >
    AdapterActivator_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_PORTABLESERVER_ADAPTERACTIVATOR_CH_)
#define _PORTABLESERVER_ADAPTERACTIVATOR_CH_
  
  class TAO_PortableServer_Export AdapterActivator
    : public virtual CORBA::Object
  {
  public:
    typedef AdapterActivator_ptr _ptr_type;
    typedef AdapterActivator_var _var_type;
    
    // The static operations.
    static AdapterActivator_ptr _duplicate (AdapterActivator_ptr obj);
    
    static void _tao_release (AdapterActivator_ptr obj);
    
    static AdapterActivator_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static AdapterActivator_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static AdapterActivator_ptr _nil (void)
    {
      return static_cast<AdapterActivator_ptr> (0);
    }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual CORBA::Boolean unknown_adapter (
        ::PortableServer::POA_ptr parent,
        const char * name
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_interface/interface_ch.cpp:210
    
    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    AdapterActivator (void);
    
    virtual ~AdapterActivator (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    AdapterActivator (const AdapterActivator &);
    
    void operator= (const AdapterActivator &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_PortableServer_Export ::CORBA::TypeCode_ptr const _tc_AdapterActivator;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module PortableServer

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:59

// Traits specializations.
namespace TAO
{

#if !defined (_PORTABLESERVER_ADAPTERACTIVATOR__TRAITS_CH_)
#define _PORTABLESERVER_ADAPTERACTIVATOR__TRAITS_CH_
  
  template<>
  struct TAO_PortableServer_Export Objref_Traits< ::PortableServer::AdapterActivator>
  {
    static ::PortableServer::AdapterActivator_ptr duplicate (
        ::PortableServer::AdapterActivator_ptr
      );
    static void release (
        ::PortableServer::AdapterActivator_ptr
      );
    static ::PortableServer::AdapterActivator_ptr nil (void);
    static CORBA::Boolean marshal (
        ::PortableServer::AdapterActivator_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_ch.cpp:52

TAO_PortableServer_Export void operator<<= (CORBA::Any &, PortableServer::AdapterActivator_ptr); // copying
TAO_PortableServer_Export void operator<<= (CORBA::Any &, PortableServer::AdapterActivator_ptr *); // non-copying
TAO_PortableServer_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableServer::AdapterActivator_ptr &);

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */

// TAO_IDL - Generated from
// be\be_codegen.cpp:955

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */



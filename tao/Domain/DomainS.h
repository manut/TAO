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
// be\be_codegen.cpp:391

#ifndef _TAO_IDL_ORIG_DOMAINS_H_
#define _TAO_IDL_ORIG_DOMAINS_H_

#include /**/ "ace/pre.h"

#include "tao/DomainC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/PortableServer/PolicyS.h"
#include "tao/Collocation_Proxy_Broker.h"
#include "tao/PortableServer/PortableServer.h"
#include "tao/PortableServer/Servant_Base.h"
#include "tao/IFR_Client/IFR_ExtendedC.h"

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

#include "domain_export.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Domain_Export

// TAO_IDL - Generated from
// be\be_visitor_module/module_sh.cpp:49

namespace POA_CORBA
{
  
  
  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_sh.cpp:87
  
  class DomainManager;
  typedef DomainManager *DomainManager_ptr;
  
  class _TAO_DomainManager_Direct_Proxy_Impl;
  class _TAO_DomainManager_Strategized_Proxy_Broker;
  
  class TAO_Domain_Export DomainManager
    : public virtual PortableServer::ServantBase
  {
  protected:
    DomainManager (void);
  
  public:
    // Useful for template programming.
    typedef ::CORBA::DomainManager _stub_type;
    typedef ::CORBA::DomainManager_ptr _stub_ptr_type;
    typedef ::CORBA::DomainManager_var _stub_var_type;
    
    DomainManager (const DomainManager& rhs);
    virtual ~DomainManager (void);
    
    virtual CORBA::Boolean _is_a (
        const char* logical_type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static void _is_a_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );
    
    static void _non_existent_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );
    
    static void _interface_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );
    
    static void _component_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );
    
    virtual void _dispatch (
        TAO_ServerRequest & req,
        void * servant_upcall
        ACE_ENV_ARG_DECL
      );
    
    ::CORBA::DomainManager *_this (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45
    
    virtual ::CORBA::Policy_ptr get_domain_policy (
        ::CORBA::PolicyType policy_type
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    static void get_domain_policy_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );
  };
  
  ///////////////////////////////////////////////////////////////////////
  //               Strategized Proxy Broker Declaration 
  //
  
  // TAO_IDL - Generated from
  // be\be_visitor_interface/strategized_proxy_broker_sh.cpp:36
  
  class TAO_Domain_Export _TAO_DomainManager_Strategized_Proxy_Broker
    : public virtual TAO::Collocation_Proxy_Broker
  {
  public: 
    _TAO_DomainManager_Strategized_Proxy_Broker (void);
    
    virtual ~_TAO_DomainManager_Strategized_Proxy_Broker (void);
    
    TAO::Collocation_Strategy
    get_strategy (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((CORBA::SystemException));
    
    void
    dispatch (
        CORBA::Object_ptr obj,
        CORBA::Object_out forward_obj,
        TAO::Argument ** args,
        int num_args,
        const char * op,
        size_t op_len,
        TAO::Collocation_Strategy strategy
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((CORBA::Exception));
    
    static _TAO_DomainManager_Strategized_Proxy_Broker *
    the_TAO_DomainManager_Strategized_Proxy_Broker (void);
  };
  
  //
  //            End Strategized Proxy Broker Declaration 
  ///////////////////////////////////////////////////////////////////////
  
  
  
  // TAO_IDL - Generated from 
  // be\be_visitor_interface/direct_proxy_impl_sh.cpp:31
  
  ///////////////////////////////////////////////////////////////////////
  //                    Direct  Impl. Declaration
  //
  
  class TAO_Domain_Export _TAO_DomainManager_Direct_Proxy_Impl
  {
  public:
    _TAO_DomainManager_Direct_Proxy_Impl (void);
    
    virtual ~_TAO_DomainManager_Direct_Proxy_Impl (void) {}
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24
    
    static void
    get_domain_policy (
        TAO_Abstract_ServantBase *servant,
        TAO::Argument ** args,
        int num_args
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
  };
  
  //
  //                Direct  Proxy Impl. Declaration
  ///////////////////////////////////////////////////////////////////////
  
  
  
  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_sh.cpp:87
  
  class ConstructionPolicy;
  typedef ConstructionPolicy *ConstructionPolicy_ptr;
  
  class _TAO_ConstructionPolicy_Direct_Proxy_Impl;
  class _TAO_ConstructionPolicy_Strategized_Proxy_Broker;
  
  class TAO_Domain_Export ConstructionPolicy
    : public virtual POA_CORBA::Policy
  {
  protected:
    ConstructionPolicy (void);
  
  public:
    // Useful for template programming.
    typedef ::CORBA::ConstructionPolicy _stub_type;
    typedef ::CORBA::ConstructionPolicy_ptr _stub_ptr_type;
    typedef ::CORBA::ConstructionPolicy_var _stub_var_type;
    
    ConstructionPolicy (const ConstructionPolicy& rhs);
    virtual ~ConstructionPolicy (void);
    
    virtual CORBA::Boolean _is_a (
        const char* logical_type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static void _is_a_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );
    
    static void _non_existent_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );
    
    static void _interface_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );
    
    static void _component_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );
    
    virtual void _dispatch (
        TAO_ServerRequest & req,
        void * servant_upcall
        ACE_ENV_ARG_DECL
      );
    
    ::CORBA::ConstructionPolicy *_this (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void make_domain_manager (
        ::CORBA::InterfaceDef_ptr object_type,
        ::CORBA::Boolean constr_policy
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    static void make_domain_manager_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL
      );
    
    static void
    _get_policy_type_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:1859
    
    static void
    copy_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:1859
    
    static void
    destroy_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
  };
  
  ///////////////////////////////////////////////////////////////////////
  //               Strategized Proxy Broker Declaration 
  //
  
  // TAO_IDL - Generated from
  // be\be_visitor_interface/strategized_proxy_broker_sh.cpp:36
  
  class TAO_Domain_Export _TAO_ConstructionPolicy_Strategized_Proxy_Broker
    : public virtual TAO::Collocation_Proxy_Broker
  {
  public: 
    _TAO_ConstructionPolicy_Strategized_Proxy_Broker (void);
    
    virtual ~_TAO_ConstructionPolicy_Strategized_Proxy_Broker (void);
    
    TAO::Collocation_Strategy
    get_strategy (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((CORBA::SystemException));
    
    void
    dispatch (
        CORBA::Object_ptr obj,
        CORBA::Object_out forward_obj,
        TAO::Argument ** args,
        int num_args,
        const char * op,
        size_t op_len,
        TAO::Collocation_Strategy strategy
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((CORBA::Exception));
    
    static _TAO_ConstructionPolicy_Strategized_Proxy_Broker *
    the_TAO_ConstructionPolicy_Strategized_Proxy_Broker (void);
  };
  
  //
  //            End Strategized Proxy Broker Declaration 
  ///////////////////////////////////////////////////////////////////////
  
  
  
  // TAO_IDL - Generated from 
  // be\be_visitor_interface/direct_proxy_impl_sh.cpp:31
  
  ///////////////////////////////////////////////////////////////////////
  //                    Direct  Impl. Declaration
  //
  
  class TAO_Domain_Export _TAO_ConstructionPolicy_Direct_Proxy_Impl
    : public virtual ::POA_CORBA::_TAO_Policy_Direct_Proxy_Impl
  {
  public:
    _TAO_ConstructionPolicy_Direct_Proxy_Impl (void);
    
    virtual ~_TAO_ConstructionPolicy_Direct_Proxy_Impl (void) {}
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24
    
    static void
    make_domain_manager (
        TAO_Abstract_ServantBase *servant,
        TAO::Argument ** args,
        int num_args
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));static void
    _get_policy_type (
        TAO_Abstract_ServantBase *servant, 
        TAO::Argument ** args,
        int num_args
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2050
    
    static void
    copy (
        TAO_Abstract_ServantBase *servant, 
        TAO::Argument ** args,
        int num_args
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2050
    
    static void
    destroy (
        TAO_Abstract_ServantBase *servant, 
        TAO::Argument ** args,
        int num_args
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
  };
  
  //
  //                Direct  Proxy Impl. Declaration
  ///////////////////////////////////////////////////////////////////////
  
  

// TAO_IDL - Generated from
// be\be_visitor_module/module_sh.cpp:80

} // module CORBA

// TAO_IDL - Generated from 
// be\be_codegen.cpp:995

#include "DomainS_T.h"

#if defined (__ACE_INLINE__)
#include "DomainS.inl"
#endif /* defined INLINE */

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"
#endif /* ifndef */


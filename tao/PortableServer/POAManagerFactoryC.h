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
// be/be_codegen.cpp:154

#ifndef _TAO_IDL_POAMANAGERFACTORYC_H_
#define _TAO_IDL_POAMANAGERFACTORYC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/PortableServer/portableserver_export.h"
#include "tao/AnyTypeCode/AnyTypeCode_methods.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Environment.h"
#include "tao/Object.h"
#include "tao/AnyTypeCode/PolicyA.h"
#include "tao/Sequence_T.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"
#include "tao/Versioned_Namespace.h"

#include "tao/PolicyC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_PortableServer_Export

// should be generated, maybe by be_visitor_module/module_ch.cpp
TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:49

namespace PortableServer
{

  // TAO_IDL - Generated from
  // be/be_interface.cpp:640

#if !defined (_PORTABLESERVER_POAMANAGER__VAR_OUT_CH_)
#define _PORTABLESERVER_POAMANAGER__VAR_OUT_CH_

  class POAManager;
  typedef POAManager *POAManager_ptr;

  typedef
    TAO_Objref_Var_T<
        POAManager
      >
    POAManager_var;

  typedef
    TAO_Objref_Out_T<
        POAManager
      >
    POAManager_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_interface.cpp:640

#if !defined (_PORTABLESERVER_POAMANAGERFACTORY__VAR_OUT_CH_)
#define _PORTABLESERVER_POAMANAGERFACTORY__VAR_OUT_CH_

  class POAManagerFactory;
  typedef POAManagerFactory *POAManagerFactory_ptr;

  typedef
    TAO_Objref_Var_T<
        POAManagerFactory
      >
    POAManagerFactory_var;

  typedef
    TAO_Objref_Out_T<
        POAManagerFactory
      >
    POAManagerFactory_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_ch.cpp:54

#if !defined (_PORTABLESERVER_POAMANAGERFACTORY_CH_)
#define _PORTABLESERVER_POAMANAGERFACTORY_CH_

  class TAO_PortableServer_Export POAManagerFactory
    : public virtual ::CORBA::Object
  {
  public:
    typedef POAManagerFactory_ptr _ptr_type;
    typedef POAManagerFactory_var _var_type;

    // The static operations.
    static POAManagerFactory_ptr _duplicate (POAManagerFactory_ptr obj);

    static void _tao_release (POAManagerFactory_ptr obj);

    static POAManagerFactory_ptr _narrow (
        ::CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static POAManagerFactory_ptr _unchecked_narrow (
        ::CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static POAManagerFactory_ptr _nil (void)
    {
      return static_cast<POAManagerFactory_ptr> (0);
    }



    // TAO_IDL - Generated from
    // be/be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_PORTABLESERVER_POAMANAGERFACTORY_POAMANAGERSEQ_CH_)
#define _PORTABLESERVER_POAMANAGERFACTORY_POAMANAGERSEQ_CH_

    class POAManagerSeq;

    typedef
      TAO_VarSeq_Var_T<
          POAManagerSeq
        >
      POAManagerSeq_var;

    typedef
      TAO_Seq_Out_T<
          POAManagerSeq
        >
      POAManagerSeq_out;

    class TAO_PortableServer_Export POAManagerSeq
      : public
          TAO::unbounded_object_reference_sequence<
              PortableServer::POAManager,
              PortableServer::POAManager_var
            >
    {
    public:
      POAManagerSeq (void);
      POAManagerSeq ( ::CORBA::ULong max);
      POAManagerSeq (
          ::CORBA::ULong max,
          ::CORBA::ULong length,
          PortableServer::POAManager_ptr* buffer,
          ::CORBA::Boolean release = false
        );
      POAManagerSeq (const POAManagerSeq &);
      ~POAManagerSeq (void);

      static void _tao_any_destructor (void *);

      typedef POAManagerSeq_var _var_type;
    };

#endif /* end #if !defined */

    // TAO_IDL - Generated from
    // be/be_visitor_typecode/typecode_decl.cpp:49

    static ::CORBA::TypeCode_ptr const _tc_POAManagerSeq;

    // TAO_IDL - Generated from
    // be/be_visitor_exception/exception_ch.cpp:53

#if !defined (_PORTABLESERVER_POAMANAGERFACTORY_MANAGERALREADYEXISTS_CH_)
#define _PORTABLESERVER_POAMANAGERFACTORY_MANAGERALREADYEXISTS_CH_

    class TAO_PortableServer_Export ManagerAlreadyExists : public ::CORBA::UserException
    {
    public:

      ManagerAlreadyExists (void);
      ManagerAlreadyExists (const ManagerAlreadyExists &);
      ~ManagerAlreadyExists (void);

      ManagerAlreadyExists &operator= (const ManagerAlreadyExists &);

      static void _tao_any_destructor (void *);

      static ManagerAlreadyExists *_downcast ( ::CORBA::Exception *);
      static const ManagerAlreadyExists *_downcast ( ::CORBA::Exception const *);

      static ::CORBA::Exception *_alloc (void);

      virtual ::CORBA::Exception *_tao_duplicate (void) const;

      virtual void _raise (void) const;

      virtual void _tao_encode (
          TAO_OutputCDR &cdr
          ACE_ENV_ARG_DECL
        ) const;

      virtual void _tao_decode (
          TAO_InputCDR &cdr
          ACE_ENV_ARG_DECL
        );

      virtual ::CORBA::TypeCode_ptr _tao_type (void) const;
    };

    // TAO_IDL - Generated from
    // be/be_visitor_typecode/typecode_decl.cpp:49

    static ::CORBA::TypeCode_ptr const _tc_ManagerAlreadyExists;

#endif /* end #if !defined */

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::PortableServer::POAManager_ptr create_POAManager (
        const char * id,
        const ::CORBA::PolicyList & policies
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException,
        ::PortableServer::POAManagerFactory::ManagerAlreadyExists,
        ::CORBA::PolicyError
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::PortableServer::POAManagerFactory::POAManagerSeq * list (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::PortableServer::POAManager_ptr find (
        const char * id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_interface/interface_ch.cpp:210

    virtual ::CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);

  protected:
    // Abstract or local interface only.
    POAManagerFactory (void);

    virtual ~POAManagerFactory (void);

  private:
    // Private and unimplemented for concrete interfaces.
    POAManagerFactory (const POAManagerFactory &);

    void operator= (const POAManagerFactory &);
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:49

  extern TAO_PortableServer_Export ::CORBA::TypeCode_ptr const _tc_POAManagerFactory;

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:78

} // module PortableServer

// should be generated, maybe by be_visitor_module/module_ch.cpp
TAO_END_VERSIONED_NAMESPACE_DECL

// TAO_IDL - Generated from
// be/be_visitor_traits.cpp:63
TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{

#if !defined (_PORTABLESERVER_POAMANAGER__TRAITS_)
#define _PORTABLESERVER_POAMANAGER__TRAITS_

  template<>
  struct TAO_PortableServer_Export Objref_Traits< ::PortableServer::POAManager>
  {
    static ::PortableServer::POAManager_ptr duplicate (
        ::PortableServer::POAManager_ptr
      );
    static void release (
        ::PortableServer::POAManager_ptr
      );
    static ::PortableServer::POAManager_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::PortableServer::POAManager_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */

#if !defined (_PORTABLESERVER_POAMANAGERFACTORY__TRAITS_)
#define _PORTABLESERVER_POAMANAGERFACTORY__TRAITS_

  template<>
  struct TAO_PortableServer_Export Objref_Traits< ::PortableServer::POAManagerFactory>
  {
    static ::PortableServer::POAManagerFactory_ptr duplicate (
        ::PortableServer::POAManagerFactory_ptr
      );
    static void release (
        ::PortableServer::POAManagerFactory_ptr
      );
    static ::PortableServer::POAManagerFactory_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::PortableServer::POAManagerFactory_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// be/be_codegen.cpp:1092
#include /**/ "ace/post.h"

#endif /* ifndef */
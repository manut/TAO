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
// be\be_codegen.cpp:609

#ifndef _TAO_IDL_ORIG_SERVEROBJECTS_CPP_
#define _TAO_IDL_ORIG_SERVEROBJECTS_CPP_


#include "ServerObjectS.h"
#include "tao/PortableServer/Object_Adapter.h"
#include "tao/PortableServer/Operation_Table.h"
#include "tao/TAO_Server_Request.h"
#include "tao/ORB_Core.h"
#include "tao/Profile.h"
#include "tao/Stub.h"
#include "tao/IFR_Client_Adapter.h"
#include "tao/Object_T.h"
#include "tao/Typecode.h"
#include "tao/DynamicC.h"
#include "tao/CDR.h"
#include "tao/Basic_Arguments.h"
#include "tao/PortableInterceptor.h"
#if TAO_HAS_INTERCEPTORS == 1
#include "tao/PortableServer/PICurrent_Guard.h"
#include "tao/PortableServer/ServerRequestInfo.h"
#include "tao/PortableServer/ServerInterceptorAdapter.h"
#include "tao/RequestInfo_Util.h"
#endif  /* TAO_HAS_INTERCEPTORS == 1 */

#include "ace/Dynamic_Service.h"
#include "ace/Malloc_Allocator.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "ServerObjectS.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:65

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_interface.cpp:1536

class TAO_ImplementationRepository_ServerObject_Perfect_Hash_OpTable
  : public TAO_Perfect_Hash_OpTable
{
private:
  unsigned int hash (const char *str, unsigned int len);

public:
  const TAO_operation_db_entry * lookup (const char *str, unsigned int len);
};

/* C++ code produced by gperf version 2.8 (ACE version) */
/* Command-line: c:\ace\latest\ace_wrappers\bin\gperf.exe -m -M -J -c -C -D -E -T -f 0 -F 0,0,0 -a -o -t -p -K opname_ -L C++ -Z TAO_ImplementationRepository_ServerObject_Perfect_Hash_OpTable -N lookup  */
unsigned int
TAO_ImplementationRepository_ServerObject_Perfect_Hash_OpTable::hash (const char *str, unsigned int len)
{
  static const unsigned char asso_values[] =
    {
#if defined (ACE_MVS)
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16,  0,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16,  0,
     16, 16, 16,  5, 16,  0, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16,  0,
     16,  0, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16,  0,  0, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16,
#else
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16,  0, 16,  0, 16, 16,
     16,  5, 16,  0, 16, 16, 16, 16, 16, 16,
      0, 16,  0, 16, 16,  0,  0, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16,
#endif /* ACE_MVS */
    };
  return len + asso_values[(int) str[len - 1]] + asso_values[(int) str[0]];
}

const class TAO_operation_db_entry *
TAO_ImplementationRepository_ServerObject_Perfect_Hash_OpTable::lookup (const char *str, unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 6,
      MIN_WORD_LENGTH = 4,
      MAX_WORD_LENGTH = 13,
      MIN_HASH_VALUE = 4,
      MAX_HASH_VALUE = 15,
      HASH_VALUE_RANGE = 12,
      DUPLICATES = 0,
      WORDLIST_SIZE = 10
    };

  static const class TAO_operation_db_entry  wordlist[] =
    {
      {"",0,0,0},{"",0,0,0},{"",0,0,0},{"",0,0,0},
      {"ping", &POA_ImplementationRepository::ServerObject::ping_skel, &POA_ImplementationRepository::_TAO_ServerObject_ThruPOA_Proxy_Impl::ping, &POA_ImplementationRepository::_TAO_ServerObject_Direct_Proxy_Impl::ping},
      {"_is_a", &POA_ImplementationRepository::ServerObject::_is_a_skel, 0, 0},
      {"",0,0,0},{"",0,0,0},
      {"shutdown", &POA_ImplementationRepository::ServerObject::shutdown_skel, &POA_ImplementationRepository::_TAO_ServerObject_ThruPOA_Proxy_Impl::shutdown, &POA_ImplementationRepository::_TAO_ServerObject_Direct_Proxy_Impl::shutdown},
      {"",0,0,0},
      {"_component", &POA_ImplementationRepository::ServerObject::_component_skel, 0, 0},
      {"",0,0,0},{"",0,0,0},
      {"_non_existent", &POA_ImplementationRepository::ServerObject::_non_existent_skel, 0, 0},
      {"",0,0,0},
      {"_interface", &POA_ImplementationRepository::ServerObject::_interface_skel, 0, 0},
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= MIN_HASH_VALUE)
        {
          const char *s = wordlist[key].opname_;

          if (*str == *s && !strncmp (str + 1, s + 1, len - 1))
            return &wordlist[key];
        }
    }
  return 0;
}

static TAO_ImplementationRepository_ServerObject_Perfect_Hash_OpTable tao_ImplementationRepository_ServerObject_optable;

// TAO_IDL - Generated from
// be\be_visitor_interface/interceptors_ss.cpp:53

#if (TAO_HAS_INTERCEPTORS == 1)

// TAO_IDL - Generated from
// be\be_visitor_operation/interceptors_ss.cpp:74

class TAO_ServerRequestInfo_ImplementationRepository_ServerObject_ping : public TAO_ServerRequestInfo
{
public:
  TAO_ServerRequestInfo_ImplementationRepository_ServerObject_ping (
      TAO_ServerRequest &_tao_server_request,
      TAO_Object_Adapter::Servant_Upcall *tao_servant_upcall,
      POA_ImplementationRepository::ServerObject *tao_impl
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  virtual Dynamic::ParameterList * arguments (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((CORBA::SystemException));
  
  virtual Dynamic::ExceptionList * exceptions (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((CORBA::SystemException));
  
  virtual CORBA::Any * result (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((CORBA::SystemException));
  
  virtual char * target_most_derived_interface (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((CORBA::SystemException));
  
  virtual CORBA::Boolean target_is_a (
      const char * id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((CORBA::SystemException));
  
private:
  TAO_ServerRequestInfo_ImplementationRepository_ServerObject_ping (
      const TAO_ServerRequestInfo_ImplementationRepository_ServerObject_ping &
    );
  
  void operator= (
      const TAO_ServerRequestInfo_ImplementationRepository_ServerObject_ping &
    );
  
private:
  POA_ImplementationRepository::ServerObject *_tao_impl;
  
};

// TAO_IDL - Generated from
// be\be_visitor_operation/interceptors_ss.cpp:438

TAO_ServerRequestInfo_ImplementationRepository_ServerObject_ping::TAO_ServerRequestInfo_ImplementationRepository_ServerObject_ping (
    TAO_ServerRequest &_tao_server_request,
    TAO_Object_Adapter::Servant_Upcall *_tao_servant_upcall,
    POA_ImplementationRepository::ServerObject *tao_impl
    ACE_ENV_ARG_DECL_NOT_USED
  )
  : TAO_ServerRequestInfo (_tao_server_request, _tao_servant_upcall),
    _tao_impl (tao_impl)
{}

Dynamic::ParameterList *
TAO_ServerRequestInfo_ImplementationRepository_ServerObject_ping::arguments (
    ACE_ENV_SINGLE_ARG_DECL
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Generate the argument list on demand.
  Dynamic::ParameterList *parameter_list =
    TAO_RequestInfo_Util::make_parameter_list (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);
  
  return parameter_list;
}

Dynamic::ExceptionList *
TAO_ServerRequestInfo_ImplementationRepository_ServerObject_ping::exceptions (
    ACE_ENV_SINGLE_ARG_DECL
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Generate the exception list on demand.
  Dynamic::ExceptionList *exception_list =
    TAO_RequestInfo_Util::make_exception_list (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);
  
  return exception_list;
}

CORBA::Any * 
TAO_ServerRequestInfo_ImplementationRepository_ServerObject_ping::result (
    ACE_ENV_SINGLE_ARG_DECL
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Generate the result on demand.
  CORBA::Boolean tk_void_any = 1;
  CORBA::Any *result_any =
    TAO_RequestInfo_Util::make_any (tk_void_any ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);
  
  return result_any;
}

char *
TAO_ServerRequestInfo_ImplementationRepository_ServerObject_ping::target_most_derived_interface (
    ACE_ENV_SINGLE_ARG_DECL_NOT_USED
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return
    CORBA::string_dup (this->_tao_impl->_interface_repository_id ());
}

CORBA::Boolean
TAO_ServerRequestInfo_ImplementationRepository_ServerObject_ping::target_is_a (
    const char * id
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->_tao_impl->_is_a (id ACE_ENV_ARG_PARAMETER);
}

// TAO_IDL - Generated from
// be\be_visitor_operation/interceptors_ss.cpp:74

class TAO_ServerRequestInfo_ImplementationRepository_ServerObject_shutdown : public TAO_ServerRequestInfo
{
public:
  TAO_ServerRequestInfo_ImplementationRepository_ServerObject_shutdown (
      TAO_ServerRequest &_tao_server_request,
      TAO_Object_Adapter::Servant_Upcall *tao_servant_upcall,
      POA_ImplementationRepository::ServerObject *tao_impl
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  virtual Dynamic::ParameterList * arguments (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((CORBA::SystemException));
  
  virtual Dynamic::ExceptionList * exceptions (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((CORBA::SystemException));
  
  virtual CORBA::Any * result (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((CORBA::SystemException));
  
  virtual char * target_most_derived_interface (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((CORBA::SystemException));
  
  virtual CORBA::Boolean target_is_a (
      const char * id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((CORBA::SystemException));
  
private:
  TAO_ServerRequestInfo_ImplementationRepository_ServerObject_shutdown (
      const TAO_ServerRequestInfo_ImplementationRepository_ServerObject_shutdown &
    );
  
  void operator= (
      const TAO_ServerRequestInfo_ImplementationRepository_ServerObject_shutdown &
    );
  
private:
  POA_ImplementationRepository::ServerObject *_tao_impl;
  
};

// TAO_IDL - Generated from
// be\be_visitor_operation/interceptors_ss.cpp:438

TAO_ServerRequestInfo_ImplementationRepository_ServerObject_shutdown::TAO_ServerRequestInfo_ImplementationRepository_ServerObject_shutdown (
    TAO_ServerRequest &_tao_server_request,
    TAO_Object_Adapter::Servant_Upcall *_tao_servant_upcall,
    POA_ImplementationRepository::ServerObject *tao_impl
    ACE_ENV_ARG_DECL_NOT_USED
  )
  : TAO_ServerRequestInfo (_tao_server_request, _tao_servant_upcall),
    _tao_impl (tao_impl)
{}

Dynamic::ParameterList *
TAO_ServerRequestInfo_ImplementationRepository_ServerObject_shutdown::arguments (
    ACE_ENV_SINGLE_ARG_DECL
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Generate the argument list on demand.
  Dynamic::ParameterList *parameter_list =
    TAO_RequestInfo_Util::make_parameter_list (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);
  
  return parameter_list;
}

Dynamic::ExceptionList *
TAO_ServerRequestInfo_ImplementationRepository_ServerObject_shutdown::exceptions (
    ACE_ENV_SINGLE_ARG_DECL
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Generate the exception list on demand.
  Dynamic::ExceptionList *exception_list =
    TAO_RequestInfo_Util::make_exception_list (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);
  
  return exception_list;
}

CORBA::Any * 
TAO_ServerRequestInfo_ImplementationRepository_ServerObject_shutdown::result (
    ACE_ENV_SINGLE_ARG_DECL
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Generate the result on demand.
  CORBA::Boolean tk_void_any = 1;
  CORBA::Any *result_any =
    TAO_RequestInfo_Util::make_any (tk_void_any ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);
  
  return result_any;
}

char *
TAO_ServerRequestInfo_ImplementationRepository_ServerObject_shutdown::target_most_derived_interface (
    ACE_ENV_SINGLE_ARG_DECL_NOT_USED
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return
    CORBA::string_dup (this->_tao_impl->_interface_repository_id ());
}

CORBA::Boolean
TAO_ServerRequestInfo_ImplementationRepository_ServerObject_shutdown::target_is_a (
    const char * id
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->_tao_impl->_is_a (id ACE_ENV_ARG_PARAMETER);
}

#endif /* TAO_HAS_INTERCEPTORS */

///////////////////////////////////////////////////////////////////////
//            Strategized Proxy Broker Implementation
//

// TAO_IDL - Generated from
// be\be_visitor_interface/strategized_proxy_broker_ss.cpp:40

// Factory function Implementation.
POA_ImplementationRepository::_TAO_ServerObject_Strategized_Proxy_Broker *
POA_ImplementationRepository::_TAO_ServerObject_Strategized_Proxy_Broker::the_TAO_ServerObject_Strategized_Proxy_Broker (void)
{
  static POA_ImplementationRepository::_TAO_ServerObject_Strategized_Proxy_Broker
  strategized_proxy_broker;
  
  return &strategized_proxy_broker;
}

POA_ImplementationRepository::_TAO_ServerObject_Strategized_Proxy_Broker::_TAO_ServerObject_Strategized_Proxy_Broker (void)
{
}

POA_ImplementationRepository::_TAO_ServerObject_Strategized_Proxy_Broker::~_TAO_ServerObject_Strategized_Proxy_Broker (void)
{
}

TAO::Collocation_Strategy
POA_ImplementationRepository::_TAO_ServerObject_Strategized_Proxy_Broker::get_strategy (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO::Collocation_Strategy strategy =
    TAO_ORB_Core::collocation_strategy (obj ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (TAO::TAO_CS_REMOTE_STRATEGY);
  
  return strategy;
}

void
POA_ImplementationRepository::_TAO_ServerObject_Strategized_Proxy_Broker::dispatch (
    CORBA::Object_ptr obj,
    CORBA::Object_out forward_obj,
    TAO::Argument ** args,
    int num_args,
    const char * op,
    size_t op_len,
    TAO::Collocation_Strategy strategy
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((CORBA::Exception))
{
  TAO_Object_Adapter::Servant_Upcall servant_upcall (
      obj->_stubobj ()->servant_orb_var ()->orb_core ()
    );
  
  TAO_Collocated_Skeleton collocated_skel;
  TAO_Abstract_ServantBase *servant = 0;
  
  if (strategy == TAO::TAO_CS_THRU_POA_STRATEGY)
    {
      servant_upcall.prepare_for_upcall (
          obj->_stubobj ()->object_key (),
          op,
          forward_obj
          ACE_ENV_ARG_PARAMETER
        );
      ACE_CHECK;
      
      servant_upcall.pre_invoke_collocated_request (
          ACE_ENV_SINGLE_ARG_PARAMETER
        );
      ACE_CHECK;
      
      servant = servant_upcall.servant ();
    }
  else
    {
      servant = obj->_servant ();
    }
  
  int status = servant->_find (op,
                               collocated_skel,
                               strategy,
                               op_len);
  
  if (status == -1)
    {
      ACE_THROW (CORBA::BAD_OPERATION (TAO::VMCID | 2, CORBA::COMPLETED_NO));
    }
  
  ACE_TRY
    {
      collocated_skel (servant,
                       args,
                       num_args
                       ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
#if (TAO_HAS_MINIMUM_CORBA == 0)
  ACE_CATCH (PortableServer::ForwardRequest, forward_request)
    {
      forward_obj =
        CORBA::Object::_duplicate (forward_request.forward_reference.in ());
      return;
    }
#else
  ACE_CATCHANY
    {
      ACE_UNUSED_ARG (forward_obj);
      ACE_RE_THROW;
    }
#endif /* TAO_HAS_MINIMUM_CORBA */
  ACE_ENDTRY;
  ACE_CHECK;
}

//
//        End Strategized Proxy Broker Implementation
///////////////////////////////////////////////////////////////////////

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_ss.cpp:652

TAO::Collocation_Proxy_Broker *
ImplementationRepository__TAO_ServerObject_Proxy_Broker_Factory_function (CORBA::Object_ptr)
{
  return
    ::POA_ImplementationRepository::_TAO_ServerObject_Strategized_Proxy_Broker::the_TAO_ServerObject_Strategized_Proxy_Broker ();
}

int
ImplementationRepository__TAO_ServerObject_Proxy_Broker_Factory_Initializer (size_t)
{
  ImplementationRepository__TAO_ServerObject_Proxy_Broker_Factory_function_pointer = 
    ImplementationRepository__TAO_ServerObject_Proxy_Broker_Factory_function;
  
  return 0;
}

static int
ImplementationRepository__TAO_ServerObject_Proxy_Broker_Stub_Factory_Initializer_Scarecrow =
  ImplementationRepository__TAO_ServerObject_Proxy_Broker_Factory_Initializer (
      reinterpret_cast<
          size_t> (
          ImplementationRepository__TAO_ServerObject_Proxy_Broker_Factory_Initializer
        )
    );


///////////////////////////////////////////////////////////////////////
//                 ThruPOA Proxy  Implementation
//

// TAO_IDL - Generated from
// be\be_visitor_interface/thru_poa_proxy_impl_ss.cpp:37

POA_ImplementationRepository::_TAO_ServerObject_ThruPOA_Proxy_Impl::_TAO_ServerObject_ThruPOA_Proxy_Impl (void)
{}

// ThruPOA Implementation of the IDL interface methods

// TAO_IDL - Generated from 
// be\be_visitor_operation/thru_poa_proxy_impl_ss.cpp:52

void
POA_ImplementationRepository::_TAO_ServerObject_ThruPOA_Proxy_Impl::ping (
    TAO_Abstract_ServantBase *servant,
    TAO::Argument **,
    int 
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  reinterpret_cast<
      POA_ImplementationRepository::ServerObject_ptr> (
      servant->_downcast (
          "IDL:ImplementationRepository/ServerObject:1.0"
        )
    )->ping (
        ACE_ENV_SINGLE_ARG_PARAMETER
      );
  ACE_CHECK;
}

// TAO_IDL - Generated from 
// be\be_visitor_operation/thru_poa_proxy_impl_ss.cpp:52

void
POA_ImplementationRepository::_TAO_ServerObject_ThruPOA_Proxy_Impl::shutdown (
    TAO_Abstract_ServantBase *servant,
    TAO::Argument **,
    int 
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  reinterpret_cast<
      POA_ImplementationRepository::ServerObject_ptr> (
      servant->_downcast (
          "IDL:ImplementationRepository/ServerObject:1.0"
        )
    )->shutdown (
        ACE_ENV_SINGLE_ARG_PARAMETER
      );
  ACE_CHECK;
}

//
//           End ThruPOA Proxy Implementation
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
//                 Direct Proxy  Implementation
//

POA_ImplementationRepository::_TAO_ServerObject_Direct_Proxy_Impl::_TAO_ServerObject_Direct_Proxy_Impl (void)
{}

// TAO_IDL - Generated from 
// be\be_visitor_operation/direct_proxy_impl_ss.cpp:42

void
POA_ImplementationRepository::_TAO_ServerObject_Direct_Proxy_Impl::ping (
    TAO_Abstract_ServantBase  *servant,
    TAO::Argument **,
    int 
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  reinterpret_cast<
      POA_ImplementationRepository::ServerObject_ptr> (
      servant->_downcast (
          "IDL:ImplementationRepository/ServerObject:1.0"
        )
    )->ping (
        ACE_ENV_SINGLE_ARG_PARAMETER
      );
  ACE_CHECK;
}// TAO_IDL - Generated from 
// be\be_visitor_operation/direct_proxy_impl_ss.cpp:42

void
POA_ImplementationRepository::_TAO_ServerObject_Direct_Proxy_Impl::shutdown (
    TAO_Abstract_ServantBase  *servant,
    TAO::Argument **,
    int 
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  reinterpret_cast<
      POA_ImplementationRepository::ServerObject_ptr> (
      servant->_downcast (
          "IDL:ImplementationRepository/ServerObject:1.0"
        )
    )->shutdown (
        ACE_ENV_SINGLE_ARG_PARAMETER
      );
  ACE_CHECK;
}

//
//           End Direct Proxy Implementation
///////////////////////////////////////////////////////////////////////

// TAO_IDL - Generated from 
// be\be_visitor_interface/interface_ss.cpp:97

POA_ImplementationRepository::ServerObject::ServerObject (void)
{
  this->optable_ = &tao_ImplementationRepository_ServerObject_optable;
}

POA_ImplementationRepository::ServerObject::ServerObject (const ServerObject& rhs)
  : TAO_Abstract_ServantBase (rhs),
    TAO_ServantBase (rhs)
{
}

POA_ImplementationRepository::ServerObject::~ServerObject (void)
{
}

// TAO_IDL - Generated from 
// be\be_visitor_operation/operation_ss.cpp:98

void POA_ImplementationRepository::ServerObject::ping_skel (
    TAO_ServerRequest &_tao_server_request,
    void *_tao_servant,
    void *_tao_servant_upcall
    ACE_ENV_ARG_DECL
  )
{
  POA_ImplementationRepository::ServerObject *_tao_impl =
    static_cast<
        POA_ImplementationRepository::ServerObject *> (
        _tao_servant
      );
  _tao_server_request.argument_flag (0);
  
  
#if (TAO_HAS_INTERCEPTORS == 1)
  TAO_Object_Adapter::Servant_Upcall *_tao_upcall =
    static_cast<
        TAO_Object_Adapter::Servant_Upcall *> (
        _tao_servant_upcall
      );
    
  TAO_ServerRequestInterceptor_Adapter _tao_vfr (
      _tao_server_request.orb_core ()->server_request_interceptors (),
      _tao_server_request.interceptor_count ()
    );
  
  TAO_ServerRequestInfo_ImplementationRepository_ServerObject_ping _tao_ri (
      _tao_server_request,
      _tao_upcall,
      _tao_impl
      ACE_ENV_ARG_PARAMETER
    );
  
  ACE_TRY
    {
      {
        TAO::PICurrent_Guard _tao_pi_guard (_tao_ri.server_request (),
                                            true  /* Copy TSC to RSC */);
        
        _tao_vfr.receive_request (&_tao_ri ACE_ENV_ARG_PARAMETER);
        ACE_TRY_CHECK;
        
        if (!_tao_vfr.location_forwarded ())
          {
#endif /* TAO_HAS_INTERCEPTORS */
            
              _tao_impl->ping (
                  ACE_ENV_SINGLE_ARG_PARAMETER
                );
            TAO_INTERCEPTOR_CHECK;
#if (TAO_HAS_INTERCEPTORS == 1)
          }
      }
      
      if (!_tao_vfr.location_forwarded ())
        {
          _tao_ri.reply_status (PortableInterceptor::SUCCESSFUL);
          _tao_vfr.send_reply (&_tao_ri ACE_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;
        }
    }
  ACE_CATCHANY
    {
      _tao_ri.exception (&ACE_ANY_EXCEPTION);
      _tao_vfr.send_exception (
          &_tao_ri
          ACE_ENV_ARG_PARAMETER
        );
      ACE_TRY_CHECK;
      
      PortableInterceptor::ReplyStatus _tao_status =
        _tao_ri.reply_status (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
      
      if (_tao_status == PortableInterceptor::SYSTEM_EXCEPTION
          || _tao_status == PortableInterceptor::USER_EXCEPTION)
        {
          ACE_RE_THROW;
        }
    }
  
# if defined (ACE_HAS_EXCEPTIONS) \
  && defined (ACE_HAS_BROKEN_UNEXPECTED_EXCEPTIONS)
  ACE_CATCHALL
    {
      CORBA::UNKNOWN ex;
      
      _tao_ri.exception (&ex);
      _tao_vfr.send_exception (
          &_tao_ri
          ACE_ENV_ARG_PARAMETER
        );
      ACE_TRY_CHECK;
      
      PortableInterceptor::ReplyStatus _tao_status =
        _tao_ri.reply_status (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
      
      if (_tao_status == PortableInterceptor::SYSTEM_EXCEPTION)
        ACE_TRY_THROW (ex);
    }
# endif  /* ACE_HAS_EXCEPTIONS && ACE_HAS_BROKEN_UNEXPECTED_EXCEPTIONS */
  ACE_ENDTRY;
  ACE_CHECK;
#endif /* TAO_HAS_INTERCEPTORS */
  
  _tao_server_request.init_reply ();
  
  // In case _tao_servant_upcall is not used in this function
  ACE_UNUSED_ARG (_tao_servant_upcall);
}

// TAO_IDL - Generated from 
// be\be_visitor_operation/operation_ss.cpp:98

void POA_ImplementationRepository::ServerObject::shutdown_skel (
    TAO_ServerRequest &_tao_server_request,
    void *_tao_servant,
    void *_tao_servant_upcall
    ACE_ENV_ARG_DECL
  )
{
  POA_ImplementationRepository::ServerObject *_tao_impl =
    static_cast<
        POA_ImplementationRepository::ServerObject *> (
        _tao_servant
      );
  _tao_server_request.argument_flag (0);
  
  
#if (TAO_HAS_INTERCEPTORS == 1)
  TAO_Object_Adapter::Servant_Upcall *_tao_upcall =
    static_cast<
        TAO_Object_Adapter::Servant_Upcall *> (
        _tao_servant_upcall
      );
    
  TAO_ServerRequestInterceptor_Adapter _tao_vfr (
      _tao_server_request.orb_core ()->server_request_interceptors (),
      _tao_server_request.interceptor_count ()
    );
  
  TAO_ServerRequestInfo_ImplementationRepository_ServerObject_shutdown _tao_ri (
      _tao_server_request,
      _tao_upcall,
      _tao_impl
      ACE_ENV_ARG_PARAMETER
    );
  
  ACE_TRY
    {
      {
        TAO::PICurrent_Guard _tao_pi_guard (_tao_ri.server_request (),
                                            true  /* Copy TSC to RSC */);
        
        _tao_vfr.receive_request (&_tao_ri ACE_ENV_ARG_PARAMETER);
        ACE_TRY_CHECK;
        
        if (!_tao_vfr.location_forwarded ())
          {
#endif /* TAO_HAS_INTERCEPTORS */
            
              _tao_impl->shutdown (
                  ACE_ENV_SINGLE_ARG_PARAMETER
                );
            TAO_INTERCEPTOR_CHECK;
#if (TAO_HAS_INTERCEPTORS == 1)
          }
      }
      
      if (!_tao_vfr.location_forwarded ())
        {
          _tao_ri.reply_status (PortableInterceptor::SUCCESSFUL);
          _tao_vfr.send_reply (&_tao_ri ACE_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;
        }
    }
  ACE_CATCHANY
    {
      _tao_ri.exception (&ACE_ANY_EXCEPTION);
      _tao_vfr.send_exception (
          &_tao_ri
          ACE_ENV_ARG_PARAMETER
        );
      ACE_TRY_CHECK;
      
      PortableInterceptor::ReplyStatus _tao_status =
        _tao_ri.reply_status (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
      
      if (_tao_status == PortableInterceptor::SYSTEM_EXCEPTION
          || _tao_status == PortableInterceptor::USER_EXCEPTION)
        {
          ACE_RE_THROW;
        }
    }
  
# if defined (ACE_HAS_EXCEPTIONS) \
  && defined (ACE_HAS_BROKEN_UNEXPECTED_EXCEPTIONS)
  ACE_CATCHALL
    {
      CORBA::UNKNOWN ex;
      
      _tao_ri.exception (&ex);
      _tao_vfr.send_exception (
          &_tao_ri
          ACE_ENV_ARG_PARAMETER
        );
      ACE_TRY_CHECK;
      
      PortableInterceptor::ReplyStatus _tao_status =
        _tao_ri.reply_status (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
      
      if (_tao_status == PortableInterceptor::SYSTEM_EXCEPTION)
        ACE_TRY_THROW (ex);
    }
# endif  /* ACE_HAS_EXCEPTIONS && ACE_HAS_BROKEN_UNEXPECTED_EXCEPTIONS */
  ACE_ENDTRY;
  ACE_CHECK;
#endif /* TAO_HAS_INTERCEPTORS */
  
  _tao_server_request.init_reply ();
  
  // In case _tao_servant_upcall is not used in this function
  ACE_UNUSED_ARG (_tao_servant_upcall);
}

// TAO_IDL - Generated from 
// be\be_visitor_interface/interface_ss.cpp:162

void POA_ImplementationRepository::ServerObject::_is_a_skel (
    TAO_ServerRequest &_tao_server_request, 
    void * _tao_servant,
    void * /* Servant_Upcall */
    ACE_ENV_ARG_DECL
  )
{
  TAO_InputCDR &_tao_in = _tao_server_request.incoming ();
  
  POA_ImplementationRepository::ServerObject *_tao_impl =
    (POA_ImplementationRepository::ServerObject *) _tao_servant;
  
  CORBA::Boolean _tao_retval = 0;
  CORBA::String_var value;
  
  if (!(_tao_in >> value.out ()))
    {
      ACE_THROW (CORBA::MARSHAL ());
    }
  
  _tao_retval = _tao_impl->_is_a (value.in () ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
  
  _tao_server_request.init_reply ();
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  
  if (!(_tao_out << CORBA::Any::from_boolean (_tao_retval)))
    {
      ACE_THROW (CORBA::MARSHAL ());
    }
}

void POA_ImplementationRepository::ServerObject::_non_existent_skel (
    TAO_ServerRequest &_tao_server_request, 
    void * _tao_servant,
    void * /* Servant_Upcall */
    ACE_ENV_ARG_DECL
  )
{
  POA_ImplementationRepository::ServerObject *_tao_impl =
    (POA_ImplementationRepository::ServerObject *) _tao_servant;
  
  CORBA::Boolean _tao_retval =
    _tao_impl->_non_existent (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;
  
  _tao_server_request.init_reply ();
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  
  if (!(_tao_out << CORBA::Any::from_boolean (_tao_retval)))
    {
      ACE_THROW (CORBA::MARSHAL ());
    }
}

void POA_ImplementationRepository::ServerObject::_interface_skel (
    TAO_ServerRequest &_tao_server_request, 
    void * _tao_servant,
    void * /* Servant_Upcall */
    ACE_ENV_ARG_DECL
  )
{
  TAO_IFR_Client_Adapter *_tao_adapter =
    ACE_Dynamic_Service<TAO_IFR_Client_Adapter>::instance (
        TAO_ORB_Core::ifr_client_adapter_name ()
      );
    
  if (_tao_adapter == 0)
    {
      ACE_THROW (CORBA::INTF_REPOS ());
    }
  
  POA_ImplementationRepository::ServerObject *_tao_impl =
    (POA_ImplementationRepository::ServerObject *) _tao_servant;
  
  CORBA::InterfaceDef_ptr _tao_retval = 
    _tao_impl->_get_interface (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;
  
  _tao_server_request.init_reply ();
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  
  CORBA::Boolean _tao_result =
    _tao_adapter->interfacedef_cdr_insert (
        _tao_out,
        _tao_retval
      );
  
  _tao_adapter->dispose (_tao_retval);
  
  if (_tao_result == 0)
    {
      ACE_THROW (CORBA::MARSHAL ());
    }
}

void POA_ImplementationRepository::ServerObject::_component_skel (
    TAO_ServerRequest &_tao_server_request, 
    void * _tao_object_reference,
    void * /* Servant_Upcall */
    ACE_ENV_ARG_DECL
  )
{
  POA_ImplementationRepository::ServerObject *_tao_impl =
    (POA_ImplementationRepository::ServerObject *) _tao_object_reference;
  
  CORBA::Object_var _tao_retval =
    _tao_impl->_get_component (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;
  
  _tao_server_request.init_reply ();
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  
  if (!(_tao_out << _tao_retval.in ()))
    {
      ACE_THROW (CORBA::MARSHAL ());
    }
}

CORBA::Boolean POA_ImplementationRepository::ServerObject::_is_a (
    const char* value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:ImplementationRepository/ServerObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
     )
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

void* POA_ImplementationRepository::ServerObject::_downcast (
    const char* logical_type_id
  )
{
  if (ACE_OS::strcmp (logical_type_id,
                      "IDL:ImplementationRepository/ServerObject:1.0") == 0)
    {
      return static_cast<POA_ImplementationRepository::ServerObject_ptr> (this);
    }
  
  if (ACE_OS::strcmp (logical_type_id,
                      "IDL:omg.org/CORBA/Object:1.0") == 0)
    {
      return static_cast<PortableServer::Servant> (this);
    }
  
  return 0;
}

const char* POA_ImplementationRepository::ServerObject::_interface_repository_id (void) const
{
  return "IDL:ImplementationRepository/ServerObject:1.0";
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_ss.cpp:588

void POA_ImplementationRepository::ServerObject::_dispatch (
    TAO_ServerRequest &req,
    void *servant_upcall
    ACE_ENV_ARG_DECL
  )
{
  this->synchronous_upcall_dispatch (req,
                                     servant_upcall,
                                     this
                                     ACE_ENV_ARG_PARAMETER);
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_ss.cpp:530

ImplementationRepository::ServerObject *
POA_ImplementationRepository::ServerObject::_this (ACE_ENV_SINGLE_ARG_DECL)
{
  TAO_Stub *stub = this->_create_stub (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);
  
  TAO_Stub_Auto_Ptr safe_stub (stub);
  CORBA::Object_ptr tmp = CORBA::Object::_nil ();
  
  if (stub->servant_orb_var ()->orb_core ()->optimize_collocation_objects ())
    {
      ACE_NEW_RETURN (
          tmp,
          CORBA::Object (stub, 1, this),
          0
        );
    }
  else
    {
      ACE_NEW_RETURN (
          tmp,
          CORBA::Object (stub, 0, this),
          0
        );
    }
  
  CORBA::Object_var obj = tmp;
  (void) safe_stub.release ();
  
  typedef ::ImplementationRepository::ServerObject STUB_SCOPED_NAME;
  return
    TAO::Narrow_Utils<STUB_SCOPED_NAME>::unchecked_narrow (
        obj.in (),
        ImplementationRepository__TAO_ServerObject_Proxy_Broker_Factory_function_pointer
      );
}

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1683

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

#endif /* ifndef */


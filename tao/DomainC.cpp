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
// be\be_codegen.cpp:291


#include "DomainC.h"
#include "tao/CDR.h"
#include "tao/Exception_Data.h"
#include "tao/Invocation_Adapter.h"
#include "tao/Object_T.h"
#include "tao/Basic_Arguments.h"
#include "tao/Object_Argument_T.h"
#include "tao/Special_Basic_Arguments.h"
#include "ace/OS_NS_string.h"

#include "tao/ORB_Core.h"
#include "tao/IFR_Client_Adapter.h"
#include "ace/Dynamic_Service.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "DomainC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:70

// TAO specific stuff.
namespace CORBA
{
  class InterfaceDef;
  typedef InterfaceDef *InterfaceDef_ptr;
  typedef TAO_Objref_Var_T<InterfaceDef> InterfaceDef_var;
  typedef TAO_Objref_Out_T<InterfaceDef> InterfaceDef_out;
}

namespace TAO
{

#if TAO_HAS_INTERCEPTORS == 1

  template<>
  void
  In_Object_Argument_T<CORBA::InterfaceDef_ptr>::interceptor_param (Dynamic::Parameter & p)
  {
    TAO_IFR_Client_Adapter *adapter =
      ACE_Dynamic_Service<TAO_IFR_Client_Adapter>::instance (
          TAO_ORB_Core::ifr_client_adapter_name ()
        );

    adapter->interfacedef_any_insert (p.argument, this->x_);
    p.mode = CORBA::PARAM_IN;
  }

#endif /* TAO_HAS_INTERCEPTORS */

  template<>
  CORBA::Boolean
  In_Object_Argument_T<CORBA::InterfaceDef_ptr>::marshal (TAO_OutputCDR & cdr)
  {
    TAO_IFR_Client_Adapter *adapter =
      ACE_Dynamic_Service<TAO_IFR_Client_Adapter>::instance (
          TAO_ORB_Core::ifr_client_adapter_name ()
        );

    return adapter->interfacedef_cdr_insert (cdr, this->x_);
  }
}

// Arg traits specializations.
namespace TAO
{

#if !defined (_CORBA_POLICY__ARG_TRAITS_CS_)
#define _CORBA_POLICY__ARG_TRAITS_CS_
  
  template<>
  class  Arg_Traits<CORBA::Policy>
    : public
        Object_Arg_Traits_T<
            CORBA::Policy_ptr,
            CORBA::Policy_var,
            CORBA::Policy_out,
            TAO::Objref_Traits<CORBA::Policy>
          >
  {
  };

#endif /* end #if !defined */

#if !defined (_CORBA_INTERFACEDEF__ARG_TRAITS_CS_)
#define _CORBA_INTERFACEDEF__ARG_TRAITS_CS_
  
  template<>
  class  Arg_Traits<CORBA::InterfaceDef>
    : public
        Object_Arg_Traits_T<
            CORBA::InterfaceDef_ptr,
            CORBA::InterfaceDef_var,
            CORBA::InterfaceDef_out,
            TAO::Objref_Traits<CORBA::InterfaceDef>
          >
  {
  };

#endif /* end #if !defined */
}


// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for CORBA::DomainManager.

CORBA::DomainManager_ptr
TAO::Objref_Traits<CORBA::DomainManager>::duplicate (
    CORBA::DomainManager_ptr p
  )
{
  return CORBA::DomainManager::_duplicate (p);
}

void
TAO::Objref_Traits<CORBA::DomainManager>::release (
    CORBA::DomainManager_ptr p
  )
{
  CORBA::release (p);
}

CORBA::DomainManager_ptr
TAO::Objref_Traits<CORBA::DomainManager>::nil (void)
{
  return CORBA::DomainManager::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<CORBA::DomainManager>::marshal (
    CORBA::DomainManager_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*CORBA__TAO_DomainManager_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

// TAO_IDL - Generated from
// be\be_visitor_operation/operation_cs.cpp:78

::CORBA::Policy_ptr CORBA::DomainManager::get_domain_policy (
    ::CORBA::PolicyType policy_type
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  if (!this->is_evaluated ())
    {
      ACE_NESTED_CLASS (CORBA, Object)::tao_object_initialize (this);
    }
  
  if (this->the_TAO_DomainManager_Proxy_Broker_ == 0)
    {
      CORBA_DomainManager_setup_collocation ();
    }
  
  TAO::Arg_Traits< ::CORBA::Policy>::ret_val _tao_retval;
  TAO::Arg_Traits< ::CORBA::PolicyType>::in_arg_val _tao_policy_type (policy_type);
  
  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval,
      &_tao_policy_type
    };
  
  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      2,
      "get_domain_policy",
      17,
      this->the_TAO_DomainManager_Proxy_Broker_
    );
  
  _tao_call.invoke (0, 0 ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (_tao_retval.excp ());
  
  return _tao_retval.retn ();
}

CORBA::DomainManager::DomainManager (void)
 : the_TAO_DomainManager_Proxy_Broker_ (0)
{
  this->CORBA_DomainManager_setup_collocation ();
}

void
CORBA::DomainManager::CORBA_DomainManager_setup_collocation ()
{
  if (::CORBA__TAO_DomainManager_Proxy_Broker_Factory_function_pointer)
    {
      this->the_TAO_DomainManager_Proxy_Broker_ =
        ::CORBA__TAO_DomainManager_Proxy_Broker_Factory_function_pointer (this);
    }
}

CORBA::DomainManager::~DomainManager (void)
{}

void 
CORBA::DomainManager::_tao_any_destructor (void *_tao_void_pointer)
{
  DomainManager *_tao_tmp_pointer =
    static_cast<DomainManager *> (_tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

CORBA::DomainManager_ptr
CORBA::DomainManager::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL
  )
{
  return
    TAO::Narrow_Utils<DomainManager>::narrow (
        _tao_objref,
        "IDL:omg.org/CORBA/DomainManager:1.0",
        CORBA__TAO_DomainManager_Proxy_Broker_Factory_function_pointer
        ACE_ENV_ARG_PARAMETER
      );
}

CORBA::DomainManager_ptr
CORBA::DomainManager::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL
  )
{
  return
    TAO::Narrow_Utils<DomainManager>::unchecked_narrow (
        _tao_objref,
        "IDL:omg.org/CORBA/DomainManager:1.0",
        CORBA__TAO_DomainManager_Proxy_Broker_Factory_function_pointer
        ACE_ENV_ARG_PARAMETER
      );
}

CORBA::DomainManager_ptr
CORBA::DomainManager::_duplicate (DomainManager_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
CORBA::DomainManager::_tao_release (DomainManager_ptr obj)
{
  CORBA::release (obj);
}

CORBA::Boolean
CORBA::DomainManager::_is_a (
    const char *value
    ACE_ENV_ARG_DECL
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/DomainManager:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
    )
    {
      return true; // success using local knowledge
    }
  else
    {
      return this->ACE_NESTED_CLASS (CORBA, Object)::_is_a (
          value
          ACE_ENV_ARG_PARAMETER
        );
    }
}

const char* CORBA::DomainManager::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/DomainManager:1.0";
}

CORBA::Boolean
CORBA::DomainManager::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for CORBA::ConstructionPolicy.

CORBA::ConstructionPolicy_ptr
TAO::Objref_Traits<CORBA::ConstructionPolicy>::duplicate (
    CORBA::ConstructionPolicy_ptr p
  )
{
  return CORBA::ConstructionPolicy::_duplicate (p);
}

void
TAO::Objref_Traits<CORBA::ConstructionPolicy>::release (
    CORBA::ConstructionPolicy_ptr p
  )
{
  CORBA::release (p);
}

CORBA::ConstructionPolicy_ptr
TAO::Objref_Traits<CORBA::ConstructionPolicy>::nil (void)
{
  return CORBA::ConstructionPolicy::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<CORBA::ConstructionPolicy>::marshal (
    CORBA::ConstructionPolicy_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*CORBA__TAO_ConstructionPolicy_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

// TAO_IDL - Generated from
// be\be_visitor_operation/operation_cs.cpp:78

void CORBA::ConstructionPolicy::make_domain_manager (
    ::CORBA::InterfaceDef_ptr object_type,
    ::CORBA::Boolean constr_policy
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  if (!this->is_evaluated ())
    {
      ACE_NESTED_CLASS (CORBA, Object)::tao_object_initialize (this);
    }
  
  if (this->the_TAO_ConstructionPolicy_Proxy_Broker_ == 0)
    {
      CORBA_ConstructionPolicy_setup_collocation ();
    }
  
  TAO::Arg_Traits< void>::ret_val _tao_retval;
  TAO::Arg_Traits< ::CORBA::InterfaceDef>::in_arg_val _tao_object_type (object_type);
  TAO::Arg_Traits< ::ACE_InputCDR::to_boolean>::in_arg_val _tao_constr_policy (constr_policy);
  
  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval,
      &_tao_object_type,
      &_tao_constr_policy
    };
  
  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      3,
      "make_domain_manager",
      19,
      this->the_TAO_ConstructionPolicy_Proxy_Broker_
    );
  
  _tao_call.invoke (0, 0 ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

CORBA::ConstructionPolicy::ConstructionPolicy (void)
 : the_TAO_ConstructionPolicy_Proxy_Broker_ (0)
{
  this->CORBA_ConstructionPolicy_setup_collocation ();
}

void
CORBA::ConstructionPolicy::CORBA_ConstructionPolicy_setup_collocation ()
{
  if (::CORBA__TAO_ConstructionPolicy_Proxy_Broker_Factory_function_pointer)
    {
      this->the_TAO_ConstructionPolicy_Proxy_Broker_ =
        ::CORBA__TAO_ConstructionPolicy_Proxy_Broker_Factory_function_pointer (this);
    }
  
  this->CORBA_Policy_setup_collocation ();
}

CORBA::ConstructionPolicy::~ConstructionPolicy (void)
{}

void 
CORBA::ConstructionPolicy::_tao_any_destructor (void *_tao_void_pointer)
{
  ConstructionPolicy *_tao_tmp_pointer =
    static_cast<ConstructionPolicy *> (_tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

CORBA::ConstructionPolicy_ptr
CORBA::ConstructionPolicy::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL
  )
{
  return
    TAO::Narrow_Utils<ConstructionPolicy>::narrow (
        _tao_objref,
        "IDL:omg.org/CORBA/ConstructionPolicy:1.0",
        CORBA__TAO_ConstructionPolicy_Proxy_Broker_Factory_function_pointer
        ACE_ENV_ARG_PARAMETER
      );
}

CORBA::ConstructionPolicy_ptr
CORBA::ConstructionPolicy::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL
  )
{
  return
    TAO::Narrow_Utils<ConstructionPolicy>::unchecked_narrow (
        _tao_objref,
        "IDL:omg.org/CORBA/ConstructionPolicy:1.0",
        CORBA__TAO_ConstructionPolicy_Proxy_Broker_Factory_function_pointer
        ACE_ENV_ARG_PARAMETER
      );
}

CORBA::ConstructionPolicy_ptr
CORBA::ConstructionPolicy::_duplicate (ConstructionPolicy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
CORBA::ConstructionPolicy::_tao_release (ConstructionPolicy_ptr obj)
{
  CORBA::release (obj);
}

CORBA::Boolean
CORBA::ConstructionPolicy::_is_a (
    const char *value
    ACE_ENV_ARG_DECL
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Policy:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/ConstructionPolicy:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
    )
    {
      return true; // success using local knowledge
    }
  else
    {
      return this->ACE_NESTED_CLASS (CORBA, Object)::_is_a (
          value
          ACE_ENV_ARG_PARAMETER
        );
    }
}

const char* CORBA::ConstructionPolicy::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/ConstructionPolicy:1.0";
}

CORBA::Boolean
CORBA::ConstructionPolicy::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

// TAO_IDL - Generated from 
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_CORBA_DOMAINMANAGERLIST_CS_)
#define _CORBA_DOMAINMANAGERLIST_CS_

CORBA::DomainManagerList::DomainManagerList (void)
{}

CORBA::DomainManagerList::DomainManagerList (
    CORBA::ULong max
  )
  : TAO_Unbounded_Object_Sequence<
        CORBA::DomainManager,
        CORBA::DomainManager_var
      >
    (max)
{}

CORBA::DomainManagerList::DomainManagerList (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA::DomainManager_ptr * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Object_Sequence<
        CORBA::DomainManager,
        CORBA::DomainManager_var
      >
    (max, length, buffer, release)
{}

CORBA::DomainManagerList::DomainManagerList (
    const DomainManagerList &seq
  )
  : TAO_Unbounded_Object_Sequence<
        CORBA::DomainManager,
        CORBA::DomainManager_var
      >
    (seq)
{}

CORBA::DomainManagerList::~DomainManagerList (void)
{}

void CORBA::DomainManagerList::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  DomainManagerList * _tao_tmp_pointer =
    static_cast<DomainManagerList *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_interface/cdr_op_cs.cpp:63

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::DomainManager_ptr _tao_objref
  )
{
  CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::DomainManager_ptr &_tao_objref
  )
{
  CORBA::Object_var obj;
  
  if (!(strm >> obj.inout ()))
    {
      return false;
    }
  
  typedef ::CORBA::DomainManager RHS_SCOPED_NAME;
  
  // Narrow to the right type.
  _tao_objref =
    TAO::Narrow_Utils<RHS_SCOPED_NAME>::unchecked_narrow (
        obj.in (),
        CORBA__TAO_DomainManager_Proxy_Broker_Factory_function_pointer
      );
    
  return 1;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/cdr_op_cs.cpp:63

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::ConstructionPolicy_ptr _tao_objref
  )
{
  CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::ConstructionPolicy_ptr &_tao_objref
  )
{
  CORBA::Object_var obj;
  
  if (!(strm >> obj.inout ()))
    {
      return false;
    }
  
  typedef ::CORBA::ConstructionPolicy RHS_SCOPED_NAME;
  
  // Narrow to the right type.
  _tao_objref =
    TAO::Narrow_Utils<RHS_SCOPED_NAME>::unchecked_narrow (
        obj.in (),
        CORBA__TAO_ConstructionPolicy_Proxy_Broker_Factory_function_pointer
      );
    
  return 1;
}

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_CORBA_DomainManagerList_CPP_
#define _TAO_CDR_OP_CORBA_DomainManagerList_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::DomainManagerList &_tao_sequence
  )
{
  const CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      CORBA::Boolean _tao_marshal_flag = true;
      
      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag =
            TAO::Objref_Traits<CORBA::DomainManager>::marshal (
                _tao_sequence[i].in (), strm
              );
        }
      
      return _tao_marshal_flag;
    }
  
  return false;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::DomainManagerList &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len;
  
  if (strm >> _tao_seq_len)
    {
      // Add a check to the length of the sequence
      // to make sure it does not exceed the length
      // of the stream. (See bug 58.)
      if (_tao_seq_len > strm.length ())
        {
          return false;
        }
      
      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);
      
      // If length is 0 we return true.
      if (0 >= _tao_seq_len) 
        {
          return true;
        }
      
      // Retrieve all the elements.
      CORBA::Boolean _tao_marshal_flag = true;
      
      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm >> _tao_sequence[i].out ());
        }
      
      return _tao_marshal_flag;
    
    }
  
  return false;
}

#endif /* _TAO_CDR_OP_CORBA_DomainManagerList_CPP_ */

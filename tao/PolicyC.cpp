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
// be\be_codegen.cpp:323


#include "PolicyC.h"
#include "tao/CDR.h"
#include "tao/Exception_Data.h"
#include "tao/Invocation_Adapter.h"
#include "tao/Object_T.h"
#include "tao/Typecode.h"
#include "tao/Basic_Arguments.h"
#include "tao/Object_Argument_T.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "PolicyC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:64

// Arg traits specializations.
namespace TAO
{

#if !defined (_CORBA_POLICY__ARG_TRAITS_CS_)
#define _CORBA_POLICY__ARG_TRAITS_CS_
  
  ACE_TEMPLATE_SPECIALIZATION
  class TAO_Export Arg_Traits<CORBA::Policy>
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
}


// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

CORBA::PolicyError::PolicyError (void)
  : CORBA::UserException (
        "IDL:omg.org/CORBA/PolicyError:1.0",
        "PolicyError"
      )
{
}

CORBA::PolicyError::~PolicyError (void)
{
}

CORBA::PolicyError::PolicyError (const ::CORBA::PolicyError &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
  this->reason = _tao_excp.reason;
}

CORBA::PolicyError&
CORBA::PolicyError::operator= (const ::CORBA::PolicyError &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  this->reason = _tao_excp.reason;
  return *this;
}

void CORBA::PolicyError::_tao_any_destructor (void *_tao_void_pointer)
{
  PolicyError *_tao_tmp_pointer =
    ACE_static_cast (PolicyError*, _tao_void_pointer);
  delete _tao_tmp_pointer;
}

CORBA::PolicyError *
CORBA::PolicyError::_downcast (CORBA::Exception *_tao_excp)
{
  if (!ACE_OS::strcmp ("IDL:omg.org/CORBA/PolicyError:1.0", _tao_excp->_rep_id ()))
    {
      return ACE_dynamic_cast (PolicyError *, _tao_excp);
    }
  else
    {
      return 0;
    }
}

CORBA::Exception *CORBA::PolicyError::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::CORBA::PolicyError, 0);
  return retval;
}

CORBA::Exception *
CORBA::PolicyError::_tao_duplicate (void) const
{
  CORBA::Exception *result;
  ACE_NEW_RETURN (
      result,
      ::CORBA::PolicyError (*this),
      0
    );
  return result;
}

void CORBA::PolicyError::_raise (void) const
{
  TAO_RAISE (*this);
}

void CORBA::PolicyError::_tao_encode (
    TAO_OutputCDR &cdr
    ACE_ENV_ARG_DECL
  ) const
{
  if (cdr << *this)
    {
      return;
    }
  
  ACE_THROW (CORBA::MARSHAL ());
}

void CORBA::PolicyError::_tao_decode (
    TAO_InputCDR &cdr
    ACE_ENV_ARG_DECL
  )
{
  if (cdr >> *this)
    {
      return;
    }
  
  ACE_THROW (CORBA::MARSHAL ());
}



// TAO_IDL - Generated from
// be\be_visitor_exception/exception_ctor.cpp:66

CORBA::PolicyError::PolicyError (
    CORBA::PolicyErrorCode _tao_reason
  )
  : CORBA::UserException (
        "IDL:omg.org/CORBA/PolicyError:1.0",
        "PolicyError"
      )
{
  this->reason = _tao_reason;
}

// TAO extension - the virtual _type method.
CORBA::TypeCode_ptr CORBA::PolicyError::_type (void) const
{
  ACE_DEBUG ((LM_DEBUG,
              ACE_LIB_TEXT ("This TAO-specific method is now")
              ACE_LIB_TEXT (" deprecated and will be removed")
              ACE_LIB_TEXT (" in future versions.\n")));
  
  return ::CORBA::_tc_PolicyError;
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

CORBA::InvalidPolicies::InvalidPolicies (void)
  : CORBA::UserException (
        "IDL:omg.org/CORBA/InvalidPolicies:1.0",
        "InvalidPolicies"
      )
{
}

CORBA::InvalidPolicies::~InvalidPolicies (void)
{
}

CORBA::InvalidPolicies::InvalidPolicies (const ::CORBA::InvalidPolicies &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
  this->indices = _tao_excp.indices;
}

CORBA::InvalidPolicies&
CORBA::InvalidPolicies::operator= (const ::CORBA::InvalidPolicies &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  this->indices = _tao_excp.indices;
  return *this;
}

void CORBA::InvalidPolicies::_tao_any_destructor (void *_tao_void_pointer)
{
  InvalidPolicies *_tao_tmp_pointer =
    ACE_static_cast (InvalidPolicies*, _tao_void_pointer);
  delete _tao_tmp_pointer;
}

CORBA::InvalidPolicies *
CORBA::InvalidPolicies::_downcast (CORBA::Exception *_tao_excp)
{
  if (!ACE_OS::strcmp ("IDL:omg.org/CORBA/InvalidPolicies:1.0", _tao_excp->_rep_id ()))
    {
      return ACE_dynamic_cast (InvalidPolicies *, _tao_excp);
    }
  else
    {
      return 0;
    }
}

CORBA::Exception *CORBA::InvalidPolicies::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::CORBA::InvalidPolicies, 0);
  return retval;
}

CORBA::Exception *
CORBA::InvalidPolicies::_tao_duplicate (void) const
{
  CORBA::Exception *result;
  ACE_NEW_RETURN (
      result,
      ::CORBA::InvalidPolicies (*this),
      0
    );
  return result;
}

void CORBA::InvalidPolicies::_raise (void) const
{
  TAO_RAISE (*this);
}

void CORBA::InvalidPolicies::_tao_encode (
    TAO_OutputCDR &cdr
    ACE_ENV_ARG_DECL
  ) const
{
  if (cdr << *this)
    {
      return;
    }
  
  ACE_THROW (CORBA::MARSHAL ());
}

void CORBA::InvalidPolicies::_tao_decode (
    TAO_InputCDR &cdr
    ACE_ENV_ARG_DECL
  )
{
  if (cdr >> *this)
    {
      return;
    }
  
  ACE_THROW (CORBA::MARSHAL ());
}



// TAO_IDL - Generated from
// be\be_visitor_exception/exception_ctor.cpp:66

CORBA::InvalidPolicies::InvalidPolicies (
    const CORBA::UShortSeq & _tao_indices
  )
  : CORBA::UserException (
        "IDL:omg.org/CORBA/InvalidPolicies:1.0",
        "InvalidPolicies"
      )
{
  this->indices = _tao_indices;
}

// TAO extension - the virtual _type method.
CORBA::TypeCode_ptr CORBA::InvalidPolicies::_type (void) const
{
  ACE_DEBUG ((LM_DEBUG,
              ACE_LIB_TEXT ("This TAO-specific method is now")
              ACE_LIB_TEXT (" deprecated and will be removed")
              ACE_LIB_TEXT (" in future versions.\n")));
  
  return ::CORBA::_tc_InvalidPolicies;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for CORBA::Policy.

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::Policy_ptr
TAO::Objref_Traits<CORBA::Policy>::tao_duplicate (
    CORBA::Policy_ptr p
  )
{
  return CORBA::Policy::_duplicate (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Objref_Traits<CORBA::Policy>::tao_release (
    CORBA::Policy_ptr p
  )
{
  CORBA::release (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::Policy_ptr
TAO::Objref_Traits<CORBA::Policy>::tao_nil (void)
{
  return CORBA::Policy::_nil ();
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::Boolean
TAO::Objref_Traits<CORBA::Policy>::tao_marshal (
    CORBA::Policy_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return p->marshal (cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*CORBA__TAO_Policy_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

// TAO_IDL - Generated from
// be\be_visitor_operation/operation_cs.cpp:78

CORBA::PolicyType CORBA::Policy::policy_type (
    ACE_ENV_SINGLE_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  if (!this->is_evaluated ())
    {
      ACE_NESTED_CLASS (CORBA, Object)::tao_object_initialize (this);
    }
  
  if (this->the_TAO_Policy_Proxy_Broker_ == 0)
    {
      CORBA_Policy_setup_collocation (
          this->ACE_NESTED_CLASS (CORBA, Object)::_is_collocated ()
        );
    }
  
  TAO::Arg_Traits<CORBA::PolicyType>::ret_val _tao_retval;
  
  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval
    };
  
  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      1,
      "_get_policy_type",
      16,
      this->the_TAO_Policy_Proxy_Broker_
    );
  
  _tao_call.invoke (0, 0 ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (_tao_retval.excp ());
  
  return _tao_retval.retn ();
}

// TAO_IDL - Generated from
// be\be_visitor_operation/operation_cs.cpp:78

::CORBA::Policy_ptr CORBA::Policy::copy (
    ACE_ENV_SINGLE_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  if (!this->is_evaluated ())
    {
      ACE_NESTED_CLASS (CORBA, Object)::tao_object_initialize (this);
    }
  
  if (this->the_TAO_Policy_Proxy_Broker_ == 0)
    {
      CORBA_Policy_setup_collocation (
          this->ACE_NESTED_CLASS (CORBA, Object)::_is_collocated ()
        );
    }
  
  TAO::Arg_Traits<CORBA::Policy>::ret_val _tao_retval;
  
  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval
    };
  
  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      1,
      "copy",
      4,
      this->the_TAO_Policy_Proxy_Broker_
    );
  
  _tao_call.invoke (0, 0 ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (_tao_retval.excp ());
  
  return _tao_retval.retn ();
}

// TAO_IDL - Generated from
// be\be_visitor_operation/operation_cs.cpp:78

void CORBA::Policy::destroy (
    ACE_ENV_SINGLE_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  if (!this->is_evaluated ())
    {
      ACE_NESTED_CLASS (CORBA, Object)::tao_object_initialize (this);
    }
  
  if (this->the_TAO_Policy_Proxy_Broker_ == 0)
    {
      CORBA_Policy_setup_collocation (
          this->ACE_NESTED_CLASS (CORBA, Object)::_is_collocated ()
        );
    }
  
  TAO::Arg_Traits<void>::ret_val _tao_retval;
  
  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval
    };
  
  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      1,
      "destroy",
      7,
      this->the_TAO_Policy_Proxy_Broker_
    );
  
  _tao_call.invoke (0, 0 ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

CORBA::Policy::Policy (int collocated)
 : the_TAO_Policy_Proxy_Broker_ (0)
{
  this->CORBA_Policy_setup_collocation (collocated);
}

void
CORBA::Policy::CORBA_Policy_setup_collocation (int collocated)
{
  if (collocated)
    {
      this->the_TAO_Policy_Proxy_Broker_ =
        ::CORBA__TAO_Policy_Proxy_Broker_Factory_function_pointer (this);
    }
}

CORBA::Policy::~Policy (void)
{}

void 
CORBA::Policy::_tao_any_destructor (void *_tao_void_pointer)
{
  Policy *_tao_tmp_pointer =
    ACE_static_cast (Policy *, _tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

CORBA::Policy_ptr
CORBA::Policy::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL
  )
{
  return
    TAO::Narrow_Utils<Policy>::narrow (
        _tao_objref,
        "IDL:omg.org/CORBA/Policy:1.0",
        CORBA__TAO_Policy_Proxy_Broker_Factory_function_pointer
        ACE_ENV_ARG_PARAMETER
      );
}

CORBA::Policy_ptr
CORBA::Policy::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL
  )
{
  return
    TAO::Narrow_Utils<Policy>::unchecked_narrow (
        _tao_objref,
        "IDL:omg.org/CORBA/Policy:1.0",
        CORBA__TAO_Policy_Proxy_Broker_Factory_function_pointer
        ACE_ENV_ARG_PARAMETER
      );
}

CORBA::Policy_ptr
CORBA::Policy::_duplicate (Policy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

CORBA::Boolean
CORBA::Policy::_is_a (
    const char *value
    ACE_ENV_ARG_DECL
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Policy:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
     )
    {
      return 1; // success using local knowledge
    }
  else
    {
      return this->ACE_NESTED_CLASS (CORBA, Object)::_is_a (
          value
          ACE_ENV_ARG_PARAMETER
        );
    }
}

const char* CORBA::Policy::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/Policy:1.0";
}

CORBA::Boolean
CORBA::Policy::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for CORBA::PolicyManager.

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::PolicyManager_ptr
TAO::Objref_Traits<CORBA::PolicyManager>::tao_duplicate (
    CORBA::PolicyManager_ptr p
  )
{
  return CORBA::PolicyManager::_duplicate (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Objref_Traits<CORBA::PolicyManager>::tao_release (
    CORBA::PolicyManager_ptr p
  )
{
  CORBA::release (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::PolicyManager_ptr
TAO::Objref_Traits<CORBA::PolicyManager>::tao_nil (void)
{
  return CORBA::PolicyManager::_nil ();
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::Boolean
TAO::Objref_Traits<CORBA::PolicyManager>::tao_marshal (
    CORBA::PolicyManager_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return p->marshal (cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*CORBA__TAO_PolicyManager_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

CORBA::PolicyManager::PolicyManager (void)
{}

CORBA::PolicyManager::~PolicyManager (void)
{}

void 
CORBA::PolicyManager::_tao_any_destructor (void *_tao_void_pointer)
{
  PolicyManager *_tao_tmp_pointer =
    ACE_static_cast (PolicyManager *, _tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

CORBA::PolicyManager_ptr
CORBA::PolicyManager::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return PolicyManager::_nil ();
    }
  
  PolicyManager_ptr proxy =
    dynamic_cast<PolicyManager_ptr> (_tao_objref);
  
  return PolicyManager::_duplicate (proxy);
}

CORBA::PolicyManager_ptr
CORBA::PolicyManager::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return PolicyManager::_nil ();
    }
  
  PolicyManager_ptr proxy =
    dynamic_cast<PolicyManager_ptr> (_tao_objref);
  
  return PolicyManager::_duplicate (proxy);
}

CORBA::PolicyManager_ptr
CORBA::PolicyManager::_duplicate (PolicyManager_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

CORBA::Boolean
CORBA::PolicyManager::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/PolicyManager:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
     )
    {
      return 1; // success using local knowledge
    }
  else
    {
      return 0;
    }
}

const char* CORBA::PolicyManager::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/PolicyManager:1.0";
}

CORBA::Boolean
CORBA::PolicyManager::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for CORBA::PolicyCurrent.

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::PolicyCurrent_ptr
TAO::Objref_Traits<CORBA::PolicyCurrent>::tao_duplicate (
    CORBA::PolicyCurrent_ptr p
  )
{
  return CORBA::PolicyCurrent::_duplicate (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Objref_Traits<CORBA::PolicyCurrent>::tao_release (
    CORBA::PolicyCurrent_ptr p
  )
{
  CORBA::release (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::PolicyCurrent_ptr
TAO::Objref_Traits<CORBA::PolicyCurrent>::tao_nil (void)
{
  return CORBA::PolicyCurrent::_nil ();
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::Boolean
TAO::Objref_Traits<CORBA::PolicyCurrent>::tao_marshal (
    CORBA::PolicyCurrent_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return p->marshal (cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*CORBA__TAO_PolicyCurrent_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

CORBA::PolicyCurrent::PolicyCurrent (void)
{}

CORBA::PolicyCurrent::~PolicyCurrent (void)
{}

void 
CORBA::PolicyCurrent::_tao_any_destructor (void *_tao_void_pointer)
{
  PolicyCurrent *_tao_tmp_pointer =
    ACE_static_cast (PolicyCurrent *, _tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

CORBA::PolicyCurrent_ptr
CORBA::PolicyCurrent::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return PolicyCurrent::_nil ();
    }
  
  PolicyCurrent_ptr proxy =
    dynamic_cast<PolicyCurrent_ptr> (_tao_objref);
  
  return PolicyCurrent::_duplicate (proxy);
}

CORBA::PolicyCurrent_ptr
CORBA::PolicyCurrent::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return PolicyCurrent::_nil ();
    }
  
  PolicyCurrent_ptr proxy =
    dynamic_cast<PolicyCurrent_ptr> (_tao_objref);
  
  return PolicyCurrent::_duplicate (proxy);
}

CORBA::PolicyCurrent_ptr
CORBA::PolicyCurrent::_duplicate (PolicyCurrent_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

CORBA::Boolean
CORBA::PolicyCurrent::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/PolicyManager:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Current:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/PolicyCurrent:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
     )
    {
      return 1; // success using local knowledge
    }
  else
    {
      return 0;
    }
}

const char* CORBA::PolicyCurrent::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/PolicyCurrent:1.0";
}

CORBA::Boolean
CORBA::PolicyCurrent::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be\be_visitor_exception/cdr_op_cs.cpp:60

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::PolicyError &_tao_aggregate
  )
{
  // First marshal the repository ID.
  if (strm << _tao_aggregate._rep_id ())
    {
      // Now marshal the members (if any).
      if (
        (strm << _tao_aggregate.reason)
       )
        {
          return 1;
        }
      else
        {
          return 0;
        }
    }
  else
    {
      return 0;
    }
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::PolicyError &_tao_aggregate
  )
{
  // Demarshal the members.
  if (
    (strm >> _tao_aggregate.reason)
  )
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

// TAO_IDL - Generated from
// be\be_visitor_exception/cdr_op_cs.cpp:60

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::InvalidPolicies &_tao_aggregate
  )
{
  // First marshal the repository ID.
  if (strm << _tao_aggregate._rep_id ())
    {
      // Now marshal the members (if any).
      if (
        (strm << _tao_aggregate.indices)
       )
        {
          return 1;
        }
      else
        {
          return 0;
        }
    }
  else
    {
      return 0;
    }
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::InvalidPolicies &_tao_aggregate
  )
{
  // Demarshal the members.
  if (
    (strm >> _tao_aggregate.indices)
  )
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

// Hand crafted.
//
// ****************************************************************
CORBA::Boolean
CORBA::Policy::_tao_encode (TAO_OutputCDR &)
{
  return 0;
}

CORBA::Boolean
CORBA::Policy::_tao_decode (TAO_InputCDR &)
{
  return 0;
}

TAO_Cached_Policy_Type
CORBA::Policy::_tao_cached_type (void) const
{
  return TAO_CACHED_POLICY_UNCACHED;
}

TAO_Policy_Scope
CORBA::Policy::_tao_scope (void) const
{
  return TAO_POLICY_DEFAULT_SCOPE;
}
// ****************************************************************

// TAO_IDL - Generated from
// be\be_visitor_interface/cdr_op_cs.cpp:63

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::Policy_ptr _tao_objref
  )
{
  CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::Policy_ptr &_tao_objref
  )
{
  CORBA::Object_var obj;
  
  if ((strm >> obj.inout ()) == 0)
    {
      return 0;
    }
  
  typedef ::CORBA::Policy RHS_SCOPED_NAME;
  
  // Narrow to the right type.
  _tao_objref =
    TAO::Narrow_Utils<RHS_SCOPED_NAME>::unchecked_narrow (
        obj.in (),
        CORBA__TAO_Policy_Proxy_Broker_Factory_function_pointer
      );
    
  return 1;
}

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1628

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

#if !defined (_CORBA_POLICY__ARG_TRAITS_TMPLINST_CS_)
#define _CORBA_POLICY__ARG_TRAITS_TMPLINST_CS_

  template class
    TAO::Arg_Traits<
        CORBA::Policy
      >;

  template class
    TAO::Object_Arg_Traits_T<
        CORBA::Policy_ptr,
        CORBA::Policy_var,
        CORBA::Policy_out,
        TAO::Objref_Traits<CORBA::Policy>
      >;

#endif /* end #if !defined */

  template class
    TAO::Ret_Object_Argument_T<
        CORBA::Policy_ptr,
        CORBA::Policy_var
      >;

  template class
    TAO::Objref_Traits<
        CORBA::Policy
      >;

  template class
    TAO_Objref_Var_T<
        CORBA::Policy
      >;
  
  template class
    TAO_Objref_Out_T<
        CORBA::Policy
      >;

  template class
    TAO::Narrow_Utils<
        CORBA::Policy
      >;

  template class
    TAO::Objref_Traits<
        CORBA::PolicyManager
      >;

  template class
    TAO_Objref_Var_T<
        CORBA::PolicyManager
      >;
  
  template class
    TAO_Objref_Out_T<
        CORBA::PolicyManager
      >;

  template class
    TAO::Objref_Traits<
        CORBA::PolicyCurrent
      >;

  template class
    TAO_Objref_Var_T<
        CORBA::PolicyCurrent
      >;
  
  template class
    TAO_Objref_Out_T<
        CORBA::PolicyCurrent
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#if !defined (_CORBA_POLICY__ARG_TRAITS_TMPLINST_CS_)
#define _CORBA_POLICY__ARG_TRAITS_TMPLINST_CS_

# pragma instantiate \
    TAO::Arg_Traits< \
        CORBA::Policy \
      >

# pragma instantiate \
    TAO::Object_Arg_Traits_T< \
        CORBA::Policy_ptr, \
        CORBA::Policy_var, \
        CORBA::Policy_out, \
        TAO::Objref_Traits<CORBA::Policy> \
      >

#endif /* end #if !defined */

# pragma instantiate \
    TAO::Objref_Traits< \
        CORBA::Policy \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        CORBA::Policy
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        CORBA::Policy
      >

# pragma instantiate \
    TAO::Narrow_Utils< \
        CORBA::Policy \
      >

# pragma instantiate \
    TAO::Objref_Traits< \
        CORBA::PolicyManager \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        CORBA::PolicyManager
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        CORBA::PolicyManager
      >

# pragma instantiate \
    TAO::Objref_Traits< \
        CORBA::PolicyCurrent \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        CORBA::PolicyCurrent
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        CORBA::PolicyCurrent
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 


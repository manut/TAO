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
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:314


#include "Messaging.h"
#include "tao/Stub.h"
#include "tao/Invocation.h"
#include "tao/PortableInterceptor.h"

#if TAO_HAS_INTERCEPTORS == 1
#include "tao/RequestInfo_Util.h"
#include "tao/ClientRequestInfo_i.h"
#include "tao/ClientInterceptorAdapter.h"
#endif  /* TAO_HAS_INTERCEPTORS == 1 */



#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "MessagingC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_Messaging_ExceptionHolder[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  42,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x4d657373), 
  ACE_NTOHL (0x6167696e), 
  ACE_NTOHL (0x672f4578), 
  ACE_NTOHL (0x63657074), 
  ACE_NTOHL (0x696f6e48), 
  ACE_NTOHL (0x6f6c6465), 
  ACE_NTOHL (0x723a312e), 
  ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/Messaging/ExceptionHolder:1.0
    16,
  ACE_NTOHL (0x45786365), 
  ACE_NTOHL (0x7074696f), 
  ACE_NTOHL (0x6e486f6c), 
  ACE_NTOHL (0x64657200),  // name = ExceptionHolder
    0, // value modifier
  CORBA::tk_null, // no stateful base valuetype

3, // member count
    20,
  ACE_NTOHL (0x69735f73), 
  ACE_NTOHL (0x79737465), 
  ACE_NTOHL (0x6d5f6578), 
  ACE_NTOHL (0x63657074), 
  ACE_NTOHL (0x696f6e00),  // name = is_system_exception
    CORBA::tk_boolean,

  1, // data member visibility marker

  11,
  ACE_NTOHL (0x62797465), 
  ACE_NTOHL (0x5f6f7264), 
  ACE_NTOHL (0x65720000),  // name = byte_order
    CORBA::tk_boolean,

  1, // data member visibility marker

  20,
  ACE_NTOHL (0x6d617273), 
  ACE_NTOHL (0x68616c65), 
  ACE_NTOHL (0x645f6578), 
  ACE_NTOHL (0x63657074), 
  ACE_NTOHL (0x696f6e00),  // name = marshaled_exception
    CORBA::tk_alias, // typecode kind for typedefs
  76, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    31,
    ACE_NTOHL (0x49444c3a), 
    ACE_NTOHL (0x6f6d672e), 
    ACE_NTOHL (0x6f72672f), 
    ACE_NTOHL (0x434f5242), 
    ACE_NTOHL (0x412f4f63), 
    ACE_NTOHL (0x74657453), 
    ACE_NTOHL (0x65713a31), 
    ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/CORBA/OctetSeq:1.0
        9,
    ACE_NTOHL (0x4f637465), 
    ACE_NTOHL (0x74536571), 
    ACE_NTOHL (0x0),  // name = OctetSeq
        CORBA::tk_sequence, // typecode kind
    12, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      CORBA::tk_octet,

      0U,


  1, // data member visibility marker

};

static CORBA::TypeCode _tc_TAO_tc_Messaging_ExceptionHolder (
    CORBA::tk_value,
    sizeof (_oc_Messaging_ExceptionHolder),
    (char *) &_oc_Messaging_ExceptionHolder,
    0,
    sizeof (Messaging::ExceptionHolder)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (Messaging)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_ExceptionHolder,
    &_tc_TAO_tc_Messaging_ExceptionHolder
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/valuetype_cs.cpp:95

void
tao_Messaging_ExceptionHolder_add_ref (
    Messaging::ExceptionHolder *p
  )
{
  CORBA::add_ref (p);
}

void
tao_Messaging_ExceptionHolder_remove_ref (
    Messaging::ExceptionHolder *p
  )
{
  CORBA::remove_ref (p);
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_valuetype.cpp:298

// *************************************************************
// Operations for class Messaging::ExceptionHolder_var
// *************************************************************

Messaging::ExceptionHolder_var::ExceptionHolder_var (void)
  : ptr_ (0)
{}

Messaging::ExceptionHolder_var::ExceptionHolder_var (ExceptionHolder* p)
  : ptr_ (p)
{}

Messaging::ExceptionHolder_var::ExceptionHolder_var (const ExceptionHolder* p)
  : ptr_ (ACE_const_cast (ExceptionHolder *, p))
{}

Messaging::ExceptionHolder *
Messaging::ExceptionHolder_var::ptr (void) const
{
  return this->ptr_;
}

Messaging::ExceptionHolder_var::ExceptionHolder_var (const ExceptionHolder_var &p)
{
  CORBA::add_ref (p.ptr ());
  this->ptr_ = p.ptr ();
}

Messaging::ExceptionHolder_var::~ExceptionHolder_var (void) // destructor
{
  CORBA::remove_ref (this->ptr_);
}

Messaging::ExceptionHolder_var &
Messaging::ExceptionHolder_var::operator= (ExceptionHolder *p)
{
  CORBA::remove_ref (this->ptr_);
  this->ptr_ = p;
  return *this;
}

Messaging::ExceptionHolder_var &
Messaging::ExceptionHolder_var::operator= (const ExceptionHolder_var &p)
{
  if (this != &p)
  {
    CORBA::remove_ref (this->ptr_);
    ExceptionHolder *tmp = p.ptr ();
    CORBA::add_ref (tmp);
    this->ptr_ = tmp;
  }
  
  return *this;
}

Messaging::ExceptionHolder_var::operator const Messaging::ExceptionHolder* () const // cast
{
  return this->ptr_;
}

Messaging::ExceptionHolder_var::operator Messaging::ExceptionHolder*& () // cast 
{
  return this->ptr_;
}

Messaging::ExceptionHolder *
Messaging::ExceptionHolder_var::operator-> (void) const
{
  return this->ptr_;
}

Messaging::ExceptionHolder *
Messaging::ExceptionHolder_var::in (void) const
{
  return this->ptr_;
}

Messaging::ExceptionHolder *&
Messaging::ExceptionHolder_var::inout (void)
{
  return this->ptr_;
}

Messaging::ExceptionHolder *&
Messaging::ExceptionHolder_var::out (void)
{
  CORBA::remove_ref (this->ptr_);
  this->ptr_ = 0;
  return this->ptr_;
}

Messaging::ExceptionHolder *
Messaging::ExceptionHolder_var::_retn (void)
{
  // yield ownership of managed obj reference
  ExceptionHolder* tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

void
Messaging::ExceptionHolder_var::tao_add_ref (
    ExceptionHolder *p
  )
{
  CORBA::add_ref (p);
}

void
Messaging::ExceptionHolder_var::tao_remove_ref (
    ExceptionHolder *p
  )
{
  CORBA::remove_ref (p);
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_valuetype.cpp:568

// *************************************************************
// Operations for class Messaging::ExceptionHolder_out
// *************************************************************

Messaging::ExceptionHolder_out::ExceptionHolder_out (ExceptionHolder *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

Messaging::ExceptionHolder_out::ExceptionHolder_out (ExceptionHolder_var &p)
  : ptr_ (p.out ())
{
  CORBA::remove_ref (this->ptr_);
  this->ptr_ = 0;
}

Messaging::ExceptionHolder_out::ExceptionHolder_out (const ExceptionHolder_out &p)
  : ptr_ (ACE_const_cast (ExceptionHolder_out&, p).ptr_)
{}

Messaging::ExceptionHolder_out &
Messaging::ExceptionHolder_out::operator= (const ExceptionHolder_out &p)
{
  this->ptr_ = ACE_const_cast (ExceptionHolder_out&, p).ptr_;
  return *this;
}

Messaging::ExceptionHolder_out &
Messaging::ExceptionHolder_out::operator= (const ExceptionHolder_var &p)
{
  ExceptionHolder *tmp = p.ptr ();
  CORBA::add_ref (tmp);
  this->ptr_ = tmp;
  return *this;
}

Messaging::ExceptionHolder_out &
Messaging::ExceptionHolder_out::operator= (ExceptionHolder *p)
{
  this->ptr_ = p;
  return *this;
}

Messaging::ExceptionHolder_out::operator Messaging::ExceptionHolder*& () // cast
{
  return this->ptr_;
}

Messaging::ExceptionHolder *&
Messaging::ExceptionHolder_out::ptr (void) // ptr
{
  return this->ptr_;
}

Messaging::ExceptionHolder *
Messaging::ExceptionHolder_out::operator-> (void)
{
  return this->ptr_;
}

// *************************************************************

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/valuetype_cs.cpp:138

Messaging::ExceptionHolder *
Messaging::ExceptionHolder::_downcast (CORBA::ValueBase *v)
{
  if (v == 0)
    {
      return 0;
    }
  
  return (ExceptionHolder *) v->_tao_obv_narrow ((ptr_arith_t) &_downcast);
}

const char *
Messaging::ExceptionHolder::_tao_obv_repository_id (void) const
{
  return this->_tao_obv_static_repository_id ();
}

void *
#if defined (_MSC_VER)
Messaging::ExceptionHolder::Messaging_ExceptionHolder_tao_obv_narrow (ptr_arith_t type_id)
#else
Messaging::ExceptionHolder::_tao_obv_narrow (ptr_arith_t type_id)
#endif /* _MSC_VER */
{
  if (type_id == (ptr_arith_t) &_downcast)
    {
      return this;
    }
  
  void *rval = 0;
  
  return rval;
}

#if defined (_MSC_VER)
void *
Messaging::ExceptionHolder::_tao_obv_narrow (ptr_arith_t type_id)
{
  return this->Messaging_ExceptionHolder_tao_obv_narrow (type_id);
}
#endif /* _MSC_VER */

void
Messaging::ExceptionHolder::_tao_any_destructor (void *_tao_void_pointer)
{
  ExceptionHolder *tmp =
    ACE_static_cast (
        ExceptionHolder *,
        _tao_void_pointer
      );
  delete tmp;
}

CORBA::Boolean Messaging::ExceptionHolder::_tao_marshal_v (TAO_OutputCDR & strm)
{
  return this->_tao_marshal__Messaging_ExceptionHolder (strm);
}

CORBA::Boolean Messaging::ExceptionHolder::_tao_unmarshal_v (TAO_InputCDR & strm)
{
  return this->_tao_unmarshal__Messaging_ExceptionHolder (strm);
}

CORBA::Boolean Messaging::ExceptionHolder::_tao_unmarshal (
    TAO_InputCDR &strm,
    ExceptionHolder *&new_object
  )
{
  CORBA::ValueBase *base = 0;
  CORBA::ValueFactory_var factory;
  CORBA::Boolean retval =
    CORBA::ValueBase::_tao_unmarshal_pre (
        strm,
        factory.out (),
        base,
        ExceptionHolder::_tao_obv_static_repository_id ()
      );
  
  if (retval == 0)
    {
      return 0;
    }
  
  if (factory.in () != 0)
    {
      base = factory->create_for_unmarshal ();
      
      if (base == 0)
        {
          return 0;  // %! except.?
        }
      
      retval = base->_tao_unmarshal_v (strm);
      
      if (retval == 0)
        {
          return 0;
        }
    }
  
  // Now base must be null or point to the unmarshaled object.
  // Align the pointer to the right subobject.
  new_object = ExceptionHolder::_downcast (base);
  return retval;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/valuetype_init_cs.cpp:84

Messaging::ExceptionHolder_init::ExceptionHolder_init (void)
{
}

Messaging::ExceptionHolder_init::~ExceptionHolder_init (void)
{
}

const char* 
Messaging::ExceptionHolder_init::tao_repository_id (void)
{
  return Messaging::ExceptionHolder::_tao_obv_static_repository_id ();
}

CORBA::ValueBase *
Messaging::ExceptionHolder_init::create_for_unmarshal (void)
{
  CORBA::ValueBase *ret_val = 0;
  ACE_NEW_RETURN (
      ret_val,
      OBV_Messaging::ExceptionHolder,
      0
    );
  return ret_val;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_cs.cpp:61

int Messaging::ReplyHandler::_tao_class_id = 0;

Messaging::ReplyHandler_ptr
tao_Messaging_ReplyHandler_duplicate (
    Messaging::ReplyHandler_ptr p
  )
{
  return Messaging::ReplyHandler::_duplicate (p);
}

void
tao_Messaging_ReplyHandler_release (
    Messaging::ReplyHandler_ptr p
  )
{
  CORBA::release (p);
}

Messaging::ReplyHandler_ptr
tao_Messaging_ReplyHandler_nil (
    void
  )
{
  return Messaging::ReplyHandler::_nil ();
}

Messaging::ReplyHandler_ptr
tao_Messaging_ReplyHandler_narrow (
    CORBA::Object *p
    ACE_ENV_ARG_DECL
  )
{
  return Messaging::ReplyHandler::_narrow (p ACE_ENV_ARG_PARAMETER);
}

CORBA::Object *
tao_Messaging_ReplyHandler_upcast (
    void *src
  )
{
  Messaging::ReplyHandler **tmp =
    ACE_static_cast (Messaging::ReplyHandler **, src);
  return *tmp;
}

CORBA::Boolean
tao_Messaging_ReplyHandler_marshal (
    Messaging::ReplyHandler_ptr p,
    TAO_OutputCDR &strm
  )
{
  return p->marshal (strm);
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:721

// *************************************************************
// Messaging::ReplyHandler_var
// *************************************************************

Messaging::ReplyHandler_var::ReplyHandler_var (void)
  : ptr_ (ReplyHandler::_nil ())
{}

::Messaging::ReplyHandler_ptr
Messaging::ReplyHandler_var::ptr (void) const
{
  return this->ptr_;
}

Messaging::ReplyHandler_var::ReplyHandler_var (const ::Messaging::ReplyHandler_var &p)
  : TAO_Base_var (),
    ptr_ (ReplyHandler::_duplicate (p.ptr ()))
{}

Messaging::ReplyHandler_var::~ReplyHandler_var (void)
{
  CORBA::release (this->ptr_);
}

Messaging::ReplyHandler_var &
Messaging::ReplyHandler_var::operator= (ReplyHandler_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

Messaging::ReplyHandler_var &
Messaging::ReplyHandler_var::operator= (const ::Messaging::ReplyHandler_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = ::Messaging::ReplyHandler::_duplicate (p.ptr ());
  }
  return *this;
}

Messaging::ReplyHandler_var::operator const ::Messaging::ReplyHandler_ptr &() const // cast
{
  return this->ptr_;
}

Messaging::ReplyHandler_var::operator ::Messaging::ReplyHandler_ptr &() // cast 
{
  return this->ptr_;
}

::Messaging::ReplyHandler_ptr
Messaging::ReplyHandler_var::operator-> (void) const
{
  return this->ptr_;
}

::Messaging::ReplyHandler_ptr
Messaging::ReplyHandler_var::in (void) const
{
  return this->ptr_;
}

::Messaging::ReplyHandler_ptr &
Messaging::ReplyHandler_var::inout (void)
{
  return this->ptr_;
}

::Messaging::ReplyHandler_ptr &
Messaging::ReplyHandler_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = ::Messaging::ReplyHandler::_nil ();
  return this->ptr_;
}

::Messaging::ReplyHandler_ptr
Messaging::ReplyHandler_var::_retn (void)
{
  // yield ownership of managed obj reference
  ::Messaging::ReplyHandler_ptr val = this->ptr_;
  this->ptr_ = ::Messaging::ReplyHandler::_nil ();
  return val;
}

::Messaging::ReplyHandler_ptr
Messaging::ReplyHandler_var::tao_duplicate (ReplyHandler_ptr p)
{
  return ::Messaging::ReplyHandler::_duplicate (p);
}

void
Messaging::ReplyHandler_var::tao_release (ReplyHandler_ptr p)
{
  CORBA::release (p);
}

::Messaging::ReplyHandler_ptr
Messaging::ReplyHandler_var::tao_nil (void)
{
  return ::Messaging::ReplyHandler::_nil ();
}

::Messaging::ReplyHandler_ptr
Messaging::ReplyHandler_var::tao_narrow (
    CORBA::Object *p
    ACE_ENV_ARG_DECL
  )
{
  return ::Messaging::ReplyHandler::_narrow (p ACE_ENV_ARG_PARAMETER);
}

CORBA::Object *
Messaging::ReplyHandler_var::tao_upcast (void *src)
{
  ReplyHandler **tmp =
    ACE_static_cast (ReplyHandler **, src);
  return *tmp;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:1030

// *************************************************************
// Messaging::ReplyHandler_out
// *************************************************************

Messaging::ReplyHandler_out::ReplyHandler_out (ReplyHandler_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = ::Messaging::ReplyHandler::_nil ();
}

Messaging::ReplyHandler_out::ReplyHandler_out (ReplyHandler_var &p)
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = ::Messaging::ReplyHandler::_nil ();
}

Messaging::ReplyHandler_out::ReplyHandler_out (const ::Messaging::ReplyHandler_out &p)
  : ptr_ (ACE_const_cast (ReplyHandler_out &, p).ptr_)
{}

::Messaging::ReplyHandler_out &
Messaging::ReplyHandler_out::operator= (const ::Messaging::ReplyHandler_out &p)
{
  this->ptr_ = ACE_const_cast (ReplyHandler_out&, p).ptr_;
  return *this;
}

Messaging::ReplyHandler_out &
Messaging::ReplyHandler_out::operator= (const ::Messaging::ReplyHandler_var &p)
{
  this->ptr_ = ::Messaging::ReplyHandler::_duplicate (p.ptr ());
  return *this;
}

Messaging::ReplyHandler_out &
Messaging::ReplyHandler_out::operator= (ReplyHandler_ptr p)
{
  this->ptr_ = p;
  return *this;
}

Messaging::ReplyHandler_out::operator ::Messaging::ReplyHandler_ptr &() // cast
{
  return this->ptr_;
}

::Messaging::ReplyHandler_ptr &
Messaging::ReplyHandler_out::ptr (void)
{
  return this->ptr_;
}

::Messaging::ReplyHandler_ptr
Messaging::ReplyHandler_out::operator-> (void)
{
  return this->ptr_;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interceptors_cs.cpp:56

#if (TAO_HAS_INTERCEPTORS == 1)

#endif /* TAO_HAS_INTERCEPTORS */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/remote_proxy_impl_cs.cpp:31

///////////////////////////////////////////////////////////////////////
//                Base & Remote Proxy  Implementation. 
//

Messaging::_TAO_ReplyHandler_Proxy_Impl::_TAO_ReplyHandler_Proxy_Impl (void)
{}

Messaging::_TAO_ReplyHandler_Remote_Proxy_Impl::_TAO_ReplyHandler_Remote_Proxy_Impl (void)
{}

// Remote Implementation of the IDL interface methods

//
//            End  Base & Remote  Proxy Implemeentation. 
///////////////////////////////////////////////////////////////////////

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/remote_proxy_broker_cs.cpp:31

///////////////////////////////////////////////////////////////////////
//           Remote & Base  Proxy Broker Implementation
//

Messaging::_TAO_ReplyHandler_Proxy_Broker::_TAO_ReplyHandler_Proxy_Broker (void)
{
}

Messaging::_TAO_ReplyHandler_Proxy_Broker::~_TAO_ReplyHandler_Proxy_Broker (void)
{
}

Messaging::_TAO_ReplyHandler_Proxy_Broker * (*Messaging__TAO_ReplyHandler_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

// Factory Member function Implementation.
Messaging::_TAO_ReplyHandler_Remote_Proxy_Broker *
Messaging::_TAO_ReplyHandler_Remote_Proxy_Broker::the_TAO_ReplyHandler_Remote_Proxy_Broker (void)
{
  static ::Messaging::_TAO_ReplyHandler_Remote_Proxy_Broker remote_proxy_broker;
  return &remote_proxy_broker;
}

Messaging::_TAO_ReplyHandler_Remote_Proxy_Broker::_TAO_ReplyHandler_Remote_Proxy_Broker (void)
{
}

Messaging::_TAO_ReplyHandler_Remote_Proxy_Broker::~_TAO_ReplyHandler_Remote_Proxy_Broker (void)
{
}

Messaging::_TAO_ReplyHandler_Proxy_Impl&
Messaging::_TAO_ReplyHandler_Remote_Proxy_Broker::select_proxy (
    ::Messaging::ReplyHandler *
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return this->remote_proxy_impl_;
}

//
//           End Remote & Base Proxy Broker Implementation
///////////////////////////////////////////////////////////////////////

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_cs.cpp:235

Messaging::ReplyHandler::ReplyHandler (int collocated)
{
  this->Messaging_ReplyHandler_setup_collocation (collocated);
}

void
Messaging::ReplyHandler::Messaging_ReplyHandler_setup_collocation (int collocated)
{
  if (collocated)
    this->the_TAO_ReplyHandler_Proxy_Broker_ =
      ::Messaging__TAO_ReplyHandler_Proxy_Broker_Factory_function_pointer (this);
  else
    this->the_TAO_ReplyHandler_Proxy_Broker_ =
      ::Messaging::_TAO_ReplyHandler_Remote_Proxy_Broker::the_TAO_ReplyHandler_Remote_Proxy_Broker ();
}

Messaging::ReplyHandler::~ReplyHandler (void)
{}

void 
Messaging::ReplyHandler::_tao_any_destructor (void *_tao_void_pointer)
{
  ReplyHandler *tmp = ACE_static_cast (ReplyHandler *, _tao_void_pointer);
  CORBA::release (tmp);
}

Messaging::ReplyHandler_ptr
Messaging::ReplyHandler::_narrow (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL
  )
{
  if (CORBA::is_nil (obj))
    {
      return ReplyHandler::_nil ();
    }
  
  if (! obj->_is_local ())
    {
      CORBA::Boolean is_a =
        obj->_is_a (
            "IDL:omg.org/Messaging/ReplyHandler:1.0"
            ACE_ENV_ARG_PARAMETER
          );
      ACE_CHECK_RETURN (ReplyHandler::_nil ());
      
      if (is_a == 0)
        {
          return ReplyHandler::_nil ();
        }
    }
  
  return ReplyHandler::_unchecked_narrow (obj ACE_ENV_ARG_PARAMETER);
}

Messaging::ReplyHandler_ptr 
Messaging::ReplyHandler::_unchecked_narrow (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (obj))
    {
      return ReplyHandler::_nil ();
    }
  
  if (! obj->_is_local ())
    {
      TAO_Stub* stub = obj->_stubobj ();
      
      if (stub != 0)
        {
          stub->_incr_refcnt ();
        }
      
      ReplyHandler_ptr default_proxy = ReplyHandler::_nil ();
      
      if (
          !CORBA::is_nil (stub->servant_orb_var ().ptr ()) &&
          stub->servant_orb_var ()->orb_core ()->optimize_collocation_objects () &&
          obj->_is_collocated () &&
          Messaging__TAO_ReplyHandler_Proxy_Broker_Factory_function_pointer != 0
        )
        {
          ACE_NEW_RETURN (
              default_proxy,
              ::Messaging::ReplyHandler (
                  stub,
                  1,
                  obj->_servant ()
                ),
              ReplyHandler::_nil ()
            );
        }
      
      if (CORBA::is_nil (default_proxy))
        {
          ACE_NEW_RETURN (
              default_proxy,
              ::Messaging::ReplyHandler (
                  stub,
                  0,
                  obj->_servant ()
                ),
              ReplyHandler::_nil ()
            );
        }
      
      return default_proxy;
    }
  else 
    return
      ACE_reinterpret_cast (
          ReplyHandler_ptr,
          obj->_tao_QueryInterface (
              ACE_reinterpret_cast (
                  ptr_arith_t,
                  &ReplyHandler::_tao_class_id
                )
            )
        );
}

Messaging::ReplyHandler_ptr
Messaging::ReplyHandler::_duplicate (ReplyHandler_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

CORBA::Boolean
Messaging::ReplyHandler::_is_a (
    const char *value
    ACE_ENV_ARG_DECL
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/Messaging/ReplyHandler:1.0"
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

void *Messaging::ReplyHandler::_tao_QueryInterface (ptr_arith_t type)
{
  void *retv = 0;
  
  if (type == ACE_reinterpret_cast (
              ptr_arith_t,
              &ACE_NESTED_CLASS (::Messaging, ReplyHandler)::_tao_class_id)
            )
    {
      retv = ACE_reinterpret_cast (void*, this);
    }
  else if (type == ACE_reinterpret_cast (
               ptr_arith_t,
               &CORBA::Object::_tao_class_id)
             )
    {
      retv =
        ACE_reinterpret_cast (
            void *,
            ACE_static_cast (CORBA::Object_ptr, this)
          );
    }
  
  if (retv != 0)
    {
      this->_add_ref ();
    }
  
  return retv;
}

const char* Messaging::ReplyHandler::_interface_repository_id (void) const
{
  return "IDL:omg.org/Messaging/ReplyHandler:1.0";
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_Messaging_ReplyHandler[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  39,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x4d657373), 
  ACE_NTOHL (0x6167696e), 
  ACE_NTOHL (0x672f5265), 
  ACE_NTOHL (0x706c7948), 
  ACE_NTOHL (0x616e646c), 
  ACE_NTOHL (0x65723a31), 
  ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/Messaging/ReplyHandler:1.0
    13,
  ACE_NTOHL (0x5265706c), 
  ACE_NTOHL (0x7948616e), 
  ACE_NTOHL (0x646c6572), 
  ACE_NTOHL (0x0),  // name = ReplyHandler
  };

static CORBA::TypeCode _tc_TAO_tc_Messaging_ReplyHandler (
    CORBA::tk_objref,
    sizeof (_oc_Messaging_ReplyHandler),
    (char *) &_oc_Messaging_ReplyHandler,
    0,
    sizeof (Messaging::ReplyHandler)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (Messaging)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_ReplyHandler,
    &_tc_TAO_tc_Messaging_ReplyHandler
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/valuetype_obv_cs.cpp:58

OBV_Messaging::ExceptionHolder::~ExceptionHolder (void)
{}

CORBA::Boolean
OBV_Messaging::ExceptionHolder::_tao_marshal__Messaging_ExceptionHolder (TAO_OutputCDR &strm)
{
  return _tao_marshal_state (strm);
}

CORBA::Boolean
OBV_Messaging::ExceptionHolder::_tao_unmarshal__Messaging_ExceptionHolder (TAO_InputCDR &strm)
{
  return _tao_unmarshal_state (strm);
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/field_cs.cpp:568

// Accessor to set the member.
void
OBV_Messaging::ExceptionHolder::is_system_exception (CORBA::Boolean val)
{
  // Set the value.
  this->_pd_is_system_exception = val;
}

// Retrieve the member
CORBA::Boolean
OBV_Messaging::ExceptionHolder::is_system_exception (void) const
{
  return this->_pd_is_system_exception;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/field_cs.cpp:568

// Accessor to set the member.
void
OBV_Messaging::ExceptionHolder::byte_order (CORBA::Boolean val)
{
  // Set the value.
  this->_pd_byte_order = val;
}

// Retrieve the member
CORBA::Boolean
OBV_Messaging::ExceptionHolder::byte_order (void) const
{
  return this->_pd_byte_order;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/field_cs.cpp:744

// Accessor to set the member.
void
OBV_Messaging::ExceptionHolder::marshaled_exception (const CORBA::OctetSeq &val)
{
  this->_pd_marshaled_exception = val;
}

// Readonly get method.
const CORBA::OctetSeq &
OBV_Messaging::ExceptionHolder::marshaled_exception (void) const
{
  return this->_pd_marshaled_exception;
}

// Read/write get method.
CORBA::OctetSeq &
OBV_Messaging::ExceptionHolder::marshaled_exception (void)
{
  return this->_pd_marshaled_exception;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/any_op_cs.cpp:56

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    Messaging::ExceptionHolder *_tao_elem
  )
{
  CORBA::add_ref (_tao_elem);
  _tao_any <<= &_tao_elem;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    Messaging::ExceptionHolder **_tao_elem
  )
{
  TAO::Any_Impl_T<Messaging::ExceptionHolder>::insert (
      _tao_any,
      Messaging::ExceptionHolder::_tao_any_destructor,
      Messaging::_tc_ExceptionHolder,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    Messaging::ExceptionHolder *&_tao_elem
  )
{
  return
    TAO::Any_Impl_T<Messaging::ExceptionHolder>::extract (
        _tao_any,
        Messaging::ExceptionHolder::_tao_any_destructor,
        Messaging::_tc_ExceptionHolder,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
  template class TAO_Valuetype_Manager<Messaging::ExceptionHolder, Messaging::ExceptionHolder_var>;
  template class TAO::Any_Impl_T<Messaging::ExceptionHolder>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#  pragma instantiate TAO_Valuetype_Manager<Messaging::ExceptionHolder, Messaging::ExceptionHolder_var>
#  pragma instantiate TAO::Any_Impl_T<Messaging::ExceptionHolder>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/any_op_cs.cpp:52

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    Messaging::ReplyHandler_ptr _tao_elem
  )
{
  Messaging::ReplyHandler_ptr _tao_objptr =
    Messaging::ReplyHandler::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    Messaging::ReplyHandler_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<Messaging::ReplyHandler>::insert (
      _tao_any,
      Messaging::ReplyHandler::_tao_any_destructor,
      Messaging::_tc_ReplyHandler,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    Messaging::ReplyHandler_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<Messaging::ReplyHandler>::extract (
        _tao_any,
        Messaging::ReplyHandler::_tao_any_destructor,
        Messaging::_tc_ReplyHandler,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
  template class TAO_Object_Manager<Messaging::ReplyHandler,Messaging::ReplyHandler_var>;
  template class TAO::Any_Impl_T<Messaging::ReplyHandler>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO_Object_Manager<Messaging::ReplyHandler, Messaging::ReplyHandler_var>
# pragma instantiate TAO::Any_Impl_T<Messaging::ReplyHandler>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_valuetype.cpp:740

void
CORBA::add_ref (Messaging::ExceptionHolder * vt)
{
  if (vt != 0)
    {
      vt->_add_ref ();
    }
}

void
CORBA::remove_ref (Messaging::ExceptionHolder * vt)
{
  if (vt != 0)
    {
      vt->_remove_ref ();
    }
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/cdr_op_cs.cpp:73

CORBA::Boolean
operator<< (
    TAO_OutputCDR &strm,
    const Messaging::ExceptionHolder *_tao_valuetype
  )
{
  return
    CORBA::ValueBase::_tao_marshal (
        strm,
        ACE_const_cast (
            Messaging::ExceptionHolder *,
            _tao_valuetype
          ),
        (ptr_arith_t) &Messaging::ExceptionHolder::_downcast
      );
}

CORBA::Boolean
operator>> (
    TAO_InputCDR &strm,
    Messaging::ExceptionHolder *&_tao_valuetype
  )
{
  return Messaging::ExceptionHolder::_tao_unmarshal (strm, _tao_valuetype);
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/marshal_cs.cpp:44

CORBA::Boolean
OBV_Messaging::ExceptionHolder::_tao_marshal_state (TAO_OutputCDR &strm)
{
  if (
    (strm << CORBA::Any::from_boolean (_pd_is_system_exception)) &&
    (strm << CORBA::Any::from_boolean (_pd_byte_order)) &&
    (strm << _pd_marshaled_exception)
   )
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

CORBA::Boolean
OBV_Messaging::ExceptionHolder::_tao_unmarshal_state (TAO_InputCDR &strm)
{
  if (
    (strm >> CORBA::Any::to_boolean (_pd_is_system_exception)) &&
    (strm >> CORBA::Any::to_boolean (_pd_byte_order)) &&
    (strm >> _pd_marshaled_exception)
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
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/cdr_op_cs.cpp:94

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Messaging::ReplyHandler_ptr _tao_objref
  )
{
  CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    Messaging::ReplyHandler_ptr &_tao_objref
  )
{
  ACE_TRY_NEW_ENV
  {
    CORBA::Object_var obj;
    
    if ((strm >> obj.inout ()) == 0)
      {
        return 0;
      }
    
    // Narrow to the right type.
    _tao_objref =
      Messaging::ReplyHandler::_unchecked_narrow (
          obj.in ()
          ACE_ENV_ARG_PARAMETER
        );
    ACE_TRY_CHECK;
    return 1;
  }
  ACE_CATCHANY
  {
    // do nothing
  }
  ACE_ENDTRY;
  return 0;
}



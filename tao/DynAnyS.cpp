/* -*- C++ -*- */
// $Id$
// ======================================================================
//
// = LIBRARY
//    TAO
//
// = FILENAME
//    DynAnyS.cpp
//
// = AUTHOR
//
// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO ORB and the TAO IDL Compiler have been developed by Washington
// University Computer Science's Distributed Object Computing Group.
//
// Information on TAO is available at
//                 http://www.cs.wustl.edu/~schmidt/TAO.html
//
//
// Modified by Jeff Parsons <jp4@cs.wustl.edu>
//
// ======================================================================

#include "tao/DynAnyC.h"

#if !defined (TAO_HAS_MINIMUM_CORBA)

#include "tao/POA_CORBA.h"
#include "tao/Servant_Base.h"
#include "tao/POAC.h"

ACE_RCSID(tao, DynAnyS, "$Id$")

// constructor
POA_CORBA::DynAny::DynAny (void)
{
}

// copy ctor
POA_CORBA::DynAny::DynAny (POA_CORBA::DynAny& rhs)
  : TAO_Local_ServantBase (rhs)
{}
// destructor
POA_CORBA::DynAny::~DynAny (void)
{
}

CORBA::Boolean
POA_CORBA::DynAny::_is_a (const char* value,
                          CORBA::Environment &_tao_environment)
{
  if ((!ACE_OS::strcmp ((char *) value,
                        "IDL:/CORBA_DynAny:1.0"))
      || (!ACE_OS::strcmp ((char *) value,
                           CORBA::_tc_Object->id (_tao_environment))))
      return 1;
    else
      return 0;
}

void*
POA_CORBA::DynAny::_downcast (const char* logical_type_id)
{
  if (ACE_OS::strcmp (logical_type_id,
                      "IDL:/CORBA_DynAny:1.0") == 0)
    return ACE_static_cast (POA_CORBA::DynAny_ptr, this);

  if (ACE_OS::strcmp (logical_type_id,
                      "IDL:omg.org/CORBA/Object:1.0") == 0)
    return ACE_static_cast(PortableServer::Servant, this);

  return 0;
}

void POA_CORBA::DynAny::_dispatch (CORBA::ServerRequest &,
                                   void *,
                                   CORBA::Environment &)
{
}

const char*
POA_CORBA::DynAny::_interface_repository_id (void) const
{
  return "IDL:/CORBA_DynAny:1.0";
}

POA_CORBA::_tao_collocated_DynAny::_tao_collocated_DynAny (
    POA_CORBA::DynAny_ptr  servant,
    TAO_Stub *stub
  )
  : CORBA_DynAny (),
    CORBA_Object (stub,
                  servant,
                  1),
    servant_ (servant)
{
}

POA_CORBA::DynAny_ptr
POA_CORBA::_tao_collocated_DynAny::_get_servant (void) const
{
  return this->servant_;
}

CORBA::Boolean
POA_CORBA::_tao_collocated_DynAny::_is_a (
    const char* logical_type_id,
    CORBA::Environment &_tao_environment
  )
{
  return this->servant_->_is_a (
      logical_type_id,
      _tao_environment
    );
}

CORBA::TypeCode_ptr
POA_CORBA::_tao_collocated_DynAny::type (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->type (
    _tao_environment
  );
}

void
POA_CORBA::_tao_collocated_DynAny::assign (
    CORBA_DynAny_ptr CORBA_Dyn_any,
    CORBA::Environment &_tao_environment
   )
{
  this->servant_->assign (
    CORBA_Dyn_any,
    _tao_environment
  );
}

void
POA_CORBA::_tao_collocated_DynAny::from_any (
    const CORBA::Any & value,
    CORBA::Environment &_tao_environment
   )
{
  this->servant_->from_any (
    value,
    _tao_environment
  );
}

CORBA::Any *
POA_CORBA::_tao_collocated_DynAny::to_any (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->to_any (
    _tao_environment
  );
}

void
POA_CORBA::_tao_collocated_DynAny::destroy (
    CORBA::Environment &_tao_environment
   )
{
  this->servant_->destroy (
    _tao_environment
  );
}

CORBA_DynAny_ptr
POA_CORBA::_tao_collocated_DynAny::copy (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->copy (
    _tao_environment
  );
}

void
POA_CORBA::_tao_collocated_DynAny::insert_boolean (
    CORBA::Boolean value,
    CORBA::Environment &_tao_environment
   )
{
  this->servant_->insert_boolean (
    value,
    _tao_environment
  );
}

void
POA_CORBA::_tao_collocated_DynAny::insert_octet (
    CORBA::Octet value,
    CORBA::Environment &_tao_environment
   )
{
  this->servant_->insert_octet (
    value,
    _tao_environment
  );
}

void
POA_CORBA::_tao_collocated_DynAny::insert_char (
    CORBA::Char value,
    CORBA::Environment &_tao_environment
   )
{
  this->servant_->insert_char (
    value,
    _tao_environment
  );
}

void
POA_CORBA::_tao_collocated_DynAny::insert_short (
    CORBA::Short value,
    CORBA::Environment &_tao_environment
   )
{
  this->servant_->insert_short (
    value,
    _tao_environment
  );
}

void
POA_CORBA::_tao_collocated_DynAny::insert_ushort (
    CORBA::UShort value,
    CORBA::Environment &_tao_environment
   )
{
  this->servant_->insert_ushort (
    value,
    _tao_environment
  );
}

void
POA_CORBA::_tao_collocated_DynAny::insert_long (
    CORBA::Long value,
    CORBA::Environment &_tao_environment
   )
{
  this->servant_->insert_long (
    value,
    _tao_environment
  );
}

void
POA_CORBA::_tao_collocated_DynAny::insert_ulong (
    CORBA::ULong value,
    CORBA::Environment &_tao_environment
   )
{
  this->servant_->insert_ulong (
    value,
    _tao_environment
  );
}

void
POA_CORBA::_tao_collocated_DynAny::insert_float (
    CORBA::Float value,
    CORBA::Environment &_tao_environment
   )
{
  this->servant_->insert_float (
    value,
    _tao_environment
  );
}

void
POA_CORBA::_tao_collocated_DynAny::insert_double (
    CORBA::Double value,
    CORBA::Environment &_tao_environment
   )
{
  this->servant_->insert_double (
    value,
    _tao_environment
  );
}

void
POA_CORBA::_tao_collocated_DynAny::insert_string (
    const char * value,
    CORBA::Environment &_tao_environment
   )
{
  this->servant_->insert_string (
    value,
    _tao_environment
  );
}

void
POA_CORBA::_tao_collocated_DynAny::insert_reference (
    CORBA::Object_ptr value,
    CORBA::Environment &_tao_environment
   )
{
  this->servant_->insert_reference (
    value,
    _tao_environment
  );
}

void
POA_CORBA::_tao_collocated_DynAny::insert_typecode (
    CORBA::TypeCode_ptr value,
    CORBA::Environment &_tao_environment
   )
{
  this->servant_->insert_typecode (
    value,
    _tao_environment
  );
}

void
POA_CORBA::_tao_collocated_DynAny::insert_longlong (
    CORBA::LongLong value,
    CORBA::Environment &_tao_environment
   )
{
  this->servant_->insert_longlong (
    value,
    _tao_environment
  );
}

void
POA_CORBA::_tao_collocated_DynAny::insert_ulonglong (
    CORBA::ULongLong value,
    CORBA::Environment &_tao_environment
   )
{
  this->servant_->insert_ulonglong (
    value,
    _tao_environment
  );
}

void
POA_CORBA::_tao_collocated_DynAny::insert_wchar (
    CORBA::WChar value,
    CORBA::Environment &_tao_environment
   )
{
  this->servant_->insert_wchar (
    value,
    _tao_environment
  );
}

void
POA_CORBA::_tao_collocated_DynAny::insert_any (
    const CORBA::Any & value,
    CORBA::Environment &_tao_environment
   )
{
  this->servant_->insert_any (
    value,
    _tao_environment
  );
}

CORBA::Boolean
POA_CORBA::_tao_collocated_DynAny::get_boolean (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->get_boolean (
    _tao_environment
  );
}

CORBA::Octet
POA_CORBA::_tao_collocated_DynAny::get_octet (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->get_octet (
    _tao_environment
  );
}

CORBA::Char
POA_CORBA::_tao_collocated_DynAny::get_char (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->get_char (
    _tao_environment
  );
}

CORBA::Short
POA_CORBA::_tao_collocated_DynAny::get_short (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->get_short (
    _tao_environment
  );
}

CORBA::UShort
POA_CORBA::_tao_collocated_DynAny::get_ushort (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->get_ushort (
    _tao_environment
  );
}

CORBA::Long
POA_CORBA::_tao_collocated_DynAny::get_long (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->get_long (
    _tao_environment
  );
}

CORBA::ULong
POA_CORBA::_tao_collocated_DynAny::get_ulong (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->get_ulong (
    _tao_environment
  );
}

CORBA::Float
POA_CORBA::_tao_collocated_DynAny::get_float (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->get_float (
    _tao_environment
  );
}

CORBA::Double
POA_CORBA::_tao_collocated_DynAny::get_double (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->get_double (
    _tao_environment
  );
}

char *
POA_CORBA::_tao_collocated_DynAny::get_string (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->get_string (
    _tao_environment
  );
}

CORBA::Object_ptr
POA_CORBA::_tao_collocated_DynAny::get_reference (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->get_reference (
    _tao_environment
  );
}

CORBA::TypeCode_ptr
POA_CORBA::_tao_collocated_DynAny::get_typecode (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->get_typecode (
    _tao_environment
  );
}

CORBA::LongLong
POA_CORBA::_tao_collocated_DynAny::get_longlong (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->get_longlong (
    _tao_environment
  );
}

CORBA::ULongLong
POA_CORBA::_tao_collocated_DynAny::get_ulonglong (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->get_ulonglong (
    _tao_environment
  );
}

CORBA::WChar
POA_CORBA::_tao_collocated_DynAny::get_wchar (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->get_wchar (
    _tao_environment
  );
}

CORBA::Any *
POA_CORBA::_tao_collocated_DynAny::get_any (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->get_any (
    _tao_environment
  );
}

CORBA_DynAny_ptr
POA_CORBA::_tao_collocated_DynAny::current_component (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->current_component (
    _tao_environment
  );
}

CORBA::Boolean
POA_CORBA::_tao_collocated_DynAny::next (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->next (
    _tao_environment
  );
}

CORBA::Boolean
POA_CORBA::_tao_collocated_DynAny::seek (
    CORBA::Long index,
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->seek (
    index,
    _tao_environment
  );
}

void
POA_CORBA::_tao_collocated_DynAny::rewind (
    CORBA::Environment &_tao_environment
   )
{
  this->servant_->rewind (
    _tao_environment
  );
}


CORBA_DynAny*
POA_CORBA::DynAny::_this (CORBA_Environment &TAO_IN_ENV)
{
  TAO_Stub *stub = this->_create_stub (TAO_IN_ENV);

  if (TAO_IN_ENV.exception () != 0)
    return 0;

  return new POA_CORBA::_tao_collocated_DynAny (this, stub);
}

// constructor
POA_CORBA::DynEnum::DynEnum (void)
{
}

// copy ctor
POA_CORBA::DynEnum::DynEnum (POA_CORBA::DynEnum& rhs)
  : ACE_NESTED_CLASS (POA_CORBA, DynAny (rhs)),
    TAO_Local_ServantBase (rhs)
        {}
// destructor
POA_CORBA::DynEnum::~DynEnum (void)
{
}

CORBA::Boolean
POA_CORBA::DynEnum::_is_a (
    const char* value,
    CORBA::Environment &_tao_environment
  )
{
  if ((!ACE_OS::strcmp ((char *) value,
                        "IDL:/CORBA_DynEnum:1.0"))
      || (!ACE_OS::strcmp ((char *) value,
                           "IDL:/CORBA_DynAny:1.0"))
      || (!ACE_OS::strcmp ((char *) value,
                           CORBA::_tc_Object->id (_tao_environment))))
      return 1;
    else
      return 0;
}

void*
POA_CORBA::DynEnum::_downcast (
    const char* logical_type_id
  )
{
  if (!ACE_OS::strcmp (logical_type_id,
                       "IDL:/CORBA_DynEnum:1.0"))
    return ACE_static_cast (POA_CORBA::DynEnum_ptr,
                            this);

  if (!ACE_OS::strcmp (logical_type_id,
                       "IDL:/CORBA_DynAny:1.0"))
    return ACE_static_cast (POA_CORBA::DynAny_ptr,
                            this);

  if (!ACE_OS::strcmp (logical_type_id,
                       "IDL:omg.org/CORBA/Object:1.0"))
    return ACE_static_cast(PortableServer::Servant,
                           this);

  return 0;
}

void
POA_CORBA::DynEnum::_dispatch (CORBA::ServerRequest &,
                               void *,
                               CORBA::Environment &)
{
}

const char*
POA_CORBA::DynEnum::_interface_repository_id (void) const
{
  return "IDL:/CORBA_DynEnum:1.0";
}

POA_CORBA::_tao_collocated_DynEnum::_tao_collocated_DynEnum (
    POA_CORBA::DynEnum_ptr servant,
    TAO_Stub *stub
  )
  : CORBA_DynEnum (),
    ACE_NESTED_CLASS (POA_CORBA, _tao_collocated_DynAny (servant,
                                                         stub)),
    CORBA_Object (stub,
                  servant,
                  1),
    servant_ (servant)
{
}

POA_CORBA::DynEnum_ptr
POA_CORBA::_tao_collocated_DynEnum::_get_servant (void) const
{
  return this->servant_;
}

CORBA::Boolean
POA_CORBA::_tao_collocated_DynEnum::_is_a (
    const char* logical_type_id,
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->_is_a (
      logical_type_id,
      _tao_environment
    );
}

char *
POA_CORBA::_tao_collocated_DynEnum::value_as_string (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->value_as_string (
    _tao_environment
  );
}

void
POA_CORBA::_tao_collocated_DynEnum::value_as_string (
    const char * value_as_string,
    CORBA::Environment &_tao_environment
   )
{
  this->servant_->value_as_string (
    value_as_string,
    _tao_environment
  );
}

CORBA::ULong
POA_CORBA::_tao_collocated_DynEnum::value_as_ulong (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->value_as_ulong (
    _tao_environment
  );
}

void
POA_CORBA::_tao_collocated_DynEnum::value_as_ulong (
    CORBA::ULong value_as_ulong,
    CORBA::Environment &_tao_environment
   )
{
  this->servant_->value_as_ulong (
    value_as_ulong,
    _tao_environment
  );
}


CORBA_DynEnum*
POA_CORBA::DynEnum::_this (CORBA_Environment &TAO_IN_ENV)
{
  TAO_Stub *stub = this->_create_stub (TAO_IN_ENV);

  if (TAO_IN_ENV.exception () != 0)
    return 0;

  return new POA_CORBA::_tao_collocated_DynEnum (this,
                                                 stub);
}

// constructor
POA_CORBA::DynStruct::DynStruct (void)
{
}

// copy ctor
POA_CORBA::DynStruct::DynStruct (POA_CORBA::DynStruct& rhs)
  : ACE_NESTED_CLASS (POA_CORBA, DynAny (rhs)),
    TAO_Local_ServantBase (rhs)
{}
// destructor
POA_CORBA::DynStruct::~DynStruct (void)
{
}
CORBA::Boolean
POA_CORBA::DynStruct::_is_a (
    const char* value,
    CORBA::Environment &_tao_environment
  )
{
  if ((!ACE_OS::strcmp ((char *)value, "IDL:/CORBA_DynStruct:1.0"))
      || (!ACE_OS::strcmp ((char *)value, "IDL:/CORBA_DynAny:1.0"))
      || (!ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (_tao_environment))))
      return 1;
    else
      return 0;
}

void*
POA_CORBA::DynStruct::_downcast (
    const char* logical_type_id
  )
{
  if (!ACE_OS::strcmp (logical_type_id,
                       "IDL:/CORBA_DynStruct:1.0"))
    return ACE_static_cast (POA_CORBA::DynStruct_ptr,
                            this);

  if (!ACE_OS::strcmp (logical_type_id,
                       "IDL:/CORBA_DynAny:1.0"))
    return ACE_static_cast (POA_CORBA::DynAny_ptr,
                            this);

  if (!ACE_OS::strcmp (logical_type_id,
                       "IDL:omg.org/CORBA/Object:1.0"))
    return ACE_static_cast(PortableServer::Servant,
                           this);

  return 0;
}

void
POA_CORBA::DynStruct::_dispatch (CORBA::ServerRequest &,
                                 void *,
                                 CORBA::Environment &)
{
}

const char*
POA_CORBA::DynStruct::_interface_repository_id (void) const
{
  return "IDL:/CORBA_DynStruct:1.0";
}

POA_CORBA::_tao_collocated_DynStruct::_tao_collocated_DynStruct (
    POA_CORBA::DynStruct_ptr  servant,
    TAO_Stub *stub
  )
  : CORBA_DynStruct (),
    ACE_NESTED_CLASS (POA_CORBA, _tao_collocated_DynAny (servant,
                                                         stub)),
    CORBA_Object (stub,
                  servant,
                  1),
    servant_ (servant)
{
}

POA_CORBA::DynStruct_ptr
POA_CORBA::_tao_collocated_DynStruct::_get_servant (void) const
{
  return this->servant_;
}

CORBA::Boolean
POA_CORBA::_tao_collocated_DynStruct::_is_a (
    const char* logical_type_id,
    CORBA::Environment &_tao_environment
  )
{
  return this->servant_->_is_a (
      logical_type_id,
      _tao_environment
    );
}

char *
POA_CORBA::_tao_collocated_DynStruct::current_member_name (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->current_member_name (
    _tao_environment
  );
}

CORBA::TCKind
POA_CORBA::_tao_collocated_DynStruct::current_member_kind (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->current_member_kind (
    _tao_environment
  );
}

CORBA::NameValuePairSeq *
POA_CORBA::_tao_collocated_DynStruct::get_members (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->get_members (
    _tao_environment
  );
}

void
POA_CORBA::_tao_collocated_DynStruct::set_members (
    const CORBA::NameValuePairSeq & value,
    CORBA::Environment &_tao_environment
   )
{
  this->servant_->set_members (
    value,
    _tao_environment
  );
}


CORBA_DynStruct*
POA_CORBA::DynStruct::_this (CORBA_Environment &TAO_IN_ENV)
{
  TAO_Stub *stub = this->_create_stub (TAO_IN_ENV);

  if (TAO_IN_ENV.exception () != 0)
    return 0;

  return new POA_CORBA::_tao_collocated_DynStruct (this,
                                                   stub);
}

// constructor
POA_CORBA::DynUnion::DynUnion (void)
{
}

// copy ctor
POA_CORBA::DynUnion::DynUnion (POA_CORBA::DynUnion& rhs)
  : ACE_NESTED_CLASS (POA_CORBA, DynAny (rhs)),
    TAO_Local_ServantBase (rhs)
{}
// destructor
POA_CORBA::DynUnion::~DynUnion (void)
{
}
CORBA::Boolean
POA_CORBA::DynUnion::_is_a (
    const char* value,
    CORBA::Environment &_tao_environment
  )
{
  if ((!ACE_OS::strcmp ((char *)value, "IDL:/CORBA_DynUnion:1.0"))
      || (!ACE_OS::strcmp ((char *)value, "IDL:/CORBA_DynAny:1.0"))
      || (!ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (_tao_environment))))
      return 1;
    else
      return 0;
}

void*
POA_CORBA::DynUnion::_downcast (
    const char* logical_type_id
  )
{
  if (!ACE_OS::strcmp (logical_type_id,
                       "IDL:/CORBA_DynUnion:1.0"))
    return ACE_static_cast (POA_CORBA::DynUnion_ptr,
                            this);

  if (!ACE_OS::strcmp (logical_type_id,
                       "IDL:/CORBA_DynAny:1.0"))
    return ACE_static_cast (POA_CORBA::DynAny_ptr,
                            this);

  if (!ACE_OS::strcmp (logical_type_id,
                       "IDL:omg.org/CORBA/Object:1.0"))
    return ACE_static_cast(PortableServer::Servant,
                           this);

  return 0;
}

void POA_CORBA::DynUnion::_dispatch (CORBA::ServerRequest &,
                                    void *,
                                    CORBA::Environment &)
{
}

const char* POA_CORBA::DynUnion::_interface_repository_id (void) const
{
  return "IDL:/CORBA_DynUnion:1.0";
}

POA_CORBA::_tao_collocated_DynUnion::_tao_collocated_DynUnion (
    POA_CORBA::DynUnion_ptr  servant,
    TAO_Stub *stub
  )
  : CORBA_DynUnion (),
    ACE_NESTED_CLASS (POA_CORBA, _tao_collocated_DynAny (servant,
                                                         stub)),
    CORBA_Object (stub, servant, 1),
    servant_ (servant)
{
}

POA_CORBA::DynUnion_ptr
POA_CORBA::_tao_collocated_DynUnion::_get_servant (void) const
{
  return this->servant_;
}

CORBA::Boolean
POA_CORBA::_tao_collocated_DynUnion::_is_a (
    const char* logical_type_id,
    CORBA::Environment &_tao_environment
  )
{
  return this->servant_->_is_a (
      logical_type_id,
      _tao_environment
    );
}

CORBA::Boolean
POA_CORBA::_tao_collocated_DynUnion::set_as_default (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->set_as_default (
    _tao_environment
  );
}

void
POA_CORBA::_tao_collocated_DynUnion::set_as_default (
    CORBA::Boolean set_as_default,
    CORBA::Environment &_tao_environment
   )
{
  this->servant_->set_as_default (
    set_as_default,
    _tao_environment
  );
}

CORBA_DynAny_ptr
POA_CORBA::_tao_collocated_DynUnion::discriminator (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->discriminator (
    _tao_environment
  );
}

CORBA::TCKind
POA_CORBA::_tao_collocated_DynUnion::discriminator_kind (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->discriminator_kind (
    _tao_environment
  );
}

CORBA_DynAny_ptr
POA_CORBA::_tao_collocated_DynUnion::member (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->member (
    _tao_environment
  );
}

char *
POA_CORBA::_tao_collocated_DynUnion::member_name (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->member_name (
    _tao_environment
  );
}

void
POA_CORBA::_tao_collocated_DynUnion::member_name (
    const char * member_name,
    CORBA::Environment &_tao_environment
   )
{
  this->servant_->member_name (
    member_name,
    _tao_environment
  );
}

CORBA::TCKind
POA_CORBA::_tao_collocated_DynUnion::member_kind (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->member_kind (
    _tao_environment
  );
}


CORBA_DynUnion*
POA_CORBA::DynUnion::_this (CORBA_Environment &TAO_IN_ENV)
{
  TAO_Stub *stub = this->_create_stub (TAO_IN_ENV);

  if (TAO_IN_ENV.exception () != 0)
    return 0;

  return new POA_CORBA::_tao_collocated_DynUnion (this,
                                             stub);
}

// constructor
POA_CORBA::DynSequence::DynSequence (void)
{
}

// copy ctor
POA_CORBA::DynSequence::DynSequence (POA_CORBA::DynSequence& rhs)
  : ACE_NESTED_CLASS (POA_CORBA, DynAny (rhs)),
    TAO_Local_ServantBase (rhs)
{}
// destructor
POA_CORBA::DynSequence::~DynSequence (void)
{
}
CORBA::Boolean
POA_CORBA::DynSequence::_is_a (
    const char* value,
    CORBA::Environment &_tao_environment
  )
{
  if ((!ACE_OS::strcmp ((char *)value, "IDL:/CORBA_DynSequence:1.0"))
      || (!ACE_OS::strcmp ((char *)value, "IDL:/CORBA_DynAny:1.0"))
      || (!ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (_tao_environment))))
      return 1;
    else
      return 0;
}

void*
POA_CORBA::DynSequence::_downcast (
    const char* logical_type_id
  )
{
  if (!ACE_OS::strcmp (logical_type_id,
                       "IDL:/CORBA_DynSequence:1.0"))
    return ACE_static_cast (POA_CORBA::DynSequence_ptr,
                            this);

  if (!ACE_OS::strcmp (logical_type_id,
                       "IDL:/CORBA_DynAny:1.0"))
    return ACE_static_cast (POA_CORBA::DynAny_ptr,
                            this);

  if (!ACE_OS::strcmp (logical_type_id,
                       "IDL:omg.org/CORBA/Object:1.0"))
    return ACE_static_cast(PortableServer::Servant,
                           this);

  return 0;
}

void
POA_CORBA::DynSequence::_dispatch (CORBA::ServerRequest &,
                                   void *,
                                   CORBA::Environment &)
{
}

const char*
POA_CORBA::DynSequence::_interface_repository_id (void) const
{
  return "IDL:/CORBA_DynSequence:1.0";
}

POA_CORBA::_tao_collocated_DynSequence::_tao_collocated_DynSequence (
    POA_CORBA::DynSequence_ptr  servant,
    TAO_Stub *stub
  )
  : CORBA_DynSequence (),
    ACE_NESTED_CLASS (POA_CORBA, _tao_collocated_DynAny (servant,
                                                         stub)),
    CORBA_Object (stub, servant, 1),
    servant_ (servant)
{
}

POA_CORBA::DynSequence_ptr
POA_CORBA::_tao_collocated_DynSequence::_get_servant (void) const
{
  return this->servant_;
}

CORBA::Boolean
POA_CORBA::_tao_collocated_DynSequence::_is_a (
    const char* logical_type_id,
    CORBA::Environment &_tao_environment
  )
{
  return this->servant_->_is_a (
      logical_type_id,
      _tao_environment
    );
}

CORBA::ULong
POA_CORBA::_tao_collocated_DynSequence::length (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->length (
    _tao_environment
  );
}

void
POA_CORBA::_tao_collocated_DynSequence::length (
    CORBA::ULong length,
    CORBA::Environment &_tao_environment
   )
{
  this->servant_->length (
    length,
    _tao_environment
  );
}

CORBA_AnySeq *
POA_CORBA::_tao_collocated_DynSequence::get_elements (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->get_elements (
    _tao_environment
  );
}

void
POA_CORBA::_tao_collocated_DynSequence::set_elements (
    const CORBA_AnySeq & value,
    CORBA::Environment &_tao_environment
   )
{
  this->servant_->set_elements (
    value,
    _tao_environment
  );
}


CORBA_DynSequence*
POA_CORBA::DynSequence::_this (CORBA_Environment &TAO_IN_ENV)
{
  TAO_Stub *stub = this->_create_stub (TAO_IN_ENV);

  if (TAO_IN_ENV.exception () != 0)
    return 0;

  return new POA_CORBA::_tao_collocated_DynSequence (this,
                                                     stub);
}

// constructor
POA_CORBA::DynArray::DynArray (void)
{
}

// copy ctor
POA_CORBA::DynArray::DynArray (POA_CORBA::DynArray& rhs)
  : ACE_NESTED_CLASS (POA_CORBA, DynAny (rhs)),
    TAO_Local_ServantBase (rhs)
{}
// destructor
POA_CORBA::DynArray::~DynArray (void)
{
}
CORBA::Boolean
POA_CORBA::DynArray::_is_a (
    const char* value,
    CORBA::Environment &_tao_environment
  )
{
  if ((!ACE_OS::strcmp ((char *)value, "IDL:/CORBA_DynArray:1.0"))
      || (!ACE_OS::strcmp ((char *)value, "IDL:/CORBA_DynAny:1.0"))
      || (!ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (_tao_environment))))
      return 1;
    else
      return 0;
}

void*
POA_CORBA::DynArray::_downcast (
    const char* logical_type_id
  )
{
  if (!ACE_OS::strcmp (logical_type_id,
                       "IDL:/CORBA_DynArray:1.0"))
    return ACE_static_cast (POA_CORBA::DynArray_ptr,
                            this);

  if (!ACE_OS::strcmp (logical_type_id,
                       "IDL:/CORBA_DynAny:1.0"))
    return ACE_static_cast (POA_CORBA::DynAny_ptr,
                            this);

  if (!ACE_OS::strcmp (logical_type_id,
                       "IDL:omg.org/CORBA/Object:1.0"))
    return ACE_static_cast(PortableServer::Servant,
                           this);

  return 0;
}

void
POA_CORBA::DynArray::_dispatch (CORBA::ServerRequest &,
                                void *,
                                CORBA::Environment &)
{
}

const char*
POA_CORBA::DynArray::_interface_repository_id (void) const
{
  return "IDL:/CORBA_DynArray:1.0";
}

POA_CORBA::_tao_collocated_DynArray::_tao_collocated_DynArray (
    POA_CORBA::DynArray_ptr  servant,
    TAO_Stub *stub
  )
  : CORBA_DynArray (),
    ACE_NESTED_CLASS (POA_CORBA, _tao_collocated_DynAny (servant,
                                                         stub)),
    CORBA_Object (stub, servant, 1),
    servant_ (servant)
{
}

POA_CORBA::DynArray_ptr
POA_CORBA::_tao_collocated_DynArray::_get_servant (void) const
{
  return this->servant_;
}

CORBA::Boolean POA_CORBA::_tao_collocated_DynArray::_is_a (
    const char* logical_type_id,
    CORBA::Environment &_tao_environment
  )
{
  return this->servant_->_is_a (
      logical_type_id,
      _tao_environment
    );
}

CORBA_AnySeq *
POA_CORBA::_tao_collocated_DynArray::get_elements (
    CORBA::Environment &_tao_environment
   )
{
  return this->servant_->get_elements (
    _tao_environment
  );
}

void
POA_CORBA::_tao_collocated_DynArray::set_elements (
    const CORBA_AnySeq & value,
    CORBA::Environment &_tao_environment
   )
{
  this->servant_->set_elements (
    value,
    _tao_environment
  );
}


CORBA_DynArray*
POA_CORBA::DynArray::_this (CORBA_Environment &TAO_IN_ENV)
{
  TAO_Stub *stub = this->_create_stub (TAO_IN_ENV);

  if (TAO_IN_ENV.exception () != 0)
    return 0;

  return new POA_CORBA::_tao_collocated_DynArray (this,
                                                  stub);
}

#endif /* TAO_HAS_MINIMUM_CORBA */

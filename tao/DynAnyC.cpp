/* -*- C++ -*- */
// $Id$
// ======================================================================
//
// = LIBRARY
//    TAO
//
// = FILENAME
//    DynAnyC.cpp
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
// Modified by Jeff Parsons <parsons@cs.wustl.edu>
//
// ======================================================================

#include "tao/DynAnyC.h"

#if (TAO_HAS_MINIMUM_CORBA == 0)

#include "tao/Stub.h"
#include "tao/Servant_Base.h"
#include "tao/varout.h"
#include "tao/POA_CORBA.h"

#if !defined (__ACE_INLINE__)
#include "tao/DynAnyC.i"
#endif /* !defined INLINE */

ACE_RCSID(tao, DynAnyC, "$Id$")

CORBA_DynAny_ptr CORBA_DynAny::_duplicate (CORBA_DynAny_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_incr_refcnt ();

  return obj;
} // end of _duplicate

CORBA_DynAny_ptr CORBA_DynAny::_narrow (CORBA::Object_ptr obj,
                                        CORBA::Environment &ACE_TRY_ENV)
{
  if (CORBA::is_nil (obj))
    return CORBA_DynAny::_nil ();

  if (!obj->_is_a ("IDL:/CORBA_DynAny:1.0", ACE_TRY_ENV))
    return CORBA_DynAny::_nil ();

  void *servant = 0;
  if (!obj->_is_collocated ()
      || !obj->_servant ()
      || (servant = obj->_servant ()->_downcast ("IDL:/CORBA_DynAny:1.0")) == 0)
    ACE_THROW_RETURN (CORBA::MARSHAL (), CORBA_DynAny::_nil ());

  CORBA_DynAny_ptr retval = CORBA_DynAny::_nil ();

  ACE_NEW_RETURN (
      retval,
      POA_CORBA::_tao_collocated_DynAny (
          ACE_reinterpret_cast (POA_CORBA::DynAny_ptr,
                                servant),
          0
        ),
      CORBA_DynAny::_nil ()
    );

  return retval;
}

CORBA_DynAny_ptr CORBA_DynAny::_nil (void)
{
  return (CORBA_DynAny_ptr) NULL;
} // end of _nil

// default constructor
CORBA_DynAny::Invalid::Invalid (void)
  : CORBA_UserException (CORBA_DynAny::_tc_Invalid)
{
}

// destructor - all members are of self managing types
CORBA_DynAny::Invalid::~Invalid (void)
{
}

// copy constructor
CORBA_DynAny::Invalid::Invalid (const CORBA_DynAny::Invalid &_tao_excp)
  : CORBA_UserException (_tao_excp._type ())
{
  }

// assignment operator
CORBA_DynAny::Invalid&
CORBA_DynAny::Invalid::operator= (const CORBA_DynAny::Invalid &_tao_excp)
{
  this->CORBA_UserException::operator= (_tao_excp);
  return *this;
}

// narrow
CORBA_DynAny::Invalid *
CORBA_DynAny::Invalid::_narrow (CORBA::Exception *exc)
{
  if (!ACE_OS::strcmp ("IDL:/CORBA_DynAny/Invalid:1.0",
                       exc->_id ())) // same type
    return ACE_dynamic_cast (CORBA_DynAny::Invalid *,
                             exc);
  else
    return 0;
}


void CORBA_DynAny::Invalid::_raise ()
{
  TAO_RAISE(*this);
}

void CORBA_DynAny::Invalid::_tao_encode (TAO_OutputCDR &cdr,
                                         CORBA::Environment &ACE_TRY_ENV) const
{
  if (cdr << this->_id ())
    return;
  ACE_THROW (CORBA::MARSHAL ());
}

void CORBA_DynAny::Invalid::_tao_decode (TAO_InputCDR &,
                                         CORBA::Environment &)
{
}

// TAO extension - the _alloc method
CORBA::Exception *CORBA_DynAny::Invalid::_alloc (void)
{
  CORBA::Exception *retval = 0;

  ACE_NEW_RETURN (retval,
                  CORBA_DynAny::Invalid,
                  0);

  return retval;
}

static const CORBA::Long _oc_CORBA_DynAny_Invalid[] =
{
  TAO_ENCAP_BYTE_ORDER,     // byte order
  24,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x2f44796e),
  ACE_NTOHL (0x416e792f),
  ACE_NTOHL (0x496e7661),
  ACE_NTOHL (0x6c69643a),
  ACE_NTOHL (0x312e3000),   // repository ID =
                            // IDL:/CORBA_DynAny/Invalid:1.0
  8,
  ACE_NTOHL (0x496e7661),
  ACE_NTOHL (0x6c696400),   // name = Invalid
  0,                        // member count
};
static CORBA::TypeCode _tc_TAO_tc_CORBA_DynAny_Invalid (
    CORBA::tk_except,
    sizeof (_oc_CORBA_DynAny_Invalid),
    (char *) &_oc_CORBA_DynAny_Invalid,
    0,
    sizeof (CORBA_DynAny::Invalid)
  );

CORBA::TypeCode_ptr CORBA_DynAny::_tc_Invalid =
  &_tc_TAO_tc_CORBA_DynAny_Invalid;

// default constructor
CORBA_DynAny::InvalidValue::InvalidValue (void)
  : CORBA_UserException (CORBA_DynAny::_tc_InvalidValue)
{
}

// destructor - all members are of self managing types
CORBA_DynAny::InvalidValue::~InvalidValue (void)
{
}

// copy constructor
CORBA_DynAny::InvalidValue::InvalidValue (
    const CORBA_DynAny::InvalidValue &_tao_excp
  )
  : CORBA_UserException (_tao_excp._type ())
{
}

// assignment operator
CORBA_DynAny::InvalidValue&
CORBA_DynAny::InvalidValue::operator= (
    const CORBA_DynAny::InvalidValue &_tao_excp
  )
{
  this->CORBA_UserException::operator= (_tao_excp);
  return *this;
}

// narrow
CORBA_DynAny::InvalidValue *
CORBA_DynAny::InvalidValue::_narrow (CORBA::Exception *exc)
{
  if (!ACE_OS::strcmp ("IDL:/CORBA_DynAny/InvalidValue:1.0",
                       exc->_id ())) // same type
    return ACE_dynamic_cast (CORBA_DynAny::InvalidValue *,
                             exc);
  else
    return 0;
}


void CORBA_DynAny::InvalidValue::_raise ()
{
  TAO_RAISE(*this);
}

void CORBA_DynAny::InvalidValue::_tao_encode (TAO_OutputCDR &cdr,
                                              CORBA::Environment &ACE_TRY_ENV) const
{
  if (cdr << this->_id ())
    return;
  ACE_THROW (CORBA::MARSHAL ());
}

void CORBA_DynAny::InvalidValue::_tao_decode (TAO_InputCDR &,
                                              CORBA::Environment &)
{
}

// TAO extension - the _alloc method
CORBA::Exception *CORBA_DynAny::InvalidValue::_alloc (void)
{
  CORBA::Exception *retval = 0;

  ACE_NEW_RETURN (retval,
                  CORBA_DynAny::InvalidValue,
                  0);

  return retval;
}

static const CORBA::Long _oc_CORBA_DynAny_InvalidValue[] =
{
  TAO_ENCAP_BYTE_ORDER,   // byte order
  29,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x2f44796e),
  ACE_NTOHL (0x416e792f),
  ACE_NTOHL (0x496e7661),
  ACE_NTOHL (0x6c696456),
  ACE_NTOHL (0x616c7565),
  ACE_NTOHL (0x3a312e30),
  ACE_NTOHL (0xfdfdfd),   // repository ID =
                          // IDL:/CORBA_DynAny/InvalidValue:1.0
  13,
  ACE_NTOHL (0x496e7661),
  ACE_NTOHL (0x6c696456),
  ACE_NTOHL (0x616c7565),
  ACE_NTOHL (0xfdfdfd),   // name = InvalidValue
  0,                      // member count
};
static CORBA::TypeCode _tc_TAO_tc_CORBA_DynAny_InvalidValue (
    CORBA::tk_except,
    sizeof (_oc_CORBA_DynAny_InvalidValue),
    (char *) &_oc_CORBA_DynAny_InvalidValue,
    0,
    sizeof (CORBA_DynAny::InvalidValue)
  );

CORBA::TypeCode_ptr CORBA_DynAny::_tc_InvalidValue =
  &_tc_TAO_tc_CORBA_DynAny_InvalidValue;

// default constructor
CORBA_DynAny::TypeMismatch::TypeMismatch (void)
  : CORBA_UserException (CORBA_DynAny::_tc_TypeMismatch)
{
}

// destructor - all members are of self managing types
CORBA_DynAny::TypeMismatch::~TypeMismatch (void)
{
}

// copy constructor
CORBA_DynAny::TypeMismatch::TypeMismatch (
    const CORBA_DynAny::TypeMismatch &_tao_excp
  )
  : CORBA_UserException (_tao_excp._type ())
{
}

// assignment operator
CORBA_DynAny::TypeMismatch&
CORBA_DynAny::TypeMismatch::operator= (
    const CORBA_DynAny::TypeMismatch &_tao_excp
  )
{
  this->CORBA_UserException::operator= (_tao_excp);
  return *this;
}

// narrow
CORBA_DynAny::TypeMismatch *
CORBA_DynAny::TypeMismatch::_narrow (CORBA::Exception *exc)
{
  if (!ACE_OS::strcmp ("IDL:/CORBA_DynAny/TypeMismatch:1.0",
                       exc->_id ())) // same type
    return ACE_dynamic_cast (CORBA_DynAny::TypeMismatch *,
                             exc);
  else
    return 0;
}


void CORBA_DynAny::TypeMismatch::_raise ()
{
  TAO_RAISE(*this);
}

void CORBA_DynAny::TypeMismatch::_tao_encode (TAO_OutputCDR &cdr,
                                              CORBA::Environment &ACE_TRY_ENV) const
{
  if (cdr << this->_id ())
    return;
  ACE_THROW (CORBA::MARSHAL ());
}

void CORBA_DynAny::TypeMismatch::_tao_decode (TAO_InputCDR &,
                                              CORBA::Environment &)
{
}

// TAO extension - the _alloc method
CORBA::Exception *CORBA_DynAny::TypeMismatch::_alloc (void)
{
  CORBA::Exception *retval = 0;

  ACE_NEW_RETURN (retval,
                  CORBA_DynAny::TypeMismatch,
                  0);

  return retval;
}

static const CORBA::Long _oc_CORBA_DynAny_TypeMismatch[] =
{
  TAO_ENCAP_BYTE_ORDER,     // byte order
  29,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x2f44796e),
  ACE_NTOHL (0x416e792f),
  ACE_NTOHL (0x54797065),
  ACE_NTOHL (0x4d69736d),
  ACE_NTOHL (0x61746368),
  ACE_NTOHL (0x3a312e30),
  ACE_NTOHL (0xfdfdfd),     // repository ID =
                            // IDL:/CORBA_DynAny/TypeMismatch:1.0
  13, ACE_NTOHL (0x54797065),
  ACE_NTOHL (0x4d69736d),
  ACE_NTOHL (0x61746368),
  ACE_NTOHL (0xfdfdfd),     // name = TypeMismatch
  0,                        // member count
};
static CORBA::TypeCode _tc_TAO_tc_CORBA_DynAny_TypeMismatch (
    CORBA::tk_except,
    sizeof (_oc_CORBA_DynAny_TypeMismatch),
    (char *) &_oc_CORBA_DynAny_TypeMismatch,
    0,
    sizeof (CORBA_DynAny::TypeMismatch)
  );

CORBA::TypeCode_ptr CORBA_DynAny::_tc_TypeMismatch =
  &_tc_TAO_tc_CORBA_DynAny_TypeMismatch;

// default constructor
CORBA_DynAny::InvalidSeq::InvalidSeq (void)
  : CORBA_UserException (CORBA_DynAny::_tc_InvalidSeq)
{
}

// destructor - all members are of self managing types
CORBA_DynAny::InvalidSeq::~InvalidSeq (void)
{
}

// copy constructor
CORBA_DynAny::InvalidSeq::InvalidSeq (
    const CORBA_DynAny::InvalidSeq &_tao_excp
  )
  : CORBA_UserException (_tao_excp._type ())
{
}

// assignment operator
CORBA_DynAny::InvalidSeq&
CORBA_DynAny::InvalidSeq::operator= (
    const CORBA_DynAny::InvalidSeq &_tao_excp
  )
{
  this->CORBA_UserException::operator= (_tao_excp);
  return *this;
}

// narrow
CORBA_DynAny::InvalidSeq *
CORBA_DynAny::InvalidSeq::_narrow (CORBA::Exception *exc)
{
  if (!ACE_OS::strcmp ("IDL:/CORBA_DynAny/InvalidSeq:1.0",
                       exc->_id ())) // same type
    return ACE_dynamic_cast (CORBA_DynAny::InvalidSeq *,
                             exc);
  else
    return 0;
}


void CORBA_DynAny::InvalidSeq::_raise ()
{
  TAO_RAISE(*this);
}

void CORBA_DynAny::InvalidSeq::_tao_encode (TAO_OutputCDR &cdr,
                                            CORBA::Environment &ACE_TRY_ENV) const
{
  if (cdr << this->_id ())
    return;
  ACE_THROW (CORBA::MARSHAL ());
}

void CORBA_DynAny::InvalidSeq::_tao_decode (TAO_InputCDR &,
                                            CORBA::Environment &)
{
}

// TAO extension - the _alloc method
CORBA::Exception *CORBA_DynAny::InvalidSeq::_alloc (void)
{
  CORBA::Exception *retval = 0;

  ACE_NEW_RETURN (retval,
                  CORBA_DynAny::InvalidSeq,
                  0);

  return retval;
}

static const CORBA::Long _oc_CORBA_DynAny_InvalidSeq[] =
{
  TAO_ENCAP_BYTE_ORDER,     // byte order
  27,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x2f44796e),
  ACE_NTOHL (0x416e792f),
  ACE_NTOHL (0x496e7661),
  ACE_NTOHL (0x6c696453),
  ACE_NTOHL (0x65713a31),
  ACE_NTOHL (0x2e3000fd),   // repository ID =
                            // IDL:/CORBA_DynAny/InvalidSeq:1.0
  11,
  ACE_NTOHL (0x496e7661),
  ACE_NTOHL (0x6c696453),
  ACE_NTOHL (0x657100fd),   // name = InvalidSeq
  0,                        // member count
};
static CORBA::TypeCode _tc_TAO_tc_CORBA_DynAny_InvalidSeq (
    CORBA::tk_except,
    sizeof (_oc_CORBA_DynAny_InvalidSeq),
    (char *) &_oc_CORBA_DynAny_InvalidSeq,
    0,
    sizeof (CORBA_DynAny::InvalidSeq)
  );

CORBA::TypeCode_ptr CORBA_DynAny::_tc_InvalidSeq =
  &_tc_TAO_tc_CORBA_DynAny_InvalidSeq;

CORBA::TypeCode_ptr
CORBA_DynAny::type (CORBA::Environment &)
{
  return 0;
}

void
CORBA_DynAny::assign (CORBA_DynAny_ptr,
                      CORBA::Environment &)
{
}

CORBA_DynAny_ptr
CORBA_DynAny::copy (CORBA::Environment &)
{
  return 0;
}

void
CORBA_DynAny::destroy (CORBA::Environment &)
{
}

void
CORBA_DynAny::from_any (const CORBA_Any &,
                        CORBA::Environment &)
{
}

CORBA::Any_ptr
CORBA_DynAny::to_any (CORBA::Environment &)
{
  return 0;
}

CORBA_DynAny_ptr
CORBA_DynAny::current_component (CORBA::Environment &)
{
  return 0;
}

CORBA::Boolean
CORBA_DynAny::next (CORBA::Environment &)
{
  return 0;
}

CORBA::Boolean
CORBA_DynAny::seek (CORBA::Long,
                    CORBA::Environment &)
{
  return 0;
}

void
CORBA_DynAny::rewind (CORBA::Environment &)
{
}

void
CORBA_DynAny::insert_boolean (CORBA::Boolean,
                              CORBA::Environment &)
{
}

void
CORBA_DynAny::insert_octet (CORBA::Octet,
                            CORBA::Environment &)
{
}

void
CORBA_DynAny::insert_char (CORBA::Char,
                           CORBA::Environment &)
{
}

void
CORBA_DynAny::insert_short (CORBA::Short,
                            CORBA::Environment &)
{
}

void
CORBA_DynAny::insert_ushort (CORBA::UShort,
                             CORBA::Environment &)
{
}

void
CORBA_DynAny::insert_long (CORBA::Long,
                           CORBA::Environment &)
{
}

void
CORBA_DynAny::insert_ulong (CORBA::ULong,
                            CORBA::Environment &)
{
}

void
CORBA_DynAny::insert_float (CORBA::Float,
                            CORBA::Environment &)
{
}

void
CORBA_DynAny::insert_double (CORBA::Double,
                             CORBA::Environment &)
{
}

void
CORBA_DynAny::insert_string (const char *,
                             CORBA::Environment &)
{
}

void
CORBA_DynAny::insert_reference (CORBA::Object_ptr,
                                CORBA::Environment &)
{
}

void
CORBA_DynAny::insert_typecode (CORBA::TypeCode_ptr,
                               CORBA::Environment &)
{
}

void
CORBA_DynAny::insert_longlong (CORBA::LongLong,
                               CORBA::Environment &)
{
}

void
CORBA_DynAny::insert_ulonglong (CORBA::ULongLong,
                                CORBA::Environment &)
{
}

void
CORBA_DynAny::insert_wchar (CORBA::WChar,
                            CORBA::Environment &)
{
}

void
CORBA_DynAny::insert_any (const CORBA::Any &,
                          CORBA::Environment &)
{
}

CORBA::Boolean
CORBA_DynAny::get_boolean (CORBA::Environment &)
{
  return 0;
}

CORBA::Octet
CORBA_DynAny::get_octet (CORBA::Environment &)
{
  return 0;
}

CORBA::Char
CORBA_DynAny::get_char (CORBA::Environment &)
{
  return 0;
}

CORBA::Short
CORBA_DynAny::get_short (CORBA::Environment &)
{
  return 0;
}

CORBA::UShort
CORBA_DynAny::get_ushort (CORBA::Environment &)
{
  return 0;
}

CORBA::Long
CORBA_DynAny::get_long (CORBA::Environment &)
{
  return 0;
}

CORBA::ULong
CORBA_DynAny::get_ulong (CORBA::Environment &)
{
  return 0;
}

CORBA::Float
CORBA_DynAny::get_float (CORBA::Environment &)
{
  return 0;
}

CORBA::Double
CORBA_DynAny::get_double (CORBA::Environment &)
{
  return 0;
}

char *
CORBA_DynAny::get_string (CORBA::Environment &)
{
  return 0;
}

CORBA::Object_ptr
CORBA_DynAny::get_reference (CORBA::Environment &)
{
  return 0;
}

CORBA::TypeCode_ptr
CORBA_DynAny::get_typecode (CORBA::Environment &)
{
  return 0;
}

CORBA::LongLong
CORBA_DynAny::get_longlong (CORBA::Environment &)
{
#if defined (ACE_LACKS_LONGLONG_T)
  CORBA::LongLong tmp = {0, 0};
  return tmp;
#else  /* ! ACE_LACKS_LONGLONG_T */
  return 0;
#endif /* ! ACE_LACKS_LONGLONG_T */
}

CORBA::ULongLong
CORBA_DynAny::get_ulonglong (CORBA::Environment &)
{
  return 0;
}

CORBA::WChar
CORBA_DynAny::get_wchar (CORBA::Environment &)
{
  return 0;
}

CORBA::Any_ptr
CORBA_DynAny::get_any (CORBA::Environment &)
{
   return 0;
}

CORBA::Boolean CORBA_DynAny::_is_a (const CORBA::Char *value,
                                    CORBA::Environment &env)
{
  if ((!ACE_OS::strcmp ((char *)value,
                        "IDL:/CORBA_DynAny:1.0"))
      || (!ACE_OS::strcmp ((char *)value,
                           CORBA::_tc_Object->id (env))))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value,
                                      env); // remote call
}

const char* CORBA_DynAny::_interface_repository_id (void) const
{
  return "IDL:/CORBA_DynAny:1.0";
}

static const CORBA::Long _oc_CORBA_DynAny[] =
{
  TAO_ENCAP_BYTE_ORDER,     // byte order
  16,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x2f44796e),
  ACE_NTOHL (0x416e793a),
  ACE_NTOHL (0x312e3000),   // repository ID = IDL:/CORBA_DynAny:1.0
  7,
  ACE_NTOHL (0x44796e41),
  ACE_NTOHL (0x6e7900fd),   // name = CORBA_DynAny,
};
static CORBA::TypeCode _tc_TAO_tc_CORBA_DynAny (
    CORBA::tk_objref,
    sizeof (_oc_CORBA_DynAny),
    (char *) &_oc_CORBA_DynAny,
    0,
    sizeof (CORBA_DynAny)
  );

CORBA::TypeCode_ptr _tc_CORBA_DynAny = &_tc_TAO_tc_CORBA_DynAny;

CORBA_DynEnum_ptr CORBA_DynEnum::_duplicate (CORBA_DynEnum_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_incr_refcnt ();

  return obj;
} // end of _duplicate

CORBA_DynEnum_ptr CORBA_DynEnum::_narrow (CORBA::Object_ptr obj,
                                          CORBA::Environment &ACE_TRY_ENV)
{
  if (CORBA::is_nil (obj))
    return CORBA_DynEnum::_nil ();

  if (!obj->_is_a ("IDL:/CORBA_DynEnum:1.0", ACE_TRY_ENV))
    return CORBA_DynEnum::_nil ();

  void *servant = 0;
  if (!obj->_is_collocated ()
      || !obj->_servant ()
      || (servant = obj->_servant ()->_downcast ("IDL:/CORBA_DynEnum:1.0")) == 0)
    ACE_THROW_RETURN (CORBA::MARSHAL (), CORBA_DynEnum::_nil ());

  CORBA_DynEnum_ptr retval = CORBA_DynEnum::_nil ();

  ACE_NEW_RETURN (
      retval,
      POA_CORBA::_tao_collocated_DynEnum (
          ACE_reinterpret_cast (POA_CORBA::DynEnum_ptr,
                                servant),
          0
        ),
      CORBA_DynEnum::_nil ()
    );

  return retval;
}

CORBA_DynEnum_ptr CORBA_DynEnum::_nil (void)
{
  return (CORBA_DynEnum_ptr) NULL;
} // end of _nil

char*
CORBA_DynEnum::value_as_string (CORBA::Environment &)
{
  return 0;
}

void
CORBA_DynEnum::value_as_string (const char*,
                                CORBA::Environment &)
{
}

CORBA::ULong
CORBA_DynEnum::value_as_ulong (CORBA::Environment &)
{
  return 0;
}

void
CORBA_DynEnum::value_as_ulong (CORBA::ULong,
                               CORBA::Environment &)
{
}

CORBA::Boolean CORBA_DynEnum::_is_a (const CORBA::Char *value,
                                     CORBA::Environment &env)
{
  if ((!ACE_OS::strcmp ((char *)value,
                        "IDL:/CORBA_DynEnum:1.0"))
      || (!ACE_OS::strcmp ((char *)value,
                           "IDL:/CORBA_DynAny:1.0"))
      || (!ACE_OS::strcmp ((char *)value,
                           CORBA::_tc_Object->id (env))))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value,
                                      env); // remote call
}

const char* CORBA_DynEnum::_interface_repository_id (void) const
{
  return "IDL:/CORBA_DynEnum:1.0";
}

static const CORBA::Long _oc_CORBA_DynEnum[] =
{
  TAO_ENCAP_BYTE_ORDER,     // byte order
  17,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x2f44796e),
  ACE_NTOHL (0x456e756d),
  ACE_NTOHL (0x3a312e30),
  ACE_NTOHL (0xfdfdfd),     // repository ID = IDL:/CORBA_DynEnum:1.0
  8,
  ACE_NTOHL (0x44796e45),
  ACE_NTOHL (0x6e756d00),   // name = CORBA_DynEnum,
};
static CORBA::TypeCode _tc_TAO_tc_CORBA_DynEnum (CORBA::tk_objref,
                                              sizeof (_oc_CORBA_DynEnum),
                                              (char *) &_oc_CORBA_DynEnum,
                                              0,
                                              sizeof (CORBA_DynEnum));

CORBA::TypeCode_ptr _tc_CORBA_DynEnum = &_tc_TAO_tc_CORBA_DynEnum;

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  
#if !defined (__TAO_UNBOUNDED_SEQUENCE_CORBA_NAMEVALUEPAIRSEQ_CS_)
#define __TAO_UNBOUNDED_SEQUENCE_CORBA_NAMEVALUEPAIRSEQ_CS_

  void
  _TAO_Unbounded_Sequence_CORBA_NameValuePairSeq::_allocate_buffer (CORBA::ULong length)
  {
    CORBA::NameValuePair* tmp = 0;
    tmp = _TAO_Unbounded_Sequence_CORBA_NameValuePairSeq::allocbuf (length);
    
    if (this->buffer_ != 0)
    {
      CORBA::NameValuePair *old = ACE_reinterpret_cast (CORBA::NameValuePair *,this->buffer_);
      
      for (CORBA::ULong i = 0; i < this->length_; ++i)
        tmp[i] = old[i];
      
      if (this->release_)
        _TAO_Unbounded_Sequence_CORBA_NameValuePairSeq::freebuf (old);
      
    }
    this->buffer_ = tmp;
  }
  
  void
  _TAO_Unbounded_Sequence_CORBA_NameValuePairSeq::_deallocate_buffer (void)
  {
    if (this->buffer_ == 0 || this->release_ == 0)
      return;
    
    CORBA::NameValuePair *tmp = ACE_reinterpret_cast (CORBA::NameValuePair *,this->buffer_);
    
    _TAO_Unbounded_Sequence_CORBA_NameValuePairSeq::freebuf (tmp);
    this->buffer_ = 0;
  } 
  
  _TAO_Unbounded_Sequence_CORBA_NameValuePairSeq::~_TAO_Unbounded_Sequence_CORBA_NameValuePairSeq (void) // Dtor.
  {
    this->_deallocate_buffer ();
  }
  
  
#endif /* end #if !defined */


#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 

#if !defined (_CORBA_NAME_VALUE_PAIR_SEQ_CS_)
#define _CORBA_NAME_VALUE_PAIR_SEQ_CS_

// *************************************************************
// CORBA_NameValuePairSeq
// *************************************************************

CORBA_NameValuePairSeq::CORBA_NameValuePairSeq (void)
{}
CORBA_NameValuePairSeq::CORBA_NameValuePairSeq (CORBA::ULong max) // uses max size
  :
#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION) \
             || defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA) \
             || !defined (ACE_HAS_TEMPLATE_SPECIALIZATION)
  _TAO_Unbounded_Sequence_CORBA_NameValuePairSeq
#else /* AHETI */
  TAO_Unbounded_Sequence<CORBA::NameValuePair>
#endif /* AHETI */
 (max)
{}
CORBA_NameValuePairSeq::CORBA_NameValuePairSeq (CORBA::ULong max,
                                    CORBA::ULong length,
                                    CORBA::NameValuePair *buffer,
                                    CORBA::Boolean release)
  :
#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION) \
             || defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA) \
             || !defined (ACE_HAS_TEMPLATE_SPECIALIZATION)
  _TAO_Unbounded_Sequence_CORBA_NameValuePairSeq
#else /* AHETI */
  TAO_Unbounded_Sequence<CORBA::NameValuePair>
#endif /* AHETI */
 (max, length, buffer, release)
{}
CORBA_NameValuePairSeq::CORBA_NameValuePairSeq (
    const CORBA_NameValuePairSeq &seq
  ) // copy ctor
  :
#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION) \
             || defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA) \
             || !defined (ACE_HAS_TEMPLATE_SPECIALIZATION)
  _TAO_Unbounded_Sequence_CORBA_NameValuePairSeq
#else /* AHETI */
  TAO_Unbounded_Sequence< CORBA::NameValuePair>
#endif /* AHETI */
 (seq)
{}
CORBA_NameValuePairSeq::~CORBA_NameValuePairSeq (void) // dtor
{}


#endif /* end #if !defined */

CORBA_DynStruct_ptr CORBA_DynStruct::_duplicate (CORBA_DynStruct_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_incr_refcnt ();

  return obj;
} // end of _duplicate

CORBA_DynStruct_ptr CORBA_DynStruct::_narrow (CORBA::Object_ptr obj,
                                              CORBA::Environment &ACE_TRY_ENV)
{
  if (CORBA::is_nil (obj))
    return CORBA_DynStruct::_nil ();

  if (!obj->_is_a ("IDL:/CORBA_DynStruct:1.0", ACE_TRY_ENV))
    return CORBA_DynStruct::_nil ();

  void *servant = 0;
  if (!obj->_is_collocated ()
      || !obj->_servant ()
      || (servant = obj->_servant ()->_downcast ("IDL:/CORBA_DynStruct:1.0")) == 0)
    ACE_THROW_RETURN (CORBA::MARSHAL (),  CORBA_DynStruct::_nil ());

  CORBA_DynStruct_ptr retval = CORBA_DynStruct::_nil ();

  ACE_NEW_RETURN (
      retval,
      POA_CORBA::_tao_collocated_DynStruct (
          ACE_reinterpret_cast (POA_CORBA::DynStruct_ptr,
                                servant),
          0
        ),
      CORBA_DynStruct::_nil ()
    );

  return retval;
}

CORBA_DynStruct_ptr CORBA_DynStruct::_nil (void)
{
  return (CORBA_DynStruct_ptr) NULL;
} // end of _nil

CORBA::FieldName
CORBA_DynStruct::current_member_name (CORBA::Environment  &)
{
  return 0;
}

CORBA::TCKind
CORBA_DynStruct::current_member_kind (CORBA::Environment &)
{
  return CORBA::tk_null;
}

CORBA_NameValuePairSeq*
CORBA_DynStruct::get_members (CORBA::Environment &)
{
  return 0;
}

void
CORBA_DynStruct::set_members (const CORBA_NameValuePairSeq &,
                              CORBA::Environment &)
{
}

CORBA::Boolean CORBA_DynStruct::_is_a (const CORBA::Char *value,
                                       CORBA::Environment &env)
{
  if ((!ACE_OS::strcmp ((char *)value,
                        "IDL:/CORBA_DynStruct:1.0"))
      || (!ACE_OS::strcmp ((char *)value,
                           "IDL:/CORBA_DynAny:1.0"))
      || (!ACE_OS::strcmp ((char *)value,
                           CORBA::_tc_Object->id (env))))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value,
                                      env); // remote call
}

const char* CORBA_DynStruct::_interface_repository_id (void) const
{
  return "IDL:/CORBA_DynStruct:1.0";
}

static const CORBA::Long _oc_CORBA_DynStruct[] =
{
  TAO_ENCAP_BYTE_ORDER,     // byte order
  19,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x2f44796e),
  ACE_NTOHL (0x53747275),
  ACE_NTOHL (0x63743a31),
  ACE_NTOHL (0x2e3000fd),   // repository ID = IDL:/CORBA_DynStruct:1.0
  10,
  ACE_NTOHL (0x44796e53),
  ACE_NTOHL (0x74727563),
  ACE_NTOHL (0x7400fdfd),   // name = CORBA_DynStruct,
};

static CORBA::TypeCode _tc_TAO_tc_CORBA_DynStruct (
    CORBA::tk_objref,
    sizeof (_oc_CORBA_DynStruct),
    (char *) &_oc_CORBA_DynStruct,
    0,
    sizeof (CORBA_DynStruct));

CORBA::TypeCode_ptr _tc_CORBA_DynStruct = &_tc_TAO_tc_CORBA_DynStruct;

CORBA_DynUnion_ptr CORBA_DynUnion::_duplicate (CORBA_DynUnion_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_incr_refcnt ();

  return obj;
} // end of _duplicate

CORBA_DynUnion_ptr CORBA_DynUnion::_narrow (CORBA::Object_ptr obj,
                                            CORBA::Environment &ACE_TRY_ENV)
{
  if (CORBA::is_nil (obj))
    return CORBA_DynUnion::_nil ();

  if (!obj->_is_a ("IDL:/CORBA_DynUnion:1.0",
                   ACE_TRY_ENV))
    return CORBA_DynUnion::_nil ();

  void *servant = 0;
  if (!obj->_is_collocated ()
      || !obj->_servant ()
      || (servant = obj->_servant ()->_downcast ("IDL:/CORBA_DynUnion:1.0")) == 0)
    ACE_THROW_RETURN (CORBA::MARSHAL (), CORBA_DynUnion::_nil ());

  CORBA_DynUnion_ptr retval = CORBA_DynUnion::_nil ();

  ACE_NEW_RETURN (
      retval,
      POA_CORBA::_tao_collocated_DynUnion (
          ACE_reinterpret_cast (POA_CORBA::DynUnion_ptr,
                                servant),
          0
        ),
      CORBA_DynUnion::_nil ()
    );

  return retval;
}

CORBA_DynUnion_ptr CORBA_DynUnion::_nil (void)
{
  return (CORBA_DynUnion_ptr) NULL;
} // end of _nil

CORBA::Boolean
CORBA_DynUnion::set_as_default (CORBA::Environment &)
{
  return 0;
}

void
CORBA_DynUnion::set_as_default (CORBA::Boolean,
                                CORBA::Environment &)
{
}

CORBA_DynAny_ptr
CORBA_DynUnion::discriminator (CORBA::Environment &)
{
  return 0;
}

CORBA::TCKind
CORBA_DynUnion::discriminator_kind (CORBA::Environment &)
{
  return CORBA::tk_null;
}

CORBA_DynAny_ptr
CORBA_DynUnion::member (CORBA::Environment &)
{
  return 0;
}

char*
CORBA_DynUnion::member_name (CORBA::Environment &)
{
  return 0;
}

void
CORBA_DynUnion::member_name (const char*,
                             CORBA::Environment &)
{
}


CORBA::TCKind
CORBA_DynUnion::member_kind (CORBA::Environment &)
{
  return CORBA::tk_null;
}

CORBA::Boolean CORBA_DynUnion::_is_a (const CORBA::Char *value,
                                      CORBA::Environment &env)
{
  if ((!ACE_OS::strcmp ((char *)value,
                        "IDL:/CORBA_DynUnion:1.0"))
      || (!ACE_OS::strcmp ((char *)value,
                           "IDL:/CORBA_DynAny:1.0"))
      || (!ACE_OS::strcmp ((char *)value,
                           CORBA::_tc_Object->id (env))))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value,
                                      env); // remote call
}

const char* CORBA_DynUnion::_interface_repository_id (void) const
{
  return "IDL:/CORBA_DynUnion:1.0";
}

static const CORBA::Long _oc_CORBA_DynUnion[] =
{
  TAO_ENCAP_BYTE_ORDER,     // byte order
  18,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x2f44796e),
  ACE_NTOHL (0x556e696f),
  ACE_NTOHL (0x6e3a312e),
  ACE_NTOHL (0x3000fdfd),   // repository ID = IDL:/CORBA_DynUnion:1.0
  9,
  ACE_NTOHL (0x44796e55),
  ACE_NTOHL (0x6e696f6e),
  ACE_NTOHL (0xfdfdfd),     // name = CORBA_DynUnion,
};

static CORBA::TypeCode _tc_TAO_tc_CORBA_DynUnion (
    CORBA::tk_objref,
    sizeof (_oc_CORBA_DynUnion),
    (char *) &_oc_CORBA_DynUnion,
    0,
    sizeof (CORBA_DynUnion));

CORBA::TypeCode_ptr _tc_CORBA_DynUnion = &_tc_TAO_tc_CORBA_DynUnion;


#if !defined (_CORBA_ANYSEQ_CS_)
#define _CORBA_ANYSEQ_CS_

// *************************************************************
// CORBA_AnySeq
// *************************************************************

CORBA_AnySeq::CORBA_AnySeq (void)
{}
CORBA_AnySeq::CORBA_AnySeq (CORBA::ULong max) // uses max size
  :
#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION) \
       || defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA) \
       || !defined (ACE_HAS_TEMPLATE_SPECIALIZATION)
  _TAO_Unbounded_Sequence_CORBA_AnySeq
#else /* AHETI */
  TAO_Unbounded_Sequence<CORBA::Any>
#endif /* AHETI */
 (max)
{}
CORBA_AnySeq::CORBA_AnySeq (CORBA::ULong max,
                CORBA::ULong length,
                CORBA::Any *buffer,
                CORBA::Boolean release)
  :
#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION) \
             || defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA) \
             || !defined (ACE_HAS_TEMPLATE_SPECIALIZATION)
  _TAO_Unbounded_Sequence_CORBA_AnySeq
#else /* AHETI */
  TAO_Unbounded_Sequence<CORBA::Any>
#endif /* AHETI */
 (max, length, buffer, release)
{}
CORBA_AnySeq::CORBA_AnySeq (const CORBA_AnySeq &seq) // copy ctor
  :
#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION) \
             || defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA) \
             || !defined (ACE_HAS_TEMPLATE_SPECIALIZATION)
  _TAO_Unbounded_Sequence_CORBA_AnySeq
#else /* AHETI */
  TAO_Unbounded_Sequence<CORBA::Any>
#endif /* AHETI */
 (seq)
{}
CORBA_AnySeq::~CORBA_AnySeq (void) // dtor
{}


#endif /* end #if !defined */

CORBA_DynSequence_ptr CORBA_DynSequence::_duplicate (
    CORBA_DynSequence_ptr obj
  )
{
  if (!CORBA::is_nil (obj))
    obj->_incr_refcnt ();

  return obj;
} // end of _duplicate

CORBA_DynSequence_ptr CORBA_DynSequence::_narrow (CORBA::Object_ptr obj,
                                                  CORBA::Environment &ACE_TRY_ENV)
{
  if (CORBA::is_nil (obj))
    return CORBA_DynSequence::_nil ();

  if (!obj->_is_a ("IDL:/CORBA_DynSequence:1.0",
                   ACE_TRY_ENV))
    return CORBA_DynSequence::_nil ();

  void *servant = 0;
  if (!obj->_is_collocated ()
      || !obj->_servant ()
      || (servant = obj->_servant ()->_downcast ("IDL:/CORBA_DynSequence:1.0")) == 0)
    ACE_THROW_RETURN (CORBA::MARSHAL (), CORBA_DynSequence::_nil ());

  CORBA_DynSequence_ptr retval = CORBA_DynSequence::_nil ();

  ACE_NEW_RETURN (
      retval,
      POA_CORBA::_tao_collocated_DynSequence (
          ACE_reinterpret_cast (POA_CORBA::DynSequence_ptr,
                                servant),
          0
        ),
      CORBA_DynSequence::_nil ()
    );

  return retval;
}

CORBA_DynSequence_ptr CORBA_DynSequence::_nil (void)
{
  return (CORBA_DynSequence_ptr)NULL;
} // end of _nil

CORBA::ULong
CORBA_DynSequence::length (CORBA::Environment &)
{
  return 0;
}

void
CORBA_DynSequence::length (CORBA::ULong,
                           CORBA::Environment &)
{
}

CORBA_AnySeq *
CORBA_DynSequence::get_elements (CORBA::Environment &)
{
  return 0;
}

void
CORBA_DynSequence::set_elements (const CORBA_AnySeq &,
                                 CORBA::Environment &)
{
}

CORBA::Boolean CORBA_DynSequence::_is_a (const CORBA::Char *value,
                                         CORBA::Environment &env)
{
  if((!ACE_OS::strcmp ((char *)value,
                       "IDL:/CORBA_DynSequence:1.0"))
     || (!ACE_OS::strcmp ((char *) value,
                          "IDL:/CORBA_DynAny:1.0"))
     || (!ACE_OS::strcmp ((char *) value,
                          CORBA::_tc_Object->id (env))))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value,
                                      env); // remote call
}

const char* CORBA_DynSequence::_interface_repository_id (void) const
{
  return "IDL:/CORBA_DynSequence:1.0";
}

static const CORBA::Long _oc_CORBA_DynSequence[] =
{
  TAO_ENCAP_BYTE_ORDER,     // byte order
  21,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x2f44796e),
  ACE_NTOHL (0x53657175),
  ACE_NTOHL (0x656e6365),
  ACE_NTOHL (0x3a312e30),
  ACE_NTOHL (0xfdfdfd),     // repository ID = IDL:/CORBA_DynSequence:1.0
  12,
  ACE_NTOHL (0x44796e53),
  ACE_NTOHL (0x65717565),
  ACE_NTOHL (0x6e636500),  // name = CORBA_DynSequence,
};

static CORBA::TypeCode _tc_TAO_tc_CORBA_DynSequence (
    CORBA::tk_objref,
    sizeof (_oc_CORBA_DynSequence),
    (char *) &_oc_CORBA_DynSequence,
    0,
    sizeof (CORBA_DynSequence));

CORBA::TypeCode_ptr _tc_CORBA_DynSequence =
  &_tc_TAO_tc_CORBA_DynSequence;

CORBA_DynArray_ptr CORBA_DynArray::_duplicate (CORBA_DynArray_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_incr_refcnt ();

  return obj;
} // end of _duplicate

CORBA_DynArray_ptr CORBA_DynArray::_narrow (CORBA::Object_ptr obj,
                                            CORBA::Environment &ACE_TRY_ENV)
{
  if (CORBA::is_nil (obj))
    return CORBA_DynArray::_nil ();

  if (!obj->_is_a ("IDL:/CORBA_DynArray:1.0",
                   ACE_TRY_ENV))
    return CORBA_DynArray::_nil ();

  void *servant = 0;
  if (!obj->_is_collocated ()
      || !obj->_servant ()
      || (servant = obj->_servant ()->_downcast ("IDL:/CORBA_DynArray:1.0")) == 0)
    ACE_THROW_RETURN (CORBA::MARSHAL (), CORBA_DynArray::_nil ());

  CORBA_DynArray_ptr retval = CORBA_DynArray::_nil ();

  ACE_NEW_RETURN (
      retval,
      POA_CORBA::_tao_collocated_DynArray (
          ACE_reinterpret_cast (POA_CORBA::DynArray_ptr,
                                servant),
          0
        ),
      CORBA_DynArray::_nil ()
    );

  return retval;
}

CORBA_DynArray_ptr CORBA_DynArray::_nil (void)
{
  return (CORBA_DynArray_ptr) NULL;
} // end of _nil

CORBA_AnySeq *
CORBA_DynArray::get_elements (CORBA::Environment &)
{
  return 0;
}

void
CORBA_DynArray::set_elements (const CORBA_AnySeq &,
                              CORBA::Environment &)
{
}

CORBA::Boolean CORBA_DynArray::_is_a (const CORBA::Char *value,
                                      CORBA::Environment &env)
{
  if ((!ACE_OS::strcmp ((char *)value,
                        "IDL:/CORBA_DynArray:1.0"))
      || (!ACE_OS::strcmp ((char *)value,
                           "IDL:/CORBA_DynAny:1.0"))
      || (!ACE_OS::strcmp ((char *)value,
                           CORBA::_tc_Object->id (env))))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value, env); // remote call
}

const char* CORBA_DynArray::_interface_repository_id (void) const
{
  return "IDL:/CORBA_DynArray:1.0";
}

static const CORBA::Long _oc_CORBA_DynArray[] =
{
  TAO_ENCAP_BYTE_ORDER,     // byte order
  18,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x2f44796e),
  ACE_NTOHL (0x41727261),
  ACE_NTOHL (0x793a312e),
  ACE_NTOHL (0x3000fdfd),   // repository ID = IDL:/CORBA_DynArray:1.0
  9,
  ACE_NTOHL (0x44796e41),
  ACE_NTOHL (0x72726179),
  ACE_NTOHL (0xfdfdfd),     // name = CORBA_DynArray,
};

static CORBA::TypeCode _tc_TAO_tc_CORBA_DynArray (
    CORBA::tk_objref,
    sizeof (_oc_CORBA_DynArray),
    (char *) &_oc_CORBA_DynArray,
    0,
    sizeof (CORBA_DynArray));

CORBA::TypeCode_ptr _tc_CORBA_DynArray =
    &_tc_TAO_tc_CORBA_DynArray;


#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
  template class TAO_Object_Field_T<CORBA_DynAny,CORBA_DynAny_var>;
  template class TAO_Object_Field_T<CORBA_DynEnum,CORBA_DynEnum_var>;
  template class TAO_Object_Field_T<CORBA_DynStruct,CORBA_DynStruct_var>;
  template class TAO_Object_Field_T<CORBA_DynUnion,CORBA_DynUnion_var>;
  template class TAO_Object_Field_T<CORBA_DynSequence,CORBA_DynSequence_var>;
  template class TAO_Object_Field_T<CORBA_DynArray,CORBA_DynArray_var>;
  template class TAO_Object_Manager<CORBA_DynAny,CORBA_DynAny_var>;
  template class TAO_Object_Manager<CORBA_DynEnum,CORBA_DynEnum_var>;
  template class TAO_Object_Manager<CORBA_DynStruct,CORBA_DynStruct_var>;
  template class TAO_Object_Manager<CORBA_DynUnion,CORBA_DynUnion_var>;
  template class TAO_Object_Manager<CORBA_DynSequence,CORBA_DynSequence_var>;
  template class TAO_Object_Manager<CORBA_DynArray,CORBA_DynArray_var>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#  pragma instantiate TAO_Object_Field_T<CORBA_DynAny,CORBA_DynAny_var>
#  pragma instantiate TAO_Object_Field_T<CORBA_DynEnum,CORBA_DynEnum_var>
#  pragma instantiate TAO_Object_Field_T<CORBA_DynStruct,CORBA_DynStruct_var>
#  pragma instantiate TAO_Object_Field_T<CORBA_DynUnion,CORBA_DynUnion_var>
#  pragma instantiate TAO_Object_Field_T<CORBA_DynSequence,CORBA_DynSequence_var>
#  pragma instantiate TAO_Object_Field_T<CORBA_DynArray,CORBA_DynArray_var>
#  pragma instantiate TAO_Object_Manager<CORBA_DynAny,CORBA_DynAny_var>
#  pragma instantiate TAO_Object_Manager<CORBA_DynEnum,CORBA_DynEnum_var>
#  pragma instantiate TAO_Object_Manager<CORBA_DynStruct,CORBA_DynStruct_var>
#  pragma instantiate TAO_Object_Manager<CORBA_DynUnion,CORBA_DynUnion_var>
#  pragma instantiate TAO_Object_Manager<CORBA_DynSequence,CORBA_DynSequence_var>
#  pragma instantiate TAO_Object_Manager<CORBA_DynArray,CORBA_DynArray_var>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

#endif /* TAO_HAS_MINIMUM_CORBA */

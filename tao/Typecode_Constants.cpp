// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO
//
// = FILENAME
//    Typecode_Constants.cpp
//
// = DESCRIPTION
//   All the CORBA-specified typecode constants.
//
//   NOTE:  IFR TypeCode constants aren't here; they're left for an IDL
//   compiler to generate from the appropriate IDL source.
//
//   NOTE:  it'd be nice to have these not use init sections.  Most can easily
//   be in readonly data (e.g. text segment, ROM) rather than writable data;
//   that speeds program startup and page sharing in shared libraries.
//
//   THREADING NOTE:  no issues, these are immutable constants
//
// = AUTHOR
//     Copyright 1994-1995 by Sun Microsystems Inc.
//     and Aniruddha Gokhale
//
// ============================================================================

#include "tao/corba.h"

// Declare all the standard typecodes owned by the ORB

// Null and void
CORBA::TypeCode_ptr CORBA::_tc_null;
CORBA::TypeCode_ptr CORBA::_tc_void;
// Basic numeric types:  short, long, longlong, and unsigned variants
CORBA::TypeCode_ptr CORBA::_tc_short;
CORBA::TypeCode_ptr CORBA::_tc_long;
CORBA::TypeCode_ptr CORBA::_tc_longlong;
CORBA::TypeCode_ptr CORBA::_tc_ushort;
CORBA::TypeCode_ptr CORBA::_tc_ulong;
CORBA::TypeCode_ptr CORBA::_tc_ulonglong;
// Floating point types: single, double, quad precision
CORBA::TypeCode_ptr CORBA::_tc_float;
CORBA::TypeCode_ptr CORBA::_tc_double;
CORBA::TypeCode_ptr CORBA::_tc_longdouble;
// Various simple quantities.
CORBA::TypeCode_ptr CORBA::_tc_boolean;
CORBA::TypeCode_ptr CORBA::_tc_octet;
// Internationalization-related data types: ISO Latin/1 and "wide"
// characters, and strings of each.  "wchar" is probably Unicode 1.1,
// "wstring" being null-terminated sets thereof.
CORBA::TypeCode_ptr CORBA::_tc_char;
CORBA::TypeCode_ptr CORBA::_tc_wchar;
// a string/wstring have a simple parameter list that indicates the length
CORBA::TypeCode_ptr CORBA::_tc_string;
CORBA::TypeCode_ptr CORBA::_tc_wstring;
//
// Various things that can be passed as "general" parameters:
// Any, TypeCode_ptr, Principal_ptr, Object_ptr
//
CORBA::TypeCode_ptr CORBA::_tc_any;
CORBA::TypeCode_ptr CORBA::_tc_TypeCode;
CORBA::TypeCode_ptr CORBA::_tc_Principal;
CORBA::TypeCode_ptr CORBA::_tc_Object;
// Two typecodes for exceptions
CORBA::TypeCode_ptr CORBA::_tc_Bounds;
CORBA::TypeCode_ptr CORBA::_tc_BadKind;
// Internal to TAO ORB
CORBA::TypeCode_ptr TC_opaque;
CORBA::TypeCode_ptr TC_ServiceContextList;
CORBA::TypeCode_ptr TC_completion_status;

// initialize all the ORB owned TypeCode constants. This routine will be
// invoked by the ORB_init method
void
TAO_TypeCodes::init (void)
{
  // Initialize all the standard typecodes owned by the ORB

  // Null and void
  CORBA::_tc_null = new CORBA::TypeCode (CORBA::tk_null);

  CORBA::_tc_void = new CORBA::TypeCode (CORBA::tk_void);

  // Basic numeric types:  short, long, longlong, and unsigned variants
  CORBA::_tc_short = new CORBA::TypeCode (CORBA::tk_short);

  CORBA::_tc_long = new CORBA::TypeCode (CORBA::tk_long);

  CORBA::_tc_longlong = new CORBA::TypeCode (CORBA::tk_longlong);

  CORBA::_tc_ushort = new CORBA::TypeCode (CORBA::tk_ushort);

  CORBA::_tc_ulong = new CORBA::TypeCode (CORBA::tk_ulong);

  CORBA::_tc_ulonglong = new CORBA::TypeCode (CORBA::tk_ulonglong);

  // Floating point types: single, double, quad precision
  CORBA::_tc_float = new CORBA::TypeCode (CORBA::tk_float);

  CORBA::_tc_double = new CORBA::TypeCode (CORBA::tk_double);

  CORBA::_tc_longdouble = new CORBA::TypeCode (CORBA::tk_longdouble);

  // Various simple quantities.
  CORBA::_tc_boolean = new CORBA::TypeCode (CORBA::tk_boolean);

  CORBA::_tc_octet = new CORBA::TypeCode (CORBA::tk_octet);

  // Internationalization-related data types: ISO Latin/1 and "wide"
  // characters, and strings of each.  "wchar" is probably Unicode 1.1,
  // "wstring" being null-terminated sets thereof.
  CORBA::_tc_char = new CORBA::TypeCode (CORBA::tk_char);

  CORBA::_tc_wchar = new CORBA::TypeCode (CORBA::tk_wchar);

  // a string/wstring have a simple parameter list that indicates the length
  static const CORBA::Long _oc_string [] =
  {
    // CDR typecode octets
    TAO_ENCAP_BYTE_ORDER, // native endian + padding; "tricky"
    0                     // ... unbounded string
  };
  CORBA::_tc_string = new CORBA::TypeCode (CORBA::tk_string,
                                           sizeof _oc_string,
                                           (char*)&_oc_string,
                                           CORBA::B_TRUE);

  static const CORBA::Long _oc_wstring [] =
  {
    // CDR typecode octets
    TAO_ENCAP_BYTE_ORDER,	// native endian + padding; "tricky"
    0                     // ... unbounded string
  };
  CORBA::_tc_wstring = new CORBA::TypeCode (CORBA::tk_wstring,
                                            sizeof _oc_wstring,
                                            (char *) &_oc_wstring,
                                            CORBA::B_TRUE);

  //
  // Various things that can be passed as "general" parameters:
  // Any, TypeCode_ptr, Principal_ptr, Object_ptr
  //
  CORBA::_tc_any = new CORBA::TypeCode (CORBA::tk_any);

  CORBA::_tc_TypeCode = new CORBA::TypeCode (CORBA::tk_TypeCode);

  CORBA::_tc_Principal = new CORBA::TypeCode (CORBA::tk_Principal);

  // typecode for objref is complex, has two string parameters
  //
  // NOTE:  Must be four-byte aligned

  static const u_char oc_objref [] =
  {
    0, 0, 0, 0,			// big endian encoding (+ padding)
    0, 0, 0, 29,                  // 29 char string + 3 pad bytes
    'I', 'D', 'L', ':',
    'o', 'm', 'g', '.',
    'o', 'r', 'g', '/',
    'C', 'O', 'R', 'B',
    'A', '/', 'O', 'b',
    'j', 'e', 'c', 't',
    ':', '1', '.', '0',
    '\0', 0, 0, 0,
    0, 0, 0, 7,			// 7 chars "Object" + 1 pad byte
    'O', 'b', 'j', 'e',
    'c', 't', '\0', 0,
  };

  CORBA::_tc_Object = new CORBA::TypeCode (CORBA::tk_objref,
                                           sizeof oc_objref,
                                           (char *) &oc_objref,
                                           CORBA::B_TRUE);

  // Static initialization of the two user-defined exceptions that
  // are part of the ORB.

  static char tc_buf_Bounds [] =
  {
    0, 0, 0, 0,           // big endian, padded
    0, 0, 0, 38,  // strlen (id) + 1
    'I', 'D', 'L', ':',
    'o', 'm', 'g', '.',
    'o', 'r', 'g', '/',
    'C', 'O', 'R', 'B',
    'A', '/', 'T', 'y',
    'p', 'e', 'C', 'o',
    'd', 'e', '/', 'B',
    'o', 'u', 'n', 'd',
    's', ':', '1', '.',
    '0', '\0', 0, 0,
    0, 0, 0, 0            // no members to this typecode
  };

  CORBA::_tc_Bounds = new CORBA::TypeCode (CORBA::tk_except,
                                           sizeof tc_buf_Bounds,
                                           tc_buf_Bounds,
                                           CORBA::B_TRUE);

  static char tc_buf_BadKind [] =
  {
    0, 0, 0, 0,           // big endian, padded
    0, 0, 0, 39,  // strlen (id) + 1
    'I', 'D', 'L', ':',
    'o', 'm', 'g', '.',
    'o', 'r', 'g', '/',
    'C', 'O', 'R', 'B',
    'A', '/', 'T', 'y',
    'p', 'e', 'C', 'o',
    'd', 'e', '/', 'B',
    'a', 'd', 'K', 'i',
    'n', 'd', ':', '1',
    '.', '0', '\0', 0,
    0, 0, 0, 0            // no members to this typecode
  };

  CORBA::_tc_BadKind = new CORBA::TypeCode (CORBA::tk_except,
                                            sizeof tc_buf_BadKind,
                                            tc_buf_BadKind,
                                            CORBA::B_TRUE);

  // The following are internal to the TAO ORB

  // Octet codes for the parameters of the "Opaque" (sequence of octet)
  // data type used various places internally ... a CDR encapsulation
  // holding two parameters (like all sequence TypeCodes).
  //
  // NOTE: this **MUST** be longword aligned, which is why it's coded as
  // a longword array not an octet array.  Just sticking a long in for
  // padding won't work with compilers that optimize unused data out of
  // existence.

  // CDR typecode octets.

  static const CORBA::Long _oc_opaque [] =
  {

    TAO_ENCAP_BYTE_ORDER,    // native endian + padding; "tricky"
    10,                      // ... (sequence of) octets
    0                        // ... unbounded
  };

  TC_opaque = new CORBA::TypeCode (CORBA::tk_sequence,
                                   sizeof _oc_opaque,
                                   (char *) &_oc_opaque,
                                   CORBA::B_TRUE);

  // Octet codes for the parameters of the ServiceContextList TypeCode
  // ...  this is a CDR encapsulation holding two parameters (like all
  // sequences): a TypeCode, and the bounds of the sequence (zero in
  // this case).
  //
  // This is complicated since the Typecode for the data type for the
  // sequence members is complex, a structure that nests two further
  // typecodes (one is a sequence).
  //
  // NOTE:  this must be longword aligned!

  static const CORBA::Long _oc_svc_ctx_list [] =
  {
    // START bytes of encapsulation 0
    TAO_ENCAP_BYTE_ORDER, // native endian + padding; "tricky"

    //
    // FIRST sequence param:  typecode for struct is complex,
    // and so uses a nested encapsulation.
    //
    CORBA::tk_struct,
    72, // length of encapsulation 1

    // START bytes of encapsulation 1 (struct params)
    1, // native endian + padding; "tricky"
    1, 0, // type ID omitted:  null string
    1, 0, // name omitted "ServiceContext"

    2, // two struct elements

    // First structure element:  name, typecode for ULong
    //
    // NOTE:  to be more strictly correct this could be a CORBA::tk_alias
    // typecode ...

    1, 0, // name omitted:  "context_id"
    CORBA::tk_long,

    // Second structure element: name, typecode for sequence of octet;
    // the typecode for sequence of octet is complex, there's a second
    // level of nested encapuslation here.

    1, 0, // name omitted:  "context_data"
    CORBA::tk_sequence,   // sequence typecode
    16, // length of encapsulation 2

    // START bytes of encapsulation 2 (sequence params)
    1, // native endian + padding; "tricky"
    1, 0, // type ID omitted:  null string
    CORBA::tk_octet, // (sequence of) octet
    0, // ... unbounded length
    // END bytes of encapsulation 2 (sequence params)

    // END bytes of encapsulation 1 (struct params)

    // SECOND sequence param:  bound of sequence (none)
    0 // unbounded seq of ServiceContext
    // END bytes of encapsulation 0 (sequence params)
  };

  TC_ServiceContextList = new CORBA::TypeCode (CORBA::tk_sequence,
                                               sizeof _oc_svc_ctx_list,
                                               (char *) &_oc_svc_ctx_list,
                                               CORBA::B_TRUE);
  static const CORBA::ULong oc_completion_status [] =
  {
    TAO_ENCAP_BYTE_ORDER, // byte order flag, tricky
    0, 0,                 // type ID omitted
    3,                    // three members
    0, 0,                 // ... whose names are all omitted
    0, 0,
    0, 0
  };

  TC_completion_status =
    new CORBA::TypeCode (CORBA::tk_enum,
                         sizeof oc_completion_status,
                         (char *) &oc_completion_status,
                         CORBA::B_TRUE);
}

// destroy all the typecodes owned by the ORB
void
TAO_TypeCodes::fini (void)
{
  // Initialize all the standard typecodes owned by the ORB

  // Null and void
  delete CORBA::_tc_null;

  delete CORBA::_tc_void;

  // Basic numeric types:  short, long, longlong, and unsigned variants
  delete CORBA::_tc_short;

  delete CORBA::_tc_long;

  delete CORBA::_tc_longlong;

  delete CORBA::_tc_ushort;

  delete CORBA::_tc_ulong;

  delete CORBA::_tc_ulonglong;

  // Floating point types: single, double, quad precision
  delete CORBA::_tc_float;

  delete CORBA::_tc_double;

  delete CORBA::_tc_longdouble;

  // Various simple quantities.
  delete CORBA::_tc_boolean;

  delete CORBA::_tc_octet;

  // Internationalization-related data types: ISO Latin/1 and "wide"
  // characters, and strings of each.  "wchar" is probably Unicode 1.1,
  // "wstring" being null-terminated sets thereof.
  delete CORBA::_tc_char;

  delete CORBA::_tc_wchar;

  // a string/wstring have a simple parameter list that indicates the length
  delete CORBA::_tc_string;

  delete CORBA::_tc_wstring;

  //
  // Various things that can be passed as "general" parameters:
  // Any, TypeCode_ptr, Principal_ptr, Object_ptr
  //
  delete CORBA::_tc_any;

  delete CORBA::_tc_TypeCode;

  delete CORBA::_tc_Principal;

  // typecode for objref is complex, has two string parameters
  //
  delete CORBA::_tc_Object;

  // other ORB owned typecodes
  delete CORBA::_tc_Bounds;

  delete CORBA::_tc_BadKind;

  // TAO specific
  delete TC_opaque;

  delete TC_ServiceContextList;

  delete TC_completion_status;
}

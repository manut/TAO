// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/tests/Param_Test
//
// = FILENAME
//    ub_objref_seq.h
//
// = DESCRIPTION
//     Tests unbounded sequences of object references
//
// = AUTHORS
//      Aniruddha Gokhale
//
// ============================================================================

#if !defined (PARAM_TEST_UNBOUNDED_OBJREF_SEQUENCE_H)
#define PARAM_TEST_UNBOUNDED_OBJREF_SEQUENCE_H

#include "helper.h"
#include "param_testC.h"

// =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
//           test sequence of object references
// =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*

class Test_ObjRef_Sequence
{
public:
  Test_ObjRef_Sequence (void);
  // ctor

  ~Test_ObjRef_Sequence (void);
  // dtor

  int run_sii_test (Param_Test_ptr objref,
                    CORBA::Environment &env);
  // run the SII test

  int add_args (CORBA::NVList_ptr nvlist,
                CORBA::NVList_ptr retval,
                CORBA::Environment &env);
  // add args to NVList for DII

  const char *opname (void) const;
  // return operation name

  int init_parameters (Param_Test_ptr objref,
                        CORBA::Environment &env);
  // set values for parameters

  int reset_parameters (void);
  // reset values for CORBA

  CORBA::Boolean check_validity (void);
  // check if results are valid

  CORBA::Boolean check_validity (CORBA::Request_ptr req);
  // check if results are valid. This is used for DII results

  void print_values (void);
  // print all the values

protected:
  CORBA::Boolean compare (const Param_Test::Coffee_Mix &s1,
                          const Param_Test::Coffee_Mix &s2,
						  CORBA::Environment& env);
  // compare

  void print_sequence (const Param_Test::Coffee_Mix &s);
  // print individual sequence
private:
  char *opname_;
  // operation name

  Param_Test::Coffee_Mix in_;
  // in parameter

  // these need memory management
  Param_Test::Coffee_Mix_var inout_;
  // inout parameter

  Param_Test::Coffee_Mix_var out_;
  // out parameter

  Param_Test::Coffee_Mix_var ret_;
  // return value
};

#endif /* PARAM_TEST_UNBOUNDED_OBJREF_SEQUENCE_H */

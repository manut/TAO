// $Id$

// ============================================================================
//
// = LIBRARY
//   TAO/tests/Single_Read
//
// = FILENAME
//   test_i.h
//
// = AUTHOR
//   Balachandran Natarajan <bala@cs.wustl.edu>
//
// ============================================================================

#ifndef TAO_SINGLE_READ_TEST_I_H
#define TAO_SINGLE_READ_TEST_I_H

#include "testS.h"

class test_i : public POA_test
{
  // = TITLE
  //   Simple implementation.
  //
public:
  test_i (CORBA::ORB_ptr orb);
  // ctor.

  // = The test interface methods.
  void method (CORBA::ULong request_number,
               const test::data &,
               CORBA::Environment &)
    ACE_THROW_SPEC (());

  void shutdown (CORBA::Environment &)
    ACE_THROW_SPEC (());

private:
  /// The ORB.
  CORBA::ORB_var orb_;

};

#endif /* TAO_SINGLE_READ_TEST_I_H*/

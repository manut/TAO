// $Id$

// ============================================================================
//
// = LIBRARY
//   TAO/tests/Mprofile
//
// = FILENAME
//   test_i.h
//
// = AUTHOR
//   Carlos O'Ryan <coryan@uci.edu>
//
// ============================================================================

#ifndef TAO_MPROFILE_TEST_I_H
#define TAO_MPROFILE_TEST_I_H

#include "testS.h"

class Simple_Server_i : public POA_Simple_Server
{
  // = TITLE
  //   Simpler Server implementation
  //
  // = DESCRIPTION
  //   Implements the Simple_Server interface in test.idl
  //
public:
  Simple_Server_i (CORBA::ORB_ptr orb);
  // ctor

  Simple_Server_i (void);
  // ctor

  // = The Simple_Server methods.
  void remote_call (CORBA::Environment &)
    ACE_THROW_SPEC ((CORBA::SystemException));

  void shutdown (CORBA::Environment&)
    ACE_THROW_SPEC ((CORBA::SystemException));

private:
  CORBA::ORB_var orb_;
};

#endif /* TAO_MPROFILE_TEST_I_H */

// $Id:$

#include "ace/OS_NS_unistd.h"
#include "TestImpl.h"

TestImpl::TestImpl (CORBA::ORB_ptr orb)
  : orb_ (CORBA::ORB::_duplicate (orb))
{
}

// virtual 
void TestImpl::myMethod (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_DEBUG ((LM_ERROR, "(%P): TestImpl::myMethod called!.\n") );
}


// virtual 
void TestImpl::shutdown (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Give the client thread time to return from the collocated
  // call to this method before shutting down the ORB.  We sleep
  // to avoid BAD_INV_ORDER exceptions on fast dual processor machines.
  ACE_OS::sleep (1);
  this->orb_->shutdown ();
}

// $Id$

#include "test_i.h"

ACE_RCSID (Dynamic,
           test_i,
           "$Id$")

Visual_i::Visual_i (CORBA::ORB_ptr orb)
  : orb_ (CORBA::ORB::_duplicate (orb))
{
}
  // ctor

void
Visual_i::normal (CORBA::Long arg
                  ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_DEBUG ((LM_DEBUG, "Visual::normal called with %d\n", arg));
}

CORBA::Long
Visual_i::calculate (CORBA::Long one,
                     CORBA::Long two
                     ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_DEBUG ((LM_DEBUG, "Visual::calculate\n"));
  return (one + two);
}

Test_Interceptors::Visual::VarLenStruct *
Visual_i::the_structure (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  Test_Interceptors::Visual::VarLenStruct * s;

  ACE_NEW_THROW_EX (s,
                    Test_Interceptors::Visual::VarLenStruct,
                    CORBA::NO_MEMORY ());
  ACE_CHECK_RETURN (0);

  Test_Interceptors::Visual::VarLenStruct_var safe_s = s;

  s->flag    = 135;
  s->message = CORBA::string_dup ("Oh Captain, my Captain!");

  return safe_s._retn ();
}

void
Visual_i::user (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,Test_Interceptors::Silly))
{
  ACE_DEBUG ((LM_DEBUG, "Visual::user, throwing Silly\n"));
  ACE_THROW (Test_Interceptors::Silly ());
}

void
Visual_i::system (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_DEBUG ((LM_DEBUG, "Visual::user, throwing INV_OBJREF\n"));
  ACE_THROW (CORBA::INV_OBJREF ());
}

void
Visual_i::shutdown (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->orb_->shutdown ();
}

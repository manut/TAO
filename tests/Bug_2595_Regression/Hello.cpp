//
// $Id$
//
#include "Hello.h"

ACE_RCSID(Hello, Hello, "$Id$")

Hello::Hello (CORBA::ORB_ptr orb)
  : orb_ (CORBA::ORB::_duplicate (orb))
{
}

void
Hello::op (
        ::Test::Fls_out fstruct,
        ::Test::Vls_out vstruct
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ))
{
  Test::Fls a = {5, 1.0};
  fstruct = a;
  vstruct = new Test::Vls;
}

void
Hello::shutdown (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->orb_->shutdown (0);
}

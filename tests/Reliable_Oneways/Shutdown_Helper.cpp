//
// $Id$
//
#include "Shutdown_Helper.h"

ACE_RCSID(Reliable_Oneways, Shutdown_Helper, "$Id$")

Shutdown_Helper::Shutdown_Helper (CORBA::ORB_ptr orb)
  : orb_ (CORBA::ORB::_duplicate (orb))
{
}

void
Shutdown_Helper::shutdown (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->orb_->shutdown (0 ACE_ENV_ARG_PARAMETER);
}

// $Id$

#include "Server_i.h"

ACE_RCSID (PSS, Server_i, "$Id$")

Server_i::Server_i (void)
{
}

Server_i::~Server_i (void)
{
}

char *
Server_i::get_status (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return CORBA::string_dup ("active");
}

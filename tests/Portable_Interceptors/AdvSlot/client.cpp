// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id$

#include "StateTransferC.h"

int
main (int argc, char *argv[])
{
  CORBA::ORB_var orb = CORBA::ORB_init (argc, argv);

  if (argc != 2)
  {
    ACE_DEBUG ((LM_ERROR, "Usage: %s <ior>\n", argv[0]));
    return -1;
  }

  CORBA::Object_var obj = orb->string_to_object (argv[1]);
  StateTransfer_var server = StateTransfer::_narrow (obj.in ());

  CORBA::Short n  = server->number ();

  ACE_DEBUG ((LM_ERROR, "Got number %d\n", n));
}

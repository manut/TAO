/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/orbsvcs/Naming_Service
//
// = FILENAME
//    Naming_Utils.h
//
// = DESCRIPTION
//      This class implements a Naming Server wrapper class which holds
//      a Naming Context for TAO NameService.
//
// = AUTHORS
//    Nagarajan Surendran (naga@cs.wustl.edu)
//
// ============================================================================

#if !defined (_NAMING_SERVER_H)
#define _NAMING_SERVER_H

#include "tao/corba.h"
#include "orbsvcs/CosNamingC.h"
#include "Naming_Service/CosNaming_i.h"
#include "Naming_Service/Naming_Service.h"

class TAO_Naming_Server
{
  // = TITLE
  //    Defines a wrapper class which holds a Naming Context
  //    implementation for TAO "NamingService" naming context.
  //
  // = DESCRIPTION
  //    This class takes an orb and Poa reference and activates the
  //    NamingService naming context object under that. It also
  //    defines the operator -> so that NamingContext functions like
  //    bind, unbind .. can be called on a NameServer object.
public:
  TAO_Naming_Server (void);
  //Default constructor.

  TAO_Naming_Server (CORBA::ORB_var &orb,
                     PortableServer::POA_var &root_poa);
  // Takes the POA under which to register the Naming Service
  // implementation object.

  int init (CORBA::ORB_var &orb,
            PortableServer::POA_var &root_poa);
  // Initialize the name server under the given ORB and POA.

  NS_NamingContext &GetNamingContext (void);
  // Returns the "NameService" NamingContext implementation object
  // reference.

  CosNaming::NamingContext *operator -> (void) const;
  // Returns a NamingContext_ptr.

  ~TAO_Naming_Server (void);
  // Destructor.

private:
  NS_NamingContext naming_context_impl_;
  // Naming context implemetation for "NameService".

  CosNaming::NamingContext_ptr naming_context_ptr_;
  // NamingContext ptr.

  IOR_Multicast *ior_multicast_;
  // The ior_multicast event handler.
};

#endif /* _NAMING_SERVER_H */


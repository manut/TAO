// -*- C++ -*-

//=============================================================================
/**
 * @file SL3_CredentialsAcquirerFactory.h
 *
 * $Id$
 *
 * @author Ossama Othman <ossama@dre.vanderbilt.edu>
 */
//=============================================================================


#ifndef TAO_SL3_CREDENTIALS_ACQUIRER_FACTORY_H
#define TAO_SL3_CREDENTIALS_ACQUIRER_FACTORY_H

#include /**/ "ace/pre.h"

#include "orbsvcs/orbsvcs/Security/security_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "orbsvcs/orbsvcs/Security/SL3_CredentialsCurator.h"

#include "orbsvcs/orbsvcs/SecurityLevel3C.h"


namespace TAO
{
  namespace SL3
  {

    /**
     * @class CredentialsAcquirerFactory
     *
     * @brief Abstract base class for all concrete
     *        CredentialsAcquirerFactory implementations.
     *
     * All concrete CredentialsAcquirerFactory classes must implement
     * this interface.
     */
    class TAO_Security_Export CredentialsAcquirerFactory
    {
    public:

      /// Destructor.
      virtual ~CredentialsAcquirerFactory (void);

      /// Create a TAO::SL3::CredentialsAcquirerFactory.
      virtual SecurityLevel3::CredentialsAcquirer_ptr make (
        TAO::SL3::CredentialsCurator_ptr curator,
        const CORBA::Any & acquisition_arguments
        ACE_ENV_ARG_DECL) = 0;

    };

  } // End SL3 namespace
}  // End TAO namespace


#include /**/ "ace/post.h"

#endif  /* TAO_SL3_CREDENTIALS_ACQUIRER_FACTORY_H */

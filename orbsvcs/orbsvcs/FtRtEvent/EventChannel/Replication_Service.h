// -*- C++ -*-

//=============================================================================
/**
 *  @file   Replication_Service.h
 *
 *  $Id$
 *
 *  @author Huang-Ming Huang <hh1@cse.wustl.edu>
 */
//=============================================================================

#ifndef REPLCATION_SERVICE_H
#define REPLCATION_SERVICE_H

#include "orbsvcs/orbsvcs/FtRtecEventChannelAdminC.h"
#include "FTEC_Become_Primary_Listener.h"
#include "tao/PortableInterceptorC.h"
#include "ace/Service_Object.h"
#include "ftrtec_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

namespace FTRTEC
{
  class Replication_Service : public TAO_FTEC_Become_Primary_Listener,
    public ACE_Service_Object
  {
  public:
    static Replication_Service* instance();

    Replication_Service();
    ~Replication_Service();

    virtual int init (int argc,
      ACE_TCHAR* []);

    virtual void become_primary();

    void check_validity(ACE_ENV_SINGLE_ARG_DECL);

    typedef void (FtRtecEventChannelAdmin::EventChannelFacade::*RollbackOperation)
      (const FtRtecEventChannelAdmin::ObjectId& ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    void replicate_request(const FtRtecEventChannelAdmin::Operation& update,
      RollbackOperation rollback
      ACE_ENV_ARG_DECL);

    int  acquire_read (void);
    int  acquire_write (void);
    int  release (void);
  };


  ACE_STATIC_SVC_DECLARE_EXPORT (TAO_FTRTEC, Replication_Service)
  ACE_STATIC_SVC_REQUIRE(Replication_Service)
  ACE_FACTORY_DECLARE (TAO_FTRTEC, Replication_Service)
}

#endif //REPLCATION_SERVICE_H

// $Id$

#include "Replication_Service.h"
#include "AMI_Replication_Strategy.h"
#include "Basic_Replication_Strategy.h"
#include "FTEC_ORBInitializer.h"
#include "../Utils/Log.h"

#include "tao/ORBInitializer_Registry.h"
#include "tao/CDR.h"

#include "ace/OS_NS_strings.h"

ACE_RCSID (EventChannel,
           Replication_Service,
           "$Id$")

namespace FTRTEC
{
  namespace {
    auto_ptr<Replication_Strategy> replication_strategy;
    int threads = 1;
    Replication_Service* service;
  }

  Replication_Service* Replication_Service::instance()
  {
    return service;
  }

  Replication_Service::Replication_Service()
  {
    service = this;
  }

  Replication_Service::~Replication_Service()
  {
  }

  int Replication_Service::init (int argc, ACE_TCHAR* argv[])
  {
    static int initialized = 0;

    // Only allow initialization once.
    if (initialized)
      return 0;

    initialized = 1;
    bool ami = false;

    // Parse any service configurator parameters.
    while (argc > 0) {
      if (ACE_OS::strcasecmp (argv[0], ACE_LIB_TEXT("AMI")) ==0 )
        ami = true;
      if (ACE_OS::strcasecmp (argv[0], ACE_LIB_TEXT("-threads")) ==0  && argc > 1) {
        FTRTEC::threads = ACE_OS::atoi(argv[1]);
        if (FTRTEC::threads ==0 )
          FTRTEC::threads = 1;
        ++argv; --argc;
      }
      ++argv; --argc;
    }

    Replication_Strategy* strategy;
    if (ami) {
      ACE_NEW_RETURN (strategy, AMI_Replication_Strategy(threads() > 1), -1);
      TAO_FTRTEC::Log(3, "AMI replication strategy\n");
    }
    else {
      ACE_NEW_RETURN (strategy, Basic_Replication_Strategy(threads() > 1), -1);
      TAO_FTRTEC::Log(3, "Basic replication strategy\n");
    }

     ACE_AUTO_PTR_RESET (replication_strategy, strategy, Replication_Strategy);

      ACE_TRY_NEW_ENV
      {
        PortableInterceptor::ORBInitializer_ptr temp_orb_initializer =
          PortableInterceptor::ORBInitializer::_nil ();
        PortableInterceptor::ORBInitializer_var orb_initializer;

        /// Register the RTCORBA ORBInitializer.
        ACE_NEW_THROW_EX (temp_orb_initializer,
          FTEC_ORBInitializer,
          CORBA::NO_MEMORY ());
        ACE_TRY_CHECK;
        orb_initializer = temp_orb_initializer;

        PortableInterceptor::register_orb_initializer (orb_initializer.in ()
          ACE_ENV_ARG_PARAMETER);
        ACE_TRY_CHECK;
      }
      ACE_CATCHANY
      {
        ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
          "Unexpected exception caught while "
          "initializing the TransactionDepth");
        return -1;
      }
      ACE_ENDTRY;
    return 0;
  }


  void Replication_Service::become_primary()
  {
    Replication_Strategy* strategy =
      replication_strategy->make_primary_strategy();

    ACE_ASSERT(strategy);

    if (replication_strategy.get() != strategy) {
      ACE_AUTO_PTR_RESET(replication_strategy, strategy, Replication_Strategy);
    }
  }

  void Replication_Service::check_validity(ACE_ENV_SINGLE_ARG_DECL)
  {
    replication_strategy->check_validity(ACE_ENV_SINGLE_ARG_PARAMETER);
  }


  void Replication_Service::replicate_request(const FtRtecEventChannelAdmin::Operation& update,
    RollbackOperation rollback
    ACE_ENV_ARG_DECL)
  {
    TAO_OutputCDR cdr;
    cdr << update;

    ACE_Message_Block mb;
    ACE_CDR::consolidate(&mb, cdr.begin());
    FTRT::State state(mb.length(), &mb);
    //FT::State state;

    replication_strategy->replicate_request(
      state,
      rollback,
      update.object_id
      ACE_ENV_ARG_PARAMETER);
  }

  void Replication_Service::add_member(const FTRT::ManagerInfo & info,
                                       CORBA::ULong object_group_ref_version
                                       ACE_ENV_ARG_DECL)
  {
    replication_strategy->add_member(info, object_group_ref_version ACE_ENV_ARG_PARAMETER);
  }

  int  Replication_Service::acquire_read (void)
  {
    int r =  replication_strategy->acquire_read();
    TAO_FTRTEC::Log(3, "Read Lock acquired %d\n", r);
    return r;
  }

  int  Replication_Service::acquire_write (void)
  {
    int r= replication_strategy->acquire_write();
    TAO_FTRTEC::Log(3, "Write Lock acqured %d\n", r);
    return r;
  }

  int  Replication_Service::release (void)
  {
    int r= replication_strategy->release();
    TAO_FTRTEC::Log(3, "Lock Released %d\n", r);
    return r;
  }

  int Replication_Service::threads() const {
    return FTRTEC::threads;
  }

  ACE_FACTORY_DEFINE (TAO_FTRTEC, Replication_Service)

  ACE_STATIC_SVC_DEFINE (Replication_Service,
    ACE_TEXT ("FTRTEC_Replication"),
    ACE_SVC_OBJ_T,
    &ACE_SVC_NAME (Replication_Service),
    ACE_Service_Type::DELETE_THIS
    | ACE_Service_Type::DELETE_OBJ,
    0)
}

// $Id$

#ifndef IMR_LOCATOR_I_H
#define IMR_LOCATOR_I_H
#include /**/ "ace/pre.h"

#include "locator_export.h"

#include "Adapter_Activator.h"
#include "Forwarder.h"
#include "INS_Locator.h"
#include "Locator_Options.h"
#include "Locator_Repository.h"

#include "orbsvcs/orbsvcs/IOR_Multicast.h"

#include "ImR_LocatorS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class ACE_Reactor;

// Gets a request from a client and depending on the POA name,
// requests an activator to take care of activating the
// corresponding server and raises a forward exception to the
// client pointing to the correct server.
class Locator_Export ImR_Locator_i : public virtual POA_ImplementationRepository::Locator
{
public:
  ImR_Locator_i();

  /// Initialize the service, creating its own orb, poa, etc.
  int init (Options& opts ACE_ENV_ARG_DECL);

  /// Same as above, but use the given orb
  int init_with_orb (CORBA::ORB_ptr orb, Options& opts ACE_ENV_ARG_DECL);

  /// Cleans up any state created by init*.
  int fini (ACE_ENV_SINGLE_ARG_DECL);

  /// Run using the orb reference created during init()
  int run (ACE_ENV_SINGLE_ARG_DECL);

  // Note : See the IDL for descriptions of the operations.

  // Activator->Locator

  virtual CORBA::Long register_activator (const char* name,
    ImplementationRepository::Activator_ptr admin
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));
  virtual void unregister_activator (const char* name,
    CORBA::Long token ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

  // tao_imr->Locator

  virtual void activate_server (const char * name
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException,
    ImplementationRepository::NotFound,
    ImplementationRepository::CannotActivate));
  virtual void register_server (const char * name,
    const ImplementationRepository::StartupOptions &options
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException,
    ImplementationRepository::AlreadyRegistered,
    ImplementationRepository::NotFound));
  virtual void reregister_server (const char * name,
    const ImplementationRepository::StartupOptions &options
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException,
    ImplementationRepository::AlreadyRegistered,
    ImplementationRepository::NotFound ));
  virtual void remove_server (const char * name
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException, ImplementationRepository::NotFound));
  virtual void shutdown_server (const char * name
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException, ImplementationRepository::NotFound));
  virtual void find (const char * name,
    ImplementationRepository::ServerInformation_out info
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException, ImplementationRepository::NotFound));
  virtual void list (
    CORBA::ULong how_many,
    ImplementationRepository::ServerInformationList_out server_list,
    ImplementationRepository::ServerInformationIterator_out server_iterator
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

  // Server->Locator

  virtual void server_is_running (const char* name,
    const char* partial_ior,
    ImplementationRepository::ServerObject_ptr server_object
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException, ImplementationRepository::NotFound));
  virtual void server_is_shutting_down (const char * name ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException, ImplementationRepository::NotFound));

  // Used by the INS_Locator to start a sever given an object name
  char* activate_server_by_object (const char* object_name ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException,
    ImplementationRepository::NotFound,
    ImplementationRepository::CannotActivate));

  char* activate_server_by_name (const char * name, bool manual_start ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException,
    ImplementationRepository::NotFound,
    ImplementationRepository::CannotActivate));

  void server_status_changed(Server_Info& info);

private:

  char* activate_server_i (Server_Info& info, bool manual_start ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException,
    ImplementationRepository::NotFound,
    ImplementationRepository::CannotActivate));

  void start_server(Server_Info& info, bool manual_start ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException,
    ImplementationRepository::NotFound,
    ImplementationRepository::CannotActivate));

  void register_server_i (const char * name,
    const ImplementationRepository::StartupOptions &options,
    bool allow_updates
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException,
    ImplementationRepository::AlreadyRegistered,
    ImplementationRepository::NotFound ));

  bool is_alive(Server_Info& info);
  int is_alive_i(Server_Info& info);

  // Set up the multicast related if 'm' is passed on the command
  // line.
  int setup_multicast (ACE_Reactor *reactor, const char *ior);

  void unregister_activator_i(const char* activator);

  Activator_Info_Ptr get_activator (const ACE_CString& name);
  void connect_activator (Activator_Info& info);

  void auto_start_servers(ACE_ENV_SINGLE_ARG_DECL);

  void set_timeout_policy(CORBA::Object_ptr obj, const ACE_Time_Value& to);

  void connect_server(Server_Info& info);

private:

  // The class that handles the forwarding.
  ImR_Forwarder forwarder_;

  // Used for the forwarding of any type of POA.
  ImR_Adapter adapter_;

  /// The locator interface for the IORTable
  INS_Locator ins_locator_;

  CORBA::ORB_var orb_;
  PortableServer::POA_var root_poa_;
  PortableServer::POA_var imr_poa_;

  int debug_;

  TAO_IOR_Multicast ior_multicast_;

  Locator_Repository repository_;

  bool read_only_;
  ACE_Time_Value startup_timeout_;
  ACE_Time_Value ping_interval_;
};

#include /**/ "ace/post.h"
#endif /* IMR_LOCATOR_I_H */

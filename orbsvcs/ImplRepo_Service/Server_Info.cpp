// $Id$
#include "Server_Info.h"

Server_Info::Server_Info
(
 const ACE_CString& server_name,
 const ACE_CString& aname,
 const ACE_CString& cmdline,
 const ImplementationRepository::EnvironmentList& env,
 const ACE_CString& working_dir,
 ImplementationRepository::ActivationMode amode,
 int limit,
 const ACE_CString& partial_ior,
 const ACE_CString& server_ior,
 ImplementationRepository::ServerObject_ptr svrobj
 )
 : name(server_name)
 , activator(aname)
 , cmdline(cmdline)
 , env_vars(env)
 , dir(working_dir)
 , activation_mode(amode)
 , start_limit (limit)
 , partial_ior(partial_ior)
 , ior(server_ior)
 , server(ImplementationRepository::ServerObject::_duplicate(svrobj))
 , start_count(0)
{
}

ImplementationRepository::ServerInformation*
Server_Info::createImRServerInfo(ACE_ENV_SINGLE_ARG_DECL)
{
  ImplementationRepository::ServerInformation* info;
  ACE_NEW_THROW_EX (info, ImplementationRepository::ServerInformation, CORBA::NO_MEMORY());

  info->server = name.c_str();
  info->startup.command_line = cmdline.c_str();
  info->startup.environment = env_vars;
  info->startup.working_directory = dir.c_str();
  info->startup.activation = activation_mode;
  info->startup.activator = activator.c_str();
  info->startup.start_limit = start_limit;
  info->partial_ior = partial_ior.c_str();

  return info;
}

void
Server_Info::reset(void)
{
  ior = "";
  partial_ior = "";
  last_ping = ACE_Time_Value::zero;
  server = ImplementationRepository::ServerObject::_nil();
  // start_count = 0; Note : We can't do this, because it would be reset during startup.
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_Strong_Bound_Ptr<Server_Info, ACE_Null_Mutex>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate ACE_Strong_Bound_Ptr<Server_Info, ACE_Null_Mutex>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// $Id$

ACE_INLINE
TAO::CSD::TP_Collocated_Synch_With_Server_Request::TP_Collocated_Synch_With_Server_Request
                             (TAO_ServerRequest&              server_request,
                              const PortableServer::ObjectId& object_id,
                              PortableServer::POA_ptr         poa,
                              const char*                     operation,
                              PortableServer::Servant         servant,
                              TP_Servant_State*               servant_state)
  : TP_Corba_Request(object_id,
                     poa,
                     operation,
                     servant,
                     servant_state,
                     server_request)
{
}


ACE_INLINE
bool
TAO::CSD::TP_Collocated_Synch_With_Server_Request::wait(ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
{
  return this->synch_helper_.wait_while_pending();
}


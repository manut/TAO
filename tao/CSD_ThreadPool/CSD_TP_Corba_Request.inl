// $Id$


ACE_INLINE
TAO::CSD::TP_Corba_Request::TP_Corba_Request
                             (const PortableServer::ObjectId& object_id,
                              PortableServer::POA_ptr         poa,
                              const char*                     operation,
                              PortableServer::Servant         servant,
                              TP_Servant_State*               servant_state,
                              TAO_ServerRequest&              server_request)
  : TP_Request(servant,servant_state),
    object_id_(object_id),
    operation_(operation),
    server_request_(server_request)
{
  this->poa_ = PortableServer::POA::_duplicate(poa);
}


ACE_INLINE
void
TAO::CSD::TP_Corba_Request::do_clone()
{
  this->server_request_.clone();
}

ACE_INLINE
void
TAO::CSD::TP_Corba_Request::do_dispatch(ACE_ENV_SINGLE_ARG_DECL)
{
  this->server_request_.dispatch(this->servant() ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}


ACE_INLINE
void
TAO::CSD::TP_Corba_Request::do_cancel()
{
  this->server_request_.cancel();
}

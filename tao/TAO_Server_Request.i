// -*- C++ -*-
// $Id$

ACE_INLINE TAO_ORB_Core *
TAO_ServerRequest::orb_core (void)
{
  return this->orb_core_;
}

ACE_INLINE TAO_InputCDR &
TAO_ServerRequest::incoming (void)
{
  return *this->incoming_;
}

ACE_INLINE TAO_OutputCDR &
TAO_ServerRequest::outgoing (void)
{
  return *this->outgoing_;
}

ACE_INLINE const char *
TAO_ServerRequest::operation (void) const
{
  return this->operation_.c_str ();
}

ACE_INLINE void
TAO_ServerRequest::operation (ACE_CString &operation)
{
  this->operation_ = operation;
}

ACE_INLINE unsigned int
TAO_ServerRequest::operation_length (void) const
{
  return this->operation_.length ();
}

ACE_INLINE CORBA::Boolean
TAO_ServerRequest::response_expected (void) const
{
  return this->response_expected_;
}

ACE_INLINE CORBA::Boolean
TAO_ServerRequest::deferred_reply (void) const
{
  return this->deferred_reply_;
}

ACE_INLINE void
TAO_ServerRequest::response_expected (CORBA::Boolean response)
{
  this->response_expected_ = response;
}

ACE_INLINE CORBA::Boolean
TAO_ServerRequest::sync_with_server (void) const
{
  return this->sync_with_server_;
}

ACE_INLINE void
TAO_ServerRequest::sync_with_server (CORBA::Boolean sync_flag)
{
  this->sync_with_server_ = sync_flag;
}

ACE_INLINE CORBA::Principal_ptr
TAO_ServerRequest::principal (void) const
{
  return this->requesting_principal_.ptr ();
}

ACE_INLINE TAO_ObjectKey &
TAO_ServerRequest::object_key (void)
{
  return this->profile_.object_key ();
}

ACE_INLINE IOP::ServiceContextList &
TAO_ServerRequest::service_info (void)
{
  return this->service_info_;
}

ACE_INLINE void
TAO_ServerRequest::service_info (IOP::ServiceContextList &service_info)
{
  this->service_info_ = service_info;
}

ACE_INLINE CORBA::ULong
TAO_ServerRequest::request_id (void)
{
  return this->request_id_;
}

ACE_INLINE void
TAO_ServerRequest::request_id (CORBA::ULong req)
{
  this->request_id_ = req;
}

ACE_INLINE void
TAO_ServerRequest::requesting_principal (CORBA_Principal_ptr principal)
{
  this->requesting_principal_ = principal;
}

ACE_INLINE TAO_Tagged_Profile &
TAO_ServerRequest::profile (void)
{
  return this->profile_;
}

ACE_INLINE CORBA::Object_ptr
TAO_ServerRequest::forward_location (void)
{
  return CORBA::Object::_duplicate (this->forward_location_.in ());
}

ACE_INLINE CORBA::ULong
TAO_ServerRequest::exception_type (void)
{
  return this->exception_type_;
}

ACE_INLINE void
TAO_ServerRequest::exception_type (CORBA::ULong except_type)
{
  this->exception_type_ = except_type;
}

ACE_INLINE void 
TAO_ServerRequest::is_dsi (void)
{
  this->is_dsi_ = 1;
}

ACE_INLINE void 
TAO_ServerRequest::dsi_nvlist_align (ptr_arith_t alignment)
{
  this->dsi_nvlist_align_ = alignment;
}


/* -*- C++ -*- $Id$ */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html


#if (TAO_HAS_AMI_POLLER == 1)
#if defined (ACE_HAS_USING_KEYWORD)
template <class T> ACE_INLINE
POA_Messaging::ReplyHandler_tie<T>::ReplyHandler_tie (T &t)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_Messaging::ReplyHandler_tie<T>::ReplyHandler_tie (T &t, PortableServer::POA_ptr poa)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_Messaging::ReplyHandler_tie<T>::ReplyHandler_tie (T *tp, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_Messaging::ReplyHandler_tie<T>::ReplyHandler_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_Messaging::ReplyHandler_tie<T>::~ReplyHandler_tie (void)
{
  if (this->rel_) delete this->ptr_;
}

template <class T> ACE_INLINE T *
POA_Messaging::ReplyHandler_tie<T>::_tied_object (void)
{
  return this->ptr_;
}

template <class T> ACE_INLINE void
POA_Messaging::ReplyHandler_tie<T>::_tied_object (T &obj)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = &obj;
  this->rel_ = 0;
}

template <class T> ACE_INLINE void
POA_Messaging::ReplyHandler_tie<T>::_tied_object (T *obj, CORBA::Boolean release)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = obj;
  this->rel_ = release;
}

template <class T> ACE_INLINE CORBA::Boolean
POA_Messaging::ReplyHandler_tie<T>::_is_owner (void)
{
  return this->rel_;
}

template <class T> ACE_INLINE void
POA_Messaging::ReplyHandler_tie<T>::_is_owner (CORBA::Boolean b)
{
  this->rel_ = b;
}

template <class T> ACE_INLINE PortableServer::POA_ptr
POA_Messaging::ReplyHandler_tie<T>::_default_POA (CORBA::Environment &ACE_TRY_ENV)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());

  return this->ReplyHandler::_default_POA (ACE_TRY_ENV);
}

#endif /* ACE_HAS_USING_KEYWORD */
#endif /* TAO_HAS_AMI_POLLER == 1 */

// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html


// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/tie_si.cpp:96

#if defined (ACE_HAS_USING_KEYWORD)

template <class T> ACE_INLINE
POA_ImplementationRepository::ServerObject_tie<T>::ServerObject_tie (T &t)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_ImplementationRepository::ServerObject_tie<T>::ServerObject_tie (T &t, PortableServer::POA_ptr poa)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_ImplementationRepository::ServerObject_tie<T>::ServerObject_tie (T *tp, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_ImplementationRepository::ServerObject_tie<T>::ServerObject_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_ImplementationRepository::ServerObject_tie<T>::~ServerObject_tie (void)
{
  if (this->rel_)
    {
      delete this->ptr_;
    }
}

template <class T> ACE_INLINE T *
POA_ImplementationRepository::ServerObject_tie<T>::_tied_object (void)
{
  return this->ptr_;
}

template <class T> ACE_INLINE void
POA_ImplementationRepository::ServerObject_tie<T>::_tied_object (T &obj)
{
  if (this->rel_)
    {
      delete this->ptr_;
    }
  
  this->ptr_ = &obj;
  this->rel_ = 0;
}

template <class T> ACE_INLINE void
POA_ImplementationRepository::ServerObject_tie<T>::_tied_object (T *obj, CORBA::Boolean release)
{
  if (this->rel_)
    {
      delete this->ptr_;
    }
  
  this->ptr_ = obj;
  this->rel_ = release;
}

template <class T> ACE_INLINE CORBA::Boolean
POA_ImplementationRepository::ServerObject_tie<T>::_is_owner (void)
{
  return this->rel_;
}

template <class T> ACE_INLINE void
POA_ImplementationRepository::ServerObject_tie<T>::_is_owner (CORBA::Boolean b)
{
  this->rel_ = b;
}

template <class T> ACE_INLINE PortableServer::POA_ptr
POA_ImplementationRepository::ServerObject_tie<T>::_default_POA (ACE_ENV_SINGLE_ARG_DECL)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    {
      return PortableServer::POA::_duplicate (this->poa_.in ());
    }
  
  return this->ServerObject::_default_POA (ACE_ENV_SINGLE_ARG_PARAMETER);
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
void POA_ImplementationRepository::ServerObject_tie<T>::ping  (
    ACE_ENV_SINGLE_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->ping (
    ACE_ENV_SINGLE_ARG_PARAMETER
  );
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
void POA_ImplementationRepository::ServerObject_tie<T>::shutdown  (
    ACE_ENV_SINGLE_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->shutdown (
    ACE_ENV_SINGLE_ARG_PARAMETER
  );
}

#endif /* ACE_HAS_USING_KEYWORD */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/tie_si.cpp:96

#if defined (ACE_HAS_USING_KEYWORD)

template <class T> ACE_INLINE
POA_ImplementationRepository::Administration_tie<T>::Administration_tie (T &t)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_ImplementationRepository::Administration_tie<T>::Administration_tie (T &t, PortableServer::POA_ptr poa)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_ImplementationRepository::Administration_tie<T>::Administration_tie (T *tp, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_ImplementationRepository::Administration_tie<T>::Administration_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_ImplementationRepository::Administration_tie<T>::~Administration_tie (void)
{
  if (this->rel_)
    {
      delete this->ptr_;
    }
}

template <class T> ACE_INLINE T *
POA_ImplementationRepository::Administration_tie<T>::_tied_object (void)
{
  return this->ptr_;
}

template <class T> ACE_INLINE void
POA_ImplementationRepository::Administration_tie<T>::_tied_object (T &obj)
{
  if (this->rel_)
    {
      delete this->ptr_;
    }
  
  this->ptr_ = &obj;
  this->rel_ = 0;
}

template <class T> ACE_INLINE void
POA_ImplementationRepository::Administration_tie<T>::_tied_object (T *obj, CORBA::Boolean release)
{
  if (this->rel_)
    {
      delete this->ptr_;
    }
  
  this->ptr_ = obj;
  this->rel_ = release;
}

template <class T> ACE_INLINE CORBA::Boolean
POA_ImplementationRepository::Administration_tie<T>::_is_owner (void)
{
  return this->rel_;
}

template <class T> ACE_INLINE void
POA_ImplementationRepository::Administration_tie<T>::_is_owner (CORBA::Boolean b)
{
  this->rel_ = b;
}

template <class T> ACE_INLINE PortableServer::POA_ptr
POA_ImplementationRepository::Administration_tie<T>::_default_POA (ACE_ENV_SINGLE_ARG_DECL)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    {
      return PortableServer::POA::_duplicate (this->poa_.in ());
    }
  
  return this->Administration::_default_POA (ACE_ENV_SINGLE_ARG_PARAMETER);
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
void POA_ImplementationRepository::Administration_tie<T>::activate_server  (
    const char * server
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
    , ImplementationRepository::NotFound
    , ImplementationRepository::CannotActivate
  ))
{
  this->ptr_->activate_server (
    server
    ACE_ENV_ARG_PARAMETER
  );
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
char * POA_ImplementationRepository::Administration_tie<T>::activate_server_with_startup  (
    const char * server,
    CORBA::Long check_startup
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
    , ImplementationRepository::NotFound
    , ImplementationRepository::CannotActivate
  ))
{
  return this->ptr_->activate_server_with_startup (
    server,
    check_startup
    ACE_ENV_ARG_PARAMETER
  );
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
void POA_ImplementationRepository::Administration_tie<T>::register_server  (
    const char * server,
    const ImplementationRepository::StartupOptions & options
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
    , ImplementationRepository::AlreadyRegistered
  ))
{
  this->ptr_->register_server (
    server,
    options
    ACE_ENV_ARG_PARAMETER
  );
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
void POA_ImplementationRepository::Administration_tie<T>::reregister_server  (
    const char * server,
    const ImplementationRepository::StartupOptions & options
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->reregister_server (
    server,
    options
    ACE_ENV_ARG_PARAMETER
  );
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
void POA_ImplementationRepository::Administration_tie<T>::remove_server  (
    const char * server
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
    , ImplementationRepository::NotFound
  ))
{
  this->ptr_->remove_server (
    server
    ACE_ENV_ARG_PARAMETER
  );
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
void POA_ImplementationRepository::Administration_tie<T>::shutdown_server  (
    const char * server
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
    , ImplementationRepository::NotFound
  ))
{
  this->ptr_->shutdown_server (
    server
    ACE_ENV_ARG_PARAMETER
  );
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
char * POA_ImplementationRepository::Administration_tie<T>::server_is_running  (
    const char * server,
    const char * addr,
    ImplementationRepository::ServerObject_ptr server_object
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
    , ImplementationRepository::NotFound
  ))
{
  return this->ptr_->server_is_running (
    server,
    addr,
    server_object
    ACE_ENV_ARG_PARAMETER
  );
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
void POA_ImplementationRepository::Administration_tie<T>::server_is_shutting_down  (
    const char * server
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
    , ImplementationRepository::NotFound
  ))
{
  this->ptr_->server_is_shutting_down (
    server
    ACE_ENV_ARG_PARAMETER
  );
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
void POA_ImplementationRepository::Administration_tie<T>::find  (
    const char * server,
    ImplementationRepository::ServerInformation_out info
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
    , ImplementationRepository::NotFound
  ))
{
  this->ptr_->find (
    server,
    info
    ACE_ENV_ARG_PARAMETER
  );
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
void POA_ImplementationRepository::Administration_tie<T>::list  (
    CORBA::ULong how_many,
    ImplementationRepository::ServerInformationList_out server_list,
    ImplementationRepository::ServerInformationIterator_out server_iterator
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->list (
    how_many,
    server_list,
    server_iterator
    ACE_ENV_ARG_PARAMETER
  );
}

#endif /* ACE_HAS_USING_KEYWORD */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/tie_si.cpp:96

#if defined (ACE_HAS_USING_KEYWORD)

template <class T> ACE_INLINE
POA_ImplementationRepository::ServerInformationIterator_tie<T>::ServerInformationIterator_tie (T &t)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_ImplementationRepository::ServerInformationIterator_tie<T>::ServerInformationIterator_tie (T &t, PortableServer::POA_ptr poa)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_ImplementationRepository::ServerInformationIterator_tie<T>::ServerInformationIterator_tie (T *tp, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_ImplementationRepository::ServerInformationIterator_tie<T>::ServerInformationIterator_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_ImplementationRepository::ServerInformationIterator_tie<T>::~ServerInformationIterator_tie (void)
{
  if (this->rel_)
    {
      delete this->ptr_;
    }
}

template <class T> ACE_INLINE T *
POA_ImplementationRepository::ServerInformationIterator_tie<T>::_tied_object (void)
{
  return this->ptr_;
}

template <class T> ACE_INLINE void
POA_ImplementationRepository::ServerInformationIterator_tie<T>::_tied_object (T &obj)
{
  if (this->rel_)
    {
      delete this->ptr_;
    }
  
  this->ptr_ = &obj;
  this->rel_ = 0;
}

template <class T> ACE_INLINE void
POA_ImplementationRepository::ServerInformationIterator_tie<T>::_tied_object (T *obj, CORBA::Boolean release)
{
  if (this->rel_)
    {
      delete this->ptr_;
    }
  
  this->ptr_ = obj;
  this->rel_ = release;
}

template <class T> ACE_INLINE CORBA::Boolean
POA_ImplementationRepository::ServerInformationIterator_tie<T>::_is_owner (void)
{
  return this->rel_;
}

template <class T> ACE_INLINE void
POA_ImplementationRepository::ServerInformationIterator_tie<T>::_is_owner (CORBA::Boolean b)
{
  this->rel_ = b;
}

template <class T> ACE_INLINE PortableServer::POA_ptr
POA_ImplementationRepository::ServerInformationIterator_tie<T>::_default_POA (ACE_ENV_SINGLE_ARG_DECL)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    {
      return PortableServer::POA::_duplicate (this->poa_.in ());
    }
  
  return this->ServerInformationIterator::_default_POA (ACE_ENV_SINGLE_ARG_PARAMETER);
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
CORBA::Boolean POA_ImplementationRepository::ServerInformationIterator_tie<T>::next_n  (
    CORBA::ULong how_many,
    ImplementationRepository::ServerInformationList_out server_list
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->next_n (
    how_many,
    server_list
    ACE_ENV_ARG_PARAMETER
  );
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
void POA_ImplementationRepository::ServerInformationIterator_tie<T>::destroy  (
    ACE_ENV_SINGLE_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->destroy (
    ACE_ENV_SINGLE_ARG_PARAMETER
  );
}

#endif /* ACE_HAS_USING_KEYWORD */


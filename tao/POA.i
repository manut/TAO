// $Id$

// Exception macros
#include "tao/poa_macros.h"
#include "tao/Environment.h"

#if !defined (TAO_HAS_MINIMUM_CORBA)

ACE_INLINE PortableServer::ThreadPolicyValue
TAO_POA_Policies::thread (void) const
{
  return this->thread_;
}

ACE_INLINE void
TAO_POA_Policies::thread (PortableServer::ThreadPolicyValue value)
{
  this->thread_ = value;
}

#endif /* TAO_HAS_MINIMUM_CORBA */

ACE_INLINE PortableServer::LifespanPolicyValue
TAO_POA_Policies::lifespan (void) const
{
  return this->lifespan_;
}

ACE_INLINE void
TAO_POA_Policies::lifespan (PortableServer::LifespanPolicyValue value)
{
  this->lifespan_ = value;
}

ACE_INLINE PortableServer::IdUniquenessPolicyValue
TAO_POA_Policies::id_uniqueness (void) const
{
  return this->id_uniqueness_;
}

ACE_INLINE void
TAO_POA_Policies::id_uniqueness (PortableServer::IdUniquenessPolicyValue value)
{
  this->id_uniqueness_ = value;
}

ACE_INLINE PortableServer::IdAssignmentPolicyValue
TAO_POA_Policies::id_assignment (void) const
{
  return this->id_assignment_;
}

ACE_INLINE void
TAO_POA_Policies::id_assignment (PortableServer::IdAssignmentPolicyValue value)
{
  this->id_assignment_ = value;
}

ACE_INLINE PortableServer::ImplicitActivationPolicyValue
TAO_POA_Policies::implicit_activation (void) const
{
  return this->implicit_activation_;
}

ACE_INLINE void
TAO_POA_Policies::implicit_activation (PortableServer::ImplicitActivationPolicyValue value)
{
  this->implicit_activation_ = value;
}

ACE_INLINE PortableServer::ServantRetentionPolicyValue
TAO_POA_Policies::servant_retention (void) const
{
  return this->servant_retention_;
}

ACE_INLINE void
TAO_POA_Policies::servant_retention (PortableServer::ServantRetentionPolicyValue value)
{
  this->servant_retention_ = value;
}

ACE_INLINE PortableServer::RequestProcessingPolicyValue
TAO_POA_Policies::request_processing (void) const
{
  return this->request_processing_;
}

ACE_INLINE void
TAO_POA_Policies::request_processing (PortableServer::RequestProcessingPolicyValue value)
{
  this->request_processing_ = value;
}

ACE_INLINE CORBA::ULong
TAO_Creation_Time::creation_time_length (void)
{
  return 2 * sizeof (CORBA::ULong);
}

ACE_INLINE
TAO_Creation_Time::TAO_Creation_Time (const ACE_Time_Value &creation_time)
{
  this->time_stamp_[TAO_Creation_Time::SEC_FIELD]  = (CORBA::ULong) creation_time.sec ();
  this->time_stamp_[TAO_Creation_Time::USEC_FIELD] = (CORBA::ULong) creation_time.usec ();
}

ACE_INLINE
TAO_Creation_Time::TAO_Creation_Time (void)
{
  this->time_stamp_[TAO_Creation_Time::SEC_FIELD]  = 0;
  this->time_stamp_[TAO_Creation_Time::USEC_FIELD] = 0;
}

ACE_INLINE void
TAO_Creation_Time::creation_time (const void *creation_time)
{
  ACE_OS::memcpy (&this->time_stamp_,
                  creation_time,
                  TAO_Creation_Time::creation_time_length ());
}

ACE_INLINE const void *
TAO_Creation_Time::creation_time (void) const
{
  return &this->time_stamp_;
}

ACE_INLINE int
TAO_Creation_Time::operator== (const TAO_Creation_Time &rhs) const
{
#if defined (POA_NO_TIMESTAMP)
  ACE_UNUSED_ARG (rhs);
  return 1;
#else
  return ACE_OS::memcmp (&this->time_stamp_,
                         &rhs.time_stamp_,
                         TAO_Creation_Time::creation_time_length ()) == 0;
#endif /* POA_NO_TIMESTAMP */
}

ACE_INLINE int
TAO_Creation_Time::operator!= (const TAO_Creation_Time &rhs) const
{
#if defined (POA_NO_TIMESTAMP)
  ACE_UNUSED_ARG (rhs);
  return 0;
#else
  return ACE_OS::memcmp (&this->time_stamp_,
                         &rhs.time_stamp_,
                         TAO_Creation_Time::creation_time_length ()) != 0;
#endif /* POA_NO_TIMESTAMP */
}

ACE_INLINE int
TAO_Temporary_Creation_Time::operator== (const TAO_Creation_Time &rhs) const
{
#if defined (POA_NO_TIMESTAMP)
  ACE_UNUSED_ARG (rhs);
  return 1;
#else
  return ACE_OS::memcmp (this->time_stamp_,
                         rhs.creation_time (),
                         TAO_Creation_Time::creation_time_length ()) == 0;
#endif /* POA_NO_TIMESTAMP */
}

ACE_INLINE int
TAO_Temporary_Creation_Time::operator!= (const TAO_Creation_Time &rhs) const
{
#if defined (POA_NO_TIMESTAMP)
  ACE_UNUSED_ARG (rhs);
  return 0;
#else
  return ACE_OS::memcmp (this->time_stamp_,
                         rhs.creation_time (),
                         TAO_Creation_Time::creation_time_length ()) != 0;
#endif /* POA_NO_TIMESTAMP */
}

ACE_INLINE int
TAO_Creation_Time::operator== (const TAO_Temporary_Creation_Time &rhs) const
{
  return rhs == *this;
}

ACE_INLINE int
TAO_Creation_Time::operator!= (const TAO_Temporary_Creation_Time &rhs) const
{
  return rhs != *this;
}

ACE_INLINE
TAO_Temporary_Creation_Time::TAO_Temporary_Creation_Time (void)
  : time_stamp_ (0)
{
}

ACE_INLINE void
TAO_Temporary_Creation_Time::creation_time (const void *creation_time)
{
  this->time_stamp_ = (void *) creation_time;
}

ACE_INLINE ACE_Lock &
TAO_POA::lock (void)
{
  return this->lock_;
}

ACE_INLINE TAO_POA *
TAO_POA::create_POA (const TAO_POA::String &adapter_name,
                     TAO_POA_Manager &poa_manager,
                     const TAO_POA_Policies &policies,
                     CORBA::Environment &ACE_TRY_ENV)
{
  // Lock access for the duration of this transaction.
  TAO_POA_GUARD_RETURN (ACE_Lock, monitor, this->lock (), 0, ACE_TRY_ENV);

  return this->create_POA_i (adapter_name,
                             poa_manager,
                             policies,
                             ACE_TRY_ENV);
}

ACE_INLINE void
TAO_POA::destroy (CORBA::Boolean etherealize_objects,
                  CORBA::Boolean wait_for_completion,
                  CORBA::Environment &ACE_TRY_ENV)
{
  // Lock access for the duration of this transaction.
  TAO_POA_GUARD (ACE_Lock, monitor, this->lock (), ACE_TRY_ENV);

  this->destroy_i (etherealize_objects,
                   wait_for_completion,
                   ACE_TRY_ENV);
}

ACE_INLINE TAO_POA_Policies &
TAO_POA::policies (void)
{
  return this->policies_;
}

ACE_INLINE TAO_Active_Object_Map &
TAO_POA::active_object_map (void) const
{
  return *this->active_object_map_;
}

#if !defined (TAO_HAS_MINIMUM_CORBA)

ACE_INLINE PortableServer::ServantManager_ptr
TAO_POA::get_servant_manager (CORBA::Environment &ACE_TRY_ENV)
{
  // Lock access for the duration of this transaction.
  TAO_POA_GUARD_RETURN (ACE_Lock, monitor, this->lock (), PortableServer::ServantManager::_nil (), ACE_TRY_ENV);

  return this->get_servant_manager_i (ACE_TRY_ENV);
}

ACE_INLINE void
TAO_POA::set_servant_manager (PortableServer::ServantManager_ptr imgr,
                              CORBA::Environment &ACE_TRY_ENV)
{
  // Lock access for the duration of this transaction.
  TAO_POA_GUARD (ACE_Lock, monitor, this->lock (), ACE_TRY_ENV);

  this->set_servant_manager_i (imgr,
                               ACE_TRY_ENV);
}

ACE_INLINE PortableServer::Servant
TAO_POA::get_servant (CORBA::Environment &ACE_TRY_ENV)
{
  // Lock access for the duration of this transaction.
  TAO_POA_GUARD_RETURN (ACE_Lock, monitor, this->lock (), 0, ACE_TRY_ENV);

  return this->get_servant_i (ACE_TRY_ENV);
}

ACE_INLINE void
TAO_POA::set_servant (PortableServer::Servant servant,
                      CORBA::Environment &ACE_TRY_ENV)
{
  // Lock access for the duration of this transaction.
  TAO_POA_GUARD (ACE_Lock, monitor, this->lock (), ACE_TRY_ENV);

  this->set_servant_i (servant,
                       ACE_TRY_ENV);
}

#endif /* TAO_HAS_MINIMUM_CORBA */

ACE_INLINE PortableServer::ObjectId *
TAO_POA::activate_object (PortableServer::Servant servant,
                          CORBA::Environment &ACE_TRY_ENV)
{
  // Lock access for the duration of this transaction.
  TAO_POA_GUARD_RETURN (ACE_Lock, monitor, this->lock (), 0, ACE_TRY_ENV);

  return this->activate_object_i (servant,
                                  ACE_TRY_ENV);
}

ACE_INLINE void
TAO_POA::activate_object_with_id (const PortableServer::ObjectId &id,
                                  PortableServer::Servant servant,
                                  CORBA::Environment &ACE_TRY_ENV)
{
  // Lock access for the duration of this transaction.
  TAO_POA_GUARD (ACE_Lock, monitor, this->lock (), ACE_TRY_ENV);

  this->activate_object_with_id_i (id,
                                   servant,
                                   ACE_TRY_ENV);
}

ACE_INLINE void
TAO_POA::deactivate_object (const PortableServer::ObjectId &oid,
                            CORBA::Environment &ACE_TRY_ENV)
{
  // Lock access for the duration of this transaction.
  TAO_POA_GUARD (ACE_Lock, monitor, this->lock (), ACE_TRY_ENV);

  this->deactivate_object_i (oid,
                             ACE_TRY_ENV);
}

ACE_INLINE CORBA::Object_ptr
TAO_POA::create_reference (const char *intf,
                           CORBA::Environment &ACE_TRY_ENV)
{
  // Lock access for the duration of this transaction.
  TAO_POA_GUARD_RETURN (ACE_Lock, monitor, this->lock (), CORBA::Object::_nil (), ACE_TRY_ENV);

  return this->create_reference_i (intf,
                                   ACE_TRY_ENV);
}

ACE_INLINE CORBA::Object_ptr
TAO_POA::create_reference_with_id (const PortableServer::ObjectId &id,
                                   const char *intf,
                                   CORBA::Environment &ACE_TRY_ENV)
{
  // Lock access for the duration of this transaction.
  TAO_POA_GUARD_RETURN (ACE_Lock, monitor, this->lock (), CORBA::Object::_nil (), ACE_TRY_ENV);

  return this->create_reference_with_id_i (id,
                                           intf,
                                           ACE_TRY_ENV);
}

ACE_INLINE PortableServer::ObjectId *
TAO_POA::servant_to_id (PortableServer::Servant servant,
                        CORBA::Environment &ACE_TRY_ENV)
{
  // If we had upgradeable locks, this would initially be a read lock
  //
  // Lock access for the duration of this transaction.
  TAO_POA_GUARD_RETURN (ACE_Lock, monitor, this->lock (), 0, ACE_TRY_ENV);

  return this->servant_to_id_i (servant,
                                ACE_TRY_ENV);
}

ACE_INLINE PortableServer::ObjectId *
TAO_POA::servant_to_system_id (PortableServer::Servant servant,
                               CORBA::Environment &ACE_TRY_ENV)
{
  // Lock access for the duration of this transaction.
  TAO_POA_GUARD_RETURN (ACE_Lock, monitor, this->lock (), 0, ACE_TRY_ENV);

  return this->servant_to_system_id_i (servant,
                                       ACE_TRY_ENV);
}

ACE_INLINE PortableServer::Servant
TAO_POA::id_to_servant (const PortableServer::ObjectId &oid,
                        CORBA::Environment &ACE_TRY_ENV)
{
  // Lock access for the duration of this transaction.
  TAO_POA_GUARD_RETURN (ACE_Lock, monitor, this->lock (), 0, ACE_TRY_ENV);

  return this->id_to_servant_i (oid,
                                ACE_TRY_ENV);
}

ACE_INLINE CORBA::Object_ptr
TAO_POA::id_to_reference (const PortableServer::ObjectId &oid,
                          CORBA::Environment &ACE_TRY_ENV)
{
  // Lock access for the duration of this transaction.
  TAO_POA_GUARD_RETURN (ACE_Lock, monitor, this->lock (), 0, ACE_TRY_ENV);

  return this->id_to_reference_i (oid, ACE_TRY_ENV);
}

#if !defined (TAO_HAS_MINIMUM_CORBA)

ACE_INLINE void
TAO_POA::forward_object (const PortableServer::ObjectId &oid,
                         CORBA::Object_ptr forward_to,
                         CORBA::Environment &ACE_TRY_ENV)
{
  // Lock access for the duration of this transaction.
  TAO_POA_GUARD (ACE_Lock, monitor, this->lock (), ACE_TRY_ENV);

  this->forward_object_i (oid,
                          forward_to,
                          ACE_TRY_ENV);
}

#endif /* TAO_HAS_MINIMUM_CORBA */

ACE_INLINE PortableServer::POA_ptr
TAO_POA::the_parent (CORBA::Environment &ACE_TRY_ENV)
{
  if (this->parent_ != 0)
    return this->parent_->_this (ACE_TRY_ENV);
  else
    return PortableServer::POA::_nil ();
}

ACE_INLINE PortableServer::POAManager_ptr
TAO_POA::the_POAManager (CORBA::Environment &ACE_TRY_ENV)
{
  return this->poa_manager_._this (ACE_TRY_ENV);
}

#if !defined (TAO_HAS_MINIMUM_CORBA)

ACE_INLINE PortableServer::AdapterActivator_ptr
TAO_POA::the_activator (CORBA::Environment &ACE_TRY_ENV)
{
  // Lock access for the duration of this transaction.
  TAO_POA_GUARD_RETURN (ACE_Lock, monitor, this->lock (), PortableServer::AdapterActivator::_nil (), ACE_TRY_ENV);

  return PortableServer::AdapterActivator::_duplicate (this->adapter_activator_.in ());
}

ACE_INLINE void
TAO_POA::the_activator (PortableServer::AdapterActivator_ptr adapter_activator,
                        CORBA::Environment &ACE_TRY_ENV)
{
  // Lock access for the duration of this transaction.
  TAO_POA_GUARD (ACE_Lock, monitor, this->lock (), ACE_TRY_ENV);

  this->adapter_activator_ = PortableServer::AdapterActivator::_duplicate (adapter_activator);
}

#endif /* TAO_HAS_MINIMUM_CORBA */

ACE_INLINE const TAO_Creation_Time &
TAO_POA::creation_time (void)
{
  return this->creation_time_;
}

ACE_INLINE CORBA::Boolean
TAO_POA::system_id (void)
{
  return this->system_id_;
}


ACE_INLINE CORBA::Boolean
TAO_POA::root (void)
{
  return this->parent_ == 0;
}


ACE_INLINE CORBA::Boolean
TAO_POA::persistent (void)
{
  return this->persistent_;
}

ACE_INLINE const ACE_CString &
TAO_POA::name (void) const
{
  return this->name_;
}

ACE_INLINE CORBA::String
TAO_POA::the_name (CORBA::Environment &ACE_TRY_ENV)
{
  ACE_UNUSED_ARG (ACE_TRY_ENV);

  return CORBA::string_dup (this->name_.c_str ());
}

ACE_INLINE const TAO_Object_Adapter::poa_name &
TAO_POA::folded_name (void) const
{
  return this->folded_name_;
}

ACE_INLINE const TAO_Object_Adapter::poa_name &
TAO_POA::system_name (void) const
{
  return this->system_name_.in ();
}

ACE_INLINE char
TAO_POA::name_separator (void)
{
  return '\0';
}

ACE_INLINE CORBA::ULong
TAO_POA::name_separator_length (void)
{
  return sizeof (char);
}

ACE_INLINE char
TAO_POA::persistent_key_char (void)
{
  return 'P';
}

ACE_INLINE char
TAO_POA::transient_key_char (void)
{
  return 'T';
}

ACE_INLINE char
TAO_POA::persistent_key_type (void)
{
  if (this->persistent ())
    return TAO_POA::persistent_key_char ();
  else
    return TAO_POA::transient_key_char ();
}

ACE_INLINE CORBA::ULong
TAO_POA::persistent_key_type_length (void)
{
  return sizeof (char);
}

ACE_INLINE char
TAO_POA::system_id_key_char (void)
{
  return 'S';
}

ACE_INLINE char
TAO_POA::user_id_key_char (void)
{
  return 'U';
}

ACE_INLINE char
TAO_POA::system_id_key_type (void)
{
  if (this->system_id ())
    return TAO_POA::system_id_key_char ();
  else
    return TAO_POA::user_id_key_char ();
}

ACE_INLINE CORBA::ULong
TAO_POA::system_id_key_type_length (void)
{
  return sizeof (char);
}

ACE_INLINE char
TAO_POA::root_key_char (void)
{
  return 'R';
}

ACE_INLINE char
TAO_POA::non_root_key_char (void)
{
  return 'N';
}

ACE_INLINE char
TAO_POA::root_key_type (void)
{
  if (this->root ())
    return TAO_POA::root_key_char ();
  else
    return TAO_POA::non_root_key_char ();
}

ACE_INLINE CORBA::ULong
TAO_POA::root_key_type_length (void)
{
  return sizeof (char);
}

ACE_INLINE CORBA::ULong
TAO_POA::outstanding_requests (void) const
{
  return this->outstanding_requests_;
}

ACE_INLINE void
TAO_POA::outstanding_requests (CORBA::ULong new_outstanding_requests)
{
  this->outstanding_requests_ = new_outstanding_requests;
}

ACE_INLINE CORBA::ULong
TAO_POA::increment_outstanding_requests (void)
{
  return ++this->outstanding_requests_;
}

ACE_INLINE CORBA::ULong
TAO_POA::decrement_outstanding_requests (void)
{
  return --this->outstanding_requests_;
}

ACE_INLINE void
TAO_POA::establish_servant_lock (PortableServer::Servant servant)
{
#if !defined (TAO_HAS_MINIMUM_CORBA)
  if (this->policies ().thread () == PortableServer::SINGLE_THREAD_MODEL)
    {
      servant->_increment_single_threaded_poa_lock_count ();
    }
#endif /* TAO_HAS_MINIMUM_CORBA */
}

ACE_INLINE void
TAO_POA::teardown_servant_lock (PortableServer::Servant servant)
{
#if !defined (TAO_HAS_MINIMUM_CORBA)
  if (this->policies ().thread () == PortableServer::SINGLE_THREAD_MODEL)
    {
      servant->_decrement_single_threaded_poa_lock_count ();
    }
#endif /* TAO_HAS_MINIMUM_CORBA */
}

ACE_INLINE void
TAO_POA_Current_Impl::POA_impl (TAO_POA *impl)
{
  this->poa_impl_ = impl;
}

ACE_INLINE TAO_POA *
TAO_POA_Current_Impl::POA_impl (void) const
{
  return this->poa_impl_;
}

ACE_INLINE void
TAO_POA_Current_Impl::object_id (const PortableServer::ObjectId &id)
{
  this->object_id_ = id;
}

ACE_INLINE const PortableServer::ObjectId &
TAO_POA_Current_Impl::object_id (void) const
{
  return this->object_id_;
}

ACE_INLINE void
TAO_POA_Current_Impl::object_key (const TAO_ObjectKey &key)
{
  this->object_key_ = &key;
}

ACE_INLINE const TAO_ObjectKey &
TAO_POA_Current_Impl::object_key (void) const
{
  return *this->object_key_;
}

ACE_INLINE void
TAO_POA_Current_Impl::servant (PortableServer::Servant servant)
{
  this->servant_ = servant;
}

ACE_INLINE PortableServer::Servant
TAO_POA_Current_Impl::servant (void) const
{
  return this->servant_;
}

#if !defined (TAO_HAS_MINIMUM_CORBA)

ACE_INLINE PortableServer::ServantLocator::Cookie
TAO_POA_Current_Impl::locator_cookie (void) const
{
  return this->cookie_;
}

ACE_INLINE void
TAO_POA_Current_Impl::locator_cookie (PortableServer::ServantLocator::Cookie cookie)
{
  this->cookie_ = cookie;
}

#endif /* TAO_HAS_MINIMUM_CORBA */

ACE_INLINE void
TAO_POA_Current_Impl::active_object_map_entry (TAO_Active_Object_Map::Map_Entry *entry)
{
  this->active_object_map_entry_ = entry;
}

ACE_INLINE TAO_Active_Object_Map::Map_Entry *
TAO_POA_Current_Impl::active_object_map_entry (void) const
{
  return this->active_object_map_entry_;
}

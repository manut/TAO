// This may look like C, but it's really -*- C++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO
//
// = FILENAME
//    Servant_Base.h
//
// = AUTHOR
//     Irfan Pyarali
//
// ============================================================================

#ifndef TAO_SERVANT_BASE_H
#define TAO_SERVANT_BASE_H

#include "tao/corbafwd.h"
#include "tao/POAC.h"

class TAO_Operation_Table;

class TAO_Export TAO_ServantBase
{
  // = TITLE
  //   Base class for skeletons and servants.
  //
  // = DESCRIPTION
  //   The POA spec requires that all servants inherit from this
  //   class.
public:
  friend class TAO_POA;
  friend class TAO_Object_Adapter;
  friend class CORBA_Object;

  virtual ~TAO_ServantBase (void);
  // Destructor.

  virtual PortableServer::POA_ptr _default_POA (CORBA_Environment &TAO_IN_ENV = CORBA::default_environment ());
  // Returns the default POA for this servant.

  virtual CORBA::Boolean _is_a (const char* logical_type_id,
                                CORBA_Environment &TAO_IN_ENV = CORBA::default_environment ());
  // Local implementation of the CORBA::Object::_is_a method.

  virtual CORBA::Boolean _non_existent (CORBA_Environment &TAO_IN_ENV = CORBA::default_environment ());
  // Default <_non_existent>: always returns false.

  // = Reference counting hooks: no-ops by default.
  virtual void _add_ref (CORBA_Environment &TAO_IN_ENV = CORBA::default_environment ());
  virtual void _remove_ref (CORBA_Environment &TAO_IN_ENV = CORBA::default_environment ());

  virtual void *_downcast (const char *repository_id) = 0;
  // Get the correct vtable.

  virtual TAO_Stub *_create_stub (CORBA_Environment &TAO_IN_ENV = CORBA::default_environment ());
  // This is an auxiliar method for _this() and _narrow().

protected:
  TAO_ServantBase (void);
  // Default constructor, only derived classes can be created.

  TAO_ServantBase (const TAO_ServantBase &);
  // Copy constructor, protected so no instances can be created.

  TAO_ServantBase &operator= (const TAO_ServantBase &);
  // assignment operator.

  virtual void _dispatch (CORBA::ServerRequest &request,
                          void *context,
                          CORBA_Environment &TAO_IN_ENV = CORBA::default_environment ()) = 0;
  // Dispatches a request to the object: find the operation, cast the
  // type to the most derived type, demarshall all the parameters from
  // the request and finally invokes the operation, storing the
  // results and out parameters (if any) or the exceptions thrown into
  // <request>.

  virtual int _find (const char *opname,
                     TAO_Skeleton &skelfunc,
                     const unsigned int length = 0);
  // Find an operation in the operation table.

  virtual int _bind (const char *opname,
                     const TAO_Skeleton skel_ptr);
  // Register a CORBA IDL operation name.

  virtual const char *_interface_repository_id (void) const = 0;
  // Get this interface's repository id (TAO specific).

  TAO_Operation_Table *optable_;
  // The operation table for this servant, it is initialized by the
  // most derived class.
};

class TAO_RefCountServantBase : public virtual TAO_ServantBase
{
  // = TITLE
  //   Reference counting mix-in class.
  //
  // = DESCRIPTION
  //   The RefCountServantBase mix-in class overrides the inherited
  //   _add_ref and _remove_ref functions it inherits from
  //   ServantBase, implementing them to provide true reference
  //   counting. An instance of a servant class derived from
  //   RefCountServantBase initially has a reference count of
  //   one. Invoking _add_ref on the servant instance increases its
  //   reference count by one. Invoking _remove_ref on the servant
  //   instance decreases its reference count by one; if the resulting
  //   reference count equals zero, _remove_ref invokes delete on its
  //   this pointer in order to destroy the servant. For ORBs that
  //   operate in multi-threaded environments, the implementations of
  //   _add_ref and _remove_ref that the RefCountServantBase class
  //   provides shall be thread-safe.
  //
  //   Like ServantBase, RefCountServantBase supports copy
  //   construction and the default assignment operation. Copy
  //   construction always sets the reference count of the new servant
  //   instance to one. The default assignment implementation merely
  //   returns *this and does not affect the reference count.

public:

  ~TAO_RefCountServantBase (void);
  // Destructor.

  virtual void _add_ref (void);
  // Increase reference count by one.

  virtual void _remove_ref (void);
  // Decreases reference count by one; if the resulting reference
  // count equals zero, _remove_ref invokes delete on its this pointer
  // in order to destroy the servant.

protected:

  TAO_RefCountServantBase (void);
  // Constructor: initial reference count is one.

  TAO_RefCountServantBase (const TAO_RefCountServantBase &);
  // Copy Constructor: Always sets the reference count of the new
  // servant instance to one.

  TAO_RefCountServantBase &operator= (const TAO_RefCountServantBase &);
  // The default assignment implementation merely returns *this and
  // does not affect the reference count.

private:

  ACE_Atomic_Op<ACE_SYNCH_MUTEX, CORBA::ULong> ref_count_;
  // Reference counter.

};

class TAO_Export TAO_Servant_Hash
{
public:
  u_long operator () (PortableServer::Servant servant) const;
  // Returns hash value.
};

class TAO_Export TAO_Local_ServantBase : public TAO_ServantBase
{
  // = TITLE
  //   Base class for local skeletons and servants.
protected:
  TAO_Stub *_create_stub (CORBA_Environment &TAO_IN_ENV = CORBA::default_environment ());
  // This is an auxiliar method for _this().  Make sure *not* to
  // register with the default POA
};

#if !defined (TAO_HAS_MINIMUM_CORBA)

class TAO_Export TAO_DynamicImplementation : public virtual TAO_ServantBase
{
  // = TITLE
  //   Base class for DSI.
  //
  // = DESCRIPTION
  //   It is expected that the <invoke> and <_primary_interface>
  //   methods will be only invoked by the POA in the context of
  //   serving a CORBA request. Invoking this method in other
  //   circumstances may lead to unpredictable results.
public:
  virtual void invoke (CORBA::ServerRequest_ptr request,
                       CORBA_Environment &TAO_IN_ENV = CORBA::default_environment ()) = 0;
  // The invoke() method receives requests issued to any CORBA object
  // incarnated by the DSI servant and performs the processing
  // necessary to execute the request.

  virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &oid,
                                                  PortableServer::POA_ptr poa,
                                                  CORBA_Environment &TAO_IN_ENV = CORBA::default_environment ()) = 0;
  // The _primary_interface() method receives an ObjectId value and a
  // POA_ptr as input parameters and returns a valid RepositoryId
  // representing the most-derived interface for that oid.

  CORBA::Object_ptr _this (CORBA_Environment &TAO_IN_ENV = CORBA::default_environment ());
  // Returns a CORBA::Object_ptr for the target object.

protected:

  virtual const char *_interface_repository_id (void) const;
  // Return 0.  Should never be used.

  virtual void *_downcast (const char *repository_id);
  // Simply returns "this"

  virtual TAO_Stub *_create_stub (CORBA_Environment &TAO_IN_ENV = CORBA::default_environment ());
  // This is an auxiliar method for _this() and _narrow().

  virtual void _dispatch (CORBA::ServerRequest &request,
                          void *context,
                          CORBA_Environment &TAO_IN_ENV = CORBA::default_environment ());
  // Turns around and calls invoke.
};

#endif /* TAO_HAS_MINIMUM_CORBA */

#if defined (__ACE_INLINE__)
# include "tao/Servant_Base.i"
#endif /* __ACE_INLINE__ */

#endif /* TAO_SERVANT_BASE_H */

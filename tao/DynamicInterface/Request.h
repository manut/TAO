// -*- C++ -*-

//=============================================================================
/**
 *  @file    Request.h
 *
 *  $Id$
 *
 *  Header file for CORBA's Dynamic Invocation Interface "Request"
 *  type.
 *
 *  @author Copyright 1994-1995 by Sun Microsystems, Inc.
 *  @author Additions and RequestSeq by Jeff Parsons <parsons@cs.wustl.edu>
 */
//=============================================================================

#ifndef TAO_REQUEST_H
#define TAO_REQUEST_H

#include "ace/pre.h"

#include "tao/orbconf.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

// To force execution of the static constructor
// that registers the dynamic service object.
#include "Dynamic_Adapter_Impl.h"

#include "Context.h"
#include "ExceptionList.h"
#include "tao/corbafwd.h"
#include "tao/ORB.h"
#include "tao/NVList.h"
#include "tao/Environment.h"
#include "tao/Sequence.h"

namespace CORBA
{
  /**
   * @class Request
   *
   * @brief CORBA::Request
   *
   * Provides a way to create requests and populate it with parameters
   * for use in the Dynamic Invocation Interface.
   */
  class TAO_DynamicInterface_Export Request
  {
  public:

    /// Return the target of this request.
    CORBA::Object_ptr target (void) const;

    /// Return the operation name for the request.
    const CORBA::Char *operation (void) const;

    /// Return the arguments for the request.
    CORBA::NVList_ptr arguments (void);

    /// Return the result for the request.
    CORBA::NamedValue_ptr result (void);

    /// Return the exceptions resulting from this request.
    CORBA::ExceptionList_ptr exceptions (void);

    /// Accessor for the Context member.
    CORBA::Context_ptr ctx (void) const;

    /// Mutator for the Context member.
    void ctx (CORBA::Context_ptr);

    /// Return a list of the request's result's contexts.  Since TAO
    /// does not implement Contexts, this will always be 0.
    CORBA::ContextList_ptr contexts (void);

    // @deprecated  Return the <Environment> for this request.
    // CORBA::Environment_ptr env (void);


    /**
     * @name Argument manipulation helper functions.
     *
     * Arg adders, one for each type of parameter, with and without
     * optional name. Returns reference to Any for insertion using
     * <<=.
     */
    //@{
    CORBA::Any &add_in_arg (void);
    CORBA::Any &add_in_arg (const char* name);
    CORBA::Any &add_inout_arg (void);
    CORBA::Any &add_inout_arg (const char* name);
    CORBA::Any &add_out_arg (void);
    CORBA::Any &add_out_arg (const char* name);
    //@}

    /// Initialize the return type.
    void set_return_type (CORBA::TypeCode_ptr tc);

    /// Returns reference to Any for extraction using >>=.
    CORBA::Any &return_value (void);

    /// Perform method resolution and invoke an appropriate method.
    /**
     * If the method returns successfully, its result is placed in
     * the result argument specified on @c create_request. The behavior
     * is undefined if this @c Request has already been used with a
     * previous call to @c invoke>, @c send>, or
     * @send_multiple_requests.
     *
     * @note A default argument is set, but please note that this not
     *       recommended as the user may not be able to propagate the
     *       exceptions.
     */
    void invoke (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS);

    /// Send a oneway request.
    /**
     * @note A default argument is set, but please note that this not
     *       recommended as the user may not be able to propagate the
     *       exceptions.
     */
    void send_oneway (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS);

    /**
     * @name The 'deferred synchronous' methods.
     *
     * The 'deferred synchronous' methods.
     */
    //@{
    void send_deferred (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS);
    void get_response (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS);
    CORBA::Boolean poll_response (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS);
    //@}

    /// Callback method for deferred synchronous requests.
    void handle_response (TAO_InputCDR &incoming,
                          CORBA::ULong reply_status
                          ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    /// Pseudo object methods.
    static CORBA::Request* _duplicate (CORBA::Request*);
    static CORBA::Request* _nil (void);

    // = Reference counting.
    CORBA::ULong _incr_refcnt (void);
    CORBA::ULong _decr_refcnt (void);

    /// Set the lazy evaluation flag.
    void _tao_lazy_evaluation (int lazy_evaluation);

    /// Get the byte order member.
    int _tao_byte_order (void) const;

    /// Set the byte order member.
    void _tao_byte_order (int byte_order);

    // Hold on to a user exception in case we are part of a TAO
    // gateway.
    void raw_user_exception (TAO_InputCDR &cdr);

    /// Accessor for the input stream containing the exception.
    ACE_CString &raw_user_exception (void);

#if !defined(__GNUC__) || __GNUC__ > 2 || __GNUC_MINOR__ >= 8
    // Useful for template programming.
    typedef CORBA::Request_ptr _ptr_type;
    typedef CORBA::Request_var _var_type;
#endif /* __GNUC__ */

  private:
    friend class ::TAO_Dynamic_Adapter_Impl;

    // The following are not allowed except when called from the
    // friend class.

    Request (CORBA::Object_ptr obj,
             CORBA::ORB_ptr orb,
             const CORBA::Char *op,
             CORBA::NVList_ptr args,
             CORBA::NamedValue_ptr result,
             CORBA::Flags flags,
             CORBA::ExceptionList_ptr exceptions
             ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    Request (CORBA::Object_ptr obj,
             CORBA::ORB_ptr orb,
             const CORBA::Char *op
             ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    ~Request (void);

  private:

    /// Target object.
    CORBA::Object_ptr target_;

    /// Pointer to our ORB.
    CORBA::ORB_var orb_;

    /// Operation name.
    const char * opname_;

    /// Parameter list.
    CORBA::NVList_ptr args_;

    /// Result of the operation.
    CORBA::NamedValue_ptr result_;

    /// Invocation flags.
    CORBA::Flags flags_;

    /// @deprecated  Holds exceptions.
    // CORBA::Environment env_;

    /// List of exceptions raised by the operation.
    CORBA::ExceptionList_var exceptions_;

    /// List of the request's result's contexts.
    CORBA::ContextList_ptr contexts_;

    /// Context associated with this request.
    CORBA::Context_ptr ctx_;

    /// Reference counting.
    CORBA::ULong refcount_;

    /// Protect the refcount_ and response_receieved_.
    TAO_SYNCH_MUTEX lock_;

    /// If not zero then the NVList is not evaluated by default.
    int lazy_evaluation_;

    /// Set to TRUE upon completion of invoke() or handle_response().
    CORBA::Boolean response_received_;

    /// Can be reset by a gateway when passing along a request.
    int byte_order_;

    /// Stores user exception as a CDR stream when this request is
    /// used in a TAO gateway.
    ACE_CString raw_user_exception_;

  };

  /**
   * @class Request_var
   *
   * @brief The T_var class for Request.
   *
   * As any other pseudo object Request must have a T_var class, the
   * interface an semantics are specified in the CORBA spec.
   */
  class TAO_DynamicInterface_Export Request_var
  {
  public:
    Request_var (void);
    Request_var (Request_ptr);
    Request_var (const Request_var &);
    ~Request_var (void);

    Request_var &operator= (Request_ptr);
    Request_var &operator= (const Request_var &);
    Request_ptr operator-> (void) const;

    operator const Request_ptr &() const;
    operator Request_ptr &();

    // in, inout, out, _retn.
    Request_ptr in (void) const;
    Request_ptr &inout (void);
    Request_ptr &out (void);
    Request_ptr _retn (void);
    Request_ptr ptr (void) const;

  private:
    Request_ptr ptr_;
  };

  /**
   * @class Request_out
   *
   * @brief The T_out class for Request
   *
   * As any other pseudo object Request must have a T_out class, the
   * interface an semantics are specified in the CORBA spec.
   */
  class TAO_DynamicInterface_Export Request_out
  {
  public:
    Request_out (Request_ptr &);
    Request_out (Request_var &);
    Request_out (Request_out &);
    Request_out &operator= (Request_out &);
    Request_out &operator= (const Request_var &);
    Request_out &operator= (Request_ptr);
    operator Request_ptr &();
    Request_ptr &ptr (void);
    Request_ptr operator-> (void);

  private:
    Request_ptr &ptr_;
  };

  // Make sure you instantiate this in Request.cpp
  class TAO_DynamicInterface_Export ORB_RequestSeq
    : public TAO_Unbounded_Pseudo_Sequence<CORBA::Request, CORBA::Request_var>
  {
  public:
    // Helpful with template programming.
#if !defined(__GNUC__) || __GNUC__ > 2 || __GNUC_MINOR__ >= 8
    typedef ORB_RequestSeq_var _var_type;
#endif /* __GNUC__ */

    // Implement the same constructors provided by the template here,
    // check Sequence_T.h for ideas.
    // Simply delegate on the template for the implementation...

    /// Default constructor.
    ORB_RequestSeq (void);

    /// Constructor with a "hint" for the maximum capacity.
    ORB_RequestSeq (CORBA::ULong max);

    /// Constructor with a given buffer.
    ORB_RequestSeq (CORBA::ULong maximum,
                    CORBA::ULong length,
                    CORBA::Request* * data,
                    CORBA::Boolean release=0);

    /// Copy ctor, deep copies.
    ORB_RequestSeq (const ORB_RequestSeq &);

  };

  class TAO_DynamicInterface_Export ORB_RequestSeq_var
  {
  public:
    /// Default constructor.
    ORB_RequestSeq_var (void);

    ORB_RequestSeq_var (ORB_RequestSeq *);

    /// Copy constructor.
    ORB_RequestSeq_var (const ORB_RequestSeq_var &);

    /// Destructor.
    ~ORB_RequestSeq_var (void);

    ORB_RequestSeq_var &operator= (ORB_RequestSeq *);
    ORB_RequestSeq_var &operator= (const ORB_RequestSeq_var &);
    ORB_RequestSeq *operator-> (void);
    const ORB_RequestSeq *operator-> (void) const;

    operator const ORB_RequestSeq &() const;
    operator ORB_RequestSeq &();
    operator ORB_RequestSeq &() const;
    CORBA::Octet &operator[] (CORBA::ULong slot);

    // in, inout, out, _retn.
    const ORB_RequestSeq &in (void) const;
    ORB_RequestSeq &inout (void);
    ORB_RequestSeq *&out (void);
    ORB_RequestSeq *_retn (void);
    ORB_RequestSeq *ptr (void) const;

  private:
    ORB_RequestSeq *ptr_;
  };

  class TAO_DynamicInterface_Export ORB_RequestSeq_out
  {
  public:
    ORB_RequestSeq_out (ORB_RequestSeq *&);
    ORB_RequestSeq_out (ORB_RequestSeq_var &);
    ORB_RequestSeq_out (ORB_RequestSeq_out &);
    ORB_RequestSeq_out &operator= (ORB_RequestSeq_out &);
    ORB_RequestSeq_out &operator= (ORB_RequestSeq *);
    operator ORB_RequestSeq *&();
    ORB_RequestSeq *&ptr (void);
    ORB_RequestSeq *operator-> (void);
    CORBA::Octet &operator[] (CORBA::ULong slot);

  private:
    ORB_RequestSeq *&ptr_;

    /// Assignment from T_var not allowed.
    void operator= (const ORB_RequestSeq_var &);
  };

} // End CORBA namespace.

#if defined (__ACE_INLINE__)
# include "Request.inl"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"

#endif /* TAO_REQUEST_H */

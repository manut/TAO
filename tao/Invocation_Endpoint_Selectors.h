// This may look like C, but it's really -*- C++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//   TAO
//
// = FILENAME
//   Invocation_Endpoint_Selectors.h
//
// = DESCRIPTION
//   Strategies for selecting profile/endpoint from an IOR for making an
//   invocation.
//
// = AUTHOR
//   Marina Spivak <marina@cs.wustl.edu>
//
// ============================================================================

#ifndef TAO_INVOCATION_ENDPOINT_SELECTOR_H
#define TAO_INVOCATION_ENDPOINT_SELECTOR_H
#include "ace/pre.h"

#include "tao/corbafwd.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/MProfile.h"

class TAO_GIOP_Invocation;
class TAO_Endpoint;
class TAO_PrivateConnectionPolicy;
class TAO_PriorityModelPolicy;
class TAO_ClientProtocolPolicy;
class TAO_PriorityBandedConnectionPolicy;

class TAO_Export TAO_Endpoint_Selector_Factory
{
  // = TITLE
  //   Factory for initializing <Endpoint_Selection_State> and
  //   obtaining appropriate <Invocation_Endpoint_Selector>.
  //
  // = DESCRIPTION
  //   Used by Invocation classes to intialize its endpoint selection
  //   strategy and state based on the effective policies.
  //   Endpoint selection strategies are stateless objects - all the
  //   state they need is contained by Invocation in
  //   <Endpoint_Selection_State>.  Thus, rather than allocating an
  //   endpoint selection strategy object for each Invocation, the
  //   factory simply returns the appropriate one from the
  //   set preallocated in the ORB_Core.  One endpoint selection
  //   strategy object can be used by many invocations concurrently.
  //
public:
  TAO_Endpoint_Selector_Factory (void);
  // Constructor.

  ~TAO_Endpoint_Selector_Factory (void);
  // Destructor.

  void get_selector (TAO_GIOP_Invocation *invocation,
                     CORBA::Environment &ACE_TRY_ENV =
                     TAO_default_environment ());
  // Initialize Invocation's endpoint selection strategy and
  // state.

private:

  // = Helpers for <get_selector>.

#if (TAO_HAS_RT_CORBA == 1)

  void check_client_priority_policy (TAO_GIOP_Invocation *invocation,
                                     CORBA::Environment &ACE_TRY_ENV);
  // Gets the appropriate selector if TAO_HAS_CLIENT_PRIORITY_POLICY
  // is enabled. Also initializes endpoint selection state as
  // necessary.   WARNING: TAO::Client_Pririority_Policy is
  // deprecated.  See TAO RTCORBA documentation for more details.

  void init_client_protocol (TAO_GIOP_Invocation *invocation,
                             CORBA::Environment &ACE_TRY_ENV);
  // Initializes RTCORBA::ClientProtocolPolicy in the endpoint
  // selection state.

  void init_bands (TAO_GIOP_Invocation *invocation,
                   CORBA::Environment &ACE_TRY_ENV);
  // Initializes RTCORBA::PriorityBandsPolicy in the endpoint
  // selection state.

#endif /* TAO_HAS_RT_CORBA == 1 */
};

// ****************************************************************

#if (TAO_HAS_RT_CORBA == 1)

class TAO_Export TAO_Endpoint_Selection_State
{
  // = TITLE
  //   Per-Invocation state for endpoint selection activities.
  //
  // = DESCRIPTION
  //   Stores effective policy overrides for an Invocation, as well as
  //   some state about which endpoint was selected (so we know where
  //   we left off in case we need to try another endpoint during the
  //   same invocation).  This class is used by
  //   1) TAO_Endpoint_Selector_Factory to determine which endpoint
  //   selection strategy is appropriate for the Invocation
  //   2) Concrete Invocation_Endpoint_Selectors to look up/store
  //   selection state.
  //
public:

  // = Initialization and termination.

  TAO_Endpoint_Selection_State (void);
  // Constructor.

  ~TAO_Endpoint_Selection_State (void);
  // Destructor.

  // = State.

  // Effective overrides of the RTCORBA policies that affect
  // profile/endpoint selection.
  TAO_PriorityModelPolicy *priority_model_policy_;
  TAO_ClientProtocolPolicy *client_protocol_policy_;
  TAO_PrivateConnectionPolicy *private_connection_;
  TAO_PriorityBandedConnectionPolicy *bands_policy_;

  CORBA::ULong client_protocol_index_;
  // Index into the RTCORBA::ProtocolList of the
  // <client_protocol_policy_>, identifying the protocol we should
  // attempt using next.
  // TAO_Client_Priority_Policy_Selector uses this data member to keep
  // track of the profile index to try next.

  int valid_endpoint_found_;
  // Flag indicating whether at least one endpoint satisfying all the
  // policies was found during the lifetime of this object.

  CORBA::Short client_priority_;
  // If using RTCORBA::CLIENT_PROPAGATED priority model, cache our
  // client priority here.

  CORBA::Short min_priority_;
  CORBA::Short max_priority_;
  // If we need to select endpoint based on a range of priorities,
  // e.g., as in TAO_Bands_Endpoint_Selector, cache the target range
  // here.

};
#endif /* TAO_HAS_RT_CORBA == 1 */

// ****************************************************************

class TAO_Export TAO_Invocation_Endpoint_Selector
{
  // = TITLE
  //   Defines the interface for policy-based endpoint selection
  //   strategies.
  //
  // = DESCRIPTION
  //   Selects/reselects server endpoint for an Invocation.  Different
  //   concrete strategies perform selection based on different
  //   policies.
  //   All endpoint selection strategies are stateless objects - any
  //   necessary state is stored in Invocation's
  //   <endpoint_selection_state_>.
  //
public:
  TAO_Invocation_Endpoint_Selector (void);
  // Constructor.

  virtual ~TAO_Invocation_Endpoint_Selector (void);
  // Destructor.

  virtual void select_endpoint (TAO_GIOP_Invocation *invocation,
                                CORBA::Environment &ACE_TRY_ENV =
                                TAO_default_environment ()) = 0;
  // Select the endpoint and set <invocation>'s <profile_> and
  // <endpoint_> data members accordingly.

  virtual void next (TAO_GIOP_Invocation *invocation,
                     CORBA::Environment &ACE_TRY_ENV =
                     TAO_default_environment ()) = 0;
  // This method must be called when previously selected endpoint
  // didn't work out, and we want to try another one, i.e., reselect.
  // This method performs the necessary state updates, so that next
  // <select_endpoint> call picks a new endpoint.

  virtual void forward (TAO_GIOP_Invocation *invocation,
                        const TAO_MProfile &mprofile,
                        CORBA::Environment &ACE_TRY_ENV =
                        TAO_default_environment ()) = 0;
  // This method must be called if the invocation attempt on a
  // selected endpoint resulted in location forward.  This method
  // performs the necessary state updates, so that next <select_endpoint>
  // call picks a new endpoint.

  virtual void success (TAO_GIOP_Invocation *invocation) = 0;
  // Update the state to indicate that the selected endpoint/profile
  // were used successfully.

  virtual void close_connection (TAO_GIOP_Invocation *invocation) = 0;
  // Update the state to reflect that the connection being used for
  // the invocation has been closed by the server.
};

// ****************************************************************

class TAO_Export TAO_Default_Endpoint_Selector :
  public TAO_Invocation_Endpoint_Selector
{
  // = TITLE
  //   Default strategy for endpoint selection.
  //
  // = DESCRIPTION
  //   This strategy is used when there are no policies set or when
  //   the only policy set is RTCORBA::PriorityModelPolicy and its
  //   value is RTCORBA::SERVER_DECLARED.
  //   The strategy is to try the first endpoint from the first
  //   profile in the IOR.  If that doesn't work, try the next
  //   profile, and so on.
  //
public:
  TAO_Default_Endpoint_Selector (void);
  // Constructor.

  virtual ~TAO_Default_Endpoint_Selector (void);
  // Destructor.

  virtual void select_endpoint (TAO_GIOP_Invocation *invocation,
                                CORBA::Environment &ACE_TRY_ENV =
                                TAO_default_environment ());
  virtual void next (TAO_GIOP_Invocation *invocation,
                     CORBA::Environment &ACE_TRY_ENV =
                     TAO_default_environment ());
  virtual void forward (TAO_GIOP_Invocation *invocation,
                        const TAO_MProfile &mprofile,
                        CORBA::Environment &ACE_TRY_ENV =
                        TAO_default_environment ());
  virtual void success (TAO_GIOP_Invocation *invocation);
  virtual void close_connection (TAO_GIOP_Invocation *invocation);
};

// ****************************************************************

#if (TAO_HAS_RT_CORBA == 1)

class TAO_Export TAO_Priority_Endpoint_Selector :
  public TAO_Default_Endpoint_Selector
{
  // = TITLE
  //   Strategy for selecting endpoints based on the priority of the
  //   client thread making the invocation.
  //
  // = DESCRIPTION
  //   This strategy is used when RTCORBA::PriorityModelPolicy is
  //   set and its value is RTCORBA::CLIENT_PROPAGATED.
  //
public:
  TAO_Priority_Endpoint_Selector (void);
  // Constructor.

  virtual ~TAO_Priority_Endpoint_Selector (void);
  // Destructor.

  virtual void select_endpoint (TAO_GIOP_Invocation *invocation,
                                CORBA::Environment &ACE_TRY_ENV =
                                TAO_default_environment ());
private:
  int is_multihomed (TAO_Endpoint *endpoint);
  // Helper for <select_endpoint>.
};

// ****************************************************************

class TAO_Export TAO_Bands_Endpoint_Selector :
  public TAO_Default_Endpoint_Selector
{
  // = TITLE
  //   Strategy for selecting endpoints based on the priority range.
  //
  // = DESCRIPTION
  //   This strategy is used when
  //   RTCORBA::PriorityBandedConnectionPolicy is set.
  //
public:
  TAO_Bands_Endpoint_Selector (void);
  // Constructor.

  virtual ~TAO_Bands_Endpoint_Selector (void);
  // Destructor.

  virtual void select_endpoint (TAO_GIOP_Invocation *invocation,
                                CORBA::Environment &ACE_TRY_ENV =
                                TAO_default_environment ());
};

// ****************************************************************

class TAO_Export TAO_Protocol_Endpoint_Selector :
  public TAO_Invocation_Endpoint_Selector
{
  // = TITLE
  //   Strategy for selecting endpoints based on protocols.
  //
  // = DESCRIPTION
  //   This strategy is used when only RTCORBA::ClientProtocolPolicy is
  //   set or RTCORBA::ClientProtocolPolicy plus
  //   RTCORBA::SERVER_DECLARED priority model.
  //
public:
  TAO_Protocol_Endpoint_Selector (void);
  // Constructor.

  virtual ~TAO_Protocol_Endpoint_Selector (void);
  // Destructor.

  virtual void select_endpoint (TAO_GIOP_Invocation *invocation,
                                CORBA::Environment &ACE_TRY_ENV =
                                TAO_default_environment ());
  virtual void next (TAO_GIOP_Invocation *invocation,
                     CORBA::Environment &ACE_TRY_ENV =
                     TAO_default_environment ());
  virtual void forward (TAO_GIOP_Invocation *invocation,
                        const TAO_MProfile &mprofile,
                        CORBA::Environment &ACE_TRY_ENV =
                        TAO_default_environment ());
  virtual void success (TAO_GIOP_Invocation *invocation);
  virtual void close_connection (TAO_GIOP_Invocation *invocation);

protected:
  virtual void endpoint (TAO_GIOP_Invocation *invocation,
                         CORBA::Environment &ACE_TRY_ENV =
                         TAO_default_environment ());
  // Helper for <select_endpoint>.
};

// ****************************************************************

class TAO_Export TAO_Client_Priority_Policy_Selector :
  public TAO_Invocation_Endpoint_Selector
{
  // = TITLE
  //   Strategy for selecting endpoints when
  //   TAO::Client_Priority_Policy is set.
  //
  // = DESCRIPTION
  //   TAO::Client_Priority_Policy is deprecated.  Similar (and
  //   beyond) functionality can be achieved through standard RTCORBA
  //   policies.  See TAO Real-Time CORBA documentation for more
  //   information.
  //
public:
  TAO_Client_Priority_Policy_Selector (void);
  // Constructor.

  virtual ~TAO_Client_Priority_Policy_Selector (void);
  // Destructor.

  virtual void select_endpoint (TAO_GIOP_Invocation *invocation,
                                CORBA::Environment &ACE_TRY_ENV =
                                TAO_default_environment ());
  virtual void next (TAO_GIOP_Invocation *invocation,
                     CORBA::Environment &ACE_TRY_ENV =
                     TAO_default_environment ());
  virtual void forward (TAO_GIOP_Invocation *invocation,
                        const TAO_MProfile &mprofile,
                        CORBA::Environment &ACE_TRY_ENV =
                        TAO_default_environment ());
  virtual void success (TAO_GIOP_Invocation *invocation);
  virtual void close_connection (TAO_GIOP_Invocation *invocation);
};

// ****************************************************************

class TAO_Export TAO_Priority_Protocol_Selector :
  public TAO_Protocol_Endpoint_Selector
{
  // = TITLE
  //   Strategy for selecting endpoints based on protocols and the
  //   priority of the client thread making the invocation.
  //
  // = DESCRIPTION
  //   This strategy is used when RTCORBA::ClientProtocolPolicy is
  //   set and the priority model is RTCORBA::CLIENT_PROPAGATED.
  //
public:
  TAO_Priority_Protocol_Selector (void);
  // Constructor.

  virtual ~TAO_Priority_Protocol_Selector (void);
  // Destructor.

protected:
  virtual void endpoint (TAO_GIOP_Invocation *invocation,
                         CORBA::Environment &ACE_TRY_ENV =
                         TAO_default_environment ());
  //

  int is_multihomed (TAO_Endpoint *endpoint);
  // Helper for <select_endpoint>.
};

// ****************************************************************

class TAO_Export TAO_Bands_Protocol_Selector :
  public TAO_Protocol_Endpoint_Selector
{
  // = TITLE
  //   Strategy for selecting endpoints based on protocols and a
  //   priority range.
  //
  // = DESCRIPTION
  //   This strategy is used when both RTCORBA::ClientProtocolPolicy
  //   and RTCORBA::PriorityBandedConnectionPolicy are set.
  //
public:
  TAO_Bands_Protocol_Selector (void);
  // Constructor.

  virtual ~TAO_Bands_Protocol_Selector (void);
  // Destructor.

protected:
  virtual void endpoint (TAO_GIOP_Invocation *invocation,
                         CORBA::Environment &ACE_TRY_ENV =
                         TAO_default_environment ());
};

#endif /* TAO_HAS_RT_CORBA == 1 */

#if defined (__ACE_INLINE__)
# include "tao/Invocation_Endpoint_Selectors.i"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"
#endif  /* TAO_INVOCATION_ENDPOINT_SELECTOR_H */

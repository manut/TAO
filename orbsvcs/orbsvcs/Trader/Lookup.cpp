/* -*- C++ -*- */

// ========================================================================
// $Id$
//
// = LIBRARY
//    orbsvcs
// 
// = FILENAME
//    Lookup.cpp
//
// = AUTHOR
//    Marina Spivak <marina@cs.wustl.edu>
//    Seth Widoff <sbw1@cs.wustl.edu>
// 
// ========================================================================

#if !defined (TAO_LOOKUP_C)
#define TAO_LOOKUP_C

#include "Lookup.h"
#include "ace/Auto_Ptr.h"
#include <iostream.h>

#include "Query_Only_Offer_Iterator.h"
#include "Register_Offer_Iterator.h"
#include "Offer_Iterator_Collection.h"

template <class TRADER>
TAO_Lookup<TRADER>::TAO_Lookup (TRADER &trader)
  : trader_ (trader),
    TAO_Trader_Components<POA_CosTrading::Lookup> (trader.trading_components ()),
    TAO_Support_Attributes<POA_CosTrading::Lookup> (trader.support_attributes ()),
    TAO_Import_Attributes<POA_CosTrading::Lookup> (trader.import_attributes ())
{
}

template <class TRADER>
TAO_Lookup<TRADER>::~TAO_Lookup (void)
{
}

template <class TRADER> void
TAO_Lookup<TRADER>::
query (const char *type,
       const char *constraint,
       const char *preferences,
       const CosTrading::PolicySeq &in_policies,
       const CosTrading::Lookup::SpecifiedProps &desired_props,
       CORBA::ULong how_many,
       CosTrading::OfferSeq_out returned_offers,
       CosTrading::OfferIterator_out returned_offer_iterator,
       CosTrading::PolicyNameSeq_out returned_limits_applied,
       CORBA::Environment& env)
  TAO_THROW_SPEC ((CORBA::SystemException,
		   CosTrading::IllegalServiceType,
		   CosTrading::UnknownServiceType,
		   CosTrading::IllegalConstraint,
		   CosTrading::Lookup::IllegalPreference,
		   CosTrading::Lookup::IllegalPolicyName,
		   CosTrading::Lookup::PolicyTypeMismatch,
		   CosTrading::Lookup::InvalidPolicyValue,
		   CosTrading::IllegalPropertyName,
		   CosTrading::DuplicatePropertyName,
		   CosTrading::DuplicatePolicyName))
{
  // Initializing out parameters
  returned_offers = new CosTrading::OfferSeq;
  returned_offer_iterator = CosTrading::OfferIterator::_nil ();
  returned_limits_applied = new CosTrading::PolicyNameSeq;
  
  // Get service type map
  Service_Type_Map& service_type_map = this->trader_.service_type_map ();

  TAO_Policies policies (this->trader_, in_policies, env);
  TAO_CHECK_ENV_RETURN_VOID (env);
  
  // If the importer has specified a starting trader, foward the
  // query.
  CosTrading::TraderName* trader_name = policies.starting_trader (env);
  TAO_CHECK_ENV_RETURN_VOID (env);

  if (trader_name != 0)
    {
      CosTrading::TraderName_var starting_trader (trader_name);
      this->forward_query (starting_trader.in (),
			   type,
			   constraint,
			   preferences,
			   policies,
			   desired_props,
			   how_many,
			   returned_offers,
			   returned_offer_iterator,
			   returned_limits_applied,
			   env);
      return;
    }
  
  // If a federated query returns to us, ignore it to prevent
  // redundant results.
  if (this->duplicate_stem_id (policies, env))
    return;

  // If the type is invalid or unknown, let us know now.
  const TAO_Support_Attributes_Impl& support_attrs =
    this->trader_.support_attributes ();  
  CosTrading::TypeRepository_ptr type_repos =
    support_attrs.type_repos ();
  CosTradingRepos::ServiceTypeRepository_ptr rep = 
    CosTradingRepos::ServiceTypeRepository::_narrow (type_repos, env);
  TAO_CHECK_ENV_RETURN_VOID (env);
  
  // If type is not found, there is nothing to consider - return.
  // Else we found the service type....proceed with lookup.
  // We will store the matched offers in here.
  Offer_Queue ordered_offers;
  
  // Perform the lookup, placing the ordered results in ordered_offers.
  this->perform_lookup (type,
			constraint,
			preferences,
			service_type_map,
			rep,
			policies,
			ordered_offers,
			returned_limits_applied,
			env);      
  TAO_CHECK_ENV_RETURN_VOID (env);
  
  // Fill the return sequence and iterator with the bountiful results.
  CORBA::ULong offers_returned = 
    this->fill_receptacles (type,
			    ordered_offers,
			    how_many,			  
			    desired_props,
			    returned_offers,
			    returned_offer_iterator,
			    env);
  TAO_CHECK_ENV_RETURN_VOID (env);
  
  // Determine if we should perform a federated query, and if so
  // construct a sequence of links to follow.
  CosTrading::LinkNameSeq* links = 0;
  CORBA::Boolean should_follow =
    this->retrieve_links (policies,
			  offers_returned,
			  CosTrading::LinkNameSeq_out (links),
			  env);
  TAO_CHECK_ENV_RETURN_VOID (env);
  
  if (should_follow && links != 0)
    {
      // Perform the sequence of fedrated queries.
      CosTrading::LinkNameSeq_var links_to_follow (links);  
      this->federated_query (*links,
			     type,
			     constraint,
			     preferences,
			     policies,
			     desired_props,
			     how_many - returned_offers->length (),
			     returned_offers,
			     returned_offer_iterator,
			     returned_limits_applied,
			     env);
    }
  TAO_CHECK_ENV_RETURN_VOID (env);
}

template <class TRADER> void
TAO_Lookup<TRADER>::
perform_lookup (const char* type,
		const char* constraint,
		const char* preferences,
		Service_Type_Map& service_type_map,
		CosTradingRepos::ServiceTypeRepository_ptr rep,		
		TAO_Policies& policies,
		Offer_Queue& ordered_offers,
    CosTrading::PolicyNameSeq_out returned_limits_applied,
		CORBA::Environment& env)
  TAO_THROW_SPEC ((CosTrading::IllegalConstraint,
		   CosTrading::Lookup::IllegalPreference,
		   CosTrading::Lookup::PolicyTypeMismatch,
		   CosTrading::Lookup::InvalidPolicyValue,
		   CosTrading::IllegalServiceType,
		   CosTrading::UnknownServiceType))
{    
  // TAO_Offer_Filter -- ensures that we don't consider offers with
  // modifiable or dynamic properties if the Trader doesn't support
  // them, or the importer has turned them off using policies.
  // TAO_Constraint_Validator -- validates the constraint with the
  // property types in the supplied type.
  // TAO_Constraint_Interpreter -- parses the constraint string, and
  // determines whether an offer meets those constraints.
  // TAO_Preference_Interpreter -- parses the preference string and
  // orders offers according to those constraints.
  CosTradingRepos::ServiceTypeRepository::TypeStruct_var
    type_struct (rep->fully_describe_type (type, env));
  TAO_CHECK_ENV_RETURN_VOID (env);
  TAO_Offer_Filter offer_filter (type_struct.ptr (), policies, env);
  TAO_CHECK_ENV_RETURN_VOID (env);
  TAO_Constraint_Validator validator (type_struct.ptr ());
  TAO_Constraint_Interpreter constr_inter (validator, constraint, env);
  TAO_CHECK_ENV_RETURN_VOID (env);
  TAO_Preference_Interpreter pref_inter (validator, preferences, env);
  TAO_CHECK_ENV_RETURN_VOID (env);
  CORBA::ULong return_card = policies.return_card (env);
  TAO_CHECK_ENV_RETURN_VOID (env);
  
  // Try to find the map of offers of desired service type.
  this->lookup_one_type (type,
			 service_type_map,
			 constr_inter,
			 pref_inter,
			 offer_filter);

  // If the importer hasn't demanded an exact match search, we search
  // all the subtypes of the supplied type. NOTE: Only the properties
  // belonging to the provided type are considered on
  // subtypes. Additional properties on the subtype are generally
  // ignored. This is as it should be, consistent with the notions of
  // type inheritence.
  if (! policies.exact_type_match (env))
    {
      TAO_CHECK_ENV_RETURN_VOID (env);
      this->lookup_all_subtypes (type,
				 type_struct->incarnation,
				 service_type_map,
				 rep,
				 constr_inter,
				 pref_inter,
				 offer_filter);
    }
  TAO_CHECK_ENV_RETURN_VOID (env);

  // Pull the matched offers out of the pref_inter in order, and stick 
  // them in a queue. The offers in the queue will be emptied into
  // the return sequence and iterator for later purusal by the
  // importer. Only prepare for the importer no more offers than the
  // return cardinality default or policy allows.
  CORBA::ULong num_offers = pref_inter.num_offers ();
  for (CORBA::ULong i = 0; i < num_offers && i < return_card; i++)
    {
      CosTrading::Offer* offer;
      CosTrading::OfferId offer_id;
      if (pref_inter.remove_offer (offer_id, offer) == 0)
	{
	  Offer_Info offer_info;
	  offer_info.offer_id_ = offer_id;
	  offer_info.offer_ptr_ = offer;
	  ordered_offers.enqueue_tail (offer_info);
	}
      else
	break;
    }

  // Take note of the limits applied in this query.
  returned_limits_applied = offer_filter.limits_applied ();
}

template <class TRADER> void
TAO_Lookup<TRADER>::
lookup_one_type (const char* type,
		 Service_Type_Map& service_type_map,
		 TAO_Constraint_Interpreter& constr_inter,
		 TAO_Preference_Interpreter& pref_inter,
		 TAO_Offer_Filter& offer_filter)
{
  ACE_DEBUG ((LM_DEBUG, "TAO_Lookup: Performing query for %s\n", type));
  
  // Retrieve an iterator over the offers for a given type.
  Service_Type_Map::offer_iterator offer_iter (type, service_type_map);

  while (offer_filter.ok_to_consider_more () &&
	 offer_iter.has_more_offers ())
    {
      // For each offer in the iterator, attempt to match it with
      // the constraints passed to the Query method. If it matches 
      // the constraint, use the TAO_Preference_Interpreter to
      // order the matched offers with respect to the preference
      // string passed to the method. All the while the offer
      // iterator ensures we don't exceed the match cardinality
      // constraints. 
      CosTrading::Offer* offer = offer_iter.get_offer ();
      
      TAO_Constraint_Evaluator evaluator (offer);
      if (offer_filter.ok_to_consider (offer) &&
	  constr_inter.evaluate (evaluator))
	{
	  // Shove the offer and its id into the preference
	  // ordering object, pref_inter.
	  CosTrading::OfferId offer_id = offer_iter.get_id ();
	  pref_inter.order_offer (offer_id, offer, evaluator);
	  offer_filter.matched_offer ();
	}
      
      offer_iter.next_offer ();
    }
}

template <class TRADER> void
TAO_Lookup<TRADER>::
lookup_all_subtypes (const char* type,
		     CosTradingRepos::ServiceTypeRepository::IncarnationNumber& inc_num,
		     Service_Type_Map& service_type_map,
		     CosTradingRepos::ServiceTypeRepository_ptr rep,
		     TAO_Constraint_Interpreter& constr_inter,
		     TAO_Preference_Interpreter& pref_inter,
		     TAO_Offer_Filter& offer_filter)
{
  // BEGIN SPEC
  // The trader may return a service offer of a subtype of the "type"
  // requested. Sub-typing of service types is discussed in "Service
  // Types" on page 16-4. A service subtype can be described by the
  // properties of its supertypes. This ensures that a well-formed query
  // for the "type" is also a well-formed query with respect to any
  // subtypes. However, if the importer specifies the policy of
  // exact_type_match = TRUE, then only offers with the exact (no
  // subtype) service type requested are returned.  
  // END SPEC

  CosTradingRepos::ServiceTypeRepository::SpecifiedServiceTypes sst;
  CosTradingRepos::ServiceTypeRepository::ServiceTypeNameSeq_var all_types;
  
  // Optimization: Since a subtype can't have a higher incarnation
  // number than a supertype, we don't need to consider those
  // types with lower incarnation numbers.  
  sst._d (CosTradingRepos::ServiceTypeRepository::since);
  sst.incarnation (inc_num);  
  
  //  TAO_TRY
  //    {
  CORBA::Environment env;
  all_types = rep->list_types (sst, env);
  //      TAO_CHECK_ENV;
  //    }
  //  TAO_CATCHANY { return; }
  //  TAO_ENDTRY;  

  // Scan all types inserted after the super types. If the transitive
  // closure of a type's super type relation includes the super type
  // being considered, then perform a search on that type.
  CORBA::ULong num_types = all_types->length ();
  for (CORBA::ULong i = 0;
       i < num_types && offer_filter.ok_to_consider_more ();
       i++)
    {
      CosTradingRepos::ServiceTypeRepository::TypeStruct_var type_struct;
      
      TAO_TRY
	{
	  // Obtain a description of the prospective type.
	  type_struct = rep->fully_describe_type (all_types[i], TAO_TRY_ENV);
	  TAO_CHECK_ENV;
	}
      TAO_CATCHANY
	{
	  break;
	}
      TAO_ENDTRY;

      CosTradingRepos::ServiceTypeRepository::ServiceTypeNameSeq&
	super_types = type_struct->super_types;
      CORBA::ULong num_super_types = super_types.length ();

      for (CORBA::ULong j = 0; j < num_super_types; j++)
	{
	  if (ACE_OS::strcmp (type_struct->super_types[j], type) == 0)
	    {
	      // Egads, a subtype!
	      this->lookup_one_type (all_types[i],
				     service_type_map,
				     constr_inter,
				     pref_inter,
				     offer_filter);
	      break;
	    }
	}
    }  
}


template <class TRADER> int
TAO_Lookup<TRADER>::
fill_receptacles (const char* type,
		  Offer_Queue& ordered_offers,
		  CORBA::ULong how_many,		  
		  const CosTrading::Lookup::SpecifiedProps& desired_props,
		  CosTrading::OfferSeq*& offers,
		  CosTrading::OfferIterator_ptr& offer_itr,
		  CORBA::Environment& env)
  TAO_THROW_SPEC ((CosTrading::IllegalPropertyName,
		  CosTrading::DuplicatePropertyName))
{
  // BEGIN SPEC
  // The returned offers are passed back in one of two ways (or a
  // combination of both). � The "offers" return result conveys a list
  // of offers and the "offer_itr" is a reference to an interface at
  // which offers can be obtained. � The "how_many" parameter states
  // how many offers are to be returned via the "offers" result, any
  // remaining offers are available via the iterator interface. If the
  // "how_many" exceeds the number of offers to be returned, then the
  // "offer_itr" will be nil.
  // END SPEC
  
  // Ordered offers iterator.
  Offer_Queue::ITERATOR ordered_offers_iterator (ordered_offers);
  TAO_Property_Filter prop_filter (desired_props, env);
  TAO_CHECK_ENV_RETURN (env, 0);
  
  // RETURNING: Calculate how many offers go into the sequence
  //  Calculate how many go into the iterator
  CORBA::ULong size = ordered_offers.size ();
  CORBA::ULong offers_in_sequence = (how_many < size) ? how_many : size;
  CORBA::ULong offers_in_iterator = size - offers_in_sequence;
  CORBA::ULong total_offers = offers_in_sequence + offers_in_iterator;
  
  offers->length (offers_in_sequence);
  
  // Add to the sequence, filtering out the undesired properties.
  for (CORBA::ULong i = 0;
       i < offers_in_sequence;
       ordered_offers_iterator.advance (), i++)
    {
      Offer_Info* offer_info_ptr = 0;
      ordered_offers_iterator.next (offer_info_ptr);
      CosTrading::Offer& source = *offer_info_ptr->offer_ptr_;
      CosTrading::Offer& destination = (*offers)[i];
      prop_filter.filter_offer (source, destination);

      CORBA::string_free (offer_info_ptr->offer_id_);
    }
    
  // Any remaining offers go into iterator
  if (offers_in_iterator > 0)
    {
      // Create an iterator implementation 
      TAO_Offer_Iterator *oi =
	this->create_offer_iterator (type, prop_filter);
      offer_itr = oi->_this (env);
      TAO_CHECK_ENV_RETURN (env,total_offers - offers_in_iterator);
      
      // Add to the iterator
      for (i = 0;
	   i < offers_in_iterator;
	   ordered_offers_iterator.advance (), i++)
	{
	  Offer_Info* offer_info_ptr = 0;
	  ordered_offers_iterator.next (offer_info_ptr);      
	  oi->add_offer (offer_info_ptr->offer_id_,
			 offer_info_ptr->offer_ptr_);
	}
    }

  return total_offers;
}

template <class TRADER>
TAO_Offer_Iterator *
TAO_Lookup<TRADER>::
create_offer_iterator (const char *type,
		       const TAO_Property_Filter& pfilter)
{
  // This is the factory method that creates the appropriate type of
  // offer iterator. If there's no Register interface, then we can
  // just stick the offers directly into an iterator, since these
  // offers will never be removed from the Trader. If there's a
  // Register interface, then there's a chance that by the time the
  // importer calls the next_n method on the iterator that the offer
  // will have been withdrawn. So the Register_Offer_Iterator retains only
  // the offer ids, and will recognize when an offer id no longer
  // identifies an offer in the trader.

  // We pass the property filter to the iterators, so when the iterators
  // return the offers, they can remove the undesirable properties
  // from those offers.  
  TAO_Offer_Iterator* iterator = 0;
  
  if (CORBA::is_nil (this->trader_.trading_components ().register_if ()))
    iterator =  new TAO_Query_Only_Offer_Iterator (pfilter);
  else
    {
      iterator =
	new TAO_Register_Offer_Iterator<TRADER> (this->trader_, pfilter);
    }

  return iterator;
}

template <class TRADER> CORBA::Boolean
TAO_Lookup<TRADER>::duplicate_stem_id (TAO_Policies& policies,
				       CORBA::Environment& _env)
{
  // Determine whether the stem_id passed to this query is one we've 
  // already seen. If this is the case, then we shouldn't pursue this
  // query any further.
  CORBA::Boolean return_value = CORBA::B_FALSE;
  CosTrading::Admin::OctetSeq_var request_id = policies.request_id (_env);
  TAO_CHECK_ENV_RETURN (_env, return_value);

  // If the stem_id was provided and is a duplicate, return true.
  if ((request_id.ptr () != 0) &&
      this->request_ids_.insert (request_id) == 1)
    return_value = CORBA::B_TRUE;

  return return_value;
}

template <class TRADER> CORBA::Boolean
TAO_Lookup<TRADER>::retrieve_links (TAO_Policies& policies,
				    CORBA::ULong offers_returned,
				    CosTrading::LinkNameSeq_out links,
				    CORBA::Environment& _env)
  TAO_THROW_SPEC ((CORBA::SystemException, 
		   CosTrading::Lookup::PolicyTypeMismatch))
{
  CORBA::Boolean should_follow = CORBA::B_FALSE;
  CosTrading::FollowOption follow_rule = policies.link_follow_rule (_env);
  TAO_CHECK_ENV_RETURN (_env, should_follow);
  
  // Determine whether or not a federated query is warranted. A query
  // is waranted if the follow_rule governing this query is 'always'
  // or if_no_local and the local query returned nothing.
  if ((follow_rule == CosTrading::always ||
       (follow_rule == CosTrading::if_no_local && offers_returned == 0))
      && policies.hop_count (_env) > 0)
    should_follow = CORBA::B_TRUE;

  if (should_follow)
    {
      // Grab the names of all the links in the trader, and push
      // the suitable ones onto <valid_links>.
      CosTrading::Link_ptr link_interface
	= this->trader_.trading_components ().link_if ();
      ACE_Unbounded_Queue<CosTrading::LinkName> valid_links;
      CosTrading::LinkNameSeq_var link_path =
	link_interface->list_links (_env);
      TAO_CHECK_ENV_RETURN (_env, should_follow);
      
      // Determine which of the links registered with the Link
      // interface are suitable to follow. 
      for (int i = link_path->length () - 1; i >= 0; i--)
	{
	  CosTrading::FollowOption link_rule =
	    policies.link_follow_rule ((const char*) link_path[i], _env);
	  if (link_rule == CosTrading::always ||
	      (link_rule == CosTrading::if_no_local &&
	       offers_returned == 0))
	    valid_links.enqueue_tail ((char *)((const char*) link_path[i]));
	}

      // Collect those valid links into a sequence suitable for
      // passing into the federated_query method.
      CosTrading::LinkName link_name = 0,
	*link_buf = CosTrading::LinkNameSeq::allocbuf (valid_links.size ());

      if (link_buf != 0)
	{
	  for (i = valid_links.size () - 1; i >= 0; i--)
	    {	  
	      valid_links.dequeue_head (link_name);
	      link_buf[i] = CORBA::string_dup (link_name);
	    }
	  
	  ACE_NEW_RETURN (links,
			  CosTrading::LinkNameSeq (valid_links.size (),
						   valid_links.size (),
						   link_buf,
						   CORBA::B_TRUE),
			  0);
	}
    }      

  return should_follow;
}


template <class TRADER> void
TAO_Lookup<TRADER>::
federated_query (const CosTrading::LinkNameSeq& links,
		 const char *type,
		 const char *constr,
		 const char *pref,
		 TAO_Policies& policies,
		 const CosTrading::Lookup::SpecifiedProps& desired_props,
		 CORBA::ULong how_many,
		 CosTrading::OfferSeq_out offers,
		 CosTrading::OfferIterator_out offer_iter,
		 CosTrading::PolicyNameSeq_out limits,
		 CORBA::Environment& _env) 
  TAO_THROW_SPEC ((CORBA::SystemException,
		   CosTrading::IllegalServiceType,
		   CosTrading::UnknownServiceType,
		   CosTrading::IllegalConstraint,
		   CosTrading::Lookup::IllegalPreference,
		   CosTrading::Lookup::IllegalPolicyName,
		   CosTrading::Lookup::PolicyTypeMismatch,
		   CosTrading::Lookup::InvalidPolicyValue,
		   CosTrading::IllegalPropertyName,
		   CosTrading::DuplicatePropertyName,
		   CosTrading::DuplicatePolicyName))
{
  // The general idea here is this: We've assembled a number of links
  // to follow, and we'll query each of them in turn. When we've
  // assembled <return_card> number of offers, we've hit the ceiling
  // and we back out. On each query we adjust the policies for the new 
  // trader by reducing the return_card, hop_count, etc..., and merge
  // the results from the new query with the results from the previous 
  // queries.
  
  // We'll need the link and admin interfaces for this part of the
  // federated query.
  CORBA::ULong total_returned = 0,
    return_card = policies.return_card (_env);
  CosTrading::Link_ptr link_interface
    = this->trader_.trading_components ().link_if ();
  CosTrading::Admin_ptr admin_interface
    = this->trader_.trading_components ().admin_if ();

  // Begin collecting all the various offer_iterators into a
  // collection. The end result is a distributed tree of offer
  // iterators, which if traversed in its entirety is probably hugely
  // inefficient, but oh well, I can't think of a better solution.
  TAO_Offer_Iterator_Collection* offer_iter_collection;
  ACE_NEW (offer_iter_collection, TAO_Offer_Iterator_Collection);

  offer_iter_collection->add_offer_iterator (offer_iter);
  total_returned = offers->length () +
    offer_iter_collection->max_left (_env);

  for (int i = links.length () - 1; i >= 0; i--)
    {
      CosTrading::OfferSeq* out_offers = 0;
      CosTrading::OfferIterator* out_offer_iter = 0;
      CosTrading::PolicyNameSeq* out_limits = 0; 
      CosTrading::OfferSeq_var out_offers_var (out_offers);
      CosTrading::OfferIterator_var out_offer_iter_var (out_offer_iter);
      CosTrading::PolicyNameSeq_var out_limits_var (out_limits);
	    
      TAO_TRY
	{
	  // Obtain information about the link we're traversing.
	  CosTrading::Link::LinkInfo_var link_info =
	    link_interface->describe_link (links[i], TAO_TRY_ENV);
	  TAO_CHECK_ENV;

	  // Prepare a set of policies to pass to the next trader.
	  CosTrading::PolicySeq_var new_pols =
	    policies.policies_to_pass (link_info->def_pass_on_follow_rule,
				       total_returned,
				       admin_interface);
	  
	  // Perform the federated query.
	  link_info->target->
	    query (type,
		   constr,
		   pref,
		   new_pols.in (),
		   desired_props,
		   how_many - offers->length (),
		   CosTrading::OfferSeq_out (out_offers),
		   CosTrading::OfferIterator_out (out_offer_iter),
		   CosTrading::PolicyNameSeq_out (out_limits),
		   _env);
	  TAO_CHECK_ENV;
	  
	  // Merge the results.
	  CORBA::ULong offset = offers->length ();
	  offers->length (out_offers->length () + offset);
	  offer_iter_collection->add_offer_iterator (out_offer_iter);
	  for (int j = out_offers->length () - 1; j >= 0; j--)
	    offers[j + offset] = out_offers_var[j];

	  // Concatenate the limits applied.
	  offset = limits->length ();
	  offers->length (out_limits->length () + offset);
	  for (j = out_limits->length () - 1; j >= 0; j--)
	    limits[j + offset] = out_limits_var[j];

	  // If we've obtained all the offers we need, let's blow this 
	  // joint. 
	  if (total_returned >= return_card)
	    break;
	}
      TAO_CATCHANY
	{
	  break;
	}
      TAO_ENDTRY;
    }

  // Return the collection of offer iterators.
  offer_iter = offer_iter_collection->_this (_env);
}

template <class TRADER> void
TAO_Lookup<TRADER>
::forward_query (const CosTrading::TraderName& starting_trader,
		 const char *type,
		 const char *constr,
		 const char *pref,
		 TAO_Policies& policies,
		 const CosTrading::Lookup::SpecifiedProps& desired_props,
		 CORBA::ULong how_many,
		 CosTrading::OfferSeq_out offers,
		 CosTrading::OfferIterator_out offer_itr,
		 CosTrading::PolicyNameSeq_out limits_applied,
		 CORBA::Environment& _env)
  TAO_THROW_SPEC ((CORBA::SystemException,
		   CosTrading::IllegalServiceType,
		   CosTrading::UnknownServiceType,
		   CosTrading::IllegalConstraint,
		   CosTrading::Lookup::IllegalPreference,
		   CosTrading::Lookup::IllegalPolicyName,
		   CosTrading::Lookup::PolicyTypeMismatch,
		   CosTrading::Lookup::InvalidPolicyValue,
		   CosTrading::IllegalPropertyName,
		   CosTrading::DuplicatePropertyName,
		   CosTrading::DuplicatePolicyName))
{
  // Forward this query to the next link in the starting_trader sequence.
  CosTrading::Link_ptr link_interface
    = this->trader_.trading_components ().link_if ();

  TAO_TRY
    {  
      CosTrading::Link::LinkInfo_var link_info =
	link_interface->describe_link (starting_trader[0], TAO_TRY_ENV);
      TAO_CHECK_ENV;
      
      CosTrading::PolicySeq_var in_policies = policies.policies_to_forward ();

      // Perform forwarding query.
      link_info->target->query (type,
				constr,
				pref,
				in_policies.in (),
				desired_props,
				how_many,
				offers,
				offer_itr,
				limits_applied,
				_env);
      TAO_CHECK_ENV_RETURN_VOID (_env);
    }
  TAO_CATCHANY
    {
      TAO_THROW (CosTrading::Lookup::InvalidPolicyValue ());
    }
  TAO_ENDTRY;
}

#endif /* TAO_LOOKUP_C */

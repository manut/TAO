// $Id$

// ========================================================================
//
// = FILE  
//     Offer_Importer.h
//
// = DESCRIPTION
//    Class that tests the Trading Service's Lookup Interface
//
// = AUTHOR
//     Seth Widoff <sbw1@cs.wustl.edu>
//
// ======================================================================= 

#ifndef TAO_OFFER_IMPORTER
#define TAO_OFFER_IMPORTER

#include "TT_Info.h"
#include "ace/Task_T.h"
#include "orbsvcs/Trader/Trader_Utils.h"

class TAO_Offer_Importer
{
public:

  TAO_Offer_Importer (CosTrading::Lookup_ptr lookup_if);

  void perform_queries (CORBA::Environment& _env)
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
		     CosTrading::DuplicatePolicyName));

  void perform_directed_queries (CORBA::Environment& _env)
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
		     CosTrading::DuplicatePolicyName));
private:

  void perform_queries_with_policies (const TAO_Policy_Manager& policy_manager,
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
		     CosTrading::DuplicatePolicyName));
    
  
  void display_results (const CosTrading::OfferSeq& offer_seq,
			CosTrading::OfferIterator_ptr offer_iterator,
			CORBA::Environment& _env) const
    TAO_THROW_SPEC ((CORBA::SystemException));

  CosTrading::Lookup_var lookup_;
  
};

#endif /* TAO_OFFER_IMPORTER */

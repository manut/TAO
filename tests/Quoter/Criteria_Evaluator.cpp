// $Id$

// ============================================================================
//
// = FILENAME
//    Criteria_Evaluator.cpp
//
// = DESCRIPTION
//    An Evaluator for the CosLifeCycle Criteria
//
// = AUTHOR
//    Michael Kircher (mk1@cs.wustl.edu)
//
// ============================================================================

#include "Criteria_Evaluator.h"

Quoter_Criteria_Evaluator::Quoter_Criteria_Evaluator (const CosLifeCycle::Criteria &criteria)
: criteria_ (criteria)
{
}
 
Quoter_Criteria_Evaluator::~Quoter_Criteria_Evaluator ()
{
}



Stock::Criteria_Evaluator::SeqNamedValuePair *
Quoter_Criteria_Evaluator::getInitialization (CORBA::Environment &env)
{
  
  Stock::Criteria_Evaluator::SeqNamedValuePair *sequence_ptr;

  const CORBA::Any_ptr any_ptr = this->getCriteriaMember ("initialization");

  if (any_ptr == 0)
  {
    env.exception (new Stock::Criteria_Evaluator::NotAvailable ("No initialization member found.\n"));      
    return 0;
  }
  //*any_ptr >>= sequence_ptr;

  return sequence_ptr;
}
  
  
char *
Quoter_Criteria_Evaluator::getFilter (CORBA::Environment &env)
{
  CORBA::String string;
  CORBA::Any value;
  CORBA::Any_ptr any_ptr = this->getCriteriaMember ("filter");

  if (any_ptr == 0)
  {
    env.exception (new Stock::Criteria_Evaluator::NotAvailable ("No filter member found.\n"));      
    return 0;
  }
  *any_ptr >>= string;
  return string;
}


CORBA::Any *
Quoter_Criteria_Evaluator::getCriteriaMember (const CORBA::String member_name)
{
  if (!ACE_OS::strcmp(member_name, "initialization") 
    && !ACE_OS::strcmp(member_name, "filter")
    && !ACE_OS::strcmp(member_name, "logical location")
    && !ACE_OS::strcmp(member_name, "preferences"))
    return 0;

  for (unsigned int i = 0; i < criteria_.length(); i++)
  {
    if (ACE_OS::strcmp (member_name, criteria_[i].name) == 0)
    {
      CORBA::Any_ptr value_ptr;
      ACE_NEW_RETURN (value_ptr, 
                      CORBA::Any(criteria_[i].value), 
                      0);
      return value_ptr;
    }
  }
  return 0;  
}


/*
void 
Quoter_Criteria_Evaluator::setCriteria (const CosLifeCycle::Criteria & criteria,
					CORBA::Environment &_tao_environment)
{
  criteria_ = criteria;
}*/












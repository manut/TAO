/* -*- C++ -*- */
// $Id$
// ==========================================================================
//
// = LIBRARY
//   orbsvcs
//
// = FILENAME
//
//
// = DESCRIPTION
//
//
// = AUTHOR
//    Pradeep Gore <pradeep@cs.wustl.edu>
//
// ==========================================================================

#ifndef NOTIFY_FILTER_FACTORY_I_H
#define NOTIFY_FILTER_FACTORY_I_H

#include "orbsvcs/orbsvcs/CosNotifyFilterS.h"

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

class TAO_ORBSVCS_Export TAO_Notify_FilterFactory_i : public POA_CosNotifyFilter::FilterFactory, public PortableServer::RefCountServantBase
{
  // = TITLE
  //
  // = DESCRIPTION
  //
  //

public:
  TAO_Notify_FilterFactory_i (void);
  // Constructor

  virtual ~TAO_Notify_FilterFactory_i (void);
  // Destructor

  CosNotifyFilter::FilterFactory_ptr
  get_ref (CORBA::Environment &ACE_TRY_ENV);
  // Activate with the default POA

  virtual CosNotifyFilter::Filter_ptr create_filter (
    const char * constraint_grammar,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException,
    CosNotifyFilter::InvalidGrammar
  ));

  virtual CosNotifyFilter::MappingFilter_ptr create_mapping_filter (
    const char * constraint_grammar,
    const CORBA::Any & default_value,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException,
    CosNotifyFilter::InvalidGrammar
  ));

};

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#endif /* NOTIFY_FILTER_FACTORY_I_H */

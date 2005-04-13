// -*- C++ -*-

//=============================================================================
/**
 *  @file    Servant_Impl_Base.h
 *
 *  $Id$
 *
 *  This file contains the non-template declaration of a base class for
 *  the template mixin for the generated servant class.
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================


#ifndef CIAO_SERVANT_IMPL_BASE_H
#define CIAO_SERVANT_IMPL_BASE_H

#include /**/ "ace/pre.h"

#include "ace/Hash_Map_Manager_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "CCM_EventC.h"
#include "CIAO_Server_Export.h"
#include "CCM_ComponentS.h"
#include "CCM_ContainerS.h"
#include "Home_Servant_Impl_Base.h"
#include "Servant_Activator.h"

namespace CIAO
{
  class Session_Container;

  /**
   * @class Servant_Impl_Base
   *
   * @brief Non-template base class for Servant_Impl.
   *
   * Holds the non-template parts of its child class
   * Servant_Impl.
   */
  class CIAO_SERVER_Export Servant_Impl_Base
    : public virtual POA_Components::CCMObject
  {
  public:
    explicit Servant_Impl_Base (void);

    Servant_Impl_Base (Components::CCMHome_ptr home, 
                       Home_Servant_Impl_Base *home_servant,
                       Session_Container * c);

    virtual ~Servant_Impl_Base (void);

    /// Operations for CCMObject interface.

    virtual ::Components::PrimaryKeyBase *
    get_primary_key (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::NoKeyAvailable));

    virtual CORBA::IRObject_ptr
    get_component_def (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    virtual Components::SessionComponent_ptr
    get_executor (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException)) = 0;

    virtual void
    configuration_complete (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::InvalidConfiguration));

    virtual void
    remove (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::RemoveFailure));

    virtual ::Components::ConnectionDescriptions *
    get_connections (const char *name
                     ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::InvalidName));

    virtual ::Components::ComponentPortDescription *
    get_all_ports (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    virtual CORBA::Object_ptr
    provide_facet (const char *name
                   ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::InvalidName));

    virtual ::Components::FacetDescriptions *
    get_named_facets (const ::Components::NameList & names
                        ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::InvalidName));

    virtual ::Components::FacetDescriptions *
    get_all_facets (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    
    virtual ::Components::ConsumerDescriptions *
    get_all_consumers (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));
    

    virtual ::Components::EventConsumerBase_ptr
    get_consumer (const char *sink_name
                  ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::InvalidName));

    virtual ::Components::EventConsumerBase_ptr
    disconnect_consumer (const char *source_name
                         ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::InvalidName,
                       Components::NoConnection));

    virtual ::Components::ConsumerDescriptions *
    get_named_consumers (const ::Components::NameList & names
                         ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::InvalidName));

    virtual ::Components::EmitterDescriptions *
    get_all_emitters (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    virtual ::Components::EmitterDescriptions *
    get_named_emitters (const ::Components::NameList & /* names */
                        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::InvalidName));

    virtual ::Components::ReceptacleDescriptions *
    get_all_receptacles (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    virtual ::Components::ReceptacleDescriptions *
    get_named_receptacles (const ::Components::NameList & /* names */
                           ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::InvalidName));

    virtual ::Components::PublisherDescriptions *
    get_all_publishers (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    virtual ::Components::PublisherDescriptions *
    get_named_publishers (const ::Components::NameList & names
                          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::InvalidName));

    /// Operation to set attributes on the component.
    virtual void set_attributes (const Components::ConfigValues &descr
                                 ACE_ENV_ARG_DECL) = 0;

    // Creates and returns the StandardConfigurator for the component.
    virtual ::Components::StandardConfigurator_ptr 
    get_standard_configurator (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    /// Override that returns the (passed-in) default POA of our member
    /// component's container, to ensure that we get registered
    /// to that POA when _this() is called.
    virtual PortableServer::POA_ptr _default_POA (
        ACE_ENV_SINGLE_ARG_DECL
      );

  protected:
    void add_facet (const char *port_name,
                    CORBA::Object_ptr port_ref);

    CORBA::Object_ptr lookup_facet (const char *port_name);

    ::Components::FacetDescription *lookup_facet_description (
        const char *port_name
      );

    void add_consumer (const char *port_name,
                       ::Components::EventConsumerBase_ptr port_ref);

    ::Components::EventConsumerBase_ptr lookup_consumer (
        const char *port_name
      );

    ::Components::ConsumerDescription *lookup_consumer_description (
        const char *port_name
      );
      
    // Used to create unique object IDs for port object references.  
    static ACE_CString gen_UUID (void);
      
  protected:
    typedef ACE_Hash_Map_Manager_Ex<const char *,
                                    ::Components::FacetDescription_var,
                                    ACE_Hash<const char *>,
                                    ACE_Equal_To<const char *>,
                                    ACE_Null_Mutex>
       FacetTable;

    typedef ACE_Hash_Map_Manager_Ex<const char *,
                                    ::Components::ConsumerDescription_var,
                                    ACE_Hash<const char *>,
                                    ACE_Equal_To<const char *>,
                                    ACE_Null_Mutex>
       ConsumerTable;

    FacetTable facet_table_;
    ConsumerTable consumer_table_;
    Components::CCMHome_var home_;
    Home_Servant_Impl_Base *home_servant_;
    Session_Container * container_;
  };
}

#include /**/ "ace/post.h"

#endif /* CIAO_SERVANT_IMPL_T_H */

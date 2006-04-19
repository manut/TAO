/* $Id$
 * This code was generated by the XML Schema Compiler.
 *
 * Changes made to this code will most likely be overwritten
 * when the handlers are recompiled.
 *
 * If you find errors or feel that there are bugfixes to be made,
 * please contact the current XSC maintainer:
 *             Will Otte <wotte@dre.vanderbilt.edu>
 */

// Fix for Borland compilers, which seem to have a broken
// <string> include.
#ifdef __BORLANDC__
# include <string.h>
#endif

#include "CIAO_Events_Handlers_Export.h"
#ifndef CIAOEVENTS_HPP
#define CIAOEVENTS_HPP

// Forward declarations.
//
namespace CIAO
{
  namespace Config_Handlers
  {
      class EventServiceType;
      class CIAOEventsDef;
      class EventServiceDescription;
      class FilterType;
      class Filter;
      class MCastSenderDescription;
      class MCastReceiverDescription;
      class EC_to_MCastSender;
      class MCastReceiver_to_EC;
  }
}

#include <memory>
#include <list>
#include "XMLSchema/Types.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
      class CIAO_Events_Handlers_Export EventServiceType : public ::XSCRT::Type
      {
        public:
        EventServiceType (::XSCRT::XML::Element< ACE_TCHAR > const&);
        EventServiceType (::XSCRT::XML::Attribute< ACE_TCHAR > const&);

        static EventServiceType const EC;
        static EventServiceType const RTEC;
        static EventServiceType const NOTIFY;
        static EventServiceType const RTNOTIFY;

        enum Value
        {
          EC_l,RTEC_l,NOTIFY_l,RTNOTIFY_l
        };


        Value
        integral () const;

        friend bool CIAO_Events_Handlers_Export
        operator== (EventServiceType const& a, EventServiceType const& b);

        friend bool CIAO_Events_Handlers_Export
        operator!= (EventServiceType const& a, EventServiceType const& b);

        private:
        EventServiceType (Value v);

        Value v_;
      };

      bool CIAO_Events_Handlers_Export operator== (EventServiceType const &a, EventServiceType const &b);

      bool CIAO_Events_Handlers_Export operator!= (EventServiceType const &a, EventServiceType const &b);


      class CIAO_Events_Handlers_Export CIAOEventsDef : public ::XSCRT::Type
      {
        //@@ VC6 anathema
        typedef ::XSCRT::Type Base__;

        // eventServiceConfiguration
        //
        public:
        typedef ::std::list< ::CIAO::Config_Handlers::EventServiceDescription >::iterator eventServiceConfiguration_iterator;
        typedef ::std::list< ::CIAO::Config_Handlers::EventServiceDescription >::const_iterator eventServiceConfiguration_const_iterator;
        eventServiceConfiguration_iterator begin_eventServiceConfiguration ();
        eventServiceConfiguration_iterator end_eventServiceConfiguration ();
        eventServiceConfiguration_const_iterator begin_eventServiceConfiguration () const;
        eventServiceConfiguration_const_iterator end_eventServiceConfiguration () const;
        void add_eventServiceConfiguration (::CIAO::Config_Handlers::EventServiceDescription const& );
        size_t count_eventServiceConfiguration (void) const;

        protected:
        ::std::list< ::CIAO::Config_Handlers::EventServiceDescription > eventServiceConfiguration_;

        // id
        //
        public:
        bool id_p () const;
        ::XMLSchema::ID< ACE_TCHAR > const& id () const;
        ::XMLSchema::ID< ACE_TCHAR >& id ();
        void id (::XMLSchema::ID< ACE_TCHAR > const& );

        protected:
        ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > id_;

        public:
        CIAOEventsDef ();

        CIAOEventsDef (::XSCRT::XML::Element< ACE_TCHAR > const&);
        CIAOEventsDef (CIAOEventsDef const& s);

        CIAOEventsDef&
        operator= (CIAOEventsDef const& s);

        private:
        char regulator__;
      };


      class CIAO_Events_Handlers_Export EventServiceDescription : public ::XSCRT::Type
      {
        //@@ VC6 anathema
        typedef ::XSCRT::Type Base__;

        // name
        //
        public:
        ::XMLSchema::string< ACE_TCHAR > const& name () const;
        void name (::XMLSchema::string< ACE_TCHAR > const& );

        protected:
        ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > name_;

        // node
        //
        public:
        ::XMLSchema::string< ACE_TCHAR > const& node () const;
        void node (::XMLSchema::string< ACE_TCHAR > const& );

        protected:
        ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > node_;

        // type
        //
        public:
        ::CIAO::Config_Handlers::EventServiceType const& type () const;
        void type (::CIAO::Config_Handlers::EventServiceType const& );

        protected:
        ::std::auto_ptr< ::CIAO::Config_Handlers::EventServiceType > type_;

        // svc_cfg_file
        //
        public:
        ::XMLSchema::string< ACE_TCHAR > const& svc_cfg_file () const;
        void svc_cfg_file (::XMLSchema::string< ACE_TCHAR > const& );

        protected:
        ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > svc_cfg_file_;

        // filter
        //
        public:
        typedef ::std::list< ::CIAO::Config_Handlers::Filter >::iterator filter_iterator;
        typedef ::std::list< ::CIAO::Config_Handlers::Filter >::const_iterator filter_const_iterator;
        filter_iterator begin_filter ();
        filter_iterator end_filter ();
        filter_const_iterator begin_filter () const;
        filter_const_iterator end_filter () const;
        void add_filter (::CIAO::Config_Handlers::Filter const& );
        size_t count_filter (void) const;

        protected:
        ::std::list< ::CIAO::Config_Handlers::Filter > filter_;

        // id
        //
        public:
        bool id_p () const;
        ::XMLSchema::ID< ACE_TCHAR > const& id () const;
        ::XMLSchema::ID< ACE_TCHAR >& id ();
        void id (::XMLSchema::ID< ACE_TCHAR > const& );

        protected:
        ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > id_;

        public:
        EventServiceDescription (::XMLSchema::string< ACE_TCHAR > const& name__,
                                 ::XMLSchema::string< ACE_TCHAR > const& node__,
                                 ::CIAO::Config_Handlers::EventServiceType const& type__,
                                 ::XMLSchema::string< ACE_TCHAR > const& svc_cfg_file__);

        EventServiceDescription (::XSCRT::XML::Element< ACE_TCHAR > const&);
        EventServiceDescription (EventServiceDescription const& s);

        EventServiceDescription&
        operator= (EventServiceDescription const& s);

        private:
        char regulator__;
      };


      class CIAO_Events_Handlers_Export FilterType : public ::XSCRT::Type
      {
        public:
        FilterType (::XSCRT::XML::Element< ACE_TCHAR > const&);
        FilterType (::XSCRT::XML::Attribute< ACE_TCHAR > const&);

        static FilterType const CONJUNCTION;
        static FilterType const DISJUNCTION;
        static FilterType const LOGICAL_AND;
        static FilterType const NEGATE;

        enum Value
        {
          CONJUNCTION_l,DISJUNCTION_l,LOGICAL_AND_l,NEGATE_l
        };


        Value
        integral () const;

        friend bool CIAO_Events_Handlers_Export
        operator== (FilterType const& a, FilterType const& b);

        friend bool CIAO_Events_Handlers_Export
        operator!= (FilterType const& a, FilterType const& b);

        private:
        FilterType (Value v);

        Value v_;
      };

      bool CIAO_Events_Handlers_Export operator== (FilterType const &a, FilterType const &b);

      bool CIAO_Events_Handlers_Export operator!= (FilterType const &a, FilterType const &b);


      class CIAO_Events_Handlers_Export Filter : public ::XSCRT::Type
      {
        //@@ VC6 anathema
        typedef ::XSCRT::Type Base__;

        // name
        //
        public:
        ::XMLSchema::string< ACE_TCHAR > const& name () const;
        void name (::XMLSchema::string< ACE_TCHAR > const& );

        protected:
        ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > name_;

        // type
        //
        public:
        ::CIAO::Config_Handlers::FilterType const& type () const;
        void type (::CIAO::Config_Handlers::FilterType const& );

        protected:
        ::std::auto_ptr< ::CIAO::Config_Handlers::FilterType > type_;

        // source
        //
        public:
        typedef ::std::list< ::XMLSchema::string< ACE_TCHAR > >::iterator source_iterator;
        typedef ::std::list< ::XMLSchema::string< ACE_TCHAR > >::const_iterator source_const_iterator;
        source_iterator begin_source ();
        source_iterator end_source ();
        source_const_iterator begin_source () const;
        source_const_iterator end_source () const;
        void add_source (::XMLSchema::string< ACE_TCHAR > const& );
        size_t count_source (void) const;

        protected:
        ::std::list< ::XMLSchema::string< ACE_TCHAR > > source_;

        // id
        //
        public:
        bool id_p () const;
        ::XMLSchema::ID< ACE_TCHAR > const& id () const;
        ::XMLSchema::ID< ACE_TCHAR >& id ();
        void id (::XMLSchema::ID< ACE_TCHAR > const& );

        protected:
        ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > id_;

        public:
        Filter (::XMLSchema::string< ACE_TCHAR > const& name__,
                ::CIAO::Config_Handlers::FilterType const& type__);

        Filter (::XSCRT::XML::Element< ACE_TCHAR > const&);
        Filter (Filter const& s);

        Filter&
        operator= (Filter const& s);

        private:
        char regulator__;
      };


      class CIAO_Events_Handlers_Export MCastSenderDescription : public ::XSCRT::Type
      {
        //@@ VC6 anathema
        typedef ::XSCRT::Type Base__;

        // node
        //
        public:
        ::XMLSchema::string< ACE_TCHAR > const& node () const;
        void node (::XMLSchema::string< ACE_TCHAR > const& );

        protected:
        ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > node_;

        // type
        //
        public:
        ::CIAO::Config_Handlers::EventServiceType const& type () const;
        void type (::CIAO::Config_Handlers::EventServiceType const& );

        protected:
        ::std::auto_ptr< ::CIAO::Config_Handlers::EventServiceType > type_;

        // svc_cfg_file
        //
        public:
        ::XMLSchema::string< ACE_TCHAR > const& svc_cfg_file () const;
        void svc_cfg_file (::XMLSchema::string< ACE_TCHAR > const& );

        protected:
        ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > svc_cfg_file_;

        // id
        //
        public:
        bool id_p () const;
        ::XMLSchema::ID< ACE_TCHAR > const& id () const;
        ::XMLSchema::ID< ACE_TCHAR >& id ();
        void id (::XMLSchema::ID< ACE_TCHAR > const& );

        protected:
        ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > id_;

        public:
        MCastSenderDescription (::XMLSchema::string< ACE_TCHAR > const& node__,
                                ::CIAO::Config_Handlers::EventServiceType const& type__,
                                ::XMLSchema::string< ACE_TCHAR > const& svc_cfg_file__);

        MCastSenderDescription (::XSCRT::XML::Element< ACE_TCHAR > const&);
        MCastSenderDescription (MCastSenderDescription const& s);

        MCastSenderDescription&
        operator= (MCastSenderDescription const& s);

        private:
        char regulator__;
      };


      class CIAO_Events_Handlers_Export MCastReceiverDescription : public ::XSCRT::Type
      {
        //@@ VC6 anathema
        typedef ::XSCRT::Type Base__;

        // node
        //
        public:
        ::XMLSchema::string< ACE_TCHAR > const& node () const;
        void node (::XMLSchema::string< ACE_TCHAR > const& );

        protected:
        ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > node_;

        // type
        //
        public:
        ::CIAO::Config_Handlers::EventServiceType const& type () const;
        void type (::CIAO::Config_Handlers::EventServiceType const& );

        protected:
        ::std::auto_ptr< ::CIAO::Config_Handlers::EventServiceType > type_;

        // svc_cfg_file
        //
        public:
        ::XMLSchema::string< ACE_TCHAR > const& svc_cfg_file () const;
        void svc_cfg_file (::XMLSchema::string< ACE_TCHAR > const& );

        protected:
        ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > svc_cfg_file_;

        // id
        //
        public:
        bool id_p () const;
        ::XMLSchema::ID< ACE_TCHAR > const& id () const;
        ::XMLSchema::ID< ACE_TCHAR >& id ();
        void id (::XMLSchema::ID< ACE_TCHAR > const& );

        protected:
        ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > id_;

        public:
        MCastReceiverDescription (::XMLSchema::string< ACE_TCHAR > const& node__,
                                  ::CIAO::Config_Handlers::EventServiceType const& type__,
                                  ::XMLSchema::string< ACE_TCHAR > const& svc_cfg_file__);

        MCastReceiverDescription (::XSCRT::XML::Element< ACE_TCHAR > const&);
        MCastReceiverDescription (MCastReceiverDescription const& s);

        MCastReceiverDescription&
        operator= (MCastReceiverDescription const& s);

        private:
        char regulator__;
      };


      class CIAO_Events_Handlers_Export EC_to_MCastSender : public ::XSCRT::Type
      {
        //@@ VC6 anathema
        typedef ::XSCRT::Type Base__;

        // destination
        //
        public:
        ::XMLSchema::string< ACE_TCHAR > const& destination () const;
        void destination (::XMLSchema::string< ACE_TCHAR > const& );

        protected:
        ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > destination_;

        // id
        //
        public:
        bool id_p () const;
        ::XMLSchema::ID< ACE_TCHAR > const& id () const;
        ::XMLSchema::ID< ACE_TCHAR >& id ();
        void id (::XMLSchema::ID< ACE_TCHAR > const& );

        protected:
        ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > id_;

        public:
        EC_to_MCastSender (::XMLSchema::string< ACE_TCHAR > const& destination__);

        EC_to_MCastSender (::XSCRT::XML::Element< ACE_TCHAR > const&);
        EC_to_MCastSender (EC_to_MCastSender const& s);

        EC_to_MCastSender&
        operator= (EC_to_MCastSender const& s);

        private:
        char regulator__;
      };


      class CIAO_Events_Handlers_Export MCastReceiver_to_EC : public ::XSCRT::Type
      {
        //@@ VC6 anathema
        typedef ::XSCRT::Type Base__;

        // source
        //
        public:
        ::XMLSchema::string< ACE_TCHAR > const& source () const;
        void source (::XMLSchema::string< ACE_TCHAR > const& );

        protected:
        ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > source_;

        // destination
        //
        public:
        ::XMLSchema::string< ACE_TCHAR > const& destination () const;
        void destination (::XMLSchema::string< ACE_TCHAR > const& );

        protected:
        ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > destination_;

        // id
        //
        public:
        bool id_p () const;
        ::XMLSchema::ID< ACE_TCHAR > const& id () const;
        ::XMLSchema::ID< ACE_TCHAR >& id ();
        void id (::XMLSchema::ID< ACE_TCHAR > const& );

        protected:
        ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > id_;

        public:
        MCastReceiver_to_EC (::XMLSchema::string< ACE_TCHAR > const& source__,
                             ::XMLSchema::string< ACE_TCHAR > const& destination__);

        MCastReceiver_to_EC (::XSCRT::XML::Element< ACE_TCHAR > const&);
        MCastReceiver_to_EC (MCastReceiver_to_EC const& s);

        MCastReceiver_to_EC&
        operator= (MCastReceiver_to_EC const& s);

        private:
        char regulator__;
      };
    }

}

namespace CIAO
{
  namespace Config_Handlers
  {
      CIAO_Events_Handlers_Export
      ::CIAO::Config_Handlers::CIAOEventsDef
      CIAOEvents (xercesc::DOMDocument const*);
  }
}

#include "XMLSchema/Traversal.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
      namespace Traversal
      {
        typedef
        ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::EventServiceType >
        EventServiceType;

        struct CIAO_Events_Handlers_Export CIAOEventsDef : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::CIAOEventsDef >
        {
          virtual void
          traverse (Type&);

          virtual void
          traverse (Type const&);

          virtual void
          pre (Type&);

          virtual void
          pre (Type const&);

          virtual void
          eventServiceConfiguration (Type&);

          virtual void
          eventServiceConfiguration (Type const&);

          virtual void
          eventServiceConfiguration_pre (Type&);

          virtual void
          eventServiceConfiguration_pre (Type const&);

          virtual void
          eventServiceConfiguration_next (Type&);

          virtual void
          eventServiceConfiguration_next (Type const&);

          virtual void
          eventServiceConfiguration_post (Type&);

          virtual void
          eventServiceConfiguration_post (Type const&);

          virtual void
          id (Type&);

          virtual void
          id (Type const&);

          virtual void
          id_none (Type&);

          virtual void
          id_none (Type const&);

          virtual void
          post (Type&);

          virtual void
          post (Type const&);
        };

        struct CIAO_Events_Handlers_Export EventServiceDescription : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::EventServiceDescription >
        {
          virtual void
          traverse (Type&);

          virtual void
          traverse (Type const&);

          virtual void
          pre (Type&);

          virtual void
          pre (Type const&);

          virtual void
          name (Type&);

          virtual void
          name (Type const&);

          virtual void
          node (Type&);

          virtual void
          node (Type const&);

          virtual void
          type (Type&);

          virtual void
          type (Type const&);

          virtual void
          svc_cfg_file (Type&);

          virtual void
          svc_cfg_file (Type const&);

          virtual void
          filter (Type&);

          virtual void
          filter (Type const&);

          virtual void
          filter_pre (Type&);

          virtual void
          filter_pre (Type const&);

          virtual void
          filter_next (Type&);

          virtual void
          filter_next (Type const&);

          virtual void
          filter_post (Type&);

          virtual void
          filter_post (Type const&);

          virtual void
          filter_none (Type&);

          virtual void
          filter_none (Type const&);

          virtual void
          id (Type&);

          virtual void
          id (Type const&);

          virtual void
          id_none (Type&);

          virtual void
          id_none (Type const&);

          virtual void
          post (Type&);

          virtual void
          post (Type const&);
        };

        typedef
        ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::FilterType >
        FilterType;

        struct CIAO_Events_Handlers_Export Filter : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::Filter >
        {
          virtual void
          traverse (Type&);

          virtual void
          traverse (Type const&);

          virtual void
          pre (Type&);

          virtual void
          pre (Type const&);

          virtual void
          name (Type&);

          virtual void
          name (Type const&);

          virtual void
          type (Type&);

          virtual void
          type (Type const&);

          virtual void
          source (Type&);

          virtual void
          source (Type const&);

          virtual void
          source_pre (Type&);

          virtual void
          source_pre (Type const&);

          virtual void
          source_next (Type&);

          virtual void
          source_next (Type const&);

          virtual void
          source_post (Type&);

          virtual void
          source_post (Type const&);

          virtual void
          id (Type&);

          virtual void
          id (Type const&);

          virtual void
          id_none (Type&);

          virtual void
          id_none (Type const&);

          virtual void
          post (Type&);

          virtual void
          post (Type const&);
        };

        struct CIAO_Events_Handlers_Export MCastSenderDescription : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::MCastSenderDescription >
        {
          virtual void
          traverse (Type&);

          virtual void
          traverse (Type const&);

          virtual void
          pre (Type&);

          virtual void
          pre (Type const&);

          virtual void
          node (Type&);

          virtual void
          node (Type const&);

          virtual void
          type (Type&);

          virtual void
          type (Type const&);

          virtual void
          svc_cfg_file (Type&);

          virtual void
          svc_cfg_file (Type const&);

          virtual void
          id (Type&);

          virtual void
          id (Type const&);

          virtual void
          id_none (Type&);

          virtual void
          id_none (Type const&);

          virtual void
          post (Type&);

          virtual void
          post (Type const&);
        };

        struct CIAO_Events_Handlers_Export MCastReceiverDescription : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::MCastReceiverDescription >
        {
          virtual void
          traverse (Type&);

          virtual void
          traverse (Type const&);

          virtual void
          pre (Type&);

          virtual void
          pre (Type const&);

          virtual void
          node (Type&);

          virtual void
          node (Type const&);

          virtual void
          type (Type&);

          virtual void
          type (Type const&);

          virtual void
          svc_cfg_file (Type&);

          virtual void
          svc_cfg_file (Type const&);

          virtual void
          id (Type&);

          virtual void
          id (Type const&);

          virtual void
          id_none (Type&);

          virtual void
          id_none (Type const&);

          virtual void
          post (Type&);

          virtual void
          post (Type const&);
        };

        struct CIAO_Events_Handlers_Export EC_to_MCastSender : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::EC_to_MCastSender >
        {
          virtual void
          traverse (Type&);

          virtual void
          traverse (Type const&);

          virtual void
          pre (Type&);

          virtual void
          pre (Type const&);

          virtual void
          destination (Type&);

          virtual void
          destination (Type const&);

          virtual void
          id (Type&);

          virtual void
          id (Type const&);

          virtual void
          id_none (Type&);

          virtual void
          id_none (Type const&);

          virtual void
          post (Type&);

          virtual void
          post (Type const&);
        };

        struct CIAO_Events_Handlers_Export MCastReceiver_to_EC : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::MCastReceiver_to_EC >
        {
          virtual void
          traverse (Type&);

          virtual void
          traverse (Type const&);

          virtual void
          pre (Type&);

          virtual void
          pre (Type const&);

          virtual void
          source (Type&);

          virtual void
          source (Type const&);

          virtual void
          destination (Type&);

          virtual void
          destination (Type const&);

          virtual void
          id (Type&);

          virtual void
          id (Type const&);

          virtual void
          id_none (Type&);

          virtual void
          id_none (Type const&);

          virtual void
          post (Type&);

          virtual void
          post (Type const&);
        };
      }
    }

}

#include "XMLSchema/Writer.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
      namespace Writer
      {
        struct EventServiceType : Traversal::EventServiceType,
        virtual ::XSCRT::Writer< ACE_TCHAR >
        {
          EventServiceType (::XSCRT::XML::Element< ACE_TCHAR >&);

          virtual void
          traverse (Type &o)
          {
            this->traverse (const_cast <Type const &> (o));
          }

          virtual void
          traverse (Type const&);

          protected:
          EventServiceType ();
        };

        struct CIAOEventsDef : Traversal::CIAOEventsDef,
        virtual ::XSCRT::Writer< ACE_TCHAR >
        {
          typedef ::CIAO::Config_Handlers::CIAOEventsDef Type;
          CIAOEventsDef (::XSCRT::XML::Element< ACE_TCHAR >&);

          virtual void
          traverse (Type &o)
          {

            this->traverse (const_cast <Type const &> (o));
          }


          virtual void
          traverse (Type const&);

          virtual void
          eventServiceConfiguration_pre (Type &o)
          {

            this->eventServiceConfiguration_pre (const_cast <Type const &> (o));
          }


          virtual void
          eventServiceConfiguration_pre (Type const&);

          virtual void
          eventServiceConfiguration_next (Type &o)
          {

            this->eventServiceConfiguration_next (const_cast <Type const &> (o));
          }


          virtual void
          eventServiceConfiguration_next (Type const&);

          virtual void
          eventServiceConfiguration_post (Type &o)
          {

            this->eventServiceConfiguration_post (const_cast <Type const &> (o));
          }


          virtual void
          eventServiceConfiguration_post (Type const&);

          virtual void
          id (Type &o)
          {

            this->id (const_cast <Type const &> (o));
          }


          virtual void
          id (Type const&);

          protected:
          CIAOEventsDef ();
        };

        struct EventServiceDescription : Traversal::EventServiceDescription,
        virtual ::XSCRT::Writer< ACE_TCHAR >
        {
          typedef ::CIAO::Config_Handlers::EventServiceDescription Type;
          EventServiceDescription (::XSCRT::XML::Element< ACE_TCHAR >&);

          virtual void
          traverse (Type &o)
          {

            this->traverse (const_cast <Type const &> (o));
          }


          virtual void
          traverse (Type const&);

          virtual void
          name (Type &o)
          {

            this->name (const_cast <Type const &> (o));
          }


          virtual void
          name (Type const&);

          virtual void
          node (Type &o)
          {

            this->node (const_cast <Type const &> (o));
          }


          virtual void
          node (Type const&);

          virtual void
          type (Type &o)
          {

            this->type (const_cast <Type const &> (o));
          }


          virtual void
          type (Type const&);

          virtual void
          svc_cfg_file (Type &o)
          {

            this->svc_cfg_file (const_cast <Type const &> (o));
          }


          virtual void
          svc_cfg_file (Type const&);

          virtual void
          filter_pre (Type &o)
          {

            this->filter_pre (const_cast <Type const &> (o));
          }


          virtual void
          filter_pre (Type const&);

          virtual void
          filter_next (Type &o)
          {

            this->filter_next (const_cast <Type const &> (o));
          }


          virtual void
          filter_next (Type const&);

          virtual void
          filter_post (Type &o)
          {

            this->filter_post (const_cast <Type const &> (o));
          }


          virtual void
          filter_post (Type const&);

          virtual void
          id (Type &o)
          {

            this->id (const_cast <Type const &> (o));
          }


          virtual void
          id (Type const&);

          protected:
          EventServiceDescription ();
        };

        struct FilterType : Traversal::FilterType,
        virtual ::XSCRT::Writer< ACE_TCHAR >
        {
          FilterType (::XSCRT::XML::Element< ACE_TCHAR >&);

          virtual void
          traverse (Type &o)
          {
            this->traverse (const_cast <Type const &> (o));
          }

          virtual void
          traverse (Type const&);

          protected:
          FilterType ();
        };

        struct Filter : Traversal::Filter,
        virtual ::XSCRT::Writer< ACE_TCHAR >
        {
          typedef ::CIAO::Config_Handlers::Filter Type;
          Filter (::XSCRT::XML::Element< ACE_TCHAR >&);

          virtual void
          traverse (Type &o)
          {

            this->traverse (const_cast <Type const &> (o));
          }


          virtual void
          traverse (Type const&);

          virtual void
          name (Type &o)
          {

            this->name (const_cast <Type const &> (o));
          }


          virtual void
          name (Type const&);

          virtual void
          type (Type &o)
          {

            this->type (const_cast <Type const &> (o));
          }


          virtual void
          type (Type const&);

          virtual void
          source_pre (Type &o)
          {

            this->source_pre (const_cast <Type const &> (o));
          }


          virtual void
          source_pre (Type const&);

          virtual void
          source_next (Type &o)
          {

            this->source_next (const_cast <Type const &> (o));
          }


          virtual void
          source_next (Type const&);

          virtual void
          source_post (Type &o)
          {

            this->source_post (const_cast <Type const &> (o));
          }


          virtual void
          source_post (Type const&);

          virtual void
          id (Type &o)
          {

            this->id (const_cast <Type const &> (o));
          }


          virtual void
          id (Type const&);

          protected:
          Filter ();
        };

        struct MCastSenderDescription : Traversal::MCastSenderDescription,
        virtual ::XSCRT::Writer< ACE_TCHAR >
        {
          typedef ::CIAO::Config_Handlers::MCastSenderDescription Type;
          MCastSenderDescription (::XSCRT::XML::Element< ACE_TCHAR >&);

          virtual void
          traverse (Type &o)
          {

            this->traverse (const_cast <Type const &> (o));
          }


          virtual void
          traverse (Type const&);

          virtual void
          node (Type &o)
          {

            this->node (const_cast <Type const &> (o));
          }


          virtual void
          node (Type const&);

          virtual void
          type (Type &o)
          {

            this->type (const_cast <Type const &> (o));
          }


          virtual void
          type (Type const&);

          virtual void
          svc_cfg_file (Type &o)
          {

            this->svc_cfg_file (const_cast <Type const &> (o));
          }


          virtual void
          svc_cfg_file (Type const&);

          virtual void
          id (Type &o)
          {

            this->id (const_cast <Type const &> (o));
          }


          virtual void
          id (Type const&);

          protected:
          MCastSenderDescription ();
        };

        struct MCastReceiverDescription : Traversal::MCastReceiverDescription,
        virtual ::XSCRT::Writer< ACE_TCHAR >
        {
          typedef ::CIAO::Config_Handlers::MCastReceiverDescription Type;
          MCastReceiverDescription (::XSCRT::XML::Element< ACE_TCHAR >&);

          virtual void
          traverse (Type &o)
          {

            this->traverse (const_cast <Type const &> (o));
          }


          virtual void
          traverse (Type const&);

          virtual void
          node (Type &o)
          {

            this->node (const_cast <Type const &> (o));
          }


          virtual void
          node (Type const&);

          virtual void
          type (Type &o)
          {

            this->type (const_cast <Type const &> (o));
          }


          virtual void
          type (Type const&);

          virtual void
          svc_cfg_file (Type &o)
          {

            this->svc_cfg_file (const_cast <Type const &> (o));
          }


          virtual void
          svc_cfg_file (Type const&);

          virtual void
          id (Type &o)
          {

            this->id (const_cast <Type const &> (o));
          }


          virtual void
          id (Type const&);

          protected:
          MCastReceiverDescription ();
        };

        struct EC_to_MCastSender : Traversal::EC_to_MCastSender,
        virtual ::XSCRT::Writer< ACE_TCHAR >
        {
          typedef ::CIAO::Config_Handlers::EC_to_MCastSender Type;
          EC_to_MCastSender (::XSCRT::XML::Element< ACE_TCHAR >&);

          virtual void
          traverse (Type &o)
          {

            this->traverse (const_cast <Type const &> (o));
          }


          virtual void
          traverse (Type const&);

          virtual void
          destination (Type &o)
          {

            this->destination (const_cast <Type const &> (o));
          }


          virtual void
          destination (Type const&);

          virtual void
          id (Type &o)
          {

            this->id (const_cast <Type const &> (o));
          }


          virtual void
          id (Type const&);

          protected:
          EC_to_MCastSender ();
        };

        struct MCastReceiver_to_EC : Traversal::MCastReceiver_to_EC,
        virtual ::XSCRT::Writer< ACE_TCHAR >
        {
          typedef ::CIAO::Config_Handlers::MCastReceiver_to_EC Type;
          MCastReceiver_to_EC (::XSCRT::XML::Element< ACE_TCHAR >&);

          virtual void
          traverse (Type &o)
          {

            this->traverse (const_cast <Type const &> (o));
          }


          virtual void
          traverse (Type const&);

          virtual void
          source (Type &o)
          {

            this->source (const_cast <Type const &> (o));
          }


          virtual void
          source (Type const&);

          virtual void
          destination (Type &o)
          {

            this->destination (const_cast <Type const &> (o));
          }


          virtual void
          destination (Type const&);

          virtual void
          id (Type &o)
          {

            this->id (const_cast <Type const &> (o));
          }


          virtual void
          id (Type const&);

          protected:
          MCastReceiver_to_EC ();
        };
      }
    }

}

namespace CIAO
{
  namespace Config_Handlers
  {
      CIAO_Events_Handlers_Export
      void
      CIAOEvents (::CIAO::Config_Handlers::CIAOEventsDef const&, xercesc::DOMDocument*);
  }
}

#endif // CIAOEVENTS_HPP

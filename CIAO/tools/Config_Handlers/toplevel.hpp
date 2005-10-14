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


// Fixes the VC6 warning 4786.
#include "vc6-4786.h"
 
// Fix for Borland compilers, which seem to have a broken
// <string> include.
#ifdef __BORLANDC__
# include <string.h>
#endif

#include "XSC_XML_Handlers_Export.h"
#ifndef TOPLEVEL_HPP
#define TOPLEVEL_HPP

// Forward declarations.
//
namespace CIAO
{
  namespace Config_Handlers
  {
    class TopLevelPackageDescription;
  }
}

#include <memory>
#include <list>
#include "XMLSchema/Types.hpp"

#include "pcd.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    class XSC_XML_Handlers_Export TopLevelPackageDescription : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // package
      // 
      public:
      typedef ::std::list< ::CIAO::Config_Handlers::PackageConfiguration >::iterator package_iterator;
      typedef ::std::list< ::CIAO::Config_Handlers::PackageConfiguration >::const_iterator package_const_iterator;
      package_iterator begin_package ();
      package_iterator end_package ();
      package_const_iterator begin_package () const;
      package_const_iterator end_package () const;
      void add_package (::CIAO::Config_Handlers::PackageConfiguration const& );
      size_t count_package (void) const;

      protected:
      ::std::list< ::CIAO::Config_Handlers::PackageConfiguration > package_;

      public:
      TopLevelPackageDescription ();

      TopLevelPackageDescription (::XSCRT::XML::Element< ACE_TCHAR > const&);
      TopLevelPackageDescription (TopLevelPackageDescription const& s);

      TopLevelPackageDescription&
      operator= (TopLevelPackageDescription const& s);

      private:
      char regulator__;
    };
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
  }
}

#include "XMLSchema/Traversal.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace Traversal
    {
      struct XSC_XML_Handlers_Export TopLevelPackageDescription : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::TopLevelPackageDescription >
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
        package (Type&);

        virtual void
        package (Type const&);

        virtual void
        package_pre (Type&);

        virtual void
        package_pre (Type const&);

        virtual void
        package_next (Type&);

        virtual void
        package_next (Type const&);

        virtual void
        package_post (Type&);

        virtual void
        package_post (Type const&);

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
      struct TopLevelPackageDescription : Traversal::TopLevelPackageDescription, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::TopLevelPackageDescription Type;
        TopLevelPackageDescription (::XSCRT::XML::Element< ACE_TCHAR >&);

        #ifdef __BORLANDC__
        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        traverse (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        package_pre (Type &o)
        {

          this->package_pre (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        package_pre (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        package_next (Type &o)
        {

          this->package_next (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        package_next (Type const&);

        // Hack to make borland stop complaining.  
        #ifdef __BORLANDC__
        virtual void 
        package_post (Type &o)
        {

          this->package_post (const_cast <Type const &> (o));
        }


        #endif /* __BORLANDC__ */
        virtual void
        package_post (Type const&);

        protected:
        TopLevelPackageDescription ();
      };
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
  }
}

#endif // TOPLEVEL_HPP

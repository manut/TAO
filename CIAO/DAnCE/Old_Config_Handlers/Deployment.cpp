// $Id$
#include "Deployment.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    ::CIAO::Config_Handlers::Domain
    domain (xercesc::DOMDocument const* d)
    {
      ::XSCRT::XML::Element< char > e (d->getDocumentElement ());
      if (e.name () == "domain")
      {
        ::CIAO::Config_Handlers::Domain r (e);
        return r;
      }

      else
      {
        throw 1;
      }
    }

    ::CIAO::Config_Handlers::DeploymentPlan
    deploymentPlan (xercesc::DOMDocument const* d)
    {
      ::XSCRT::XML::Element< char > e (d->getDocumentElement ());
      if (e.name () == "deploymentPlan")
      {
        ::CIAO::Config_Handlers::DeploymentPlan r (e);
        return r;
      }

      else
      {
        throw 1;
      }
    }

    ::CIAO::Config_Handlers::ImplementationArtifactDescription
    implementationArtifactDescription (xercesc::DOMDocument const* d)
    {
      ::XSCRT::XML::Element< char > e (d->getDocumentElement ());
      if (e.name () == "implementationArtifactDescription")
      {
        ::CIAO::Config_Handlers::ImplementationArtifactDescription r (e);
        return r;
      }

      else
      {
        throw 1;
      }
    }

    ::CIAO::Config_Handlers::ComponentInterfaceDescription
    componentInterfaceDescription (xercesc::DOMDocument const* d)
    {
      ::XSCRT::XML::Element< char > e (d->getDocumentElement ());
      if (e.name () == "componentInterfaceDescription")
      {
        ::CIAO::Config_Handlers::ComponentInterfaceDescription r (e);
        return r;
      }

      else
      {
        throw 1;
      }
    }

    ::CIAO::Config_Handlers::ComponentImplementationDescription
    componentImplementationDescription (xercesc::DOMDocument const* d)
    {
      ::XSCRT::XML::Element< char > e (d->getDocumentElement ());
      if (e.name () == "componentImplementationDescription")
      {
        ::CIAO::Config_Handlers::ComponentImplementationDescription r (e);
        return r;
      }

      else
      {
        throw 1;
      }
    }

    ::CIAO::Config_Handlers::ComponentPackageDescription
    componentPackageDescription (xercesc::DOMDocument const* d)
    {
      ::XSCRT::XML::Element< char > e (d->getDocumentElement ());
      if (e.name () == "componentPackageDescription")
      {
        ::CIAO::Config_Handlers::ComponentPackageDescription r (e);
        return r;
      }

      else
      {
        throw 1;
      }
    }

    ::CIAO::Config_Handlers::PackageConfiguration
    packageConfiguration (xercesc::DOMDocument const* d)
    {
      ::XSCRT::XML::Element< char > e (d->getDocumentElement ());
      if (e.name () == "packageConfiguration")
      {
        ::CIAO::Config_Handlers::PackageConfiguration r (e);
        return r;
      }

      else
      {
        throw 1;
      }
    }

    ::CIAO::Config_Handlers::TopLevelPackageDescription
    topLevelPackageDescription (xercesc::DOMDocument const* d)
    {
      ::XSCRT::XML::Element< char > e (d->getDocumentElement ());
      if (e.name () == "topLevelPackageDescription")
      {
        ::CIAO::Config_Handlers::TopLevelPackageDescription r (e);
        return r;
      }

      else
      {
        throw 1;
      }
    }
  }
}


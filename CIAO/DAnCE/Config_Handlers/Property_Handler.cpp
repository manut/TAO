//$Id$

#include "Property_Handler.h"
#include "Any_Handler.h"
#include "Basic_Deployment_Data.hpp"
#include "ciao/Deployment_DataC.h"

namespace CIAO
{
  namespace Config_Handlers
  {

    Property_Handler::Property_Handler (void)
    {
    }

    Property_Handler::~Property_Handler (void)
    {
    }

    void
    Property_Handler::get_property (
      const Property& desc,
      Deployment::Property& toconfig)
    {
      toconfig.name =
        CORBA::string_dup (desc.name ().c_str ());

      Any_Handler::extract_into_any (desc.value (),
                                     toconfig.value);

    }

    Property
    Property_Handler::get_property (
      const Deployment::Property& src)
    {
      ::XMLSchema::string< char > name ((src.name));
      Any value (Any_Handler::get_any (src.value));

      Property prop (name,value);

      return prop;
    }

  }
}

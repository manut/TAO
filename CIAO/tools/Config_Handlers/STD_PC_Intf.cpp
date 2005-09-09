// $Id$

#if defined (_MSC_VER) && (_MSC_VER < 1300)
#pragma warning (disable: 4018)
#pragma warning (disable: 4284)
#pragma warning (disable: 4146)
#endif

#include "STD_PC_Intf.h"
#include "XML_Helper.h"
#include "Deployment.hpp"
#include "STD_PCD_Handler.h"
#include "ciao/Packaging_DataC.h"


namespace CIAO
{
  namespace Config_Handlers
  {
    STD_PC_Intf::STD_PC_Intf (const char *file)
    {
      if (!this->prepare_PC (file))
        throw;
    }

    bool
    STD_PC_Intf::prepare_PC (const char *file)
    {
      ACE_Auto_Ptr<XML_Helper> helper (new XML_Helper);

      if (!helper->is_initialized ())
        return false;

      // parse the .pcd (PackageConfigurationDescription) file
      xercesc::DOMDocument *dom =
        helper->create_dom (file);

      if (!dom)
        return false;


      PackageConfiguration pc =
        packageConfiguration (dom);


      Deployment::PackageConfiguration idl_pc;


      STD_PCD_Handler pcd_handler (helper.get ());

      pcd_handler.package_config (pc,
                                  idl_pc);


      Deployment::PackageConfiguration *p_idl_pc =
        new Deployment::PackageConfiguration (idl_pc);

      // let ACE_Auto_Ptr take over
      this->idl_pc_.reset (p_idl_pc);

      if (this->idl_pc_.get ())
        return true;

      return false;
    }

    ::Deployment::PackageConfiguration const *
    STD_PC_Intf::get_PC (void) const
    {
      return this->idl_pc_.get ();
    }

    ::Deployment::PackageConfiguration *
    STD_PC_Intf::get_PC (void)
    {
      return this->idl_pc_.release ();
    }
  }
}

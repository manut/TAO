// $Id$

#include "XML_Topology_Factory.h"
#include "XML_Saver.h"
#include "XML_Loader.h"

#include "tao/debug.h"
#include "ace/OS_NS_strings.h"
//#include "ace/Service_Object.h"

namespace TAO_Notify
{

  XML_Topology_Factory::XML_Topology_Factory()
    : save_base_path_ ("./Notification_Service_Topology")
    , load_base_path_ ("./Notification_Service_Topology")
    , backup_count_ (2)
    , timestamp_ (true)
  {
  }

  // virtual
  Topology_Saver*
  XML_Topology_Factory::create_saver ()
  {
    XML_Saver *saver = 0;

    ACE_NEW_RETURN (saver, XML_Saver (this->timestamp_), 0);

    if (! saver->open ( this->save_base_path_.c_str (), this->backup_count_))
    {
      delete saver;
      saver = 0;
    }
    return ACE_static_cast (Topology_Saver *, saver);
  }

  // virtual
  Topology_Loader*
  XML_Topology_Factory::create_loader()
  {
    XML_Loader *loader = 0;
    ACE_NEW_NORETURN(loader, XML_Loader);

    if (! loader->open(this->load_base_path_))
    {
      delete loader;
      loader = 0;
    }
    return ACE_static_cast (Topology_Loader *, loader);
  }

  // virtual
  int
  XML_Topology_Factory::init (int argc, ACE_TCHAR *argv[])
  {
    int result = 0;
    bool verbose = false;
    for (int narg = 0; narg < argc; ++narg)
    {
      ACE_TCHAR * av = argv[narg];
      if (ACE_OS::strcasecmp (av, "-v") == 0)
      {
        verbose = true;
        ACE_DEBUG ((LM_DEBUG,
          ACE_TEXT ("(%P|%t) Standard_Event_Persistence: -verbose\n")
          ));
      }
      else if (ACE_OS::strcasecmp (av, "-base_path") == 0 && narg + 1 < argc)
      {
        this->save_base_path_ = argv[narg + 1];
        this->load_base_path_ = argv[narg + 1];
        if (TAO_debug_level > 0 || verbose)
        {
          ACE_DEBUG ((LM_DEBUG,
            ACE_TEXT ("(%P|%t) XML_TopologyFactory: Setting -base_path: %s\n"),
            this->save_base_path_.c_str ()
          ));
        }
        narg += 1;
      }
      else if (ACE_OS::strcasecmp (av, "-save_base_path") == 0 && narg + 1 < argc)
      {
        this->save_base_path_ = argv[narg + 1];
        if (TAO_debug_level > 0 || verbose)
        {
          ACE_DEBUG ((LM_DEBUG,
            ACE_TEXT ("(%P|%t) XML_TopologyFactory: Setting -save_base_path: %s\n"),
            this->save_base_path_.c_str ()
          ));
        }
        narg += 1;
      }
      else if (ACE_OS::strcasecmp (av, "-load_base_path") == 0 && narg + 1 < argc)
      {
        this->load_base_path_ = argv[narg + 1];
        if (TAO_debug_level > 0 || verbose)
        {
          ACE_DEBUG ((LM_DEBUG,
            ACE_TEXT ("(%P|%t) XML_TopologyFactory: Setting -load_base_path: %s\n"),
            this->load_base_path_.c_str ()
          ));
        }
        narg += 1;
      }
      else if (ACE_OS::strcasecmp (av, "-backup_count") == 0 && narg + 1 < argc)
      {
        this->backup_count_ = ACE_OS::atoi(argv[narg + 1]);
        if (TAO_debug_level > 0 || verbose)
        {
          ACE_DEBUG ((LM_DEBUG,
            ACE_TEXT ("(%P|%t) XML_TopologyFactory: Setting -file_count: %d\n"),
            this->backup_count_
          ));
        }
        narg += 1;
      }
      else if (ACE_OS::strcasecmp (av, "-no_timestamp") == 0)
      {
        this->timestamp_ = false;
        if (TAO_debug_level > 0 || verbose)
        {
          ACE_DEBUG ((LM_DEBUG,
            ACE_TEXT ("(%P|%t) XML_TopologyFactory: Setting -no_timestamp\n")
          ));
        }
      }
      else
      {
        ACE_ERROR ((LM_ERROR,
          ACE_TEXT ("(%P|%t) Unknown parameter to XML Topology Factory: %s\n"),
          argv[narg]
          ));
        result = -1;
      }
    }
    return result;
  }

  // virtual
  int
  XML_Topology_Factory::fini ()
  {
    // nothing to do yet
    return 0;
  }

ACE_FACTORY_DEFINE (TAO_Notify_Persist, XML_Topology_Factory)


} /* namespace TAO_Notify */



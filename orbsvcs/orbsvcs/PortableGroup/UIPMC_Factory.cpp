// $Id$

#include "orbsvcs/Log_Macros.h"
#include "orbsvcs/PortableGroup/UIPMC_Factory.h"
#include "orbsvcs/PortableGroup/UIPMC_Acceptor.h"
#include "orbsvcs/PortableGroup/UIPMC_Connector.h"
#include "tao/ORB_Constants.h"
#include "ace/OS_NS_strings.h"
#include "ace/UUID.h"

static const char the_prefix[] = "uipmc";

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_UIPMC_Protocol_Factory::TAO_UIPMC_Protocol_Factory (void)
  :  TAO_Protocol_Factory (IOP::TAG_UIPMC),
     major_ (TAO_DEF_GIOP_MAJOR),
     minor_ (TAO_DEF_GIOP_MINOR),
     listen_on_all_(false)
{
}

TAO_UIPMC_Protocol_Factory::~TAO_UIPMC_Protocol_Factory (void)
{
}

int
TAO_UIPMC_Protocol_Factory::match_prefix (const ACE_CString &prefix)
{
  // Check for the proper prefix for this protocol.
  return (ACE_OS::strcasecmp (prefix.c_str (), ::the_prefix) == 0);
}

const char *
TAO_UIPMC_Protocol_Factory::prefix (void) const
{
  return ::the_prefix;
}

char
TAO_UIPMC_Protocol_Factory::options_delimiter (void) const
{
  return '/';
}

TAO_Acceptor *
TAO_UIPMC_Protocol_Factory::make_acceptor (void)
{
  TAO_Acceptor *acceptor = 0;
  ACE_NEW_RETURN (acceptor,
                  TAO_UIPMC_Acceptor (this->listen_on_all_),
                  0);

  return acceptor;
}

int
TAO_UIPMC_Protocol_Factory::init (int argc,
                                  ACE_TCHAR* argv [])
{
  for (int curarg = 0; curarg < argc; ++curarg)
    {
      // This option lets you override the default
      if (ACE_OS::strcasecmp (argv[curarg],
                              ACE_TEXT ("-ORBListenOnAll")) == 0)
        {
          ++curarg;
          if (curarg < argc)
            {
              if (curarg < argc)
                this->listen_on_all_ = (bool) ACE_OS::atoi (argv[curarg]);
            }
        }
      else
        {
          ORBSVCS_DEBUG ((LM_DEBUG,
                      ACE_TEXT ("TAO_UIPMC_Protocol_Factory::init - ")
                      ACE_TEXT ("ignoring unknown option <%s>\n"),
                      argv[curarg]));
        }
    }

  return 0;
}

TAO_Connector *
TAO_UIPMC_Protocol_Factory::make_connector (void)
{
  // This is done only once when the library is loaded and
  // only on the client side.
  ACE_Utils::UUID_GENERATOR::instance ()->init ();

  TAO_Connector *connector = 0;
  ACE_NEW_RETURN (connector,
                  TAO_UIPMC_Connector,
                  0);
  return connector;
}

int
TAO_UIPMC_Protocol_Factory::requires_explicit_endpoint (void) const
{
  // A multicast endpoint can't be picked automatically in the
  // pluggable protocol framework.  It must be determined from
  // the UIPMC profile that has the group reference.  This information
  // is either specified by the user or generated by the
  // multicast group manager or other UIPMC profile generation
  // interface.
  return 1;
}

TAO_END_VERSIONED_NAMESPACE_DECL

ACE_STATIC_SVC_DEFINE (TAO_UIPMC_Protocol_Factory,
                       ACE_TEXT ("UIPMC_Factory"),
                       ACE_SVC_OBJ_T,
                       &ACE_SVC_NAME (TAO_UIPMC_Protocol_Factory),
                       ACE_Service_Type::DELETE_THIS |
                       ACE_Service_Type::DELETE_OBJ,
                       0)

ACE_FACTORY_DEFINE (TAO_PortableGroup, TAO_UIPMC_Protocol_Factory)

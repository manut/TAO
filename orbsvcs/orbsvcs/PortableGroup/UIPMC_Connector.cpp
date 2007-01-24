// $Id$

#include "orbsvcs/PortableGroup/UIPMC_Profile.h"
#include "orbsvcs/PortableGroup/UIPMC_Connector.h"

#include "tao/debug.h"
#include "tao/ORB_Core.h"
#include "tao/Environment.h"
#include "tao/Base_Transport_Property.h"
#include "tao/Protocols_Hooks.h"

#include "ace/Connector.h"
#include "ace/OS_NS_strings.h"

ACE_RCSID (PortableGroup,
           UIPMC_Connector, "$Id$")

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_UIPMC_Connector::TAO_UIPMC_Connector (CORBA::Boolean)
  : TAO_Connector (IOP::TAG_UIPMC)
{
}

TAO_UIPMC_Connector::~TAO_UIPMC_Connector (void)
{
}

int
TAO_UIPMC_Connector::open (TAO_ORB_Core *orb_core)
{
  this->orb_core (orb_core);

  // For the sake of uniformity do
  if (this->create_connect_strategy () == -1)
    return -1;

  // @@ Michael: We do not use traditional connection management.

  return 0;
}

int
TAO_UIPMC_Connector::close (void)
{
  SvcHandlerIterator iter (svc_handler_table_);

  while (!iter.done ())
    {
      (*iter).int_id_->remove_reference ();
      iter++;
    }

  return 0;
}

int
TAO_UIPMC_Connector::set_validate_endpoint (TAO_Endpoint *endpoint)
{
  if (endpoint->tag () != IOP::TAG_UIPMC)
    return -1;

  TAO_UIPMC_Endpoint *uipmc_endpoint =
    dynamic_cast<TAO_UIPMC_Endpoint *> (endpoint );

  if (uipmc_endpoint == 0)
    return -1;

  const ACE_INET_Addr &remote_address =
    uipmc_endpoint->object_addr ();

  // Verify that the remote ACE_INET_Addr was initialized properly.
  // Failure can occur if hostname lookup failed when initializing the
  // remote ACE_INET_Addr.
  if (remote_address.get_type () != AF_INET)
    {
      if (TAO_debug_level > 0)
        {
          ACE_DEBUG ((LM_DEBUG,
                      ACE_TEXT ("TAO (%P|%t) UIPMC connection failed.\n")
                      ACE_TEXT ("TAO (%P|%t) This is most likely ")
                      ACE_TEXT ("due to a hostname lookup ")
                      ACE_TEXT ("failure.\n")));
        }

      return -1;
    }

  return 0;
}

TAO_Transport *
TAO_UIPMC_Connector::make_connection (TAO::Profile_Transport_Resolver *,
                                      TAO_Transport_Descriptor_Interface &desc,
                                      ACE_Time_Value *)
{
  TAO_UIPMC_Endpoint *uipmc_endpoint =
    dynamic_cast<TAO_UIPMC_Endpoint *> (desc.endpoint ());

  if (uipmc_endpoint == 0)
    return 0;

  const ACE_INET_Addr &remote_address =
    uipmc_endpoint->object_addr ();

  TAO_UIPMC_Connection_Handler *svc_handler = 0;

  if (this->svc_handler_table_.find (remote_address, svc_handler) == -1)
    {
      TAO_UIPMC_Connection_Handler *svc_handler_i = 0;
      ACE_NEW_RETURN (svc_handler_i,
                      TAO_UIPMC_Connection_Handler (this->orb_core ()),
                      0);

      svc_handler_i->local_addr (ACE_sap_any_cast (ACE_INET_Addr &));
      svc_handler_i->addr (remote_address);

      svc_handler_i->open (0);

      svc_handler_table_.bind (remote_address,
                               svc_handler_i);
      svc_handler = svc_handler_i;

      if (TAO_debug_level > 2)
        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("(%P|%t) UIPMC_Connector::make_connection, ")
                    ACE_TEXT ("new connection on HANDLE %d\n"),
                    svc_handler->get_handle ()));
   }

  // @@ Michael: We do not use traditional connection management.
  svc_handler->add_reference ();

  return svc_handler->transport ();
}


TAO_Profile *
TAO_UIPMC_Connector::create_profile (TAO_InputCDR& cdr)
{
  TAO_Profile *pfile;
  ACE_NEW_RETURN (pfile,
                  TAO_UIPMC_Profile (this->orb_core ()),
                  0);

  int r = pfile->decode (cdr);
  if (r == -1)
    {
      pfile->_decr_refcnt ();
      pfile = 0;
    }

  return pfile;
}

TAO_Profile *
TAO_UIPMC_Connector::make_profile (void)
{
  // The endpoint should be of the form:
  //    N.n@host:port/object_key
  // or:
  //    host:port/object_key

  TAO_Profile *profile = 0;
  ACE_NEW_THROW_EX (profile,
                    TAO_UIPMC_Profile (this->orb_core ()),
                    CORBA::NO_MEMORY (
                      CORBA::SystemException::_tao_minor_code (
                        TAO::VMCID,
                        ENOMEM),
                      CORBA::COMPLETED_NO));

  return profile;
}

int
TAO_UIPMC_Connector::check_prefix (const char *endpoint)
{
  // Check for a valid string
  if (!endpoint || !*endpoint)
    return -1;  // Failure

  static const char protocol[] = "miop";
  static size_t const len = sizeof (protocol) - 1;

  size_t const slot = ACE_OS::strchr (endpoint, ':') - endpoint;

  // Check for the proper prefix in the IOR.  If the proper prefix
  // isn't in the IOR then it is not an IOR we can use.
  if (slot == len
      && ACE_OS::strncasecmp (endpoint, protocol, len) == 0)
    return 0;

  return -1;
  // Failure: not a MIOP IOR
  // DO NOT throw an exception here.
}

char
TAO_UIPMC_Connector::object_key_delimiter (void) const
{
  return TAO_UIPMC_Profile::object_key_delimiter_;
}

int
TAO_UIPMC_Connector::cancel_svc_handler (
  TAO_Connection_Handler * /* svc_handler */)
{
  // Noop
  return 0;
}

TAO_END_VERSIONED_NAMESPACE_DECL


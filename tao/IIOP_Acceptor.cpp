// This may look like C, but it's really -*- C++ -*-
// $Id$

#include "tao/IIOP_Acceptor.h"
#include "tao/IIOP_Profile.h"
#include "tao/MProfile.h"
#include "tao/ORB_Core.h"
#include "tao/Server_Strategy_Factory.h"
#include "tao/debug.h"

#include "ace/Auto_Ptr.h"

#if !defined(__ACE_INLINE__)
#include "tao/IIOP_Acceptor.i"
#endif /* __ACE_INLINE__ */

ACE_RCSID(tao, IIOP_Acceptor, "$Id$")

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class ACE_Acceptor<TAO_IIOP_Server_Connection_Handler, ACE_SOCK_ACCEPTOR>;
template class ACE_Strategy_Acceptor<TAO_IIOP_Server_Connection_Handler, ACE_SOCK_ACCEPTOR>;
template class ACE_Accept_Strategy<TAO_IIOP_Server_Connection_Handler, ACE_SOCK_ACCEPTOR>;
template class ACE_Creation_Strategy<TAO_IIOP_Server_Connection_Handler>;
template class ACE_Concurrency_Strategy<TAO_IIOP_Server_Connection_Handler>;
template class ACE_Scheduling_Strategy<TAO_IIOP_Server_Connection_Handler>;
template class TAO_Creation_Strategy<TAO_IIOP_Server_Connection_Handler>;
template class TAO_Concurrency_Strategy<TAO_IIOP_Server_Connection_Handler>;
template class TAO_Accept_Strategy<TAO_IIOP_Server_Connection_Handler, ACE_SOCK_ACCEPTOR>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#pragma instantiate ACE_Acceptor<TAO_IIOP_Server_Connection_Handler, ACE_SOCK_ACCEPTOR>
#pragma instantiate ACE_Strategy_Acceptor<TAO_IIOP_Server_Connection_Handler, ACE_SOCK_ACCEPTOR>
#pragma instantiate ACE_Accept_Strategy<TAO_IIOP_Server_Connection_Handler, ACE_SOCK_ACCEPTOR>
#pragma instantiate ACE_Creation_Strategy<TAO_IIOP_Server_Connection_Handler>
#pragma instantiate ACE_Concurrency_Strategy<TAO_IIOP_Server_Connection_Handler>
#pragma instantiate ACE_Scheduling_Strategy<TAO_IIOP_Server_Connection_Handler>
#pragma instantiate TAO_Creation_Strategy<TAO_IIOP_Server_Connection_Handler>
#pragma instantiate TAO_Concurrency_Strategy<TAO_IIOP_Server_Connection_Handler>
#pragma instantiate TAO_Accept_Strategy<TAO_IIOP_Server_Connection_Handler, ACE_SOCK_ACCEPTOR>

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

TAO_IIOP_Acceptor::TAO_IIOP_Acceptor (CORBA::Boolean flag)
  : TAO_Acceptor (TAO_TAG_IIOP_PROFILE),
    addrs_ (0),
    hosts_ (0),
    num_hosts_ (0),
    version_ (TAO_DEF_GIOP_MAJOR, TAO_DEF_GIOP_MINOR),
    orb_core_ (0),
    base_acceptor_ (),
    creation_strategy_ (0),
    concurrency_strategy_ (0),
    accept_strategy_ (0),
    lite_flag_ (flag)
{
}

TAO_IIOP_Acceptor::~TAO_IIOP_Acceptor (void)
{
  delete this->creation_strategy_;
  delete this->concurrency_strategy_;
  delete this->accept_strategy_;

  delete [] this->addrs_;
  delete [] this->hosts_;
}

// TODO =
//    2) For V1.[1,2] there are tagged components

int
TAO_IIOP_Acceptor::create_mprofile (const TAO_ObjectKey &object_key,
                                    TAO_MProfile &mprofile)
{
  // Adding this->num_hosts_ to the TAO_MProfile.
  int count = mprofile.profile_count ();
  if ((mprofile.size () - count) < this->num_hosts_
      && mprofile.grow (count + this->num_hosts_) == -1)
    return -1;

  for (size_t i = 0; i < this->num_hosts_; ++i)
    {
      TAO_IIOP_Profile *pfile = 0;
      ACE_NEW_RETURN (pfile,
                      TAO_IIOP_Profile (this->hosts_[i].c_str (),
                                        this->addrs_[i].get_port_number (),
                                        object_key,
                                        this->addrs_[i],
                                        this->version_,
                                        this->orb_core_),
                      -1);

      if (mprofile.give_profile (pfile) == -1)
        {
          pfile->_decr_refcnt ();
          pfile = 0;
          return -1;
        }

      if (this->orb_core_->orb_params ()->std_profile_components () == 0)
        continue;

      pfile->tagged_components ().set_orb_type (TAO_ORB_TYPE);

      CONV_FRAME::CodeSetComponentInfo code_set_info;
      code_set_info.ForCharData.native_code_set  =
        TAO_DEFAULT_CHAR_CODESET_ID;
      code_set_info.ForWcharData.native_code_set =
        TAO_DEFAULT_WCHAR_CODESET_ID;
      pfile->tagged_components ().set_code_sets (code_set_info);

      pfile->tagged_components ().set_tao_priority (this->priority ());
    }

  return 0;
}

int
TAO_IIOP_Acceptor::is_collocated (const TAO_Profile *pfile)
{
  const TAO_IIOP_Profile *profile =
    ACE_dynamic_cast (const TAO_IIOP_Profile *,
                      pfile);

  for (size_t i = 0; i < this->num_hosts_; ++i)
    {
      // compare the port and sin_addr (numeric host address)
      if (profile->object_addr () == this->addrs_[i])
        return 1;  // Collocated
    }

  return 0;  // Not collocated
}

int
TAO_IIOP_Acceptor::close (void)
{
  return this->base_acceptor_.close ();
}

int
TAO_IIOP_Acceptor::open (TAO_ORB_Core *orb_core,
                         int major,
                         int minor,
                         const char *address,
                         const char *options)
{
  if (this->hosts_ != 0)
    {
      // The hostname cache has already been set!
      // This is bad mojo, i.e. an internal TAO error.
      ACE_ERROR_RETURN ((LM_ERROR,
                         ASYS_TEXT ("TAO (%P|%t) ")
                         ASYS_TEXT ("IIOP_Acceptor::open - "),
                         ASYS_TEXT ("hostname already set\n\n")),
                        -1);
    }

  if (address == 0)
    return -1;

  if (major >=0 && minor >= 0)
    this->version_.set_version (ACE_static_cast (CORBA::Octet,
                                                 major),
                                ACE_static_cast (CORBA::Octet,
                                                 minor));
  // Parse options
  if (this->parse_options (options) == -1)
    return -1;

  ACE_INET_Addr addr;

  if (ACE_OS::strchr (address, ':') == address)
    {
      // The address is a port number or port name.  No hostname was
      // specified.  The hostname for each network interface and the
      // fully qualified domain name must be obtained.

      // Check for multiple network interfaces.
      if (this->probe_interfaces (orb_core) == -1)
        return -1;

      // First convert the port into a usable form.
      if (addr.set (address + sizeof (':')) != 0)
        return -1;

      // Now reset the port and set the host.
      if (addr.set (addr.get_port_number (),
                    ACE_static_cast (ACE_UINT32, INADDR_ANY),
                    1) != 0)
        return -1;
      else
        return this->open_i (orb_core, addr);
    }
  else if (ACE_OS::strchr (address, ':') == 0)
    {
      // The address is a hostname.  No port was specified, so assume
      // port zero (port will be chosen for us).
      if (addr.set ((unsigned short) 0, address) != 0)
        return -1;
    }
  else if (addr.set (address) != 0)
    // Host and port were specified.
    return -1;


  this->num_hosts_ = 1;  // Only one hostname to store

  ACE_NEW_RETURN (this->addrs_,
                  ACE_INET_Addr[this->num_hosts_],
                  -1);

  ACE_NEW_RETURN (this->hosts_,
                  ACE_CString[this->num_hosts_],
                  -1);

  if (this->hostname (orb_core,
                      addr,
                      this->hosts_[0]) != 0)
    return -1;

  // Copy the addr.  The port is (re)set in
  // TAO_IIOP_Acceptor::open_i().
  if (this->addrs_[0].set (addr) != 0)
    return -1;

  return this->open_i (orb_core, addr);
}

int
TAO_IIOP_Acceptor::open_default (TAO_ORB_Core *orb_core,
                                 const char *options)
{
  if (this->hosts_ != 0)
    {
      // The hostname cache has already been set!
      // This is bad mojo, i.e. an internal TAO error.
      ACE_ERROR_RETURN ((LM_ERROR,
                         ASYS_TEXT ("TAO (%P|%t) ")
                         ASYS_TEXT ("IIOP_Acceptor::open_default - "),
                         ASYS_TEXT ("hostname already set\n\n")),
                        -1);
    }

  // Parse options
  if (this->parse_options (options) == -1)
    return -1;

  // Check for multiple network interfaces.
  if (this->probe_interfaces (orb_core) == -1)
    return -1;

  // Now that each network interface's hostname has been cached, open
  // an endpoint on each network interface using the INADDR_ANY
  // address.
  ACE_INET_Addr addr;

  if (addr.set (ACE_static_cast(u_short, 0),
                ACE_static_cast(ACE_UINT32, INADDR_ANY),
                1) != 0)
    return -1;

  return this->open_i (orb_core,
                       addr);
}

int
TAO_IIOP_Acceptor::open_i (TAO_ORB_Core* orb_core,
                           const ACE_INET_Addr& addr)
{
  this->orb_core_ = orb_core;

  ACE_NEW_RETURN (this->creation_strategy_,
                  TAO_IIOP_CREATION_STRATEGY (this->orb_core_,
                                              this->lite_flag_),
                  -1);

  ACE_NEW_RETURN (this->concurrency_strategy_,
                  TAO_IIOP_CONCURRENCY_STRATEGY (this->orb_core_),
                  -1);

  ACE_NEW_RETURN (this->accept_strategy_,
                  TAO_IIOP_ACCEPT_STRATEGY (this->orb_core_),
                  -1);

  if (this->base_acceptor_.open (addr,
                                 this->orb_core_->reactor (this),
                                 this->creation_strategy_,
                                 this->accept_strategy_,
                                 this->concurrency_strategy_) == -1)
    {
      if (TAO_debug_level > 0)
        ACE_DEBUG ((LM_DEBUG,
                    ASYS_TEXT ("\n\nTAO (%P|%t) IIOP_Acceptor::open_i ")
                    ASYS_TEXT ("- %p\n\n"),
                    ASYS_TEXT ("cannot open acceptor")));
      return -1;
    }

  ACE_INET_Addr address;

  // We do this make sure the port number the endpoint is listening on
  // gets set in the addr.
  if (this->base_acceptor_.acceptor ().get_local_addr (address) != 0)
    {
      // @@ Should this be a catastrophic error???
      if (TAO_debug_level > 0)
        ACE_DEBUG ((LM_DEBUG,
                    ASYS_TEXT ("\n\nTAO (%P|%t) IIOP_Acceptor::open_i ")
                    ASYS_TEXT ("- %p\n\n"),
                    ASYS_TEXT ("cannot get local addr")));
      return -1;
    }

  // Set the port for each addr.  If there is more than one network
  // interface then the endpoint created on each interface will be on
  // the same port.  This is how a wildcard socket bind() is supposed
  // to work.
  u_short port = address.get_port_number ();
  for (size_t j = 0; j < this->num_hosts_; ++j)
    this->addrs_[j].set_port_number (port, 1);

  if (TAO_debug_level > 5)
    {
      for (size_t i = 0; i < this->num_hosts_; ++i)
        {
          ACE_DEBUG ((LM_DEBUG,
                      ASYS_TEXT ("\nTAO (%P|%t) IIOP_Acceptor::open_i - ")
                      ASYS_TEXT ("listening on: <%s:%u>\n"),
                      this->hosts_[i].c_str (),
                      this->addrs_[i].get_port_number ()));
        }
    }

  return 0;
}

int
TAO_IIOP_Acceptor::hostname (TAO_ORB_Core *orb_core,
                             ACE_INET_Addr &addr,
                             ACE_CString &host)
{
  if (orb_core->orb_params ()->use_dotted_decimal_addresses ())
    {
      const char *tmp = addr.get_host_addr ();
      if (tmp == 0)
        {
          if (TAO_debug_level > 0)
            ACE_DEBUG ((LM_DEBUG,
                        ASYS_TEXT ("\n\nTAO (%P|%t) ")
                        ASYS_TEXT ("IIOP_Acceptor::hostname ")
                        ASYS_TEXT ("- %p\n\n"),
                        ASYS_TEXT ("cannot cache hostname")));
          return -1;
        }

      host = tmp;
    }
  else
    {
      char tmp_host[MAXHOSTNAMELEN + 1];
      if (addr.get_host_name (tmp_host,
                              sizeof (tmp_host)) != 0)
        {
          if (TAO_debug_level > 0)
            ACE_DEBUG ((LM_DEBUG,
                        ASYS_TEXT ("\n\nTAO (%P|%t) ")
                        ASYS_TEXT ("IIOP_Acceptor::hostname ")
                        ASYS_TEXT ("- %p\n\n"),
                        ASYS_TEXT ("cannot cache hostname")));
          return -1;
        }

      host = tmp_host;
    }

  return 0;
}

int
TAO_IIOP_Acceptor::probe_interfaces (TAO_ORB_Core *orb_core)
{
  // Extract the hostname for each network interface, and then cache
  // it.  The hostnames will then be used when creating a
  // TAO_IIOP_Profile for each endpoint setup on the probed
  // network interfaces.
  ACE_INET_Addr *if_addrs = 0;
  size_t if_cnt = 0;

  if (ACE::get_ip_interfaces (if_cnt,
                              if_addrs) != 0
      && errno != ENOTSUP)
    {
      // In the case where errno == ENOTSUP, if_cnt and if_addrs will
      // not be modified, and will each remain equal to zero.  This
      // causes the default interface to be used.
      return -1;
    }

  if (if_cnt == 0 || if_addrs == 0)
    {
      if (TAO_debug_level > 0)
        {
          ACE_DEBUG ((LM_WARNING,
                      ASYS_TEXT ("TAO (%P|%t) Unable to probe network ")
                      ASYS_TEXT ("interfaces.  Using default.")));
        }

      if_cnt = 1; // Force the network interface count to be one.
      delete [] if_addrs;
      ACE_NEW_RETURN (if_addrs,
                      ACE_INET_Addr[if_cnt],
                      -1);
    }

  // Scan for the loopback interface since it shouldn't be included in
  // the list of cached hostnames unless it is the only interface.
  size_t lo_cnt = 0;  // Loopback interface count
  for (size_t j = 0; j < if_cnt; ++j)
    if (if_addrs[j].get_ip_address () == INADDR_LOOPBACK)
      lo_cnt++;

  // The instantiation for this template is in
  // tao/IIOP_Connector.cpp.
  ACE_Auto_Basic_Array_Ptr<ACE_INET_Addr> safe_if_addrs (if_addrs);

  // If the loopback interface is the only interface then include it
  // in the list of interfaces to query for a hostname, otherwise
  // exclude it from the list.
  if (if_cnt == lo_cnt)
    this->num_hosts_ = if_cnt;
  else
    this->num_hosts_ = if_cnt - lo_cnt;

  ACE_NEW_RETURN (this->addrs_,
                  ACE_INET_Addr[this->num_hosts_],
                  -1);

  ACE_NEW_RETURN (this->hosts_,
                  ACE_CString[this->num_hosts_],
                  -1);

  // The number of hosts/interfaces we want to cache may not be the
  // same as the number of detected interfaces so keep a separate
  // count.
  size_t host_cnt = 0;

  for (size_t i = 0; i < if_cnt; ++i)
    {
      // Ignore any loopback interface if there are other
      // non-loopback interfaces.
      if (if_cnt != lo_cnt &&
          if_addrs[i].get_ip_address() == INADDR_LOOPBACK)
        continue;

      if (this->hostname (orb_core,
                          if_addrs[i],
                          this->hosts_[host_cnt]) != 0)
        return -1;

      // Copy the addr.  The port is (re)set in
      // TAO_IIOP_Acceptor::open_i().
      if (this->addrs_[host_cnt].set (if_addrs[i]) != 0)
        return -1;

      host_cnt++;
    }

  return 0;
}

CORBA::ULong
TAO_IIOP_Acceptor::endpoint_count (void)
{
  return this->num_hosts_;
}

int
TAO_IIOP_Acceptor::parse_options (const char *str)
{
  if (str == 0)
    return 0;  // No options to parse.  Not a problem.

  // Use an option format similar to the one used for CGI scripts in
  // HTTP URLs.
  // e.g.:  option1=foo&option2=bar

  ACE_CString options (str);

  size_t len = options.length ();

  const char option_delimiter = '&';

  // Count the number of options.

  CORBA::ULong option_count = 1;
  // Number of endpoints in the string  (initialized to 1).

  // Only check for endpoints after the protocol specification and
  // before the object key.
  for (size_t i = 0; i < len; ++i)
    if (options[i] == option_delimiter)
      option_count++;

  // The idea behind the following loop is to split the options into
  // (option, name) pairs.
  // For example,
  //    `option1=foo&option2=bar'
  // will be parsed into:
  //    `option1=foo'
  //    `option2=bar'

  int begin = 0;
  int end = -1;

  for (CORBA::ULong j = 0; j < option_count; ++j)
    {
      begin += end + 1;

      if (j < option_count - 1)
        end = options.find (option_delimiter, begin);
      else
        end = len - begin;  // Handle last endpoint differently

      if (end == begin)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ASYS_TEXT ("TAO (%P|%t) Zero length IIOP option.\n")),
                          -1);
      else if (end != ACE_CString::npos)
        {
          ACE_CString opt = options.substring (begin, end);

          int slot = opt.find ("=");

          if (slot == ACE_static_cast (int, len - 1)
              || slot == ACE_CString::npos)
            ACE_ERROR_RETURN ((LM_ERROR,
                               ASYS_TEXT ("TAO (%P|%t) IIOP option <%s> is ")
                               ASYS_TEXT ("missing a value.\n"),
                               opt.c_str ()),
                              -1);

          ACE_CString name = opt.substring (0, slot);
          ACE_CString value = opt.substring (slot + 1);

          if (name.length () == 0)
            ACE_ERROR_RETURN ((LM_ERROR,
                               ASYS_TEXT ("TAO (%P|%t) Zero length IIOP ")
                               ASYS_TEXT ("option name.\n")),
                              -1);

          if (name == "priority")
            {
              CORBA::Short corba_priority =
                ACE_static_cast (CORBA::Short,
                                 ACE_OS::atoi (value.c_str ()));

              if (corba_priority >= 0
                  /* && corba_priority < 32768 */)
                // priority_ and corba_priority will always be less
                // than 32768 since CORBA::Short is a signed 16 bit
                // integer.
                this->priority_ = corba_priority;
              else
                ACE_ERROR_RETURN ((LM_ERROR,
                                   ASYS_TEXT ("TAO (%P|%t) Invalid IIOP endpoint ")
                                   ASYS_TEXT ("priority: <%s>\n"),
                                   value.c_str ()),
                                  -1);
            }
          else
            ACE_ERROR_RETURN ((LM_ERROR,
                               ASYS_TEXT ("TAO (%P|%t) Invalid IIOP option: <%s>\n"),
                               name.c_str ()),
                              -1);
        }
    }
  return 0;
}

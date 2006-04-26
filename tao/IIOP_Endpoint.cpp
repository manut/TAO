/*
 * Add all include files within the following
 * two markers.
 */
//@@ TAO_ENDPOINT_SPL_COPY_HOOK_START

#include "tao/IIOP_Endpoint.h"

#if defined (TAO_HAS_IIOP) && (TAO_HAS_IIOP != 0)

#include "tao/IOP_IORC.h"
#include "tao/debug.h"
#include "tao/ORB_Core.h"

#include "ace/Log_Msg.h"
#include "ace/Guard_T.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_strings.h"

ACE_RCSID (tao,
           IIOP_Endpoint,
           "$Id$")

#if !defined (__ACE_INLINE__)
# include "tao/IIOP_Endpoint.i"
#endif /* __ACE_INLINE__ */

#include "ace/OS_NS_stdio.h"
#include "ace/os_include/os_netdb.h"

#include "ace/Vector_T.h"
#include "ace/ACE.h"
#include "ace/INET_Addr.h"
#include "ace/Sock_Connect.h"

//@@ TAO_ENDPOINT_SPL_COPY_HOOK_END

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

//@@ TAO_ENDPOINT_SPL_COPY_HOOK_START
TAO_IIOP_Endpoint::TAO_IIOP_Endpoint (const ACE_INET_Addr &addr,
                                      int use_dotted_decimal_addresses)
  : TAO_Endpoint (IOP::TAG_INTERNET_IOP)
  , host_ ()
  , port_ (683) // default port (IANA assigned)
#if defined (ACE_HAS_IPV6)
  , is_ipv6_decimal_ (false)
#endif /* ACE_HAS_IPV6 */
  , is_encodable_ (true)
  , object_addr_set_ (false)
  , object_addr_ (addr)
  , preferred_path_ ()
  , next_ (0)
{
  this->set (addr, use_dotted_decimal_addresses);
}

TAO_IIOP_Endpoint::TAO_IIOP_Endpoint (const char *host,
                                      CORBA::UShort port,
                                      const ACE_INET_Addr &addr,
                                      CORBA::Short priority)
  : TAO_Endpoint (IOP::TAG_INTERNET_IOP, priority)
  , host_ ()
  , port_ (port)
#if defined (ACE_HAS_IPV6)
  , is_ipv6_decimal_ (false)
#endif /* ACE_HAS_IPV6 */
  , is_encodable_ (true)
  , object_addr_set_ (false)
  , object_addr_ (addr)
  , preferred_path_ ()
  , next_ (0)
{
  this->host(host); // With IPv6 performs check for decimal address
}

TAO_IIOP_Endpoint::TAO_IIOP_Endpoint (void)
  : TAO_Endpoint (IOP::TAG_INTERNET_IOP)
  , host_ ()
  , port_ (683)  // default port (IANA assigned)
#if defined (ACE_HAS_IPV6)
  , is_ipv6_decimal_ (false)
#endif /* ACE_HAS_IPV6 */
  , is_encodable_ (true)
  , object_addr_set_ (false)
  , object_addr_ ()
  , preferred_path_ ()
  , next_ (0)
{
}

TAO_IIOP_Endpoint::TAO_IIOP_Endpoint (const char *host,
                                      CORBA::UShort port,
                                      CORBA::Short priority)
  : TAO_Endpoint (IOP::TAG_INTERNET_IOP, priority)
  , host_ ()
  , port_ (port)
#if defined (ACE_HAS_IPV6)
  , is_ipv6_decimal_ (false)
#endif /* ACE_HAS_IPV6 */
  , is_encodable_ (true)
  , object_addr_set_ (false)
  , object_addr_ ()
  , preferred_path_ ()
  , next_ (0)
{
  this->host(host); // With IPv6 performs check for decimal address
}
//@@ TAO_ENDPOINT_SPL_COPY_HOOK_END


TAO_IIOP_Endpoint &
TAO_IIOP_Endpoint::operator= (const TAO_IIOP_Endpoint &other)
{
  this->host_ = other.host_;
  this->port_ = other.port_;
#if defined (ACE_HAS_IPV6)
  this->is_ipv6_decimal_ = other.is_ipv6_decimal_;
#endif /* ACE_HAS_IPV6 */
  this->is_encodable_  = other.is_encodable_;
  this->object_addr_set_ = other.object_addr_set_;
  this->object_addr_ = other.object_addr_;
  this->preferred_path_ = other.preferred_path_;
  this->next_ = 0; // do not copy list membership, since we are only cloning the values
  return *this;
}

TAO_IIOP_Endpoint::~TAO_IIOP_Endpoint (void)
{
}

//@@ TAO_ENDPOINT_SPL_COPY_HOOK_START

TAO_IIOP_Endpoint::TAO_IIOP_Endpoint (const TAO_IIOP_Endpoint &rhs)
  : TAO_Endpoint (rhs.tag_, rhs.priority_)
  , host_ (rhs.host_)
  , port_ (rhs.port_)
#if defined (ACE_HAS_IPV6)
  , is_ipv6_decimal_ (rhs.is_ipv6_decimal_)
#endif /* ACE_HAS_IPV6 */
  , is_encodable_ (rhs.is_encodable_)
  , object_addr_set_ (rhs.object_addr_set_)
  , object_addr_ (rhs.object_addr_)
  , preferred_path_  (rhs.preferred_path_)
  , next_ (0)
{
}

int
TAO_IIOP_Endpoint::set (const ACE_INET_Addr &addr,
                        int use_dotted_decimal_addresses)
{
  char tmp_host[MAXHOSTNAMELEN + 1];

#if defined (ACE_HAS_IPV6)
  this->is_ipv6_decimal_ = false; // Reset
#endif /* ACE_HAS_IPV6 */

  if (use_dotted_decimal_addresses
      || addr.get_host_name (tmp_host, sizeof (tmp_host)) != 0)
    {
      if (use_dotted_decimal_addresses == 0 && TAO_debug_level > 5)
        {
          ACE_DEBUG ((LM_DEBUG,
                      ACE_TEXT ("TAO (%P|%t) - IIOP_Endpoint::set, ")
                      ACE_TEXT ("%p\n"),
                      ACE_TEXT ("cannot determine hostname")));
        }

      const char *tmp = addr.get_host_addr ();
      if (tmp == 0)
        {
          if (TAO_debug_level > 0)
            {
              ACE_ERROR ((LM_ERROR,
                          ACE_TEXT ("TAO (%P|%t) - IIOP_Endpoint::set, ")
                          ACE_TEXT ("%p\n"),
                          ACE_TEXT ("cannot determine hostname and hostaddr")));
            }
          return -1;
        }
      else
        {
          this->host_ = tmp;
#if defined (ACE_HAS_IPV6)
          if (addr.get_type () == PF_INET6)
            this->is_ipv6_decimal_ = true;
#endif /* ACE_HAS_IPV6 */
        }
    }
  else
    this->host_ = CORBA::string_dup (tmp_host);

  this->port_ = addr.get_port_number();

  return 0;
}

int
TAO_IIOP_Endpoint::addr_to_string (char *buffer, size_t length)
{
  size_t actual_len =
    ACE_OS::strlen (this->host_.in ()) // chars in host name
    + sizeof (':')                     // delimiter
    + ACE_OS::strlen ("65536")         // max port
    + sizeof ('\0');

#if defined (ACE_HAS_IPV6)
  if (this->is_ipv6_decimal_)
    actual_len += 2; // '[' + ']'
#endif /* ACE_HAS_IPV6 */

  if (length < actual_len)
    return -1;

#if defined (ACE_HAS_IPV6)
  if (this->is_ipv6_decimal_)
    ACE_OS::sprintf (buffer, "[%s]:%d",
                     this->host_.in (), this->port_);
  else
#endif /* ACE_HAS_IPV6 */
  ACE_OS::sprintf (buffer, "%s:%d",
                   this->host_.in (), this->port_);

  return 0;
}

const char *
TAO_IIOP_Endpoint::host (const char *h)
{
  this->host_ = h;
#if defined (ACE_HAS_IPV6)
  if (ACE_OS::strchr (h, ':') != 0)
    this->is_ipv6_decimal_ = true;
#endif /* ACE_HAS_IPV6 */

  return this->host_.in ();
}

TAO_Endpoint *
TAO_IIOP_Endpoint::next (void)
{
  return this->next_;
}

TAO_Endpoint *
TAO_IIOP_Endpoint::duplicate (void)
{
  TAO_IIOP_Endpoint *endpoint = 0;

  // @@ NOTE: Not exception safe..
  ACE_NEW_RETURN (endpoint, TAO_IIOP_Endpoint (*this), 0);

  return endpoint;
}

const ACE_INET_Addr &
TAO_IIOP_Endpoint::object_addr (void) const
{
  // The object_addr_ is initialized here, rather than at IOR decode
  // time for several reasons:
  //   1. A request on the object may never be invoked.
  //   2. The DNS setup may have changed dynamically.
  //   ...etc..

  // Double checked locking optimization.
  if (!this->object_addr_set_)
    {
      ACE_GUARD_RETURN (TAO_SYNCH_MUTEX,
                        guard,
                        this->addr_lookup_lock_,
                        this->object_addr_);

      if (!this->object_addr_set_)
        {
          (void) this->object_addr_i ();
        }
    }

  return this->object_addr_;
}

void
TAO_IIOP_Endpoint::object_addr_i (void) const
{
  // We should have already held the lock

#if defined (ACE_HAS_IPV6)
  bool is_ipv4_decimal_ = false;
  if (!this->is_ipv6_decimal_)
    is_ipv4_decimal_ =
      ACE_OS::strspn (this->host_.in (), ".0123456789") ==
                              ACE_OS::strlen (this->host_.in ());

  // If this is *not* an IPv4 decimal address at first try to
  // resolve the address as an IPv6 address; if that fails
  // (or it's an IPv4 address) and the address is *not* an IPv6
  // decimal address try to resolve it as an IPv4 address.
  if ((is_ipv4_decimal_ ||
        this->object_addr_.set (this->port_,
                                this->host_.in (),
                                1,
                                AF_INET6) == -1) &&
      (this->is_ipv6_decimal_ ||
        this->object_addr_.set (this->port_,
                              this->host_.in (),
                              1,
                              AF_INET) == -1))
#else
  if (this->object_addr_.set (this->port_,
                              this->host_.in ()) == -1)
#endif
    {
      // If this call fails, it most likely due a hostname
      // lookup failure caused by a DNS misconfiguration.  If
      // a request is made to the object at the given host and
      // port, then a CORBA::TRANSIENT() exception should be
      // thrown.

      // Invalidate the ACE_INET_Addr.  This is used as a flag
      // to denote that ACE_INET_Addr initialization failed.
      this->object_addr_.set_type (-1);
    }
  else
    {
      this->object_addr_set_ = true;
    }
}

static ACE_CString find_local(const ACE_Vector<ACE_CString>& local_ips,
                              const ACE_CString& pattern)
{
  for (size_t i = 0; i < local_ips.size(); ++i)
  {
    ACE_CString ret = local_ips[i];
    if (ACE::wild_match(ret.c_str(), pattern.c_str()))
      return ret;
  }
  return "";
}

TAO_IIOP_Endpoint*
TAO_IIOP_Endpoint::add_local_endpoint(TAO_IIOP_Endpoint* ep, const char* local)
{
  TAO_Endpoint* tmp = ep->duplicate();
  ep->next_ = static_cast<TAO_IIOP_Endpoint*>(tmp);
  ep->next_->is_encodable_ = true;
  ep->next_->preferred_path_.host = CORBA::string_dup(local);
  return ep->next_;
}

static void
get_ip_interfaces(ACE_Vector<ACE_CString>& local_ips)
{
  ACE_INET_Addr* tmp = 0;
  size_t cnt = 0;
  int err = ACE::get_ip_interfaces (cnt, tmp);
  if (err != 0)
    return;
#if defined (ACE_HAS_IPV6)
  char buf[64];
#else /* ACE_HAS_IPV6 */
  char buf[32];
#endif /* !ACE_HAS_IPV6 */
  for (size_t i = 0; i < cnt; ++i)
  {
    const char *s_if = tmp[i].get_host_addr(buf, sizeof (buf));
    ACE_ASSERT(s_if != 0);
    ACE_CString tmp(s_if);
    //ssize_t pos = tmp.find(':');
    //if (pos != ACE_CString::npos)
    //  tmp = tmp.substr(0, pos);
    local_ips.push_back(tmp);
  }
  delete[] tmp;
}

// Given a comma separated list of preferred interface directives, which
// are of the form <wild_remote>=<wild_local>, this function will retrieve
// the list of preferred local ip addresses by matching wild_local against
// the list of all local ip interfaces, for any directive where wild_remote
// matches the host from our endpoint.
static void find_preferred_interfaces (const ACE_CString& host,
                                       const ACE_CString& csvPreferred,
                                       ACE_Vector<ACE_CString>& preferred)
{
  ACE_Vector<ACE_CString> local_ips;
  get_ip_interfaces(local_ips);
  if (local_ips.size() == 0)
    return;

  // The outer loop steps through each preferred interface directive
  // and chains a new endpoint if the remote interface matches the
  // current endpoint.
  size_t index = 0;
  while (index < csvPreferred.length())
  {
    ssize_t comma = csvPreferred.find(',', index);
    ssize_t assign = csvPreferred.find('=', index);

    if (assign == ACE_CString::npos)
    {
      assign = csvPreferred.find(':', index);
      if (assign == ACE_CString::npos)
      {
        ACE_ASSERT(assign != ACE_CString::npos);
        return;
      }
    }

    ACE_CString wild_local;
    if (comma == ACE_CString::npos)
      wild_local = csvPreferred.substr(assign + 1);
    else
      wild_local = csvPreferred.substr(assign + 1, comma - assign - 1);
    ACE_CString wild_remote = csvPreferred.substr(index, assign - index);

    index = static_cast<size_t>(comma) + 1;

    // For now, we just try to match against the host literally. In
    // the future it might be worthwhile to resolve some aliases for
    // this->host_ using DNS (and possibly reverse DNS) lookups. Then we
    // could try matching against those too.
    if (ACE::wild_match(host.c_str(), wild_remote.c_str(), false))
    {
      // If it's a match, then it means we need to use a
      // local interface that matches wild_local.
      ACE_CString local = find_local(local_ips, wild_local);
      if (local.length() > 0)
      {
        preferred.push_back(local);
      }
      else
      {
        // There is no matching local interface, so we can skip
        // to the next preferred interface directive.
      }
    }
    else
    {
      // The preferred interface directive is for a different
      // remote endpoint.
    }
    if (comma == ACE_CString::npos)
      break;
  }
}

CORBA::ULong
TAO_IIOP_Endpoint::preferred_interfaces (const char* csv, bool enforce)
{
  ACE_Vector<ACE_CString> preferred;
  find_preferred_interfaces(this->host_.in(), csv, preferred);
  CORBA::ULong count = preferred.size();
  if (count > 0)
  {
    this->is_encodable_ = true;
    this->preferred_path_.host = CORBA::string_dup(preferred[0].c_str());
    TAO_IIOP_Endpoint* ep = this;
    for (size_t i = 1; i < count; ++i)
    {
      ep = add_local_endpoint(ep, preferred[i].c_str());
    }

    // If we're not enforcing the preferred interfaces, then we can just add
    // a new non-preferred endpoint to the end with a default local addr.
    if (! enforce)
    {
      ep = add_local_endpoint(ep, "");
    }
    else
    {
      --count;
    }
  }
  return count;
}

CORBA::Boolean
TAO_IIOP_Endpoint::is_equivalent (const TAO_Endpoint *other_endpoint)
{
  const TAO_IIOP_Endpoint *endpoint =
    dynamic_cast<const TAO_IIOP_Endpoint *> (other_endpoint);

  if (endpoint == 0)
    return 0;

  return (this->port_ == endpoint->port_
          && (ACE_OS::strcmp (this->host (), endpoint->host ()) == 0));
}

CORBA::ULong
TAO_IIOP_Endpoint::hash (void)
{
  if (this->hash_val_ != 0)
    return this->hash_val_;

  {
    ACE_GUARD_RETURN (TAO_SYNCH_MUTEX,
                      guard,
                      this->addr_lookup_lock_,
                      this->hash_val_);
    // .. DCL
    if (this->hash_val_ != 0)
      return this->hash_val_;

    // A few comments about this optimization. The call below will
    // deadlock if the object_addr_set is false. If you don't belive

    if (!this->object_addr_set_)
      {
        // Set the object_addr first
        (void) this->object_addr_i ();
      }

    this->hash_val_ = this->object_addr_.hash ();
  }

  return this->hash_val_;
}

bool
TAO_IIOP_Endpoint::is_preferred_network (void) const
{
  return (this->preferred_path_.host.in () != 0 &&
          this->preferred_path_.host.in ()[0] != 0);
}

const char *
TAO_IIOP_Endpoint::preferred_network (void) const
{
  return this->preferred_path_.host.in ();
}

//@@ TAO_ENDPOINT_SPL_COPY_HOOK_END

TAO_END_VERSIONED_NAMESPACE_DECL

#endif /* TAO_HAS_IIOP && TAO_HAS_IIOP != 0 */

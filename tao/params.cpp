// $Id$

#include "tao/params.h"
#include "tao/orbconf.h"

#if !defined (__ACE_INLINE__)
# include "tao/params.i"
#endif /* __ACE_INLINE__ */

#include "ace/OS_NS_Thread.h"


ACE_RCSID (tao,
           params,
           "$Id$")


TAO_ORB_Parameters::TAO_ORB_Parameters (void)
  : endpoints_map_ (10)
  , mcast_discovery_endpoint_ ()
  , default_init_ref_ (TAO_DEFAULT_INIT_REFERENCE_INITIALIZER)
  , sock_rcvbuf_size_ (ACE_DEFAULT_MAX_SOCKET_BUFSIZ)
  , sock_sndbuf_size_ (ACE_DEFAULT_MAX_SOCKET_BUFSIZ)
  , nodelay_ (1)
  , cdr_memcpy_tradeoff_ (ACE_DEFAULT_CDR_MEMCPY_TRADEOFF)
  , use_lite_protocol_ (0)
  , use_dotted_decimal_addresses_ (0)
  , linger_ (-1)
  , std_profile_components_ (1)
  , ace_sched_policy_ (ACE_SCHED_OTHER)
  , sched_policy_ (THR_SCHED_DEFAULT)
  , scope_policy_ (THR_SCOPE_PROCESS)
  , single_read_optimization_ (1)
  , shared_profile_ (0)
  , pref_network_ ()
  , disable_rt_collocation_resolver_ (false)
  , enforce_preferred_interfaces_ (false)
{
  for (int i = 0; i != TAO_NO_OF_MCAST_SERVICES; ++i)
    {
      this->service_port_[i] = 0;
    }
}

void
TAO_ORB_Parameters::get_endpoint_set (const ACE_CString &lane,
                                      TAO_EndpointSet &endpoint_set)
{
  // Look for the lane in the endpoints map.
  endpoints_map_type::iterator const endpoints =
    this->endpoints_map_.find (lane);

  // If lane is not in the map, <endpoint_set> remains empty
  if (endpoints == this->endpoints_map_.end ())
    return;

  // At this point, the parsing should not fail since they have been
  // parsed successfully before.
  int const result =
    this->parse_and_add_endpoints ((*endpoints).second,
                                   endpoint_set);

  ACE_ASSERT (result == 0);
  ACE_UNUSED_ARG (result);
}

int
TAO_ORB_Parameters::add_endpoints (const ACE_CString &lane,
                                   const ACE_CString &additional_endpoints)
{
  TAO_EndpointSet endpoint_set;

  // Parse the additional endpoints.
  int result =
    this->parse_and_add_endpoints (additional_endpoints,
                                   endpoint_set);

  // Parse failure.
  if (result != 0)
    return result;

  // Look for the lane in the endpoints map.
  //
  // Return reference to endpoints string corresponding to lane
  // string.  If none, a default constructed string is inserted into
  // the map and returned.
  ACE_CString & existing_endpoints = this->endpoints_map_[lane];

  // Create the resulting endpoints string.
  if (existing_endpoints.length () != 0)
    {
      existing_endpoints += ";";
    }

  existing_endpoints += additional_endpoints;

  return 0;
}

int
TAO_ORB_Parameters::parse_and_add_endpoints (const ACE_CString &endpoints,
                                             TAO_EndpointSet &endpoint_set)
{
  // Parse the string into seperate endpoints, where `endpoints' is of
  // the form:
  //
  //    protocol1://V,v@addr1,...,addrN;protocol2://addr1,...,W.w@addrN;...
  //
  // A single endpoint, instead of several, can be added just as well.

  static char const endpoints_delimiter = ';';

  size_t const length = endpoints.length ();

  if (endpoints[0] == endpoints_delimiter ||
      endpoints[length - 1] == endpoints_delimiter)
    {
      return -1;
      // Failure: endpoints string has an empty endpoint at the
      // beginning or the end of the string
      // (e.g. ";uiop://foo;iiop://1.3@bar")
    }

  int status = 0;
  // Return code:  0 = success,  -1 = failure

  if (length > 0)
    {
      int endpoints_count = 1;

      for (size_t j = 0; j != length; ++j)
        {
          if (endpoints[j] == endpoints_delimiter)
            {
              ++endpoints_count;
            }
        }

      int begin = 0;
      int end = endpoints.find (endpoints_delimiter);

      for (int i = 0; i < endpoints_count; ++i)
        {
          if (end == 0)
            {
              // Handle case where two consecutive endpoints `;;'
              // delimiters are found within the endpoints set.
              //
              // Is it enough to just skip over it or should we return an
              // error?
              continue;
            }

          ACE_CString const endpt =
            endpoints.substring (begin, end - begin);
          // The substring call will work even if `end' is equal to
          // ACE_CString::npos since that will just extract the substring
          // from the offset `begin' to the end of the string.

          // Check for a valid URL style endpoint set
          int const check_offset = endpt.find ("://");

          if (check_offset > 0 &&
              check_offset != endpt.npos)
            {
              endpoint_set.enqueue_tail (endpt);
              // Insert endpoint into list
            }
          else
            {
              status = -1;  // Error: invalid URL style endpoint set
            }

          begin = end + 1;
          end = endpoints.find (endpoints_delimiter, begin);
        }
    }
  else
    {
      status = -1;
      // Failure:  Empty string
    }

  return status;
}

bool
TAO_ORB_Parameters::preferred_interfaces (const char *s)
{
  // Validates that s contains one or more comma separated
  // interfaces each consisting of a string with a single
  // assignment separator ('=' or ':')
  // Any other char is legal, although '*' and '?' will be
  // treated as wildcards.
  const char* p = s;
  bool expect_assign = false;
  bool expect_comma = false;
  bool expect_char = true;
  bool expect_wild = true;
  bool found_remote = false;
  while (*p != 0)
  {
    switch (*p)
    {
    case ':':
    case '=':
      if (! expect_assign)
        return false;
      found_remote = true;
      expect_assign = false;
      expect_char = true;
      expect_comma = false;
      expect_wild = true;
      break;
    case ',':
      if (! expect_comma)
        return false;
      found_remote = false;
      expect_assign = false;
      expect_char = true;
      expect_comma = false;
      expect_wild = true;
      break;
    case '*':
    case '?':
      if (! expect_wild)
        return false;
      expect_assign = ! found_remote;
      expect_char = true;
      expect_comma = found_remote;
      expect_wild = false;
      break;
    default:
      if (! expect_char)
        return false;
      expect_assign = ! found_remote;
      expect_char = true;
      expect_comma = found_remote;
      expect_wild = true;
      break;
    }
    ++p;
    }
  if (!expect_comma || expect_assign)
    return false;

  this->pref_network_ = s;

  return true;
}

const char *
TAO_ORB_Parameters::preferred_interfaces (void) const
{
  return this->pref_network_.c_str ();
}

void
TAO_ORB_Parameters::enforce_pref_interfaces (bool p)
{
  this->enforce_preferred_interfaces_ = p;
}

bool
TAO_ORB_Parameters::enforce_pref_interfaces (void) const
{
  return this->enforce_preferred_interfaces_;
}

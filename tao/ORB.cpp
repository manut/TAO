// $Id$

// @@ as with TAO, this has a strong coupling to the Internet ORB
// (IIOP) code.  We should make it know less about that protocol
// component and have a loose table-driven coupling to ORB/protocol
// library components.

#include "tao/ORB.h"

#include "ace/Dynamic_Service.h"
#include "ace/Service_Repository.h"
#include "ace/Object_Manager.h"
#include "ace/SOCK_Dgram_Mcast.h"
#include "ace/Thread_Manager.h"
#include "ace/Read_Buffer.h"

#include "tao/Object.h"
#include "tao/Typecode.h"
#include "tao/InconsistentTypeCodeC.h"
#include "tao/NVList.h"
#include "tao/Stub.h"
#include "tao/IIOP_Profile.h"
#include "tao/DynAny_i.h"
#include "tao/ORB_Core.h"
#include "tao/Server_Strategy_Factory.h"
#include "tao/CDR_Interpreter.h"
#include "tao/debug.h"
#include "tao/TAO_Internal.h"
#include "tao/CDR.h"
#include "tao/Marshal.h"
#include "tao/IOR_LookupTable.h"
#include "tao/GIOP.h"

#if !defined (__ACE_INLINE__)
# include "tao/ORB.i"
#endif /* ! __ACE_INLINE__ */

#include "tao/Timeprobe.h"

ACE_RCSID(tao, ORB, "$Id$")

static const char ior_prefix [] = "IOR:";
static const char iioploc_prefix [] = "iioploc:";
static const char file_prefix[] = "file://";

#if defined (ACE_ENABLE_TIMEPROBES)

static const char *TAO_ORB_Timeprobe_Description[] =
{
  "CORBA_ORB::run - start",
  "CORBA_ORB::run - end",
};

enum
{
  // Timeprobe description table start key
  TAO_CORBA_ORB_RUN_START = 0,
  TAO_CORBA_ORB_RUN_END
};

// Setup Timeprobes
ACE_TIMEPROBE_EVENT_DESCRIPTIONS (TAO_ORB_Timeprobe_Description,
                                  TAO_CORBA_ORB_RUN_START);

#endif /* ACE_ENABLE_TIMEPROBES */

#if !defined (TAO_HAS_MINIMUM_CORBA)

// Typecode stuff for the InconsistentTypeCode exception
static const CORBA::Long _oc_CORBA_ORB_InconsistentTypeCode[] =
{
  TAO_ENCAP_BYTE_ORDER,   // byte order
  47,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x6f6d672e),
  ACE_NTOHL (0x6f72672f),
  ACE_NTOHL (0x434f5242),
  ACE_NTOHL (0x412f4f52),
  ACE_NTOHL (0x422f496e),
  ACE_NTOHL (0x636f6e73),
  ACE_NTOHL (0x69737465),
  ACE_NTOHL (0x6e745479),
  ACE_NTOHL (0x7065436f),
  ACE_NTOHL (0x64653a31),
  ACE_NTOHL (0x2e3000fd), // repository ID =
                          // IDL:omg.org/CORBA/ORB/InconsistentTypeCode:1.0
  21,
  ACE_NTOHL (0x496e636f),
  ACE_NTOHL (0x6e736973),
  ACE_NTOHL (0x74656e74),
  ACE_NTOHL (0x54797065),
  ACE_NTOHL (0x436f6465),
  ACE_NTOHL (0xfdfdfd),   // name = InconsistentTypeCode
  0,                      // member count
};

static CORBA::TypeCode _tc_TAO_tc_CORBA_ORB_InconsistentTypeCode (
    CORBA::tk_except,
    sizeof (_oc_CORBA_ORB_InconsistentTypeCode),
    (char *) &_oc_CORBA_ORB_InconsistentTypeCode,
    0,
    sizeof (CORBA_ORB_InconsistentTypeCode));

// ORB exception typecode initialization.
CORBA::TypeCode_ptr CORBA_ORB::_tc_InconsistentTypeCode =
  &_tc_TAO_tc_CORBA_ORB_InconsistentTypeCode;

#endif /* TAO_HAS_MINIMUM_CORBA */

// = Static initialization.

// Count of the number of ORBs.
int CORBA_ORB::orb_init_count_ = 0;

// Pointer to the "default ORB."
CORBA::ORB_ptr CORBA::instance_ = 0;

CORBA_String_var::CORBA_String_var (char *p)
  : ptr_ (p)
{
  // NOTE: According to the CORBA spec this string must *not* be
  // copied, but it is non-compliant to use it/release it in the
  // calling code.  argument is consumed. p should never be NULL
}

CORBA_String_var::CORBA_String_var (const CORBA_String_var& r)
{
  this->ptr_ = CORBA::string_dup (r.ptr_);
}

CORBA_String_var::~CORBA_String_var (void)
{
  if (this->ptr_ != 0)
    {
      CORBA::string_free (this->ptr_);
      this->ptr_ = 0;
    }
}

CORBA_ORB::InvalidName::InvalidName (void)
{
}

void
CORBA_ORB::InvalidName::_raise (void)
{
  TAO_RAISE(*this);
}

CORBA_ORB::InvalidName*
CORBA_ORB::InvalidName::_narrow (CORBA_Exception *ex)
{
  if (ex->_is_a ("IDL:omg.orb/CORBA/ORB/InvalidName:1.0"))
    return ACE_dynamic_cast (CORBA_ORB::InvalidName*, ex);
  return 0;
}

int
CORBA_ORB::InvalidName::_is_a (const char* interface_id) const
{
  return ((ACE_OS::strcmp (interface_id,
                          "IDL:omg.orb/CORBA/ORB/InvalidName:1.0") ==
           0)
          || CORBA_UserException::_is_a (interface_id));
}

CORBA_ORB::CORBA_ORB (TAO_ORB_Core* orb_core)
  : refcount_ (1),
    open_called_ (0),
    shutdown_lock_ (0),
    should_shutdown_ (0),
    name_service_ (CORBA_Object::_nil ()),
    schedule_service_ (CORBA_Object::_nil ()),
    event_service_ (CORBA_Object::_nil ()),
    trading_service_ (CORBA_Object::_nil ()),
    orb_core_ (orb_core),
    use_omg_ior_format_ (1),
    optimize_collocation_objects_ (1)
{
  leader_follower_info_.leaders_ = 0;
  leader_follower_info_.leader_thread_ID_ =
    ACE_OS::NULL_thread;
  ACE_NEW (this->cond_become_leader_,
           ACE_SYNCH_CONDITION (leader_follower_info_.leader_follower_lock_));
}

CORBA_ORB::~CORBA_ORB (void)
{
  this->orb_core_->fini ();

  ACE_MT (ACE_GUARD (ACE_Recursive_Thread_Mutex, tao_mon, *ACE_Static_Object_Lock::instance ()));

  CORBA_ORB::orb_init_count_--;

  if (CORBA_ORB::orb_init_count_ == 0)
    {
      // free up all the ORB owned Exceptions
      TAO_Exceptions::fini ();

      // free up all the ORB owned TypeCodes
      TAO_TypeCodes::fini ();

      // @@ Note that we shouldn't need to actually delete this
      // instance since it'll be handled by the destruction of the
      // instance via another mechanism.
      CORBA::instance_ = 0;
    }

  delete this->shutdown_lock_;
  this->shutdown_lock_ = 0;

  if (!CORBA::is_nil (this->name_service_))
    CORBA::release (this->name_service_);
  if (!CORBA::is_nil (this->schedule_service_))
    CORBA::release (this->schedule_service_);
  if (!CORBA::is_nil (this->event_service_))
    CORBA::release (this->event_service_);
  if (!CORBA::is_nil (this->trading_service_))
    CORBA::release (this->trading_service_);

  delete this->cond_become_leader_;
}

// Set up listening endpoints.

int
CORBA_ORB::open (void)
{
  // Double check pattern
  if (this->open_called_ == 1)
    return 1;

  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, tao_mon, this->open_lock_, -1);

  if (this->open_called_ == 1)
    return 1;

  this->open_called_ = 1;

  TAO_Server_Strategy_Factory *f = this->orb_core_->server_factory ();

  // @@ For now we simple assume an IIOP handler, in the future
  // @@ this has to be more general
  // @@ Fred: right, this is my idea for this stuff:
  //    Using the Connector Registry try every endpoint listed in the
  //    orb_params(), for each one create a TAO_Acceptor [check the
  //    Pluggable.h file for a description on how to do that],
  //    activate the acceptor with the reactor and insert it in the
  //    Acceptor Registry.
  TAO_IIOP_BASE_ACCEPTOR *iiop_acceptor =
    ACE_dynamic_cast(TAO_IIOP_BASE_ACCEPTOR *,
                     this->orb_core_->acceptor ()->acceptor ());

  // Initialize the endpoint ... or try!

  if (iiop_acceptor->open (this->orb_core_->orb_params ()->addr (),
                           this->orb_core_->reactor(),
                           f->creation_strategy (),
                           f->accept_strategy (),
                           f->concurrency_strategy (),
                           f->scheduling_strategy ()) == -1)
    // Need to return an error somehow!!  Maybe set do_exit?
    return -1;

  // The following step is necessary since the user may have specified
  // a 0 for a port number.  Once we open the acceptor, we can recheck
  // the address and get the accurate port number.
  ACE_INET_Addr new_address;
  if (iiop_acceptor->acceptor ().get_local_addr (new_address) == -1)
    return -1;

  // Reset the address
  this->orb_core_->orb_params ()->addr (new_address);

  iiop_acceptor->acceptor ().enable (ACE_CLOEXEC);
  this->orb_core_->add_to_collocation_table ();

  return 0;
}

void
CORBA_ORB::shutdown (CORBA::Boolean wait_for_completion)
{
  // Set the shutdown flag
  this->should_shutdown (1);

  // Grab the thread manager
  ACE_Thread_Manager *tm = this->orb_core_->thr_mgr ();

  // Try to cancel all the threads in the ORB.
  tm->cancel_all ();

  // Wake up all waiting threads in the reactor.
  this->orb_core_->reactor ()->wakeup_all_threads ();

  // If <wait_for_completion> is set, wait for all threads to exit.
  if (wait_for_completion != 0)
    tm->wait ();

  return;
}

#if !defined (TAO_HAS_MINIMUM_CORBA)

void
CORBA_ORB::create_list (CORBA::Long count,
                        CORBA::NVList_ptr &retval)
{
  assert (CORBA::ULong (count) <= UINT_MAX);

  // create an empty list
  retval = new CORBA::NVList;

  // if count is greater than 0, create a list of NamedValues
  if (count != 0)
    {
      retval->max_ = (CORBA::ULong) count;
      for (CORBA::Long i=0; i < count; i++)
        {
          CORBA::NamedValue_ptr nv = new CORBA::NamedValue;
          retval->values_.enqueue_tail (nv);
        }
    }
}

int
CORBA_ORB::perform_work (const ACE_Time_Value &tv)
{
  ACE_Reactor *r = this->orb_core_->reactor ();

  // Set the owning thread of the Reactor to the one which we're
  // currently in.  This is necessary b/c it's possible that the
  // application is calling us from a thread other than that in which
  // the Reactor's CTOR (which sets the owner) was called.
  r->owner (ACE_Thread::self ());

  ACE_Time_Value tmp_tv (tv);
  return r->handle_events (tmp_tv);
}

CORBA::Boolean
CORBA_ORB::work_pending (void)
{
  // There's ALWAYS work to do ;-)
  return 1;
}

#endif /* TAO_HAS_MINIMUM_CORBA */

int
CORBA_ORB::run (ACE_Time_Value *tv,
                int break_on_timeouts)
{
  ACE_FUNCTION_TIMEPROBE (TAO_CORBA_ORB_RUN_START);

  {
    ACE_Guard<ACE_SYNCH_MUTEX> g (this->orb_core_->leader_follower_lock ());

    while (this->orb_core_->leader_available ())
      {
        // @@ Why do this on every iteration, shouldn't this be done
        // just once?
        if (this->orb_core_->add_follower (this->cond_become_leader_) == -1)
          ACE_ERROR ((LM_ERROR,
                      "(%P|%t) ORB::run: Failed to add a follower thread\n"));
        this->cond_become_leader_->wait ();
      }
    this->orb_core_->set_leader_thread ();
  }

  ACE_Reactor *r = this->orb_core_->reactor ();

  // Set the owning thread of the Reactor to the one which we're
  // currently in.  This is necessary b/c it's possible that the
  // application is calling us from a thread other than that in which
  // the Reactor's CTOR (which sets the owner) was called.
  r->owner (ACE_Thread::self ());

  // This method should only be called by servers, so now we set up
  // for listening!
  if (this->open () == -1)
    return -1;

#if 0
  const int max_iterations = 100;
  int counter = 0;
#endif /* 0 */

  int result = 1;
  // 1 to detect that nothing went wrong

  // Loop "forever" handling client requests.
  while (this->should_shutdown () == 0)
    {
#if 0
   ^   counter++;
      if (counter == max_iterations)
        {
          ACE_TIMEPROBE_PRINT;
          ACE_TIMEPROBE_RESET;
          counter = 0;
        }

      ACE_FUNCTION_TIMEPROBE (TAO_CORBA_ORB_RUN_START);
#endif /* 0 */

      switch (r->handle_events (tv))
        {
        case 0: // Timed out, so we return to caller.
          if (break_on_timeouts)
            result = 0;
          break;
          /* NOTREACHED */
        case -1: // Something else has gone wrong, so return to caller.
          result = -1;
          break;
          /* NOTREACHED */
        default:
          // Some handlers were dispatched, so keep on processing
          // requests until we're told to shutdown .
          break;
          /* NOTREACHED */
        }
      if (result == 0 || result == -1)
        break;
    }

  if (result != -1)
    {
      if (this->orb_core_->unset_leader_wake_up_follower () == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "(%P|%t) ORB::run: Failed to add a follower thread\n"),
                          -1);
      return 0;
      // nothing went wrong
    }
  else
    return result;
}

int
CORBA_ORB::run (ACE_Time_Value &tv)
{
  return this->run (&tv, 1);
}

int
CORBA_ORB::run (ACE_Time_Value *tv)
{
  return this->run (tv, 1);
}

int
CORBA_ORB::run (void)
{
  return this->run (0, 0);
}

CORBA_Object_ptr
CORBA_ORB::resolve_root_poa (const char *adapter_name,
                             TAO_POA_Manager *poa_manager,
                             const TAO_POA_Policies *policies)
{
  CORBA::Environment env;

  return this->orb_core_->root_poa_reference (env,
                                              adapter_name,
                                              poa_manager,
                                              policies);
}

CORBA_Object_ptr
CORBA_ORB::resolve_poa_current (void)
{
  // Return the pointer to this thread's POACurrent.

  CORBA::Environment env;

  TAO_POA_Current *poa_current = this->orb_core_->poa_current ();
  if (poa_current == 0)
    return CORBA_Object::_nil ();

  PortableServer::Current_var result = poa_current->_this (env);
  if (env.exception () != 0)
    return CORBA_Object::_nil ();
  else
    return result._retn ();
}

CORBA_Object_ptr
CORBA_ORB::resolve_commandline_ref (const char *& init_ref)
{

  // @@ Where are the exceptions caught ??
  CORBA::Environment env;

  // Initialize our return ptr.
  CORBA_Object_ptr return_value = CORBA_Object::_nil ();

  // Get the commandline initial reference.
  init_ref = this->orb_core_->orb_params ()->init_ref ();

  // Parse the IOR from the given commandline mapping
  // <ObjectId>=<IOR>.
  const char* ior_location = init_ref + ACE_OS::strcspn (init_ref,"=") + 1;
  char *ior = CORBA::string_dup (ior_location);

  // Convert the given IOR to object. Note the IOR could be of the form
  // IOR: ...    / iiop: ...    / iioploc: ...    / iiopname: ...

  return_value = this->string_to_object (ior, env);

  // check for errors
  if (env.exception () != 0)
    return_value = CORBA_Object::_nil ();

  // @@EXC@@ Use an auto_ptr or a String_var
  CORBA::string_free (ior);

  // @@ Vishal: Why do we duplicate this value?
  return CORBA_Object::_duplicate (return_value);
}


CORBA_Object_ptr
CORBA_ORB::resolve_service (CORBA::String service_name,
			    ACE_Time_Value *timeout)
{
  CORBA::Environment env;
  CORBA_Object_ptr return_value = CORBA_Object::_nil ();

  // First check to see if we've already initialized this.
  if (this->name_service_ != CORBA_Object::_nil ())
    {
      // @@ Someone please double-check this ;-)
      return_value = this->name_service_;
    }
  else
    {
      ACE_CString name_service_ior =
        this->orb_core_->orb_params ()->name_service_ior ();

      // Second, check to see if the user has give us a parameter on
      // the command-line.
      if (name_service_ior.length () == 0)
        // Third, check to see if the user has an environment variable.
        name_service_ior = ACE_OS::getenv ("NameServiceIOR");

      if (name_service_ior.length () != 0)
        {
          this->name_service_ =
            this->string_to_object (name_service_ior.c_str (), env);

          // check for errors
          if (env.exception () != 0)
            this->name_service_ = CORBA_Object::_nil ();
        }
      else
        {
          // First, determine if the port was supplied on the command line
          u_short port =
            this->orb_core_->orb_params ()->name_service_port ();

          if (port == 0)
            {
              // Look for the port among our environment variables.
              const char *port_number =
                ACE_OS::getenv ("NameServicePort");

              if (port_number != 0)
                port = ACE_OS::atoi (port_number);
              else
                port = TAO_DEFAULT_NAME_SERVER_REQUEST_PORT;
            }

          this->name_service_ =
            this->multicast_to_service(service_name,
                                       port,
                                       timeout);
        }
    }

  // Return ior.
  return_value = this->name_service_;
  return CORBA_Object::_duplicate (return_value);
}

CORBA_Object_ptr
CORBA_ORB::resolve_trading_service (ACE_Time_Value *timeout)
{
  CORBA::Environment env;
  CORBA_Object_ptr return_value = CORBA_Object::_nil ();

  // First check to see if we've already initialized this.
  if (this->trading_service_ != CORBA_Object::_nil ())
    {
      // @@ Someone please double-check this ;-)
      return_value = this->trading_service_;
    }
  else
    {
      ACE_CString trading_service_ior =
        this->orb_core_->orb_params ()->trading_service_ior ();

      // Second, check to see if the user has give us a parameter on
      // the command-line.
      if (trading_service_ior.length () == 0)
        // Third, check to see if the user has an environment variable.
        trading_service_ior = ACE_OS::getenv ("TradingServiceIOR");

      if (trading_service_ior.length () != 0)
        {
          this->trading_service_ =
            this->string_to_object (trading_service_ior.c_str (), env);

          // check for errors
          if (env.exception () != 0)
            this->trading_service_ = CORBA_Object::_nil ();
        }
      else
        {
          // First, determine if the port was supplied on the command line
          // @@ FRED: need a generic rep for this!
          u_short port =
            this->orb_core_->orb_params ()->trading_service_port ();

          if (port == 0)
            {
              // Look for the port among our environment variables.
              const char *port_number = ACE_OS::getenv ("TradingServicePort");

              if (port_number != 0)
                port = ACE_OS::atoi (port_number);
              else
                port = TAO_DEFAULT_TRADING_SERVER_REQUEST_PORT;
            }

          this->trading_service_ =
            this->multicast_to_service ("TradingService",
                                        port,
                                        timeout);
        }
    }

  return_value = this->trading_service_;
  return CORBA_Object::_duplicate (return_value);
}

int
CORBA_ORB::multicast_query (char *buf,
			    const char *service_name,
                            u_short port,
                            ACE_Time_Value *timeout)
{
  ACE_INET_Addr my_addr;
  ACE_SOCK_Acceptor acceptor;
  ACE_SOCK_Stream stream;

  // Bind listener to any port and then find out what the port was.
  if (acceptor.open (ACE_Addr::sap_any) == -1
      || acceptor.get_local_addr (my_addr) == -1)
    ACE_ERROR_RETURN ((LM_DEBUG,
		       "acceptor.open () || "
		       "acceptor.get_local_addr () failed"),
		      -1);

  // Send a Multicast with service name and a port no.
  ACE_SOCK_Dgram dgram;

  // This starts out initialized to all zeros!
  ACE_INET_Addr multicast_addr (port,
				ACE_DEFAULT_MULTICAST_ADDR);

  // Open the datagram.
  if (dgram.open (ACE_Addr::sap_any) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
		       "Unable to open the Datagram!\n"),
		      -1);

  // Convert the port that we are listening at to Network Byte Order.
  ACE_UINT16 response_port =
    ACE_HTONS (my_addr.get_port_number ());

  // Length of data to be sent. This is sent as a header.
  CORBA::Short data_len =
    sizeof (ACE_UINT16) + ACE_OS::strlen (service_name);

  // Vector to be sent.
  const int iovcnt = 3;
  iovec iovp[iovcnt];

  // The length of data to be sent.
  iovp[0].iov_base = (char *) &data_len;
  iovp[0].iov_len  = sizeof (CORBA::Short);

  // The port at which we are listening.
  iovp[1].iov_base = (char *) &response_port;
  iovp[1].iov_len  = sizeof (ACE_UINT16);

  // The service name string.
  iovp[2].iov_base = (char *) service_name;
  iovp[2].iov_len  = ACE_OS::strlen (service_name);

  // Send the multicast.
  ssize_t n_bytes = dgram.send (iovp,
				iovcnt,
				multicast_addr);
  if (TAO_debug_level > 0)
    ACE_DEBUG ((LM_DEBUG,
                "\nsent multicast request."));

  // We don't need the Dgram anymore.
  dgram.close ();

  // Check for errors.
  if (n_bytes == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "Error sending IIOP Multicast!\n"),
                      -1);
  else if (TAO_debug_level > 0)
    ACE_DEBUG ((LM_DEBUG,
		"\n%s; Sent multicast."
		"# of bytes sent is %d.\n",
		__FILE__,
		n_bytes));

  // Wait for response until TAO_DEFAULT_SERVICE_RESOLUTION_TIMEOUT.
  ACE_Time_Value tv (timeout == 0
		     ? ACE_Time_Value (TAO_DEFAULT_SERVICE_RESOLUTION_TIMEOUT)
		     : *timeout);

  // Start listening.
  if (acceptor.accept (stream, 0, &tv) == -1)
    if (TAO_debug_level > 0)
      ACE_ERROR_RETURN ((LM_DEBUG,
			 "multicast_query : Unable to accept\n"),
			0);

  // Receive the IOR.
  n_bytes = stream.recv (buf,
                         BUFSIZ,
                         0,
                         timeout);
  // Close socket now.
  stream.close ();

  // Check for errors.
  if (n_bytes == -1)
    {
      if (TAO_debug_level > 0)
	ACE_ERROR_RETURN ((LM_ERROR,
			   "Error reading IIOP multicast response!\n"),
			  -1);
      return -1;
    }

  // Null terminate message.
  buf[n_bytes] = 0;

  if (TAO_debug_level > 0)
    ACE_DEBUG ((LM_DEBUG,
		"%s; Service resolved to ior: <%s>\n",
		__FILE__,
		buf));

  return 0;
}

// @@ This will have to be sanitized of transport specific calls
//    in order to support pluggable protocols!  But, it does use
//    UDP and multicast.  Not all transport protocols may support
//    this, connectionless and multicast. fredk
// @@ FRED: Should define a flag, something like Protocol_Has_Multicast
//    If there is no multicast, then this functionality is not available
//    and we return NULL.

CORBA_Object_ptr
CORBA_ORB::multicast_to_service (const char * service_name,
                                 u_short port,
                                 ACE_Time_Value *timeout)
{
  char buf[BUFSIZ + 1];

  // Use UDP multicast to locate the  service.
  CORBA_Object_ptr return_value =
    CORBA_Object::_nil ();

  if (this->multicast_query (buf,
			     service_name,
			     port,
			     timeout) == 0)
    {
      CORBA::Environment env;

      // Convert IOR to an object reference.
      CORBA_Object_ptr objectified_ior =
	this->string_to_object ((CORBA::String) buf, env);

      // Check for errors.
      if (env.exception () == 0)
        return_value = objectified_ior;
    }

  // Return ior.
  return return_value;
}

CORBA_Object_ptr
CORBA_ORB::resolve_initial_references (CORBA::String name,
                                       CORBA_Environment &TAO_IN_ENV)
{
  return this->resolve_initial_references (name,
                                           0,
                                           TAO_IN_ENV);
}

CORBA_Object_ptr
CORBA_ORB::resolve_initial_references (CORBA::String name,
                                       ACE_Time_Value *timeout,
                                       CORBA_Environment &TAO_IN_ENV)
{
  // Get the table of initial references specified through -ORBInitRef.
  TAO_IOR_LookupTable *table =
    this->orb_core_->orb_params ()->ior_lookup_table ();

  ACE_CString ior;
  ACE_CString object_id ((const char *) name);

  // Resolved Object reference.
  CORBA_Object_ptr return_value = CORBA_Object::_nil ();

  if (table->find_ior (object_id, ior) == 0)
    {
      // Name found in the IOR Table.
      return_value = this->string_to_object (ior.c_str (), TAO_IN_ENV);
      return CORBA_Object::_duplicate (return_value);
    }
  else
    {
      // Get the list of initial reference prefixes specified through
      // -ORBDefaultInitRef.
      char * default_init_ref =
	this->orb_core_->orb_params ()->default_init_ref ();

      // Check if a DefaultInitRef was specified.
      if (ACE_OS::strlen (default_init_ref) != 0)
	{
	  ACE_CString list_of_profiles;

	  // Used by the strtok_r.
	  char *lasts[BUFSIZ];

	  // Append the given object ID to all the end-points of
	  // Default Init Ref.
	  for (char *str = ACE_OS::strtok_r (default_init_ref,
                                             ",",
                                             lasts);
	       str != 0 ;
	       str = ACE_OS::strtok_r (0,
                                       ",",
                                       lasts))
	    {
	      list_of_profiles += ACE_CString (str);
	      list_of_profiles += ACE_CString ("/");
	      list_of_profiles += object_id;
	      list_of_profiles += ACE_CString (",");
	    }

	  // Clean up.
	  delete [] default_init_ref;

	  // Replace the last extra comma with a null.
	  list_of_profiles[list_of_profiles.length () - 1] = '\0';

	  return_value = this->string_to_object (list_of_profiles.rep (),
                                                 TAO_IN_ENV);

	  return CORBA_Object::_duplicate (return_value);
	}

      delete default_init_ref;
    }

  if (ACE_OS::strcmp (name,
                      TAO_OBJID_NAMESERVICE) == 0)
    return this->resolve_service ("NameService",
				  timeout);
  else if (ACE_OS::strcmp (name,
                           TAO_OBJID_TRADINGSERVICE) == 0)
    return this->resolve_trading_service (timeout);
  else if (ACE_OS::strcmp (name,
                           TAO_OBJID_ROOTPOA) == 0)
    return this->resolve_root_poa ();
  else if (ACE_OS::strcmp (name,
                           TAO_OBJID_POACURRENT) == 0)
    return this->resolve_poa_current ();
  else
    return this->resolve_service (name,
				  timeout);

  //    TAO_THROW_RETURN (CORBA_ORB::InvalidName (),
  //                CORBA_Object::_nil ());

}

TAO_Stub *
CORBA_ORB::create_stub_object (const TAO_ObjectKey &key,
                               const char *type_id,
                               CORBA::Environment &env)
{
  if (this->open () == -1)
    {
      env.exception (new CORBA::INTERNAL (CORBA::COMPLETED_NO));
      return 0;
    }

  CORBA::String id;

  if (type_id)
    id = CORBA::string_copy (type_id);
  else
    id = 0;

  // First we create a profile list, well actually a list of one!
  // @@ should go to the acceptor for this, the orb delegates to the acceptor
  // to create Profiles!
  // We do not use ACE_NEW cause we want to return an exception if this
  // fails.

  // @@ Fred, please use ACE_NEW_THROW_RETURN instead!
  TAO_IIOP_Profile *pfile =
    new TAO_IIOP_Profile (this->orb_core_->orb_params ()->host (),
                          this->orb_core_->orb_params ()->addr ().get_port_number (),
                          key,
                          this->orb_core_->orb_params ()->addr ());

  TAO_Stub *data = 0;
  // @@ replace IIOP::Profile with something more appropriate!!
  data = new TAO_Stub (id, pfile);

  if (pfile == 0)
    {
      env.exception (new CORBA::NO_MEMORY (CORBA::COMPLETED_NO));
      return 0;
    }
  else
    {
      // We do not use ACE_NEW_RETURN or ACE_NEW since we need to
      // deallocate pfile.
      // @@ Fred, but you don't do this...

      // Plus we want to return an exception.  @@ If that's the only
      // reason, then you can use ACE_NEW_THROW_RETURN.
      data = new TAO_Stub (id, pfile);
      // pfile is given to TAO_Stub!

      if (data == 0)
        env.exception (new CORBA::NO_MEMORY (CORBA::COMPLETED_NO));
    }

  return data;
}

// Create an objref

CORBA::Object_ptr
CORBA_ORB::key_to_object (const TAO_ObjectKey &key,
                          const char *type_id,
                          CORBA::Environment &env)
{
  TAO_Stub *data = this->create_stub_object (key, type_id, env);

  if (env.exception () != 0)
    return CORBA::Object::_nil ();

  // Create the CORBA level proxy
  CORBA_Object *new_obj = new CORBA_Object (data);

  // Clean up in case of errors.
  if (CORBA::is_nil (new_obj))
    {
      data->_decr_refcnt ();
      env.exception (new CORBA::INTERNAL (CORBA::COMPLETED_NO));
      return CORBA::Object::_nil ();
    }

  return new_obj;
}

// Get access to the leader_follower_info.

TAO_Leader_Follower_Info &
CORBA_ORB::leader_follower_info (void)
{
  return leader_follower_info_;
}

#if !defined (TAO_HAS_MINIMUM_CORBA)

// Dynamic Any factory functions.

ACE_INLINE
CORBA_DynAny_ptr
CORBA_ORB::create_dyn_any       (const CORBA_Any& any,
                                 CORBA::Environment& env)
{
  return TAO_DynAny_i::create_dyn_any (any, env);
}

ACE_INLINE
CORBA_DynAny_ptr
CORBA_ORB::create_basic_dyn_any (CORBA_TypeCode_ptr tc,
                                 CORBA::Environment& env)
{
  return TAO_DynAny_i::create_dyn_any (tc, env);
}

ACE_INLINE
CORBA_DynStruct_ptr
CORBA_ORB::create_dyn_struct    (CORBA_TypeCode_ptr tc,
                                 CORBA::Environment& env)
{
  return TAO_DynAny_i::create_dyn_struct (tc, env);
}

ACE_INLINE
CORBA_DynSequence_ptr
CORBA_ORB::create_dyn_sequence  (CORBA_TypeCode_ptr tc,
                                 CORBA::Environment& env)
{
  return TAO_DynAny_i::create_dyn_sequence (tc, env);
}

ACE_INLINE
CORBA_DynArray_ptr
CORBA_ORB::create_dyn_array     (CORBA_TypeCode_ptr tc,
                                 CORBA::Environment& env)
{
  return TAO_DynAny_i::create_dyn_array (tc, env);
}

ACE_INLINE
CORBA_DynUnion_ptr
CORBA_ORB::create_dyn_union     (CORBA_TypeCode_ptr tc,
                                 CORBA::Environment& env)
{
  return TAO_DynAny_i::create_dyn_union (tc, env);
}

ACE_INLINE
CORBA_DynEnum_ptr
CORBA_ORB::create_dyn_enum      (CORBA_TypeCode_ptr tc,
                                 CORBA::Environment& env)
{
  return TAO_DynAny_i::create_dyn_enum (tc, env);
}

#endif /* TAO_HAS_MINIMUM_CORBA */

// String utility support; this needs to be integrated with the ORB's
// own memory allocation subsystem.

CORBA::String
CORBA::string_copy (const CORBA::Char *str)
{
  if (!str)
    return 0;

  size_t len = ACE_OS::strlen (str);

  // This allocates an extra byte for the '\0';
  CORBA::String copy = CORBA::string_alloc (len);

  ACE_OS::memcpy (copy, str, len + 1);
  return copy;
}

CORBA_String_var &
CORBA_String_var::operator= (char *p)
{
  if (this->ptr_ != p)
    {
      if (this->ptr_ != 0)
        CORBA::string_free (this->ptr_);
      this->ptr_ = p;
    }
  return *this;
}

CORBA_String_var &
CORBA_String_var::operator= (const char *p)
{
  if (this->ptr_ != 0)
    CORBA::string_free (this->ptr_);

  this->ptr_ = CORBA::string_dup (p);
  return *this;
}

CORBA_String_var &
CORBA_String_var::operator= (const CORBA_String_var& r)
{
  if (this != &r)
    {
      if (this->ptr_ != 0)
        CORBA::string_free (this->ptr_);
      this->ptr_ = CORBA::string_dup (r.ptr_);
    }
  return *this;
}

// Wide Character string utility support; this can need to be
// integrated with the ORB's own memory allocation subsystem.

CORBA::WString
CORBA::wstring_alloc (CORBA::ULong len)
{
  return new CORBA::WChar [(size_t) (len + 1)];
}

CORBA::WString
CORBA::wstring_copy (const CORBA::WChar *const str)
{
  if (!str)
    return 0;

  CORBA::WString retval = CORBA::wstring_alloc (ACE_OS::wslen (str));
  return ACE_OS::wscpy (retval, str);
}

void
CORBA::wstring_free (CORBA::WChar *const str)
{
  delete [] str;
}

void
CORBA_ORB::init_orb_globals (CORBA::Environment &env)
{
  ACE_MT (ACE_GUARD (ACE_Recursive_Thread_Mutex, tao_mon, *ACE_Static_Object_Lock::instance ()));

  // Put these initializations here so that exceptions are enabled
  // immediately.

  if (CORBA_ORB::orb_init_count_ == 0)
    {
      // initialize the system TypeCodes
      TAO_TypeCodes::init ();
      // initialize the factory for marshaling
      TAO_Marshal::init ();
      // initialize the interpreter
      TAO_CDR_Interpreter::init ();
      // initialize the system exceptions
      TAO_Exceptions::init (env);
    }
  CORBA_ORB::orb_init_count_++;
}

// ORB initialisation, per OMG document 94-9-46.
//
// XXX in addition to the "built in" Internet ORB, there will be ORBs
// @@                                ^^^^^^^^ XXX
// which are added separately, e.g. through a DLL listed in the
// registry.  Registry will be used to assign orb names and to
// establish which is the default.

CORBA::ORB_ptr
CORBA::ORB_init (int &argc,
                 char *const *argv,
                 const char * orb_name)
{
  return CORBA::ORB_init (argc, argv, orb_name,
                          CORBA::default_environment ());
}

CORBA::ORB_ptr
CORBA::ORB_init (int &argc,
                 char *const *argv,
                 const char * /* orb_name */,
                 CORBA::Environment &env)
{
  // Using ACE_Static_Object_Lock::instance() precludes <ORB_init>
  // from being called within a static object CTOR.
  ACE_MT (ACE_GUARD_RETURN (ACE_SYNCH_RECURSIVE_MUTEX, guard,
                            *ACE_Static_Object_Lock::instance (), 0));
  env.clear ();

  // Make sure initialization of TAO globals only occurs once.
  CORBA_ORB::init_orb_globals (env);

  if (env.exception () != 0)
    return 0;

  // Verify some of the basic implementation requirements.  This test
  // gets optimized away by a decent compiler (or else the rest of the
  // routine does).
  //
  // NOTE:  we still "just" assume that native floating point is IEEE.

  if (sizeof (CORBA::Short) != 2
      || sizeof (CORBA::Long) != 4
      || sizeof (CORBA::LongLong) != 8
      || sizeof (CORBA::Float) != 4
      || sizeof (CORBA::Double) != 8
      || sizeof (CORBA::LongDouble) != 16
      || sizeof (CORBA::WChar) < 2
      || sizeof (void *) != ACE_SIZEOF_VOID_P)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "%s; ERROR: unexpected basic type size; "
                  "s:%d l:%d ll:%d f:%d d:%d ld:%d wc:%d v:%d\n"
                  "please reconfigure TAO\n",
                  __FILE__,
                  sizeof (CORBA::Short),
                  sizeof (CORBA::Long),
                  sizeof (CORBA::LongLong),
                  sizeof (CORBA::Float),
                  sizeof (CORBA::Double),
                  sizeof (CORBA::LongDouble),
                  sizeof (CORBA::WChar),
                  sizeof (void *)));

      env.exception (new CORBA::INITIALIZE (CORBA::COMPLETED_NO));
      return 0;
    }

  // Get ORB Core
  // @@ As part of the ORB re-architecture this may be the point where
  //    we locate the right ORB (from a table) and use that one
  //    instead of using TAO_ORB_Core_instance ().
  TAO_ORB_Core *oc = TAO_ORB_Core_instance ();

  // Initialize the ORB Core instance.
  int result = oc->init (argc, (char **) argv);

  // Check for errors and return 0 if error.
  if (result == -1)
    {
      env.exception (new CORBA::BAD_PARAM (CORBA::COMPLETED_NO));
      return 0;
    }

  // @@ We may only want to set this if ORB_init() has 0 argc/argv
  // parameters.
  if (CORBA::instance_ == 0)
    CORBA::instance_ = oc->orb ();

  return oc->orb ();
}

// ****************************************************************

// Objref stringification.
CORBA::String
CORBA_ORB::object_to_string (CORBA::Object_ptr obj,
                             CORBA::Environment &env)
{
  env.clear ();

  // Application writer controls what kind of objref strings they get,
  // maybe along with other things, by how they initialize the ORB.

  if (use_omg_ior_format_)
    {
      // By default, orbs use IOR strings; these are ugly (and error
      // prone) but specified by CORBA.
      //
      // XXX there should be a simple way to reuse this code in other
      // ORB implementations ...

      // @@ Is BUFSIZ the right size here?
      char buf [BUFSIZ];
      TAO_OutputCDR cdr (buf,
                         sizeof buf,
                         TAO_ENCAP_BYTE_ORDER);

      // support limited oref ACE_OS::strcmp.
      (void) ACE_OS::memset (buf, 0, BUFSIZ);

      // Marshal the objref into an encapsulation bytestream.
      (void) cdr.write_octet (TAO_ENCAP_BYTE_ORDER);
      if ((cdr << obj) == 0)
        return 0;

      // Now hexify the encapsulated CDR data into a string, and
      // return that string.

      CORBA::String cp;
      size_t len = cdr.length ();

      CORBA::String string;
      ACE_ALLOCATOR_RETURN (string,
                            CORBA::string_alloc (sizeof ior_prefix + 2 * len),
                            0);

      ACE_OS::strcpy ((char *) string,
                      ior_prefix);

      const char *bytes = cdr.buffer ();

      for (cp = (CORBA::String) ACE_OS::strchr ((char *) string, ':') + 1;
           len--;
           bytes++)
        {
          *cp++ = ACE::nibble2hex ((*bytes) >> 4);
          *cp++ = ACE::nibble2hex (*bytes);
        }

      *cp = 0;
      return string;
    }
  else
    {
      // The "internet" ORB uses readable URL style objrefs, as used
      // in the World Wide Web.
      //
      // This only works for IIOP objrefs.  If we're handed an objref
      // that's not an IIOP objref, fail -- application must use an
      // ORB that's configured differently.  @@ Is this true? FRED

      if (obj->_stubobj () == 0)
        return CORBA::string_copy ((CORBA::String) TAO_IIOP_Profile::prefix ());
        // @@ This should be some sort of default prefix, not
        // hardcoded to IIOP!! FRED

      CORBA::String buf =
        obj->_stubobj ()->profile_in_use ()->to_string (env);
      return buf;
    }
}

// ****************************************************************

// Destringify arbitrary objrefs.  called from resolve_name_service ()
// with an IOR multicast_to_service ().
CORBA::Object_ptr
CORBA_ORB::string_to_object (const char *str,
                             CORBA::Environment &ACE_TRY_ENV)
{
  CORBA::Object_ptr obj = CORBA::Object::_nil ();

  // Use the prefix code to choose which destringify algorithm to use.
  const size_t iiop_prefix_len =
    ACE_OS::strlen (TAO_IIOP_Profile::prefix ());
  if (ACE_OS::strncmp (str,
                       TAO_IIOP_Profile::prefix (),
                       iiop_prefix_len) == 0)
    obj = this->iiop_string_to_object (str + iiop_prefix_len,
                                       ACE_TRY_ENV);

  else if (ACE_OS::strncmp (str,
                            file_prefix,
                            sizeof file_prefix - 1) == 0)
    obj = this->file_string_to_object (str + sizeof file_prefix -1,
                                       ACE_TRY_ENV);

  else if (ACE_OS::strncmp (str,
                            ior_prefix,
                            sizeof ior_prefix - 1) == 0)
    obj = this->ior_string_to_object (str + sizeof ior_prefix - 1,
                                      ACE_TRY_ENV);

  else if (ACE_OS::strncmp (str,
			    iioploc_prefix,
			    sizeof iioploc_prefix - 1) == 0)
    obj = this->iioploc_string_to_object (str + sizeof iioploc_prefix - 1,
                                          ACE_TRY_ENV);

  return obj;
}

// ****************************************************************

// Destringify OMG-specified "IOR" string.
//
// XXX there should be a simple way to reuse this code in other ORB
// implementations ...

CORBA::Object_ptr
CORBA_ORB::ior_string_to_object (const char *str,
                                 CORBA::Environment &ACE_TRY_ENV)
{
  // Unhex the bytes, and make a CDR deencapsulation stream from the
  // resulting data.
  ACE_Message_Block mb (ACE_OS::strlen ((char *) str) / 2 + 1
                        + ACE_CDR::MAX_ALIGNMENT + 1);

  ACE_CDR::mb_align (&mb);

  char *buffer = mb.rd_ptr ();

  const char *tmp = str;
  size_t len = 0;

  while (tmp [0] && tmp [1])
    {
      u_char byte;

      if (!(isxdigit (tmp [0]) && isxdigit (tmp [1])))
        break;

      byte = (u_char) (ACE::hex2byte (tmp [0]) << 4);
      byte |= ACE::hex2byte (tmp [1]);

      buffer [len++] = byte;
      tmp += 2;
    }

  if (tmp [0] && !isspace (tmp [0]))
    {
      ACE_THROW_RETURN (CORBA::BAD_PARAM (CORBA::COMPLETED_NO),
                        CORBA::Object::_nil ());
    }

  // Create deencapsulation stream ... then unmarshal objref from that
  // stream.

  int byte_order = *(mb.rd_ptr ());
  mb.rd_ptr (1);
  mb.wr_ptr (len);
  TAO_InputCDR stream (&mb, byte_order);

  CORBA::Object_ptr objref = CORBA::Object::_nil ();
  stream >> objref;

  return objref;
}

// Destringify URL style IIOP objref.
CORBA::Object_ptr
CORBA_ORB::iiop_string_to_object (const char *string,
                                  CORBA::Environment &ACE_TRY_ENV)
{
  // NIL objref encodes as just "iiop:" ... which has already been
  // removed, so we see it as an empty string.
  CORBA::Object_ptr obj = CORBA::Object::_nil ();

  if (!string || !*string)
    return obj;

  // type ID not encoded in this string ... makes narrowing rather
  // expensive, though it does ensure that type-safe narrowing code
  // gets thoroughly excercised/debugged!  Without a typeID, the
  // _narrow will be required to make an expensive remote "is_a" call.

  // Allocate a Multiple Profile with the given no. of profiles.
  TAO_MProfile *mp;
  ACE_NEW_RETURN (mp,
		  TAO_MProfile (1),
		  obj);

  TAO_Profile* pfile;
  ACE_NEW_RETURN (pfile,
                  TAO_IIOP_Profile (string, ACE_TRY_ENV),
                  obj);
  ACE_CHECK_RETURN (obj);
  // pfile refcount == 1

  mp->give_profile (pfile);

  // Now make the TAO_Stub ...
  TAO_Stub *data;
  ACE_NEW_RETURN (data,
                  TAO_Stub ((char *) 0, mp),
                  obj);
  // pfile refcount == 2

  // Create the CORBA level proxy.
  TAO_ServantBase *servant =
    this->_get_collocated_servant (data);

  ACE_NEW_RETURN (obj,
                  CORBA_Object (data,
                                servant,
                                servant != 0),
                  obj);

  // Set the ref_count on data to 1, which is correct, because only
  // obj has now a reference to it.
  // data->_decr_refcnt ();

  return obj;
}

// DeStringifies the iioploc style IORs. This function creates a Stub
// object with multiple profiles and then the object reference.
CORBA::Object_ptr
CORBA_ORB::iioploc_string_to_object (const char *string,
			  CORBA::Environment &env)
{
  CORBA::Object_ptr obj = CORBA::Object::_nil ();

  // NIL objref encodes as just "iioploc:" ... which has already been
  // removed, so we see it as an empty string.

  if (!string || !*string)
    return CORBA::Object::_nil ();

  // type ID not encoded in this string ... makes narrowing rather
  // expensive, though it does ensure that type-safe narrowing code
  // gets thoroughly excercised/debugged!  Without a typeID, the
  // _narrow will be required to make an expensive remote "is_a" call.

  ACE_CString list_of_profiles (string);

  // Count the No. of profiles in the given list.
  int profile_count = 1;

  for (size_t i = 0;
       i < list_of_profiles.length ();
       i++)
    {
      if (list_of_profiles[i] == ',')
      profile_count++;
    }

  // Allocate a Multiple Profile with the given no. of profiles.
  TAO_MProfile *mp;
  ACE_NEW_RETURN (mp,
		  TAO_MProfile (profile_count),
		  CORBA::Object::_nil ());

  // Extract the comma separated profiles in the list and
  // populate the Multiple Profile.
  TAO_IIOP_Profile *pfile;
  char *lasts[BUFSIZ];

  for (char *str = ACE_OS::strtok_r (list_of_profiles.rep (), ",",lasts);
       str != 0 ;
       str = ACE_OS::strtok_r (0, ",",lasts))

    {
      ACE_NEW_RETURN (pfile,
		      TAO_IIOP_Profile (CORBA::string_dup (str),
   					env),
   		      CORBA::Object::_nil ());

      // Give up ownership of the profile.
      mp->give_profile (pfile);
    }

  // Now make the TAO_Stub ...
  TAO_Stub *data;
  ACE_NEW_RETURN (data,
                  TAO_Stub ((char *) 0, mp),
                  CORBA::Object::_nil ());

  // Create the CORBA level proxy.
  TAO_ServantBase *servant =
    this->_get_collocated_servant (data);

  // This will increase the ref_count on data by one
  ACE_NEW_RETURN (obj,
                  CORBA_Object (data,
                                servant,
                                servant != 0),
                  CORBA::Object::_nil ());

  // @@EXC@@ This code is not exception safe, we should use auto_ptr<>
  // or allocate <mp> from the stack!
  delete mp;

  return obj;
}

CORBA::Object_ptr
CORBA_ORB::file_string_to_object (const char* filename,
                                  CORBA::Environment& ACE_TRY_ENV)
{
  ACE_HANDLE handle = ACE_OS::open (filename, O_RDONLY);
  if (handle == ACE_INVALID_HANDLE)
    return CORBA::Object::_nil ();

  ACE_Read_Buffer reader (handle);

  char* string = reader.read ();
  ACE_OS::close (handle);
  if (string == 0)
    return CORBA::Object::_nil ();

  CORBA::Object_ptr object = CORBA::Object::_nil ();
  ACE_TRY
    {
      object = this->string_to_object (string, ACE_TRY_ENV);
      ACE_TRY_CHECK;

      reader.alloc ()->free (string);
    }
  ACE_CATCHANY
    {
      reader.alloc ()->free (string);
      ACE_RETHROW;
    }
  ACE_ENDTRY;

  return object;
}

// ****************************************************************

TAO_ServantBase *
CORBA_ORB::_get_collocated_servant (TAO_Stub *sobj)
{
  // ACE_DEBUG ((LM_DEBUG, "CORBA_ORB: get_collocated_servant\n"));

  if (this->optimize_collocation_objects_ && sobj != 0)
    {
      TAO_Profile *pfile = sobj->profile_in_use ();

      // Make sure users passed in a valid TAO_Stub otherwise, we
      // don't know what to do next.
      if (pfile == 0)
        {
          // @@ Fred, can you please either keep these debugging
          // statements in or remove them, but please don't leave the
          // #if 0's around!
#if 0
          ACE_ERROR ((LM_ERROR,
		      "%p: Passing IIOP ORB and non-IIOP object\n",
		      "_get_collocated_object"));
#endif
	  // Something must be wrong!
          return 0;
        }
#if 0
      ACE_DEBUG ((LM_DEBUG,
                  "CORBA_ORB: checking collocation for <%s>\n",
                  pfile->addr_to_string ()));
#endif

      // @@EXC@@ We should receive the <env> from the command line.
      // @@ Fred: why do we need an environment for the
      // Profile::_key() method?

      CORBA::Environment env;
      TAO_ObjectKey_var objkey = pfile->_key (env);

      if (env.exception ())
        {
#if 0
          ACE_DEBUG ((LM_DEBUG,
                      "CORBA_ORB: cannot find key for <%s>\n",
                      pfile->addr_to_string ()));
#endif
          return 0;
        }

      // Check if the object requested is a collocated object.
      // @@ FRED - can we make this more generic!!
      // @@ Fred: this is a question that the Acceptor registry must
      //    answer, in other words: we should go to the connector
      //    registry with the Stub object and ask if that object is
      //    collocated or not.  Then we simply lookup in the POA to
      //    find the servant.
      //    How does the Acceptor Registry answer the question:
      //    - For each profile in the Stub it iterates over the
      //      acceptors, if the profile and the acceptor have the same
      //      protocol then we pass the profile to the acceptor.
      //    - The acceptor downcast the profile, the derived class
      //      contains a method that returns the address in the
      //      favourite format for that protocol (i.e. this is not a
      //      method of the base class); it uses that address to match
      //      with the addresses it is accepting on.
      //    - A policy question: do we return when the first acceptor
      //      matches or if they all match?
      //      Before answering: "only when they all match" think about
      //      a server that is restarted with more endpoints (or
      //      less), shouldn't old, persistent IORs, still be treated
      //      as collocated?
      TAO_POA *poa = 0;
      if (pfile->tag () == TAO_IOP_TAG_INTERNET_IOP)
        {
          const ACE_INET_Addr &addr =
            ACE_dynamic_cast (TAO_IIOP_Profile*,pfile)->object_addr();

          poa = this->orb_core_->get_collocated_poa (addr);
        }
      else
        ACE_ERROR ((LM_ERROR,
                    "get_collocated_poa NOT Supported for NON-IIOP profile!\n"));

      if (poa != 0)
        {
          PortableServer::Servant servant =
            poa->find_servant (objkey.in (), env);
          if (env.exception ())
            {
#if 0
              ACE_DEBUG ((LM_DEBUG,
                          "CORBA_ORB: cannot find servant for <%s>\n",
                          pfile->addr_to_string ()));
#endif
              return 0;
            }

#if 0
          ACE_DEBUG ((LM_DEBUG,
                      "CORBA_ORB: object at <%s> is collocated\n",
                      pfile->addr_to_string ()));
#endif
          return servant;
        }
    }

#if 0
  ACE_DEBUG ((LM_DEBUG,
	      "CORBA_ORB: collocation failed for \n"));
#endif

  return 0;
}

// ****************************************************************

// Add a mapping ObjectID->IOR to the table.
int
CORBA_ORB::_tao_add_to_IOR_table (ACE_CString object_id,
                                  CORBA::Object_ptr obj)
{
  if (CORBA::is_nil (obj))
    ACE_ERROR_RETURN ((LM_ERROR,
		       "Unable to add IOR to table\n"),
		      -1);

  CORBA::String_var string =
    this->object_to_string (obj);

  if (string.in () == 0 || string.in ()[0] == '\0')
    return -1;

  ACE_CString ior (string.in ());

  if (this->lookup_table_.add_ior (object_id, ior) != 0)
    ACE_ERROR_RETURN ((LM_ERROR,
		       "Unable to add IOR to table\n"),
		      -1);

  return 0;
}

// Find an IOR in the table for the given ObjectID.
int
CORBA_ORB::_tao_find_in_IOR_table (ACE_CString object_id,
                                   CORBA::Object_ptr &obj)
{
  ACE_CString ior;

  if (this->lookup_table_.find_ior (object_id, ior) != 0)
    ACE_ERROR_RETURN ((LM_ERROR,
		       "No match for the given ObjectID\n"),
		      -1);

  obj = this->string_to_object (ior.c_str ());

  return 0;
}

// ****************************************************************

CORBA::ORB_ptr
CORBA::instance (void)
{
  ACE_MT (ACE_GUARD_RETURN (ACE_SYNCH_RECURSIVE_MUTEX, guard,
                            *ACE_Static_Object_Lock::instance (), 0));
  if (CORBA::instance_ == 0)
    {
      int argc = 0;
      char *const *argv = 0;
      // Note that CORBA::ORB_init() will also acquire the static
      // lock, but that's ok since it's a recursive lock.
      CORBA::instance_ = CORBA::ORB_init (argc, argv);
    }

  return CORBA::instance_;
}

void
CORBA::instance (CORBA::ORB_ptr orb)
{
  ACE_MT (ACE_GUARD (ACE_SYNCH_RECURSIVE_MUTEX, guard,
                     *ACE_Static_Object_Lock::instance ()));
  CORBA::instance_ = orb;
}

// *************************************************************
// Inline operators for TAO_opaque encoding and decoding
// *************************************************************

CORBA::Boolean
operator<< (TAO_OutputCDR& cdr, const TAO_opaque& x)
{
  CORBA::ULong length = x.length ();
  cdr.write_ulong (length);
#if !defined (TAO_NO_COPY_OCTET_SEQUENCES)
  cdr.write_octet_array (x.get_buffer (), length);
#else
  if (x.mb () == 0)
    cdr.write_octet_array (x.get_buffer (), length);
  else
    cdr.write_octet_array_mb (x.mb ());
#endif /* TAO_NO_COPY_OCTET_SEQUENCES */
  return cdr.good_bit ();
}

CORBA::Boolean
operator>>(TAO_InputCDR& cdr, TAO_opaque& x)
{
  CORBA::ULong length;
  cdr.read_ulong (length);
#if !defined (TAO_NO_COPY_OCTET_SEQUENCES)
  x.length (length);
  cdr.read_octet_array (x.get_buffer (), length);
#else
  x.replace (length, cdr.start ());
  cdr.skip_bytes (length);
#endif /* TAO_NO_COPY_OCTET_SEQUENCES */
  return cdr.good_bit ();
}

// ****************************************************************

#define CACHED_CONNECT_STRATEGY ACE_Cached_Connect_Strategy<TAO_Client_Connection_Handler, TAO_SOCK_CONNECTOR, TAO_Cached_Connector_Lock>
#define REFCOUNTED_HASH_RECYCLABLE_ADDR ACE_Refcounted_Hash_Recyclable<ACE_INET_Addr>

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

#if !defined (TAO_NO_COPY_OCTET_SEQUENCES)
template class TAO_Unbounded_Sequence<CORBA::Octet>;
#endif /* defined (TAO_NO_COPY_OCTET_SEQUENCES) */

template class ACE_Dynamic_Service<TAO_Server_Strategy_Factory>;
template class ACE_Dynamic_Service<TAO_Client_Strategy_Factory>;
template class CACHED_CONNECT_STRATEGY;
template class ACE_Guard<TAO_Cached_Connector_Lock>;
template class ACE_Atomic_Op<ACE_SYNCH_MUTEX, u_int>;
template class ACE_Hash_Map_Entry<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *>;
template class ACE_Hash<REFCOUNTED_HASH_RECYCLABLE_ADDR>;
template class ACE_Equal_To<REFCOUNTED_HASH_RECYCLABLE_ADDR>;
template class ACE_Hash_Map_Manager<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *, ACE_SYNCH_MUTEX>;
template class ACE_Hash_Map_Manager_Ex<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *, ACE_Hash<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_Equal_To<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_SYNCH_MUTEX>;
template class ACE_Hash_Map_Iterator_Base_Ex<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *, ACE_Hash<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_Equal_To<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_SYNCH_MUTEX>;
template class ACE_Hash_Map_Iterator<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *, ACE_SYNCH_MUTEX>;
template class ACE_Hash_Map_Iterator_Ex<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *, ACE_Hash<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_Equal_To<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_SYNCH_MUTEX>;
template class ACE_Hash_Map_Reverse_Iterator<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *, ACE_SYNCH_MUTEX>;
template class ACE_Hash_Map_Reverse_Iterator_Ex<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *, ACE_Hash<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_Equal_To<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_SYNCH_MUTEX>;
template class ACE_Hash_Map_Manager<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *, ACE_SYNCH_NULL_MUTEX>;
template class ACE_Hash_Map_Manager_Ex<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *, ACE_Hash<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_Equal_To<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_SYNCH_NULL_MUTEX>;
template class ACE_Hash_Map_Iterator_Base_Ex<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *, ACE_Hash<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_Equal_To<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_SYNCH_NULL_MUTEX>;
template class ACE_Hash_Map_Iterator<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *, ACE_SYNCH_NULL_MUTEX>;
template class ACE_Hash_Map_Iterator_Ex<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *, ACE_Hash<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_Equal_To<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_SYNCH_NULL_MUTEX>;
template class ACE_Hash_Map_Reverse_Iterator<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *, ACE_SYNCH_NULL_MUTEX>;
template class ACE_Hash_Map_Reverse_Iterator_Ex<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *, ACE_Hash<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_Equal_To<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_SYNCH_NULL_MUTEX>;

template class ACE_Unbounded_Set<ACE_INET_Addr>;
template class ACE_Unbounded_Set_Iterator<ACE_INET_Addr>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#if !defined (TAO_NO_COPY_OCTET_SEQUENCES)
#pragma instantiate TAO_Unbounded_Sequence<CORBA::Octet>
#endif /* defined (TAO_NO_COPY_OCTET_SEQUENCES) */

#pragma instantiate ACE_Dynamic_Service<TAO_Server_Strategy_Factory>
#pragma instantiate ACE_Dynamic_Service<TAO_Client_Strategy_Factory>
#pragma instantiate CACHED_CONNECT_STRATEGY
#pragma instantiate ACE_Guard<TAO_Cached_Connector_Lock>
#pragma instantiate ACE_Atomic_Op<ACE_SYNCH_MUTEX, u_int>
#pragma instantiate ACE_Hash_Map_Entry<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *>
#pragma instantiate ACE_Hash<REFCOUNTED_HASH_RECYCLABLE_ADDR>
#pragma instantiate ACE_Equal_To<REFCOUNTED_HASH_RECYCLABLE_ADDR>
#pragma instantiate ACE_Hash_Map_Manager<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *, ACE_SYNCH_MUTEX>
#pragma instantiate ACE_Hash_Map_Manager_Ex<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *, ACE_Hash<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_Equal_To<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_SYNCH_MUTEX>
#pragma instantiate ACE_Hash_Map_Iterator_Base_Ex<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *, ACE_Hash<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_Equal_To<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_SYNCH_MUTEX>
#pragma instantiate ACE_Hash_Map_Iterator<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *, ACE_SYNCH_MUTEX>
#pragma instantiate ACE_Hash_Map_Iterator_Ex<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *, ACE_Hash<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_Equal_To<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_SYNCH_MUTEX>
#pragma instantiate ACE_Hash_Map_Reverse_Iterator<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *, ACE_SYNCH_MUTEX>
#pragma instantiate ACE_Hash_Map_Reverse_Iterator_Ex<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *, ACE_Hash<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_Equal_To<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_SYNCH_MUTEX>
#pragma instantiate ACE_Hash_Map_Manager<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *, ACE_SYNCH_NULL_MUTEX>
#pragma instantiate ACE_Hash_Map_Manager_Ex<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *, ACE_Hash<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_Equal_To<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_SYNCH_NULL_MUTEX>
#pragma instantiate ACE_Hash_Map_Iterator_Base_Ex<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *, ACE_Hash<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_Equal_To<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_SYNCH_NULL_MUTEX>
#pragma instantiate ACE_Hash_Map_Iterator<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *, ACE_SYNCH_NULL_MUTEX>
#pragma instantiate ACE_Hash_Map_Iterator_Ex<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *, ACE_Hash<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_Equal_To<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_SYNCH_NULL_MUTEX>
#pragma instantiate ACE_Hash_Map_Reverse_Iterator<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *, ACE_SYNCH_NULL_MUTEX>
#pragma instantiate ACE_Hash_Map_Reverse_Iterator_Ex<REFCOUNTED_HASH_RECYCLABLE_ADDR, TAO_Client_Connection_Handler *, ACE_Hash<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_Equal_To<REFCOUNTED_HASH_RECYCLABLE_ADDR>, ACE_SYNCH_NULL_MUTEX>

#pragma instantiate ACE_Unbounded_Set<ACE_INET_Addr>
#pragma instantiate ACE_Unbounded_Set_Iterator<ACE_INET_Addr>

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

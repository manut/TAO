/* -*- C++ -*- $Id$ */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "tao/orbconf.h"

#if (TAO_HAS_CORBA_MESSAGING == 1)

#include "MessagingS.h"
#include "Operation_Table.h"
#include "Object_Adapter.h"
#include "tao/TAO_Server_Request.h"
#include "tao/Stub.h"
#include "tao/ORB_Core.h"

#if !defined (__ACE_INLINE__)
#include "MessagingS.i"
#endif /* !defined INLINE */

ACE_RCSID(tao, MessagingS, "$Id$")

#if (TAO_HAS_AMI_CALLBACK == 1) || (TAO_HAS_AMI_POLLER == 1)

class TAO_Messaging_ReplyHandler_Perfect_Hash_OpTable : public TAO_Perfect_Hash_OpTable
{
private:
  unsigned int hash (const char *str, unsigned int len);
public:
 const TAO_operation_db_entry * lookup (const char *str, unsigned int len);
};
/* starting time is 12:21:06 */
/* C++ code produced by gperf version 2.8 (ACE version) */
/* Command-line: gperf -m -M -J -c -C -D -E -T -f 0 -F 0 -a -o -t -p -K opname_ -L C++ -Z TAO_Messaging_ReplyHandler_Perfect_Hash_OpTable -N lookup  */
unsigned int
TAO_Messaging_ReplyHandler_Perfect_Hash_OpTable::hash (const char *str, unsigned int len)
{
  static const unsigned char asso_values[] =
    {
#if defined (ACE_MVS)
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14,  0,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14,  0,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14,  0, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14,
#else
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14,  0, 14,  0, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14,  0, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14,
#endif /* ACE_MVS */
    };
  return len + asso_values[str[len - 1]] + asso_values[str[0]];
}

const class TAO_operation_db_entry *
TAO_Messaging_ReplyHandler_Perfect_Hash_OpTable::lookup (const char *str, unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 2,
      MIN_WORD_LENGTH = 5,
      MAX_WORD_LENGTH = 13,
      MIN_HASH_VALUE = 5,
      MAX_HASH_VALUE = 13,
      HASH_VALUE_RANGE = 9,
      DUPLICATES = 0
    };

  static const class TAO_operation_db_entry  wordlist[] =
    {
      {"",0},{"",0},{"",0},{"",0},{"",0},
      {"_is_a",  &POA_Messaging::ReplyHandler::_is_a_skel},
      {"",0},{"",0},{"",0},{"",0},{"",0},{"",0},{"",0},
      {"_non_existent",  &POA_Messaging::ReplyHandler::_non_existent_skel},
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= MIN_HASH_VALUE)
        {
          const char *s = wordlist[key].opname_;

          if (*str == *s && !strncmp (str + 1, s + 1, len - 1))
            return &wordlist[key];
        }
    }
  return 0;
}
/* ending time is 12:21:06 */
static TAO_Messaging_ReplyHandler_Perfect_Hash_OpTable tao_Messaging_ReplyHandler_optable;

Messaging::ReplyHandler_ptr _TAO_collocation_POA_Messaging_ReplyHandler_Stub_Factory (
    CORBA::Object_ptr obj
  )
{
  TAO_Stub *stub = obj->_stubobj ();

  switch (stub->servant_orb_var ()->orb_core ()->get_collocation_strategy ())
    {
    case TAO_ORB_Core::THRU_POA:
      {
      Messaging::ReplyHandler_ptr retval = 0;
      ACE_NEW_RETURN (
          retval,
          POA_Messaging::_tao_thru_poa_collocated_ReplyHandler (stub),
          0
        );
      return retval;
      }
    case TAO_ORB_Core::DIRECT:
      if (obj->_is_local () != 0)
        {
          TAO_Collocated_Object *local_object =
            TAO_Collocated_Object::_narrow (obj);

          POA_Messaging::ReplyHandler *servant = ACE_reinterpret_cast (POA_Messaging::ReplyHandler*, local_object->_servant ()->_downcast ("IDL:omg.org/Messaging/ReplyHandler:1.0"));
          if (servant != 0)
            {
              Messaging::ReplyHandler *retval = 0;
              ACE_NEW_RETURN (
                  retval,
                  POA_Messaging::_tao_direct_collocated_ReplyHandler (servant, stub),
                  0
                );
              return retval;
            }
        }
      break;
    default:
      break;
    }
  return 0;
}

int _TAO_collocation_POA_Messaging_ReplyHandler_Stub_Factory_Initializer (long dummy)
{
  ACE_UNUSED_ARG (dummy);

  _TAO_collocation_Messaging_ReplyHandler_Stub_Factory_function_pointer =
    _TAO_collocation_POA_Messaging_ReplyHandler_Stub_Factory;

  return 0;
}

static int _TAO_collocation_POA_Messaging_ReplyHandler_Stub_Factory_Initializer_Scarecrow =
  _TAO_collocation_POA_Messaging_ReplyHandler_Stub_Factory_Initializer (ACE_reinterpret_cast (long, _TAO_collocation_POA_Messaging_ReplyHandler_Stub_Factory_Initializer));

// skeleton constructor
POA_Messaging::ReplyHandler::ReplyHandler (void)
{
  this->optable_ = &tao_Messaging_ReplyHandler_optable;
}

// copy ctor
POA_Messaging::ReplyHandler::ReplyHandler (const ReplyHandler& rhs)
  :   TAO_ServantBase (rhs)
{}

// skeleton destructor
POA_Messaging::ReplyHandler::~ReplyHandler (void)
{
}

void POA_Messaging::ReplyHandler::_is_a_skel (
    TAO_ServerRequest &_tao_server_request,
    void * _tao_object_reference,
    void * /* context */,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  TAO_InputCDR &_tao_in = _tao_server_request.incoming ();
  POA_Messaging::ReplyHandler *_tao_impl = (POA_Messaging::ReplyHandler *) _tao_object_reference;
  CORBA::Boolean _tao_retval = 0;
  CORBA::String_var value;
  if (!((_tao_in >> value.out ())))
    ACE_THROW (CORBA::MARSHAL ());

  _tao_retval = _tao_impl->_is_a (value.in (), ACE_TRY_ENV);
  ACE_CHECK;

  _tao_server_request.init_reply ();
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  if (!((_tao_out << CORBA::Any::from_boolean (_tao_retval))))
    ACE_THROW (CORBA::MARSHAL ());
}

void POA_Messaging::ReplyHandler::_non_existent_skel (
    TAO_ServerRequest &_tao_server_request,
    void * _tao_object_reference,
    void * /* context */,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  POA_Messaging::ReplyHandler *_tao_impl = (POA_Messaging::ReplyHandler *) _tao_object_reference;
  CORBA::Boolean _tao_retval = _tao_impl->_non_existent (ACE_TRY_ENV);
  ACE_CHECK;

  _tao_server_request.init_reply ();
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  if (!((_tao_out << CORBA::Any::from_boolean (_tao_retval))))
    ACE_THROW (CORBA::MARSHAL ());
}

CORBA::Boolean POA_Messaging::ReplyHandler::_is_a (
    const char* value,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/Messaging/ReplyHandler:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (ACE_TRY_ENV))))
      return 1;
    else
      return 0;
}

void* POA_Messaging::ReplyHandler::_downcast (
    const char* logical_type_id
  )
{
if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/Messaging/ReplyHandler:1.0") == 0)
    return ACE_static_cast (POA_Messaging::ReplyHandler_ptr, this);
    if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/Object:1.0") == 0)
    return ACE_static_cast(PortableServer::Servant, this);
  return 0;
}

void POA_Messaging::ReplyHandler::_dispatch (TAO_ServerRequest &req, void *context, CORBA::Environment &ACE_TRY_ENV)
{
  this->synchronous_upcall_dispatch(req, context, this, ACE_TRY_ENV);
}

const char* POA_Messaging::ReplyHandler::_interface_repository_id (void) const
{
  return "IDL:omg.org/Messaging/ReplyHandler:1.0";
}

Messaging::ReplyHandler*
POA_Messaging::ReplyHandler::_this (CORBA_Environment &ACE_TRY_ENV)
{
  TAO_Stub *stub = this->_create_stub (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);
  if (stub->servant_orb_var ()->orb_core ()->optimize_collocation_objects ())
    switch (stub->servant_orb_var ()->orb_core ()->get_collocation_strategy ())
      {
      case TAO_ORB_Core::THRU_POA:
        {
          ::Messaging::ReplyHandler_ptr retval = 0;
          ACE_NEW_RETURN (
              retval,
              POA_Messaging::_tao_thru_poa_collocated_ReplyHandler (stub),
              0
            );
          return retval;
        }
      case TAO_ORB_Core::DIRECT:
        {
          ::Messaging::ReplyHandler_ptr retval = 0;
          ACE_NEW_RETURN (
              retval,
              POA_Messaging::_tao_direct_collocated_ReplyHandler (this, stub),
              0
            );
          return retval;
        }
      default:
        ACE_THROW_RETURN (CORBA::BAD_PARAM (), 0);
      }
  else
    {
      // stub->_incr_refcnt ();
      CORBA::Object_ptr tmp = CORBA::Object::_nil ();
      ACE_NEW_RETURN (tmp, CORBA::Object (stub), 0);
      CORBA::Object_var obj = tmp;
      return ::Messaging::ReplyHandler::_unchecked_narrow (obj.in ());
    }
}

POA_Messaging::_tao_thru_poa_collocated_ReplyHandler::_tao_thru_poa_collocated_ReplyHandler (
  TAO_Stub *stub
)
  :  CORBA_Object (stub, 1)
{
}

CORBA::Boolean POA_Messaging::_tao_thru_poa_collocated_ReplyHandler::_is_a(
    const CORBA::Char *logical_type_id,
    CORBA_Environment &ACE_TRY_ENV
  )

{
  TAO_Object_Adapter::Servant_Upcall servant_upcall (
      this->_stubobj ()->servant_orb_var ()->orb_core ()
    );
  CORBA::Object_var forward_to;
  servant_upcall.prepare_for_upcall (
      this->_object_key (),
      "_is_a",
      forward_to.out (),
      ACE_TRY_ENV
    );
  ACE_CHECK_RETURN (0);
  return ACE_reinterpret_cast (
      POA_Messaging::ReplyHandler_ptr,
      servant_upcall.servant ()->_downcast (
          "IDL:omg.org/Messaging/ReplyHandler:1.0"
        )
    )->_is_a (logical_type_id, ACE_TRY_ENV);
}


CORBA::Boolean POA_Messaging::_tao_thru_poa_collocated_ReplyHandler::_non_existent(
    CORBA_Environment &ACE_TRY_ENV
  )

{
  TAO_Object_Adapter::Servant_Upcall servant_upcall (
      this->_stubobj ()->servant_orb_var ()->orb_core ()
    );
  CORBA::Object_var forward_to;
  servant_upcall.prepare_for_upcall (
      this->_object_key (),
      "_non_existent",
      forward_to.out (),
      ACE_TRY_ENV
    );
  ACE_CHECK_RETURN (0);
  return ACE_reinterpret_cast (
      POA_Messaging::ReplyHandler_ptr,
      servant_upcall.servant ()->_downcast (
          "IDL:omg.org/Messaging/ReplyHandler:1.0"
        )
    )->_non_existent (ACE_TRY_ENV);
}


POA_Messaging::_tao_direct_collocated_ReplyHandler::_tao_direct_collocated_ReplyHandler (
    POA_Messaging::ReplyHandler_ptr  servant,
    TAO_Stub *stub
  )
  : ACE_NESTED_CLASS (Messaging,ReplyHandler) (),
    TAO_Collocated_Object (stub, 1, servant),
    CORBA_Object (stub, 1),
    servant_ (servant)
{
}

CORBA::Boolean POA_Messaging::_tao_direct_collocated_ReplyHandler::_is_a(
    const CORBA::Char *logical_type_id,
    CORBA_Environment &ACE_TRY_ENV
  )

{
  return this->servant_->_is_a (logical_type_id, ACE_TRY_ENV);
}

void *
POA_Messaging::_tao_direct_collocated_ReplyHandler::_tao_QueryInterface (ptr_arith_t type)
{
  void *value =
    this->TAO_Collocated_Object::_tao_QueryInterface (type);
  if (value != 0)
    return value;
  return this->ACE_NESTED_CLASS (Messaging, ReplyHandler)::_tao_QueryInterface (type);
}


POA_Messaging::ReplyHandler_ptr POA_Messaging::_tao_direct_collocated_ReplyHandler::_get_servant (void) const
{
  return this->servant_;
}

CORBA::Boolean POA_Messaging::_tao_direct_collocated_ReplyHandler::_non_existent(
    CORBA_Environment &ACE_TRY_ENV
  )

{
  return this->servant_->_non_existent (ACE_TRY_ENV);
}

#endif /* TAO_HAS_AMI_CALLBACK == 1 || TAO_HAS_AMI_POLLER == 1 */

#endif /* TAO_HAS_CORBA_MESSAGING == 1 */

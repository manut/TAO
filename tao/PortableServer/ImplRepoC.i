// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html


// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:63

#if !defined (_IMPLEMENTATIONREPOSITORY_SERVEROBJECT___CI_)
#define _IMPLEMENTATIONREPOSITORY_SERVEROBJECT___CI_

ACE_INLINE
ImplementationRepository::ServerObject::ServerObject (
    TAO_Stub *objref,
    CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (objref, _tao_collocated, servant, oc),
    the_TAO_ServerObject_Proxy_Broker_ (0)
  
{
  this->ImplementationRepository_ServerObject_setup_collocation (_tao_collocated);
}

ACE_INLINE
ImplementationRepository::ServerObject::ServerObject (
    IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (ior, oc),
    the_TAO_ServerObject_Proxy_Broker_ (0)
  
{
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:63

#if !defined (_IMPLEMENTATIONREPOSITORY_ADMINISTRATION___CI_)
#define _IMPLEMENTATIONREPOSITORY_ADMINISTRATION___CI_

ACE_INLINE
ImplementationRepository::Administration::Administration (
    TAO_Stub *objref,
    CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (objref, _tao_collocated, servant, oc),
    the_TAO_Administration_Proxy_Broker_ (0)
  
{
  this->ImplementationRepository_Administration_setup_collocation (_tao_collocated);
}

ACE_INLINE
ImplementationRepository::Administration::Administration (
    IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (ior, oc),
    the_TAO_Administration_Proxy_Broker_ (0)
  
{
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:63

#if !defined (_IMPLEMENTATIONREPOSITORY_SERVERINFORMATIONITERATOR___CI_)
#define _IMPLEMENTATIONREPOSITORY_SERVERINFORMATIONITERATOR___CI_

ACE_INLINE
ImplementationRepository::ServerInformationIterator::ServerInformationIterator (
    TAO_Stub *objref,
    CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (objref, _tao_collocated, servant, oc),
    the_TAO_ServerInformationIterator_Proxy_Broker_ (0)
  
{
  this->ImplementationRepository_ServerInformationIterator_setup_collocation (_tao_collocated);
}

ACE_INLINE
ImplementationRepository::ServerInformationIterator::ServerInformationIterator (
    IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (ior, oc),
    the_TAO_ServerInformationIterator_Proxy_Broker_ (0)
  
{
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/cdr_op_ci.cpp:72

TAO_PortableServer_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const ImplementationRepository::ServerObject_ptr
  );

TAO_PortableServer_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    ImplementationRepository::ServerObject_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/cdr_op_ci.cpp:71

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const ImplementationRepository::AlreadyRegistered &_tao_aggregate
  )
{
  // First marshal the repository ID.
  if (strm << _tao_aggregate._rep_id ())
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &,
    ImplementationRepository::AlreadyRegistered&
  )
{
  return 1;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/cdr_op_ci.cpp:71

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const ImplementationRepository::CannotActivate &_tao_aggregate
  )
{
  // First marshal the repository ID.
  if (strm << _tao_aggregate._rep_id ())
    {
      // Now marshal the members (if any).
      if (
        (strm << _tao_aggregate.reason.in ())
       )
        {
          return 1;
        }
      else
        {
          return 0;
        }
    }
  else
    {
      return 0;
    }
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    ImplementationRepository::CannotActivate &_tao_aggregate
  )
{
  // Demarshal the members.
  if (
    (strm >> _tao_aggregate.reason.out ())
  )
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/cdr_op_ci.cpp:71

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const ImplementationRepository::NotFound &_tao_aggregate
  )
{
  // First marshal the repository ID.
  if (strm << _tao_aggregate._rep_id ())
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &,
    ImplementationRepository::NotFound&
  )
{
  return 1;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ci.cpp:70

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const ImplementationRepository::EnvironmentVariable &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.name.in ()) &&
    (strm << _tao_aggregate.value.in ());
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    ImplementationRepository::EnvironmentVariable &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.name.out ()) &&
    (strm >> _tao_aggregate.value.out ());
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_ImplementationRepository_EnvironmentList_I_
#define _TAO_CDR_OP_ImplementationRepository_EnvironmentList_I_

CORBA::Boolean TAO_PortableServer_Export operator<< (
    TAO_OutputCDR &,
    const ImplementationRepository::EnvironmentList &
  );

CORBA::Boolean TAO_PortableServer_Export operator>> (
    TAO_InputCDR &,
    ImplementationRepository::EnvironmentList &
  );

#endif /* _TAO_CDR_OP_ImplementationRepository_EnvironmentList_I_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_enum/cdr_op_ci.cpp:51

ACE_INLINE
CORBA::Boolean operator<< (TAO_OutputCDR &strm, const ImplementationRepository::ActivationMode &_tao_enumval)
{
  CORBA::ULong _tao_temp = _tao_enumval;
  return strm << _tao_temp;
}

ACE_INLINE
CORBA::Boolean operator>> (TAO_InputCDR &strm, ImplementationRepository::ActivationMode &_tao_enumval)
{
  CORBA::ULong _tao_temp = 0;
  CORBA::Boolean _tao_result = strm >> _tao_temp;
  
  if (_tao_result == 1)
    {
      _tao_enumval = ACE_static_cast (ImplementationRepository::ActivationMode, _tao_temp);
    }
  
  return _tao_result;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ci.cpp:70

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const ImplementationRepository::StartupOptions &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.command_line.in ()) &&
    (strm << _tao_aggregate.environment) &&
    (strm << _tao_aggregate.working_directory.in ()) &&
    (strm << _tao_aggregate.activation) &&
    (strm << _tao_aggregate.location.in ());
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    ImplementationRepository::StartupOptions &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.command_line.out ()) &&
    (strm >> _tao_aggregate.environment) &&
    (strm >> _tao_aggregate.working_directory.out ()) &&
    (strm >> _tao_aggregate.activation) &&
    (strm >> _tao_aggregate.location.out ());
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ci.cpp:70

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const ImplementationRepository::ServerInformation &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.logical_server.in ()) &&
    (strm << _tao_aggregate.server.in ()) &&
    (strm << _tao_aggregate.startup) &&
    (strm << _tao_aggregate.location.in ());
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    ImplementationRepository::ServerInformation &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.logical_server.out ()) &&
    (strm >> _tao_aggregate.server.out ()) &&
    (strm >> _tao_aggregate.startup) &&
    (strm >> _tao_aggregate.location.out ());
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_ImplementationRepository_ServerInformationList_I_
#define _TAO_CDR_OP_ImplementationRepository_ServerInformationList_I_

CORBA::Boolean TAO_PortableServer_Export operator<< (
    TAO_OutputCDR &,
    const ImplementationRepository::ServerInformationList &
  );

CORBA::Boolean TAO_PortableServer_Export operator>> (
    TAO_InputCDR &,
    ImplementationRepository::ServerInformationList &
  );

#endif /* _TAO_CDR_OP_ImplementationRepository_ServerInformationList_I_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface_fwd/cdr_op_ci.cpp:59

TAO_PortableServer_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const ImplementationRepository::ServerInformationIterator_ptr
  );

TAO_PortableServer_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    ImplementationRepository::ServerInformationIterator_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/cdr_op_ci.cpp:72

TAO_PortableServer_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const ImplementationRepository::Administration_ptr
  );

TAO_PortableServer_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    ImplementationRepository::Administration_ptr &
  );


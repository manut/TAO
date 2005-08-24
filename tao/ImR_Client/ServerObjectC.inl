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
// be\be_visitor_interface/interface_ci.cpp:70

#if !defined (_IMPLEMENTATIONREPOSITORY_SERVEROBJECT___CI_)
#define _IMPLEMENTATIONREPOSITORY_SERVEROBJECT___CI_

ACE_INLINE
ImplementationRepository::ServerObject::ServerObject (
    TAO_Stub *objref,
    ::CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (
        objref,
        _tao_collocated,
        servant,
        oc
      ),
    the_TAO_ServerObject_Proxy_Broker_ (0)
{
  this->ImplementationRepository_ServerObject_setup_collocation ();
}

ACE_INLINE
ImplementationRepository::ServerObject::ServerObject (
    IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS ( ::CORBA, Object) (ior, oc),
    the_TAO_ServerObject_Proxy_Broker_ (0)
{
}

#endif /* end #if !defined */

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

#include "DomainC.h"
#include "tao/Typecode.h"
#include "tao/Any_Impl_T.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_CORBA_DomainManager[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  36,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x6f6d672e),
  ACE_NTOHL (0x6f72672f),
  ACE_NTOHL (0x434f5242),
  ACE_NTOHL (0x412f446f),
  ACE_NTOHL (0x6d61696e),
  ACE_NTOHL (0x4d616e61),
  ACE_NTOHL (0x6765723a),
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/DomainManager:1.0
    14,
  ACE_NTOHL (0x446f6d61),
  ACE_NTOHL (0x696e4d61),
  ACE_NTOHL (0x6e616765),
  ACE_NTOHL (0x72000000),  // name = DomainManager
  };

static CORBA::TypeCode _tc_TAO_tc_CORBA_DomainManager (
    CORBA::tk_objref,
    sizeof (_oc_CORBA_DomainManager),
    (char *) &_oc_CORBA_DomainManager,
    0,
    sizeof (CORBA::DomainManager)
  );

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_DomainManager =
    &_tc_TAO_tc_CORBA_DomainManager;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_CORBA_ConstructionPolicy[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  41,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x6f6d672e),
  ACE_NTOHL (0x6f72672f),
  ACE_NTOHL (0x434f5242),
  ACE_NTOHL (0x412f436f),
  ACE_NTOHL (0x6e737472),
  ACE_NTOHL (0x75637469),
  ACE_NTOHL (0x6f6e506f),
  ACE_NTOHL (0x6c696379),
  ACE_NTOHL (0x3a312e30),
  ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/CORBA/ConstructionPolicy:1.0
    19,
  ACE_NTOHL (0x436f6e73),
  ACE_NTOHL (0x74727563),
  ACE_NTOHL (0x74696f6e),
  ACE_NTOHL (0x506f6c69),
  ACE_NTOHL (0x63790000),  // name = ConstructionPolicy
  };

static CORBA::TypeCode _tc_TAO_tc_CORBA_ConstructionPolicy (
    CORBA::tk_objref,
    sizeof (_oc_CORBA_ConstructionPolicy),
    (char *) &_oc_CORBA_ConstructionPolicy,
    0,
    sizeof (CORBA::ConstructionPolicy)
  );

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_ConstructionPolicy =
    &_tc_TAO_tc_CORBA_ConstructionPolicy;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_CORBA_DomainManagerList[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  40,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x6f6d672e),
  ACE_NTOHL (0x6f72672f),
  ACE_NTOHL (0x434f5242),
  ACE_NTOHL (0x412f446f),
  ACE_NTOHL (0x6d61696e),
  ACE_NTOHL (0x4d616e61),
  ACE_NTOHL (0x6765724c),
  ACE_NTOHL (0x6973743a),
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/DomainManagerList:1.0
    18,
  ACE_NTOHL (0x446f6d61),
  ACE_NTOHL (0x696e4d61),
  ACE_NTOHL (0x6e616765),
  ACE_NTOHL (0x724c6973),
  ACE_NTOHL (0x74000000),  // name = DomainManagerList
    CORBA::tk_sequence, // typecode kind
  80, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_objref, // typecode kind
    64, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      36,
      ACE_NTOHL (0x49444c3a),
      ACE_NTOHL (0x6f6d672e),
      ACE_NTOHL (0x6f72672f),
      ACE_NTOHL (0x434f5242),
      ACE_NTOHL (0x412f446f),
      ACE_NTOHL (0x6d61696e),
      ACE_NTOHL (0x4d616e61),
      ACE_NTOHL (0x6765723a),
      ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/DomainManager:1.0
            14,
      ACE_NTOHL (0x446f6d61),
      ACE_NTOHL (0x696e4d61),
      ACE_NTOHL (0x6e616765),
      ACE_NTOHL (0x72000000),  // name = DomainManager

    0U,

};

static CORBA::TypeCode _tc_TAO_tc_CORBA_DomainManagerList (
    CORBA::tk_alias,
    sizeof (_oc_CORBA_DomainManagerList),
    (char *) &_oc_CORBA_DomainManagerList,
    0,
    sizeof (CORBA::DomainManagerList)
  );

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_DomainManagerList =
    &_tc_TAO_tc_CORBA_DomainManagerList;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<CORBA::DomainManager>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::DomainManager_ptr _tao_elem
  )
{
  CORBA::DomainManager_ptr _tao_objptr =
    CORBA::DomainManager::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::DomainManager_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<CORBA::DomainManager>::insert (
      _tao_any,
      CORBA::DomainManager::_tao_any_destructor,
      CORBA::_tc_DomainManager,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::DomainManager_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<CORBA::DomainManager>::extract (
        _tao_any,
        CORBA::DomainManager::_tao_any_destructor,
        CORBA::_tc_DomainManager,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<CORBA::ConstructionPolicy>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ConstructionPolicy_ptr _tao_elem
  )
{
  CORBA::ConstructionPolicy_ptr _tao_objptr =
    CORBA::ConstructionPolicy::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ConstructionPolicy_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<CORBA::ConstructionPolicy>::insert (
      _tao_any,
      CORBA::ConstructionPolicy::_tao_any_destructor,
      CORBA::_tc_ConstructionPolicy,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::ConstructionPolicy_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<CORBA::ConstructionPolicy>::extract (
        _tao_any,
        CORBA::ConstructionPolicy::_tao_any_destructor,
        CORBA::_tc_ConstructionPolicy,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_sequence/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::DomainManagerList &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::DomainManagerList>::insert_copy (
      _tao_any,
      CORBA::DomainManagerList::_tao_any_destructor,
      CORBA::_tc_DomainManagerList,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::DomainManagerList *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::DomainManagerList>::insert (
      _tao_any,
      CORBA::DomainManagerList::_tao_any_destructor,
      CORBA::_tc_DomainManagerList,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::DomainManagerList *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast (
      const CORBA::DomainManagerList *&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::DomainManagerList *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::DomainManagerList>::extract (
        _tao_any,
        CORBA::DomainManagerList::_tao_any_destructor,
        CORBA::_tc_DomainManagerList,
        _tao_elem
      );
}



#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Impl_T<
        CORBA::DomainManager
      >;

  template class
    TAO::Any_Impl_T<
        CORBA::ConstructionPolicy
      >;

  template class
    TAO::Any_Dual_Impl_T<
        CORBA::DomainManagerList
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Impl_T< \
        CORBA::DomainManager \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        CORBA::ConstructionPolicy \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        CORBA::DomainManagerList \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */


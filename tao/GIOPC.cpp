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
// be\be_codegen.cpp:323


#include "GIOPC.h"
#include "tao/CDR.h"
#include "tao/Typecode.h"
#include "tao/Any.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "GIOPC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:64

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_structure/structure_cs.cpp:66

void
GIOP::Version::_tao_any_destructor (
    void *_tao_void_pointer
  )
{
  Version *_tao_tmp_pointer =
    ACE_static_cast (Version *, _tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from
// be\be_visitor_structure/structure_cs.cpp:66

void
GIOP::IORAddressingInfo::_tao_any_destructor (
    void *_tao_void_pointer
  )
{
  IORAddressingInfo *_tao_tmp_pointer =
    ACE_static_cast (IORAddressingInfo *, _tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from
// be\be_visitor_union/union_cs.cpp:91

GIOP::TargetAddress::TargetAddress (void)
{
  ACE_OS::memset (&this->disc_, 0, sizeof (this->disc_));
  ACE_OS::memset (&this->u_, 0, sizeof (this->u_));
  this->disc_ = 0;
}

GIOP::TargetAddress::TargetAddress (const ::GIOP::TargetAddress &u)
{
  this->disc_ = u.disc_;
  switch (this->disc_)
  {
    case 0:
    {
      if (u.u_.object_key_ == 0)
        {
          this->u_.object_key_ = 0;
        }
      else
        {
          ACE_NEW (
              this->u_.object_key_,
              CORBA::OctetSeq (*u.u_.object_key_)
            );
        }
    }
    break;
    case 1:
    {
      if (u.u_.profile_ == 0)
        {
          this->u_.profile_ = 0;
        }
      else
        {
          ACE_NEW (
              this->u_.profile_,
              IOP::TaggedProfile (*u.u_.profile_)
            );
        }
    }
    break;
    case 2:
    {
      if (u.u_.ior_ == 0)
        {
          this->u_.ior_ = 0;
        }
      else
        {
          ACE_NEW (
              this->u_.ior_,
              GIOP::IORAddressingInfo (*u.u_.ior_)
            );
        }
    }
    break;
    default:
    break;
  }
}

GIOP::TargetAddress::~TargetAddress (void)
{
  // Finalize.
  this->_reset (this->disc_, 1);
}

void GIOP::TargetAddress::_tao_any_destructor (void *_tao_void_pointer)
{
  TargetAddress *tmp =
    ACE_static_cast (TargetAddress *, _tao_void_pointer);
  delete tmp;
}

GIOP::TargetAddress &
GIOP::TargetAddress::operator= (const ::GIOP::TargetAddress &u)
{
  if (&u == this)
    {
      return *this;
    }

  this->_reset (u.disc_, 0);
  this->disc_ = u.disc_;

  switch (this->disc_)
  {
    case 0:
    {
      if (u.u_.object_key_ == 0)
        {
          this->u_.object_key_ = 0;
        }
      else
        {
          ACE_NEW_RETURN (
              this->u_.object_key_,
              CORBA::OctetSeq (*u.u_.object_key_),
              *this
            );
        }
    }
    break;
    case 1:
    {
      if (u.u_.profile_ == 0)
        {
          this->u_.profile_ = 0;
        }
      else
        {
          ACE_NEW_RETURN (
              this->u_.profile_,
              IOP::TaggedProfile (*u.u_.profile_),
              *this
            );
        }
    }
    break;
    case 2:
    {
      if (u.u_.ior_ == 0)
        {
          this->u_.ior_ = 0;
        }
      else
        {
          ACE_NEW_RETURN (
              this->u_.ior_,
              GIOP::IORAddressingInfo (*u.u_.ior_),
              *this
            );
        }
    }
    break;
    default:
    break;
  }

  return *this;
}

// Reset method to reset old values of a union.
void GIOP::TargetAddress::_reset (CORBA::Short, CORBA::Boolean /*finalize*/)
{
  switch (this->disc_)
  {
    case 0:
      delete this->u_.object_key_;
      this->u_.object_key_ = 0;
      break;
    case 1:
      delete this->u_.profile_;
      this->u_.profile_ = 0;
      break;
    case 2:
      delete this->u_.ior_;
      this->u_.ior_ = 0;
      break;
    default:
      break;
  }
}

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_cs.cpp:61

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const GIOP::Version &_tao_aggregate
  )
{
  return
    (strm << CORBA::Any::from_octet (_tao_aggregate.major)) &&
    (strm << CORBA::Any::from_octet (_tao_aggregate.minor));
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    GIOP::Version &_tao_aggregate
  )
{
  return
    (strm >> CORBA::Any::to_octet (_tao_aggregate.major)) &&
    (strm >> CORBA::Any::to_octet (_tao_aggregate.minor));
}

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_cs.cpp:61

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const GIOP::IORAddressingInfo &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.selected_profile_index) &&
    (strm << _tao_aggregate.ior);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    GIOP::IORAddressingInfo &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.selected_profile_index) &&
    (strm >> _tao_aggregate.ior);
}

// TAO_IDL - Generated from
// be\be_visitor_union/cdr_op_cs.cpp:67

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const GIOP::TargetAddress &_tao_union
  )
{
  if ( !(strm << _tao_union._d ()) )
    {
      return 0;
    }

  CORBA::Boolean result = 1;

  switch (_tao_union._d ())
  {
    case 0:
      {
        result = strm << _tao_union.object_key ();
      }
      break;
    case 1:
      {
        result = strm << _tao_union.profile ();
      }
      break;
    case 2:
      {
        result = strm << _tao_union.ior ();
      }
      break;
    default:
      break;
  }

  return result;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    GIOP::TargetAddress &_tao_union
  )
{
  CORBA::Short _tao_discriminant;
  if ( !(strm >> _tao_discriminant) )
    {
      return 0;
    }

  CORBA::Boolean result = 1;

  switch (_tao_discriminant)
  {
    case 0:
      {
        CORBA::OctetSeq _tao_union_tmp;
        result = strm >> _tao_union_tmp;

        if (result)
          {
            _tao_union.object_key (_tao_union_tmp);
            _tao_union._d (_tao_discriminant);
          }
      }
      break;
    case 1:
      {
        IOP::TaggedProfile _tao_union_tmp;
        result = strm >> _tao_union_tmp;

        if (result)
          {
            _tao_union.profile (_tao_union_tmp);
            _tao_union._d (_tao_discriminant);
          }
      }
      break;
    case 2:
      {
        GIOP::IORAddressingInfo _tao_union_tmp;
        result = strm >> _tao_union_tmp;

        if (result)
          {
            _tao_union.ior (_tao_union_tmp);
            _tao_union._d (_tao_discriminant);
          }
      }
      break;
    default:
      _tao_union._d (_tao_discriminant);
      break;
  }

  return result;
}

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1628

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO_Fixed_Var_T<
        GIOP::Version
      >;

  template class
    TAO_Var_Base_T<
        GIOP::Version
      >;

  template class
    TAO_Var_Var_T<
        GIOP::IORAddressingInfo
      >;

  template class
    TAO_Var_Base_T<
        GIOP::IORAddressingInfo
      >;

  template class
    TAO_Out_T<
        GIOP::IORAddressingInfo,
        GIOP::IORAddressingInfo_var
      >;

  template class
    TAO_Var_Var_T<
        GIOP::TargetAddress
      >;

  template class
    TAO_Var_Base_T<
        GIOP::TargetAddress
      >;

  template class
    TAO_Out_T<
        GIOP::TargetAddress,
        GIOP::TargetAddress_var
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO_Fixed_Var_T< \
        GIOP::Version \
      >

# pragma instantiate \
    TAO_Var_Base_T< \
        GIOP::Version \
      >

# pragma instantiate \
    TAO_Var_Var_T< \
        GIOP::IORAddressingInfo \
      >

# pragma instantiate \
    TAO_Var_Base_T< \
        GIOP::IORAddressingInfo \
      >

# pragma instantiate \
    TAO_Out_T< \
        GIOP::IORAddressingInfo, \
        GIOP::IORAddressingInfo_var \
      >

# pragma instantiate \
    TAO_Var_Var_T< \
        GIOP::TargetAddress \
      >

# pragma instantiate \
    TAO_Var_Base_T< \
        GIOP::TargetAddress \
      >

# pragma instantiate \
    TAO_Out_T< \
        GIOP::TargetAddress, \
        GIOP::TargetAddress_var \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */


/* -*- C++ -*- */
//$Id$

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "tao/BoundsC.h"
#include "tao/Typecode.h"

#if !defined (__ACE_INLINE__)
#include "tao/BoundsC.i"
#endif /* !defined INLINE */

// default constructor
CORBA_Bounds::CORBA_Bounds (void)
  : CORBA_UserException ("IDL:omg.org/CORBA/Bounds:1.0")
{
}

// destructor - all members are of self managing types
CORBA_Bounds::~CORBA_Bounds (void)
{
}

void CORBA_Bounds::_tao_any_destructor (void *x)
{
  CORBA_Bounds *tmp = ACE_static_cast (CORBA_Bounds*,x);
  delete tmp;
}

// copy constructor
CORBA_Bounds::CORBA_Bounds (const CORBA::Bounds &_tao_excp)
  : CORBA_UserException (_tao_excp._id ())
{
}

// assignment operator
CORBA_Bounds&
CORBA_Bounds::operator= (const CORBA_Bounds &_tao_excp)
{

  this->CORBA_UserException::operator= (_tao_excp);
  return *this;
}

// narrow
CORBA_Bounds_ptr
CORBA_Bounds::_downcast (CORBA_Exception *exc)
{
  if (!ACE_OS::strcmp ("IDL:omg.org/CORBA/Bounds:1.0", exc->_id ())) // same type
    return ACE_dynamic_cast (CORBA_Bounds_ptr, exc);
  else
    return 0;
}


void CORBA_Bounds::_raise ()
{
  TAO_RAISE(*this);
}

void CORBA_Bounds::_tao_encode (TAO_OutputCDR &cdr
                                TAO_ENV_ARG_DECL) const
{
  if (cdr << *this)
    return;
  ACE_THROW (CORBA::MARSHAL ());
}

void CORBA_Bounds::_tao_decode (TAO_InputCDR &cdr
                                TAO_ENV_ARG_DECL)
{
  if (cdr >> *this)
    return;
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the _alloc method
CORBA::Exception *CORBA_Bounds::_alloc (void)
{
  CORBA::Exception *retval = 0;

  ACE_NEW_RETURN (retval,
                  CORBA_Bounds,
                  0);

  return retval;
}

CORBA::TypeCode_ptr
CORBA_Bounds::_type (void) const
{
  return CORBA::TypeCode::_tc_Bounds;
}

void operator<<= (CORBA::Any &_tao_any, const CORBA::Bounds &_tao_elem)
{
  TAO_OutputCDR stream;
  stream << _tao_elem;
  _tao_any._tao_replace (CORBA::_tc_Bounds,
                         TAO_ENCAP_BYTE_ORDER,
                         stream.begin ());
}

void operator<<= (CORBA::Any &_tao_any, CORBA::Bounds *_tao_elem) // non copying
{
  TAO_OutputCDR stream;
  stream << *_tao_elem;
  _tao_any._tao_replace (CORBA::_tc_Bounds,
                         TAO_ENCAP_BYTE_ORDER,
                         stream.begin (),
                         1,
                         _tao_elem,
                         CORBA::Bounds::_tao_any_destructor);
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, CORBA::Bounds *&_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equal (CORBA::_tc_Bounds TAO_ENV_ARG_PARAMETER)) return 0; // not equal
    ACE_TRY_CHECK;
    if (_tao_any.any_owns_data ())
    {
      _tao_elem = (CORBA::Bounds *)_tao_any.value ();
      return 1;
    }
    else
    {
      ACE_NEW_RETURN (_tao_elem, CORBA::Bounds, 0);
      TAO_InputCDR stream (
          _tao_any._tao_get_cdr (),
          _tao_any._tao_byte_order ());
      if (stream >> *_tao_elem)
      {
        ((CORBA::Any *)&_tao_any)->_tao_replace (
            CORBA::_tc_Bounds,
            1,
            ACE_reinterpret_cast (void*, _tao_elem),
            CORBA::Bounds::_tao_any_destructor);
        return 1;
      }
      else
      {
        delete _tao_elem;
        _tao_elem = 0;
      }
    }
  }
  ACE_CATCHANY
  {
    delete _tao_elem;
    _tao_elem = 0;
    return 0;
  }
  ACE_ENDTRY;
  return 0;
}

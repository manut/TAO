//$Id$
/* -*- C++ -*- */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "tao/Services.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Environment.h"
#include "tao/Typecode.h"
#include "tao/ORB_Core.h"

#if !defined (__ACE_INLINE__)
#include "Services.i"
#endif /* !defined INLINE */


#if !defined (_CORBA_SERVICEDETAIL__TAO_SEQ_OCTET_CS_)
#define _CORBA_SERVICEDETAIL__TAO_SEQ_OCTET_CS_

// *************************************************************
// CORBA::ServiceDetail::_tao_seq_Octet
// *************************************************************

CORBA::ServiceDetail::_tao_seq_Octet::_tao_seq_Octet (void)
{}
CORBA::ServiceDetail::_tao_seq_Octet::_tao_seq_Octet (CORBA::ULong max) // uses max size
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  TAO_Unbounded_Sequence<CORBA::Octet>
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<CORBA::Octet>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (max)
{}
CORBA::ServiceDetail::_tao_seq_Octet::_tao_seq_Octet (CORBA::ULong max, CORBA::ULong length, CORBA::Octet *buffer, CORBA::Boolean release)
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  TAO_Unbounded_Sequence<CORBA::Octet>
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<CORBA::Octet>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (max, length, buffer, release)
{}
CORBA::ServiceDetail::_tao_seq_Octet::_tao_seq_Octet (const _tao_seq_Octet &seq) // copy ctor
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  TAO_Unbounded_Sequence<CORBA::Octet>
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<CORBA::Octet>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (seq)
{}
CORBA::ServiceDetail::_tao_seq_Octet::~_tao_seq_Octet (void) // dtor
{}

static const CORBA::Long _oc_CORBA_ServiceDetail__tao_seq_Octet[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_octet,

  0,
};
static CORBA::TypeCode _tc_TAO_tc_CORBA_ServiceDetail__tao_seq_Octet (CORBA::tk_sequence, sizeof (_oc_CORBA_ServiceDetail__tao_seq_Octet), (char *) &_oc_CORBA_ServiceDetail__tao_seq_Octet, 0, sizeof (CORBA::ServiceDetail::_tao_seq_Octet));
CORBA::TypeCode_ptr CORBA::ServiceDetail::_tc__tao_seq_Octet = &_tc_TAO_tc_CORBA_ServiceDetail__tao_seq_Octet;


#endif /* end #if !defined */


#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_SEQUENCE_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEOPTION_CS_)
#define __TAO_UNBOUNDED_SEQUENCE_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEOPTION_CS_

  void
  CORBA::ServiceInformation::_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption::_allocate_buffer (CORBA::ULong length)
  {
    CORBA::ULong* tmp = CORBA::ServiceInformation::_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption::allocbuf (length);

    if (this->buffer_ != 0)
    {
      CORBA::ULong *old = ACE_reinterpret_cast (CORBA::ULong *,this->buffer_);

      for (CORBA::ULong i = 0; i < this->length_; ++i)
        tmp[i] = old[i];

      if (this->release_)
        CORBA::ServiceInformation::_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption::freebuf (old);

    }
    this->buffer_ = tmp;
  }

  void
  CORBA::ServiceInformation::_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption::_deallocate_buffer (void)
  {
    if (this->buffer_ == 0 || this->release_ == 0)
      return;

    CORBA::ULong *tmp = ACE_reinterpret_cast (CORBA::ULong *,this->buffer_);

    CORBA::ServiceInformation::_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption::freebuf (tmp);
    this->buffer_ = 0;
  }

  CORBA::ServiceInformation::_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption::~_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption (void) // Dtor.
  {
    this->_deallocate_buffer ();
  }


#endif /* end #if !defined */


#endif /* !TAO_USE_SEQUENCE_TEMPLATES */

#if !defined (_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEOPTION_CS_)
#define _CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEOPTION_CS_

// *************************************************************
// CORBA::ServiceInformation::_tao_seq_ServiceOption
// *************************************************************

CORBA::ServiceInformation::_tao_seq_ServiceOption::_tao_seq_ServiceOption (void)
{}
CORBA::ServiceInformation::_tao_seq_ServiceOption::_tao_seq_ServiceOption (CORBA::ULong max) // uses max size
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<CORBA::ULong>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (max)
{}
CORBA::ServiceInformation::_tao_seq_ServiceOption::_tao_seq_ServiceOption (CORBA::ULong max, CORBA::ULong length, CORBA::ULong *buffer, CORBA::Boolean release)
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<CORBA::ULong>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (max, length, buffer, release)
{}
CORBA::ServiceInformation::_tao_seq_ServiceOption::_tao_seq_ServiceOption (const _tao_seq_ServiceOption &seq) // copy ctor
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<CORBA::ULong>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (seq)
{}
CORBA::ServiceInformation::_tao_seq_ServiceOption::~_tao_seq_ServiceOption (void) // dtor
{}


#endif /* end #if !defined */


#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_SEQUENCE_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEDETAIL_CS_)
#define __TAO_UNBOUNDED_SEQUENCE_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEDETAIL_CS_

  void
  CORBA::ServiceInformation::_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail::_allocate_buffer (CORBA::ULong length)
  {
    CORBA::ServiceDetail* tmp = CORBA::ServiceInformation::_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail::allocbuf (length);

    if (this->buffer_ != 0)
    {
      CORBA::ServiceDetail *old = ACE_reinterpret_cast (CORBA::ServiceDetail *,this->buffer_);

      for (CORBA::ULong i = 0; i < this->length_; ++i)
        tmp[i] = old[i];

      if (this->release_)
        CORBA::ServiceInformation::_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail::freebuf (old);

    }
    this->buffer_ = tmp;
  }

  void
  CORBA::ServiceInformation::_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail::_deallocate_buffer (void)
  {
    if (this->buffer_ == 0 || this->release_ == 0)
      return;

    CORBA::ServiceDetail *tmp = ACE_reinterpret_cast (CORBA::ServiceDetail *,this->buffer_);

    CORBA::ServiceInformation::_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail::freebuf (tmp);
    this->buffer_ = 0;
  }

  CORBA::ServiceInformation::_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail::~_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail (void) // Dtor.
  {
    this->_deallocate_buffer ();
  }


#endif /* end #if !defined */


#endif /* !TAO_USE_SEQUENCE_TEMPLATES */

#if !defined (_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEDETAIL_CS_)
#define _CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEDETAIL_CS_

// *************************************************************
// CORBA::ServiceInformation::_tao_seq_ServiceDetail
// *************************************************************

CORBA::ServiceInformation::_tao_seq_ServiceDetail::_tao_seq_ServiceDetail (void)
{}
CORBA::ServiceInformation::_tao_seq_ServiceDetail::_tao_seq_ServiceDetail (CORBA::ULong max) // uses max size
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<CORBA::ServiceDetail>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (max)
{}
CORBA::ServiceInformation::_tao_seq_ServiceDetail::_tao_seq_ServiceDetail (CORBA::ULong max, CORBA::ULong length, CORBA::ServiceDetail *buffer, CORBA::Boolean release)
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<CORBA::ServiceDetail>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (max, length, buffer, release)
{}
CORBA::ServiceInformation::_tao_seq_ServiceDetail::_tao_seq_ServiceDetail (const _tao_seq_ServiceDetail &seq) // copy ctor
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<CORBA::ServiceDetail>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (seq)
{}
CORBA::ServiceInformation::_tao_seq_ServiceDetail::~_tao_seq_ServiceDetail (void) // dtor
{}


#endif /* end #if !defined */

void operator<<= (CORBA::Any &_tao_any, const CORBA::ServiceDetail &_tao_elem)
{
  TAO_OutputCDR stream;
  stream << _tao_elem;

  _tao_any._tao_replace (CORBA::_tc_ServiceDetail,
                         TAO_ENCAP_BYTE_ORDER,
                         stream.begin ());
}

void CORBA::ServiceDetail::_tao_any_destructor (void *x)
{
  CORBA::ServiceDetail *tmp = ACE_static_cast(CORBA::ServiceDetail*,x);
  delete tmp;
}

void operator<<= (CORBA::Any &_tao_any, CORBA::ServiceDetail *_tao_elem) // non copying
{
  TAO_OutputCDR stream;
  stream << *_tao_elem;

  _tao_any._tao_replace (CORBA::_tc_ServiceDetail,
                         TAO_ENCAP_BYTE_ORDER,
                         stream.begin (),
                         1,
                         _tao_elem,
                         CORBA::ServiceDetail::_tao_any_destructor);
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, CORBA::ServiceDetail *&_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equal (CORBA::_tc_ServiceDetail ACE_ENV_ARG_PARAMETER)) return 0; // not equal
    ACE_TRY_CHECK;
    if (_tao_any.any_owns_data ())
    {
      _tao_elem = (CORBA::ServiceDetail *)_tao_any.value ();
      return 1;
      }
    else
    {
      ACE_NEW_RETURN (_tao_elem, CORBA::ServiceDetail, 0);
      TAO_InputCDR stream (_tao_any._tao_get_cdr (),
                           _tao_any._tao_byte_order ());
      if (stream >> *_tao_elem)
      {
        ((CORBA::Any *)&_tao_any)->_tao_replace (
            CORBA::_tc_ServiceDetail,
            1,
            _tao_elem,
            CORBA::ServiceDetail::_tao_any_destructor);
        return 1;
      }
      else
      {
        delete _tao_elem;
      }
    }
  }
  ACE_CATCHANY
  {
    delete _tao_elem;
    return 0;
  }
  ACE_ENDTRY;
  return 0;
}

void operator<<= (CORBA::Any &_tao_any, const CORBA::ServiceInformation &_tao_elem) // copying
{
  TAO_OutputCDR stream;
  stream << _tao_elem;

  _tao_any._tao_replace (CORBA::_tc_ServiceInformation,
                         TAO_ENCAP_BYTE_ORDER,
                         stream.begin ());
}

void CORBA::ServiceInformation::_tao_any_destructor (void *x)
{
  CORBA::ServiceInformation *tmp = ACE_static_cast(CORBA::ServiceInformation*,x);
  delete tmp;
}

void operator<<= (CORBA::Any &_tao_any, CORBA::ServiceInformation *_tao_elem) // non copying
{
    TAO_OutputCDR stream;
    stream << *_tao_elem;
    _tao_any._tao_replace (CORBA::_tc_ServiceInformation,
                           TAO_ENCAP_BYTE_ORDER,
                           stream.begin (),
                           1,
                           _tao_elem,
                           CORBA::ServiceInformation::_tao_any_destructor);
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, CORBA::ServiceInformation *&_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equal (CORBA::_tc_ServiceInformation ACE_ENV_ARG_PARAMETER)) return 0; // not equal
    ACE_TRY_CHECK;
    if (_tao_any.any_owns_data ())
    {
      _tao_elem = (CORBA::ServiceInformation *)_tao_any.value ();
      return 1;
      }
    else
    {
      ACE_NEW_RETURN (_tao_elem, CORBA::ServiceInformation, 0);
      TAO_InputCDR stream (_tao_any._tao_get_cdr (),
                           _tao_any._tao_byte_order ());
      if (stream >> *_tao_elem)
      {
        ((CORBA::Any *)&_tao_any)->_tao_replace (
            CORBA::_tc_ServiceInformation,
            1,
            _tao_elem,
            CORBA::ServiceInformation::_tao_any_destructor);
        return 1;
      }
      else
      {
        delete _tao_elem;
      }
    }
  }
  ACE_CATCHANY
  {
    delete _tao_elem;
    return 0;
  }
  ACE_ENDTRY;
  return 0;
}

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA_ServiceDetail::_tao_seq_Octet &_tao_sequence
  )
{
  if (strm << _tao_sequence.length ())
  {
    // encode all elements

#if (TAO_NO_COPY_OCTET_SEQUENCES == 1)
    {
      TAO_Unbounded_Sequence<CORBA::Octet> *oseq =
        ACE_dynamic_cast (TAO_Unbounded_Sequence<CORBA::Octet>*, (CORBA_ServiceDetail::_tao_seq_Octet *)&_tao_sequence);
      if (oseq->mb ())
        return strm.write_octet_array_mb (oseq->mb ());
      else
        return strm.write_octet_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
    }

#else /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
    return strm.write_octet_array (_tao_sequence.get_buffer (), _tao_sequence.length ());

#endif /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
  }
  return 0; // error
}

CORBA::Boolean operator>> (TAO_InputCDR &strm, CORBA_ServiceDetail::_tao_seq_Octet &_tao_sequence)
{
  CORBA::ULong _tao_seq_len;
  if (strm >> _tao_seq_len)
  {
    // set the length of the sequence
    _tao_sequence.length (_tao_seq_len);
    // retrieve all the elements

#if (TAO_NO_COPY_OCTET_SEQUENCES == 1)
    if (ACE_BIT_DISABLED (strm.start ()->flags (),
                          ACE_Message_Block::DONT_DELETE))
      {
        TAO_ORB_Core* orb_core = strm.orb_core ();

        if (orb_core != 0 &&
            strm.orb_core ()->resource_factory ()->
            input_cdr_allocator_type_locked () == 1)
          {
            TAO_Unbounded_Sequence<CORBA::Octet> *oseq =
              ACE_static_cast(TAO_Unbounded_Sequence<CORBA::Octet>*, &_tao_sequence);
            oseq->replace (_tao_seq_len, strm.start ());
            oseq->mb ()->wr_ptr (oseq->mb()->rd_ptr () + _tao_seq_len);
            strm.skip_bytes (_tao_seq_len);
            return 1;
          }
      }

    return strm.read_octet_array (_tao_sequence.get_buffer (), _tao_seq_len);

#else /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
    return strm.read_octet_array (_tao_sequence.get_buffer (), _tao_sequence.length ());

#endif /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
  }
  return 0; // error
}

CORBA::Boolean
operator<< (TAO_OutputCDR &strm, const CORBA_ServiceDetail &_tao_aggregate)
{
  if (
    (strm << _tao_aggregate.service_detail_type) &&
    (strm << _tao_aggregate.service_detail)
  )
    return 1;
  else
    return 0;

}

CORBA::Boolean
operator>> (TAO_InputCDR &strm, CORBA_ServiceDetail &_tao_aggregate)
{
  if (
    (strm >> _tao_aggregate.service_detail_type) &&
    (strm >> _tao_aggregate.service_detail)
  )
    return 1;
  else
    return 0;

}

CORBA::Boolean
operator<< (
            TAO_OutputCDR &strm,
            const CORBA_ServiceInformation::_tao_seq_ServiceOption &_tao_sequence
            )
{
  if (strm << _tao_sequence.length ())
  {
    // encode all elements
    return strm.write_ulong_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
  }
  return 0; // error
}

CORBA::Boolean
operator>> (TAO_InputCDR &strm,
            CORBA_ServiceInformation::_tao_seq_ServiceOption &_tao_sequence)
{
  CORBA::ULong _tao_seq_len;
  if (strm >> _tao_seq_len)
  {
    // set the length of the sequence
    _tao_sequence.length (_tao_seq_len);
    // retrieve all the elements
    return strm.read_ulong_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
  }
  return 0; // error
}

CORBA::Boolean
operator<< (
            TAO_OutputCDR &strm,
            const CORBA_ServiceInformation::_tao_seq_ServiceDetail &_tao_sequence
            )
{
  if (strm << _tao_sequence.length ())
  {
    // encode all elements
    CORBA::Boolean _tao_marshal_flag = 1;
    for (CORBA::ULong i = 0; i < _tao_sequence.length () && _tao_marshal_flag; i++)
      _tao_marshal_flag = (strm << _tao_sequence[i]);
    return _tao_marshal_flag;
  }
  return 0; // error
}

CORBA::Boolean
operator>> (TAO_InputCDR &strm,
            CORBA_ServiceInformation::_tao_seq_ServiceDetail &_tao_sequence)
{
  CORBA::ULong _tao_seq_len;
  if (strm >> _tao_seq_len)
  {
    // set the length of the sequence
    _tao_sequence.length (_tao_seq_len);
    // retrieve all the elements
    CORBA::Boolean _tao_marshal_flag = 1;
    for (CORBA::ULong i = 0; i < _tao_sequence.length () && _tao_marshal_flag; i++)
      _tao_marshal_flag = (strm >> _tao_sequence[i]);
    return _tao_marshal_flag;
  }
  return 0; // error
}

CORBA::Boolean
operator<< (TAO_OutputCDR &strm,
            const CORBA_ServiceInformation &_tao_aggregate)
{
  if (
    (strm << _tao_aggregate.service_options) &&
    (strm << _tao_aggregate.service_details)
  )
    return 1;
  else
    return 0;

}

CORBA::Boolean operator>> (TAO_InputCDR &strm,
                           CORBA_ServiceInformation &_tao_aggregate)
{
  if (
    (strm >> _tao_aggregate.service_options) &&
    (strm >> _tao_aggregate.service_details)
  )
    return 1;
  else
    return 0;

}

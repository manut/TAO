/* -*- C++ -*- $Id$ */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#ifndef _TAO_IDL_TAOC_H_
#define _TAO_IDL_TAOC_H_

#include "tao/orbconf.h"
#include "tao/varout.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if (TAO_HAS_CORBA_MESSAGING == 1)

#include "tao/PolicyC.h"
#include "tao/TimeBaseC.h"

#endif /* TAO_HAS_CORBA_MESSAGING == 1 */

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export
#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_Export
#endif /* TAO_EXPORT_NESTED_CLASSES */
#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

TAO_NAMESPACE  TAO
{

#if (TAO_HAS_CORBA_MESSAGING == 1)

  typedef CORBA::Short PrioritySelectionMode;
  typedef CORBA::Short_out PrioritySelectionMode_out;
    TAO_NAMESPACE_STORAGE_CLASS CORBA::TypeCode_ptr _tc_PrioritySelectionMode;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::Short USE_NO_PRIORITY;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::Short USE_THREAD_PRIORITY;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::Short USE_PRIORITY_RANGE;

  struct TAO_Export PrioritySpecification
  {
    ACE_NESTED_CLASS (TAO, PrioritySelectionMode) mode;
    CORBA::Short min_priority;
    CORBA::Short max_priority;
  };

  class TAO_Export PrioritySpecification_var
  {
  public:
    PrioritySpecification_var (void); // default constructor
    PrioritySpecification_var (PrioritySpecification *);
    PrioritySpecification_var (const PrioritySpecification_var &); // copy constructor
    ~PrioritySpecification_var (void); // destructor

    PrioritySpecification_var &operator= (PrioritySpecification *);
    PrioritySpecification_var &operator= (const PrioritySpecification_var &);
    PrioritySpecification *operator-> (void);
    const PrioritySpecification *operator-> (void) const;

    operator const PrioritySpecification &() const;
    operator PrioritySpecification &();
    operator PrioritySpecification &() const;
    // in, inout, out, _retn
    const PrioritySpecification &in (void) const;
    PrioritySpecification &inout (void);
    PrioritySpecification &out (void);
    PrioritySpecification _retn (void);
    PrioritySpecification *ptr (void) const;

  private:
    PrioritySpecification *ptr_;
  };

  typedef PrioritySpecification &PrioritySpecification_out;

  TAO_NAMESPACE_STORAGE_CLASS CORBA::TypeCode_ptr _tc_PrioritySpecification;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong CLIENT_PRIORITY_POLICY_TYPE;


#if !defined (_TAO_CLIENTPRIORITYPOLICY___PTR_CH_)
#define _TAO_CLIENTPRIORITYPOLICY___PTR_CH_

  class ClientPriorityPolicy;
  typedef ClientPriorityPolicy *ClientPriorityPolicy_ptr;

#endif /* end #if !defined */


#if !defined (_TAO_CLIENTPRIORITYPOLICY___VAR_CH_)
#define _TAO_CLIENTPRIORITYPOLICY___VAR_CH_

  class TAO_Export ClientPriorityPolicy_var
  {
  public:
    ClientPriorityPolicy_var (void); // default constructor
    ClientPriorityPolicy_var (ClientPriorityPolicy_ptr);
    ClientPriorityPolicy_var (const ClientPriorityPolicy_var &); // copy constructor
    ~ClientPriorityPolicy_var (void); // destructor

    ClientPriorityPolicy_var &operator= (ClientPriorityPolicy_ptr);
    ClientPriorityPolicy_var &operator= (const ClientPriorityPolicy_var &);
    ClientPriorityPolicy_ptr operator-> (void) const;

    operator const ClientPriorityPolicy_ptr &() const;
    operator ClientPriorityPolicy_ptr &();
    // in, inout, out, _retn
    ClientPriorityPolicy_ptr in (void) const;
    ClientPriorityPolicy_ptr &inout (void);
    ClientPriorityPolicy_ptr &out (void);
    ClientPriorityPolicy_ptr _retn (void);
    ClientPriorityPolicy_ptr ptr (void) const;

  private:
    ClientPriorityPolicy_ptr ptr_;
  };


#endif /* end #if !defined */


#if !defined (_TAO_CLIENTPRIORITYPOLICY___OUT_CH_)
#define _TAO_CLIENTPRIORITYPOLICY___OUT_CH_

  class TAO_Export ClientPriorityPolicy_out
  {
  public:
    ClientPriorityPolicy_out (ClientPriorityPolicy_ptr &);
    ClientPriorityPolicy_out (ClientPriorityPolicy_var &);
    ClientPriorityPolicy_out (const ClientPriorityPolicy_out &);
    ClientPriorityPolicy_out &operator= (const ClientPriorityPolicy_out &);
    ClientPriorityPolicy_out &operator= (const ClientPriorityPolicy_var &);
    ClientPriorityPolicy_out &operator= (ClientPriorityPolicy_ptr);
    operator ClientPriorityPolicy_ptr &();
    ClientPriorityPolicy_ptr &ptr (void);
    ClientPriorityPolicy_ptr operator-> (void);

  private:
    ClientPriorityPolicy_ptr &ptr_;
  };


#endif /* end #if !defined */


#if !defined (_TAO_CLIENTPRIORITYPOLICY_CH_)
#define _TAO_CLIENTPRIORITYPOLICY_CH_

class TAO_Export ClientPriorityPolicy: public virtual CORBA::Policy
  {
  public:
  #if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
    typedef ClientPriorityPolicy_ptr _ptr_type;
    typedef ClientPriorityPolicy_var _var_type;
  #endif /* ! __GNUC__ || g++ >= 2.8 */

    // the static operations
    static ClientPriorityPolicy_ptr _duplicate (ClientPriorityPolicy_ptr obj);
    static ClientPriorityPolicy_ptr _narrow (
        CORBA::Object_ptr obj,
        CORBA::Environment &env =
          TAO_default_environment ()
      );
    static ClientPriorityPolicy_ptr _unchecked_narrow (
        CORBA::Object_ptr obj,
        CORBA::Environment &env =
          TAO_default_environment ()
      );
    static ClientPriorityPolicy_ptr _nil (void)
      {
        return (TAO::ClientPriorityPolicy_ptr)0;
      }

    virtual ACE_NESTED_CLASS (TAO, PrioritySpecification) priority_specification (
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      ) = 0;

    virtual CORBA::Boolean _is_a (
        const CORBA::Char *type_id,
        CORBA::Environment &env =
          TAO_default_environment ()
      );
    virtual const char* _interface_repository_id (void) const;

  protected:
    ClientPriorityPolicy (void);
    ClientPriorityPolicy (TAO_Stub *objref,
        TAO_ServantBase *_tao_servant = 0,
        CORBA::Boolean _tao_collocated = 0
      );
    virtual ~ClientPriorityPolicy (void);
  private:
    ClientPriorityPolicy (const ClientPriorityPolicy &);
    void operator= (const ClientPriorityPolicy &);
  };


#endif /* end #if !defined */

  TAO_NAMESPACE_STORAGE_CLASS CORBA::TypeCode_ptr _tc_ClientPriorityPolicy;

  typedef CORBA::UShort BufferingConstraintMode;
  typedef CORBA::UShort_out BufferingConstraintMode_out;
    TAO_NAMESPACE_STORAGE_CLASS CORBA::TypeCode_ptr _tc_BufferingConstraintMode;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::UShort BUFFER_FLUSH;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::UShort BUFFER_TIMEOUT;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::UShort BUFFER_MESSAGE_COUNT;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::UShort BUFFER_MESSAGE_BYTES;

  struct TAO_Export BufferingConstraint
  {
    ACE_NESTED_CLASS (TAO, BufferingConstraintMode) mode;
    TimeBase::TimeT timeout;
    CORBA::ULong message_count;
    CORBA::ULong message_bytes;
  };

  class TAO_Export BufferingConstraint_var
  {
  public:
    BufferingConstraint_var (void); // default constructor
    BufferingConstraint_var (BufferingConstraint *);
    BufferingConstraint_var (const BufferingConstraint_var &); // copy constructor
    ~BufferingConstraint_var (void); // destructor

    BufferingConstraint_var &operator= (BufferingConstraint *);
    BufferingConstraint_var &operator= (const BufferingConstraint_var &);
    BufferingConstraint *operator-> (void);
    const BufferingConstraint *operator-> (void) const;

    operator const BufferingConstraint &() const;
    operator BufferingConstraint &();
    operator BufferingConstraint &() const;
    // in, inout, out, _retn
    const BufferingConstraint &in (void) const;
    BufferingConstraint &inout (void);
    BufferingConstraint &out (void);
    BufferingConstraint _retn (void);
    BufferingConstraint *ptr (void) const;

  private:
    BufferingConstraint *ptr_;
  };

  typedef BufferingConstraint &BufferingConstraint_out;

  TAO_NAMESPACE_STORAGE_CLASS CORBA::TypeCode_ptr _tc_BufferingConstraint;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong BUFFERING_CONSTRAINT_POLICY_TYPE;


#if !defined (_TAO_BUFFERINGCONSTRAINTPOLICY___PTR_CH_)
#define _TAO_BUFFERINGCONSTRAINTPOLICY___PTR_CH_

  class BufferingConstraintPolicy;
  typedef BufferingConstraintPolicy *BufferingConstraintPolicy_ptr;

#endif /* end #if !defined */


#if !defined (_TAO_BUFFERINGCONSTRAINTPOLICY___VAR_CH_)
#define _TAO_BUFFERINGCONSTRAINTPOLICY___VAR_CH_

  class TAO_Export BufferingConstraintPolicy_var
  {
  public:
    BufferingConstraintPolicy_var (void); // default constructor
    BufferingConstraintPolicy_var (BufferingConstraintPolicy_ptr);
    BufferingConstraintPolicy_var (const BufferingConstraintPolicy_var &); // copy constructor
    ~BufferingConstraintPolicy_var (void); // destructor

    BufferingConstraintPolicy_var &operator= (BufferingConstraintPolicy_ptr);
    BufferingConstraintPolicy_var &operator= (const BufferingConstraintPolicy_var &);
    BufferingConstraintPolicy_ptr operator-> (void) const;

    operator const BufferingConstraintPolicy_ptr &() const;
    operator BufferingConstraintPolicy_ptr &();
    // in, inout, out, _retn
    BufferingConstraintPolicy_ptr in (void) const;
    BufferingConstraintPolicy_ptr &inout (void);
    BufferingConstraintPolicy_ptr &out (void);
    BufferingConstraintPolicy_ptr _retn (void);
    BufferingConstraintPolicy_ptr ptr (void) const;

  private:
    BufferingConstraintPolicy_ptr ptr_;
  };


#endif /* end #if !defined */


#if !defined (_TAO_BUFFERINGCONSTRAINTPOLICY___OUT_CH_)
#define _TAO_BUFFERINGCONSTRAINTPOLICY___OUT_CH_

  class TAO_Export BufferingConstraintPolicy_out
  {
  public:
    BufferingConstraintPolicy_out (BufferingConstraintPolicy_ptr &);
    BufferingConstraintPolicy_out (BufferingConstraintPolicy_var &);
    BufferingConstraintPolicy_out (const BufferingConstraintPolicy_out &);
    BufferingConstraintPolicy_out &operator= (const BufferingConstraintPolicy_out &);
    BufferingConstraintPolicy_out &operator= (const BufferingConstraintPolicy_var &);
    BufferingConstraintPolicy_out &operator= (BufferingConstraintPolicy_ptr);
    operator BufferingConstraintPolicy_ptr &();
    BufferingConstraintPolicy_ptr &ptr (void);
    BufferingConstraintPolicy_ptr operator-> (void);

  private:
    BufferingConstraintPolicy_ptr &ptr_;
  };


#endif /* end #if !defined */


#if !defined (_TAO_BUFFERINGCONSTRAINTPOLICY_CH_)
#define _TAO_BUFFERINGCONSTRAINTPOLICY_CH_

class TAO_Export BufferingConstraintPolicy: public virtual CORBA::Policy
  {
  public:
  #if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
    typedef BufferingConstraintPolicy_ptr _ptr_type;
    typedef BufferingConstraintPolicy_var _var_type;
  #endif /* ! __GNUC__ || g++ >= 2.8 */

    // the static operations
    static BufferingConstraintPolicy_ptr _duplicate (BufferingConstraintPolicy_ptr obj);
    static BufferingConstraintPolicy_ptr _narrow (
        CORBA::Object_ptr obj,
        CORBA::Environment &env =
          TAO_default_environment ()
      );
    static BufferingConstraintPolicy_ptr _unchecked_narrow (
        CORBA::Object_ptr obj,
        CORBA::Environment &env =
          TAO_default_environment ()
      );
    static BufferingConstraintPolicy_ptr _nil (void)
      {
        return (TAO::BufferingConstraintPolicy_ptr)0;
      }

    virtual ACE_NESTED_CLASS (TAO, BufferingConstraint) buffering_constraint (
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      ) = 0;

    virtual CORBA::Boolean _is_a (
        const CORBA::Char *type_id,
        CORBA::Environment &env =
          TAO_default_environment ()
      );
    virtual const char* _interface_repository_id (void) const;

  protected:
    BufferingConstraintPolicy (void);
    BufferingConstraintPolicy (TAO_Stub *objref,
        TAO_ServantBase *_tao_servant = 0,
        CORBA::Boolean _tao_collocated = 0
      );
    virtual ~BufferingConstraintPolicy (void);
  private:
    BufferingConstraintPolicy (const BufferingConstraintPolicy &);
    void operator= (const BufferingConstraintPolicy &);
  };


#endif /* end #if !defined */

  TAO_NAMESPACE_STORAGE_CLASS CORBA::TypeCode_ptr _tc_BufferingConstraintPolicy;


#endif /* TAO_HAS_CORBA_MESSAGING == 1 */

  // It seems easier to have copies of these here than to use
  // #if (TAO_HAS_CORBA_MESSAGING == 1) everywhere or to
  // define a new class TAO_GIOP_Reliable_Oneway_Invocation
  typedef CORBA::Short SyncScope;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::Short SYNC_NONE;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::Short SYNC_WITH_TRANSPORT;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::Short SYNC_WITH_SERVER;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::Short SYNC_WITH_TARGET;
}
TAO_NAMESPACE_CLOSE // module TAO

#if (TAO_HAS_CORBA_MESSAGING == 1)

TAO_Export void operator<<= (CORBA::Any &, const TAO::PrioritySpecification &); // copying version
TAO_Export void operator<<= (CORBA::Any &, TAO::PrioritySpecification*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, TAO::PrioritySpecification *&);
// Any operators for interface TAO::ClientPriorityPolicy
TAO_Export void operator<<= (CORBA::Any &, TAO::ClientPriorityPolicy_ptr);
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, TAO::ClientPriorityPolicy *&);
TAO_Export void operator<<= (CORBA::Any &, const TAO::BufferingConstraint &); // copying version
TAO_Export void operator<<= (CORBA::Any &, TAO::BufferingConstraint*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, TAO::BufferingConstraint *&);
// Any operators for interface TAO::BufferingConstraintPolicy
void  operator<<= (CORBA::Any &, TAO::BufferingConstraintPolicy_ptr);
CORBA::Boolean  operator>>= (const CORBA::Any &, TAO::BufferingConstraintPolicy *&);

#endif /* TAO_HAS_CORBA_MESSAGING == 1 */

#ifndef __ACE_INLINE__

#if (TAO_HAS_CORBA_MESSAGING == 1)

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const TAO::PrioritySpecification &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, TAO::PrioritySpecification &);
TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const TAO::BufferingConstraint &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, TAO::BufferingConstraint &);

#endif /* TAO_HAS_CORBA_MESSAGING == 1 */

#endif /* __ACE_INLINE__ */


#if defined (__ACE_INLINE__)
#include "tao/TAOC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#endif /* ifndef */

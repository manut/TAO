/* -*- C++ -*- */
//
// $Id$
//
// ================================================================
//
// = LIBRARY
//   TAO
//
// = FILENAME
//   IOPC.h
//
// = DESCRIPTION
//   Generated from IOP.pidl, that contains the OMG standarized IOP
//   module.
//   The code was generated by the IDL compiler and then hand-crafted
//   to reduce the includes interdependencies.
//
// ================================================================

#ifndef TAO_IOPC_H
#define TAO_IOPC_H

#include "tao/CDR.h"
#include "tao/Sequence.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export
#if defined(_MSC_VER)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

TAO_NAMESPACE  IOP
{
  typedef CORBA::ULong ProfileId;
  typedef CORBA::ULong_out ProfileId_out;
    TAO_NAMESPACE_STORAGE_CLASS CORBA::TypeCode_ptr _tc_ProfileId;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong TAG_INTERNET_IOP;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong TAG_MULTIPLE_COMPONENTS;

  struct TAO_Export TaggedProfile
  {
    ProfileId tag;

    class TAO_Export _tao_seq_Octet : public TAO_Unbounded_Sequence<CORBA::Octet>
    {
    public:
      _tao_seq_Octet (void); // default ctor
      _tao_seq_Octet (CORBA::ULong max); // uses max size
      _tao_seq_Octet (
        CORBA::ULong max,
        CORBA::ULong length,
        CORBA::Octet *buffer,
        CORBA::Boolean release=0
      );
      _tao_seq_Octet (const _tao_seq_Octet &); // copy ctor
      ~_tao_seq_Octet (void); // dtor

#if defined(TAO_NO_COPY_OCTET_SEQUENCES)
      _tao_seq_Octet (
          CORBA::ULong length,
          const ACE_Message_Block* mb
        )
        : TAO_Unbounded_Sequence<CORBA::Octet> (length, mb) {}
#endif /* TAO_NO_COPY_OCTET_SEQUENCE */

    };

    _tao_seq_Octet profile_data;
  };

  class TAO_Export TaggedProfile_var
  {
  public:
    TaggedProfile_var (void); // default constructor
    TaggedProfile_var (TaggedProfile *);
    TaggedProfile_var (const TaggedProfile_var &); // copy constructor
    ~TaggedProfile_var (void); // destructor

    TaggedProfile_var &operator= (TaggedProfile *);
    TaggedProfile_var &operator= (const TaggedProfile_var &);
    TaggedProfile *operator-> (void);
    const TaggedProfile *operator-> (void) const;

    operator const TaggedProfile &() const;
    operator TaggedProfile &();
    operator TaggedProfile &() const;
    // in, inout, out, _retn
    const TaggedProfile &in (void) const;
    TaggedProfile &inout (void);
    TaggedProfile *&out (void);
    TaggedProfile *_retn (void);
    TaggedProfile *ptr (void) const;

  private:
    TaggedProfile *ptr_;
  };

  class TAO_Export TaggedProfile_out
  {
  public:
    TaggedProfile_out (TaggedProfile *&);
    TaggedProfile_out (TaggedProfile_var &);
    TaggedProfile_out (const TaggedProfile_out &);
    TaggedProfile_out &operator= (const TaggedProfile_out &);
    TaggedProfile_out &operator= (TaggedProfile *);
    operator TaggedProfile *&();
    TaggedProfile *&ptr (void);
    TaggedProfile *operator-> (void);

  private:
    TaggedProfile *&ptr_;
    // assignment from T_var not allowed
    void operator= (const TaggedProfile_var &);
  };

  TAO_NAMESPACE_STORAGE_CLASS CORBA::TypeCode_ptr _tc_TaggedProfile;

  struct TAO_Export IOR
  {
    TAO_String_Manager type_id;


    // *************************************************************
    // _tao_seq_TaggedProfile
    // *************************************************************

    class TAO_Export _tao_seq_TaggedProfile : public TAO_Unbounded_Sequence<TaggedProfile>
    {
    public:
      _tao_seq_TaggedProfile (void); // default ctor
      _tao_seq_TaggedProfile (CORBA::ULong max); // uses max size
      _tao_seq_TaggedProfile (
        CORBA::ULong max,
        CORBA::ULong length,
        TaggedProfile *buffer,
        CORBA::Boolean release=0
      );
      _tao_seq_TaggedProfile (const _tao_seq_TaggedProfile &); // copy ctor
      ~_tao_seq_TaggedProfile (void); // dtor
    };
    typedef _tao_seq_TaggedProfile *_tao_seq_TaggedProfile_ptr;

    _tao_seq_TaggedProfile profiles;
  };

  class TAO_Export IOR_var
  {
  public:
    IOR_var (void); // default constructor
    IOR_var (IOR *);
    IOR_var (const IOR_var &); // copy constructor
    ~IOR_var (void); // destructor

    IOR_var &operator= (IOR *);
    IOR_var &operator= (const IOR_var &);
    IOR *operator-> (void);
    const IOR *operator-> (void) const;

    operator const IOR &() const;
    operator IOR &();
    operator IOR &() const;
    // in, inout, out, _retn
    const IOR &in (void) const;
    IOR &inout (void);
    IOR *&out (void);
    IOR *_retn (void);
    IOR *ptr (void) const;

  private:
    IOR *ptr_;
  };

  class TAO_Export IOR_out
  {
  public:
    IOR_out (IOR *&);
    IOR_out (IOR_var &);
    IOR_out (const IOR_out &);
    IOR_out &operator= (const IOR_out &);
    IOR_out &operator= (IOR *);
    operator IOR *&();
    IOR *&ptr (void);
    IOR *operator-> (void);

  private:
    IOR *&ptr_;
    // assignment from T_var not allowed
    void operator= (const IOR_var &);
  };

  TAO_NAMESPACE_STORAGE_CLASS CORBA::TypeCode_ptr _tc_IOR;

  typedef CORBA::ULong ComponentId;
  typedef CORBA::ULong_out ComponentId_out;
    TAO_NAMESPACE_STORAGE_CLASS CORBA::TypeCode_ptr _tc_ComponentId;

  struct TAO_Export TaggedComponent
  {
    ComponentId tag;

    class TAO_Export _tao_seq_Octet : public TAO_Unbounded_Sequence<CORBA::Octet>
    {
    public:
      _tao_seq_Octet (void); // default ctor
      _tao_seq_Octet (CORBA::ULong max); // uses max size
      _tao_seq_Octet (
        CORBA::ULong max,
        CORBA::ULong length,
        CORBA::Octet *buffer,
        CORBA::Boolean release=0
      );
      _tao_seq_Octet (const _tao_seq_Octet &); // copy ctor
      ~_tao_seq_Octet (void); // dtor

#if defined(TAO_NO_COPY_OCTET_SEQUENCES)
      _tao_seq_Octet (
          CORBA::ULong length,
          const ACE_Message_Block* mb
        )
        : TAO_Unbounded_Sequence<CORBA::Octet> (length, mb) {}
#endif /* TAO_NO_COPY_OCTET_SEQUENCE */

    };
    typedef _tao_seq_Octet *_tao_seq_Octet_ptr;

    _tao_seq_Octet component_data;
  };

  class TAO_Export TaggedComponent_var
  {
  public:
    TaggedComponent_var (void); // default constructor
    TaggedComponent_var (TaggedComponent *);
    TaggedComponent_var (const TaggedComponent_var &); // copy constructor
    ~TaggedComponent_var (void); // destructor

    TaggedComponent_var &operator= (TaggedComponent *);
    TaggedComponent_var &operator= (const TaggedComponent_var &);
    TaggedComponent *operator-> (void);
    const TaggedComponent *operator-> (void) const;

    operator const TaggedComponent &() const;
    operator TaggedComponent &();
    operator TaggedComponent &() const;
    // in, inout, out, _retn
    const TaggedComponent &in (void) const;
    TaggedComponent &inout (void);
    TaggedComponent *&out (void);
    TaggedComponent *_retn (void);
    TaggedComponent *ptr (void) const;

  private:
    TaggedComponent *ptr_;
  };

  class TAO_Export TaggedComponent_out
  {
  public:
    TaggedComponent_out (TaggedComponent *&);
    TaggedComponent_out (TaggedComponent_var &);
    TaggedComponent_out (const TaggedComponent_out &);
    TaggedComponent_out &operator= (const TaggedComponent_out &);
    TaggedComponent_out &operator= (TaggedComponent *);
    operator TaggedComponent *&();
    TaggedComponent *&ptr (void);
    TaggedComponent *operator-> (void);

  private:
    TaggedComponent *&ptr_;
    // assignment from T_var not allowed
    void operator= (const TaggedComponent_var &);
  };

  TAO_NAMESPACE_STORAGE_CLASS CORBA::TypeCode_ptr _tc_TaggedComponent;

  class TAO_Export MultipleComponentProfile : public TAO_Unbounded_Sequence<TaggedComponent>
  {
  public:
    MultipleComponentProfile (void); // default ctor
    MultipleComponentProfile (CORBA::ULong max); // uses max size
    MultipleComponentProfile (
      CORBA::ULong max,
      CORBA::ULong length,
      TaggedComponent *buffer,
      CORBA::Boolean release=0
    );
    MultipleComponentProfile (const MultipleComponentProfile &); // copy ctor
    ~MultipleComponentProfile (void); // dtor
  };
  typedef MultipleComponentProfile *MultipleComponentProfile_ptr;

  // *************************************************************
  // class IOP::MultipleComponentProfile_var
  // *************************************************************

  class TAO_Export MultipleComponentProfile_var
  {
  public:
    MultipleComponentProfile_var (void); // default constructor
    MultipleComponentProfile_var (MultipleComponentProfile *);
    MultipleComponentProfile_var (const MultipleComponentProfile_var &); // copy constructor
    ~MultipleComponentProfile_var (void); // destructor

    MultipleComponentProfile_var &operator= (MultipleComponentProfile *);
    MultipleComponentProfile_var &operator= (const MultipleComponentProfile_var &);
    MultipleComponentProfile *operator-> (void);
    const MultipleComponentProfile *operator-> (void) const;

    operator const MultipleComponentProfile &() const;
    operator MultipleComponentProfile &();
    operator MultipleComponentProfile &() const;
    TaggedComponent &operator[] (CORBA::ULong index);
    // in, inout, out, _retn
    const MultipleComponentProfile &in (void) const;
    MultipleComponentProfile &inout (void);
    MultipleComponentProfile *&out (void);
    MultipleComponentProfile *_retn (void);
    MultipleComponentProfile *ptr (void) const;

  private:
    MultipleComponentProfile *ptr_;
  };

  class TAO_Export MultipleComponentProfile_out
  {
  public:
    MultipleComponentProfile_out (MultipleComponentProfile *&);
    MultipleComponentProfile_out (MultipleComponentProfile_var &);
    MultipleComponentProfile_out (const MultipleComponentProfile_out &);
    MultipleComponentProfile_out &operator= (const MultipleComponentProfile_out &);
    MultipleComponentProfile_out &operator= (MultipleComponentProfile *);
    operator MultipleComponentProfile *&();
    MultipleComponentProfile *&ptr (void);
    MultipleComponentProfile *operator-> (void);
    TaggedComponent &operator[] (CORBA::ULong index);

  private:
    MultipleComponentProfile *&ptr_;
    // assignment from T_var not allowed
    void operator= (const MultipleComponentProfile_var &);
  };

  TAO_NAMESPACE_STORAGE_CLASS CORBA::TypeCode_ptr _tc_MultipleComponentProfile;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong TAG_ORB_TYPE;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong TAG_CODE_SETS;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong TAG_POLICIES;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong TAG_ALTERNATE_IIOP_ADDRESS;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong TAG_ASSOCIATION_OPTIONS;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong TAG_SEC_NAME;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong TAG_SPKM_1_SEC_MECH;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong TAG_SPKM_2_SEC_MECH;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong TAG_KerberosV5_SEC_MECH;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong TAG_CSI_ECMA_Secret_SEC_MECH;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong TAG_CSI_ECMA_Hybrid_SEC_MECH;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong TAG_SSL_SEC_TRANS;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong TAG_CSI_ECMA_Public_SEC_MECH;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong TAG_GENERIC_SEC_MECH;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong TAG_COMPLETE_OBJECT_KEY;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong TAG_ENDPOINT_ID_POSITION;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong TAG_LOCATION_POLICY;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong TAG_DCE_STRING_BINDING;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong TAG_DCE_BINDING_NAME;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong TAG_DCE_NO_PIPES;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong TAG_DCE_SEC_MECH;

  typedef CORBA::ULong ServiceId;
  typedef CORBA::ULong_out ServiceId_out;
    TAO_NAMESPACE_STORAGE_CLASS CORBA::TypeCode_ptr _tc_ServiceId;

  struct TAO_Export ServiceContext
  {
    ServiceId context_id;

    // *************************************************************
    // _tao_seq_Octet
    // *************************************************************

    class TAO_Export _tao_seq_Octet : public TAO_Unbounded_Sequence<CORBA::Octet>
    {
    public:
      _tao_seq_Octet (void); // default ctor
      _tao_seq_Octet (CORBA::ULong max); // uses max size
      _tao_seq_Octet (
        CORBA::ULong max,
        CORBA::ULong length,
        CORBA::Octet *buffer,
        CORBA::Boolean release=0
      );
      _tao_seq_Octet (const _tao_seq_Octet &); // copy ctor
      ~_tao_seq_Octet (void); // dtor

#if defined(TAO_NO_COPY_OCTET_SEQUENCES)
      _tao_seq_Octet (
          CORBA::ULong length,
          const ACE_Message_Block* mb
        )
        : TAO_Unbounded_Sequence<CORBA::Octet> (length, mb) {}
#endif /* TAO_NO_COPY_OCTET_SEQUENCE */

    };
    typedef _tao_seq_Octet *_tao_seq_Octet_ptr;

    _tao_seq_Octet context_data;
  };

  class TAO_Export ServiceContext_var
  {
  public:
    ServiceContext_var (void); // default constructor
    ServiceContext_var (ServiceContext *);
    ServiceContext_var (const ServiceContext_var &); // copy constructor
    ~ServiceContext_var (void); // destructor

    ServiceContext_var &operator= (ServiceContext *);
    ServiceContext_var &operator= (const ServiceContext_var &);
    ServiceContext *operator-> (void);
    const ServiceContext *operator-> (void) const;

    operator const ServiceContext &() const;
    operator ServiceContext &();
    operator ServiceContext &() const;
    // in, inout, out, _retn
    const ServiceContext &in (void) const;
    ServiceContext &inout (void);
    ServiceContext *&out (void);
    ServiceContext *_retn (void);
    ServiceContext *ptr (void) const;

  private:
    ServiceContext *ptr_;
  };

  class TAO_Export ServiceContext_out
  {
  public:
    ServiceContext_out (ServiceContext *&);
    ServiceContext_out (ServiceContext_var &);
    ServiceContext_out (const ServiceContext_out &);
    ServiceContext_out &operator= (const ServiceContext_out &);
    ServiceContext_out &operator= (ServiceContext *);
    operator ServiceContext *&();
    ServiceContext *&ptr (void);
    ServiceContext *operator-> (void);

  private:
    ServiceContext *&ptr_;
    // assignment from T_var not allowed
    void operator= (const ServiceContext_var &);
  };

  TAO_NAMESPACE_STORAGE_CLASS CORBA::TypeCode_ptr _tc_ServiceContext;

  class TAO_Export ServiceContextList : public TAO_Unbounded_Sequence<ServiceContext>
  {
  public:
    ServiceContextList (void); // default ctor
    ServiceContextList (CORBA::ULong max); // uses max size
    ServiceContextList (
      CORBA::ULong max,
      CORBA::ULong length,
      ServiceContext *buffer,
      CORBA::Boolean release=0
    );
    ServiceContextList (const ServiceContextList &); // copy ctor
    ~ServiceContextList (void); // dtor
  };
  typedef ServiceContextList *ServiceContextList_ptr;

  // *************************************************************
  // class IOP::ServiceContextList_var
  // *************************************************************

  class TAO_Export ServiceContextList_var
  {
  public:
    ServiceContextList_var (void); // default constructor
    ServiceContextList_var (ServiceContextList *);
    ServiceContextList_var (const ServiceContextList_var &); // copy constructor
    ~ServiceContextList_var (void); // destructor

    ServiceContextList_var &operator= (ServiceContextList *);
    ServiceContextList_var &operator= (const ServiceContextList_var &);
    ServiceContextList *operator-> (void);
    const ServiceContextList *operator-> (void) const;

    operator const ServiceContextList &() const;
    operator ServiceContextList &();
    operator ServiceContextList &() const;
    ServiceContext &operator[] (CORBA::ULong index);
    // in, inout, out, _retn
    const ServiceContextList &in (void) const;
    ServiceContextList &inout (void);
    ServiceContextList *&out (void);
    ServiceContextList *_retn (void);
    ServiceContextList *ptr (void) const;

  private:
    ServiceContextList *ptr_;
  };

  class TAO_Export ServiceContextList_out
  {
  public:
    ServiceContextList_out (ServiceContextList *&);
    ServiceContextList_out (ServiceContextList_var &);
    ServiceContextList_out (const ServiceContextList_out &);
    ServiceContextList_out &operator= (const ServiceContextList_out &);
    ServiceContextList_out &operator= (ServiceContextList *);
    operator ServiceContextList *&();
    ServiceContextList *&ptr (void);
    ServiceContextList *operator-> (void);
    ServiceContext &operator[] (CORBA::ULong index);

  private:
    ServiceContextList *&ptr_;
    // assignment from T_var not allowed
    void operator= (const ServiceContextList_var &);
  };

  TAO_NAMESPACE_STORAGE_CLASS CORBA::TypeCode_ptr _tc_ServiceContextList;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong TransactionService;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong CodeSets;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong ChainBypassCheck;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong ChainBypassInfo;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong LogicalThreadId;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong BI_DIR_IIOP;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong SendingContextRunTime;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong INVOCATION_POLICIES;

  TAO_NAMESPACE_STORAGE_CLASS const CORBA::ULong UnknownExceptionInfo;

}
TAO_NAMESPACE_CLOSE // module IOP

void TAO_Export operator<<= (CORBA::Any &, const IOP::TaggedProfile &); // copying version
void TAO_Export operator<<= (CORBA::Any &, IOP::TaggedProfile*); // noncopying version
CORBA::Boolean TAO_Export operator>>= (const CORBA::Any &, IOP::TaggedProfile *&);
void TAO_Export operator<<= (CORBA::Any &, const IOP::IOR &); // copying version
void TAO_Export operator<<= (CORBA::Any &, IOP::IOR*); // noncopying version
CORBA::Boolean TAO_Export operator>>= (const CORBA::Any &, IOP::IOR *&);
void TAO_Export operator<<= (CORBA::Any &, const IOP::TaggedComponent &); // copying version
void TAO_Export operator<<= (CORBA::Any &, IOP::TaggedComponent*); // noncopying version
CORBA::Boolean TAO_Export operator>>= (const CORBA::Any &, IOP::TaggedComponent *&);
void TAO_Export operator<<= (CORBA::Any &, const IOP::MultipleComponentProfile &); // copying version
void TAO_Export operator<<= (CORBA::Any &, IOP::MultipleComponentProfile*); // noncopying version
CORBA::Boolean TAO_Export operator>>= (const CORBA::Any &, IOP::MultipleComponentProfile *&);
void TAO_Export operator<<= (CORBA::Any &, const IOP::ServiceContext &); // copying version
void TAO_Export operator<<= (CORBA::Any &, IOP::ServiceContext*); // noncopying version
CORBA::Boolean TAO_Export operator>>= (const CORBA::Any &, IOP::ServiceContext *&);
void TAO_Export operator<<= (CORBA::Any &, const IOP::ServiceContextList &); // copying version
void TAO_Export operator<<= (CORBA::Any &, IOP::ServiceContextList*); // noncopying version
CORBA::Boolean TAO_Export operator>>= (const CORBA::Any &, IOP::ServiceContextList *&);

#ifndef __ACE_INLINE__

CORBA::Boolean TAO_Export operator<< (TAO_OutputCDR &, const IOP::TaggedProfile &);
CORBA::Boolean TAO_Export operator>> (TAO_InputCDR &, IOP::TaggedProfile &);
CORBA::Boolean TAO_Export operator<< (
    TAO_OutputCDR &,
    const IOP::TaggedProfile::_tao_seq_Octet &
  );
CORBA::Boolean TAO_Export operator>> (
    TAO_InputCDR &,
    IOP::TaggedProfile::_tao_seq_Octet &
  );

CORBA::Boolean TAO_Export operator<< (TAO_OutputCDR &, const IOP::IOR &);
CORBA::Boolean TAO_Export operator>> (TAO_InputCDR &, IOP::IOR &);
CORBA::Boolean TAO_Export operator<< (
    TAO_OutputCDR &,
    const IOP::IOR::_tao_seq_TaggedProfile &
  );
CORBA::Boolean TAO_Export operator>> (
    TAO_InputCDR &,
    IOP::IOR::_tao_seq_TaggedProfile &
  );

CORBA::Boolean TAO_Export operator<< (TAO_OutputCDR &, const IOP::TaggedComponent &);
CORBA::Boolean TAO_Export operator>> (TAO_InputCDR &, IOP::TaggedComponent &);
CORBA::Boolean TAO_Export operator<< (
    TAO_OutputCDR &,
    const IOP::TaggedComponent::_tao_seq_Octet &
  );
CORBA::Boolean TAO_Export operator>> (
    TAO_InputCDR &,
    IOP::TaggedComponent::_tao_seq_Octet &
  );

CORBA::Boolean TAO_Export operator<< (
    TAO_OutputCDR &,
    const IOP::MultipleComponentProfile &
  );
CORBA::Boolean TAO_Export operator>> (
    TAO_InputCDR &,
    IOP::MultipleComponentProfile &
  );

CORBA::Boolean TAO_Export operator<< (TAO_OutputCDR &, const IOP::ServiceContext &);
CORBA::Boolean TAO_Export operator>> (TAO_InputCDR &, IOP::ServiceContext &);
CORBA::Boolean TAO_Export operator<< (
    TAO_OutputCDR &,
    const IOP::ServiceContext::_tao_seq_Octet &
  );
CORBA::Boolean TAO_Export operator>> (
    TAO_InputCDR &,
    IOP::ServiceContext::_tao_seq_Octet &
  );

CORBA::Boolean TAO_Export operator<< (
    TAO_OutputCDR &,
    const IOP::ServiceContextList &
  );
CORBA::Boolean TAO_Export operator>> (
    TAO_InputCDR &,
    IOP::ServiceContextList &
  );


#endif /* __ACE_INLINE__ */


#if defined (__ACE_INLINE__)
#include "tao/IOPC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER)
#pragma warning(default:4250)
#endif /* _MSC_VER */

#endif /* TAO_IOPC_H */

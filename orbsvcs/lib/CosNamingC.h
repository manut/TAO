// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO ORB and the TAO IDL Compiler have been developed by Washington 
// University Computer Science's Distributed Object Computing Group.
//
// Information on TAO is available at
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#if !defined (_TAO_IDL_COSNAMINGC_H_)
#define _TAO_IDL_COSNAMINGC_H_

#include "tao/corba.h"

class CosNaming{
public:
  typedef CORBA::String Istring;
  typedef CORBA::String_var Istring_var;
  typedef CORBA::String_out Istring_out;

  static CORBA::TypeCode_ptr _tc_Istring;

  struct NameComponent
  {
    ACE_NESTED_CLASS (CosNaming,Istring_var) id;

    ACE_NESTED_CLASS (CosNaming,Istring_var) kind;

  };

  class NameComponent_var
  {
  public:
    NameComponent_var (void); // default constructor
    NameComponent_var (NameComponent *);
    NameComponent_var (const NameComponent_var &); // copy constructor
    ~NameComponent_var (void); // destructor
    
    NameComponent_var &operator= (NameComponent *);
    NameComponent_var &operator= (const NameComponent_var &);
    NameComponent *operator-> (void);
    const NameComponent *operator-> (void) const;
    
    operator const NameComponent &() const;
    operator NameComponent &();
    operator NameComponent &() const;
    // in, inout, out, _retn 
    const NameComponent &in (void) const;
    NameComponent &inout (void);
    NameComponent *&out (void);
    NameComponent *_retn (void);
    NameComponent *ptr(void) const;

  private:
    NameComponent *ptr_;
  };

  class NameComponent_out
  {
  public:
    NameComponent_out (NameComponent *&);
    NameComponent_out (NameComponent_var &);
    NameComponent_out (NameComponent_out &);
    NameComponent_out &operator= (NameComponent_out &);
    NameComponent_out &operator= (NameComponent *);
    operator NameComponent *&();
    NameComponent *&ptr (void);
    NameComponent *operator-> (void);
    
  private:
    NameComponent *&ptr_;
    // assignment from T_var not allowed
    void operator= (const NameComponent_var &);
  };

  static CORBA::TypeCode_ptr _tc_NameComponent;


#if !defined (_COSNAMING__TAO__SEQ_NAME_CH_)
#define _COSNAMING__TAO__SEQ_NAME_CH_

// *************************************************************
  // class _tao__seq_Name
  // *************************************************************

  class _tao__seq_Name
  {
  public:
    _tao__seq_Name (void); // default constructor
    _tao__seq_Name (CORBA::ULong max);
    _tao__seq_Name (CORBA::ULong max, CORBA::ULong length, 
    	ACE_NESTED_CLASS (CosNaming,NameComponent) *value, CORBA::Boolean release=CORBA::B_FALSE);
    _tao__seq_Name(const _tao__seq_Name &); // copy constructor
    ~_tao__seq_Name (void);
    _tao__seq_Name &operator= (const _tao__seq_Name &);
    CORBA::ULong maximum (void) const;
    void length (CORBA::ULong);
    CORBA::ULong length (void) const;
    ACE_NESTED_CLASS (CosNaming,NameComponent) &operator[] (CORBA::ULong index);
    const ACE_NESTED_CLASS (CosNaming,NameComponent) &operator[] (CORBA::ULong index) const;
    static ACE_NESTED_CLASS (CosNaming,NameComponent) *allocbuf (CORBA::ULong nelems);
    static void freebuf (ACE_NESTED_CLASS (CosNaming,NameComponent) *);
  private:
    CORBA::ULong maximum_;
    CORBA::ULong length_;
    ACE_NESTED_CLASS (CosNaming,NameComponent) *buffer_;
    CORBA::Boolean release_;
  };
  typedef _tao__seq_Name* _tao__seq_Name_ptr;
  static CORBA::TypeCode_ptr _tc__tao__seq_Name;


#endif // end #if !defined


#if !defined (_COSNAMING__TAO__SEQ_NAME___VAR_CH_)
#define _COSNAMING__TAO__SEQ_NAME___VAR_CH_

// *************************************************************
  // class CosNaming::_tao__seq_Name_var
  // *************************************************************

  class _tao__seq_Name_var
  {
  public:
    _tao__seq_Name_var (void); // default constructor
    _tao__seq_Name_var (_tao__seq_Name *);
    _tao__seq_Name_var (const _tao__seq_Name_var &); // copy constructor
    ~_tao__seq_Name_var (void); // destructor
    
    _tao__seq_Name_var &operator= (_tao__seq_Name *);
    _tao__seq_Name_var &operator= (const _tao__seq_Name_var &);
    _tao__seq_Name *operator-> (void);
    const _tao__seq_Name *operator-> (void) const;
    
    operator const _tao__seq_Name &() const;
    operator _tao__seq_Name &();
    operator _tao__seq_Name &() const;
    ACE_NESTED_CLASS (CosNaming,NameComponent) &operator[] (CORBA::ULong index);
    // in, inout, out, _retn 
    const _tao__seq_Name &in (void) const;
    _tao__seq_Name &inout (void);
    _tao__seq_Name *&out (void);
    _tao__seq_Name *_retn (void);
    _tao__seq_Name *ptr (void) const;

  private:
    _tao__seq_Name *ptr_;
  };


#endif // end #if !defined


#if !defined (_COSNAMING__TAO__SEQ_NAME___OUT_CH_)
#define _COSNAMING__TAO__SEQ_NAME___OUT_CH_

  class _tao__seq_Name_out
  {
  public:
    _tao__seq_Name_out (_tao__seq_Name *&);
    _tao__seq_Name_out (_tao__seq_Name_var &);
    _tao__seq_Name_out (_tao__seq_Name_out &);
    _tao__seq_Name_out &operator= (_tao__seq_Name_out &);
    _tao__seq_Name_out &operator= (_tao__seq_Name *);
    operator _tao__seq_Name *&();
    _tao__seq_Name *&ptr (void);
    _tao__seq_Name *operator-> (void);
    ACE_NESTED_CLASS (CosNaming,NameComponent) &operator[] (CORBA::ULong index);
    
  private:
    _tao__seq_Name *&ptr_;
    // assignment from T_var not allowed
    void operator= (const _tao__seq_Name_var &);
  };


#endif // end #if !defined

  typedef ACE_NESTED_CLASS (CosNaming,_tao__seq_Name) Name;
  typedef ACE_NESTED_CLASS (CosNaming,_tao__seq_Name_var) Name_var;
  typedef ACE_NESTED_CLASS (CosNaming,_tao__seq_Name_out) Name_out;

  static CORBA::TypeCode_ptr _tc_Name;

  enum BindingType
  {
    nobject, 
    ncontext
  };
  typedef BindingType &BindingType_out;
  static CORBA::TypeCode_ptr _tc_BindingType;

  struct Binding
  {
    ACE_NESTED_CLASS (CosNaming,Name) binding_name;

    ACE_NESTED_CLASS (CosNaming,BindingType) binding_type;

  };

  class Binding_var
  {
  public:
    Binding_var (void); // default constructor
    Binding_var (Binding *);
    Binding_var (const Binding_var &); // copy constructor
    ~Binding_var (void); // destructor
    
    Binding_var &operator= (Binding *);
    Binding_var &operator= (const Binding_var &);
    Binding *operator-> (void);
    const Binding *operator-> (void) const;
    
    operator const Binding &() const;
    operator Binding &();
    operator Binding &() const;
    // in, inout, out, _retn 
    const Binding &in (void) const;
    Binding &inout (void);
    Binding *&out (void);
    Binding *_retn (void);
    Binding *ptr(void) const;

  private:
    Binding *ptr_;
  };

  class Binding_out
  {
  public:
    Binding_out (Binding *&);
    Binding_out (Binding_var &);
    Binding_out (Binding_out &);
    Binding_out &operator= (Binding_out &);
    Binding_out &operator= (Binding *);
    operator Binding *&();
    Binding *&ptr (void);
    Binding *operator-> (void);
    
  private:
    Binding *&ptr_;
    // assignment from T_var not allowed
    void operator= (const Binding_var &);
  };

  static CORBA::TypeCode_ptr _tc_Binding;


#if !defined (_COSNAMING__TAO__SEQ_BINDINGLIST_CH_)
#define _COSNAMING__TAO__SEQ_BINDINGLIST_CH_

// *************************************************************
  // class _tao__seq_BindingList
  // *************************************************************

  class _tao__seq_BindingList
  {
  public:
    _tao__seq_BindingList (void); // default constructor
    _tao__seq_BindingList (CORBA::ULong max);
    _tao__seq_BindingList (CORBA::ULong max, CORBA::ULong length, 
    	ACE_NESTED_CLASS (CosNaming,Binding) *value, CORBA::Boolean release=CORBA::B_FALSE);
    _tao__seq_BindingList(const _tao__seq_BindingList &); // copy constructor
    ~_tao__seq_BindingList (void);
    _tao__seq_BindingList &operator= (const _tao__seq_BindingList &);
    CORBA::ULong maximum (void) const;
    void length (CORBA::ULong);
    CORBA::ULong length (void) const;
    ACE_NESTED_CLASS (CosNaming,Binding) &operator[] (CORBA::ULong index);
    const ACE_NESTED_CLASS (CosNaming,Binding) &operator[] (CORBA::ULong index) const;
    static ACE_NESTED_CLASS (CosNaming,Binding) *allocbuf (CORBA::ULong nelems);
    static void freebuf (ACE_NESTED_CLASS (CosNaming,Binding) *);
  private:
    CORBA::ULong maximum_;
    CORBA::ULong length_;
    ACE_NESTED_CLASS (CosNaming,Binding) *buffer_;
    CORBA::Boolean release_;
  };
  typedef _tao__seq_BindingList* _tao__seq_BindingList_ptr;
  static CORBA::TypeCode_ptr _tc__tao__seq_BindingList;


#endif // end #if !defined


#if !defined (_COSNAMING__TAO__SEQ_BINDINGLIST___VAR_CH_)
#define _COSNAMING__TAO__SEQ_BINDINGLIST___VAR_CH_

// *************************************************************
  // class CosNaming::_tao__seq_BindingList_var
  // *************************************************************

  class _tao__seq_BindingList_var
  {
  public:
    _tao__seq_BindingList_var (void); // default constructor
    _tao__seq_BindingList_var (_tao__seq_BindingList *);
    _tao__seq_BindingList_var (const _tao__seq_BindingList_var &); // copy constructor
    ~_tao__seq_BindingList_var (void); // destructor
    
    _tao__seq_BindingList_var &operator= (_tao__seq_BindingList *);
    _tao__seq_BindingList_var &operator= (const _tao__seq_BindingList_var &);
    _tao__seq_BindingList *operator-> (void);
    const _tao__seq_BindingList *operator-> (void) const;
    
    operator const _tao__seq_BindingList &() const;
    operator _tao__seq_BindingList &();
    operator _tao__seq_BindingList &() const;
    ACE_NESTED_CLASS (CosNaming,Binding) &operator[] (CORBA::ULong index);
    // in, inout, out, _retn 
    const _tao__seq_BindingList &in (void) const;
    _tao__seq_BindingList &inout (void);
    _tao__seq_BindingList *&out (void);
    _tao__seq_BindingList *_retn (void);
    _tao__seq_BindingList *ptr (void) const;

  private:
    _tao__seq_BindingList *ptr_;
  };


#endif // end #if !defined


#if !defined (_COSNAMING__TAO__SEQ_BINDINGLIST___OUT_CH_)
#define _COSNAMING__TAO__SEQ_BINDINGLIST___OUT_CH_

  class _tao__seq_BindingList_out
  {
  public:
    _tao__seq_BindingList_out (_tao__seq_BindingList *&);
    _tao__seq_BindingList_out (_tao__seq_BindingList_var &);
    _tao__seq_BindingList_out (_tao__seq_BindingList_out &);
    _tao__seq_BindingList_out &operator= (_tao__seq_BindingList_out &);
    _tao__seq_BindingList_out &operator= (_tao__seq_BindingList *);
    operator _tao__seq_BindingList *&();
    _tao__seq_BindingList *&ptr (void);
    _tao__seq_BindingList *operator-> (void);
    ACE_NESTED_CLASS (CosNaming,Binding) &operator[] (CORBA::ULong index);
    
  private:
    _tao__seq_BindingList *&ptr_;
    // assignment from T_var not allowed
    void operator= (const _tao__seq_BindingList_var &);
  };


#endif // end #if !defined

  typedef ACE_NESTED_CLASS (CosNaming,_tao__seq_BindingList) BindingList;
  typedef ACE_NESTED_CLASS (CosNaming,_tao__seq_BindingList_var) BindingList_var;
  typedef ACE_NESTED_CLASS (CosNaming,_tao__seq_BindingList_out) BindingList_out;

  static CORBA::TypeCode_ptr _tc_BindingList;

  class BindingIterator;
  
#if !defined (_COSNAMING_BINDINGITERATOR___PTR_CH_)
#define _COSNAMING_BINDINGITERATOR___PTR_CH_

typedef BindingIterator *BindingIterator_ptr; 

#endif // end #if !defined


#if !defined (_COSNAMING_BINDINGITERATOR___VAR_CH_)
#define _COSNAMING_BINDINGITERATOR___VAR_CH_

  class BindingIterator_var
  {
  public:
    BindingIterator_var (void); // default constructor
    BindingIterator_var (BindingIterator_ptr);
    BindingIterator_var (const BindingIterator_var &); // copy constructor
    ~BindingIterator_var (void); // destructor
    
    BindingIterator_var &operator= (BindingIterator_ptr);
    BindingIterator_var &operator= (const BindingIterator_var &);
    BindingIterator_ptr operator-> (void) const;
    
    operator const BindingIterator_ptr &() const;
    operator BindingIterator_ptr &();
    // in, inout, out, _retn 
    BindingIterator_ptr in (void) const;
    BindingIterator_ptr &inout (void);
    BindingIterator_ptr &out (void);
    BindingIterator_ptr _retn (void);
    BindingIterator_ptr ptr (void) const;

  private:
    BindingIterator_ptr ptr_;
  };


#endif // end #if !defined


#if !defined (_COSNAMING_BINDINGITERATOR___OUT_CH_)
#define _COSNAMING_BINDINGITERATOR___OUT_CH_

  class BindingIterator_out
  {
  public:
    BindingIterator_out (BindingIterator_ptr &);
    BindingIterator_out (BindingIterator_var &);
    BindingIterator_out (BindingIterator_out &);
    BindingIterator_out &operator= (BindingIterator_out &);
    BindingIterator_out &operator= (const BindingIterator_var &);
    BindingIterator_out &operator= (BindingIterator_ptr);
    operator BindingIterator_ptr &();
    BindingIterator_ptr &ptr (void);
    BindingIterator_ptr operator-> (void);
    
  private:
    BindingIterator_ptr &ptr_;
  };


#endif // end #if !defined

  
#if !defined (_COSNAMING_NAMINGCONTEXT___PTR_CH_)
#define _COSNAMING_NAMINGCONTEXT___PTR_CH_

class NamingContext;
  typedef NamingContext *NamingContext_ptr;
  
#endif // end #if !defined


#if !defined (_COSNAMING_NAMINGCONTEXT_CH_)
#define _COSNAMING_NAMINGCONTEXT_CH_

class NamingContext: public virtual ACE_CORBA_1 (Object)
  {
  public:
    // the static operations
    static NamingContext_ptr _duplicate (NamingContext_ptr obj);
    static NamingContext_ptr _narrow (CORBA::Object_ptr obj, CORBA::Environment &env);
    static NamingContext_ptr _nil (void);
    static NamingContext_ptr _bind (const char *host, CORBA::UShort port, const char *key, CORBA::Environment &env);

    enum NotFoundReason
    {
      missing_node, 
      not_context, 
      not_object
    };
    typedef NotFoundReason &NotFoundReason_out;
    static CORBA::TypeCode_ptr _tc_NotFoundReason;

    
#if !defined (_COSNAMING_NAMINGCONTEXT_NOTFOUND___PTR_CH_)
#define _COSNAMING_NAMINGCONTEXT_NOTFOUND___PTR_CH_

    class NotFound;
    typedef NotFound *NotFound_ptr;
    
#endif // end #if !defined


#if !defined (_COSNAMING_NAMINGCONTEXT_NOTFOUND_CH_)
#define _COSNAMING_NAMINGCONTEXT_NOTFOUND_CH_

    class NotFound : public virtual CORBA::UserException
    {
    public:
          NotFound (void);
    };
    
    
#endif // end #if !defined

static CORBA::TypeCode_ptr _tc_NotFound;

    
#if !defined (_COSNAMING_NAMINGCONTEXT_CANNOTPROCEED___PTR_CH_)
#define _COSNAMING_NAMINGCONTEXT_CANNOTPROCEED___PTR_CH_

    class CannotProceed;
    typedef CannotProceed *CannotProceed_ptr;
    
#endif // end #if !defined


#if !defined (_COSNAMING_NAMINGCONTEXT_CANNOTPROCEED_CH_)
#define _COSNAMING_NAMINGCONTEXT_CANNOTPROCEED_CH_

    class CannotProceed : public virtual CORBA::UserException
    {
    public:
          CannotProceed (void);
    };
    
    
#endif // end #if !defined

static CORBA::TypeCode_ptr _tc_CannotProceed;

    
#if !defined (_COSNAMING_NAMINGCONTEXT_INVALIDNAME___PTR_CH_)
#define _COSNAMING_NAMINGCONTEXT_INVALIDNAME___PTR_CH_

    class InvalidName;
    typedef InvalidName *InvalidName_ptr;
    
#endif // end #if !defined


#if !defined (_COSNAMING_NAMINGCONTEXT_INVALIDNAME_CH_)
#define _COSNAMING_NAMINGCONTEXT_INVALIDNAME_CH_

    class InvalidName : public virtual CORBA::UserException
    {
    public:
          InvalidName (void);
    };
    
    
#endif // end #if !defined

static CORBA::TypeCode_ptr _tc_InvalidName;

    
#if !defined (_COSNAMING_NAMINGCONTEXT_ALREADYBOUND___PTR_CH_)
#define _COSNAMING_NAMINGCONTEXT_ALREADYBOUND___PTR_CH_

    class AlreadyBound;
    typedef AlreadyBound *AlreadyBound_ptr;
    
#endif // end #if !defined


#if !defined (_COSNAMING_NAMINGCONTEXT_ALREADYBOUND_CH_)
#define _COSNAMING_NAMINGCONTEXT_ALREADYBOUND_CH_

    class AlreadyBound : public virtual CORBA::UserException
    {
    public:
          AlreadyBound (void);
    };
    
    
#endif // end #if !defined

static CORBA::TypeCode_ptr _tc_AlreadyBound;

    
#if !defined (_COSNAMING_NAMINGCONTEXT_NOTEMPTY___PTR_CH_)
#define _COSNAMING_NAMINGCONTEXT_NOTEMPTY___PTR_CH_

    class NotEmpty;
    typedef NotEmpty *NotEmpty_ptr;
    
#endif // end #if !defined


#if !defined (_COSNAMING_NAMINGCONTEXT_NOTEMPTY_CH_)
#define _COSNAMING_NAMINGCONTEXT_NOTEMPTY_CH_

    class NotEmpty : public virtual CORBA::UserException
    {
    public:
          NotEmpty (void);
    };
    
    
#endif // end #if !defined

static CORBA::TypeCode_ptr _tc_NotEmpty;

    virtual void bind (const ACE_NESTED_CLASS (CosNaming,Name) & n, CORBA::Object_ptr  obj, CORBA::Environment &env);
    virtual void rebind (const ACE_NESTED_CLASS (CosNaming,Name) & n, CORBA::Object_ptr  obj, CORBA::Environment &env);
    virtual void bind_context (const ACE_NESTED_CLASS (CosNaming,Name) & n, ACE_NESTED_CLASS (CosNaming,NamingContext_ptr)  nc, CORBA::Environment &env);
    virtual void rebind_context (const ACE_NESTED_CLASS (CosNaming,Name) & n, ACE_NESTED_CLASS (CosNaming,NamingContext_ptr)  nc, CORBA::Environment &env);
    virtual CORBA::Object_ptr resolve (const ACE_NESTED_CLASS (CosNaming,Name) & n, CORBA::Environment &env);
    virtual void unbind (const ACE_NESTED_CLASS (CosNaming,Name) & n, CORBA::Environment &env);
    virtual ACE_NESTED_CLASS (CosNaming,NamingContext_ptr)  new_context (CORBA::Environment &env);
    virtual ACE_NESTED_CLASS (CosNaming,NamingContext_ptr)  bind_new_context (const ACE_NESTED_CLASS (CosNaming,Name) & n, CORBA::Environment &env);
    virtual void destroy (CORBA::Environment &env);
    virtual void list (CORBA::ULong how_many, ACE_NESTED_CLASS (CosNaming,BindingList_out)  bl, ACE_NESTED_CLASS (CosNaming,BindingIterator_out)  bi, CORBA::Environment &env);
  protected:
    NamingContext (void); // default constructor
    NamingContext (STUB_Object *objref);
    virtual ~NamingContext (void);
  private:
    NamingContext (const NamingContext&);
    void operator= (const NamingContext&);
  };


#endif // end #if !defined


#if !defined (_COSNAMING_NAMINGCONTEXT___VAR_CH_)
#define _COSNAMING_NAMINGCONTEXT___VAR_CH_

  class NamingContext_var
  {
  public:
    NamingContext_var (void); // default constructor
    NamingContext_var (NamingContext_ptr);
    NamingContext_var (const NamingContext_var &); // copy constructor
    ~NamingContext_var (void); // destructor
    
    NamingContext_var &operator= (NamingContext_ptr);
    NamingContext_var &operator= (const NamingContext_var &);
    NamingContext_ptr operator-> (void) const;
    
    operator const NamingContext_ptr &() const;
    operator NamingContext_ptr &();
    // in, inout, out, _retn 
    NamingContext_ptr in (void) const;
    NamingContext_ptr &inout (void);
    NamingContext_ptr &out (void);
    NamingContext_ptr _retn (void);
    NamingContext_ptr ptr (void) const;

  private:
    NamingContext_ptr ptr_;
  };


#endif // end #if !defined


#if !defined (_COSNAMING_NAMINGCONTEXT___OUT_CH_)
#define _COSNAMING_NAMINGCONTEXT___OUT_CH_

  class NamingContext_out
  {
  public:
    NamingContext_out (NamingContext_ptr &);
    NamingContext_out (NamingContext_var &);
    NamingContext_out (NamingContext_out &);
    NamingContext_out &operator= (NamingContext_out &);
    NamingContext_out &operator= (const NamingContext_var &);
    NamingContext_out &operator= (NamingContext_ptr);
    operator NamingContext_ptr &();
    NamingContext_ptr &ptr (void);
    NamingContext_ptr operator-> (void);
    
  private:
    NamingContext_ptr &ptr_;
  };


#endif // end #if !defined

  static CORBA::TypeCode_ptr _tc_NamingContext;

  
#if !defined (_COSNAMING_BINDINGITERATOR___PTR_CH_)
#define _COSNAMING_BINDINGITERATOR___PTR_CH_

class BindingIterator;
  typedef BindingIterator *BindingIterator_ptr;
  
#endif // end #if !defined


#if !defined (_COSNAMING_BINDINGITERATOR_CH_)
#define _COSNAMING_BINDINGITERATOR_CH_

class BindingIterator: public virtual ACE_CORBA_1 (Object)
  {
  public:
    // the static operations
    static BindingIterator_ptr _duplicate (BindingIterator_ptr obj);
    static BindingIterator_ptr _narrow (CORBA::Object_ptr obj, CORBA::Environment &env);
    static BindingIterator_ptr _nil (void);
    static BindingIterator_ptr _bind (const char *host, CORBA::UShort port, const char *key, CORBA::Environment &env);

    virtual CORBA::Boolean next_one (ACE_NESTED_CLASS (CosNaming,Binding_out)  b, CORBA::Environment &env);
    virtual CORBA::Boolean next_n (CORBA::ULong how_many, ACE_NESTED_CLASS (CosNaming,BindingList_out)  bl, CORBA::Environment &env);
    virtual void destroy (CORBA::Environment &env);
  protected:
    BindingIterator (void); // default constructor
    BindingIterator (STUB_Object *objref);
    virtual ~BindingIterator (void);
  private:
    BindingIterator (const BindingIterator&);
    void operator= (const BindingIterator&);
  };


#endif // end #if !defined


#if !defined (_COSNAMING_BINDINGITERATOR___VAR_CH_)
#define _COSNAMING_BINDINGITERATOR___VAR_CH_

  class BindingIterator_var
  {
  public:
    BindingIterator_var (void); // default constructor
    BindingIterator_var (BindingIterator_ptr);
    BindingIterator_var (const BindingIterator_var &); // copy constructor
    ~BindingIterator_var (void); // destructor
    
    BindingIterator_var &operator= (BindingIterator_ptr);
    BindingIterator_var &operator= (const BindingIterator_var &);
    BindingIterator_ptr operator-> (void) const;
    
    operator const BindingIterator_ptr &() const;
    operator BindingIterator_ptr &();
    // in, inout, out, _retn 
    BindingIterator_ptr in (void) const;
    BindingIterator_ptr &inout (void);
    BindingIterator_ptr &out (void);
    BindingIterator_ptr _retn (void);
    BindingIterator_ptr ptr (void) const;

  private:
    BindingIterator_ptr ptr_;
  };


#endif // end #if !defined


#if !defined (_COSNAMING_BINDINGITERATOR___OUT_CH_)
#define _COSNAMING_BINDINGITERATOR___OUT_CH_

  class BindingIterator_out
  {
  public:
    BindingIterator_out (BindingIterator_ptr &);
    BindingIterator_out (BindingIterator_var &);
    BindingIterator_out (BindingIterator_out &);
    BindingIterator_out &operator= (BindingIterator_out &);
    BindingIterator_out &operator= (const BindingIterator_var &);
    BindingIterator_out &operator= (BindingIterator_ptr);
    operator BindingIterator_ptr &();
    BindingIterator_ptr &ptr (void);
    BindingIterator_ptr operator-> (void);
    
  private:
    BindingIterator_ptr &ptr_;
  };


#endif // end #if !defined

  static CORBA::TypeCode_ptr _tc_BindingIterator;

};


#if defined (__ACE_INLINE__)
#include "CosNamingC.i"
#endif // defined INLINE


#endif // if !defined

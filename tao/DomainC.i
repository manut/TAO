/* -*- C++ -*- */
// $Id$

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

ACE_INLINE
CORBA::DomainManager::DomainManager (void) // default constructor
{}

ACE_INLINE
CORBA::DomainManager::DomainManager (TAO_Stub *objref, 
                                     TAO_ServantBase *_tao_servant, 
				     CORBA::Boolean _tao_collocated) // constructor
  : CORBA_Object (objref, _tao_servant, _tao_collocated)
{}

ACE_INLINE
CORBA::DomainManager::~DomainManager (void) // destructor
{}

ACE_INLINE CORBA::DomainManager_ptr
CORBA::DomainManager::_nil (void)
{
  return (CORBA::DomainManager_ptr)0;
}

// *************************************************************
// Inline operations for class CORBA::DomainManager_var
// *************************************************************

ACE_INLINE
CORBA::DomainManager_var::DomainManager_var (void) // default constructor
  : ptr_ (CORBA::DomainManager::_nil ())
{}

ACE_INLINE
CORBA::DomainManager_var::DomainManager_var (CORBA::DomainManager_ptr p)
  : ptr_ (p)
{}

ACE_INLINE CORBA::DomainManager_ptr 
CORBA::DomainManager_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE
CORBA::DomainManager_var::DomainManager_var (const CORBA::DomainManager_var &p) // copy constructor
  : ptr_ (CORBA::DomainManager::_duplicate (p.ptr ()))
{}

ACE_INLINE
CORBA::DomainManager_var::~DomainManager_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

ACE_INLINE CORBA::DomainManager_var &
CORBA::DomainManager_var::operator= (CORBA::DomainManager_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

ACE_INLINE CORBA::DomainManager_var &
CORBA::DomainManager_var::operator= (const CORBA::DomainManager_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = CORBA::DomainManager::_duplicate (p.ptr ());
  }
  return *this;
}

ACE_INLINE 
CORBA::DomainManager_var::operator const CORBA::DomainManager_ptr &() const // cast
{
  return this->ptr_;
}

ACE_INLINE 
CORBA::DomainManager_var::operator CORBA::DomainManager_ptr &() // cast 
{
  return this->ptr_;
}

ACE_INLINE CORBA::DomainManager_ptr 
CORBA::DomainManager_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA::DomainManager_ptr
CORBA::DomainManager_var::in (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA::DomainManager_ptr &
CORBA::DomainManager_var::inout (void)
{
  return this->ptr_;
}

ACE_INLINE CORBA::DomainManager_ptr &
CORBA::DomainManager_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA::DomainManager::_nil ();
  return this->ptr_;
}

ACE_INLINE CORBA::DomainManager_ptr 
CORBA::DomainManager_var::_retn (void)
{
  // yield ownership of managed obj reference
  CORBA::DomainManager_ptr val = this->ptr_;
  this->ptr_ = CORBA::DomainManager::_nil ();
  return val;
}

// *************************************************************
// Inline operations for class CORBA::DomainManager_out
// *************************************************************

ACE_INLINE
CORBA::DomainManager_out::DomainManager_out (CORBA::DomainManager_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = CORBA::DomainManager::_nil ();
}

ACE_INLINE
CORBA::DomainManager_out::DomainManager_out (CORBA::DomainManager_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA::DomainManager::_nil ();
}

ACE_INLINE
CORBA::DomainManager_out::DomainManager_out (const CORBA::DomainManager_out &p) // copy constructor
  : ptr_ (ACE_const_cast (CORBA::DomainManager_out&,p).ptr_)
{}

ACE_INLINE CORBA::DomainManager_out &
CORBA::DomainManager_out::operator= (const CORBA::DomainManager_out &p)
{
  this->ptr_ = ACE_const_cast (CORBA::DomainManager_out&,p).ptr_;
  return *this;
}

ACE_INLINE CORBA::DomainManager_out &
CORBA::DomainManager_out::operator= (const CORBA::DomainManager_var &p)
{
  this->ptr_ = CORBA::DomainManager::_duplicate (p.ptr ());
  return *this;
}

ACE_INLINE CORBA::DomainManager_out &
CORBA::DomainManager_out::operator= (CORBA::DomainManager_ptr p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE 
CORBA::DomainManager_out::operator CORBA::DomainManager_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE CORBA::DomainManager_ptr &
CORBA::DomainManager_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE CORBA::DomainManager_ptr 
CORBA::DomainManager_out::operator-> (void)
{
  return this->ptr_;
}

#if ! defined (TAO_HAS_MINIMUM_CORBA)

ACE_INLINE
CORBA::ConstructionPolicy::ConstructionPolicy (void) // default constructor
{}

ACE_INLINE
CORBA::ConstructionPolicy::ConstructionPolicy (TAO_Stub *objref, TAO_ServantBase *_tao_servant, CORBA::Boolean _tao_collocated) // constructor
  : CORBA_Object (objref, _tao_servant, _tao_collocated)
{}

ACE_INLINE
CORBA::ConstructionPolicy::~ConstructionPolicy (void) // destructor
{}

ACE_INLINE CORBA::ConstructionPolicy_ptr
CORBA::ConstructionPolicy::_nil (void)
{
  return (CORBA::ConstructionPolicy_ptr)0;
}

// *************************************************************
// Inline operations for class CORBA::ConstructionPolicy_var
// *************************************************************

ACE_INLINE
CORBA::ConstructionPolicy_var::ConstructionPolicy_var (void) // default constructor
  : ptr_ (CORBA::ConstructionPolicy::_nil ())
{}

ACE_INLINE
CORBA::ConstructionPolicy_var::ConstructionPolicy_var (CORBA::ConstructionPolicy_ptr p)
  : ptr_ (p)
{}

ACE_INLINE CORBA::ConstructionPolicy_ptr 
CORBA::ConstructionPolicy_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE
CORBA::ConstructionPolicy_var::ConstructionPolicy_var (const CORBA::ConstructionPolicy_var &p) // copy constructor
  : ptr_ (CORBA::ConstructionPolicy::_duplicate (p.ptr ()))
{}

ACE_INLINE
CORBA::ConstructionPolicy_var::~ConstructionPolicy_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

ACE_INLINE CORBA::ConstructionPolicy_var &
CORBA::ConstructionPolicy_var::operator= (CORBA::ConstructionPolicy_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

ACE_INLINE CORBA::ConstructionPolicy_var &
CORBA::ConstructionPolicy_var::operator= (const CORBA::ConstructionPolicy_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = CORBA::ConstructionPolicy::_duplicate (p.ptr ());
  }
  return *this;
}

ACE_INLINE 
CORBA::ConstructionPolicy_var::operator const CORBA::ConstructionPolicy_ptr &() const // cast
{
  return this->ptr_;
}

ACE_INLINE 
CORBA::ConstructionPolicy_var::operator CORBA::ConstructionPolicy_ptr &() // cast 
{
  return this->ptr_;
}

ACE_INLINE CORBA::ConstructionPolicy_ptr 
CORBA::ConstructionPolicy_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA::ConstructionPolicy_ptr
CORBA::ConstructionPolicy_var::in (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA::ConstructionPolicy_ptr &
CORBA::ConstructionPolicy_var::inout (void)
{
  return this->ptr_;
}

ACE_INLINE CORBA::ConstructionPolicy_ptr &
CORBA::ConstructionPolicy_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA::ConstructionPolicy::_nil ();
  return this->ptr_;
}

ACE_INLINE CORBA::ConstructionPolicy_ptr 
CORBA::ConstructionPolicy_var::_retn (void)
{
  // yield ownership of managed obj reference
  CORBA::ConstructionPolicy_ptr val = this->ptr_;
  this->ptr_ = CORBA::ConstructionPolicy::_nil ();
  return val;
}

// *************************************************************
// Inline operations for class CORBA::ConstructionPolicy_out
// *************************************************************

ACE_INLINE
CORBA::ConstructionPolicy_out::ConstructionPolicy_out (CORBA::ConstructionPolicy_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = CORBA::ConstructionPolicy::_nil ();
}

ACE_INLINE
CORBA::ConstructionPolicy_out::ConstructionPolicy_out (CORBA::ConstructionPolicy_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA::ConstructionPolicy::_nil ();
}

ACE_INLINE
CORBA::ConstructionPolicy_out::ConstructionPolicy_out (const CORBA::ConstructionPolicy_out &p) // copy constructor
  : ptr_ (ACE_const_cast (CORBA::ConstructionPolicy_out&,p).ptr_)
{}

ACE_INLINE CORBA::ConstructionPolicy_out &
CORBA::ConstructionPolicy_out::operator= (const CORBA::ConstructionPolicy_out &p)
{
  this->ptr_ = ACE_const_cast (CORBA::ConstructionPolicy_out&,p).ptr_;
  return *this;
}

ACE_INLINE CORBA::ConstructionPolicy_out &
CORBA::ConstructionPolicy_out::operator= (const CORBA::ConstructionPolicy_var &p)
{
  this->ptr_ = CORBA::ConstructionPolicy::_duplicate (p.ptr ());
  return *this;
}

ACE_INLINE CORBA::ConstructionPolicy_out &
CORBA::ConstructionPolicy_out::operator= (CORBA::ConstructionPolicy_ptr p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE 
CORBA::ConstructionPolicy_out::operator CORBA::ConstructionPolicy_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE CORBA::ConstructionPolicy_ptr &
CORBA::ConstructionPolicy_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE CORBA::ConstructionPolicy_ptr 
CORBA::ConstructionPolicy_out::operator-> (void)
{
  return this->ptr_;
}


#endif /* ! defined (TAO_HAS_MINIMUM_CORBA) */

// *************************************************************
// Inline operations for class CORBA::DomainManagerList_var
// *************************************************************

ACE_INLINE
CORBA::DomainManagerList_var::DomainManagerList_var (void) // default constructor
  : ptr_ (0)
{}

ACE_INLINE
CORBA::DomainManagerList_var::DomainManagerList_var (CORBA::DomainManagerList *p)
  : ptr_ (p)
{}

ACE_INLINE
CORBA::DomainManagerList_var::DomainManagerList_var (const CORBA::DomainManagerList_var &p) // copy constructor
{
  if (p.ptr_)
    this->ptr_ = new CORBA::DomainManagerList(*p.ptr_);
  else
    this->ptr_ = 0;
}

ACE_INLINE
CORBA::DomainManagerList_var::~DomainManagerList_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE CORBA::DomainManagerList_var &
CORBA::DomainManagerList_var::operator= (CORBA::DomainManagerList *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE CORBA::DomainManagerList_var &
CORBA::DomainManagerList_var::operator= (const CORBA::DomainManagerList_var &p) // deep copy
{
  if (this != &p)
  {
    delete this->ptr_;
    this->ptr_ = new CORBA::DomainManagerList (*p.ptr_);
  }
  return *this;
}

ACE_INLINE const CORBA::DomainManagerList *
CORBA::DomainManagerList_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA::DomainManagerList *
CORBA::DomainManagerList_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE 
CORBA::DomainManagerList_var::operator const CORBA::DomainManagerList &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE 
CORBA::DomainManagerList_var::operator CORBA::DomainManagerList &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE 
CORBA::DomainManagerList_var::operator CORBA::DomainManagerList &() const// cast 
{
  return *this->ptr_;
}

ACE_INLINE TAO_Object_Manager<CORBA::DomainManager> 
CORBA::DomainManagerList_var::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

ACE_INLINE const CORBA::DomainManagerList &
CORBA::DomainManagerList_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE CORBA::DomainManagerList &
CORBA::DomainManagerList_var::inout (void)
{
  return *this->ptr_;
}

// mapping for variable size 
ACE_INLINE CORBA::DomainManagerList *&
CORBA::DomainManagerList_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE CORBA::DomainManagerList *
CORBA::DomainManagerList_var::_retn (void)
{
  CORBA::DomainManagerList *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE CORBA::DomainManagerList *
CORBA::DomainManagerList_var::ptr (void) const
{
  return this->ptr_;
}

// *************************************************************
// Inline operations for class CORBA::DomainManagerList_out
// *************************************************************

ACE_INLINE
CORBA::DomainManagerList_out::DomainManagerList_out (CORBA::DomainManagerList *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
CORBA::DomainManagerList_out::DomainManagerList_out (CORBA::DomainManagerList_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
CORBA::DomainManagerList_out::DomainManagerList_out (const CORBA::DomainManagerList_out &p) // copy constructor
  : ptr_ (ACE_const_cast (CORBA::DomainManagerList_out&,p).ptr_)
{}

ACE_INLINE CORBA::DomainManagerList_out &
CORBA::DomainManagerList_out::operator= (const CORBA::DomainManagerList_out &p)
{
  this->ptr_ = ACE_const_cast (CORBA::DomainManagerList_out&,p).ptr_;
  return *this;
}

ACE_INLINE CORBA::DomainManagerList_out &
CORBA::DomainManagerList_out::operator= (CORBA::DomainManagerList *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE 
CORBA::DomainManagerList_out::operator CORBA::DomainManagerList *&() // cast
{
  return this->ptr_;
}

ACE_INLINE CORBA::DomainManagerList *&
CORBA::DomainManagerList_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE CORBA::DomainManagerList *
CORBA::DomainManagerList_out::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE TAO_Object_Manager<CORBA::DomainManager> 
CORBA::DomainManagerList_out::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

ACE_INLINE CORBA::Boolean
operator<< (
    TAO_OutputCDR &,
    const CORBA::DomainManager_ptr
  );
ACE_INLINE CORBA::Boolean
operator>> (
    TAO_InputCDR &,
    CORBA::DomainManager_ptr &
  );

ACE_INLINE CORBA::Boolean
operator<< (
    TAO_OutputCDR &strm,
    const CORBA::DomainManager_ptr _tao_objref
  )
{
  CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

ACE_INLINE CORBA::Boolean
operator>> (
    TAO_InputCDR &strm,
    CORBA::DomainManager_ptr &_tao_objref
  )
{
  ACE_TRY_NEW_ENV
  {
    CORBA::Object_var obj;
    if ((strm >> obj.inout ()) == 0)
      return 0;
    // narrow to the right type
    _tao_objref =
      CORBA::DomainManager::_narrow (
          obj.in (),
          ACE_TRY_ENV
        );
    ACE_TRY_CHECK;
    return 1;
  }
  ACE_CATCHANY
  {
    // do nothing
  }
  ACE_ENDTRY;
  return 0;
}

#if ! defined (TAO_HAS_MINIMUM_CORBA)

ACE_INLINE CORBA::Boolean
operator<< (
    TAO_OutputCDR &,
    const CORBA::ConstructionPolicy_ptr
  );
ACE_INLINE CORBA::Boolean
operator>> (
    TAO_InputCDR &,
    CORBA::ConstructionPolicy_ptr &
  );

ACE_INLINE CORBA::Boolean
operator<< (
    TAO_OutputCDR &strm,
    const CORBA::ConstructionPolicy_ptr _tao_objref
  )
{
  CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

ACE_INLINE CORBA::Boolean
operator>> (
    TAO_InputCDR &strm,
    CORBA::ConstructionPolicy_ptr &_tao_objref
  )
{
  ACE_TRY_NEW_ENV
  {
    CORBA::Object_var obj;
    if ((strm >> obj.inout ()) == 0)
      return 0;
    // narrow to the right type
    _tao_objref =
      CORBA::ConstructionPolicy::_narrow (
          obj.in (),
          ACE_TRY_ENV
        );
    ACE_TRY_CHECK;
    return 1;
  }
  ACE_CATCHANY
  {
    // do nothing
  }
  ACE_ENDTRY;
  return 0;
}

#endif /* ! defined (TAO_HAS_MINIMUM_CORBA) */

ACE_INLINE CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::DomainManagerList &_tao_sequence
  )
{
  if (strm << _tao_sequence.length ())
  {
    // encode all elements
    CORBA::Boolean _tao_marshal_flag = 1;
    for (CORBA::ULong i = 0; i < _tao_sequence.length () && _tao_marshal_flag; i++)
      _tao_marshal_flag = (strm << _tao_sequence[i].in ());
    return _tao_marshal_flag;
  }
  return 0; // error
}

ACE_INLINE CORBA::Boolean operator>> (TAO_InputCDR &strm, CORBA::DomainManagerList &_tao_sequence)
{
  CORBA::ULong _tao_seq_len;
  if (strm >> _tao_seq_len)
  {
    // set the length of the sequence
    _tao_sequence.length (_tao_seq_len);
    // retrieve all the elements
    CORBA::Boolean _tao_marshal_flag = 1;
    for (CORBA::ULong i = 0; i < _tao_sequence.length () && _tao_marshal_flag; i++)
      _tao_marshal_flag = (strm >> _tao_sequence[i].out ());
    return _tao_marshal_flag;
  }
  return 0; // error
}


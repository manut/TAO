// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO ORB and the TAO IDL Compiler have been developed by Washington 
// University Computer Science's Distributed Object Computing Group.
//
// Information on TAO is available at
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

// *************************************************************
// Inline operations for exception RtecEventComm::Disconnected
// *************************************************************

// default constructor
ACE_INLINE
RtecEventComm::Disconnected::Disconnected (void)
  : CORBA_UserException (_tc_Disconnected)
{
}

// *************************************************************
// Inline operations for class RtecEventComm::EventData_var
// *************************************************************

ACE_INLINE
RtecEventComm::EventData_var::EventData_var (void) // default constructor
	: ptr_ (0)
{}

ACE_INLINE
RtecEventComm::EventData_var::EventData_var (RtecEventComm::EventData *p)
	: ptr_ (p)
{}

ACE_INLINE
RtecEventComm::EventData_var::EventData_var (const RtecEventComm::EventData_var &p) // copy constructor
{
  if (p.ptr_)
  	this->ptr_ = new RtecEventComm::EventData(*p.ptr_);
  else
  	this->ptr_ = 0;
}

ACE_INLINE
RtecEventComm::EventData_var::~EventData_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE RtecEventComm::EventData_var &
RtecEventComm::EventData_var::operator= (RtecEventComm::EventData *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE RtecEventComm::EventData_var &
RtecEventComm::EventData_var::operator= (const RtecEventComm::EventData_var &p)
{
  if (this != &p)
  {
    delete this->ptr_;
    this->ptr_ = new RtecEventComm::EventData (*p.ptr_);
  }
  return *this;
}

ACE_INLINE const RtecEventComm::EventData *
RtecEventComm::EventData_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::EventData *
RtecEventComm::EventData_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE 
RtecEventComm::EventData_var::operator const RtecEventComm::EventData &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE 
RtecEventComm::EventData_var::operator RtecEventComm::EventData &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE 
RtecEventComm::EventData_var::operator RtecEventComm::EventData &() const// cast 
{
  return *this->ptr_;
}

ACE_INLINE const RtecEventComm::EventData &
RtecEventComm::EventData_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE RtecEventComm::EventData &
RtecEventComm::EventData_var::inout (void)
{
  return *this->ptr_;
}

// mapping for fixed size 
ACE_INLINE RtecEventComm::EventData &
RtecEventComm::EventData_var::out (void)
{
  return *this->ptr_;
}

ACE_INLINE RtecEventComm::EventData
RtecEventComm::EventData_var::_retn (void)
{
  return *this->ptr_;
}

ACE_INLINE RtecEventComm::EventData *
RtecEventComm::EventData_var::ptr (void) const
{
  return this->ptr_;
}

// *************************************************************
// Inline operations for class RtecEventComm::Event_var
// *************************************************************

ACE_INLINE
RtecEventComm::Event_var::Event_var (void) // default constructor
	: ptr_ (0)
{}

ACE_INLINE
RtecEventComm::Event_var::Event_var (RtecEventComm::Event *p)
	: ptr_ (p)
{}

ACE_INLINE
RtecEventComm::Event_var::Event_var (const RtecEventComm::Event_var &p) // copy constructor
{
  if (p.ptr_)
  	this->ptr_ = new RtecEventComm::Event(*p.ptr_);
  else
  	this->ptr_ = 0;
}

ACE_INLINE
RtecEventComm::Event_var::~Event_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE RtecEventComm::Event_var &
RtecEventComm::Event_var::operator= (RtecEventComm::Event *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE RtecEventComm::Event_var &
RtecEventComm::Event_var::operator= (const RtecEventComm::Event_var &p)
{
  if (this != &p)
  {
    delete this->ptr_;
    this->ptr_ = new RtecEventComm::Event (*p.ptr_);
  }
  return *this;
}

ACE_INLINE const RtecEventComm::Event *
RtecEventComm::Event_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::Event *
RtecEventComm::Event_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE 
RtecEventComm::Event_var::operator const RtecEventComm::Event &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE 
RtecEventComm::Event_var::operator RtecEventComm::Event &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE 
RtecEventComm::Event_var::operator RtecEventComm::Event &() const// cast 
{
  return *this->ptr_;
}

ACE_INLINE const RtecEventComm::Event &
RtecEventComm::Event_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE RtecEventComm::Event &
RtecEventComm::Event_var::inout (void)
{
  return *this->ptr_;
}

// mapping for fixed size 
ACE_INLINE RtecEventComm::Event &
RtecEventComm::Event_var::out (void)
{
  return *this->ptr_;
}

ACE_INLINE RtecEventComm::Event
RtecEventComm::Event_var::_retn (void)
{
  return *this->ptr_;
}

ACE_INLINE RtecEventComm::Event *
RtecEventComm::Event_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::Event *
RtecEventComm::_tao__seq_EventSet::allocbuf (CORBA::ULong nelems)
{
  return new RtecEventComm::Event[nelems]; // allocate from heap
}

ACE_INLINE void
RtecEventComm::_tao__seq_EventSet::freebuf (RtecEventComm::Event *seq)
{
  delete [] seq;
}

//default constructor
ACE_INLINE 
RtecEventComm::_tao__seq_EventSet::_tao__seq_EventSet (void)
	: maximum_ (0),
	  length_ (0),
	  buffer_ (0),
	  release_ (0) // does not own
{}

// constructor for unbounded seq
ACE_INLINE 
RtecEventComm::_tao__seq_EventSet::_tao__seq_EventSet(CORBA::ULong max )
	: maximum_ (max),
	  length_ (0),
	  buffer_ (RtecEventComm::_tao__seq_EventSet::allocbuf (max)),
	  release_ (1) // owns
{}

// constructor from data buffer
ACE_INLINE 
RtecEventComm::_tao__seq_EventSet::_tao__seq_EventSet (CORBA::ULong max, CORBA::ULong length, 
	RtecEventComm::Event *value, CORBA::Boolean release)
	: maximum_ (max),
	  length_ (length),
	  buffer_ (value),
	  release_ (release) // ownership depends on release
{}

ACE_INLINE CORBA::ULong
RtecEventComm::_tao__seq_EventSet::maximum (void) const
{
  return this->maximum_;
}

ACE_INLINE CORBA::ULong
RtecEventComm::_tao__seq_EventSet::length  (void) const
{
  return this->length_;
}

ACE_INLINE RtecEventComm::Event &
RtecEventComm::_tao__seq_EventSet::operator[] (CORBA::ULong index) // read/write
{
  return this->buffer_[index];
}

ACE_INLINE const RtecEventComm::Event &
RtecEventComm::_tao__seq_EventSet::operator[] (CORBA::ULong index) const // read
{
  return this->buffer_[index];
}

// *************************************************************
// Inline operations for class RtecEventComm::_tao__seq_EventSet_var
// *************************************************************

ACE_INLINE
RtecEventComm::_tao__seq_EventSet_var::_tao__seq_EventSet_var (void) // default constructor
	: ptr_ (0)
{}

ACE_INLINE
RtecEventComm::_tao__seq_EventSet_var::_tao__seq_EventSet_var (RtecEventComm::_tao__seq_EventSet_ptr p)
	: ptr_ (p)
{}

ACE_INLINE
RtecEventComm::_tao__seq_EventSet_var::_tao__seq_EventSet_var (const RtecEventComm::_tao__seq_EventSet_var &p) // copy constructor
{
  if (p.ptr_)
  	this->ptr_ = new RtecEventComm::_tao__seq_EventSet(*p.ptr_);
  else
  	this->ptr_ = 0;
}

ACE_INLINE
RtecEventComm::_tao__seq_EventSet_var::~_tao__seq_EventSet_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE RtecEventComm::_tao__seq_EventSet_var &
RtecEventComm::_tao__seq_EventSet_var::operator= (RtecEventComm::_tao__seq_EventSet *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE RtecEventComm::_tao__seq_EventSet_var &
RtecEventComm::_tao__seq_EventSet_var::operator= (const RtecEventComm::_tao__seq_EventSet_var &p) // deep copy
{
  if (this != &p)
  {
    delete this->ptr_;
    this->ptr_ = new RtecEventComm::_tao__seq_EventSet (*p.ptr_);
  }
  return *this;
}

ACE_INLINE const RtecEventComm::_tao__seq_EventSet *
RtecEventComm::_tao__seq_EventSet_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::_tao__seq_EventSet *
RtecEventComm::_tao__seq_EventSet_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE 
RtecEventComm::_tao__seq_EventSet_var::operator const RtecEventComm::_tao__seq_EventSet &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE 
RtecEventComm::_tao__seq_EventSet_var::operator RtecEventComm::_tao__seq_EventSet &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE 
RtecEventComm::_tao__seq_EventSet_var::operator RtecEventComm::_tao__seq_EventSet &() const// cast 
{
  return *this->ptr_;
}

ACE_INLINE RtecEventComm::Event&
RtecEventComm::_tao__seq_EventSet_var::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

ACE_INLINE const RtecEventComm::_tao__seq_EventSet &
RtecEventComm::_tao__seq_EventSet_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE RtecEventComm::_tao__seq_EventSet &
RtecEventComm::_tao__seq_EventSet_var::inout (void)
{
  return *this->ptr_;
}

// mapping for variable size 
ACE_INLINE RtecEventComm::_tao__seq_EventSet *&
RtecEventComm::_tao__seq_EventSet_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE RtecEventComm::_tao__seq_EventSet *
RtecEventComm::_tao__seq_EventSet_var::_retn (void)
{
  RtecEventComm::_tao__seq_EventSet *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE RtecEventComm::_tao__seq_EventSet *
RtecEventComm::_tao__seq_EventSet_var::ptr (void) const
{
  return this->ptr_;
}

// *************************************************************
// Inline operations for class RtecEventComm::_tao__seq_EventSet_out
// *************************************************************

ACE_INLINE
RtecEventComm::_tao__seq_EventSet_out::_tao__seq_EventSet_out (RtecEventComm::_tao__seq_EventSet *&p)
	: ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
RtecEventComm::_tao__seq_EventSet_out::_tao__seq_EventSet_out (RtecEventComm::_tao__seq_EventSet_var &p) // constructor from _var
	: ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
RtecEventComm::_tao__seq_EventSet_out::_tao__seq_EventSet_out (RtecEventComm::_tao__seq_EventSet_out &p) // copy constructor
	: ptr_ (p.ptr_)
{}

ACE_INLINE RtecEventComm::_tao__seq_EventSet_out &
RtecEventComm::_tao__seq_EventSet_out::operator= (RtecEventComm::_tao__seq_EventSet_out &p)
{
  this->ptr_ = p.ptr_;
  return *this;
}

ACE_INLINE RtecEventComm::_tao__seq_EventSet_out &
RtecEventComm::_tao__seq_EventSet_out::operator= (RtecEventComm::_tao__seq_EventSet *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE 
RtecEventComm::_tao__seq_EventSet_out::operator RtecEventComm::_tao__seq_EventSet *&() // cast
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::_tao__seq_EventSet *&
RtecEventComm::_tao__seq_EventSet_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::_tao__seq_EventSet *
RtecEventComm::_tao__seq_EventSet_out::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::Event& 
RtecEventComm::_tao__seq_EventSet_out::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

ACE_INLINE
RtecEventComm::PushConsumer::PushConsumer (void) // default constructor
{}

ACE_INLINE
RtecEventComm::PushConsumer::PushConsumer (STUB_Object *objref) // constructor
	: ACE_CORBA_1 (Object) (objref)
{}

ACE_INLINE
RtecEventComm::PushConsumer::~PushConsumer (void) // destructor
{}


#if !defined (_RTECEVENTCOMM_PUSHCONSUMER___VAR_CI_)
#define _RTECEVENTCOMM_PUSHCONSUMER___VAR_CI_

// *************************************************************
// Inline operations for class RtecEventComm::PushConsumer_var
// *************************************************************

ACE_INLINE
RtecEventComm::PushConsumer_var::PushConsumer_var (void) // default constructor
	: ptr_ (RtecEventComm::PushConsumer::_nil ())
{}

ACE_INLINE
RtecEventComm::PushConsumer_var::PushConsumer_var (RtecEventComm::PushConsumer_ptr p)
	: ptr_ (p)
{}

ACE_INLINE RtecEventComm::PushConsumer_ptr 
RtecEventComm::PushConsumer_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE
RtecEventComm::PushConsumer_var::PushConsumer_var (const RtecEventComm::PushConsumer_var &p) // copy constructor
	: ptr_ (RtecEventComm::PushConsumer::_duplicate (p.ptr ()))
{}

ACE_INLINE
RtecEventComm::PushConsumer_var::~PushConsumer_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

ACE_INLINE RtecEventComm::PushConsumer_var &
RtecEventComm::PushConsumer_var::operator= (RtecEventComm::PushConsumer_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

ACE_INLINE RtecEventComm::PushConsumer_var &
RtecEventComm::PushConsumer_var::operator= (const RtecEventComm::PushConsumer_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = RtecEventComm::PushConsumer::_duplicate (p.ptr ());
  }
  return *this;
}

ACE_INLINE 
RtecEventComm::PushConsumer_var::operator const RtecEventComm::PushConsumer_ptr &() const // cast
{
  return this->ptr_;
}

ACE_INLINE 
RtecEventComm::PushConsumer_var::operator RtecEventComm::PushConsumer_ptr &() // cast 
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::PushConsumer_ptr 
RtecEventComm::PushConsumer_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::PushConsumer_ptr
RtecEventComm::PushConsumer_var::in (void) const
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::PushConsumer_ptr &
RtecEventComm::PushConsumer_var::inout (void)
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::PushConsumer_ptr &
RtecEventComm::PushConsumer_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = RtecEventComm::PushConsumer::_nil ();
  return this->ptr_;
}

ACE_INLINE RtecEventComm::PushConsumer_ptr 
RtecEventComm::PushConsumer_var::_retn (void)
{
  // yield ownership of managed obj reference
  RtecEventComm::PushConsumer_ptr val = this->ptr_;
  this->ptr_ = RtecEventComm::PushConsumer::_nil ();
  return val;
}


#endif // end #if !defined


#if !defined (_RTECEVENTCOMM_PUSHCONSUMER___OUT_CI_)
#define _RTECEVENTCOMM_PUSHCONSUMER___OUT_CI_

// *************************************************************
// Inline operations for class RtecEventComm::PushConsumer_out
// *************************************************************

ACE_INLINE
RtecEventComm::PushConsumer_out::PushConsumer_out (RtecEventComm::PushConsumer_ptr &p)
	: ptr_ (p)
{
  this->ptr_ = RtecEventComm::PushConsumer::_nil ();
}

ACE_INLINE
RtecEventComm::PushConsumer_out::PushConsumer_out (RtecEventComm::PushConsumer_var &p) // constructor from _var
	: ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = RtecEventComm::PushConsumer::_nil ();
}

ACE_INLINE
RtecEventComm::PushConsumer_out::PushConsumer_out (RtecEventComm::PushConsumer_out &p) // copy constructor
	: ptr_ (p.ptr_)
{}

ACE_INLINE RtecEventComm::PushConsumer_out &
RtecEventComm::PushConsumer_out::operator= (RtecEventComm::PushConsumer_out &p)
{
  this->ptr_ = p.ptr_;
  return *this;
}

ACE_INLINE RtecEventComm::PushConsumer_out &
RtecEventComm::PushConsumer_out::operator= (const RtecEventComm::PushConsumer_var &p)
{
  this->ptr_ = RtecEventComm::PushConsumer::_duplicate (p.ptr ());
  return *this;
}

ACE_INLINE RtecEventComm::PushConsumer_out &
RtecEventComm::PushConsumer_out::operator= (RtecEventComm::PushConsumer_ptr p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE 
RtecEventComm::PushConsumer_out::operator RtecEventComm::PushConsumer_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::PushConsumer_ptr &
RtecEventComm::PushConsumer_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::PushConsumer_ptr 
RtecEventComm::PushConsumer_out::operator-> (void)
{
  return this->ptr_;
}


#endif // end #if !defined

ACE_INLINE
RtecEventComm::PushSupplier::PushSupplier (void) // default constructor
{}

ACE_INLINE
RtecEventComm::PushSupplier::PushSupplier (STUB_Object *objref) // constructor
	: ACE_CORBA_1 (Object) (objref)
{}

ACE_INLINE
RtecEventComm::PushSupplier::~PushSupplier (void) // destructor
{}


#if !defined (_RTECEVENTCOMM_PUSHSUPPLIER___VAR_CI_)
#define _RTECEVENTCOMM_PUSHSUPPLIER___VAR_CI_

// *************************************************************
// Inline operations for class RtecEventComm::PushSupplier_var
// *************************************************************

ACE_INLINE
RtecEventComm::PushSupplier_var::PushSupplier_var (void) // default constructor
	: ptr_ (RtecEventComm::PushSupplier::_nil ())
{}

ACE_INLINE
RtecEventComm::PushSupplier_var::PushSupplier_var (RtecEventComm::PushSupplier_ptr p)
	: ptr_ (p)
{}

ACE_INLINE RtecEventComm::PushSupplier_ptr 
RtecEventComm::PushSupplier_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE
RtecEventComm::PushSupplier_var::PushSupplier_var (const RtecEventComm::PushSupplier_var &p) // copy constructor
	: ptr_ (RtecEventComm::PushSupplier::_duplicate (p.ptr ()))
{}

ACE_INLINE
RtecEventComm::PushSupplier_var::~PushSupplier_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

ACE_INLINE RtecEventComm::PushSupplier_var &
RtecEventComm::PushSupplier_var::operator= (RtecEventComm::PushSupplier_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

ACE_INLINE RtecEventComm::PushSupplier_var &
RtecEventComm::PushSupplier_var::operator= (const RtecEventComm::PushSupplier_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = RtecEventComm::PushSupplier::_duplicate (p.ptr ());
  }
  return *this;
}

ACE_INLINE 
RtecEventComm::PushSupplier_var::operator const RtecEventComm::PushSupplier_ptr &() const // cast
{
  return this->ptr_;
}

ACE_INLINE 
RtecEventComm::PushSupplier_var::operator RtecEventComm::PushSupplier_ptr &() // cast 
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::PushSupplier_ptr 
RtecEventComm::PushSupplier_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::PushSupplier_ptr
RtecEventComm::PushSupplier_var::in (void) const
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::PushSupplier_ptr &
RtecEventComm::PushSupplier_var::inout (void)
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::PushSupplier_ptr &
RtecEventComm::PushSupplier_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = RtecEventComm::PushSupplier::_nil ();
  return this->ptr_;
}

ACE_INLINE RtecEventComm::PushSupplier_ptr 
RtecEventComm::PushSupplier_var::_retn (void)
{
  // yield ownership of managed obj reference
  RtecEventComm::PushSupplier_ptr val = this->ptr_;
  this->ptr_ = RtecEventComm::PushSupplier::_nil ();
  return val;
}


#endif // end #if !defined


#if !defined (_RTECEVENTCOMM_PUSHSUPPLIER___OUT_CI_)
#define _RTECEVENTCOMM_PUSHSUPPLIER___OUT_CI_

// *************************************************************
// Inline operations for class RtecEventComm::PushSupplier_out
// *************************************************************

ACE_INLINE
RtecEventComm::PushSupplier_out::PushSupplier_out (RtecEventComm::PushSupplier_ptr &p)
	: ptr_ (p)
{
  this->ptr_ = RtecEventComm::PushSupplier::_nil ();
}

ACE_INLINE
RtecEventComm::PushSupplier_out::PushSupplier_out (RtecEventComm::PushSupplier_var &p) // constructor from _var
	: ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = RtecEventComm::PushSupplier::_nil ();
}

ACE_INLINE
RtecEventComm::PushSupplier_out::PushSupplier_out (RtecEventComm::PushSupplier_out &p) // copy constructor
	: ptr_ (p.ptr_)
{}

ACE_INLINE RtecEventComm::PushSupplier_out &
RtecEventComm::PushSupplier_out::operator= (RtecEventComm::PushSupplier_out &p)
{
  this->ptr_ = p.ptr_;
  return *this;
}

ACE_INLINE RtecEventComm::PushSupplier_out &
RtecEventComm::PushSupplier_out::operator= (const RtecEventComm::PushSupplier_var &p)
{
  this->ptr_ = RtecEventComm::PushSupplier::_duplicate (p.ptr ());
  return *this;
}

ACE_INLINE RtecEventComm::PushSupplier_out &
RtecEventComm::PushSupplier_out::operator= (RtecEventComm::PushSupplier_ptr p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE 
RtecEventComm::PushSupplier_out::operator RtecEventComm::PushSupplier_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::PushSupplier_ptr &
RtecEventComm::PushSupplier_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::PushSupplier_ptr 
RtecEventComm::PushSupplier_out::operator-> (void)
{
  return this->ptr_;
}


#endif // end #if !defined

ACE_INLINE
RtecEventComm::PullSupplier::PullSupplier (void) // default constructor
{}

ACE_INLINE
RtecEventComm::PullSupplier::PullSupplier (STUB_Object *objref) // constructor
	: ACE_CORBA_1 (Object) (objref)
{}

ACE_INLINE
RtecEventComm::PullSupplier::~PullSupplier (void) // destructor
{}


#if !defined (_RTECEVENTCOMM_PULLSUPPLIER___VAR_CI_)
#define _RTECEVENTCOMM_PULLSUPPLIER___VAR_CI_

// *************************************************************
// Inline operations for class RtecEventComm::PullSupplier_var
// *************************************************************

ACE_INLINE
RtecEventComm::PullSupplier_var::PullSupplier_var (void) // default constructor
	: ptr_ (RtecEventComm::PullSupplier::_nil ())
{}

ACE_INLINE
RtecEventComm::PullSupplier_var::PullSupplier_var (RtecEventComm::PullSupplier_ptr p)
	: ptr_ (p)
{}

ACE_INLINE RtecEventComm::PullSupplier_ptr 
RtecEventComm::PullSupplier_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE
RtecEventComm::PullSupplier_var::PullSupplier_var (const RtecEventComm::PullSupplier_var &p) // copy constructor
	: ptr_ (RtecEventComm::PullSupplier::_duplicate (p.ptr ()))
{}

ACE_INLINE
RtecEventComm::PullSupplier_var::~PullSupplier_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

ACE_INLINE RtecEventComm::PullSupplier_var &
RtecEventComm::PullSupplier_var::operator= (RtecEventComm::PullSupplier_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

ACE_INLINE RtecEventComm::PullSupplier_var &
RtecEventComm::PullSupplier_var::operator= (const RtecEventComm::PullSupplier_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = RtecEventComm::PullSupplier::_duplicate (p.ptr ());
  }
  return *this;
}

ACE_INLINE 
RtecEventComm::PullSupplier_var::operator const RtecEventComm::PullSupplier_ptr &() const // cast
{
  return this->ptr_;
}

ACE_INLINE 
RtecEventComm::PullSupplier_var::operator RtecEventComm::PullSupplier_ptr &() // cast 
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::PullSupplier_ptr 
RtecEventComm::PullSupplier_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::PullSupplier_ptr
RtecEventComm::PullSupplier_var::in (void) const
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::PullSupplier_ptr &
RtecEventComm::PullSupplier_var::inout (void)
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::PullSupplier_ptr &
RtecEventComm::PullSupplier_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = RtecEventComm::PullSupplier::_nil ();
  return this->ptr_;
}

ACE_INLINE RtecEventComm::PullSupplier_ptr 
RtecEventComm::PullSupplier_var::_retn (void)
{
  // yield ownership of managed obj reference
  RtecEventComm::PullSupplier_ptr val = this->ptr_;
  this->ptr_ = RtecEventComm::PullSupplier::_nil ();
  return val;
}


#endif // end #if !defined


#if !defined (_RTECEVENTCOMM_PULLSUPPLIER___OUT_CI_)
#define _RTECEVENTCOMM_PULLSUPPLIER___OUT_CI_

// *************************************************************
// Inline operations for class RtecEventComm::PullSupplier_out
// *************************************************************

ACE_INLINE
RtecEventComm::PullSupplier_out::PullSupplier_out (RtecEventComm::PullSupplier_ptr &p)
	: ptr_ (p)
{
  this->ptr_ = RtecEventComm::PullSupplier::_nil ();
}

ACE_INLINE
RtecEventComm::PullSupplier_out::PullSupplier_out (RtecEventComm::PullSupplier_var &p) // constructor from _var
	: ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = RtecEventComm::PullSupplier::_nil ();
}

ACE_INLINE
RtecEventComm::PullSupplier_out::PullSupplier_out (RtecEventComm::PullSupplier_out &p) // copy constructor
	: ptr_ (p.ptr_)
{}

ACE_INLINE RtecEventComm::PullSupplier_out &
RtecEventComm::PullSupplier_out::operator= (RtecEventComm::PullSupplier_out &p)
{
  this->ptr_ = p.ptr_;
  return *this;
}

ACE_INLINE RtecEventComm::PullSupplier_out &
RtecEventComm::PullSupplier_out::operator= (const RtecEventComm::PullSupplier_var &p)
{
  this->ptr_ = RtecEventComm::PullSupplier::_duplicate (p.ptr ());
  return *this;
}

ACE_INLINE RtecEventComm::PullSupplier_out &
RtecEventComm::PullSupplier_out::operator= (RtecEventComm::PullSupplier_ptr p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE 
RtecEventComm::PullSupplier_out::operator RtecEventComm::PullSupplier_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::PullSupplier_ptr &
RtecEventComm::PullSupplier_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::PullSupplier_ptr 
RtecEventComm::PullSupplier_out::operator-> (void)
{
  return this->ptr_;
}


#endif // end #if !defined

ACE_INLINE
RtecEventComm::PullConsumer::PullConsumer (void) // default constructor
{}

ACE_INLINE
RtecEventComm::PullConsumer::PullConsumer (STUB_Object *objref) // constructor
	: ACE_CORBA_1 (Object) (objref)
{}

ACE_INLINE
RtecEventComm::PullConsumer::~PullConsumer (void) // destructor
{}


#if !defined (_RTECEVENTCOMM_PULLCONSUMER___VAR_CI_)
#define _RTECEVENTCOMM_PULLCONSUMER___VAR_CI_

// *************************************************************
// Inline operations for class RtecEventComm::PullConsumer_var
// *************************************************************

ACE_INLINE
RtecEventComm::PullConsumer_var::PullConsumer_var (void) // default constructor
	: ptr_ (RtecEventComm::PullConsumer::_nil ())
{}

ACE_INLINE
RtecEventComm::PullConsumer_var::PullConsumer_var (RtecEventComm::PullConsumer_ptr p)
	: ptr_ (p)
{}

ACE_INLINE RtecEventComm::PullConsumer_ptr 
RtecEventComm::PullConsumer_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE
RtecEventComm::PullConsumer_var::PullConsumer_var (const RtecEventComm::PullConsumer_var &p) // copy constructor
	: ptr_ (RtecEventComm::PullConsumer::_duplicate (p.ptr ()))
{}

ACE_INLINE
RtecEventComm::PullConsumer_var::~PullConsumer_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

ACE_INLINE RtecEventComm::PullConsumer_var &
RtecEventComm::PullConsumer_var::operator= (RtecEventComm::PullConsumer_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

ACE_INLINE RtecEventComm::PullConsumer_var &
RtecEventComm::PullConsumer_var::operator= (const RtecEventComm::PullConsumer_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = RtecEventComm::PullConsumer::_duplicate (p.ptr ());
  }
  return *this;
}

ACE_INLINE 
RtecEventComm::PullConsumer_var::operator const RtecEventComm::PullConsumer_ptr &() const // cast
{
  return this->ptr_;
}

ACE_INLINE 
RtecEventComm::PullConsumer_var::operator RtecEventComm::PullConsumer_ptr &() // cast 
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::PullConsumer_ptr 
RtecEventComm::PullConsumer_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::PullConsumer_ptr
RtecEventComm::PullConsumer_var::in (void) const
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::PullConsumer_ptr &
RtecEventComm::PullConsumer_var::inout (void)
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::PullConsumer_ptr &
RtecEventComm::PullConsumer_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = RtecEventComm::PullConsumer::_nil ();
  return this->ptr_;
}

ACE_INLINE RtecEventComm::PullConsumer_ptr 
RtecEventComm::PullConsumer_var::_retn (void)
{
  // yield ownership of managed obj reference
  RtecEventComm::PullConsumer_ptr val = this->ptr_;
  this->ptr_ = RtecEventComm::PullConsumer::_nil ();
  return val;
}


#endif // end #if !defined


#if !defined (_RTECEVENTCOMM_PULLCONSUMER___OUT_CI_)
#define _RTECEVENTCOMM_PULLCONSUMER___OUT_CI_

// *************************************************************
// Inline operations for class RtecEventComm::PullConsumer_out
// *************************************************************

ACE_INLINE
RtecEventComm::PullConsumer_out::PullConsumer_out (RtecEventComm::PullConsumer_ptr &p)
	: ptr_ (p)
{
  this->ptr_ = RtecEventComm::PullConsumer::_nil ();
}

ACE_INLINE
RtecEventComm::PullConsumer_out::PullConsumer_out (RtecEventComm::PullConsumer_var &p) // constructor from _var
	: ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = RtecEventComm::PullConsumer::_nil ();
}

ACE_INLINE
RtecEventComm::PullConsumer_out::PullConsumer_out (RtecEventComm::PullConsumer_out &p) // copy constructor
	: ptr_ (p.ptr_)
{}

ACE_INLINE RtecEventComm::PullConsumer_out &
RtecEventComm::PullConsumer_out::operator= (RtecEventComm::PullConsumer_out &p)
{
  this->ptr_ = p.ptr_;
  return *this;
}

ACE_INLINE RtecEventComm::PullConsumer_out &
RtecEventComm::PullConsumer_out::operator= (const RtecEventComm::PullConsumer_var &p)
{
  this->ptr_ = RtecEventComm::PullConsumer::_duplicate (p.ptr ());
  return *this;
}

ACE_INLINE RtecEventComm::PullConsumer_out &
RtecEventComm::PullConsumer_out::operator= (RtecEventComm::PullConsumer_ptr p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE 
RtecEventComm::PullConsumer_out::operator RtecEventComm::PullConsumer_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::PullConsumer_ptr &
RtecEventComm::PullConsumer_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE RtecEventComm::PullConsumer_ptr 
RtecEventComm::PullConsumer_out::operator-> (void)
{
  return this->ptr_;
}


#endif // end #if !defined


/* -*- C++ -*- */

// ============================================================================
//
// = LIBRARY
//    TAO
// 
// = FILENAME
//    params.i
//
// = AUTHOR
//    Chris Cleeland
// 
// ============================================================================

ACE_INLINE
TAO_OA_Parameters::TAO_OA_Parameters (void)
{
}

ACE_INLINE
TAO_OA_Parameters::~TAO_OA_Parameters (void)
{
}

ACE_INLINE void
TAO_OA_Parameters::demux_strategy (TAO_Demux_Strategy strategy)
{
  this->demux_ = strategy;      // Trust that the value is valid!
}

//ACE_INLINE TAO_OA_Parameters::TAO_Demux_Strategy
ACE_INLINE TAO_Demux_Strategy
TAO_OA_Parameters::demux_strategy (void)
{
  return this->demux_;
}

ACE_INLINE void
TAO_OA_Parameters::tablesize (CORBA::ULong tblsize)
{
  this->tablesize_ = tblsize;
}

ACE_INLINE CORBA::ULong
TAO_OA_Parameters::tablesize (void)
{
  return this->tablesize_;
}

ACE_INLINE void 
TAO_OA_Parameters::userdef_lookup_strategy (TAO_Object_Table *&ot)
{
  // provide a way for user defined object key lookup strategies to be plugged
  // in
  ot_ = ot;
  ot = 0;  // we own it now
}

ACE_INLINE TAO_Object_Table *
TAO_OA_Parameters::userdef_lookup_strategy (void)
{
  // return the lookup strategy
  return ot_;
}

ACE_INLINE
TAO_ORB_Parameters::TAO_ORB_Parameters (void)
  : name_service_ior_ (0)
{
}

ACE_INLINE
TAO_ORB_Parameters::~TAO_ORB_Parameters (void)
{
}

ACE_INLINE void
TAO_ORB_Parameters::addr (const ACE_INET_Addr &addr)
{
  this->addr_ = addr;
}

ACE_INLINE const ACE_INET_Addr &
TAO_ORB_Parameters::addr (void)
{
  return this->addr_;
}

ACE_INLINE void
TAO_ORB_Parameters::name_service_ior (CORBA::String ns)
{
  this->name_service_ior_ = ns;
}

ACE_INLINE CORBA::String
TAO_ORB_Parameters::name_service_ior (void)
{
  return this->name_service_ior_;
}


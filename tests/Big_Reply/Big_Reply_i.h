// This may look like C, but it's really -*- C++ -*-
// ===================================================================
/**
 *  @file   Big_Reply_i.h
 *
 *  $Id$
 *
 *  @author Balachandran Natarajan <bala@cs.wustl.edu>
 **/
// ===================================================================

#ifndef TAO_TESTS_BIG_REPLY_I_H
#define TAO_TESTS_BIG_REPLY_I_H
#include "ace/pre.h"

#include "TestS.h"

class Big_Reply_i
  : public virtual POA_Test::Big_Reply
  , public virtual PortableServer::RefCountServantBase
{
public:
  /// Constructor
  Big_Reply_i (CORBA::ORB_ptr orb,
               CORBA::ULong length);

  ///Destructor
  virtual ~Big_Reply_i (void);

  // = The skeleton methods
  virtual Test::Octet_Seq *get_big_reply (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void shutdown (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException));
private:
  /// Our local ORB ptr
  CORBA::ORB_ptr orb_;

  /// Length of the reply sequence
  CORBA::ULong length_;

  /// The reply message
  Test::Octet_Seq_var reply_message_;

};

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma warning(pop)
#endif /* _MSC_VER */

#include "ace/post.h"

#endif /*TAO_TESTS_BIG_REPLY_I_H*/

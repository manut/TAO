//$Id$
#include "Big_Reply_i.h"

Big_Reply_i::Big_Reply_i (CORBA::ORB_ptr orb,
                          CORBA::ULong len)
  : orb_ (orb),
    length_ (len)
{
}

Big_Reply_i::~Big_Reply_i (void)
{
  // no-op
}

Test::Octet_Seq *
Big_Reply_i::get_big_reply (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  Test::Octet_Seq_var reply_mesg;

  ACE_NEW_THROW_EX (reply_mesg,
                    Test::Octet_Seq (this->length_),
                    CORBA::NO_MEMORY ());

  reply_mesg->length (this->length_);

  return reply_mesg._retn ();
}


void
Big_Reply_i::shutdown (CORBA::Environment & /*ACE_TRY_ENV*/)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->orb_->shutdown ();
  ACE_CHECK;
}

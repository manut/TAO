// $Id$
#include "Foo_i.h"
#include "OrbShutdownTask.h"


Foo_i::Foo_i(unsigned num_clients)
  : value_(0),
    num_clients_(num_clients)
{
}


Foo_i::~Foo_i()
{
}


void
Foo_i::op1(void)
  ACE_THROW_SPEC((CORBA::SystemException))
{
}


void
Foo_i::op2(CORBA::Long value)
  ACE_THROW_SPEC((CORBA::SystemException))
{
  this->value_ = value;
}


CORBA::Long
Foo_i::op3(void)
  ACE_THROW_SPEC((CORBA::SystemException))
{
  return this->value_;
}



void
Foo_i::op4(CORBA::Long value)
  ACE_THROW_SPEC((CORBA::SystemException))
{
  this->value_ = value;
}


void
Foo_i::op5(void)
  ACE_THROW_SPEC((CORBA::SystemException, FooException))
{
  throw FooException();
}


void
Foo_i::done(void)
  ACE_THROW_SPEC((CORBA::SystemException))
{
  unsigned num_left = --this->num_clients_;

  if (num_left == 0)
    {
      if (TheOrbShutdownTask::instance()->open(0) != 0)
        {
          ACE_ERROR((LM_ERROR, "(%P|%t)Foo_i::done: "
            "failed to create orb shutdown thread.\n"));
        }
    }
}

// $Id$
#ifndef FOO_I_H
#define FOO_I_H

#include "FooS.h"
#include "ace/CORBA_macros.h"
#include "tao/Environment.h"


class Foo_i : public virtual POA_Foo
{
  public:

    Foo_i(unsigned num_clients);
    virtual ~Foo_i();

    virtual void op1(void)
      ACE_THROW_SPEC((CORBA::SystemException));

    virtual void op2(CORBA::Long value)
      ACE_THROW_SPEC((CORBA::SystemException));

    virtual CORBA::Long op3(void)
      ACE_THROW_SPEC((CORBA::SystemException));

    virtual void op4(CORBA::Long value)
      ACE_THROW_SPEC((CORBA::SystemException));

    virtual void op5(void)
      ACE_THROW_SPEC((CORBA::SystemException, FooException));

    virtual void done(void)
      ACE_THROW_SPEC((CORBA::SystemException));


  private:

    CORBA::Long value_;
    unsigned num_clients_;

    unsigned count_op1_;
    unsigned count_op2_;
    unsigned count_op3_;
    unsigned count_op4_;
    unsigned count_op5_;
};

#endif

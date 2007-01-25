// $Id$
#ifndef FOO_A_I_H
#define FOO_A_I_H

#include "CSD_TP_Foo_A_Export.h"
#include "Foo_AS.h"
#include "Foo_A_Statistics.h"


class CSD_TP_Foo_A_Export Foo_A_i : public virtual POA_Foo_A
{
  public:

    Foo_A_i();
    virtual ~Foo_A_i();

    virtual void op1(void)
      ACE_THROW_SPEC((CORBA::SystemException));

    virtual void op2(CORBA::Long value)
                                 ACE_THROW_SPEC((CORBA::SystemException));

    virtual CORBA::Long op3(CORBA::Long value)
                                 ACE_THROW_SPEC((CORBA::SystemException));

    virtual void op4(CORBA::Long value)
                                 ACE_THROW_SPEC((CORBA::SystemException));

    virtual void op5(void)
      ACE_THROW_SPEC((CORBA::SystemException, FooException));

    virtual void done(void)
      ACE_THROW_SPEC((CORBA::SystemException));

    void gather_stats (Foo_A_Statistics& stats) ;

  private:

    LongVector in_values_ [5];
    unsigned op_count_ [5];
};

#endif

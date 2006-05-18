// $Id$

#include "TruncatableS_impl.h"
#include "ace/OS_NS_stdio.h"

ACE_RCSID(Truncatable, TruncatableS_impl, "$Id$")

Test_impl::Test_impl (CORBA::ORB_ptr orb)
    : orb_ (CORBA::ORB::_duplicate (orb))
{
}

void
Test_impl::op1 (
    const char * id,
    ::OBV_TruncatableTest::BaseValue * iv,
    ::OBV_TruncatableTest::BaseValue_out ov,
    char *& desc
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    ::CORBA::SystemException
  ))
{
  if (TAO_debug_level > 0)
    ACE_DEBUG((LM_DEBUG, "(%P|%t)Test_impl::op1 id=%s basic_data=%u desc=%s \n",
      id, iv->basic_data (), desc));

   char *tmp = CORBA::string_alloc (ACE_OS::strlen (id) + ACE_OS::strlen (desc) + 2);
   ACE_OS::sprintf (tmp, "%s: %s", id, desc);
   CORBA::string_free (desc);
   desc = tmp;

   ov = new ::OBV_OBV_TruncatableTest::BaseValue();
   ov->basic_data (iv->basic_data());
 }


void
Test_impl::op2 (
    ::OBV_TruncatableTest::TValue1 * iv,
    const char * id,
    ::OBV_TruncatableTest::TValue1_out ov,
    char *& desc
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    ::CORBA::SystemException
  ))
{
  if (TAO_debug_level > 0)
    ACE_DEBUG((LM_DEBUG, "(%P|%t)Test_impl::op2 id=%s basic_data=%u data1=%u desc=%s \n",
      id, iv->basic_data (), iv->data1 (), desc));
  char *tmp = CORBA::string_alloc (ACE_OS::strlen (id) + ACE_OS::strlen (desc) + 2);
  ACE_OS::sprintf (tmp, "%s: %s", id, desc);
  CORBA::string_free (desc);
  desc = tmp;

  ov = new ::OBV_OBV_TruncatableTest::TValue1();
  ov->basic_data (iv->basic_data());
  ov->data1 (iv->data1());
}


void
Test_impl::op3 (
  const char * id,
  ::OBV_TruncatableTest::TValue4 * iv,
  ::OBV_TruncatableTest::TValue4_out ov,
  char *& desc
  ACE_ENV_ARG_DECL
)
ACE_THROW_SPEC ((
  ::CORBA::SystemException
))
{
  if (TAO_debug_level > 0)
    ACE_DEBUG((LM_DEBUG, "(%P|%t)Test_impl::op3 id=%s basic_data=%u data=%u data4=%u desc=%s \n",
      id, iv->basic_data (), iv->nv4()->data (), iv->data4 (), desc));

  char *tmp = CORBA::string_alloc (ACE_OS::strlen (id) + ACE_OS::strlen (desc) + 2);
  ACE_OS::sprintf (tmp, "%s: %s", id, desc);
  CORBA::string_free (desc);
  desc = tmp;

  ov = new ::OBV_OBV_TruncatableTest::TValue4();
  ::OBV_OBV_TruncatableTest::NestedValue* nv = new ::OBV_OBV_TruncatableTest::NestedValue();
  nv->data (iv->nv4()->data ());
  ov->basic_data (iv->basic_data());
  ov->nv4 (nv);
  ov->data4 (iv->data4());
}


::OBV_TruncatableTest::BaseValue *
Test_impl::op4 (
  const char * id,
  ::OBV_TruncatableTest::TValue1 * iv1,
  ::CORBA::Short x,
  ::OBV_TruncatableTest::TValue4 * iv2,
  ::OBV_TruncatableTest::TValue4 * iv3,
  ::OBV_TruncatableTest::TValue1 * iv4,
  char *& desc
  ACE_ENV_ARG_DECL
  )
ACE_THROW_SPEC ((
  ::CORBA::SystemException
  ))
{
  if (TAO_debug_level > 0)
  {
    ACE_DEBUG((LM_DEBUG, "(%P|%t)Test_impl::op4 id=%s basic_data=%u data1=%u desc=%s \n",
      id, iv1->basic_data (), iv1->data1 (), desc));
    ACE_DEBUG((LM_DEBUG, "(%P|%t)Test_impl::op4 id=%s basic_data=%u data=%u data4=%u desc=%s \n",
      id, iv2->basic_data (), iv2->nv4()->data (), iv2->data4 (), desc));
    ACE_DEBUG((LM_DEBUG, "(%P|%t)Test_impl::op4 id=%s basic_data=%u data=%u data4=%u desc=%s \n",
      id, iv3->basic_data (), iv3->nv4()->data (), iv3->data4 (), desc));
    ACE_DEBUG((LM_DEBUG, "(%P|%t)Test_impl::op4 id=%s basic_data=%u data1=%u desc=%s \n",
      id, iv4->basic_data (), iv4->data1 (), desc));
  }

  char *tmp = CORBA::string_alloc (ACE_OS::strlen (id) + ACE_OS::strlen (desc) + 2);
  ACE_OS::sprintf (tmp, "%s: %s", id, desc);
  CORBA::string_free (desc);
  desc = tmp;

  ::OBV_TruncatableTest::BaseValue * ov = new ::OBV_OBV_TruncatableTest::BaseValue();
  CORBA::ULong total = x * (iv1->basic_data () + iv2->basic_data () + iv3->basic_data () + iv4->basic_data ());
  ov->basic_data (total);

  return ov;
}


void
Test_impl::shutdown (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->orb_->shutdown (0 ACE_ENV_ARG_PARAMETER);
}
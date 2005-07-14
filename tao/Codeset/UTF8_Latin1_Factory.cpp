// -*- C++ -*-
// $Id$
#include "ace/Dynamic_Service.h"
#include "UTF8_Latin1_Factory.h"

// Instantiate templates that allow discovery of this factory
// in the Service Manager.
#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class ACE_Dynamic_Service<TAO_UTF8_Latin1_Factory>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#pragma instantiate ACE_Dynamic_Service<TAO_UTF8_Latin1_Factory>

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

ACE_STATIC_SVC_DEFINE (TAO_UTF8_Latin1_Factory,
                       ACE_TEXT ("UTF8_Latin1_Factory"),
                       ACE_SVC_OBJ_T,
                       &ACE_SVC_NAME (TAO_UTF8_Latin1_Factory),
                       ACE_Service_Type::DELETE_THIS
                       | ACE_Service_Type::DELETE_OBJ,
                       0)
ACE_FACTORY_DEFINE (TAO_Codeset, TAO_UTF8_Latin1_Factory)
ACE_STATIC_SVC_REQUIRE (TAO_UTF8_Latin1_Factory)

TAO_UTF8_Latin1_Factory::TAO_UTF8_Latin1_Factory()
  : translator_ (0)
{
}

TAO_UTF8_Latin1_Factory::~TAO_UTF8_Latin1_Factory ()
{
  delete this->translator_;
}
int
TAO_UTF8_Latin1_Factory::init (int argc, ACE_TCHAR *argv[])
{
  TAO_Codeset_Translator_Factory::init (argc, argv);
  return 0;
}

CONV_FRAME::CodeSetId
TAO_UTF8_Latin1_Factory::ncs () const
{
  create_translator();
  return this->translator_->ncs();
}

CONV_FRAME::CodeSetId
TAO_UTF8_Latin1_Factory::tcs () const
{
  create_translator();
  return this->translator_->tcs();
}

// Assign either a reference to the existing translator or a new translator
// for input CDR streams
void
TAO_UTF8_Latin1_Factory::assign (TAO_InputCDR *cdr) const
{
  if (cdr)
    {
      create_translator();
      this->assign_i(cdr,this->translator_);
    }
}

// Assign either a reference to the existing translator or a new translator
// for output CDR streams
void
TAO_UTF8_Latin1_Factory::assign (TAO_OutputCDR *cdr) const
{
  if (cdr)
    {
      create_translator();
      this->assign_i(cdr,this->translator_);
    }
}

void
TAO_UTF8_Latin1_Factory::create_translator () const
{
  if (this->translator_ == 0)
  {
    TAO_UTF8_Latin1_Factory * pthis =
      const_cast <TAO_UTF8_Latin1_Factory *>(this);
    ACE_NEW (pthis->translator_, TAO_UTF8_Latin1_Translator);
    if (this->translator_ == 0)
    {
      if (TAO_debug_level)
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("(%P|%t) TAO_UTF8_Latin1_Factory cannot ")
                    ACE_TEXT("create TAO_UTF8_Latin1_Translator\n")
                    ));
    }
  }
}

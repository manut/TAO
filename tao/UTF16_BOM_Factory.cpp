// -*- C++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//    tao
//
// = FILENAME
//    UTF16_BOM_Factory.cpp
//
// = DESCRIPTION
//    Loader for an instance of the UTF16_BOM_Translator.
//
// = AUTHOR
//    Phil Mesnier <mesnier_p@ociweb.com>
//
// ============================================================================

#include "UTF16_BOM_Factory.h"
#include "ace/OS_NS_strings.h"
#include "ace/Dynamic_Service.h"
#include "ace/Log_Msg.h"

// Instantiate templates that allow discovery of this factory
// via the Service Manager.
#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class ACE_Dynamic_Service<UTF16_BOM_Factory>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#pragma instantiate ACE_Dynamic_Service<UTF16_BOM_Factory>

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

ACE_STATIC_SVC_DEFINE (UTF16_BOM_Factory,
                       ACE_TEXT ("UTF16_BOM_Factory"),
                       ACE_SVC_OBJ_T,
                       &ACE_SVC_NAME (UTF16_BOM_Factory),
                       ACE_Service_Type::DELETE_THIS
                       | ACE_Service_Type::DELETE_OBJ,
                       0)
ACE_FACTORY_DEFINE (TAO, UTF16_BOM_Factory)
ACE_STATIC_SVC_REQUIRE (UTF16_BOM_Factory)

UTF16_BOM_Factory::UTF16_BOM_Factory ()
  : translator_ (0)
  , forceBE_ (false)
{
}

UTF16_BOM_Factory::~UTF16_BOM_Factory ()
{
  delete this->translator_;
}

int
UTF16_BOM_Factory::init (int argc, ACE_TCHAR *argv[])
{
  TAO_Codeset_Translator_Factory::init (argc, argv);

  for (int narg = 0; narg < argc;)
  {
    int consumed = parse_one_arg (argc - narg, &argv[narg]);
    if (consumed > 0)
    {
      narg += consumed;
    }
    else
    {
      ACE_ERROR ((LM_ERROR,
        ACE_TEXT ("(%P|%t)UTF16_BOM_Factory parameter error: %s\n")
        ACE_TEXT ("Usage: UTF16_BOM_Factory \"-forceBE\"\n")
        , argv[narg]
        ));
      return -1;
    }
  }
  return 0;
}

int
UTF16_BOM_Factory::parse_one_arg (int argc, ACE_TCHAR *argv[])
{
  ACE_UNUSED_ARG (argc);
  int consumed = 0;
  if (ACE_OS::strcasecmp (argv[0], "-forcebe") == 0)
  {
    this->forceBE_ = true;
    consumed = 1;
  }
  return consumed;
}

CONV_FRAME::CodeSetId
UTF16_BOM_Factory::ncs () const
{
  create_translator();
  return this->translator_->ncs();
}

CONV_FRAME::CodeSetId
UTF16_BOM_Factory::tcs () const
{
  create_translator();
  return this->translator_->tcs();
}

// Assign either a reference to the existing translator or a new translator
// for input CDR streams
void
UTF16_BOM_Factory::assign (TAO_InputCDR *cdr) const
{
  if (cdr)
    {
      create_translator ();
      this->assign_i (cdr, this->translator_);
    }
}

// Assign either a reference to the existing translator or a new translator
// for output CDR streams
void
UTF16_BOM_Factory::assign (TAO_OutputCDR *cdr) const
{
  if (cdr)
    {
      create_translator ();
      this->assign_i (cdr, this->translator_);
    }
}

void
UTF16_BOM_Factory::create_translator () const
{
  if (this->translator_ == 0)
  {
    UTF16_BOM_Factory * pthis = const_cast<UTF16_BOM_Factory *> (this);
    ACE_NEW (pthis->translator_, UTF16_BOM_Translator (this->forceBE_));
    if (this->translator_ == 0)
    {
      ACE_ERROR ((LM_ERROR,
        ACE_TEXT ("(%P|%t) UTF16_BOM_Factory cannot create UTF16_BOM_Translator\n")
        ));
    }
  }
}

// $Id$

// ============================================================================
//
//
// = LIBRARY
//    TAO_IFR_BE_DLL
//
// = FILENAME
//    be_global.cpp
//
// = DESCRIPTION
//    Stores global data specific to the compiler back end.
//
// = AUTHOR
//    Jeff Parsons <parsons@cs.wustl.edu>
//
// ============================================================================

#include "be_global.h"
#include "ast_generator.h"
#include "global_extern.h"
#include "idl_defines.h"

ACE_RCSID (IFR_Service,
           be_global,
           "$Id$")

TAO_IFR_BE_Export BE_GlobalData *be_global = 0;

BE_GlobalData::BE_GlobalData (void)
  : removing_ (I_FALSE),
    holding_scope_name_ (CORBA::string_dup ("TAO_IFR_holding_scope_module")),
    enable_locking_ (I_FALSE),
    do_included_files_ (I_TRUE)
{
}

BE_GlobalData::~BE_GlobalData (void)
{
}

idl_bool
BE_GlobalData::removing (void) const
{
  return this->removing_;
}

void
BE_GlobalData::removing (idl_bool value)
{
  this->removing_ = value;
}

CORBA::ORB_ptr
BE_GlobalData::orb (void) const
{
  return this->orb_.in ();
}

void
BE_GlobalData::orb (CORBA::ORB_ptr orb)
{
  this->orb_ = orb;
}

CORBA::Repository_ptr
BE_GlobalData::repository (void) const
{
  return this->repository_.in ();
}

void
BE_GlobalData::repository (CORBA::Repository_ptr repo)
{
  this->repository_ = repo;
}

CORBA::ModuleDef_ptr
BE_GlobalData::holding_scope (void) const
{
  return this->holding_scope_.in ();
}

void
BE_GlobalData::holding_scope (CORBA::ModuleDef_ptr scope)
{
  this->holding_scope_ = scope;
}

const char *
BE_GlobalData::holding_scope_name (void) const
{
  return this->holding_scope_name_.in ();
}

ACE_Unbounded_Stack<CORBA::Container_ptr> &
BE_GlobalData::ifr_scopes (void)
{
  return this->ifr_scopes_;
}

const char *
BE_GlobalData::filename (void) const
{
  return this->filename_;
}

void
BE_GlobalData::filename (char *fname)
{
  this->filename_ = fname;
}

idl_bool
BE_GlobalData::enable_locking (void) const
{
  return this->enable_locking_;
}

void
BE_GlobalData::enable_locking (idl_bool value)
{
  this->enable_locking_ = value;
}

idl_bool
BE_GlobalData::do_included_files (void) const
{
  return this->do_included_files_;
}

void
BE_GlobalData::do_included_files (idl_bool val)
{
  this->do_included_files_ = val;
}

ACE_CString
BE_GlobalData::orb_args (void) const
{
  return this->orb_args_;
}

void
BE_GlobalData::orb_args (const ACE_CString& args)
{
  this->orb_args_ = args;
}

ACE_CString
BE_GlobalData::spawn_options (void)
{
  return this->orb_args_ + idl_global->idl_flags ();
}

void
BE_GlobalData::parse_args (long &i, char **av)
{
  switch (av[i][1])
    {
      case 'L':
        be_global->enable_locking (I_TRUE);
        break;
      case 'r':
        be_global->removing (I_TRUE);
        break;
      case 'S':
        // Suppress ...
        if (av[i][2] == 'i')
          {
            // ... processing of included IDL files.
            be_global->do_included_files (0);
          }
        else
          {
            ACE_ERROR ((
                LM_ERROR,
                ACE_TEXT ("IDL: I don't understand the '%s' option\n"),
                av[i]
              ));

            ACE_OS::exit (99);
          }
        break;
      default:
        ACE_ERROR ((
            LM_ERROR,
            ACE_TEXT ("IDL: I don't understand the '%s' option\n"),
            av[i]
          ));

        idl_global->set_compile_flags (idl_global->compile_flags ()
                                       | IDL_CF_ONLY_USAGE);
        break;
    }
}

// Does nothing in this backend.
void
BE_GlobalData::prep_be_arg (char *)
{
}

// Does nothing in this backend.
void
BE_GlobalData::arg_post_proc (void)
{
}

void
BE_GlobalData::usage (void) const
{
  ACE_DEBUG ((
      LM_DEBUG,
      ACE_TEXT (" -L\t\t\tEnable locking at the IDL file level\n")
    ));
  ACE_DEBUG ((
      LM_DEBUG,
      ACE_TEXT (" -r\t\t\tRemove contents of IDL file(s) from repository\n")
    ));
  ACE_DEBUG ((
      LM_DEBUG,
      ACE_TEXT (" -Si\t\t\tSuppress processing of included IDL files\n")
    ));
}

AST_Generator *
BE_GlobalData::generator_init (void)
{
  AST_Generator *gen = 0;
  ACE_NEW_RETURN (gen,
                  AST_Generator,
                  0);             
  return gen;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class ACE_Unbounded_Stack<CORBA::Container_ptr>;
template class ACE_Node<CORBA::Container_ptr>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#pragma instantiate ACE_Unbounded_Stack<CORBA::Container_ptr>
#pragma instantiate ACE_Node<CORBA::Container_ptr>

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

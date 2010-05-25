
//=============================================================================
/**
 *  @file    be_component.cpp
 *
 *  $Id$
 *
 *  Extension of class AST_Component that provides additional means for C++
 *  mapping of an interface.
 *
 *
 *  @author Jeff Parsons
 */
//=============================================================================

#include "be_component.h"
#include "be_visitor.h"

#include "ast_mirror_port.h"
#include "ast_uses.h"
#include "ast_provides.h"
#include "ast_attribute.h"

#include "global_extern.h"
#include "utl_err.h"

be_component::be_component (UTL_ScopedName *n,
                            AST_Component *base_component,
                            AST_Type **supports,
                            long n_supports,
                            AST_Interface **supports_flat,
                            long n_supports_flat)
  : COMMON_Base (false,
                 false),
    AST_Decl (AST_Decl::NT_component,
              n),
    AST_Type (AST_Decl::NT_component,
              n),
    UTL_Scope (AST_Decl::NT_component),
    AST_Interface (n,
                   supports,
                   n_supports,
                   supports_flat,
                   n_supports_flat,
                   false,
                   false),
    AST_Component (n,
                   base_component,
                   supports,
                   n_supports,
                   supports_flat,
                   n_supports_flat),
    be_scope (AST_Decl::NT_component),
    be_decl (AST_Decl::NT_component,
             n),
    be_type (AST_Decl::NT_component,
             n),
    be_interface (n,
                  supports,
                  n_supports,
                  supports_flat,
                  n_supports_flat,
                  false,
                  false),
    n_provides_ (0UL),
    n_remote_provides_ (0UL),
    n_uses_ (0UL),
    n_remote_uses_ (0UL),
    has_uses_multiple_ (false),
    n_publishes_ (0UL),
    n_consumes_ (0UL),
    n_emits_ (0UL)
{
  this->size_type (AST_Type::VARIABLE);
  this->has_constructor (true);
}

be_component::~be_component (void)
{
}

be_component *
be_component::base_component (void) const
{
  return
    be_component::narrow_from_decl (
      this->AST_Component::base_component ());
}

void
be_component::redefine (AST_Interface *from)
{
  be_component *bc = be_component::narrow_from_decl (from);
  this->var_out_seq_decls_gen_ = bc->var_out_seq_decls_gen_;
  AST_Component::redefine (from);
}

void
be_component::destroy ()
{
  this->be_interface::destroy ();
  this->AST_Component::destroy ();
}

int
be_component::accept (be_visitor *visitor)
{
  return (idl_global->ignore_idl3 ()
            ? 0
            : visitor->visit_component (this));
}

AST_Structure *
be_component::be_add_structure (AST_Structure *t)
{
  return this->fe_add_structure (t);
}

AST_Typedef *
be_component::be_add_typedef (AST_Typedef *t)
{
  return this->fe_add_typedef (t);
}

ACE_CDR::ULong
be_component::n_provides (void) const
{
  return this->n_provides_;
}

ACE_CDR::ULong
be_component::n_remote_provides (void) const
{
  return this->n_remote_provides_;
}

ACE_CDR::ULong
be_component::n_uses (void) const
{
  return this->n_uses_;
}

ACE_CDR::ULong
be_component::n_remote_uses (void) const
{
  return this->n_remote_uses_;
}

bool
be_component::has_uses_multiple (void) const
{
  return this->has_uses_multiple_;
}

ACE_CDR::ULong
be_component::n_publishes (void) const
{
  return this->n_publishes_;
}

ACE_CDR::ULong
be_component::n_consumes (void) const
{
  return this->n_consumes_;
}

ACE_CDR::ULong
be_component::n_emits (void) const
{
  return this->n_emits_;
}

IMPL_NARROW_FROM_DECL (be_component)
IMPL_NARROW_FROM_SCOPE (be_component)

void
be_component::scan (UTL_Scope *s)
{
  if (s == 0)
    {
      return;
    }

  AST_Extended_Port *ep = 0;
  AST_Mirror_Port *mp = 0;
  AST_Uses *u = 0;
  AST_Provides *p = 0;
  AST_Attribute *a = 0;

  for (UTL_ScopeActiveIterator i (s, UTL_Scope::IK_both);
       !i.is_done ();
       i.next ())
    {
      AST_Decl *d = i.item ();

      switch (d->node_type ())
        {
          case AST_Decl::NT_provides:
            ++this->n_provides_;
            p = AST_Provides::narrow_from_decl (d);
            
            if (!p->provides_type ()->is_local ())
              {
                ++this->n_remote_provides_;
              }
              
            continue;
          case AST_Decl::NT_uses:
            ++this->n_uses_;
            u = AST_Uses::narrow_from_decl (d);
            
            if (u->is_multiple ())
              {
                this->has_uses_multiple_ = true;
              }
              
            if (!u->uses_type ()->is_local ())
              {
                ++this->n_remote_uses_;
              }
              
            continue;
          case AST_Decl::NT_publishes:
            ++this->n_publishes_;
            continue;
          case AST_Decl::NT_consumes:
            ++this->n_consumes_;
            continue;
          case AST_Decl::NT_emits:
            ++this->n_emits_;
            continue;
          case AST_Decl::NT_ext_port:
            ep = AST_Extended_Port::narrow_from_decl (d);
            this->scan (ep->port_type ());
            continue;
          case AST_Decl::NT_mirror_port:
            mp = AST_Mirror_Port::narrow_from_decl (d);
            this->mirror_scan (mp->port_type ());
            continue;
          case AST_Decl::NT_attr:
            a = AST_Attribute::narrow_from_decl (d);;
            
            if (!a->readonly ())
              {
                this->has_rw_attributes_ = true;
              }
              
            continue;
          default:
            continue;
        }
    }

  AST_Component *c = AST_Component::narrow_from_scope (s);

  if (c != 0)
    {
      this->scan (c->base_component ());
    }
}

void
be_component::mirror_scan (AST_PortType *p)
{
  for (UTL_ScopeActiveIterator i (p, UTL_Scope::IK_decls);
       !i.is_done ();
       i.next ())
    {
      AST_Decl *d = i.item ();

      switch (d->node_type ())
        {
          case AST_Decl::NT_provides:
            ++this->n_uses_;
            continue;
          case AST_Decl::NT_uses:
            ++this->n_provides_;
            continue;
          default:
            continue;
        }
    }
}


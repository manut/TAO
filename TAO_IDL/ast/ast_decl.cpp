// $Id$

/*

COPYRIGHT

Copyright 1992, 1993, 1994 Sun Microsystems, Inc.  Printed in the United
States of America.  All Rights Reserved.

This product is protected by copyright and distributed under the following
license restricting its use.

The Interface Definition Language Compiler Front End (CFE) is made
available for your use provided that you include this license and copyright
notice on all media and documentation and the software program in which
this product is incorporated in whole or part. You may copy and extend
functionality (but may not remove functionality) of the Interface
Definition Language CFE without charge, but you are not authorized to
license or distribute it to anyone else except as part of a product or
program developed by you or with the express written consent of Sun
Microsystems, Inc. ("Sun").

The names of Sun Microsystems, Inc. and any of its subsidiaries or
affiliates may not be used in advertising or publicity pertaining to
distribution of Interface Definition Language CFE as permitted herein.

This license is effective until terminated by Sun for failure to comply
with this license.  Upon termination, you shall destroy or return all code
and documentation for the Interface Definition Language CFE.

INTERFACE DEFINITION LANGUAGE CFE IS PROVIDED AS IS WITH NO WARRANTIES OF
ANY KIND INCLUDING THE WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS
FOR A PARTICULAR PURPOSE, NONINFRINGEMENT, OR ARISING FROM A COURSE OF
DEALING, USAGE OR TRADE PRACTICE.

INTERFACE DEFINITION LANGUAGE CFE IS PROVIDED WITH NO SUPPORT AND WITHOUT
ANY OBLIGATION ON THE PART OF Sun OR ANY OF ITS SUBSIDIARIES OR AFFILIATES
TO ASSIST IN ITS USE, CORRECTION, MODIFICATION OR ENHANCEMENT.

SUN OR ANY OF ITS SUBSIDIARIES OR AFFILIATES SHALL HAVE NO LIABILITY WITH
RESPECT TO THE INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY
INTERFACE DEFINITION LANGUAGE CFE OR ANY PART THEREOF.

IN NO EVENT WILL SUN OR ANY OF ITS SUBSIDIARIES OR AFFILIATES BE LIABLE FOR
ANY LOST REVENUE OR PROFITS OR OTHER SPECIAL, INDIRECT AND CONSEQUENTIAL
DAMAGES, EVEN IF SUN HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.

Use, duplication, or disclosure by the government is subject to
restrictions as set forth in subparagraph (c)(1)(ii) of the Rights in
Technical Data and Computer Software clause at DFARS 252.227-7013 and FAR
52.227-19.

Sun, Sun Microsystems and the Sun logo are trademarks or registered
trademarks of Sun Microsystems, Inc.

SunSoft, Inc.
2550 Garcia Avenue
Mountain View, California  94043

NOTE:

SunOS, SunSoft, Sun, Solaris, Sun Microsystems or the Sun logo are
trademarks or registered trademarks of Sun Microsystems, Inc.

 */

/*
 * ast_decl.cc - Implementation of class AST_Decl
 *
 * AST_Decl is the base class for all AST nodes except AST_Expression.
 * AST_Decls have a node type (a value from the enum AST_Decl::NodeType)
 * a name (a UTL_ScopedName) and a list of pragmas (a UTL_StrList).
 * Additionally AST_Decl nodes record the scope of definition, the
 * file name in which they were defined, the line on which they were
 * defined in that file, and a boolean denoting whether this is the
 * main file or an #include'd file.
 */

#include        "idl.h"
#include        "idl_extern.h"

ACE_RCSID(ast, ast_decl, "$Id$")

/*
 * Constructor(s) and destructor
 */

AST_Decl::AST_Decl()
  : pd_imported(I_FALSE),
    pd_in_main_file(I_FALSE),
    pd_defined_in(NULL),
    pd_node_type(NT_module),
    pd_line(-1),
    pd_file_name(NULL),
    pd_name(NULL),
    pd_local_name(NULL),
    pd_original_local_name (NULL),
    pd_pragmas(NULL),
    pd_added(I_FALSE)
{
}

AST_Decl::AST_Decl(NodeType nt, UTL_ScopedName *n, UTL_StrList *p)
  : pd_imported(idl_global->imported()),
    pd_in_main_file(idl_global->in_main_file()),
    pd_defined_in(idl_global->scopes()->depth() > 0
                  ? idl_global->scopes()->top()
                  : 0),
    pd_node_type(nt),
    pd_line(idl_global->lineno()),
    pd_file_name(idl_global->filename()),
    pd_local_name(n == NULL ? 0 : n->last_component()),
    pd_pragmas(p),
    pd_added(I_FALSE)
{
  compute_full_name (n);

  // Keep the name _cxx_ removed, if any.
  if (n != 0)
    {
      this->original_local_name (n->last_component ());
    }
}

/*
 * Private operations
 */

/*
 * Compute the full scoped name of an AST node
 */
void
AST_Decl::compute_full_name(UTL_ScopedName *n)
{
  UTL_ScopedName        *cn = NULL;
  AST_Decl              *d  = NULL;

  /*
   * Initialize this name to NULL
   */
  pd_name = NULL;
  /*
   * Global scope?
   */
  if (defined_in() == NULL) {
    pd_name = n;
    return;
  }
  /*
   * OK, not global. So copy name of containing scope, then
   * smash last cdr of copy with new component
   */
  d = ScopeAsDecl(defined_in());
  if (d != NULL)
    cn = d->name();
  if (cn != NULL)
    pd_name = (UTL_ScopedName *) cn->copy();
  if (pd_name == NULL)
    pd_name = new UTL_ScopedName(local_name(), NULL);
  else
    pd_name->nconc(new UTL_ScopedName(local_name(), NULL));
}

/*
 * Public operations
 */

/*
 * Return TRUE if one of my ancestor scopes is "s"
 * and FALSE otherwise
 */
idl_bool
AST_Decl::has_ancestor(AST_Decl *s)
{
  if (this == s)
    return I_TRUE;
  if (pd_defined_in == NULL)
    return I_FALSE;
  return ScopeAsDecl(pd_defined_in)->has_ancestor(s);
}

/*
 * Dump this AST_Decl to the ostream o
 */
void
AST_Decl::dump(ostream &o)
{
  pd_local_name->dump(o);
}

/*
 * Redefinition of inherited virtual operations
 */

/*
 * Data accessors
 */

idl_bool
AST_Decl::imported()
{
  return pd_imported;
}

void
AST_Decl::set_imported(idl_bool is_it)
{
  pd_imported = is_it;
}

idl_bool
AST_Decl::in_main_file()
{
  return pd_in_main_file;
}

void
AST_Decl::set_in_main_file(idl_bool is_it)
{
  pd_in_main_file = is_it;
}

idl_bool
AST_Decl::added()
{
  return pd_added;
}

void
AST_Decl::set_added(idl_bool is_it)
{
  pd_added = is_it;
}

UTL_Scope *
AST_Decl::defined_in()
{
  return pd_defined_in;
}

void
AST_Decl::set_defined_in(UTL_Scope *s)
{
  pd_defined_in = s;
}

AST_Decl::NodeType
AST_Decl::node_type()
{
  return pd_node_type;
}

long
AST_Decl::line()
{
  return pd_line;
}

void
AST_Decl::set_line(long l)
{
  pd_line = l;
}

UTL_String *
AST_Decl::file_name()
{
  return pd_file_name;
}

void
AST_Decl::set_file_name(UTL_String *s)
{
  pd_file_name = s;
}

UTL_ScopedName *
AST_Decl::name()
{
  return pd_name;
}


// @@ Wherever compute_* are called, we should remember to delete them
//    after use.  

// Variation of the <name>. Computes scoped name string, applying
// prefix and suffix to the local name component. 
UTL_ScopedName *
AST_Decl::compute_name (const char *prefix, const char *suffix)
{
  if (prefix == 0 || suffix == 0)
    return 0;

  UTL_ScopedName *result_name = NULL;

  // Prepare prefix_<local_name>_suffix string.

  ACE_CString suffix_str (suffix);
  ACE_CString local_str (this->local_name ()->get_string ());
  
  ACE_CString result_local_str (prefix);
  result_local_str += local_str;
  result_local_str += suffix_str;

  // Identifier for the resulting local name.
  Identifier *result_local_id = new Identifier (result_local_str.c_str (),
                                                1,
                                                0,
                                                I_FALSE);
  
  // UTL_Scoped name for the resulting local name.
  UTL_ScopedName *result_local_name = new UTL_ScopedName (result_local_id,
                                                          NULL);
  
  // Global scope?
  if (this->defined_in () == NULL) 
    {
      result_name = result_local_name;
    }
  else
    {
      // OK, not global. So copy name of containing scope, then 
      // smash last cdr of copy with new component.
      
      AST_Decl *d = ScopeAsDecl(defined_in());
      if (d != NULL)
        {
          UTL_ScopedName *cn = d->name();
          if (cn != NULL) 
            {
              result_name = (UTL_ScopedName *) cn->copy();
              if (result_name == NULL)
                {
                  result_name = result_local_name;
                }
              else
                result_name->nconc(result_local_name);
            }
        }
    }
  
  return result_name;
  
}





void
AST_Decl::set_name(UTL_ScopedName *n)
{
  pd_name = n;
  if (n != NULL)
    {
      pd_local_name = n->last_component();

      // The name without _cxx_ prefix removed, if there was any. 
      original_local_name (n->last_component ());
    }
}

Identifier *
AST_Decl::local_name()
{
  return pd_local_name;
}

Identifier *
AST_Decl::compute_local_name (const char *prefix, const char *suffix)
{
  if (prefix == 0 || suffix == 0)
    return 0;

  // Init the result with prefix.
  ACE_CString result_str (prefix);
  
  // Put local.
  result_str += ACE_CString (this->local_name ()->get_string ());

  // Put suffix.
  result_str += ACE_CString (suffix);

  // Identifier for the resulting local name.
  Identifier *result_id = new Identifier (result_str.c_str (),
                                          1,
                                          0,
                                          I_FALSE);
  return result_id;
}

// If there is _cxx_ in the beginning, we will remove that and keep
// a copy of the original name. TAO IDL's front end adds _cxx_
// prefix to the all the reserved keywords. But when we invoke the
// operation remotely, we should be sending only the name with out
// "_cxx_" prefix.

void
AST_Decl::original_local_name (Identifier *local_name)
{
  // Remove _cxx_ if it is present.
  if (ACE_OS::strstr (local_name->get_string (), "_cxx_") == local_name->get_string ())
    {
      // CSting class is good to do this stuff.
      ACE_CString name_str (local_name->get_string ());
      
      // Remove _cxx_.
      name_str = name_str.substr (ACE_OS::strlen ("_cxx_"));

      // Assign to the Identifier variable.
      this->pd_original_local_name = new Identifier (name_str.c_str (),
                                                     1,
                                                     0,
                                                     I_FALSE);
    }
  else
    {
      this->pd_original_local_name = local_name;
    }
}

Identifier *
AST_Decl::original_local_name ()
{
  return pd_original_local_name;
}

void
AST_Decl::add_pragmas(UTL_StrList *p)
{
  if (p != NULL) {
    if (pd_pragmas != NULL)
      pd_pragmas->nconc(p);
    else
      pd_pragmas = p;
  }
}

UTL_StrList *
AST_Decl::pragmas()
{
  return pd_pragmas;
}

/*
 * Narrowing methods for AST_Decl
 */
IMPL_NARROW_METHODS0(AST_Decl)
IMPL_NARROW_FROM_DECL(AST_Decl)

/*
** Narrowing methods for COMMON_Base
*/
IMPL_NARROW_METHODS0(COMMON_Base)

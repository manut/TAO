// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    be_structure.cpp
//
// = DESCRIPTION
//    Extension of class AST_Structure that provides additional means for C++
//    mapping.
//
// = AUTHOR
//    Copyright 1994-1995 by Sun Microsystems, Inc.
//    and
//    Aniruddha Gokhale
//
// ============================================================================

#include        "idl.h"
#include        "idl_extern.h"
#include        "be.h"

ACE_RCSID(be, be_structure, "$Id$")


/*
 * BE_Structure
 */
be_structure::be_structure (void)
{
}

be_structure::be_structure (UTL_ScopedName *n,
                            UTL_StrList *p,
                            idl_bool local,
                            idl_bool abstract)
  : AST_Decl (AST_Decl::NT_struct, n, p),
    UTL_Scope (AST_Decl::NT_struct),
    COMMON_Base (local, abstract)
{
}

// generate the _var definition for ourself
int
be_structure::gen_var_defn (char *)
{
  TAO_OutStream *ch; // output stream
  TAO_NL  nl;        // end line
  char namebuf [NAMEBUFSIZE];  // names

  ACE_OS::memset (namebuf,
                  '\0',
                  NAMEBUFSIZE);

  ACE_OS::sprintf (namebuf,
                   "%s_var",
                   this->local_name ()->get_string ());

  // retrieve a singleton instance of the code generator
  TAO_CodeGen *cg = TAO_CODEGEN::instance ();

  ch = cg->client_header ();

  // generate the var definition (always in the client header).
  // Depending upon the data type, there are some differences which
  // we account for here.

  ch->indent (); // start with whatever was our current indent level
  *ch << "class " << idl_global->stub_export_macro ()
      << " " << namebuf << nl;
  *ch << "{" << nl;
  *ch << "public:\n";
  ch->incr_indent ();
  // default constr
  *ch << namebuf << " (void); // default constructor" << nl;
  // constr
  *ch << namebuf << " (" << this->local_name () << " *);" << nl;
  // copy constructor
  *ch << namebuf << " (const " << namebuf <<
    " &); // copy constructor" << nl;

  // fixed-size types only
  if (this->size_type () == be_decl::FIXED)
    {
      *ch << namebuf << " (const " << this->local_name ()
          << " &); // fixed-size types only" << nl;
    }

  // destructor
  *ch << "~" << namebuf << " (void); // destructor" << nl;
  *ch << nl;
  // assignment operator from a pointer
  *ch << namebuf << " &operator= (" << this->local_name () << " *);" << nl;
  // assignment from _var
  *ch << namebuf << " &operator= (const " << namebuf << " &);" << nl;

  // fixed-size types only
  if (this->size_type () == be_decl::FIXED)
    {
      *ch << namebuf << " &operator= (const " << this->local_name ()
          << " &); // fixed-size types only" << nl;
    }

  // arrow operator
  *ch << local_name () << " *operator-> (void);" << nl;
  *ch << "const " << this->local_name ()
      << " *operator-> (void) const;" << nl;
  *ch << nl;

  // other extra types (cast operators, [] operator, and others)
  *ch << "operator const " << this->local_name () << " &() const;" << nl;
  *ch << "operator " << this->local_name () << " &();" << nl;
  *ch << "operator " << this->local_name () << " &() const;" << nl;

  if (this->size_type () == be_decl::VARIABLE)
    {
      *ch << "operator " << this->local_name ()
          << " *&(); // variable-size types only" << nl;
    }

  *ch << nl;
  *ch << "// in, inout, out, _retn " << nl;
  // the return types of in, out, inout, and _retn are based on the
  // parameter passing rules and the base type
  if (this->size_type () == be_decl::FIXED)
    {
      *ch << "const " << this->local_name () << " &in (void) const;" << nl;
      *ch << local_name () << " &inout (void);" << nl;
      *ch << local_name () << " &out (void);" << nl;
      *ch << local_name () << " _retn (void);" << nl;
    }
  else
    {
      *ch << "const " << this->local_name () << " &in (void) const;" << nl;
      *ch << local_name () << " &inout (void);" << nl;
      *ch << local_name () << " *&out (void);" << nl;
      *ch << local_name () << " *_retn (void);" << nl;
    }

  // generate an additional member function
  // that returns the underlying pointer
  *ch << this->local_name () << " *ptr (void) const;\n";

  *ch << "\n";
  ch->decr_indent ();

  // generate the private section
  *ch << "private:\n";
  ch->incr_indent ();
  *ch << this->local_name () << " *ptr_;\n";
  ch->decr_indent ();
  *ch << "};\n\n";

  return 0;
}

// Implementation of the _var class, generated in the inline file.
int
be_structure::gen_var_impl (char *,
                            char *)
{
  TAO_OutStream *ci; // output stream
  TAO_NL  nl;        // end line
  char fname [NAMEBUFSIZE];  // to hold the full and
  char lname [NAMEBUFSIZE];  // local _var names

  ACE_OS::memset (fname, '\0', NAMEBUFSIZE);
  ACE_OS::sprintf (fname, "%s_var", this->full_name ());

  ACE_OS::memset (lname, '\0', NAMEBUFSIZE);
  ACE_OS::sprintf (lname, "%s_var", this->local_name ()->get_string ());

  // retrieve a singleton instance of the code generator
  TAO_CodeGen *cg = TAO_CODEGEN::instance ();

  ci = cg->client_inline ();

  ci->indent (); // start with whatever was our current indent level

  *ci << "// *************************************************************"
      << nl;
  *ci << "// Inline operations for class " << fname << nl;
  *ci << "// *************************************************************\n\n";

  // default constr
  *ci << "ACE_INLINE" << nl;
  *ci << fname << "::" << lname
      << " (void) // default constructor" << nl;
  *ci << "  " << ": ptr_ (0)" << nl;
  *ci << "{}\n\n";

  // constr from a pointer
  ci->indent ();
  *ci << "ACE_INLINE" << nl;
  *ci << fname << "::" << lname << " (" << this->local_name ()
      << " *p)" << nl;
  *ci << "  : ptr_ (p)" << nl;
  *ci << "{}\n\n";

  // copy constructor
  ci->indent ();
  *ci << "ACE_INLINE" << nl;
  *ci << fname << "::" << lname << " (const ::" << fname
      << " &p) // copy constructor" << nl;
  *ci << "{\n";
  ci->incr_indent ();
  *ci << "if (p.ptr_)" << nl;
  *ci << "  ACE_NEW (this->ptr_, " << "::" << this->name ()
      << " (*p.ptr_));" << nl;
  *ci << "else" << nl;
  *ci << "  this->ptr_ = 0;\n";
  ci->decr_indent ();
  *ci << "}\n\n";

  // fixed-size types only
  if (this->size_type () == be_decl::FIXED)
    {
      *ci << "// fixed-size types only" << nl;
      *ci << "ACE_INLINE" << nl;
      *ci << fname << "::" << lname << " (const "
          << "::" << this->name () << " &p)" << nl;
      *ci << "{\n";
      ci->incr_indent ();
      *ci << "ACE_NEW (this->ptr_, " << "::" << this->name ()
          << " (p));\n";
      ci->decr_indent ();
      *ci << "}\n\n";
    }

  // destructor
  ci->indent ();
  *ci << "ACE_INLINE" << nl;
  *ci << fname << "::~" << lname << " (void) // destructor" << nl;
  *ci << "{\n";
  ci->incr_indent ();
  *ci << "delete this->ptr_;\n";
  ci->decr_indent ();
  *ci << "}\n\n";

  // assignment operator from a pointer
  ci->indent ();
  *ci << "ACE_INLINE " << fname << " &" << nl;
  *ci << fname << "::operator= (" << this->local_name ()
      << " *p)" << nl;
  *ci << "{\n";
  ci->incr_indent ();
  *ci << "delete this->ptr_;" << nl;
  *ci << "this->ptr_ = p;" << nl;
  *ci << "return *this;\n";
  ci->decr_indent ();
  *ci << "}\n\n";

  // assignment operator from _var
  ci->indent ();
  *ci << "ACE_INLINE ::" << fname << " &" << nl;
  *ci << fname << "::operator= (const ::" << fname
      << " &p)" << nl;
  *ci << "{\n";
  ci->incr_indent ();
  *ci << "if (this != &p)" << nl;
  *ci << "{\n";
  ci->incr_indent ();
  *ci << "delete this->ptr_;" << nl;
  *ci << "ACE_NEW_RETURN (this->ptr_, " << "::" << this->name ()
      << " (*p.ptr_), *this);\n";
  ci->decr_indent ();
  *ci << "}" << nl;
  *ci << "return *this;\n";
  ci->decr_indent ();
  *ci << "}\n\n";

  // fixed-size types only
  if (this->size_type () == be_decl::FIXED)
    {
      ci->indent ();
      *ci << "// fixed-size types only" << nl;
      *ci << "ACE_INLINE " << fname << " &" << nl;
      *ci << fname << "::operator= (const " << "::" << this->name ()
          << " &p)" << nl;
      *ci << "{\n";
      ci->incr_indent ();
      *ci << "if (this->ptr_ != &p)" << nl;
      *ci << "{\n";
      ci->incr_indent ();
      *ci << "delete this->ptr_;" << nl;
      *ci << "ACE_NEW_RETURN (this->ptr_, ::"
          << this->name () << " (p), *this);\n";
      ci->decr_indent ();
      *ci << "}" << nl;
      *ci << "return *this;\n";
      ci->decr_indent ();
      *ci << "}\n\n";
    }

  // two arrow operators
  ci->indent ();
  *ci << "ACE_INLINE const " << "::" << this->name () << " *" << nl;
  *ci << fname << "::operator-> (void) const" << nl;
  *ci << "{\n";
  ci->incr_indent ();
  *ci << "return this->ptr_;\n";
  ci->decr_indent ();
  *ci << "}\n\n";

  ci->indent ();
  *ci << "ACE_INLINE " << "::" << this->name () << " *" << nl;
  *ci << fname << "::operator-> (void)" << nl;
  *ci << "{\n";
  ci->incr_indent ();
  *ci << "return this->ptr_;\n";
  ci->decr_indent ();
  *ci << "}\n\n";

  // other extra methods - 3 cast operator ()
  ci->indent ();
  *ci << "ACE_INLINE" << nl;
  *ci << fname << "::operator const " << "::" << this->name ()
      << " &() const // cast" << nl;
  *ci << "{\n";
  ci->incr_indent ();
  *ci << "return *this->ptr_;\n";
  ci->decr_indent ();
  *ci << "}\n\n";

  ci->indent ();
  *ci << "ACE_INLINE" << nl;
  *ci << fname << "::operator " << "::" << this->name ()
      << " &() // cast " << nl;
  *ci << "{\n";
  ci->incr_indent ();
  *ci << "return *this->ptr_;\n";
  ci->decr_indent ();
  *ci << "}\n\n";

  ci->indent ();
  *ci << "ACE_INLINE" << nl;
  *ci << fname << "::operator " << "::" << this->name ()
      << " &() const // cast " << nl;
  *ci << "{\n";
  ci->incr_indent ();
  *ci << "return *this->ptr_;\n";
  ci->decr_indent ();
  *ci << "}\n\n";

  // variable-size types only
  if (this->size_type () == be_decl::VARIABLE)
    {
      ci->indent ();
      *ci << "// variable-size types only" << nl;
      *ci << "ACE_INLINE" << nl;
      *ci << fname << "::operator " << "::" << this->name ()
          << " *&() // cast " << nl;
      *ci << "{\n";
      ci->incr_indent ();
      *ci << "return this->ptr_;\n";
      ci->decr_indent ();
      *ci << "}\n\n";
    }

  // in, inout, out, and _retn
  ci->indent ();
  *ci << "ACE_INLINE const " << "::" << this->name () << " &" << nl;
  *ci << fname << "::in (void) const" << nl;
  *ci << "{\n";
  ci->incr_indent ();
  *ci << "return *this->ptr_;\n";
  ci->decr_indent ();
  *ci << "}\n\n";

  ci->indent ();
  *ci << "ACE_INLINE " << "::" << this->name () << " &" << nl;
  *ci << fname << "::inout (void)" << nl;
  *ci << "{\n";
  ci->incr_indent ();
  *ci << "return *this->ptr_;\n";
  ci->decr_indent ();
  *ci << "}\n\n";

  // the out is handled differently based on our size type
  ci->indent ();
  if (this->size_type () == be_decl::VARIABLE)
    {
      *ci << "// mapping for variable size " << nl;
      *ci << "ACE_INLINE " << "::" << this->name () << " *&" << nl;
      *ci << fname << "::out (void)" << nl;
      *ci << "{\n";
      ci->incr_indent ();
      *ci << "delete this->ptr_;" << nl;
      *ci << "this->ptr_ = 0;" << nl;
      *ci << "return this->ptr_;\n";
      ci->decr_indent ();
      *ci << "}\n\n";

      ci->indent ();
      *ci << "ACE_INLINE " << "::" << this->name () << " *" << nl;
      *ci << fname << "::_retn (void)" << nl;
      *ci << "{\n";
      ci->incr_indent ();
      *ci << "::" << this->name () << " *tmp = this->ptr_;" << nl;
      *ci << "this->ptr_ = 0;" << nl;
      *ci << "return tmp;\n";
      ci->decr_indent ();
      *ci << "}\n\n";

    }
  else
    {
      *ci << "// mapping for fixed size " << nl;
      *ci << "ACE_INLINE " << "::" << this->name () << " &" << nl;
      *ci << fname << "::out (void)" << nl;
      *ci << "{\n";
      ci->incr_indent ();
      *ci << "return *this->ptr_;\n";
      ci->decr_indent ();
      *ci << "}\n\n";

      ci->indent ();
      *ci << "ACE_INLINE " << "::" << this->name () << nl;
      *ci << fname << "::_retn (void)" << nl;
      *ci << "{\n";
      ci->incr_indent ();
      *ci << "return *this->ptr_;\n";
      ci->decr_indent ();
      *ci << "}\n\n";

    }

  // the additional ptr () member function
  ci->indent ();
  *ci << "ACE_INLINE " << "::" << this->name () << " *" << nl;
  *ci << fname << "::ptr (void) const" << nl;
  *ci << "{\n";
  ci->incr_indent ();
  *ci << "return this->ptr_;\n";
  ci->decr_indent ();
  *ci << "}\n\n";

  return 0;
}

// generate the _out definition
int
be_structure::gen_out_defn (char *)
{
  TAO_OutStream *ch; // output stream
  TAO_NL  nl;        // end line
  char namebuf [NAMEBUFSIZE];  // to hold the _out name

  ACE_OS::memset (namebuf,
                  '\0',
                  NAMEBUFSIZE);

  ACE_OS::sprintf (namebuf,
                   "%s_out",
                   this->local_name ()->get_string ());

  // retrieve a singleton instance of the code generator
  TAO_CodeGen *cg = TAO_CODEGEN::instance ();

  ch = cg->client_header ();

  // generate the out definition (always in the client header)
  ch->indent (); // start with whatever was our current indent level

  *ch << "class " << idl_global->stub_export_macro ()
      << " " << namebuf << nl;
  *ch << "{" << nl;
  *ch << "public:\n";
  ch->incr_indent ();

  // No default constructor

  // constructor from a pointer
  *ch << namebuf << " (" << this->local_name () << " *&);" << nl;
  // constructor from a _var &
  *ch << namebuf << " (" << this->local_name () << "_var &);" << nl;
  // constructor from a _out &
  *ch << namebuf << " (const " << namebuf << " &);" << nl;
  // assignment operator from a _out &
  *ch << namebuf << " &operator= (const " << namebuf << " &);" << nl;
  // assignment operator from a pointer &, cast operator, ptr fn, operator
  // -> and any other extra operators
  // assignment
  *ch << namebuf << " &operator= ("
      << this->local_name () << " *);" << nl;
  // operator ()
  *ch << "operator " << this->local_name () << " *&();" << nl;
  // ptr fn
  *ch << this->local_name () << " *&ptr (void);" << nl;
  // operator ->
  *ch << this->local_name () << " *operator-> (void);" << nl;

  *ch << "\n";
  ch->decr_indent ();
  *ch << "private:\n";
  ch->incr_indent ();
  *ch << local_name () << " *&ptr_;" << nl;
  *ch << "// assignment from T_var not allowed" << nl;
  *ch << "void operator= (const " << this->local_name () << "_var &);\n";

  ch->decr_indent ();
  *ch << "};\n\n";
  return 0;
}

int
be_structure::gen_out_impl (char *,
                            char *)
{
  TAO_OutStream *ci; // output stream
  TAO_NL  nl;        // end line
  char fname [NAMEBUFSIZE];  // to hold the full and
  char lname [NAMEBUFSIZE];  // local _out names

  ACE_OS::memset (fname,
                  '\0',
                  NAMEBUFSIZE);

  ACE_OS::sprintf (fname,
                   "%s_out",
                   this->full_name ());

  ACE_OS::memset (lname,
                  '\0',
                  NAMEBUFSIZE);

  ACE_OS::sprintf (lname,
                   "%s_out",
                   this->local_name ()->get_string ());

  // retrieve a singleton instance of the code generator
  TAO_CodeGen *cg = TAO_CODEGEN::instance ();

  ci = cg->client_inline ();

  // generate the var implementation in the inline file

  ci->indent (); // start with whatever was our current indent level

  *ci << "// *************************************************************"
      << nl;
  *ci << "// Inline operations for class " << fname << nl;
  *ci << "// *************************************************************\n\n";

  // constr from a pointer
  ci->indent ();
  *ci << "ACE_INLINE" << nl;
  *ci << fname << "::" << lname << " (" << "::"
      << this->name () << " *&p)" << nl;
  *ci << "  : ptr_ (p)" << nl;
  *ci << "{\n";
  ci->incr_indent ();
  *ci << "this->ptr_ = 0;\n";
  ci->decr_indent ();
  *ci << "}\n\n";

  // constructor from _var &
  ci->indent ();
  *ci << "ACE_INLINE" << nl;
  *ci << fname << "::" << lname << " (" << this->local_name ()
      << "_var &p) // constructor from _var" << nl;
  *ci << "  : ptr_ (p.out ())" << nl;
  *ci << "{\n";
  ci->incr_indent ();
  *ci << "delete this->ptr_;" << nl;
  *ci << "this->ptr_ = 0;\n";
  ci->decr_indent ();
  *ci << "}\n\n";

  // copy constructor
  ci->indent ();
  *ci << "ACE_INLINE" << nl;
  *ci << fname << "::" << lname << " (const ::" << fname
      << " &p) // copy constructor" << nl;
  *ci << "  : ptr_ (ACE_const_cast (" << lname << "&, p).ptr_)" << nl;
  *ci << "{}\n\n";

  // assignment operator from _out &
  ci->indent ();
  *ci << "ACE_INLINE " << fname << " &" << nl;
  *ci << fname << "::operator= (const ::" << fname <<
    " &p)" << nl;
  *ci << "{\n";
  ci->incr_indent ();
  *ci << "this->ptr_ = ACE_const_cast (" << lname << "&, p).ptr_;" << nl;
  *ci << "return *this;\n";
  ci->decr_indent ();
  *ci << "}\n\n";

  // assignment from _var is not allowed by a private declaration

  // assignment operator from pointer
  ci->indent ();
  *ci << "ACE_INLINE " << fname << " &" << nl;
  *ci << fname << "::operator= (" << this->local_name () << " *p)" << nl;
  *ci << "{\n";
  ci->incr_indent ();
  *ci << "this->ptr_ = p;" << nl;
  *ci << "return *this;\n";
  ci->decr_indent ();
  *ci << "}\n\n";

  // other extra methods - cast operator ()
  ci->indent ();
  *ci << "ACE_INLINE " << nl;
  *ci << fname << "::operator " << "::" << this->name ()
      << " *&() // cast" << nl;
  *ci << "{\n";
  ci->incr_indent ();
  *ci << "return this->ptr_;\n";
  ci->decr_indent ();
  *ci << "}\n\n";

  // ptr function
  ci->indent ();
  *ci << "ACE_INLINE " << "::" << this->name () << " *&" << nl;
  *ci << fname << "::ptr (void) // ptr" << nl;
  *ci << "{\n";
  ci->incr_indent ();
  *ci << "return this->ptr_;\n";
  ci->decr_indent ();
  *ci << "}\n\n";

  // operator ->
  ci->indent ();
  *ci << "ACE_INLINE " << "::" << this->name () << " *" << nl;
  *ci << fname << "::operator-> (void)" << nl;
  *ci << "{\n";
  ci->incr_indent ();
  *ci << "return this->ptr_;\n";
  ci->decr_indent ();
  *ci << "}\n\n";


  return 0;
}

// compute the size type of the node in question
int
be_structure::compute_size_type (void)
{
  UTL_ScopeActiveIterator *si;
  AST_Decl *d;
  be_decl *bd;

  if (this->nmembers () > 0)
    {
      // if there are elements in this scope

      si = new UTL_ScopeActiveIterator (this,
                                        UTL_Scope::IK_decls);
      // instantiate a scope iterator.

      while (!(si->is_done ()))
        {
          // get the next AST decl node
          d = si->item ();
          bd = be_decl::narrow_from_decl (d);
          if (bd != 0)
            {
              // our sizetype depends on the sizetype of our members. Although
              // previous value of sizetype may get overwritten, we are
              // guaranteed by the "size_type" call that once the value reached
              // be_decl::VARIABLE, nothing else can overwrite it.
              this->size_type (bd->size_type ());

              // While we're iterating, we might as well do this one too.
              this->has_constructor (bd->has_constructor ());
            }
          else
            {
              ACE_DEBUG ((LM_DEBUG,
                          "WARNING (%N:%l) be_structure::compute_size_type - "
                          "narrow_from_decl returned 0\n"));
            }
          si->next ();
        } // end of while
      delete si; // free the iterator object
    }
  return 0;
}

// Are we or the parameter node involved in any recursion
idl_bool
be_structure::in_recursion (be_type *node)
{
  if (!node)
    {
      // we are determining the recursive status for ourselves
      node = this;
    }

  // proceed if the number of members in our scope is greater than 0
  if (this->nmembers () > 0)
    {
      // initialize an iterator to iterate thru our scope
      UTL_ScopeActiveIterator *si;
      ACE_NEW_RETURN (si,
                      UTL_ScopeActiveIterator (this,
                                               UTL_Scope::IK_decls),
                      -1);
      // continue until each element is visited
      while (!si->is_done ())
        {
          be_field *field = be_field::narrow_from_decl (si->item ());
          if (!field)
          // This will be an enum value or other legitimate non-field
          // member - in any case, no recursion.
            {
              si->next ();
              continue;
            }
          be_type *type = be_type::narrow_from_decl (field->field_type ());
          if (!type)
            {
              delete si;
              ACE_ERROR_RETURN ((LM_ERROR,
                                 ACE_TEXT ("(%N:%l) be_structure::")
                                 ACE_TEXT ("in_recursion - ")
                                 ACE_TEXT ("bad field type\n")),
                                0);
            }
          if (type->in_recursion (node))
            {
              delete si;
              return 1;
            }
          si->next ();
        } // end of while loop
      delete si;
    } // end of if

  // not in recursion
  return 0;
}

int
be_structure::accept (be_visitor *visitor)
{
  return visitor->visit_structure (this);
}

// Narrowing
IMPL_NARROW_METHODS3 (be_structure, AST_Structure, be_scope, be_type)
IMPL_NARROW_FROM_DECL (be_structure)
IMPL_NARROW_FROM_SCOPE (be_structure)

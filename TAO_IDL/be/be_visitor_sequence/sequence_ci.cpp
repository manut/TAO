//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    sequence_ci.cpp
//
// = DESCRIPTION
//    Visitor generating code for Sequence in the client inline file
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

#include "idl.h"
#include "idl_extern.h"
#include "be.h"

#include "be_visitor_sequence.h"

ACE_RCSID(be_visitor_sequence, sequence_ci, "$Id$")


// ***********************************************************
// sequence visitor for inline generation
// ***********************************************************


be_visitor_sequence_ci::be_visitor_sequence_ci (be_visitor_context *ctx)
  : be_visitor_decl (ctx)
{
}

be_visitor_sequence_ci::~be_visitor_sequence_ci (void)
{
}

int
be_visitor_sequence_ci::visit_sequence (be_sequence *node)
{
  TAO_OutStream *os = this->ctx_->stream ();

  if (node->cli_inline_gen () || node->imported ())
    {
      return 0;
    }

  // Instantiation.

  if (this->instantiate_sequence (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_sequence_ci::"
                         "visit_sequence - "
                         "codegen. for the primitive type sequence\n"),
                        -1);
    }

  // End of instantiation.

  // Generate the ifdefined macro for the sequence type.
  os->gen_ifdef_macro (node->flat_name ());

  // All we do is generate the _var and _out implementations.
  if (this->gen_var_impl (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_sequence_ci::"
                         "visit_sequence - "
                         "codegen for _var failed\n"), -1);
    }

  if (this->gen_out_impl (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_sequence_ci::"
                         "visit_sequence - "
                         "codegen for _out failed\n"), -1);
    }

  // Generate the endif macro for the sequence type.
  os->gen_endif ();
  node->cli_inline_gen (1);

  return 0;
}

int
be_visitor_sequence_ci::instantiate_sequence (be_sequence *node)
{
  be_type *bt = be_type::narrow_from_decl (node->base_type ());

  if (bt == 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_sequence_ch::"
                         "gen_instantiate_template_name - "
                         "Bad element type\n"), -1);
    }

  // Generate the appropriate sequence type.
  switch (node->managed_type ())
    {
    case be_sequence::MNG_PSEUDO:
    case be_sequence::MNG_OBJREF:
      if (node->unbounded ())
        {
          this->gen_unbounded_obj_sequence (node);
        }
      else
        {
          this->gen_bounded_obj_sequence (node);
        }

      break;
    case be_sequence::MNG_STRING: // Sequence of strings
      if (!node->unbounded ())
        {
          this->gen_bounded_str_sequence (node);
        }

      break;
    case be_sequence::MNG_WSTRING: // Sequence of wstrings
      if (!node->unbounded ())
        {
          this->gen_bounded_wstr_sequence (node);
        }

      break;
    default: // Not a managed type.
      if (node->unbounded ())
	      {
	        // TAO provides extensions for octet sequences, first find out
	        // if the base type is an octet (or an alias for octet).
	        be_predefined_type *predef = 0;

	        if (bt->base_node_type () == AST_Type::NT_pre_defined)
	          {
	            be_typedef* alias =
		            be_typedef::narrow_from_decl (bt);

	            if (alias == 0)
		            {
		              predef =
		                be_predefined_type::narrow_from_decl (bt);
		            }
	            else
		            {
		              predef = 
                    be_predefined_type::narrow_from_decl (
                        alias->primitive_base_type ()
                      );
		            }
	          }

	        if (predef != 0)
	          {
	            if (predef->pt() != AST_PredefinedType::PT_octet)
                {
		              this->gen_unbounded_sequence (node);
                }
	          }
	        else
            {
	            this->gen_unbounded_sequence (node);
            }
	      }
      else
        {
          this->gen_bounded_sequence (node);
        }

      break;
    } // End of switch.

  return 0;
}

int
be_visitor_sequence_ci::gen_var_impl (be_sequence *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  char fname [NAMEBUFSIZE];
  char lname [NAMEBUFSIZE];
  be_type *bt = 0;


  ACE_OS::memset (fname, 
                  '\0', 
                  NAMEBUFSIZE);

  ACE_OS::sprintf (fname, 
                   "%s_var", 
                   node->full_name ());

  ACE_OS::memset (lname, 
                  '\0', 
                  NAMEBUFSIZE);

  ACE_OS::sprintf (lname, 
                   "%s_var", 
                   node->local_name ()->get_string ());

  // Retrieve base type.
  bt = be_type::narrow_from_decl (node->base_type ());

  if (bt == 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_sequence_ci::"
                         "visit_sequence - "
                         "Bad element type\n"), -1);
    }

  // Generate the var implementation in the inline file.
  os->indent ();

  *os << "// *************************************************************"
      << be_nl;
  *os << "// Inline operations for class " << fname << be_nl;
  *os << "// *************************************************************\n\n";

  // Default constuctor.
  *os << "ACE_INLINE" << be_nl
      << fname << "::" << lname
      << " (void) // default constructor" << be_nl
      << "  " << ": ptr_ (0)" << be_nl
      << "{}\n\n";

  // Constuctorr from a _ptr.
  os->indent ();
  *os << "ACE_INLINE" << be_nl;
  *os << fname << "::" << lname << " (" << node->local_name () 
      << " *p)" << be_nl;
  *os << "  : ptr_ (p)" << be_nl;
  *os << "{}\n\n";

  // Copy constructor.
  os->indent ();
  *os << "ACE_INLINE" << be_nl;
  *os << fname << "::" << lname << " (const ::" << fname 
      << " &p) // copy constructor" << be_nl;
  *os << "{\n";
  os->incr_indent ();
  *os << "if (p.ptr_)" << be_idt_nl;
  *os << "ACE_NEW (this->ptr_, ::" << node->name () 
      << " (*p.ptr_));" << be_uidt_nl;
  *os << "else" << be_nl;
  *os << "  this->ptr_ = 0;\n";
  os->decr_indent ();
  *os << "}\n\n";

  // Fixed-size base types only.
  if (bt->size_type () == be_decl::FIXED)
    {
      *os << "// fixed-size base types only" << be_nl;
      *os << "ACE_INLINE" << be_nl;
      *os << fname << "::" << lname << " (const ::" 
          << node->name () << " &p)" << be_nl;
      *os << "{\n";
      os->incr_indent ();
      *os << "ACE_NEW (this->ptr_, ::" << node->name () 
          << " (p));\n";
      os->decr_indent ();
      *os << "}\n\n";
    }

  // Destructor.
  os->indent ();
  *os << "ACE_INLINE" << be_nl;
  *os << fname << "::~" << lname << " (void) // destructor" << be_nl;
  *os << "{\n";
  os->incr_indent ();
  *os << "delete this->ptr_;\n";
  os->decr_indent ();
  *os << "}\n\n";

  // Assignment operator from a pointer.
  os->indent ();
  *os << "ACE_INLINE " << fname << " &" << be_nl;
  *os << fname << "::operator= (" << node->local_name () 
      << " *p)" << be_nl;
  *os << "{\n";
  os->incr_indent ();
  *os << "delete this->ptr_;" << be_nl;
  *os << "this->ptr_ = p;" << be_nl;
  *os << "return *this;\n";
  os->decr_indent ();
  *os << "}\n\n";

  // Assignment operator from _var.
  os->indent ();
  *os << "ACE_INLINE " << fname << " &" << be_nl;
  *os << fname << "::operator= (const ::" << fname 
      << " &p) // deep copy" << be_nl;
  *os << "{\n";
  os->incr_indent ();
  *os << "if (this != &p)" << be_nl;
  *os << "{\n";
  os->incr_indent ();
  *os << "delete this->ptr_;" << be_nl;
  *os << "ACE_NEW_RETURN (this->ptr_, ::" 
      << node->name () << " (*p.ptr_), *this);\n";
  os->decr_indent ();
  *os << "}" << be_nl;
  *os << "return *this;\n";
  os->decr_indent ();
  *os << "}\n\n";

  // Fixed-size base types only.
  if (bt->size_type () == be_decl::FIXED)
    {
      os->indent ();
      *os << "// fixed-size types only" << be_nl;
      *os << "ACE_INLINE ::" << fname << " &" << be_nl;
      *os << fname << "::operator= (const ::" << node->name () 
          << " &p)" << be_nl;
      *os << "{\n";
      os->incr_indent ();
      *os << "if (this->ptr_ != &p)" << be_nl;
      *os << "{\n";
      os->incr_indent ();
      *os << "delete this->ptr_;" << be_nl;
      *os << "ACE_NEW_RETURN (this->ptr_, ::" 
          << node->name () << " (p), *this);\n";
      os->decr_indent ();
      *os << "}" << be_nl;
      *os << "return *this;\n";
      os->decr_indent ();
      *os << "}\n\n";
    }

  // Two arrow operators.
  os->indent ();
  *os << "ACE_INLINE const ::" << node->name () << " *" << be_nl;
  *os << fname << "::operator-> (void) const" << be_nl;
  *os << "{\n";
  os->incr_indent ();
  *os << "return this->ptr_;\n";
  os->decr_indent ();
  *os << "}\n\n";

  os->indent ();
  *os << "ACE_INLINE ::" << node->name () << " *" << be_nl;
  *os << fname << "::operator-> (void)" << be_nl;
  *os << "{\n";
  os->incr_indent ();
  *os << "return this->ptr_;\n";
  os->decr_indent ();
  *os << "}\n\n";

  // Other extra methods - 3 cast operator ().
  os->indent ();
  *os << "ACE_INLINE " << be_nl;
  *os << fname << "::operator const ::" << node->name () 
      << " &() const // cast" << be_nl;
  *os << "{\n";
  os->incr_indent ();
  *os << "return *this->ptr_;\n";
  os->decr_indent ();
  *os << "}\n\n";

  os->indent ();
  *os << "ACE_INLINE " << be_nl;
  *os << fname << "::operator ::" << node->name () 
      << " &() // cast " << be_nl;
  *os << "{\n";
  os->incr_indent ();
  *os << "return *this->ptr_;\n";
  os->decr_indent ();
  *os << "}\n\n";

  os->indent ();
  *os << "ACE_INLINE " << be_nl;
  *os << fname << "::operator ::" << node->name () 
      << " &() const // cast " << be_nl;
  *os << "{\n";
  os->incr_indent ();
  *os << "return *this->ptr_;\n";
  os->decr_indent ();
  *os << "}\n\n";

  // Variable-size base types only.
  if (bt->size_type () == be_decl::VARIABLE)
    {
      os->indent ();
      *os << "// variable-size types only" << be_nl;
      *os << "ACE_INLINE" << be_nl;
      *os << fname << "::operator ::" << node->name () 
          << " *&() // cast " << be_nl;
      *os << "{\n";
      os->incr_indent ();
      *os << "return this->ptr_;\n";
      os->decr_indent ();
      *os << "}\n\n";
    }

  // The [] operators.

  // Non-const.
  os->indent ();
  *os << "ACE_INLINE ";

  be_visitor_context ctx (*this->ctx_);
  ctx.state (TAO_CodeGen::TAO_SEQELEM_RETTYPE_CI);
  be_visitor *visitor = tao_cg->make_visitor (&ctx);

  if (visitor == 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_sequence_ci::"
                         "gen_var_impl - "
                         "Bad visitor\n"), -1);
    }

  if (bt->accept (visitor) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_sequence_ci::"
                         "gen_var_impl - "
                         "[] ret type gen failed\n"),
                        -1);
    }

  *os << be_nl;
  *os << fname << "::operator[] (CORBA::ULong index)" << be_nl;
  *os << "{\n";
  os->incr_indent ();
  *os << "return this->ptr_->operator[] (index);\n";
  os->decr_indent ();
  *os << "}\n\n";

  // Const.
  os->indent ();
  *os << "ACE_INLINE const ";

  if (bt->accept (visitor) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_sequence_ci::"
                         "gen_var_impl - "
                         "[] ret type gen failed\n"),
                        -1);
    }

  *os << be_nl;
  *os << fname << "::operator[] (CORBA::ULong index) const" << be_nl;
  *os << "{\n";
  os->incr_indent ();
  *os << "return ACE_const_cast (const ";

  if (bt->accept (visitor) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_sequence_ci::"
                         "gen_var_impl - "
                         "[] ret type gen failed\n"),
                        -1);
    }

  *os << ", this->ptr_->operator[] (index));\n";
  os->decr_indent ();
  *os << "}\n\n";

  delete visitor;

  // in, inout, out, and _retn.
  os->indent ();
  *os << "ACE_INLINE const ::" << node->name () << " &" << be_nl;
  *os << fname << "::in (void) const" << be_nl;
  *os << "{\n";
  os->incr_indent ();
  *os << "return *this->ptr_;\n";
  os->decr_indent ();
  *os << "}\n\n";

  os->indent ();
  *os << "ACE_INLINE ::" << node->name () << " &" << be_nl;
  *os << fname << "::inout (void)" << be_nl;
  *os << "{\n";
  os->incr_indent ();
  *os << "return *this->ptr_;\n";
  os->decr_indent ();
  *os << "}\n\n";

  os->indent ();
  *os << "// mapping for variable size " << be_nl;
  *os << "ACE_INLINE ::" << node->name () << " *&" << be_nl;
  *os << fname << "::out (void)" << be_nl;
  *os << "{\n";
  os->incr_indent ();
  *os << "delete this->ptr_;" << be_nl;
  *os << "this->ptr_ = 0;" << be_nl;
  *os << "return this->ptr_;\n";
  os->decr_indent ();
  *os << "}\n\n";

  os->indent ();
  *os << "ACE_INLINE ::" << node->name () << " *" << be_nl;
  *os << fname << "::_retn (void)" << be_nl;
  *os << "{\n";
  os->incr_indent ();
  *os << "::" << node->name () << " *tmp = this->ptr_;" << be_nl;
  *os << "this->ptr_ = 0;" << be_nl;
  *os << "return tmp;\n";
  os->decr_indent ();
  *os << "}\n\n";

  // The additional ptr () member function.
  os->indent ();
  *os << "ACE_INLINE ::" << node->name () << " *" << be_nl;
  *os << fname << "::ptr (void) const" << be_nl;
  *os << "{\n";
  os->incr_indent ();
  *os << "return this->ptr_;\n";
  os->decr_indent ();
  *os << "}\n\n";

  return 0;
}

int
be_visitor_sequence_ci::gen_out_impl (be_sequence *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  char fname [NAMEBUFSIZE];
  char lname [NAMEBUFSIZE];
  be_type *bt = 0;


  ACE_OS::memset (fname, '\0', NAMEBUFSIZE);
  ACE_OS::sprintf (fname, "%s_out", node->full_name ());

  ACE_OS::memset (lname, '\0', NAMEBUFSIZE);
  ACE_OS::sprintf (lname, "%s_out", node->local_name ()->get_string ());

  // Retrieve base type.
  bt = be_type::narrow_from_decl (node->base_type ());

  if (bt == 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_sequence_ci::"
                         "gen_out_impl - "
                         "Bad element type\n"), -1);
    }

  // Generate the out implementation in the inline file.

  os->indent ();

  *os << "// *************************************************************"
      << be_nl;
  *os << "// Inline operations for class " << fname << be_nl;
  *os << "// *************************************************************\n\n";

  // Constuctorr from a pointer.
  os->indent ();
  *os << "ACE_INLINE" << be_nl;
  *os << fname << "::" << lname << " (" << node->local_name () 
      << " *&p)" << be_nl;
  *os << "  : ptr_ (p)" << be_nl;
  *os << "{\n";
  os->incr_indent ();
  *os << "this->ptr_ = 0;\n";
  os->decr_indent ();
  *os << "}\n\n";

  // Constructor from _var &.
  os->indent ();
  *os << "ACE_INLINE" << be_nl;
  *os << fname << "::" << lname << " (" << node->local_name () 
      << "_var &p) // constructor from _var" << be_nl;
  *os << "  : ptr_ (p.out ())" << be_nl;
  *os << "{\n";
  os->incr_indent ();
  *os << "delete this->ptr_;" << be_nl;
  *os << "this->ptr_ = 0;\n";
  os->decr_indent ();
  *os << "}\n\n";

  // Copy constructor.
  os->indent ();
  *os << "ACE_INLINE" << be_nl;
  *os << fname << "::" << lname << " (const ::" << fname 
      << " &p) // copy constructor" << be_nl;
  *os << "  : ptr_ (ACE_const_cast (" << lname 
      << "&, p).ptr_)" << be_nl;
  *os << "{}\n\n";

  // Assignment operator from _out &.
  os->indent ();
  *os << "ACE_INLINE ::" << fname << " &" << be_nl;
  *os << fname << "::operator= (const ::" << fname 
      << " &p)" << be_nl;
  *os << "{\n";
  os->incr_indent ();
  *os << "this->ptr_ = ACE_const_cast (" << lname 
      << "&, p).ptr_;" << be_nl;
  *os << "return *this;\n";
  os->decr_indent ();
  *os << "}\n\n";

  // Assignment from _var is not allowed by a private declaration.

  // Assignment operator from pointer.
  os->indent ();
  *os << "ACE_INLINE ::" << fname << " &" << be_nl;
  *os << fname << "::operator= (" << node->local_name () 
      << " *p)" << be_nl;
  *os << "{\n";
  os->incr_indent ();
  *os << "this->ptr_ = p;" << be_nl;
  *os << "return *this;\n";
  os->decr_indent ();
  *os << "}\n\n";

  // Other extra methods - cast operator ().
  os->indent ();
  *os << "ACE_INLINE " << be_nl;
  *os << fname << "::operator ::" << node->name () 
      << " *&() // cast" << be_nl;
  *os << "{\n";
  os->incr_indent ();
  *os << "return this->ptr_;\n";
  os->decr_indent ();
  *os << "}\n\n";

  // ptr function.
  os->indent ();
  *os << "ACE_INLINE ::" << node->name () << " *&" << be_nl;
  *os << fname << "::ptr (void) // ptr" << be_nl;
  *os << "{\n";
  os->incr_indent ();
  *os << "return this->ptr_;\n";
  os->decr_indent ();
  *os << "}\n\n";

  // operator ->.
  os->indent ();
  *os << "ACE_INLINE ::" << node->name () << " *" << be_nl;
  *os << fname << "::operator-> (void)" << be_nl;
  *os << "{\n";
  os->incr_indent ();
  *os << "return this->ptr_;\n";
  os->decr_indent ();
  *os << "}\n\n";

  // Sequence has an additional method.
  os->indent ();
  *os << "ACE_INLINE ";

  be_visitor_context ctx (*this->ctx_);
  ctx.state (TAO_CodeGen::TAO_SEQELEM_RETTYPE_CI);
  be_visitor *visitor = tao_cg->make_visitor (&ctx);

  if (visitor == 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_sequence_ci::"
                         "gen_out_impl - "
                         "Bad visitor\n"), -1);
    }

  if (bt->accept (visitor) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_sequence_ci::"
                         "gen_out_impl - "
                         "[] ret type gen failed\n"),
                        -1);
    }

  delete visitor;

  *os << be_nl;
  *os << fname << "::operator[] (CORBA::ULong index)" << be_nl;
  *os << "{\n";
  os->incr_indent ();
  *os << "return this->ptr_->operator[] (index);\n";
  os->decr_indent ();
  *os << "}\n\n";

  return 0;
}

//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    valuetype_sh.cpp
//
// = DESCRIPTION
//    Visitor generating code for value types in the server header
//
// = AUTHOR
//    Jeff Parsons
//
// ============================================================================

ACE_RCSID (be_visitor_valuetype, 
           valuetype_sh, 
           "$Id$")


// ************************************************************
// Valuetype visitor for server header.
// ************************************************************

be_visitor_valuetype_sh::be_visitor_valuetype_sh (be_visitor_context *ctx)
  : be_visitor_valuetype (ctx)
{
}

be_visitor_valuetype_sh::~be_visitor_valuetype_sh (void)
{
}

int
be_visitor_valuetype_sh::visit_valuetype (be_valuetype *node)
{
  if (node->srv_hdr_gen () || node->imported () || node->is_abstract ())
    {
      return 0;
    }

  AST_Interface *concrete = node->supports_concrete ();

  // We generate a skeleton class only if the valuetype supports a
  // non-abstract interface.
  if (concrete == 0)
    {
      return 0;
    }

  TAO_OutStream *os  = this->ctx_->stream ();

  os->indent ();
  ACE_CString class_name;

  // We shall have a POA_ prefix only if we are at the topmost level.
  if (!node->is_nested ())
    {
      // We are outermost.
      class_name += "POA_";
      class_name += node->local_name ();
    }
  else
    {
      class_name +=  node->local_name ();
    }

  *os << "// TAO_IDL - Generated from" << be_nl
      << "// " << __FILE__ << ":" << __LINE__ << be_nl << be_nl;

  // Generate the skeleton class name.
  *os << "class " << class_name.c_str () << ";" << be_nl;

  // Generate the _ptr declaration.
  *os << "typedef " << class_name.c_str () << " *" << class_name.c_str ()
      << "_ptr;" << be_nl;

  // Forward class declaration.
  *os << "// Forward Classes Declaration" << be_nl;

  if (be_global->gen_thru_poa_collocation ())
    {
      *os << "class " << node->thru_poa_proxy_impl_name () << ";" << be_nl;
    }

  if (be_global->gen_direct_collocation ())
    {
      *os << "class " << node->direct_proxy_impl_name () << ";" << be_nl;
    }

  if (be_global->gen_thru_poa_collocation ()
      || be_global->gen_direct_collocation ())
    {
      *os << "class " << node->strategized_proxy_broker_name ()
          << ";" << be_nl;
    }

  *os << be_nl;

  // Now generate the class definition.
  *os << "class " << be_global->skel_export_macro ()
      << " " << class_name.c_str () << be_idt_nl << ": " << be_idt;

  *os << "public virtual " << "POA_"
      << concrete->name ();

  *os << be_uidt << be_uidt_nl
      << "{" << be_nl
      << "protected:" << be_idt_nl
      << class_name.c_str () << " (void);\n" << be_uidt_nl
      << "public:" << be_idt_nl;

  // No copy constructor for locality constraint interface.
  *os << class_name.c_str () << " (const " << class_name.c_str () 
      << "& rhs);" << be_nl
      << "virtual ~" << class_name.c_str () << " (void);" << be_nl << be_nl;

  *os << "::" << node->full_name () << " *_this (" << be_idt << be_idt_nl
      << "ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS" << be_uidt_nl
      << ");" << be_uidt_nl << be_nl;

  // The _interface_repository_id method.
  *os << "virtual const char* _interface_repository_id "
      << "(void) const;" << be_uidt_nl;

  *os << "};\n\n";

  return 0;
}


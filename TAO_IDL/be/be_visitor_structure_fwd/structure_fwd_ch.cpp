//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    structure_fwd_ch.cpp
//
// = DESCRIPTION
//    Visitor generating code for be_structure_fwd node in the client header.
//
// = AUTHOR
//    Jeff Parsons
//
// ============================================================================

ACE_RCSID (be_visitor_structure_fwd, 
           structure_fwd_ch, 
           "$Id$")

be_visitor_structure_fwd_ch::be_visitor_structure_fwd_ch (
    be_visitor_context *ctx
  )
  : be_visitor_decl (ctx)
{
}

be_visitor_structure_fwd_ch::~be_visitor_structure_fwd_ch (void)
{
}

// Visit the interface_fwd_ch node and its scope.
int
be_visitor_structure_fwd_ch::visit_structure_fwd (be_structure_fwd *node)
{
  TAO_OutStream *os = this->ctx_->stream ();

  if (node->cli_hdr_gen () || node->imported ())
    {
      return 0;
    }

  // Generate a forward declaration of the class.
  *os << "struct " << node->local_name () << ";" << be_nl;

  node->cli_hdr_gen (I_TRUE);

  return 0;
}

//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    valuetype_init_arglist_ch.cpp
//
// = DESCRIPTION
//    Visitor generating code for the parameter list of the OBV factory
//    signature.
//
// = AUTHOR
//    Boris Kolpackov <bosk@ipmce.ru>
//
// ============================================================================

ACE_RCSID (be_visitor_valuetype_init, 
           arglist_ch, 
           "$Id$")

be_visitor_valuetype_init_arglist_ch::be_visitor_valuetype_init_arglist_ch (
    be_visitor_context *ctx
  )
  : be_visitor_scope (ctx)
{
}

be_visitor_valuetype_init_arglist_ch::~be_visitor_valuetype_init_arglist_ch (
    void
  )
{
}

int
be_visitor_valuetype_init_arglist_ch::visit_factory (be_factory *node)
{
  TAO_OutStream& os = *(this->ctx_->stream ());

  os << " (" << be_idt
     << be_idt_nl;

  // All we do is hand over code generation to our scope.
  if (this->visit_scope (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_valuetype_init_arglist_ch::"
                         "visit_factory - "
                         "codegen for scope failed\n"),
                        -1);
    }

  os << be_uidt_nl
     << ")" << be_uidt;

  return 0;
}

int
be_visitor_valuetype_init_arglist_ch::visit_argument (be_argument *node)
{
  // Get the visitor that will dump the argument's mapping in the operation
  // signature.
  be_visitor_context ctx (*this->ctx_);
  int status = 0;

  switch (this->ctx_->state ())
    {
    case TAO_CodeGen::TAO_VALUETYPE_INIT_ARGLIST_CH:
      {
        ctx.state (TAO_CodeGen::TAO_ARGUMENT_ARGLIST_CH);
        be_visitor_args_arglist visitor (&ctx);
        status = node->accept (&visitor);
        break;
      }
    default:
      {
        ACE_ERROR_RETURN ((LM_ERROR,
                           "(%N:%l) be_visitor_valuetype_init_arglist_ch::"
                           "visit_argument - "
                           "Bad context\n"),
                          -1);
      }
    }

  if (status == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_valuetype_init_arglist_ch::"
                         "visit_argument - "
                         "codegen for arglist failed\n"),
                        -1);
    }

  return 0;
}

int
be_visitor_valuetype_init_arglist_ch::post_process (be_decl *bd)
{
  TAO_OutStream *os = this->ctx_->stream ();

  // If we are not the last node in the list of arguments, generate a comma.
  if (!this->last_node (bd))
    {
      *os << "," << be_nl;
    }

  return 0;
}

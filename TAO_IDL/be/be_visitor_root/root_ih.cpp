
//=============================================================================
/**
 *  @file    root_ih.cpp
 *
 *  $Id$
 *
 *  Visitor generating code for Root in the server implementation header
 *
 *
 *  @author Yamuna  Krishnamurthy (yamuna@cs.wustl.edu)
 */
//=============================================================================


// ***********************************
// Root visitor for implementation header
// ***********************************

be_visitor_root_ih::be_visitor_root_ih (be_visitor_context *ctx)
  : be_visitor_root (ctx)
{
}

be_visitor_root_ih::~be_visitor_root_ih (void)
{
}

int
be_visitor_root_ih::init (void)
{
  if (tao_cg->start_implementation_header (
          be_global->be_get_implementation_hdr_fname ()
        )
      == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_root_ih::init - "
                         "Error :%p: Unable to open implementation header file : %s\n",
                         "start_implementation_header",
                         be_global->be_get_implementation_hdr_fname ()),
                        -1);
    }


  this->ctx_->stream (tao_cg->implementation_header ());
  return 0;
}

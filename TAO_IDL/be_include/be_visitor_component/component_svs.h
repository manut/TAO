//
// $Id$
//
/* -*- c++ -*- */
// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    component_svs.h
//
// = DESCRIPTION
//    Concrete visitor for the Component node.
//    This provides for code generation in the servant source
//
// = AUTHOR
//    Jeff Parsons
//
// ============================================================================

#ifndef _BE_COMPONENT_COMPONENT_SVS_H_
#define _BE_COMPONENT_COMPONENT_SVS_H_

class be_visitor_component_svs : public be_visitor_component
{
  //
  // = TITLE
  //   be_visitor_component_svs
  //
  // = DESCRIPTION
  //   This is a concrete visitor to generate the servant
  //   source for component.
  //
  //
public:
  be_visitor_component_svs (be_visitor_context *ctx);
  
  ~be_visitor_component_svs (void);
  
  virtual int visit_component (be_component *node);
  
private:
  void gen_entrypoint (AST_Component *node);
  
private:
  TAO_OutStream &os_;
  ACE_CString export_macro_;
};
        
#endif /* _BE_COMPONENT_COMPONENT_SVS_H_ */


/* -*- c++ -*- */

//=============================================================================
/**
 *  @file    public_reset_cs.h
 *
 *  $Id$
 *
 *   Visitor for the Union class.
 *   This one generates code for the reset method of the union class
 *   for the union members in the client stubs.
 *
 *
 *  @author Aniruddha Gokhale
 */
//=============================================================================


#ifndef _BE_VISITOR_UNION_BRANCH_PUBLIC_RESET_CS_H_
#define _BE_VISITOR_UNION_BRANCH_PUBLIC_RESET_CS_H_

/**
 * @class be_visitor_union_branch_public_reset_cs
 *
 * @brief be_visitor_union_branch_public_reset_cs
 *
 * This is used to generate the body of the resetment operator and the
 * copy constructor of the union class
 */
class be_visitor_union_branch_public_reset_cs : public be_visitor_decl
{
public:
  /// constructor
  be_visitor_union_branch_public_reset_cs (be_visitor_context *ctx);

  /// destructor
  ~be_visitor_union_branch_public_reset_cs (void);

  /// visit the union_branch node
  virtual int visit_union_branch (be_union_branch *node);

  // =visit operations on all possible data types that a union_branch can be

  /// visit array type
  virtual int visit_array (be_array *node);

  /// visit enum type
  virtual int visit_enum (be_enum *node);

  /// visit interface type
  virtual int visit_interface (be_interface *node);

  /// visit interface forward type
  virtual int visit_interface_fwd (be_interface_fwd *node);

  /// visit valuebox type
  virtual int visit_valuebox (be_valuebox *node);

  /// visit interface type
  virtual int visit_valuetype (be_valuetype *node);

  /// visit interface forward type
  virtual int visit_valuetype_fwd (be_valuetype_fwd *node);

  /// visit predefined type
  virtual int visit_predefined_type (be_predefined_type *node);

  /// visit sequence type
  virtual int visit_sequence (be_sequence *node);

  /// visit string type
  virtual int visit_string (be_string *node);

  /// visit structure type
  virtual int visit_structure (be_structure *node);

  /// visit typedefed type
  virtual int visit_typedef (be_typedef *node);

  /// visit union type
  virtual int visit_union (be_union *node);

};

#endif /* _BE_VISITOR_UNION_BRANCH_PUBLIC_RESET_CS_H_ */

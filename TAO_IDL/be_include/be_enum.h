/* -*- c++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    be_enum.h
//
// = DESCRIPTION
//    Extension of class AST_Enum that provides additional means for C++
//    mapping.
//
// = AUTHOR
//    Copyright 1994-1995 by Sun Microsystems, Inc.
//    and
//    Aniruddha Gokhale
//
// ============================================================================

#ifndef BE_ENUM_H
#define BE_ENUM_H

#include "be_scope.h"
#include "be_type.h"
#include "ast_enum.h"

class UTL_StrList;
class be_visitor;

class be_enum : public virtual AST_Enum,
                public virtual be_scope,
                public virtual be_type
{
public:
  be_enum (void);
  // Default constructor.

  be_enum (UTL_ScopedName *n,
           UTL_StrList *p,
           idl_bool local,
           idl_bool abstract);
  // Constructor.

  virtual int member_count (void);
  // Return the count of members

  // Convert a numeric value to the enum's string name for it.
  virtual UTL_ScopedName *value_to_name (const unsigned long v);

  virtual void destroy (void);
  // Cleanup method.

  // Visiting.
  virtual int accept (be_visitor *visitor);

  // Narrowing.
  DEF_NARROW_METHODS3 (be_enum, AST_Enum, be_scope, be_type);
  DEF_NARROW_FROM_DECL (be_enum);
  DEF_NARROW_FROM_SCOPE (be_enum);

private:
  int compute_member_count (void);
  // Count the number of members.

  int member_count_;
  // Number of members.
};

#endif

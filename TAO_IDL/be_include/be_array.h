// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    be_array.h
//
// = DESCRIPTION
//    Extension of class AST_Array that provides additional means for C++
//    mapping.
//
// = AUTHOR
//    Copyright 1994-1995 by Sun Microsystems, Inc.
//    and
//    Aniruddha Gokhale
//
// ============================================================================

#ifndef BE_ARRAY_H
#define BE_ARRAY_H

#include "be_type.h"
#include "ast_array.h"

class UTL_ExprList;
class TAO_OutStream;
class be_visitor;

/*
 * BE_Array
 */
class be_array : public virtual AST_Array,
                 public virtual be_type
{
public:
  // =Operations

  be_array (void);
  // default constructor

  be_array (UTL_ScopedName *n,
            unsigned long ndims,
            UTL_ExprList *dims,
            idl_bool local,
            idl_bool abstract);
  // constructor

  ~be_array (void);

  virtual int gen_dimensions (TAO_OutStream *os, unsigned short slice=0);
  // generate dimensions. If slice == 1, generate dimensions for the slice
  // definition

  // Visiting
  virtual int accept (be_visitor *visitor);

  // Narrowing
  DEF_NARROW_METHODS2 (be_array, AST_Array, be_type);
  DEF_NARROW_FROM_DECL (be_array);

protected:
  virtual int compute_size_type (void);
  // compute the size type if it is unknown

  virtual int create_name (void);
  // create a name for us

  const char* tao_name (void);

private:
  char* tao_name_;
  // We need a name to generate typecodes and other objects, but it
  // must be different from the typedef name....
};

#endif

/* -*- c++ -*- */

//=============================================================================
/**
 *  @file    be_util.h
 *
 *  $Id$
 *
 *  Static helper methods used by multiple visitors.
 *
 *
 *  @author Gary Maxey
 *  @author Jeff Parsons
 */
//=============================================================================

#ifndef TAO_BE_UTIL_H
#define TAO_BE_UTIL_H

#include "TAO_IDL_BE_Export.h"

class TAO_OutStream;
class be_module;
class AST_Decl;
class AST_Generator;

class be_util
{
public:
  static void
  gen_nested_namespace_begin (TAO_OutStream *os,
                              be_module *node,
                              bool skel = false);

  static void
  gen_nested_namespace_end (TAO_OutStream *os,
                            be_module *node);

  static void
  gen_nesting_open (TAO_OutStream &os,
                    AST_Decl *node);

  static void
  gen_nesting_close (TAO_OutStream &os,
                     AST_Decl *node);

  /// Special BE arg call factored out of DRV_args.
  static TAO_IDL_BE_Export void
  prep_be_arg (char *s);

  /// Checks made after parsing args.
  static TAO_IDL_BE_Export void
  arg_post_proc (void);

  /// Display usage of BE-specific options.
  static TAO_IDL_BE_Export void
  usage (void);

  /// Create an AST node generator.
  static TAO_IDL_BE_Export AST_Generator *
  generator_init (void);

  /// Called from various places.
  static const char *
  get_output_path (bool for_anyop, bool for_skel);
};

#endif // if !defined


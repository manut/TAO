// $Id$

#ifndef FE_UTILS_H
#define FE_UTILS_H

#include "ace/Unbounded_Queue.h"

#include "ast_decl.h"
#include "ast_expression.h"
#include "ast_predefined_type.h"

class UTL_StrList;
class UTL_IdList;
typedef UTL_IdList UTL_ScopedName;
class UTL_NameList;
class AST_PortType;
class AST_Enum;
class AST_Component;
class AST_Uses;

struct TAO_IDL_FE_Export FE_Utils
{
  struct T_Param_Info
  {
    AST_Decl::NodeType type_;
    AST_Expression::ExprType const_type_;
    AST_Enum *enum_const_type_decl_;
    ACE_CString name_;
    ACE_CString seq_param_ref_;

    T_Param_Info (void);
  };

  typedef ACE_Unbounded_Queue<T_Param_Info> T_PARAMLIST_INFO;

  static bool duplicate_param_id (T_PARAMLIST_INFO *params);

  struct T_ARGLIST : ACE_Unbounded_Queue<AST_Decl *>
  {
    void destroy (void);
  };

  /// Convert from a predefined type to an expression type.
  static AST_Expression::ExprType
  PredefinedTypeToExprType (AST_PredefinedType::PredefinedType);

  /// Convert from an expression type to a predefined type.
  static AST_PredefinedType::PredefinedType
  ExprTypeToPredefinedType (AST_Expression::ExprType);

  /// Parses a string with double colons. Caller owns return
  /// value.
  static UTL_ScopedName *
  string_to_scoped_name (const char *s);

  /// Takes an #include filename generated by the preprocessor, and
  /// strips off any command line -I prefix that may have been
  /// prepended.
  static const char *
  stripped_preproc_include (const char *name);

  /// We must do this in the front end since the executor
  /// mapping IDL will have these data types.
  static void
  create_uses_multiple_stuff (AST_Component *c,
                              AST_Uses *u,
                              const char *prefix = "");

  /// For the executor IDL file, when a pragma ciao ami receptacle
  /// name is multiplex.
  static void
  create_implied_ami_uses_stuff (void);

  /// Case insensitive for Windows, otherwise not.
  static int
  path_cmp (const char *s, const char *t);

  /// To tell if we have to handle a Windows path with spaces.
  static bool
  hasspace (const char *s);

  /// Check if 'param' is a sequence of a previous param, and if
  /// so, if the previous param exists.
  static ACE_CString
  check_for_seq_of_param (FE_Utils::T_PARAMLIST_INFO *list);

  /// Attempt to open file for reading until it is found in one of the
  /// supplied include paths.  If the file was successfully opened, the
  /// directory within which it was found is returned as well.
  static FILE *
  open_included_file (char const * filename,
                      char const *& directory);

  static bool
  is_include_file_found (ACE_CString & inc_file,
                         UTL_String * idl_file_name);

  /// Validate the included idl files, somefiles might have been
  /// ignored by the preprocessor.
  static void
  validate_included_idl_files (void);

  /// Check if included file is in TAO specific include dirs.
  static bool
  validate_orb_include (UTL_String *);

  /// Strips _cxx_ prefix for use in port names.
  static void
  original_local_name (Identifier *local_name);

  /// Types, constants and exceptions can be redefined in
  /// derived interfaces, modules may be reopened, forward
  /// declarations may be repeated, etc.
  static bool
  can_be_redefined (AST_Decl *prev_dec,
                    AST_Decl *curr_decl);

private:
  static bool
  check_one_seq_of_param (FE_Utils::T_PARAMLIST_INFO *list,
                          ACE_CString &param_id,
                          size_t index);
};

#endif /* FE_UTILS_H */


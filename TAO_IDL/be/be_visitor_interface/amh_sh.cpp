//=============================================================================
/**
*  @file   amh_sh.cpp
*
*  $Id$
*
*  Specialized interface visitor for AMH generates code that is 
*  specific to AMH interfaces.
*
*  @author Darrell Brunsch <brunsch@cs.wustl.edu>
*/
//=============================================================================

#include        "idl.h"
#include        "idl_extern.h"
#include        "be.h"

#include "be_visitor_interface.h"

be_visitor_amh_interface_sh::be_visitor_amh_interface_sh (be_visitor_context *ctx)
  : be_visitor_interface_sh (ctx)
{
}

be_visitor_amh_interface_sh::~be_visitor_amh_interface_sh (void)
{
}

/** The node is the original interface node but we 'tweak' with the
    local_name and the the operation signatures to generate the AMH
    skeleton on the 'fly'
*/
int
be_visitor_amh_interface_sh::visit_interface (be_interface *node)
{
  TAO_OutStream *os = this->ctx_->stream (); // output stream

  ACE_CString class_name; // holds the class name

  os->indent ();

  // We shall have a POA_ prefix only if we are at the topmost level.
  // In AMH, only interfaces are Asynchronous, not modules, so this 
  // should be unnecessary but we retain it anyways.
  if (!node->is_nested ())
    {
      // We are outermost.
      class_name += "POA_AMH_";
      class_name += node->local_name ();
    }
  else
    {
      class_name += "AMH_";
      class_name +=  node->local_name ();
    }

  // Generate the skeleton class name.
  *os << "class " << class_name.c_str () << ";" << be_nl;

  // Generate the _ptr declaration.
  *os << "typedef " << class_name.c_str () << " *" << class_name.c_str ()
      << "_ptr;" << be_nl;

  // Now generate the class definition.
  *os << "class " << be_global->skel_export_macro ()
      << " " << class_name.c_str () << be_idt_nl << ": " << be_idt;

  long n_parents = node->n_inherits ();

  if (n_parents > 0)
    {
      for (int i = 0; i < n_parents; ++i)
        {
          *os << "public virtual " << "POA_"
              << node->inherits ()[i]->name ();

          if (i < n_parents - 1)
            {
              *os << "," << be_nl;
            }
        }
    }
  else
    {
      // We don't inherit from another user defined object, hence our
      // base class is the ServantBase class.
      *os << "public virtual PortableServer::ServantBase";
    }

  *os << be_uidt << be_uidt_nl
      << "{" << be_nl
      << "protected:" << be_idt_nl
      << class_name.c_str () << " (void);\n" << be_uidt_nl
      << "public:" << be_idt_nl;

  // No copy constructor for locality constraint interface.
  *os << class_name.c_str () << " (const " << class_name.c_str () << "& rhs);" << be_nl
      << "virtual ~" << class_name.c_str () << " (void);\n\n"
      << be_nl
      << "virtual CORBA::Boolean _is_a (" << be_idt << be_idt_nl
      << "const char* logical_type_id" << be_nl
      << "TAO_ENV_ARG_DECL_WITH_DEFAULTS" << be_uidt_nl
      << ");\n" << be_uidt_nl;

  *os << "virtual void* _downcast (" << be_idt << be_idt_nl
      << "const char* logical_type_id" << be_uidt_nl
      << ");\n" << be_uidt_nl;

  // Add a skeleton for our _is_a method.
  *os << "static void _is_a_skel (" << be_idt << be_idt_nl
      << "TAO_ServerRequest &req," << be_nl
      << "void *obj," << be_nl
      << "void *servant_upcall" << be_nl
      << "TAO_ENV_ARG_DECL" << be_uidt_nl
      << ");\n" << be_uidt_nl;

  // Add a skeleton for our _non_existent method.
  *os << "static void _non_existent_skel (" << be_idt << be_idt_nl
      << "TAO_ServerRequest &req," << be_nl
      << "void *obj," << be_nl
      << "void *servant_upcall" << be_nl
      << "TAO_ENV_ARG_DECL" << be_uidt_nl
      << ");\n" << be_uidt_nl;

  // Add a skeleton for our _interface method.
  *os << "static void _interface_skel (" << be_idt << be_idt_nl
      << "TAO_ServerRequest &req," << be_nl
      << "void *obj," << be_nl
      << "void *servant_upcall" << be_nl
      << "TAO_ENV_ARG_DECL" << be_uidt_nl
      << ");\n" << be_uidt_nl;

  // Add the dispatch method.
  *os << "virtual void _dispatch (" << be_idt << be_idt_nl
      << "TAO_ServerRequest &req," << be_nl
      << "void *_servant_upcall" << be_nl
      << "TAO_ENV_ARG_DECL" << be_uidt_nl
      << ");\n" << be_uidt_nl;

  this->this_method (node);

  // The _interface_repository_id method.
  *os << "virtual const char* _interface_repository_id "
      << "(void) const;\n\n";

  // Generate code for elements in the scope (e.g., operations).
  // We have to generate AMH-operations here.  Here is how we go 
  // about it:
  // We create a new node 'on the fly' and for each corresponding
  // operation in the original node, we add a new AMH-operation
  // into the node and then call visit_scope on the new node.
  
  // Step 1: Create the new AMH-node
  be_interface *amh_node = this->create_amh_class (class_name);

  // Step 2: Add the memebers of original node to new AMH-node
  this->add_original_members (node, amh_node);

  // Step 3: Generate the AMH-operations
  if (this->visit_scope (amh_node) ==  -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "be_visitor_interface_sh::"
                         "visit_interface - "
                         "codegen for scope failed\n"),
                        -1);
    }

  // Generate skeletons for operations of our base classes. These
  // skeletons just cast the pointer to the appropriate type
  // before invoking the call.
  if (node->traverse_inheritance_graph (be_interface::gen_skel_helper, os) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "be_visitor_interface_sh::"
                         "visit_interface - "
                         "inheritance graph traversal failed\n"),
                        -1);
    }

  delete amh_node;
  *os << "\n";
  return 0;

}

int 
be_visitor_amh_interface_sh::add_original_members (be_interface *node, 
                                                   be_interface *amh_node 
                                                   )
{
  if (!node || !amh_node)
    return -1;

  if (node->nmembers () > 0)
    {
      // initialize an iterator to iterate thru our scope
      UTL_ScopeActiveIterator *si;
      ACE_NEW_RETURN (si,
                      UTL_ScopeActiveIterator (node, UTL_Scope::IK_decls),
                      0);
      this->elem_number_ = 0;
      
      // continue until each element is visited
      while (!si->is_done ())
        {
          AST_Decl *d = si->item ();
          if (!d)
            {
              delete si;
              ACE_ERROR_RETURN ((LM_ERROR,
                                 "(%N:%l) be_visitor_amh_pre_proc::visit_interface - "
                                 "bad node in this scope\n"),
                                0);
              
            }
          
          if (d->node_type () == AST_Decl::NT_attr)
            {
              be_attribute *attribute = be_attribute::narrow_from_decl (d);
              
              if (!attribute)
                return 0;
            }
          else
            {
              be_operation* operation = be_operation::narrow_from_decl (d);
              if (operation)
                {
                  this->add_amh_operation (operation, amh_node);
                }
            }
          si->next ();
        } // end of while loop
      delete si;
    } // end of if
  return 0;
}


int
be_visitor_amh_interface_sh::add_amh_operation (be_operation *node,
                                            be_interface *amh_node)
{
  if (!node || !amh_node)
    return -1;

  // We do nothing for oneways!
  if (node->flags () == AST_Operation::OP_oneway)
    return 0;

  // Create the return type, which is "void"
  be_predefined_type *rt =
    new be_predefined_type (AST_PredefinedType::PT_void,
                            new UTL_ScopedName (new Identifier ("void"),
                                                0));

  ACE_CString original_op_name (
                                node->name ()->last_component ()->get_string ()
                                );

  UTL_ScopedName *op_name =
    ACE_static_cast (UTL_ScopedName *, amh_node->name ()-> copy ());
  op_name->nconc (new UTL_ScopedName (new Identifier (original_op_name.rep ()),
                                      0));

  // Create the operation
  be_operation *operation = new be_operation (rt, //node->return_type (),
                                              AST_Operation::OP_noflags,
                                              op_name,
                                              0,
                                              0);
  operation->set_name (op_name);

  /* Add the response_handler as the first argument
     be_argument *rh_arg = new be_argument (Direction.dir_IN,
     thid->response_handler, original_arg->field_type (),
     original_arg->name (),
     0);
     operation->add_argument_to_scope (rh_arg);
  */

  // Iterate over the arguments and put all the in and inout
  // into the new method.
  if (node->nmembers () > 0)
    {
      // initialize an iterator to iterate thru our scope
      UTL_ScopeActiveIterator *si;
      ACE_NEW_RETURN (si,
                      UTL_ScopeActiveIterator (node,
                                               UTL_Scope::IK_decls),
                      0);

      // continue until each element is visited
      while (!si->is_done ())
        {
          AST_Decl *d = si->item ();
          if (!d)
            {
              delete si;
              ACE_ERROR_RETURN ((LM_ERROR,
                                 "(%N:%l) be_visitor_amh_pre_proc::"
                                 "create_response_handler_operation - "
                                 "bad node in this scope\n"),
                                -1);

            }

          AST_Argument *original_arg = AST_Argument::narrow_from_decl (d);

          if (original_arg->direction () == AST_Argument::dir_INOUT ||
              original_arg->direction () == AST_Argument::dir_IN)
            {
              // Create the argument
              be_argument *arg = new be_argument (original_arg->direction (),
                                                  original_arg->field_type (),
                                                  original_arg->name ());

              operation->add_argument_to_scope (arg);
            }
          si->next ();
        }
      delete si;
    }

  operation->set_defined_in (amh_node);

  // After having generated the operation we insert it into the
  // AMH node interface.
  amh_node->be_add_operation (operation);

  return 0;
}


be_interface *
be_visitor_amh_interface_sh::create_amh_class (ACE_CString name)
{
  UTL_ScopedName *amh_class_name =
    new UTL_ScopedName (new Identifier (name.c_str ()), 0);

  be_interface *amh_class =
    new be_interface (amh_class_name, // name
                      0,              // list of inherited
                      0,              // number of inherited
                      0,              // list of ancestors
                      0,              // number of ancestors
                      0,              // non-local
                      0);             // non-abstract

  amh_class->set_name (amh_class_name);

  return amh_class;
}

void
be_visitor_amh_interface_sh::this_method (be_interface *node)
{
  TAO_OutStream *os = this->ctx_->stream ();

  ACE_CString non_amh_name = "    ";
  non_amh_name += node->client_enclosing_scope ();
  non_amh_name += node->original_interface ()->local_name ();

  // Print out the _this() method.
  *os << "// Special _this method for AMH! \n"
      << non_amh_name.c_str () << " *_this (" << be_idt << be_idt_nl
      << "CORBA::Environment &ACE_TRY_ENV = " << be_idt_nl
      << "TAO_default_environment ()"
      << be_uidt << be_uidt_nl
      << ");\n" << be_uidt_nl;
}

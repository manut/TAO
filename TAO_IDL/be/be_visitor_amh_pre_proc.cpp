//=============================================================================
/**
 *  @file   be_visitor_amh_pre_proc.cpp
 *
 *  $Id$
 *
 *  This visitor creates for AMH implied IDL constructs the appropriate AST
 *  (Abstract Syntax Tree) node, sets the corresponding interface or operation
 *  strategy on it and enteres the nodes into the AST.
*
*  @author Darrell Brunsch <brunsch@cs.wustl.edu>
*/
//=============================================================================

#include "be_visitor_amh_pre_proc.h"

be_visitor_amh_pre_proc::be_visitor_amh_pre_proc (be_visitor_context *ctx)
  : be_visitor_scope (ctx)
{
}



be_visitor_amh_pre_proc::~be_visitor_amh_pre_proc (void)
{
}



int
be_visitor_amh_pre_proc::visit_root (be_root *node)
{
  if (this->visit_scope (node) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "(%N:%l) be_visitor_amh_pre_proc::"
                       "visit_root - visit scope failed\n"),
                      -1);
  
  return 0;
}



int
be_visitor_amh_pre_proc::visit_module (be_module *node)
{
  if (!node->imported () && this->visit_scope (node) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "(%N:%l) be_visitor_amh_pre_proc::"
                       "visit_module - visit scope failed\n"),
                      -1);
  
  return 0;
}



int
be_visitor_amh_pre_proc::visit_interface (be_interface *node)
{
  if (!node->imported () && !node->is_local ())
    {
      AST_Module *module = 
        AST_Module::narrow_from_scope (node->defined_in ());

      if (!module)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "(%N:%l) be_visitor_amh_pre_proc::"
                           "visit_interface - module is null\n"),
                          -1);
      
      be_interface *amh_class = this->create_amh_class (node);
      
      if (amh_class)
        {
          amh_class->set_defined_in (node->defined_in ());
          
          // Insert the new amh class after the node
          module->be_add_interface (amh_class, node);
          
          // Remember from whom we were cloned
          amh_class->original_interface (node);
        }
      else
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_amh_pre_proc::"
                             "visit_interface - "
                             "creating the amh_class failed\n"),
                            -1);
        }
      
      // Since this is server side only, don't generate the client stuff.
      // We do this by pretending that all this stuff has already been
      // generated.
      amh_class->cli_hdr_gen (1);
      amh_class->cli_stub_gen (1);
      amh_class->cli_hdr_any_op_gen (1);
      amh_class->cli_stub_any_op_gen (1);
      amh_class->cli_hdr_cdr_op_gen (1);
      amh_class->cli_stub_cdr_op_gen (1);
      amh_class->cli_inline_cdr_op_gen (1);
      amh_class->cli_inline_gen (1);
      
      // Set the proper strategy
      be_interface_strategy *old_strategy =
        amh_class->set_strategy (new be_interface_amh_strategy (amh_class));
      
      if (old_strategy)
        delete old_strategy;
      
      be_valuetype *excep_holder = this->create_exception_holder (node);
      if (excep_holder)
        {
          excep_holder->set_defined_in (node->defined_in ());
          // Insert the exception holder after the original node,
          // this way we ensure that it is *before* the
          // ami handler, which is the way we want to have it.
          module->be_add_interface (excep_holder, node);
          module->set_has_nested_valuetype ();
          // Remember from whom we were cloned
          excep_holder->original_interface (node);
          /*
          // Set the strategy
          be_interface_strategy *old_strategy =
          excep_holder->set_strategy (
              new be_interface_ami_exception_holder_strategy (excep_holder)
            );
          if (old_strategy)
          delete old_strategy;
          */
        }
      else
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_amh_pre_proc::"
                             "visit_interface - "
                             "creating the exception holder failed\n"),
                            -1);
        }
      
      be_interface *response_handler = 
        this->create_response_handler (node, excep_holder);
      if (response_handler)
        {
          response_handler->set_defined_in (node->defined_in ());
          
          // Insert the ami handler after the node, the
          // exception holder will be placed between these two later.
          module->be_add_interface (response_handler, node);
          
          // Remember from whom we were cloned
          response_handler->original_interface (node);
          
          // Since this is server side only, don't generate the client stuff.
          // We do this by pretending that all this stuff has already been
          // generated.
          response_handler->cli_hdr_gen (1);
          response_handler->cli_stub_gen (1);
          response_handler->cli_hdr_any_op_gen (1);
          response_handler->cli_stub_any_op_gen (1);
          response_handler->cli_hdr_cdr_op_gen (1);
          response_handler->cli_stub_cdr_op_gen (1);
          response_handler->cli_inline_cdr_op_gen (1);
          response_handler->cli_inline_gen (1);
        }
      else
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_amh_pre_proc::"
                             "visit_interface - "
                             "creating the response handler failed\n"),
                            -1);
        }
      
      /*
      // Set the proper strategy
      be_interface_strategy *old_strategy =
      node->set_strategy (new be_interface_ami_strategy (node,
      response_handler));
      
      if (old_strategy)
      delete old_strategy;
      
      */
      if (this->visit_scope (node) == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "(%N:%l) be_visitor_amh_pre_proc::"
                           "visit_interface - visit scope failed\n"),
                          -1);
    }
  
  return 0;
}



int
be_visitor_amh_pre_proc::visit_operation (be_operation *node)
{
  // We do nothing for oneways!
  if (node->flags () == AST_Operation::OP_oneway)
    return 0;
  
  // Set the proper strategy
  be_operation_strategy *old_strategy =
    node->set_strategy (new be_operation_amh_strategy (node));
  
  if (old_strategy)
    delete old_strategy;
  
  /*  be_operation *sendc_marshaling =
      this->create_sendc_operation (node,
      0); // for arguments = FALSE
      
      be_operation *sendc_arguments =
      this->create_sendc_operation (node,
      1); // for arguments = TRUE
      
      if (sendc_marshaling && sendc_arguments)
      {
      sendc_marshaling->set_defined_in (node->defined_in ());
      
      sendc_arguments->set_defined_in (node->defined_in ());
      
      // We do not copy the exceptions because the exceptions
      // are delivered by the excep methods.
      
      // Set the proper strategy, and store the specialized
      // marshaling and arguments operations in it.
      be_operation_strategy *old_strategy =
      node->set_strategy (new be_operation_ami_sendc_strategy (node,
      sendc_marshaling,
      sendc_arguments));
      if (old_strategy)
      delete old_strategy;
      }
  */
  return 0;
}



int
be_visitor_amh_pre_proc::visit_attribute (be_attribute *node)
{
  // Temporarily generate the set operation.
  be_operation *set_operation =
    this->generate_set_operation (node);
  
  this->visit_operation (set_operation);
  
  // Retrieve the strategy set by the visit operation
  be_operation_strategy *set_operation_strategy =
    set_operation->set_strategy (
        new be_operation_default_strategy (set_operation)
      );
  
  // Assign it to the attribute as set_operation strategy
  if (set_operation_strategy)
    delete node->set_set_strategy (set_operation_strategy);
  
  // Temporerily generate the get operation.
  be_operation *get_operation =
    this->generate_get_operation (node);
  
  this->visit_operation (get_operation);
  
  be_operation_strategy *get_operation_strategy =
    get_operation->set_strategy (
        new be_operation_default_strategy (get_operation)
      );
  
  if (get_operation_strategy)
    delete node->set_get_strategy (get_operation_strategy);
  
  
  return 0;
}



be_valuetype *
be_visitor_amh_pre_proc::create_exception_holder (be_interface *node)
{
  
  // Create a virtual module named "Messaging" and a valuetype
  // "ExceptionHolder" from which we inherit.
  UTL_ScopedName *inherit_name =
    new UTL_ScopedName (new Identifier ("Messaging"),
                        0);
  
  inherit_name->nconc (new UTL_ScopedName (new Identifier ("ExceptionHolder"),
                                           0));
  
  be_valuetype *inherit_vt = new be_valuetype (inherit_name,
                                               0,
                                               0,
                                               0);
  inherit_vt->set_name (inherit_name);
  
  be_module *msg = 
    new be_module (new UTL_ScopedName (new Identifier ("Messaging"),
                                       0));

  // Notice the valuetype "ExceptionHolder" that it is defined in the
  // "Messaging" module
  inherit_vt->set_defined_in (msg);
  
  // Create the excpetion holder name
  ACE_CString excep_holder_local_name;
  this->generate_name (excep_holder_local_name,
                       "AMH_",
                       node->name ()->last_component ()->get_string(),
                       "");
  
  UTL_ScopedName *excep_holder_name = 
    ACE_static_cast (UTL_ScopedName *, node->name ()->copy ());
  excep_holder_name->last_component ()->replace_string (
                                            excep_holder_local_name.rep ()
                                          );
  
  AST_Interface_ptr *p_intf = new AST_Interface_ptr[1];
  p_intf[0] = ACE_static_cast (AST_Interface *, inherit_vt);
  
  be_valuetype *excep_holder = 
      new be_valuetype (excep_holder_name,  // name
                        p_intf,             // list of inherited
                        1,                  // number of inherited
                        0);                 // set abstract
  excep_holder->set_name (excep_holder_name);
  
  // Now our customized valuetype is created, we have to
  // add now the operations and attributes to the scope.
  
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
                                 "visit_interface - "
                                 "bad node in this scope\n"),
                                0);
              
            }

          be_decl *op = be_decl::narrow_from_decl (d);
          
          if (d->node_type () == AST_Decl::NT_attr)
            {
              AST_Attribute *attribute = AST_Attribute::narrow_from_decl (d);
              
              if (!attribute)
                return 0;
              
              this->create_raise_operation (op,
                                            excep_holder,
                                            GET_OPERATION);
              
              if (!attribute->readonly ())
                {
                  this->create_raise_operation (op,
                                                excep_holder,
                                                SET_OPERATION);
                }
              
            }
          else
            {
              this->create_raise_operation (op,
                                            excep_holder,
                                            NORMAL);
            }
          si->next ();
        } // end of while loop
      delete si;
    } // end of if

  return excep_holder;
}


be_interface *
be_visitor_amh_pre_proc::create_amh_class (be_interface *node)
{
  // Create the response handler name
  ACE_CString amh_class_local_name;
  this->generate_name (amh_class_local_name,
                       "AMH_",
                       node->name ()->last_component ()->get_string(),
                       "");

  UTL_ScopedName *amh_class_name = 
    ACE_static_cast (UTL_ScopedName *, node->name ()->copy ());
  amh_class_name->last_component ()->replace_string (
                                         amh_class_local_name.rep ()
                                       );

  //  AST_Interface_ptr *p_intf = new AST_Interface_ptr[1];

  be_interface *amh_class =
    new be_interface (amh_class_name, // name
                      0,              // list of inherited
                      0,              // number of inherited
                      0,              // list of ancestors
                      0,              // number of ancestors
                      0,              // non-local
                      0);             // non-abstract
  amh_class->set_name (amh_class_name);

  // Now our customized valuetype is created, we have to
  // add now the operations and attributes to the scope.

  if (node->nmembers () > 0)
    {
      // initialize an iterator to iterate thru our scope
      UTL_ScopeActiveIterator *si;
      ACE_NEW_RETURN (si,
                      UTL_ScopeActiveIterator (node,
                                               UTL_Scope::IK_decls),
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

              /*              
              be_operation *get_operation = this->generate_get_operation (attribute);

              this->create_response_handler_operation (get_operation,
              response_handler);

              this->create_excep_operation (get_operation,
              response_handler,
              excep_holder);

              if (!attribute->readonly ())
              {
              be_operation *set_operation = this->generate_set_operation (attribute);
              this->create_response_handler_operation (set_operation,
              response_handler);

              this->create_excep_operation (set_operation,
              response_handler,
              excep_holder);
              }
              */
            }
          else
            {
              be_operation* operation = be_operation::narrow_from_decl (d);

              if (operation)
                {
                  this->create_amh_operation (operation, amh_class);
                }
              /*
                if (operation)
                {
                this->create_response_handler_operation (operation,
                response_handler);

                this->create_excep_operation (be_operation::narrow_from_decl (d),
                response_handler,
                excep_holder);
                }
              */
            }
          si->next ();
        } // end of while loop
      delete si;
    } // end of if

  return amh_class;
}

/*
  be_interface *
  be_visitor_amh_pre_proc::create_rh_skel_class (be_interface *node)
  {
  // Create the rh_class name
  ACE_CString rh_class_local_name;
  this->generate_name (rh_class_local_name,
  "TAO_AMH_",
  node->name ()->last_component ()->get_string(),
  "ResponseHandler");

  UTL_ScopedName *rh_class_name = 
    ACE_static_cast (UTL_ScopedName *, node->name ()->copy ());
  rh_class_name->last_component ()->replace_string (
                                        rh_class_local_name.rep ()
                                      );

  //  AST_Interface_ptr *p_intf = new AST_Interface_ptr[1];

  be_interface *rh_class =
  new be_interface (rh_class_name, // name
                    0,              // list of inherited
                    0,              // number of inherited
                    0,              // list of ancestors
                    0,              // number of ancestors
                    0,              // non-local
                    0);             // non-abstract
  rh_class->set_name (rh_class_name);

  return rh_class;
  }
*/



int
be_visitor_amh_pre_proc::create_amh_operation (be_operation *node,
                                               be_interface *amh_class)
{
  if (!node)
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
    ACE_static_cast (UTL_ScopedName *, amh_class->name ()-> copy ());
  op_name->nconc (new UTL_ScopedName (new Identifier (original_op_name.rep ()),
                                      0));

  // Create the operation
  be_operation *operation = new be_operation (rt, //node->return_type (),
                                              AST_Operation::OP_noflags,
                                              op_name,
                                              0,
                                              0);
  operation->set_name (op_name);


  ACE_CString new_op_name = ACE_CString ("reply_") + original_op_name;

  UTL_ScopedName *rtop_name = 
    ACE_static_cast (UTL_ScopedName *, node->name ()-> copy ());
  op_name->last_component ()->replace_string (new_op_name.rep ());

  // Create the operation
  be_operation * rtoperation = new be_operation (rt, //node->return_type (),
                                                 AST_Operation::OP_noflags,
                                                 rtop_name,
                                                 0,
                                                 0);

  rtoperation->set_name (op_name);

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
          if (original_arg->direction () == AST_Argument::dir_INOUT ||
              original_arg->direction () == AST_Argument::dir_OUT)
            {
              // Create the argument
              be_argument *arg = new be_argument (original_arg->direction (),
                                                  original_arg->field_type (),
                                                  original_arg->name ());

              rtoperation->add_argument_to_scope (arg);
            }
          si->next ();
        }
      delete si;
    }

  // Set the proper strategy
  //be_operation_strategy *old_strategy =
  //  operation->set_strategy (new be_operation_amh_strategy (operation));
  //if (old_strategy)
  //  delete old_strategy;

  operation->set_defined_in (amh_class);

  // After having generated the operation we insert it into the
  // AMH class interface.
  amh_class->be_add_operation (operation);

  rtoperation->set_defined_in (amh_class);

  amh_class->be_add_operation (rtoperation);

  return 0;
}



be_interface *
be_visitor_amh_pre_proc::create_response_handler (
    be_interface *node,
    be_valuetype * /*excep_holder*/
  )
{
  // Generate 'Stock::AMH_QuoterResponseHandler'
  ACE_CString class_name (node->client_enclosing_scope ());
  class_name += "AMH_";
  class_name += node->local_name ();
  class_name += "ResponseHandler";
  UTL_ScopedName *inherit_name =
    new UTL_ScopedName (new Identifier (class_name.rep ()),
                        0);
  be_interface *inherit_intf = 
    new be_interface (inherit_name,
                      0,  // inherited interfaces
                      0,  // number of inherited interfaces
                      0,  // ancestors
                      0,  // number of ancestors
                      0,  // not local
                      0); // not abstract
  inherit_intf->set_name (inherit_name);

  // Generate 'TAO_AMH_ResponseHandler': This is fixed and same for any RH.
  ACE_CString tao_rh_name ("TAO_AMH_ResponseHandler");
  UTL_ScopedName *tao_inherit_name =
    new UTL_ScopedName (new Identifier (tao_rh_name.rep ()),
                        0);
  be_interface *tao_inherit_intf = 
    new be_interface (tao_inherit_name,
                      0,  // inherited interfaces
                      0,  // number of inherited interfaces
                      0,  // ancestors
                      0,  // number of ancestors
                      1,  // not local
                      0); // not abstract
  tao_inherit_intf->set_name (tao_inherit_name);



  // Create the response handler name
  ACE_CString response_handler_local_name;
  this->generate_name (response_handler_local_name,
                       "TAO_AMH_",
                       node->name ()->last_component ()->get_string(),
                       "ResponseHandler");

  UTL_ScopedName *response_handler_name = 
    ACE_static_cast (UTL_ScopedName *, node->name ()->copy ());
  response_handler_name->last_component ()->replace_string (
      response_handler_local_name.rep ()
    );

  AST_Interface_ptr *p_intf = new AST_Interface_ptr[2];
  p_intf[0] = ACE_static_cast (AST_Interface *, inherit_intf);
  p_intf[1] = ACE_static_cast (AST_Interface *, tao_inherit_intf);

  be_interface *response_handler =
    new be_interface (response_handler_name, // name
                      p_intf,             // list of inherited
                      2,                  // number of inherited
                      p_intf,             // list of ancestors
                      1,                  // number of ancestors
                      0,                  // non-local
                      0);                 // non-abstract
  response_handler->set_name (response_handler_name);

  // Now our customized valuetype is created, we have to
  // add now the operations and attributes to the scope.

  if (node->nmembers () > 0)
    {
      // initialize an iterator to iterate thru our scope
      UTL_ScopeActiveIterator *si;
      ACE_NEW_RETURN (si,
                      UTL_ScopeActiveIterator (node,
                                               UTL_Scope::IK_decls),
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
                                 "(%N:%l) be_visitor_amh_pre_proc::"
                                 "visit_interface - "
                                 "bad node in this scope\n"),
                                0);

            }

          if (d->node_type () == AST_Decl::NT_attr)
            {
              be_attribute *attribute = be_attribute::narrow_from_decl (d);

              if (!attribute)
                {
                  return 0;
                }
/*
              be_operation *get_operation = 
                this->generate_get_operation (attribute);
              this->create_response_handler_operation (get_operation,
                                                       response_handler);

              this->create_excep_operation (get_operation,
                                            response_handler,
                                            excep_holder);

              if (!attribute->readonly ())
                {
                be_operation *set_operation = this->generate_set_operation (attribute);
                this->create_response_handler_operation (set_operation,
                response_handler);

                this->create_excep_operation (set_operation,
                response_handler,
                excep_holder);
                }
*/
            }
          else
            {
              be_operation* operation = be_operation::narrow_from_decl (d);

              if (operation)
                {
                  this->create_response_handler_operation (operation,
                                                           response_handler);

                  /*                  
                  this->create_excep_operation (be_operation::narrow_from_decl (d),
                                                response_handler,
                                                excep_holder);
                  */
                }

            }

          si->next ();
        } // end of while loop

      delete si;
    } // end of if

  return response_handler;
}


int
be_visitor_amh_pre_proc::create_raise_operation (be_decl *node,
                                                 be_valuetype *excep_holder,
                                                 Operation_Kind operation_kind)
{
  be_operation *orig_op = 0;
  if (operation_kind == NORMAL)
    {
      orig_op = be_operation::narrow_from_decl (node);
      if (orig_op)
        {
          if (orig_op->flags () == AST_Operation::OP_oneway)
            // We do nothing for oneways!
            return 0;
        }
    }

  // Create the return type, which is "void"
  be_predefined_type *rt = 
    new be_predefined_type (AST_PredefinedType::PT_void,
                            new UTL_ScopedName (new Identifier ("void"),
                                                0));

  // Name the operation properly
  UTL_ScopedName *op_name = ACE_static_cast (UTL_ScopedName *,
                                             excep_holder->name ()-> copy ());

  ACE_CString new_local_name ("raise_");

  if (operation_kind == SET_OPERATION)
    {
      new_local_name += "set_";
    }
  else if (operation_kind == GET_OPERATION)
    {
      new_local_name += "get_";
    }

  new_local_name += node->name ()->last_component ()->get_string ();

  op_name->nconc (new UTL_ScopedName (new Identifier (new_local_name.rep ()),
                                      0));

  be_operation *operation = new be_operation (rt,
                                              AST_Operation::OP_noflags,
                                              op_name,
                                              0,
                                              0);
  operation->set_name (op_name);
  operation->set_defined_in (excep_holder);

  if (operation_kind == NORMAL)
    {
      if (orig_op)
        {
          // Copy the exceptions.
          if (orig_op->exceptions ())
            {
              UTL_ExceptList *exceptions = orig_op->exceptions ();
              operation->be_add_exceptions (exceptions);
            }
        }
    }

  // Set the proper strategy
  be_operation_strategy *old_strategy =
    operation->set_strategy (
        new be_operation_ami_exception_holder_raise_strategy (operation)
      );

  if (old_strategy)
    {
      delete old_strategy;
    }

  // After having generated the operation we insert it into the
  // exceptionholder valuetype.
  excep_holder->be_add_operation (operation);

  return 0;
}

int
be_visitor_amh_pre_proc::create_response_handler_operation (
    be_operation *node,
    be_interface *response_handler
  )
{
  if (!node)
    {
      return -1;
    }

  if (node->flags () == AST_Operation::OP_oneway)
    {
      // We do nothing for oneways!
      return 0;
    }

  // Create the return type, which is "void"
  be_predefined_type *rt = 
    new be_predefined_type (AST_PredefinedType::PT_void,
                            new UTL_ScopedName (new Identifier ("void"),
                                                0));

  ACE_CString original_op_name (
      node->name ()->last_component ()->get_string ()
    );

  UTL_ScopedName *op_name = 
    ACE_static_cast (UTL_ScopedName *, response_handler->name ()-> copy ());
  op_name->nconc (new UTL_ScopedName (new Identifier (original_op_name.rep ()), 
                                      0));

  // Create the operation
  be_operation *operation = new be_operation (rt,
                                              AST_Operation::OP_noflags,
                                              op_name,
                                              0,
                                              0);
  operation->set_name (op_name);

  // If return type is non-void add it as first argument

  if (!node->void_return_type ())
    {

      // Create the argument
      be_argument *arg = 
        new be_argument (AST_Argument::dir_IN,
                         node->return_type (),
                         new UTL_ScopedName (new Identifier ("return_value"), 
                                             0));

      // Add the response handler to the argument list
      operation->add_argument_to_scope (arg);
    }

  // Iterate over the arguments and put all the out and inout arguments
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

          //be_decl *arg = be_decl::narrow_from_decl (d);
          AST_Argument *original_arg = AST_Argument::narrow_from_decl (d);

          if (original_arg->direction () == AST_Argument::dir_INOUT ||
              original_arg->direction () == AST_Argument::dir_OUT)
            {
              // Create the argument
              be_argument *arg = new be_argument (AST_Argument::dir_IN,
                                                  original_arg->field_type (),
                                                  original_arg->name ());

              operation->add_argument_to_scope (arg);
            }
          si->next ();
        } // end of while loop

      delete si;
    } // end of if

  operation->set_defined_in (response_handler);

  // We do not copy the exceptions because the exceptions
  // are delivered by the excep methods.

  // After having generated the operation we insert it into the
  // response handler interface.
  response_handler->be_add_operation (operation);

  return 0;
}


/*
  int
  be_visitor_amh_pre_proc::create_excep_operation (be_operation *node,
  be_interface *response_handler,
  be_valuetype *excep_holder)
  {
  if (!node)
  return -1;

  if (node->flags () == AST_Operation::OP_oneway)
  // We do nothing for oneways!
  return 0;

  // Create the return type, which is "void"
  be_predefined_type *rt = new be_predefined_type (AST_PredefinedType::PT_void,
  new UTL_ScopedName
  (new Identifier ("void", 1, 0, I_FALSE),
  0),
  0);

  // Create the argument
  be_argument *arg = new be_argument (AST_Argument::dir_IN,
  excep_holder, // is also a valuetype
  new UTL_ScopedName (
  new Identifier (
  "excep_holder", 1, 0, I_FALSE),
  0),
  0);

  // Create the new name
  // Append _execp to the name of the operation
  ACE_CString original_op_name (node
  ->name ()
  ->last_component ()
  ->get_string ());
  ACE_CString new_op_name = original_op_name + ACE_CString ("_excep");

  UTL_ScopedName *op_name = ACE_static_cast (UTL_ScopedName *, response_handler->name ()-> copy ());
  op_name->nconc (new UTL_ScopedName
  (new Identifier
  (new_op_name.rep (), 1, 0, I_FALSE),
  0));

  // create the operation
  be_operation *operation = new be_operation (rt,
  AST_Operation::OP_noflags,
  op_name,
  0,
  0,
  0);
  operation->set_name (op_name);
  operation->add_argument_to_scope (arg);

  operation->set_defined_in (response_handler);

  // We do not copy the exceptions because the exceptions
  // are delivered by the excep methods.

  // After having generated the operation we insert it into the
  // response handler interface.
  response_handler->be_add_operation (operation);

  return 0;
  }
*/

// visit the scope and its elements
int
be_visitor_amh_pre_proc::visit_scope (be_scope *node)
{

  // proceed if the number of members in our scope is greater than 0
  if (node->nmembers () > 0)
    {
      int number_of_elements = 0;

      {
        // initialize an iterator to iterate thru our scope
        UTL_ScopeActiveIterator *si;
        ACE_NEW_RETURN (si,
                        UTL_ScopeActiveIterator (node,
                                                 UTL_Scope::IK_decls),
                        -1);

        while (!si->is_done ())
          {
            number_of_elements++;
            si->next ();
          }
        delete si;
      }

      AST_Decl **elements = new AST_Decl *[number_of_elements];

      {
        int position = 0;
        // initialize an iterator to iterate thru our scope
        UTL_ScopeActiveIterator *si;
        ACE_NEW_RETURN (si,
                        UTL_ScopeActiveIterator (node,
                                                 UTL_Scope::IK_decls),
                        -1);

        while (!si->is_done ())
          {
            elements[position++] = si->item ();
            si->next ();
          }
        delete si;
      }


      int elem_number = 0;

      // continue until each element is visited
      while (elem_number < number_of_elements)
        {
          AST_Decl *d = elements[elem_number];
          if (!d)
            {
              delete [] elements;
              ACE_ERROR_RETURN ((LM_ERROR,
                                 "(%N:%l) be_visitor_scope::visit_scope - "
                                 "bad node in this scope\n"), -1);

            }

          be_decl *bd = be_decl::narrow_from_decl (d);

          // set the scope node as "node" in which the code is being
          // generated so that elements in the node's scope can use it
          // for code generation
          this->ctx_->scope (node->decl ());

          // set the node to be visited
          this->ctx_->node (bd);
          elem_number++;


          // Send the visitor.
          if (bd == 0 ||  bd->accept (this) == -1)
            {
              delete [] elements;
              ACE_ERROR_RETURN ((LM_ERROR,
                                 "(%N:%l) be_visitor_scope::visit_scope - "
                                 "codegen for scope failed\n"), -1);

            }
        } // end of while loop
      delete [] elements;
    } // end of if
  return 0;
}

// Helper methods

int
be_visitor_amh_pre_proc::generate_name (ACE_CString &destination,
                                        const char *prefix,
                                        const char *middle_name,
                                        const char *suffix)
{
  destination = prefix;
  destination += middle_name;
  destination += suffix;
  return 0;
}



be_operation *
be_visitor_amh_pre_proc::generate_get_operation (be_attribute *node)
{
  ACE_CString original_op_name (node
                                ->name ()
                                ->last_component ()
                                ->get_string ());
  ACE_CString new_op_name = ACE_CString ("get_") + original_op_name;

  UTL_ScopedName *get_name = ACE_static_cast (UTL_ScopedName *,
                                              node->name ()-> copy ());
  get_name->last_component ()->replace_string (new_op_name.rep ());

  be_operation *operation =
    new be_operation (node->field_type (),
                      AST_Operation::OP_noflags,
                      get_name,
                      0,
                      0);
  operation->set_name (get_name);
  operation->set_defined_in (node->defined_in ());

  return operation;
}

be_operation *
be_visitor_amh_pre_proc::generate_set_operation (be_attribute *node)
{
  ACE_CString original_op_name (
      node->name ()->last_component ()->get_string ()
    );
  ACE_CString new_op_name = ACE_CString ("set_") + original_op_name;

  UTL_ScopedName *set_name = ACE_static_cast (UTL_ScopedName *,
                                              node->name ()-> copy ());
  set_name->last_component ()->replace_string (new_op_name.rep ());

  // the return type  is "void"
  be_predefined_type *rt = 
    new be_predefined_type (AST_PredefinedType::PT_void,
                            new UTL_ScopedName (new Identifier ("void"), 
                                                0));

  // argument type is the same as the attribute type
  be_argument *arg = new be_argument (AST_Argument::dir_IN,
                                      node->field_type (),
                                      set_name);
  arg->set_name (node->name ());

  // create the operation
  be_operation *operation = new be_operation (rt,
                                              AST_Operation::OP_noflags,
                                              set_name,
                                              0,
                                              0);
  operation->set_name (set_name);
  operation->set_defined_in (node->defined_in ());
  operation->add_argument_to_scope (arg);

  return operation;
}

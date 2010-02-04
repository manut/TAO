
//=============================================================================
/**
 *  @file    argument.cpp
 *
 *  $Id$
 *
 *  generic visitor for Argument node
 *
 *
 *  @author Aniruddha Gokhale
 */
//=============================================================================


be_visitor_args::be_visitor_args (be_visitor_context *ctx)
  : be_visitor_decl (ctx),
    fixed_direction_ (-1)
{
}

be_visitor_args::~be_visitor_args (void)
{
}

int be_visitor_args::visit_argument (be_argument *)
{
  return -1;
}

// Helper that returns the type name either as a nested type name (for header
// files) or as a fully scoped name. In addition, we make sure that if the type
// is an alias, we use that name.
const char *
be_visitor_args::type_name (be_type *node,
                            const char *suffix)
{
  static char namebuf [NAMEBUFSIZE];
  ACE_OS::memset (namebuf,
                  '\0',
                  NAMEBUFSIZE);

  be_type *bt = 0;

  // Use the typedefed name if that is the one used in the IDL defn.
  if (this->ctx_->alias ())
    {
      bt = this->ctx_->alias ();
    }
  else
    {
      bt = node;
    }

  ACE_OS::sprintf (namebuf,
                   "::%s",
                   bt->full_name ());

  if (suffix)
    {
      ACE_OS::strcat (namebuf,
                      suffix);
    }

  return namebuf;
}

// Helper that returns the direction type of the argument
AST_Argument::Direction
be_visitor_args::direction (void)
{
  if (this->fixed_direction_ != -1)
    {
      return AST_Argument::Direction (this->fixed_direction_);
    }

  // Grab the argument node. We know that our context has stored the right
  // argument node.
  be_argument *arg =
    be_argument::narrow_from_decl (this->ctx_->node ());

  return arg->direction ();
}

void
be_visitor_args::set_fixed_direction (AST_Argument::Direction direction)
{
  this->fixed_direction_ = direction;
}

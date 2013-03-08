// $Id$

// ============================================================================
//
// = DESCRIPTION
//      This class implements a CORBA client for a redundant CosNaming
//      Service using stubs generated by the TAO ORB IDL compiler.
//
// = AUTHORS
//      Rich Seibel <seibel_r@ociweb.com>
// ============================================================================

#include "test_objectS.h"
#include "orbsvcs/CosNamingC.h"
#include "orbsvcs/Naming/Naming_Server.h"
#include "tao/debug.h"
#include "ace/Get_Opt.h"
#include "ace/OS_NS_stdio.h"
#include "ace/High_Res_Timer.h"

#if defined (_MSC_VER)
# pragma warning (disable : 4250)
#endif /* _MSC_VER */

class My_Test_Object :
  public virtual POA_Test_Object
{
public:
  // = Initialization and termination methods.
  My_Test_Object (CORBA::Short id = 0);
  // Constructor.

  ~My_Test_Object (void);
  // Destructor.

  // = Interface implementation accessor methods.

  void id (CORBA::Short id);
  // Sets id.

  CORBA::Short id (void);
  // Gets id.

private:
  short id_;
};

My_Test_Object::My_Test_Object (CORBA::Short id)
  : id_ (id)
{
}

My_Test_Object::~My_Test_Object (void)
{
}

CORBA::Short
My_Test_Object::id (void)
{
  return id_;
}

void
My_Test_Object::id (CORBA::Short id)
{
  id_ = id;
}


// This function runs the test.

int
ACE_TMAIN(int argc, ACE_TCHAR *argv[])
{
  int c_breadth = 4;
  int c_depth = 4;
  int o_breadth = 4;
  ACE_TCHAR *ns1ref = 0;
  ACE_TCHAR *ns2ref = 0;
  int test_runs = 100;

  ACE_Get_Opt get_opts (argc, argv, ACE_TEXT ("b:d:o:p:q:t:"));
  int c;
  int i;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'b':
        i = ACE_OS::atoi(get_opts.opt_arg ());
        if (i<2)
        {
          ACE_ERROR((LM_ERROR,
                     ACE_TEXT ("Invalid breadth, must be 2 or more\n")));
          ACE_OS::exit(1);
        }
        c_breadth = i;
        break;
      case 'd':
        i = ACE_OS::atoi(get_opts.opt_arg ());
        if (i<2)
        {
          ACE_ERROR ((LM_ERROR,
                     ACE_TEXT ("Invalid depth, must be 2 or more\n")));
          ACE_OS::exit (1);
        }
        c_depth = i;
        break;
      case 'o':
        i = ACE_OS::atoi(get_opts.opt_arg ());
        if (i<2)
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("Invalid breadth, must be 2 or more\n")));
          ACE_OS::exit (1);
        }
        o_breadth = i;
        break;
      case 'p':
        ns1ref = get_opts.opt_arg ();
        break;
      case 't':
        i = ACE_OS::atoi (get_opts.opt_arg ());
        if (i<1)
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("Invalid number of test runs. ")
                      ACE_TEXT ("Must be 1 or more\n")));
          ACE_OS::exit (1);
        }
        test_runs = i;
        break;
      case 'q':
        ns2ref = get_opts.opt_arg ();
        break;
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("Argument %c \n usage:  %s")
                           ACE_TEXT (" [-b <breadth of context tree>]")
                           ACE_TEXT (" [-d <depth of context tree>]")
                           ACE_TEXT (" [-o <breadth of object tree>]")
                           ACE_TEXT (" [-t <number of performance test runs>]")
                           ACE_TEXT (" -p <ior of first name server>")
                           ACE_TEXT (" -q <ior of second name server>")
                           ACE_TEXT ("\n")),
                          -1);
      }

  CosNaming::NamingContext_var root_context_1;
  CosNaming::NamingContext_var root_context_2;

  try
  {
    // Initialize orb
    CORBA::ORB_var orb = CORBA::ORB_init(argc, argv);

    // ior's are specified for the name servers through a commandline
    // option or a file.

    // Resolve the first name server

    CORBA::Object_var ns1obj = orb->string_to_object (
                            ACE_TEXT_ALWAYS_CHAR (ns1ref));

    if (CORBA::is_nil (ns1obj.in ()))
            ACE_ERROR_RETURN ((LM_ERROR,
                               ACE_TEXT ("invalid ior <%s>\n"),
                               ns1ref),
                              -1);
    root_context_1 = CosNaming::NamingContext::_narrow (ns1obj.in ());

    // Resolve the second name server

    CORBA::Object_var ns2obj = orb->string_to_object (
                            ACE_TEXT_ALWAYS_CHAR (ns2ref));

    if (CORBA::is_nil (ns2obj.in ()))
            ACE_ERROR_RETURN ((LM_ERROR,
                               ACE_TEXT ("invalid ior <%s>\n"),
                               ns2ref),
                              -1);
    root_context_2 = CosNaming::NamingContext::_narrow (ns2obj.in ());

  }
  catch (const CORBA::Exception& ex)
  {
    ex._tao_print_exception (ACE_TEXT ("Unable to resolve name servers"));
    return -1;
  }

  // Create a bunch of objects in one context
  // Note: strings to the naming service must be char, not wchar
  try
  {
    // Bind one context level under root.
    CosNaming::Name level1;
    level1.length (1);
    level1[0].id = CORBA::string_dup ("level1_context");
    CosNaming::NamingContext_var level1_context;
    level1_context = root_context_1->bind_new_context (level1);

    for (i=0; i<o_breadth; i++)
    {
      // Instantiate a dummy object and bind it under the new context.
      My_Test_Object *impl1 = new My_Test_Object (i+1);
      Test_Object_var obj1 = impl1->_this ();
      impl1->_remove_ref ();

      level1.length (2);
      char wide_name[16];
      ACE_OS::sprintf(wide_name, "obj_%d", i);
      level1[1].id = CORBA::string_dup (wide_name);
      root_context_1->bind (level1, obj1.in ());

      // See if the newly bound object is available in the
      // replica
      try {
        CORBA::Object_var obj1_on_replica =
          root_context_2->resolve (level1);
      }
      catch (const CosNaming::NamingContext::NotFound& ex)
        {
          ex._tao_print_exception ("Unable to resolve object from replica.\n");

          // Try again...
          try {
            CORBA::Object_var obj1_on_replica =
              root_context_2->resolve (level1);
            // We did find the object on the replica, but only after a wait.
            // This would be caused by a race condition to access the variable.
            ACE_ERROR ((LM_ERROR,
                        "Object appeared after a short wait.\n"));
          }
          catch (const CosNaming::NamingContext::NotFound& second_ex)
            {
              second_ex._tao_print_exception ("It really is not there. Failing...\n");
              return -1;
            }
        }
    }
  }
  catch (const CORBA::Exception& ex)
  {
    ex._tao_print_exception (ACE_TEXT ("Unable to create a lot of objects"));
    return -1;
  }

  // Create a deep context tree
  try
  {
    CosNaming::NamingContext_var next_context = root_context_1;
    for (i=0; i<c_depth; i++)
    {
      // Bind level1 context under root.
      CosNaming::Name deep;
      deep.length (1);
      char deep_name[16];
      ACE_OS::sprintf(deep_name, "deep_%d", i);
      deep[0].id = CORBA::string_dup (deep_name);
      CosNaming::NamingContext_var deep_context;
      deep_context = next_context->bind_new_context (deep);
      next_context = deep_context;
    }
  }
  catch (const CORBA::Exception& ex)
  {
    ex._tao_print_exception (ACE_TEXT ("Unable to create deep context"));
    return -1;
  }

  // Create a wide context tree
  try
  {
    for (i=0; i<c_breadth; i++)
    {
      // Bind all level of context under root.
      CosNaming::Name wide;
      wide.length (1);
      char wide_name[16];
      ACE_OS::sprintf(wide_name, "wide_%d", i);
      wide[0].id = CORBA::string_dup (wide_name);
      CosNaming::NamingContext_var wide_context;
      wide_context = root_context_1->bind_new_context (wide);

      try {
        // Check if the new context is available in the replica
        CORBA::Object_var obj1_on_replica =
          root_context_2->resolve (wide);
        // Make sure it is a context
        CosNaming::NamingContext_var nc =
          CosNaming::NamingContext::_narrow (obj1_on_replica.in ());
      }
      catch (const CosNaming::NamingContext::NotFound& ex)
        {
          ex._tao_print_exception ("Unable to resolve wide context object from replica.\n");

          // Try again to see if it just was a race condition
          try {
            CORBA::Object_var obj1_on_replica =
              root_context_2->resolve (wide);
            // We did find the object on the replica, but only after a wait.
            // This would be caused by a race condition to access the variable.
            ACE_ERROR ((LM_ERROR,
                        "Object appeared after a short wait.\n"));
          }
          catch (const CosNaming::NamingContext::NotFound& second_ex)
            {
              second_ex._tao_print_exception ("It really is not there. Failing...\n");
              return -1;
            }
        }
    }
  }
  catch (const CORBA::Exception& ex)
  {
    ex._tao_print_exception (ACE_TEXT ("Unable to create wide context"));
    return -1;
  }

  // Delete three selected things, one from each tree
  try {
    // Remove the second to last object from the Naming Context
    CosNaming::Name wide1;
    wide1.length (2);
    wide1[0].id = CORBA::string_dup ("level1_context");
    char wide_name[16];
    ACE_OS::sprintf(wide_name, "obj_%d", o_breadth-2);
    wide1[1].id = CORBA::string_dup (wide_name);
    root_context_1->unbind (wide1);

    bool retried = false;
    // Make sure it is gone from the replica
    try {
      CORBA::Object_var obj1_on_replica =
        root_context_2->resolve (wide1);

      // An exception should be thrown by the above or
      // there is an error. This means the replica did
      // not register the loss of the context.
      ACE_ERROR ((LM_ERROR,
                  "Unbound deep context not removed from replica. Trying again...\n"));
      retried = true;  // Mark this so it can be reported in catch block.
      obj1_on_replica =
        root_context_2->resolve (wide1);
      ACE_ERROR_RETURN ((LM_ERROR,
                         "Unbound context not removed from on retry\n"),
                        -1);
    }
    catch (const CosNaming::NamingContext::NotFound&)
      {
        // Not on replica --- as it should be.
        if (retried)  // Was found on the retry
          ACE_ERROR ((LM_ERROR,
                      "Was removed after short wait.\n"));
      }

    // Remove the second to last context from the wide root Naming Context
    CosNaming::Name wide2;
    wide2.length (1);
    ACE_OS::sprintf(wide_name, "wide_%d", c_breadth-2);
    wide2[0].id = CORBA::string_dup (wide_name);
    CORBA::Object_var result_obj_ref = root_context_1->resolve (wide2);
    CosNaming::NamingContext_var result_object =
      CosNaming::NamingContext::_narrow (result_obj_ref.in ());
    if (CORBA::is_nil (result_object.in ()))
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("Problems with resolving wide context ")
                         ACE_TEXT ("- nil object ref.\n")),
                         -1);
    result_object->destroy();
    root_context_1->unbind (wide2);

    // Remove the last context from the deep Naming Context
    CosNaming::Name deep;
    deep.length (c_depth);
    char deep_name[16];
    for (i=0; i<c_depth; i++)
    {
      ACE_OS::sprintf(deep_name, "deep_%d", i);
      deep[i].id = CORBA::string_dup (deep_name);
    }
    result_obj_ref = root_context_1->resolve (deep);
    result_object =
      CosNaming::NamingContext::_narrow (result_obj_ref.in ());
    if (CORBA::is_nil (result_object.in ()))
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("Problems with resolving deep context ")
                         ACE_TEXT ("- nil object ref.\n")),
                         -1);
    result_object->destroy();
    root_context_1->unbind (deep);

    retried = false;
    // Make sure it is gone from the replica
    try {
      CORBA::Object_var obj1_on_replica =
        root_context_2->resolve (deep);

      // An exception should be thrown by the above or
      // there is an error. This means the replica did
      // not register the loss of the context.
      ACE_ERROR ((LM_ERROR,
                  "Unbound deep context not removed from replica. Trying again...\n"));
      retried = true;  // Mark this so it can be reported in catch block.
      obj1_on_replica =
        root_context_2->resolve (deep);
      ACE_ERROR_RETURN ((LM_ERROR,
                         "Unbound context not removed from on retry\n"),
                        -1);
    }
    catch (const CosNaming::NamingContext::NotFound&)
      {
        // Not on replica --- as it should be.
        if (retried)  // Was found on the retry
          ACE_ERROR ((LM_ERROR,
                      "Was removed after short wait.\n"));
      }
  }
  catch (const CORBA::Exception& ex)
  {
    ex._tao_print_exception (ACE_TEXT ("Unable to delete objects"));
    return -1;
  }

  // Now use the other name server to access 3 objects next to the
  // deleted objects and the 3 deleted objects
  try
  {
    // Access the last object from the Naming Context
    CosNaming::Name wide;
    wide.length (2);
    wide[0].id = CORBA::string_dup ("level1_context");
    char wide_name[16];
    ACE_OS::sprintf(wide_name, "obj_%d", o_breadth-1);
    wide[1].id = CORBA::string_dup (wide_name);
    CORBA::Object_var result_obj_ref = root_context_2->resolve (wide);
    Test_Object_var result_object = Test_Object::_narrow (result_obj_ref.in ());
    if (CORBA::is_nil (result_object.in ()))
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("Problems with resolving object from ")
                         ACE_TEXT ("redundant server - nil object ref.\n")),
                         -1);
  }
  catch (const CORBA::Exception& ex)
  {
    ex._tao_print_exception (
      ACE_TEXT (
        "Unable to resolve object from redundant server"));
    return -1;
  }

  try
  {
    // Access the deleted second to last object from the Naming Context
    CosNaming::Name wide;
    wide.length (2);
    wide[0].id = CORBA::string_dup ("level1_context");
    char wide_name[16];
    ACE_OS::sprintf(wide_name, "obj_%d", o_breadth-2);
    wide[1].id = CORBA::string_dup (wide_name);
    CORBA::Object_var result_obj_ref = root_context_2->resolve (wide);
    ACE_ERROR_RETURN ((LM_ERROR,
                    ACE_TEXT ("Problems with resolving object from ")
                    ACE_TEXT ("redundant server - deleted object found.\n")),
                    -1);
  }
  catch (const CosNaming::NamingContext::NotFound& ex)
  {
    // expect exception since the context was deleted.
    // Make sure the right exception reason is provided.
    if (ex.why != CosNaming::NamingContext::missing_node)
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("Wrong exception returned during resolve.\n")),
                         -1);
  }
  catch (const CORBA::Exception& ex)
    {
      ex._tao_print_exception (ACE_TEXT ("Wrong exception type returned from resolve.\n"));
      return -1;
    }
  try
  {
    // Access the last context from the wide Naming Context
    CosNaming::Name wide;
    wide.length (1);
    char wide_name[16];
    ACE_OS::sprintf(wide_name, "wide_%d", c_breadth-1);
    wide[0].id = CORBA::string_dup (wide_name);
    CORBA::Object_var result_obj_ref = root_context_2->resolve (wide);
    CosNaming::NamingContext_var result_object =
      CosNaming::NamingContext::_narrow (result_obj_ref.in ());
    if (CORBA::is_nil (result_object.in ()))
      ACE_ERROR_RETURN ((LM_ERROR,
                      ACE_TEXT ("Problems with resolving wide context from ")
                      ACE_TEXT ("redundant server - nil object ref.\n")),
                      -1);
  }
  catch (const CosNaming::NamingContext::NotFound&)
    {
      // Expected exception
    }
  catch (const CORBA::Exception& ex)
  {
    ex._tao_print_exception (
              ACE_TEXT ("Unexpected Exception received.\n"));
    return -1;
  }

  try
  {
    // Access the deleted second to last object from the Naming Context
    CosNaming::Name wide;
    wide.length (2);
    char wide_name[16];
    ACE_OS::sprintf(wide_name, "wide_%d", c_breadth-2);
    wide[0].id = CORBA::string_dup (wide_name);
    CORBA::Object_var result_obj_ref = root_context_2->resolve (wide);
    ACE_ERROR_RETURN ((LM_ERROR,
                    ACE_TEXT ("Problems with resolving wide context from ")
                    ACE_TEXT ("redundant server - deleted object found.\n")),
                    -1);
  }
  catch (const CosNaming::NamingContext::NotFound&)
    {
      // Expected exception
    }
  catch (const CORBA::Exception& ex)
  {
    ex._tao_print_exception (
              ACE_TEXT ("Unexpected Exception received.\n"));
    return -1;
  }

  try
  {
    // Access the deleted last context from the deep Naming Context
    CosNaming::Name deep;
    deep.length (c_depth);
    char deep_name[16];
    for (i=0; i<c_depth; i++)
    {
      ACE_OS::sprintf(deep_name, "deep_%d", i);
      deep[i].id = CORBA::string_dup (deep_name);
    }
    CORBA::Object_var result_obj_ref = root_context_1->resolve (deep);
    ACE_ERROR_RETURN ((LM_ERROR,
                    ACE_TEXT ("Problems with resolving deep context from ")
                    ACE_TEXT ("redundant server - deleted object found.\n")),
                    -1);
  }
  catch (const CosNaming::NamingContext::NotFound&)
    {
      // Expected exception
    }
  catch (const CORBA::Exception& ex)
  {
    ex._tao_print_exception (
             ACE_TEXT ("Unexpected Exception received resolving ")
             ACE_TEXT ("deep cxt from redundant server.\n"));
    return -1;
  }

  try
  {
    // Access the second to last object from the Naming Context
    CosNaming::Name deep;
    deep.length (c_depth-1);
    char deep_name[16];
    for (i=0; i<c_depth-1; i++)
    {
      ACE_OS::sprintf(deep_name, "deep_%d", i);
      deep[i].id = CORBA::string_dup (deep_name);
    }
    CORBA::Object_var result_obj_ref = root_context_1->resolve (deep);
    CosNaming::NamingContext_var result_object =
      CosNaming::NamingContext::_narrow (result_obj_ref.in ());
    if (CORBA::is_nil (result_object.in ()))
      ACE_ERROR_RETURN ((LM_ERROR,
                      ACE_TEXT ("Problems with resolving deep context from ")
                      ACE_TEXT ("redundant server - nil object ref.\n")),
                      -1);
  }
  catch (const CORBA::Exception& ex)
  {
    ex._tao_print_exception (
      ACE_TEXT (
        "Unable to resolve deep context from redundant server"));
    return -1;
  }

  // TODO: Cleanup namespace


  // TODO: Create object groups and bind them. Check the replica.

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("Redundancy test OK.\n")
              ACE_TEXT ("Starting performance tests.\n")));

  // Test performance of binding a bunch of objects in one context
  try
  {
    // Bind one context level under root.
    CosNaming::Name level1;
    level1.length (1);
    level1[0].id = CORBA::string_dup ("perf_context");
    CosNaming::NamingContext_var perf_context;
    perf_context = root_context_1->bind_new_context (level1);

    // Instantiate a dummy object and bind it under the new context.
    My_Test_Object *impl1 = new My_Test_Object (i+1);
    Test_Object_var obj1 = impl1->_this ();
    impl1->_remove_ref ();

    ACE_High_Res_Timer::global_scale_factor_type gsf =
      ACE_High_Res_Timer::global_scale_factor ();

    ACE_hrtime_t start = ACE_OS::gethrtime ();

    // Test how long it takes to bind
    for (i=0; i<test_runs; i++)
    {
      level1.length (1);
      char wide_name[16];
      ACE_OS::sprintf(wide_name, "obj_%d", i);
      level1[0].id = CORBA::string_dup (wide_name);
      perf_context->bind (level1, obj1.in ());
    }

    ACE_hrtime_t elapsed_time = ACE_OS::gethrtime () - start;
    // convert to microseconds
    ACE_UINT32 usecs = ACE_UINT32(elapsed_time / gsf);
    double secs = usecs / 1000000.0;

    ACE_DEBUG ((LM_DEBUG,
                "Bound %i objects in %.2f secs\n",
                test_runs, secs));

    // Test how long it takes to resolve
    start = ACE_OS::gethrtime ();
    for (i=0; i<test_runs; i++)
    {
      level1.length (1);
      char wide_name[16];
      ACE_OS::sprintf(wide_name, "obj_%d", i);
      level1[0].id = CORBA::string_dup (wide_name);
      CORBA::Object_var result_obj_ref = perf_context->resolve (level1);
    }

    elapsed_time = ACE_OS::gethrtime () - start;
    // convert to microseconds
    usecs = ACE_UINT32(elapsed_time / gsf);
    secs = ((ACE_INT32) usecs) / 1000000.0;

    ACE_DEBUG ((LM_DEBUG,
                "Resolved %i objects in %.2f secs\n",
                test_runs, secs));

    // Test how long it takes to unbind
    start = ACE_OS::gethrtime ();
    for (i=0; i<test_runs; i++)
    {
      level1.length (1);
      char wide_name[16];
      ACE_OS::sprintf(wide_name, "obj_%d", i);
      level1[0].id = CORBA::string_dup (wide_name);
      perf_context->unbind (level1);
    }

    elapsed_time = ACE_OS::gethrtime () - start;
    // convert to microseconds
    usecs = ACE_UINT32(elapsed_time / gsf);
    secs = ((ACE_INT32) usecs) / 1000000.0;

    ACE_DEBUG ((LM_DEBUG,
                "Unbound %i objects in %.2f secs\n",
                test_runs, secs));


  }
  catch (const CORBA::Exception& ex)
  {
    ex._tao_print_exception (ACE_TEXT ("ERROR: Exception during performance test.\n"));
    return -1;
  }


  return 0;

}

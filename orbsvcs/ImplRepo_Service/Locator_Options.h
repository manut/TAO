// -*- C++ -*-

//=============================================================================
/**
 *  @file   Locator_Options.h
 *
 *  $Id$
 *
 *  @brief  Definition of the Options class for the Implementation Repository.
 *
 *  @author Darrell Brunsch <brunsch@cs.wustl.edu>
 */
//=============================================================================

#ifndef LOCATOR_OPTIONS_H
#define LOCATOR_OPTIONS_H

#include "locator_export.h"

#include "ace/SString.h"
#include "ace/Time_Value.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

/**
 * @class Options
 *
 * @brief Maintains the global options.
 *
 * This is where the settings for TAO's Implementation Repository are stored.
 */
class Locator_Export Options
{
public:

  enum SERVICE_COMMAND {
    SC_NONE,
    SC_INSTALL,
    SC_REMOVE
  };

  enum RepoMode {
    REPO_NONE,
    REPO_XML_FILE,
    REPO_HEAP_FILE,
    REPO_REGISTRY
  };

  Options ();

  /// Parse the command-line arguments and initialize the options.
  int init (int argc, char *argv[]);
  /// This version should only be used when run as an nt service.
  int init_from_registry();

  /// Service Mode
  bool service (void) const;

  /// Debug level for the Implementation Repository.
  unsigned int debug (void) const;

  /// Returns the file where the IOR should be stored.
  const ACE_TString& ior_filename (void) const;

  /// Will we listen for multicast location requests?
  bool multicast (void) const;

  /// The nt service command to run (install/remove)
  SERVICE_COMMAND service_command(void) const;

  int save_registry_options();

  const ACE_TString& cmdline(void) const;

  /// File that contains the activator related information
  /// that the persistent locator has to save.
  const ACE_TString& persist_file_name(void) const;

  /// Do we allow modifications to the servers?
  bool readonly (void) const;

  RepoMode repository_mode (void) const;

  /// Returns the timeout value for program starting.
  ACE_Time_Value startup_timeout (void) const;

  /// If the server hasn't been verified for a while, then we'll
  /// ping it. Note : No timers are currently used. We simply ping()
  /// during indirect invocations, if this interval has elapsed.
  ACE_Time_Value ping_interval (void) const;

private:
  /// Parses and pulls out arguments for the ImR
  int parse_args (int &argc, char *argv[]);

  /// Print the usage information.
  void print_usage (void) const;

  /// Run a service command.
  int run_service_command (const ACE_TString& cmdline);

  int load_registry_options();
private:

  // xml, heap, or registry
  RepoMode repo_mode_;

  /// Debug level.
  unsigned int debug_;

  /// File where the IOR of the server object is stored.
  ACE_TString ior_output_file_;

  /// Will we listen for multicast location requests?
  bool multicast_;

  /// Are we running as a service?
  bool service_;

  /// The amount of time between successive "are you started yet?" pings.
  ACE_Time_Value ping_interval_;
 
  /// The amount of time to wait for a server to response after starting it.
  ACE_Time_Value startup_timeout_;

  /// Can the server_repository be modified?
  bool readonly_;

  /// SC_NONE, SC_INSTALL, SC_REMOVE, ...
  SERVICE_COMMAND service_command_;

  /// Our extra command line arguments
  ACE_CString cmdline_;

  /// The persistent XML file name.
  ACE_TString persist_file_name_;
};

#endif

/* -*- C++ -*- */
//=============================================================================
/**
 *  @file   Options.h
 *
 *  $Id$
 *
 *  @brief  Definition of the Options class for the Implementation Repository.
 *
 *  @author Darrell Brunsch <brunsch@cs.wustl.edu>
 */
//=============================================================================

#ifndef OPTIONS_H
#define OPTIONS_H

#include "tao/ORB.h"
#include "ace/Singleton.h"

// Forward declaration, so we don't to include ace/Configuration.h yet.
class ACE_Configuration;

/**
 * @class Options
 *
 * @brief Maintains the global options.
 *
 * This is where all the settings for TAO's Implementation Repository is
 * stored.  
 */
class Options
{
public:
  /// Default Constructor
  Options ();

  /// Destructor
  ~Options();

  /// Parse the command-line arguments and initialize the options.
  int parse_args (int argc, ACE_TCHAR *argv[]);

  /// Service Mode
  int service (void) const;

  /// Debug level for the Implementation Repository.  
  unsigned int debug (void) const;

  /// Returns the file where the IOR should be stored.
  FILE *output_file (void) const;

  /// Returns the configuration  object.
  ACE_Configuration* config (void) const;

  /// Returns the timeout value for program starting.
  const ACE_Time_Value &startup_timeout (void) const;

  /// Returns the timeout value for program starting.
  const ACE_Time_Value &ping_interval (void) const;

  /// Returns a pointer to the ORB.
  CORBA::ORB_ptr orb (void) const;

private:
  /// Print the usage information.
  void print_usage (void) const;

  /// Initialize file persistence.
  int initialize_file_persistence (ACE_TCHAR *filename);

  /// Initialize Registry persistence.
  int initialize_registry_persistence (void);

  /// Initialize default heap for no persistence.
  int initialize_non_persistence (void);

  /// Run a service command.
  int run_service_command (ACE_TCHAR *command);

  /// Are we running as a service?
  int service_;

  /// Debug level.
  unsigned int debug_;

  /// File where the IOR of the server object is stored.
  FILE *ior_output_file_;

  /// The persistent configuration object.
  ACE_Configuration* config_;

  /// The amount of time to wait for a server to response after starting it.
  ACE_Time_Value startup_timeout_;

  /// The amount of time between successive "are you started yet?" pings.
  ACE_Time_Value ping_interval_;

  /// The ORB for the Implementation Repository.
  CORBA::ORB_var orb_;
};

typedef ACE_Singleton <Options, ACE_Null_Mutex> OPTIONS;

#endif /* OPTIONS_H */


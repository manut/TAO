/* -*- c++ -*- */

#if !defined (TAO_AV_SERVER_H)
#define      TAO_AV_SERVER_H

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <time.h>
#include <sys/time.h>
#include "../include/common.h"
#include "../mpeg_server/proto.h"
#include "fileio.h"
#include "routine.h"
#include "com.h"
#include "ace/Get_Opt.h"

#include "ace/Acceptor.h"
#include "ace/Svc_Handler.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/INET_Addr.h"
#include "ace/SOCK_CODgram.h"
#include "ace/Select_Reactor.h"

#ifdef NATIVE_ATM
#include "atmcom.h"
#endif

#include "../mpeg_server/Video_Server.h"

class Mpeg_Svc_Handler;

class Mpeg_Acceptor 
  : public virtual ACE_Acceptor <Mpeg_Svc_Handler, 
                                 ACE_SOCK_ACCEPTOR>
{
public:  
  virtual int make_svc_handler (Mpeg_Svc_Handler *&sh);
  // Initialize the <Mpeg_Svc_Handler>.
};

class Mpeg_Svc_Handler 
  : public virtual ACE_Svc_Handler <ACE_SOCK_STREAM, 
                                    ACE_NULL_SYNCH>
{
  // @@ Naga, please make sure to document all these classes with the =TITLE/=DESCRIPTION stuff!
public:
  // = Initialization method.
  Mpeg_Svc_Handler (ACE_Reactor * = 0,
                    Mpeg_Acceptor * = 0);

  virtual int open (void *);
  // Perform the work of the SVC_HANDLER. Called by the acceptor
  // when a new connection shows up
  
  virtual int handle_connection (ACE_HANDLE = ACE_INVALID_HANDLE);
  // Handle one client connection.

  virtual int svc (void);
  // Thread method

  virtual int close (u_long);
  // Called if ACE_Svc_Handler is closed down unexpectedly.

  virtual int handle_timeout (const ACE_Time_Value &, const void *arg);
  // Handles acceptor timeouts.
private:

  ACE_SOCK_CODgram dgram_;
  // the UDP data socket

  ACE_INET_Addr server_data_addr_;
  // Data (UDP) Address of this server.
  
  ACE_INET_Addr client_data_addr_;
  // Data (UDP) Address of the client.

  Mpeg_Acceptor *acceptor_;
  // Pointer to the Acceptor that created us so that we can remove it
  // from the <ACE_Reactor> when we <fork>.

  // %% need a similar dude for audio!
  Video_Server vs_;
};

class Mpeg_Server
{
  // =TITLE
  //   Defines a class that abstracts the functionality of a mpeg
  //   video and audio server.
public:
  Mpeg_Server ();
  int init (int argc,
            char **argv);
  // Initialize the mpeg_server

  int run ();
  // Run the Mpeg_Server

  static  void int_handler (int sig);
  static  void on_exit_routine (void);
  static  void clear_child (int sig);
  // various signal handlers
  // we need them to be static 
  static void init_static (void);

  ~Mpeg_Server ();
private:

  Mpeg_Acceptor acceptor_;
  // the acceptor

  // %% why is this here  ? this should be in video_server
  // if you are newing the other handlers, you should new 
  // this one also, and destroy them in the destructor
  // for video_server
  //  Video_Sig_Handler vh_;
  // signal handler for SIGALRM to periodically send the video frames
  // to the client

  ACE_INET_Addr server_control_addr_;
  // Control (TCP) Address of this server.

  int parse_args (int argcs,
                  char **argv);
  // parse the arguments

  int set_signals (void);

};

#endif // TAO_AV_SERVER_H

eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

use lib "$ENV{ACE_ROOT}/bin";
use PerlACE::Run_Test;

PerlACE::check_privilege_group();

$ior = PerlACE::LocalFile ("supplier.ior");
$namingior = PerlACE::LocalFile ("naming.ior");
$notifyior = PerlACE::LocalFile ("notify.ior");
$notify_conf = PerlACE::LocalFile ("notify$PerlACE::svcconf_ext");
$status = 0;

$port = PerlACE::uniqueid () + 10001;
$NS = new PerlACE::Process ("../../../Naming_Service/Naming_Service",
                            "-ORBEndpoint iiop://localhost:$port " .
                            "-o $namingior");
$TS = new PerlACE::Process ("../../../Notify_Service/Notify_Service",
                            "-ORBInitRef NameService=iioploc://" .
                            "localhost:$port/NameService " .
                            "-IORoutput $notifyior -ORBSvcConf " .
                            "$notify_conf");
$STS = new PerlACE::Process ("Structured_Supplier",
                             "-ORBInitRef NameService=iioploc://" .
                             "localhost:$port/NameService");
$STC = new PerlACE::Process ("Structured_Consumer");

unlink $ior;
unlink $notifyior;
unlink $namingior;

$client_args = "-ORBInitRef NameService=iioploc://localhost:" .
               "$port/NameService";
$NS->Spawn ();

if (PerlACE::waitforfile_timed ($namingior, 20) == -1) {
      print STDERR "ERROR: waiting for the naming service to start\n";
      $NS->Kill ();
      exit 1;
}

$TS->Spawn ();

if (PerlACE::waitforfile_timed ($notifyior, 20) == -1) {
    print STDERR "ERROR: waiting for the notify service to start\n";
    $TS->Kill ();
    $NS->Kill ();
    exit 1;
}

print "****** Running consumer long blocking timeout ******\n";

unlink $ior;
$STS->Arguments($STS->Arguments());
$STS->Spawn ();
if (PerlACE::waitforfile_timed ($ior, 5) == -1) {
    print STDERR "ERROR: waiting for the supplier to start\n";
    $STS->Kill ();
    $TS->Kill ();
    $NS->Kill ();
    exit 1;
}

$STC->Arguments($client_args . " -t 2000");
$client = $STC->SpawnWaitKill (10);
if ($client != 0) {
  $STS->Kill ();
  $TS->Kill ();
  $NS->Kill ();
  exit 1;
}
$server = $STS->WaitKill(5);
if ($server != 0) {
  $TS->Kill ();
  $NS->Kill ();
  exit 1;
}

print "****** Running consumer with short blocking timeout ******\n";

unlink $ior;
$STS->Arguments($STS->Arguments());
$STS->Spawn ();

if (PerlACE::waitforfile_timed ($ior, 5) == -1) {
  print STDERR "ERROR: waiting for the supplier to start\n";
  $STS->Kill ();
  $TS->Kill ();
  $NS->Kill ();
  exit 1;
}

$STC->Arguments($client_args . " -e 19 -t 500");
$client = $STC->SpawnWaitKill (10);
if ($client != 0) {
  print STDERR "ERROR: Structured_Consumer did not run properly\n";
  $STS->Kill ();
  $TS->Kill ();
  $NS->Kill ();
  exit 1;
}
$server = $STS->WaitKill(5);
if ($server != 0) {
  $TS->Kill ();
  $NS->Kill ();
  exit 1;
}

$TS->Kill ();
$NS->Kill ();

unlink $ior;
unlink $notifyior;
unlink $namingior;


exit $status;

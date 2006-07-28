eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

use lib "$ENV{ACE_ROOT}/bin";
use PerlACE::Run_Test;
use File::stat;

# amount of delay between running the servers

$sleeptime = 2;
$status = 0;

$nsior = PerlACE::LocalFile ("ns.ior");
$testfile = PerlACE::LocalFile ("test");
$input = PerlACE::LocalFile ("test_input");

unlink $nsior, $testfile, $input;

# generate test stream data
$input = PerlACE::generate_test_file("test_input", 102400);

$NS = new PerlACE::Process ("../../../Naming_Service/Naming_Service", "-o $nsior");
$SV = new PerlACE::Process ("sender", "-ORBInitRef NameService=file://$nsior -f $input");
$RE = new PerlACE::Process ("receiver", "-ORBInitRef NameService=file://$nsior -f $testfile");
$DI = new PerlACE::Process ("distributer", "-ORBInitRef NameService=file://$nsior");

print STDERR "Starting Naming Service\n";

$NS->Spawn ();

if (PerlACE::waitforfile_timed ($nsior, 10) == -1) {
    print STDERR "ERROR: cannot find naming service IOR file\n";
    $NS->Kill ();
    exit 1;
}

print STDERR "Starting Receiver\n";

$RE->Spawn ();

sleep $sleeptime;

print STDERR "Starting Sender\n";

$SV->Spawn ();

sleep $sleeptime;

print STDERR "Starting Distributer\n";

$distributer = $DI->SpawnWaitKill (200);

if ($distributer != 0) {
    print STDERR "ERROR: distributer returned $distributer\n";
    $status = 1;
}

$sender = $SV->TerminateWaitKill (60);

if ($sender != 0) {
    print STDERR "ERROR: sender returned $sender\n";
    $status = 1;
}

$receiver = $RE->TerminateWaitKill (60);

if ($receiver != 0) {
    print STDERR "ERROR: sender returned $sender\n";
    $status = 1;
}


$nserver = $NS->TerminateWaitKill (60);

if ($nserver != 0) {
    print STDERR "ERROR: Naming Service returned $nserver\n";
    $status = 1;
}

unlink $nsior, $testfile, $input;

exit $status;

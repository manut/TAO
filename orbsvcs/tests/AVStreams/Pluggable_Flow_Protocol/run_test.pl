eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

use lib $ENV{"ACE_ROOT"}.'/bin';
use PerlACE::Run_Test;
use File::stat;

# amount of delay between running the servers

$sleeptime = 2;
$status = 0;

$nsior = PerlACE::LocalFile ("ns.ior");
$outfile = PerlACE::LocalFile ("output");

# generate test stream data
$input = "test_input";
while ( -e $input ) {
    $input = $input."X";
}
open( INPUT, "> $input" ) || die( "can't create input file: $input" );
for($i =0; $i < 1000 ; $i++ ) {
    print INPUT <<EOFINPUT;
0123456789
0123456789
0123456789
0123456789
0123456789
0123456789
0123456789
0123456789
0123456789
0123456789
EOFINPUT
}
close(INPUT);

unlink $nsior;

$NS = new PerlACE::Process ($ENV{"TAO_ROOT"}."/orbsvcs/Naming_Service/Naming_Service", "-o $nsior");
$SV = new PerlACE::Process ("receiver", "-ORBInitRef NameService=file://$nsior -f output");
$CL = new PerlACE::Process ("sender", "-ORBDebugLevel 2 -ORBInitRef NameService=file://$nsior -f $input -r 2");

print STDERR "Starting Naming Service\n";

$NS->Spawn ();

if (PerlACE::waitforfile_timed ($nsior, 5) == -1) {
    print STDERR "ERROR: cannot find naming service IOR file\n";
    $NS->Kill ();
    exit 1;
}

print STDERR "Starting Receiver\n";

$SV->Spawn ();

sleep $sleeptime;

print STDERR "Starting Sender\n";

$sender = $CL->SpawnWaitKill (200);

if ($sender != 0) {
    print STDERR "ERROR: sender returned $sender\n";
    $status = 1;
}

$receiver = $SV->TerminateWaitKill (5);

if ($receiver != 0) {
    print STDERR "ERROR: receiver returned $receiver\n";
    $status = 1;
}

$nserver = $NS->TerminateWaitKill (5);

if ($nserver != 0) {
    print STDERR "ERROR: Naming Service returned $nserver\n";
    $status = 1;
}

unlink $nsior;
unlink $output, $input;

exit $status;

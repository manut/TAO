eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
     & eval 'exec perl -S $0 $argv:q'
     if 0;

# $Id$
# -*- perl -*-

use lib '../../../bin';
use PerlACE::Run_Test;

$iorfile = PerlACE::LocalFile ("server.ior");
unlink $iorfile;

$SV = new PerlACE::Process ("server", "-o $iorfile -ORBdotteddecimaladdresses 1");
$CL1 = new PerlACE::Process ("client", "-k file://$iorfile");
$CL2 = new PerlACE::Process ("client", "-k file://$iorfile");
$CL3 = new PerlACE::Process ("client", "-k file://$iorfile");

local $start_time = time();
local $max_running_time = 600; # 10 minutes
local $elapsed = time() - $start_time;

local $ntimes = 50 ; # run test for 50 times
local $n = 0;

while($n < $ntimes) {

print STDERR " Going .. \n";
$sv1 = $SV->Spawn ();

if (PerlACE::waitforfile_timed ($iorfile,
                        $PerlACE::wait_interval_for_process_creation) == -1) {
    print STDERR "ERROR: cannot find file <$iorfile>\n";
    $SV->Kill (); $SV->TimedWait (1);
    exit 1;
}
# Start all clients in parallel
$client1 = $CL1->Spawn ();
$client2 = $CL2->Spawn ();
$client3 = $CL3->Spawn ();


sleep (30);
$SV->WaitKill (3) unless $sv1 < 0;
$CL1->WaitKill (3);
$CL2->WaitKill (3);
$CL3->WaitKill (3);

if ($client3 != 0){
    $status = -1;
    exit $status;
}

if ($client2 != 0) {
    $status = -1;
    exit $status;
}

if ($client1 != 0){
    $status = -1;
    exit $status;
}
  # $elapsed = time() - $start_time;
$n = $n + 1;

unlink $iorfile;
}



exit $status;

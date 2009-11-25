eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
     & eval 'exec perl -S $0 $argv:q'
     if 0;

# $Id$
# -*- perl -*-

use lib "$ENV{ACE_ROOT}/bin";
use PerlACE::TestTarget;

$includes = "-I ../../../..  -I ../../../../orbsvcs";

$status = 0;
$debug_level = '0';
$debug_client = '';

foreach $i (@ARGV) {
    if ($i eq '-debug') {
        $debug_level = '10';
    }
    if ($i eq '-d') {
        $debug_client = "-n";
    }
}

my $server1 = PerlACE::TestTarget::create_target (1) || die "Create target 1 failed\n";
my $server2 = PerlACE::TestTarget::create_target (2) || die "Create target 2 failed\n";
my $client = PerlACE::TestTarget::create_target (3) || die "Create target 3 failed\n";

my $ior1file = "ifr.ior";

#Files which used by server1
my $server1_ior1file = $server1->LocalFile ($ior1file);
$server1->DeleteFile($ior1file);

#Files which used by server2
my $server2_ior1file = $server2->LocalFile ($ior1file);
$server2->DeleteFile($ior1file);

#Files which used by client
my $client_ior1file = $client->LocalFile ($ior1file);
$client->DeleteFile($ior1file);


$SV1 = $server1->CreateProcess ("../../../IFR_Service/IFR_Service",
                              "-ORBdebuglevel $debug_level " .
                              "-o $server1_ior1file");

$SV2 = $server2->CreateProcess ("$ENV{ACE_ROOT}/bin/tao_ifr",
                              "-ORBdebuglevel $debug_level " .
                              "-ORBInitRef InterfaceRepository=file://$server1_ior1file $includes test.idl");

$CL = $client->CreateProcess ("IDL3_Test",
                              "-ORBInitRef InterfaceRepository=file://$client_ior1file " .
                              "$debug_client");

$server_status = $SV1->Spawn ();

if ($server_status != 0) {
    print STDERR "ERROR: server returned $server_status\n";
    exit 1;
}

if ($server1->WaitForFileTimed ($ior1file,
                               $server1->ProcessStartWaitInterval()) == -1) {
    print STDERR "ERROR: cannot find file <$server1_ior1file>\n";
    $SV1->Kill (); $SV1->TimedWait (1);
    exit 1;
}

if ($server1->GetFile ($ior1file) == -1) {
    print STDERR "ERROR: cannot retrieve file <$server1_ior1file>\n";
    $SV1->Kill (); $SV1->TimedWait (1);
    exit 1;
}

if ($server2->PutFile ($ior1file) == -1) {
    print STDERR "ERROR: cannot set file <$server2_ior1file>\n";
    $SV1->Kill (); $SV1->TimedWait (1);
    exit 1;
}

if ($client->PutFile ($ior1file) == -1) {
    print STDERR "ERROR: cannot set file <$client_ior1file>\n";
    $SV1->Kill (); $SV1->TimedWait (1);
    exit 1;
}

$server_status = $SV2->SpawnWaitKill ($server2->ProcessStartWaitInterval());

if ($server_status != 0) {
    print STDERR "ERROR: server returned $server_status\n";
    exit 1;
}

$client_status = $CL->SpawnWaitKill ($client->ProcessStartWaitInterval() + 45);

if ($client_status != 0) {
    print STDERR "ERROR: client returned $client_status\n";
    $status = 1;
}

$server_status = $SV1->TerminateWaitKill ($server1->ProcessStopWaitInterval());

if ($server_status != 0) {
    print STDERR "ERROR: server returned $server_status\n";
    $status = 1;
}

$server1->DeleteFile($ior1file);
$server2->DeleteFile($ior1file);
$client->DeleteFile($ior1file);

exit $status;

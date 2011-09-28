eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
     & eval 'exec perl -S $0 $argv:q'
     if 0;

# $Id$
# -*- perl -*-

use lib "$ENV{ACE_ROOT}/bin";
use PerlACE::TestTarget;

my $server = PerlACE::TestTarget::create_target(1) || die "Create target 1 failed\n";

$iorbase = "test.ior";
my $server_iorfile = $server->LocalFile ($iorbase);
$server->DeleteFile($iorbase);

$status = 0;

$SV = $server->CreateProcess ("Bug_2241_Regression");

print STDERR "======== Running in Default Mode \n";
$SV->Arguments ("-o $server_iorfile -k file://$server_iorfile");
$sv = $SV->SpawnWaitKill ($server->ProcessStartWaitInterval());

if ($sv != 0) {
    print STDERR "ERROR in Collocated_Test\n";
    $status = 1;
}
$server->DeleteFile($iorbase);

print STDERR "======== Running with global ORBCollocationStrategy\n";
$SV->Arguments ("-o $server_iorfile -k file://$server_iorfile -ORBCollocation global");
$sv = $SV->SpawnWaitKill ($server->ProcessStartWaitInterval());

if ($sv != 0) {
    print STDERR "ERROR in Collocated_Test\n";
    $status = 1;
}
$server->DeleteFile($iorbase);

print STDERR "======== Running with global ORBCollocationStrategy thru_poa\n";
$SV->Arguments ("-o $server_iorfile -k file://$server_iorfile -ORBCollocation global -ORBCollocationStrategy thru_poa");
$sv = $SV->SpawnWaitKill ($server->ProcessStartWaitInterval());

if ($sv != 0) {
    print STDERR "ERROR in Collocated_Test\n";
    $status = 1;
}
$server->DeleteFile($iorbase);

print STDERR "======== Running with -ORBCollocation global -ORBCollocationStrategy direct \n";
$SV->Arguments ("-o $server_iorfile -k file://$server_iorfile -ORBCollocation global -ORBCollocationStrategy direct");
$sv = $SV->SpawnWaitKill ($server->ProcessStartWaitInterval());

if ($sv != 0) {
    print STDERR "ERROR in Collocated_Test\n";
    $status = 1;
}

$server->DeleteFile($iorbase);
$server->GetStderrLog();

exit $status;

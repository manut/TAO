eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

use lib "$ENV{ACE_ROOT}/bin";
use PerlACE::TestTarget;

sub get_test_modes
{
      my $testid = shift;

      my $client_mode = "LOCAL_AND_REMOTE";
      my $server_mode = "LOCAL_AND_REMOTE";

      # There are Nine Permutations.
      if ($testid == 1) {
          $client_mode = "LOCAL_AND_REMOTE";
          $server_mode = "LOCAL_AND_REMOTE";
      }
      elsif ($testid == 2) {
          $client_mode = "LOCAL_AND_REMOTE";
          $server_mode = "LOCAL_ONLY";
      }
      elsif ($testid == 3) {
          $client_mode = "LOCAL_AND_REMOTE";
          $server_mode = "REMOTE_ONLY";
      }
      elsif ($testid == 4) {
          $client_mode = "LOCAL_ONLY";
          $server_mode = "LOCAL_AND_REMOTE";
      }
      elsif ($testid == 5) {
          $client_mode = "LOCAL_ONLY";
          $server_mode = "LOCAL_ONLY";
      }
      elsif ($testid == 6) {
          $client_mode = "LOCAL_ONLY";
          $server_mode = "REMOTE_ONLY";
      }
      elsif ($testid == 7) {
          $client_mode = "REMOTE_ONLY";
          $server_mode = "LOCAL_AND_REMOTE";
      }
      elsif ($testid == 8) {
          $client_mode = "REMOTE_ONLY";
          $server_mode = "LOCAL_ONLY";
      }
      elsif ($testid == 9) {
          $client_mode = "REMOTE_ONLY";
          $server_mode = "REMOTE_ONLY";
      }
      else {
          print STDERR "ERROR: invalid testid: $testid\n";
          exit 1;
      }

      return ($client_mode, $server_mode);
}

my $status = 0;

my $server = PerlACE::TestTarget::create_target (1) || die "Create target 1 failed\n";
my $client = PerlACE::TestTarget::create_target (2) || die "Create target 2 failed\n";

my $testid;

for ($testid = 1; $testid <= 9; ++$testid) {

    my $client_mode;
    my $server_mode;

    ($client_mode, $server_mode) = get_test_modes($testid);

    my $SV;

    $SV = $server->CreateProcess ("PI_ProcMode_Remote_TestServer", 
                                      "-p $server_mode " .
                                      "-ORBobjrefstyle url");
      
    print STDERR "\n\n==== Starting test variant #$testid\n\n";

    $server_status = $SV->Spawn ();

    if ($server_status != 0) {
        print STDERR "ERROR: server returned $server_status\n";
        exit 1;
    }

    my $CL = $client->CreateProcess ("PI_ProcMode_Remote_TestClient",
                                      "-p $client_mode " .
                                      "-ORBobjrefstyle url");

    my $client_status = $CL->SpawnWaitKill ($client->ProcessStartWaitInterval() + 30);

    if ($client_status != 0) {
        print STDERR "ERROR: PI_ProcMode_TestClient returned $client_status\n";
        print STDERR "ERROR: For client-side mode [$client_mode],\n";
        print STDERR "ERROR: and server-side mode [$server_mode].\n";
        $status = 1;
    }

    my $server_status = $SV->WaitKill ($server->ProcessStopWaitInterval() + 30);

    if ($server_status != 0) {
        print STDERR "ERROR: PI_ProcMode_TestServer returned $server_status\n";
        print STDERR "ERROR: For client-side mode [$client_mode],\n";
        print STDERR "ERROR: and server-side mode [$server_mode].\n";
        $status = 1;
    }

    if (($server_status == 0) && ($client_status == 0)) {
          print STDERR "\n==== Test variant #$testid (of 9) passed!\n";
    }
    else {
        print STDERR "\n==== Test variant #$testid (of 9) failed!\n";
    }
}

if ($status == 0) {
    print STDERR "\n==== All 9 test variants were successful!\n";
}
else {
    print STDERR "\n==== One or more of the 9 test variants failed!\n";
}

exit $status;

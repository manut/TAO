eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

###############################################################################
use lib "$ENV{ACE_ROOT}/bin";
use PerlACE::TestTarget;

$status = 0;

my $debug_level = '0';
my $imr_debug_level = $debug_level;
my $servers_count = 3;
my $client_count = 2;
my $server_reply_delay = 5;
my $usage = 0;

# Ping interval in milliseconds
my $verification_interval_msecs = 1000;

if ($#ARGV >= 0) {
    for (my $i = 0; $i <= $#ARGV; $i++) {
	if ($ARGV[$i] eq '-debug') {
	    $debug_level = '10';
	    $imr_debug_level = '10';
	    $i++;
	}
	elsif ($ARGV[$i] eq "-server_reply_delay") {
	    $i++;
	    $server_reply_delay = $ARGV[$i];
	}
	elsif ($ARGV[$i] eq "-v") {
	    $i++;
	    $verification_interval_msecs = $ARGV[$i];
	}
	else {
	    $usage = 1;
	    usage();
	    exit 1;
	}
    }
}

my $tgt_num = 0;
my $imr = PerlACE::TestTarget::create_target (++$tgt_num) || die "Create target $tgt_num failed\n";
my $act = PerlACE::TestTarget::create_target (++$tgt_num) || die "Create target $tgt_num failed\n";
my $ti =  PerlACE::TestTarget::create_target (++$tgt_num) || die "Create target $tgt_num failed\n";
my @cli;

# Have list indices match client IDs (C1, C2) with first element of list not being used.
for(my $i = 0; $i <= $client_count; $i++) {
    push (@cli, PerlACE::TestTarget::create_target (++$tgt_num)) || die "Create target $tgt_num failed\n";
}

my $refstyle = "-ORBobjrefstyle URL";
my $obj_count = 1;
my $port = $imr->RandomPort();

my $forward_on_exception_arg = "-ORBForwardOnceOnTransient 1";

my $debug_arg = "-ORBDebugLevel $debug_level";
my $imr_debug_arg = "-ORBDebugLevel $imr_debug_level";
if ($imr_debug_level == 10) {
    $imr_debug_arg = $imr_debug_arg . " -ORBVerboseLogging 1 -ORBLogFile imr_loc.log ";
}

my $objprefix = "TestObject";

$imriorfile = "imr_locator.ior";
$actiorfile = "imr_activator.ior";

my $imr_imriorfile = $imr->LocalFile ($imriorfile);
my $act_imriorfile = $act->LocalFile ($imriorfile);
my $ti_imriorfile = $ti->LocalFile ($imriorfile);
my $act_actiorfile = $act->LocalFile ($actiorfile);

my $IMR = $imr->CreateProcess ("$ENV{TAO_ROOT}/orbsvcs/ImplRepo_Service/tao_imr_locator");
my $ACT = $act->CreateProcess ("$ENV{TAO_ROOT}/orbsvcs/ImplRepo_Service/tao_imr_activator");
my $TI  = $ti->CreateProcess ("$ENV{ACE_ROOT}/bin/tao_imr");

my @srviorfile;
my @srv_imriorfile;
my @srv_iorfile;
my @srv;
my @SRV;
my @srvstatusfile;
my @srv_statusfile;
my @obj;
my @srv_server_cmd;
# Have list indices match server IDs (S1, S2, S3) with first element of list not being used.
for(my $i = 0; $i <= $servers_count; $i++) {
    push (@srv, PerlACE::TestTarget::create_target (++$tgt_num)) || die "Create target $tgt_num failed\n";
    push (@obj, $objprefix. "_" . $i);
    push (@srviorfile,  $obj[$i] . ".ior");
    push (@srvstatusfile, $obj[$i] . ".status");
    push (@srv_imriorfile, $srv[$i]->LocalFile ($imriorfile));
    push (@srv_iorfile, $srv[$i]->LocalFile ($srviorfile[$i]));
    push (@srv_statusfile, $srv[$i]->LocalFile ($srvstatusfile[$i]));
    $srv[$i]->DeleteFile ($imriorfile);
    push (@SRV, $srv[$i]->CreateProcess ("server"));
    my $server_cmd = $SRV[$i]->Executable();
    push (@srv_server_cmd, $imr->LocalFile ($server_cmd));
}

for(my $i = 0; $i <= $client_count; $i++) {
    push (@CLI, $cli[$i]->CreateProcess ("client", "$debug_arg -k file://$srviorfile[1] -n $i $forward_on_exception_arg"));
}

sub cleanup_output {
    $imr->DeleteFile ($imriorfile);
    $act->DeleteFile ($imriorfile);
    $ti->DeleteFile ($imriorfile);
    $act->DeleteFile ($actiorfile);
    for (my $i = 1; $i <= $servers_count; $i++) {
	$srv[$i]->DeleteFile ($srviorfile[$i]);
	$srv[$i]->DeleteFile ($srvstatusfile[$i]);
    }
}

sub print_msg($)
{
    my $msg = shift;
    my $bar = "===============================================================================";
    print STDERR "\n\n$bar\n$msg\n$bar\n\n";
}

sub run_imr_util {
    my $cmd = shift;
    print "Running ImR utility with $cmd\n";
    $TI->Arguments ("-ORBInitRef ImplRepoService=file://$ti_imriorfile $cmd");
#    print ">>> " . $TI->CommandLine () . "\n";
    return $TI->SpawnWaitKill($ti->ProcessStartWaitInterval());
}

# Register a server with ImR to get its IOR, then register again so it can later be invoked.
# For the second registration the IOR of another server to invoke is passed.
sub register_server_with_activator {
    my $srv_id = shift;
    my $srv_to_invoke_id = shift;

    $srv_args =
	"$debug_arg -orbuseimr 1 $refstyle ".
	"$forward_on_exception_arg ".
	"-ORBInitRef ImplRepoService=file://$imr_imriorfile -n $srv_id";

    # First run to get its IOR.
    $SRV[$srv_id]->Arguments ($srv_args);
    print ">>> " . $SRV[$srv_id]->CommandLine () . "\n";
    $SRV[$srv_id]->Spawn ();
    if ($srv[$srv_id]->WaitForFileTimed ($srvstatusfile[$srv_id],
					 $srv[$srv_id]->ProcessStartWaitInterval() + $srv_reply_delay) == -1) {
        print STDERR "ERROR: cannot find file $srvstatusfile[$srv_id]\n";
        $IMR->Kill (); $IMR->TimedWait (1);
        return 1;
    }

    $srv_args = $srv_args . " -s file://$srviorfile[$srv_to_invoke_id]";

    run_imr_util("ior $obj[$srv_id] -f $srviorfile[$srv_id]");
    run_imr_util("shutdown $obj[$srv_id]");
    run_imr_util("update $obj[$srv_id] -c \"server $srv_args\"");
}

my $start_time = time();

cleanup_output ();

sub run_test
{
    print "Running test with $servers_count servers and $obj_count objects.\n";

    my $result = 0;

    ##### Start ImplRepo #####

    print_msg ("Start ImplRepo");

    $IMR->Arguments ("-o $imr_imriorfile $refstyle -orbendpoint iiop://:$port ".
		     "$forward_on_exception_arg ".
		     "-d 1 $imr_debug_arg ".
		     "-v $verification_interval_msecs");
    print ">>> " . $IMR->CommandLine () . "\n";
    $IMR_status = $IMR->Spawn ();

    if ($IMR_status != 0) {
        print STDERR "ERROR: ImplRepo Service returned $IMR_status\n";
        return 1;
    }
    if ($imr->WaitForFileTimed ($imriorfile, $imr->ProcessStartWaitInterval()) == -1) {
        print STDERR "ERROR: cannot find file <$imr_imriorfile>\n";
        $IMR->Kill (); $IMR->TimedWait (1);
        return 1;
    }
    if ($imr->GetFile ($imriorfile) == -1) {
        print STDERR "ERROR: cannot retrieve file <$imr_imriorfile>\n";
        $IMR->Kill (); $IMR->TimedWait (1);
        return 1;
    }
    if ($act->PutFile ($imriorfile) == -1) {
        print STDERR "ERROR: cannot set file <$act_imriorfile>\n";
        $IMR->Kill (); $IMR->TimedWait (1);
        return 1;
    }
    if ($ti->PutFile ($imriorfile) == -1) {
        print STDERR "ERROR: cannot set file <$ti_imriorfile>\n";
        $IMR->Kill (); $IMR->TimedWait (1);
        return 1;
    }
    for (my $i = 1; $i <= $servers_count; $i++) {
	if ($srv[$i]->PutFile ($imriorfile) == -1) {
	    print STDERR "ERROR: cannot set file <$srv_imriorfile>\n";
	    $IMR->Kill (); $IMR->TimedWait (1);
	    return 1;
	}
    }

    ##### Start Activator #####

    print_msg ("Start Activator");

    $ACT->Arguments ("$debug_arg -d 1 -o $act_actiorfile -ORBInitRef ImplRepoService=file://$act_imriorfile");
    print ">>> " . $ACT->CommandLine () . "\n";

    $ACT_status = $ACT->Spawn ();
    if ($ACT_status != 0) {
	print STDERR "ERROR: ImR Activator returned $ACT_status\n";
	return 1;
    }
    if ($act->WaitForFileTimed ($actiorfile,$act->ProcessStartWaitInterval()) == -1) {
	print STDERR "ERROR: cannot find file <$act_imriorfile>\n";
	$ACT->Kill (); $ACT->TimedWait (1);
	$IMR->Kill (); $IMR->TimedWait (1);
	return 1;
    }

    ##### Start S3 #####

    print_msg ("Start S3");

    $SRV[3]->Arguments ("$debug_arg -orbuseimr 1 $refstyle -ORBInitRef ImplRepoService=file://$imr_imriorfile ".
			    "-d $server_reply_delay -n 3");
    print ">>> " . $SRV[3]->CommandLine () . "\n";
    $SRV[3]-> Spawn();
    if ($srv[3]->WaitForFileTimed ($srvstatusfile[3], $srv[3]->ProcessStartWaitInterval()) == -1) {
        print STDERR "ERROR: cannot find file $srvstatusfile[3]\n";
        $IMR->Kill (); $IMR->TimedWait (1);
        return 1;
    }
    # Get its IOR so S2 can use to invoke S3
    run_imr_util("ior $obj[3] -f $srviorfile[3]");

    ##### Register S2 with ImR using Activator #####

    print_msg ("Register S2 with ImR to start on demand");

    register_server_with_activator(2, 3);

    ##### Register S1 with ImR using Activator #####

    print_msg ("Register S1 with ImR to start on demand");

    register_server_with_activator(1, 2);

    ##### C1 invokes S1 #####

    print_msg ("C1 invokes S1");

    print ">>> " . $CLI[1]->CommandLine () . "\n";
    $CLI_status = $CLI[1]->Spawn ();
    if ($CLI_status != 0) {
	print STDERR "ERROR: client 1 returned $CLI_status\n";
	return 1;
    }

    ##### C2 invokes S1 in parallel with C1 after ping interval #####

    print_msg ("C2 invokes S1 in parallel with C1 after ping interval");

    # Let ping interval pass to ensure another ping will be done.
    sleep ($verification_interval_msecs / 1000 + 1);

    print ">>> " . $CLI[2]->CommandLine () . "\n";
    $CLI_status = $CLI[2]->Spawn ();
    if ($CLI_status != 0) {
	print STDERR "ERROR: client 2 returned $CLI_status\n";
	return 1;
    }

    ##### Wait for clients to terminate #####
    print_msg ("Wait for clients to terminate");
    for (my $i = 1; $i <= $client_count; $i++) {
	if ($CLI[$i]->WaitKill ($cli[$i]->ProcessStopWaitInterval () + $server_reply_delay + 60) == -1) {
	    print STDERR "ERROR: client $i not terminated correctly\n";
	    $status = 1;
	}
    }

    print_msg ("Shutting down");

    if ($srv[1]->WaitForFileTimed ($srvstatusfile[1], $srv[1]->ProcessStartWaitInterval() + $server_reply_delay) == -1) {
        print STDERR "ERROR: cannot find file $srvstatusfile[1]\n";
        $IMR->Kill (); $IMR->TimedWait (1);
        $status = 1;
    }

    ##### Shutdown servers #####
    for (my $i = 1; $i <= $servers_count; $i++ ) {
        # Shutting down any server object within the server will shutdown the whole server
        run_imr_util ("shutdown $obj[$i]");
	if ($SRV[$i]->WaitKill ($srv[$i]->ProcessStopWaitInterval ()) == -1) {
	    print STDERR "ERROR: Server $i not terminated correctly\n";
	    $status = 1;
	}
    }

    ##### Shutdown activator #####
    my $ACT_status = $ACT->TerminateWaitKill ($act->ProcessStopWaitInterval());
    if ($ACT_status != 0) {
	print STDERR "ERROR: IMR Activator returned $ACT_status\n";
	$status = 1;
    }

    ##### Shutdown locator #####
    my $IMR_status = $IMR->TerminateWaitKill ($imr->ProcessStopWaitInterval());
    if ($IMR_status != 0) {
        print STDERR "ERROR: IMR returned $IMR_status\n";
        $status = 1;
    }

    my $test_time = time() - $start_time;
    print "\nFinished. The test took $test_time seconds.\n";

    return $status;
}

END
{
    if (! $usage) {
	cleanup_output ();
    }

}

sub usage() {
    print "Usage: run_test.pl ".
	"[-server_reply_delay <request-seconds=$server_reply_delay>] ".
	"[-v <verification-interval-milliseconds=$verification-interval>]\n"
}

###############################################################################
###############################################################################

my $ret = run_test();

exit $ret;

eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

unshift @INC, '../../../bin';
require ACEutils;

$svfile = "server.ior";
$SV = Process::Create ($EXEPREFIX."server$EXE_EXT ",
                       " -o $svfile");

if (ACE::waitforfile_timed ($svfile, 5) == -1) {
  print STDERR "ERROR: cannot find file <$iorfile>\n";
  $SV->Kill (); $SV->TimedWait (1);
  exit 1;
}

$gwfile = "gateway.ior";
$GW = Process::Create ($EXEPREFIX."gateway$EXE_EXT ",
                       " -k file://$svfile"
		       . " -o $gwfile");

if (ACE::waitforfile_timed ($gwfile, 5) == -1) {
  print STDERR "ERROR: cannot find file <$iorfile>\n";
  $SV->Kill (); $SV->TimedWait (1);
  exit 1;
}

$CL = Process::Create ($EXEPREFIX."client$EXE_EXT ",
		       " -k file://$gwfile -x"
		       . " -i 100");

$client = $CL->TimedWait (60);
if ($client == -1) {
  print STDERR "ERROR: client timedout\n";
  $CL->Kill (); $CL->TimedWait (1);
}

$server = $SV->TimedWait (5);
if ($server == -1) {
  print STDERR "ERROR: server timedout\n";
  $SV->Kill (); $SV->TimedWait (1);
}

$gateway = $GW->TimedWait (5);
if ($server == -1) {
  print STDERR "ERROR: server timedout\n";
  $SV->Kill (); $SV->TimedWait (1);
}

unlink $iorfile;

if ($server != 0
    || $gateway != 0
    || $client != 0) {
  print STDERR "ERROR: test failed <$server,$gateway,$client>\n";
  exit 1;
}

exit 0;

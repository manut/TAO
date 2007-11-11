eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

use lib "$ENV{ACE_ROOT}/bin";
use PerlACE::Run_Test;

my $class = (PerlACE::is_vxworks_test() ? 'PerlACE::ProcessVX' :
                                          'PerlACE::Process');
$T = new $class ("IORTest");

$test = $T->SpawnWaitKill ($PerlACE::wait_interval_for_process_creation);

if ($test != 0) {
    print STDERR "ERROR: test returned $test\n";
    exit 1;
}

exit 0;

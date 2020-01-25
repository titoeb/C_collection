AUTOMAKE_OPTIONS = dejagnu
bin_PROGRAMS = s12
AM_CPPFLAGS =
LDADD =
CLEANFILES = *~
DISTCLEANFILES = .deps/*.P
EXTRA_DIST = test
AM_CFLAGS = --coverage -g -std=c1x

RUNTESTDEFAULTFLAGS = --tool s12 FREQTEST=`pwd`/s12 --srcdir $$srcdir/test --all

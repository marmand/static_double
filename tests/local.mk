LDADD  =
LDADD += ${builddir}/_googletest/googlemock/gtest/libgtest_main.a
LDADD += ${builddir}/_googletest/googlemock/gtest/libgtest.a
LDADD += ${PTHREAD_LIBS}
AM_CXXFLAGS = ${PTHREAD_CFLAGS}
AM_CPPFLAGS = -I ${builddir}/googletest/googletest/include

${builddir}/googletest:
	${GIT} clone https://github.com/google/googletest.git ${builddir}/googletest

${builddir}/_googletest/Makefile: ${builddir}/googletest
	${MKDIR_P} ${builddir}/_googletest
	cd ${builddir}/_googletest && ${CMAKE} ${builddir}/../googletest

${builddir}/_googletest/googlemock/gtest/libgtest.a: ${builddir}/_googletest/Makefile
	${CMAKE} --build ${builddir}/_googletest -- gtest

${builddir}/_googletest/googlemock/gtest/libgtest_main.a: ${builddir}/_googletest/Makefile
	${CMAKE} --build ${builddir}/_googletest -- gtest_main

clean-local: clean-local-check
.PHONY: clean-local-check
clean-local-check:
	-rm -rf _googletest
	-rm -rf googletest

# Defines that we'll compile only c++ sources
AM_DEFAULT_SOURCE_EXT = .cc

check_PROGRAMS += %reldir%/abs
%reldir%/abs.$(OBJEXT): ${builddir}/googletest
check_PROGRAMS += %reldir%/add
%reldir%/add.$(OBJEXT): ${builddir}/googletest
check_PROGRAMS += %reldir%/convert
%reldir%/convert.$(OBJEXT): ${builddir}/googletest
check_PROGRAMS += %reldir%/digits
%reldir%/digits.$(OBJEXT): ${builddir}/googletest
check_PROGRAMS += %reldir%/div
%reldir%/div.$(OBJEXT): ${builddir}/googletest
check_PROGRAMS += %reldir%/double
%reldir%/double.$(OBJEXT): ${builddir}/googletest
check_PROGRAMS += %reldir%/eq
%reldir%/eq.$(OBJEXT): ${builddir}/googletest
check_PROGRAMS += %reldir%/max
%reldir%/max.$(OBJEXT): ${builddir}/googletest
check_PROGRAMS += %reldir%/min
%reldir%/min.$(OBJEXT): ${builddir}/googletest
check_PROGRAMS += %reldir%/mod
%reldir%/mod.$(OBJEXT): ${builddir}/googletest
check_PROGRAMS += %reldir%/mul
%reldir%/mul.$(OBJEXT): ${builddir}/googletest
check_PROGRAMS += %reldir%/pow
%reldir%/pow.$(OBJEXT): ${builddir}/googletest
check_PROGRAMS += %reldir%/shifted
%reldir%/shifted.$(OBJEXT): ${builddir}/googletest
check_PROGRAMS += %reldir%/sub
%reldir%/sub.$(OBJEXT): ${builddir}/googletest

TESTS = $(check_PROGRAMS)

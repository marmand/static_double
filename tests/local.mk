LDADD  =
LDADD += ${builddir}/_googletest/googlemock/gtest/libgtest_main.a
LDADD += ${builddir}/_googletest/googlemock/gtest/libgtest.a
LDADD += ${PTHREAD_LIBS}
AM_CXXFLAGS = ${PTHREAD_CFLAGS}

${builddir}/googletest:
	${GIT} clone https://github.com/google/googletest.git ${builddir}/googletest

${builddir}/_googletest/Makefile: ${builddir}/googletest
	${MKDIR_P} ${builddir}/_googletest
	cd ${builddir}/_googletest && ${CMAKE} ${builddir}/../googletest

${builddir}/_googletest/googlemock/gtest/libgtest.a: ${builddir}/_googletest/Makefile
	${CMAKE} --build ${builddir}/_googletest -- gtest

${builddir}/_googletest/googlemock/gtest/libgtest_main.a: ${builddir}/_googletest/Makefile
	${CMAKE} --build ${builddir}/_googletest -- gtest_main

# Defines that we'll compile only c++ sources
AM_DEFAULT_SOURCE_EXT = .cc

check_PROGRAMS += %reldir%/abs
check_PROGRAMS += %reldir%/add
check_PROGRAMS += %reldir%/convert
check_PROGRAMS += %reldir%/digits
check_PROGRAMS += %reldir%/div
check_PROGRAMS += %reldir%/double
check_PROGRAMS += %reldir%/eq
check_PROGRAMS += %reldir%/max
check_PROGRAMS += %reldir%/min
check_PROGRAMS += %reldir%/mod
check_PROGRAMS += %reldir%/mul
check_PROGRAMS += %reldir%/pow
check_PROGRAMS += %reldir%/shifted
check_PROGRAMS += %reldir%/sub

TESTS = $(check_PROGRAMS)

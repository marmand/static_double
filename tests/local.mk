AM_LDFLAGS = ${GTEST_LIBS}
AM_CXXFLAGS = ${PTHREAD_CFLAGS}

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
check_PROGRAMS += %reldir%/shifted
check_PROGRAMS += %reldir%/sub

TESTS = $(check_PROGRAMS)

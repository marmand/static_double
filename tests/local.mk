AM_LDFLAGS = ${GTEST_LIBS}
AM_CXXFLAGS = ${PTHREAD_CFLAGS}

check_PROGRAMS =        \
digits

digits_SOURCES = %reldir%/digits.cc

TESTS = $(check_PROGRAMS)

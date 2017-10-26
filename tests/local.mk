AM_LDFLAGS = ${GTEST_LIBS}
AM_CXXFLAGS = ${PTHREAD_CFLAGS}

check_PROGRAMS =        \
digits                  \
double                  \
eq

digits_SOURCES = %reldir%/digits.cc
double_SOURCES = %reldir%/double.cc
eq_SOURCES = %reldir%/eq.cc

TESTS = $(check_PROGRAMS)

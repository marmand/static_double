AM_LDFLAGS = ${GTEST_LIBS}
AM_CXXFLAGS = ${PTHREAD_CFLAGS}

check_PROGRAMS =        \
abs                     \
convert                 \
digits                  \
double                  \
eq                      \
max                     \
mod                     \
shifted

abs_SOURCES = %reldir%/abs.cc
convert_SOURCES = %reldir%/convert.cc
digits_SOURCES = %reldir%/digits.cc
double_SOURCES = %reldir%/double.cc
eq_SOURCES = %reldir%/eq.cc
max_SOURCES = %reldir%/max.cc
mod_SOURCES = %reldir%/mod.cc
shifted_SOURCES = %reldir%/shifted.cc

TESTS = $(check_PROGRAMS)

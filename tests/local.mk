AM_LDFLAGS = ${GTEST_LIBS}
AM_CXXFLAGS = ${PTHREAD_CFLAGS}

check_PROGRAMS =        \
abs                     \
add                     \
convert                 \
digits                  \
double                  \
eq                      \
max                     \
min                     \
mod                     \
shifted

abs_SOURCES = %reldir%/abs.cc
add_SOURCES = %reldir%/add.cc
convert_SOURCES = %reldir%/convert.cc
digits_SOURCES = %reldir%/digits.cc
double_SOURCES = %reldir%/double.cc
eq_SOURCES = %reldir%/eq.cc
max_SOURCES = %reldir%/max.cc
min_SOURCES = %reldir%/min.cc
mod_SOURCES = %reldir%/mod.cc
shifted_SOURCES = %reldir%/shifted.cc

TESTS = $(check_PROGRAMS)

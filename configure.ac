#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([static_double], [0.0.0], [armand@leclercq.site])
AC_CONFIG_SRCDIR([pow.hh])
AC_CONFIG_HEADERS([config.hh])
AC_CONFIG_FILES([Makefile])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([1.14 foreign -Wall -Werror parallel-tests
                  subdir-objects color-tests
                  dist-bzip2 dist-xz])
AM_SILENT_RULES([yes])

# Checks for programs.
AC_LANG_PUSH([C++])
AC_PROG_CXX
AM_PROG_AR

# Checks for libraries.
AX_PTHREAD()
gtest_save_CXXFLAGS=$CXXFLAGS
gtest_save_LIBS=$LIBS
CXXFLAGS="$PTHREAD_CFLAGS $CXXFLAGS"
LIBS="-lgtest_main -lgtest $LIBS"
AC_LINK_IFELSE([AC_LANG_SOURCE(
[[
#include <gtest/gtest.h>

TEST(Principal, basic)
{
  ASSERT_TRUE(true);
}
]])]
, [AC_SUBST([GTEST_LIBS], ["-lgtest_main -lgtest"])]
, [AC_MSG_FAILURE([Unable to link with gtest libraries])])
CXXFLAGS=$gtest_save_CXXFLAGS
LIBS=$gtest_save_LIBS

# Checks for header files.
AC_CHECK_HEADER([gtest/gtest.h],
                [AC_DEFINE([HAVE_GTEST], [1], [Define to 1 if you have <gtest/gtest.h>.])],
                [AC_MSG_ERROR([Missing gtest.h, install google test library])])

# Checks for typedefs, structures, and compiler characteristics.
AX_CXX_COMPILE_STDCXX_11([noext])
AX_APPEND_COMPILE_FLAGS([-Wall],                    [CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wextra],                  [CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-Werror],                  [CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wcast-align],             [CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wcast-qual],              [CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wdocumentation],          [CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wformat],                 [CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wmissing-declarations],   [CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wno-parentheses],         [CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wnoexcept],               [CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-pedantic],                [CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-pedantic-errors],         [CXXFLAGS])

# Checks for library functions.
AC_CHECK_FUNCS([pow])

# Configuration macros
# FIXME: Replace that macro with something template
AC_DEFINE([DIVISION_PRECISION], [5], [Division precision])

AC_OUTPUT

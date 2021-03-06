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

AX_PTHREAD()
# For testing purpose
AC_PROG_MKDIR_P
AC_CHECK_PROGS([GIT], [git], [:])
if test "$GIT" = :
then
  AC_MSG_ERROR([This package needs git])
fi

AC_CHECK_PROGS([CMAKE], [cmake], [:])
if test "$CMAKE" = :
then
  AC_MSG_ERROR([This package needs cmake])
fi

# Checks for typedefs, structures, and compiler characteristics.
AX_CXX_COMPILE_STDCXX_11([noext])
AX_APPEND_COMPILE_FLAGS([-Wall],                    [CXXFLAGS])
# AX_APPEND_COMPILE_FLAGS([-Weffc++],                 [CXXFLAGS])
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

dnl Process this file with autoconf to produce a configure script.
AC_INIT([clutils],[0.0])
AC_CONFIG_MACRO_DIR([m4])
AM_SILENT_RULES([yes])
AM_INIT_AUTOMAKE([1.14 foreign subdir-objects])

dnl AC_CONFIG_SUBDIRS(src)

dnl
AC_CANONICAL_HOST

AC_LANG(C++)

dnl Checks for programs.
AC_PROG_LIBTOOL
AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX
AC_LIBTOOL_DLOPEN
AC_PROG_LIBTOOL
AC_PROG_INSTALL
dnl AC_PATH_PROG(AR, ar, :)

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS(unistd.h)
AC_CHECK_HEADERS(hash_map)
AC_CHECK_HEADERS(ext/hash_map)

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_MODE_T
AC_STRUCT_TM

AC_CHECK_SIZEOF(long int)
AC_CHECK_SIZEOF(long long int)

dnl CPPFLAGS="$CPPFLAGS -DSIZEOF_LONG=$ac_cv_sizeof_long"
dnl CPPFLAGS="$CPPFLAGS -DSIZEOF_LONG=$ac_cv_sizeof_long_long"

dnl Checks for library functions.
AC_FUNC_MEMCMP
AC_TYPE_SIGNAL
AC_CHECK_FUNCS(mkdir strdup)

LDFLAGS="$LDFLAGS -ldl -lltdl"	
CXXFLAGS="$CXXFLAGS -std=c++11 -Wall"

AM_CONFIG_HEADER(src/clutils-config.h)

AC_OUTPUT(Makefile \
	documentation/Makefile \
	src/Makefile \
	test/Makefile \
	test/modules/Makefile )

echo "Ready to build"


#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([lcrq],[0.2.1],[bugs@librecast.net])
AC_SUBST(PACKAGE_ABIVERS, 0.0)
AC_COPYRIGHT(Copyright (c) 2022-2024 Brett Sheffield <bacs@librecast.net>
See COPYING for license details.
)
AC_CONFIG_SRCDIR([src/])
AC_CONFIG_HEADERS([src/config.h])

# Check arch
AC_CANONICAL_TARGET
AC_SUBST([CPU],[$target_cpu])

# Enable features.
AC_ARG_ENABLE([native], AS_HELP_STRING([--enable-native], [use native build (default is no)]))
AS_IF([test "x$enable_native" = "xyes"], [
       AC_DEFINE([USE_NATIVE],[1],[Use native build])
       AC_SUBST([NATIVE], ["1"])
])

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S
AC_CHECK_PROG([testrunner], [lctest], [lctest], [maketest])
AC_SUBST([TESTRUNNER],[$testrunner])
AC_CHECK_PROGS([FALSE], [false], [/usr/bin/env false])

# Checks for libraries.
AC_SEARCH_LIBS([clock_gettime], [rt])
AC_CHECK_LIB([dl], [dlsym], AC_SUBST([LIBDL], ["-ldl"]))
AC_SEARCH_LIBS([arc4random_uniform], [libbsd])
AC_SEARCH_LIBS([sem_post], [pthread])
AC_ARG_WITH(sodium,
	    AS_HELP_STRING([--with-sodium], [use libsodium for encryption and \
			   hashing (default is yes, if available)]),
            [AC_SUBST([HAVE_LIBSODIUM], [])],
            [with_sodium=check])
        LIBSODIUM=
          AS_IF([test "x$with_sodium" != xno],
            [AC_CHECK_LIB([sodium], [sodium_init],
              [AC_SUBST([LIBSODIUM], ["-lsodium"])
               AC_SUBST([HAVE_LIBSODIUM], ["HAVE_LIBSODIUM := 1"])
               AC_DEFINE([HAVE_LIBSODIUM], [1],
                         [Define if you have libsodium])
              ],
              [if test "x$with_sodium" != xcheck; then
                 AC_MSG_FAILURE([--with-sodium was given, but libsodium not found])
               fi
              ], -lsodium)])


# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h fcntl.h stdint.h sys/param.h sys/socket.h
		  sys/time.h unistd.h],[],AC_MSG_ERROR([required header file missing]))
AC_CHECK_HEADERS([immintrin.h pmmintrin.h], [], [
		  AS_IF([test "x$enable_simd" = "xyes"], [
			 AC_MSG_FAILURE([--enable-simd was given, but required headers are missing])])
		  ])
AC_CHECK_HEADERS([endian.h sys/endian.h libkern/OSByteOrder.h sys/random.h sys/ioctl.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_BIGENDIAN([AC_DEFINE([WORDS_BIGENDIAN],[1],[Define WORDS_BIGENDIAN to 1 if your processor stores words with the most significant byte first])
		AC_SUBST([HAVE_BIGENDIAN],["#define HAVE_BIGENDIAN 1"])],
               [AC_SUBST([HAVE_BIGENDIAN],["/* #undef HAVE_BIGENDIAN */"])])
AC_C_INLINE
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_TYPE_UINT8_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_MMAP
AC_FUNC_REALLOC
AC_CHECK_FUNCS([arc4random_uniform clock_gettime floor getrandom memset munmap])

# Required only for example programs
AC_TYPE_MODE_T
AC_CHECK_FUNCS([strdup strtoul strtoull],[],
		AC_MSG_WARN([function required by example programs not found]))

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 doc/Makefile
                 examples/Makefile
                 test/Makefile
		 include/lcrq.h])
AC_OUTPUT

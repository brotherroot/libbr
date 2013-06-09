/*
 * @file  config.hpp
 * @brief 用于配置libbr
 */
#pragma once

#ifndef NDEBUG
#	if defined(ANDROID_NDK)
#		include <android/log.h>
#		define BR_ASSERT( x ) if ( !(x)) { __android_log_assert( "assert", "grinliz", "ASSERT in '%s' at %d.", __FILE__, __LINE__ ); }
#	else
#		include <assert.h>
#		define BR_ASSERT      assert
#	endif
#else
#	define BR_ASSERT( x )     { }
#endif

#if __cplusplus >= 201103L
#	define USING_STD_CPP11
#else
#	define USING_STD_CPP03
#endif

#if defined(ANDROID_NDK)
#	define HEADER_ASSERT   <assert.h>
#	define HEADER_CTYPE    <ctype.h>
#	define HEADER_ERRNO    <errno.h>
#	define HEADER_FLOAT    <float.h>
#	define HEADER_ISO646   <iso646.h>
#	define HEADER_LIMITS   <limits.h>
#	define HEADER_LOCALE   <locale.h>
#	define HEADER_MATH     <math.h>
#	define HEADER_SETJUMP  <setjump.h>
#	define HEADER_SIGNAL   <signal.h>
#	define HEADER_STDARG   <stdarg.h>
#	define HEADER_STDDEF   <stddef.h>
#	define HEADER_STDIO    <stdio.h>
#	define HEADER_STDLIB   <stdlib.h>
#	define HEADER_STRING   <string.h>
#	define HEADER_TIME     <time.h>
#	define HEADER_WCHAR    <wchar.h>
#	define HEADER_WCHTYPE  <wctype.h>
#	ifdef USING_STD_CPP11
#		define HEADER_FENV     <fenv.h>
#		define HEADER_INTTYPES <inttypes.h>
#		define HEADER_STDBOOL  <stdbool.h>
#		define HEADER_STDINT   <stdint.h>
#		define HEADER_TGMATH   <tgmath.h>
#		define HEADER_UCHAR    <uchar.h>
#	endif
#else
#	define HEADER_ASSERT   <cassert>
#   define HEADER_CTYPE    <cctype>
#	define HEADER_ERRNO    <cerrno>
#	define HEADER_FLOAT    <cfloat>
#	define HEADER_ISO646   <ciso646>
#	define HEADER_LIMITS   <climits>
#	define HEADER_LOCALE   <clocale>
#	define HEADER_MATH     <cmath>
#	define HEADER_SETJUMP  <csetjump>
#	define HEADER_SIGNAL   <csignal>
#	define HEADER_STDARG   <cstdarg>
#	define HEADER_STDDEF   <cstddef>
#	define HEADER_STDIO    <cstdio>
#	define HEADER_STDLIB   <cstdlib>
#	define HEADER_STRING   <cstring>
#	define HEADER_TIME     <ctime>
#	define HEADER_WCHAR    <cwchar>
#	define HEADER_WCHTYPE  <cwctype>
#	if defined(USING_STD_CPP11)
#		define HEADER_FENV     <cfenv>
#		define HEADER_INTTYPES <cinttypes>
#		define HEADER_STDBOOL  <cstdbool>
#		define HEADER_STDINT   <cstdint>
#		define HEADER_TGMATH   <ctgmath>
#		define HEADER_UCHAR    <cuchar>
#	endif
#endif

#if defined(USING_STD_CPP11)
#	define BR_NULLPTR nullptr
#else
#   include HEADER_STDDEF
#	define  BR_NULLPTR NULL
#endif

#if defined(_MSC_VER) && (_MSC_VER >= 1400 )
// Microsoft visual studio, version 2005 and higher.
/*int _snprintf_s(
	char *buffer,
	size_t sizeOfBuffer,
	size_t count,
	const char *format [,
		argument] ...
);*/
#include HEADER_STDARG
#include HEADER_STDIO
inline int BR_SNPRINTF( char * buffer, size_t size, char const * format, ... ) {
	va_list va;
	va_start( va, format );
	int result = vsnprintf_s( buffer, size, _TRUNCATE, format, va );
	va_end( va );
	return result;
}
#define BR_SSCANF   sscanf_s
#else
// GCC version 3 and higher
//#warning( "Using sn* functions." )
#define BR_SNPRINTF snprintf
#define BR_SSCANF   sscanf
#endif

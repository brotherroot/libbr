/*
 * @file  include/config.hpp
 * @brief 用于配置libbr
 */
#pragma once

#include <boost/config.hpp>

#ifndef NDEBUG
#	define BR_ASSERT          assert
#else
#	define BR_ASSERT( x )     { }
#endif // NDEBUG

#define HEADER_ASSERT   <cassert>
#define HEADER_CTYPE    <cctype>
#define HEADER_ERRNO    <cerrno>
#define HEADER_FLOAT    <cfloat>
#define HEADER_ISO646   <ciso646>
#define HEADER_LIMITS   <climits>
#define HEADER_LOCALE   <clocale>
#define HEADER_MATH     <cmath>
#define HEADER_SETJUMP  <csetjump>
#define HEADER_SIGNAL   <csignal>
#define HEADER_STDARG   <cstdarg>
#define HEADER_STDDEF   <cstddef>
#define HEADER_STDIO    <cstdio>
#define HEADER_STDLIB   <cstdlib>
#define HEADER_STRING   <cstring>
#define HEADER_TIME     <ctime>
#define HEADER_WCHAR    <cwchar>
#define HEADER_WCHTYPE  <cwctype>

#ifdef BOOST_NO_FENV_H
#	define HEADER_FENV     <boost/detail/fenv.hpp>
#else
#	define HEADER_FENV     <cfenv>
#endif // BOOST_NO_FENV_H

#ifdef BOOST_HAS_STDINT_H
#	define HEADER_STDINT   <cstdint>
#else
#	define HEADER_STDINT     <boost/cstdint.hpp>
#endif // BOOST_HAS_STDINT_H

#define HEADER_INTTYPES <cinttypes>
#define HEADER_STDBOOL  <cstdbool>
#define HEADER_TGMATH   <ctgmath>
#define HEADER_UCHAR    <cuchar>

#ifdef BOOST_NO_CXX11_NULLPTR
#define BR_NULLPTR NULL
#else
#define BR_NULLPTR nullptr
#endif // USING_STD_CPP11

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
#define BR_HAS_RVALUE_REFERENCES
#endif // BOOST_NO_CXX11_RVALUE_REFERENCES

#ifndef BOOST_NO_CXX11_DECLTYPE
#define BR_HAS_DECLTYPE
#endif // BOOST_NO_CXX11_DECLTYPE

#define BR_CONSTEXPR              BOOST_CONSTEXPR
#define BR_CONSTEXPR_OR_CONST     BOOST_CONSTEXPR_OR_CONST
#define BR_STATIC_CONSTEXPR       BOOST_STATIC_CONSTEXPR

#define HEADER_TYPE_TRAITS <boost/type_traits.hpp>

#define BR_GET_SIZE( Tp, n ) sizeof(Tp) * (n)

#define BR_SELFTYPE_SERIES( type_name ) \
typedef type_name       SelfType;       \
typedef SelfType const  CSelfType;      \
typedef SelfType  &     SelfRefType;    \
typedef CSelfType &     CSelfRefType;

#define BR_VALTYPE_SERIES( type_name ) \
typedef type_name       ValType;       \
typedef ValType const   CValType;      \
typedef ValType  &      ValRefType;    \
typedef CValType &      CValRefType;
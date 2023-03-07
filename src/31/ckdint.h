/**
 * @file
 * @author Kamil Cukrowski <kamilcukrowski@gmail.com>
 * @date 2021-06-19
 * @copyright 2022 Kamil Cukrowski <kamilcukrowski@gmail.com>
 * SPDX-FileCopyrightText: 2022 Kamil Cukrowski <kamilcukrowski@gmail.com>
 * SPDX-License-Identifier: MIT
 */
// Header [[[
#ifndef CKDINT_H_
#define CKDINT_H_

#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifndef _ckd_static
#ifdef CKD_COVERAGE
#define _ckd_static  static __attribute__((__noinline__)) __attribute__((__used__))
#else
#define _ckd_static  static inline
#endif
#endif
// _ckd_fchpnt - Function returns value and changes pointer.
// _ckd_fconst - Function only returns value.
#if __GNUC__
#define _ckd_fconst     _ckd_static __attribute__((__warn_unused_result__)) __attribute__((__const__))
#if __GNUC__ >= 10
#define _ckd_fchpnt(x)  _ckd_static __attribute__((__warn_unused_result__)) __attribute__((__access__(__write_only__, x)))
#else
#define _ckd_fchpnt(x)  _ckd_static __attribute__((__warn_unused_result__))
#endif
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ > 20230000L
#define _ckd_fconst     _ckd_static [[__nodiscard__]]
#define _ckd_fchpnt(x)  _ckd_static [[__nodiscard__]]
#else
#define _ckd_fconst     _ckd_static
#define _ckd_fchpnt(x)  _ckd_static
#endif

#define CKD_VERSION_DESCRIBE  v0.1.3-3-ge83f6dd
#define CKD_VERSION           0x103

// ]]]
// Declare checked integer types [[[
/// @brief A checked integer type for storing value of type char.
typedef struct {
	/// @brief The stored value.
	char _ckd_Value;
	/// @brief The overflow flag.
	bool _ckd_Overflow;
} ckd_char_t;
/// @brief A checked integer type for storing value of type signed char.
typedef struct {
	/// @brief The stored value.
	signed char _ckd_Value;
	/// @brief The overflow flag.
	bool _ckd_Overflow;
} ckd_schar_t;
/// @brief A checked integer type for storing value of type unsigned char.
typedef struct {
	/// @brief The stored value.
	unsigned char _ckd_Value;
	/// @brief The overflow flag.
	bool _ckd_Overflow;
} ckd_uchar_t;
/// @brief A checked integer type for storing value of type short.
typedef struct {
	/// @brief The stored value.
	short _ckd_Value;
	/// @brief The overflow flag.
	bool _ckd_Overflow;
} ckd_shrt_t;
/// @brief A checked integer type for storing value of type unsigned short.
typedef struct {
	/// @brief The stored value.
	unsigned short _ckd_Value;
	/// @brief The overflow flag.
	bool _ckd_Overflow;
} ckd_ushrt_t;
/// @brief A checked integer type for storing value of type int.
typedef struct {
	/// @brief The stored value.
	int _ckd_Value;
	/// @brief The overflow flag.
	bool _ckd_Overflow;
} ckd_int_t;
/// @brief A checked integer type for storing value of type unsigned int.
typedef struct {
	/// @brief The stored value.
	unsigned int _ckd_Value;
	/// @brief The overflow flag.
	bool _ckd_Overflow;
} ckd_uint_t;
/// @brief A checked integer type for storing value of type long.
typedef struct {
	/// @brief The stored value.
	long _ckd_Value;
	/// @brief The overflow flag.
	bool _ckd_Overflow;
} ckd_long_t;
/// @brief A checked integer type for storing value of type unsigned long.
typedef struct {
	/// @brief The stored value.
	unsigned long _ckd_Value;
	/// @brief The overflow flag.
	bool _ckd_Overflow;
} ckd_ulong_t;
/// @brief A checked integer type for storing value of type long long.
typedef struct {
	/// @brief The stored value.
	long long _ckd_Value;
	/// @brief The overflow flag.
	bool _ckd_Overflow;
} ckd_llong_t;
/// @brief A checked integer type for storing value of type unsigned long long.
typedef struct {
	/// @brief The stored value.
	unsigned long long _ckd_Value;
	/// @brief The overflow flag.
	bool _ckd_Overflow;
} ckd_ullong_t;
/// @brief A checked integer type for storing value of type __int128.
typedef struct {
	/// @brief The stored value.
	__int128 _ckd_Value;
	/// @brief The overflow flag.
	bool _ckd_Overflow;
} ckd_int128_t;
/// @brief A checked integer type for storing value of type unsigned __int128.
typedef struct {
	/// @brief The stored value.
	unsigned __int128 _ckd_Value;
	/// @brief The overflow flag.
	bool _ckd_Overflow;
} ckd_uint128_t;
// ]]]
// Standard integer types aliases [[[

/**
 * @define ckd_intmax_t
 * @brief Check integer type ckd_intmax_t is an alias to one of ckd_*_t basic types.
 */
#if defined(INTMAX_MAX) && INTMAX_MAX == SCHAR_MAX
#define ckd_intmax_t  ckd_schar_t
#elif defined(INTMAX_MAX) && INTMAX_MAX == SHRT_MAX
#define ckd_intmax_t  ckd_shrt_t
#elif defined(INTMAX_MAX) && INTMAX_MAX == INT_MAX
#define ckd_intmax_t  ckd_int_t
#elif defined(INTMAX_MAX) && INTMAX_MAX == LONG_MAX
#define ckd_intmax_t  ckd_long_t
#elif defined(INTMAX_MAX) && INTMAX_MAX == LLONG_MAX
#define ckd_intmax_t  ckd_llong_t
#endif
/**
 * @define ckd_uintmax_t
 * @brief Check integer type ckd_uintmax_t is an alias to one of ckd_*_t basic types.
 */
#if defined(UINTMAX_MAX) && UINTMAX_MAX == UCHAR_MAX
#define ckd_uintmax_t  ckd_uchar_t
#elif defined(UINTMAX_MAX) && UINTMAX_MAX == USHRT_MAX
#define ckd_uintmax_t  ckd_ushrt_t
#elif defined(UINTMAX_MAX) && UINTMAX_MAX == UINT_MAX
#define ckd_uintmax_t  ckd_uint_t
#elif defined(UINTMAX_MAX) && UINTMAX_MAX == ULONG_MAX
#define ckd_uintmax_t  ckd_ulong_t
#elif defined(UINTMAX_MAX) && UINTMAX_MAX == ULLONG_MAX
#define ckd_uintmax_t  ckd_ullong_t
#endif
/**
 * @define ckd_size_t
 * @brief Check integer type ckd_size_t is an alias to one of ckd_*_t basic types.
 */
#if defined(SIZE_MAX) && SIZE_MAX == UCHAR_MAX
#define ckd_size_t  ckd_uchar_t
#elif defined(SIZE_MAX) && SIZE_MAX == USHRT_MAX
#define ckd_size_t  ckd_ushrt_t
#elif defined(SIZE_MAX) && SIZE_MAX == UINT_MAX
#define ckd_size_t  ckd_uint_t
#elif defined(SIZE_MAX) && SIZE_MAX == ULONG_MAX
#define ckd_size_t  ckd_ulong_t
#elif defined(SIZE_MAX) && SIZE_MAX == ULLONG_MAX
#define ckd_size_t  ckd_ullong_t
#endif
/**
 * @define ckd_ptrdiff_t
 * @brief Check integer type ckd_ptrdiff_t is an alias to one of ckd_*_t basic types.
 */
#if defined(PTRDIFF_MAX) && PTRDIFF_MAX == SCHAR_MAX
#define ckd_ptrdiff_t  ckd_schar_t
#elif defined(PTRDIFF_MAX) && PTRDIFF_MAX == SHRT_MAX
#define ckd_ptrdiff_t  ckd_shrt_t
#elif defined(PTRDIFF_MAX) && PTRDIFF_MAX == INT_MAX
#define ckd_ptrdiff_t  ckd_int_t
#elif defined(PTRDIFF_MAX) && PTRDIFF_MAX == LONG_MAX
#define ckd_ptrdiff_t  ckd_long_t
#elif defined(PTRDIFF_MAX) && PTRDIFF_MAX == LLONG_MAX
#define ckd_ptrdiff_t  ckd_llong_t
#endif
/**
 * @define ckd_intptr_t
 * @brief Check integer type ckd_intptr_t is an alias to one of ckd_*_t basic types.
 */
#if defined(INTPTR_MAX) && INTPTR_MAX == SCHAR_MAX
#define ckd_intptr_t  ckd_schar_t
#elif defined(INTPTR_MAX) && INTPTR_MAX == SHRT_MAX
#define ckd_intptr_t  ckd_shrt_t
#elif defined(INTPTR_MAX) && INTPTR_MAX == INT_MAX
#define ckd_intptr_t  ckd_int_t
#elif defined(INTPTR_MAX) && INTPTR_MAX == LONG_MAX
#define ckd_intptr_t  ckd_long_t
#elif defined(INTPTR_MAX) && INTPTR_MAX == LLONG_MAX
#define ckd_intptr_t  ckd_llong_t
#endif
/**
 * @define ckd_uintptr_t
 * @brief Check integer type ckd_uintptr_t is an alias to one of ckd_*_t basic types.
 */
#if defined(UINTPTR_MAX) && UINTPTR_MAX == UCHAR_MAX
#define ckd_uintptr_t  ckd_uchar_t
#elif defined(UINTPTR_MAX) && UINTPTR_MAX == USHRT_MAX
#define ckd_uintptr_t  ckd_ushrt_t
#elif defined(UINTPTR_MAX) && UINTPTR_MAX == UINT_MAX
#define ckd_uintptr_t  ckd_uint_t
#elif defined(UINTPTR_MAX) && UINTPTR_MAX == ULONG_MAX
#define ckd_uintptr_t  ckd_ulong_t
#elif defined(UINTPTR_MAX) && UINTPTR_MAX == ULLONG_MAX
#define ckd_uintptr_t  ckd_ullong_t
#endif
/**
 * @define ckd_int8_t
 * @brief Check integer type ckd_int8_t is an alias to one of ckd_*_t basic types.
 */
#if defined(INT8_MAX) && INT8_MAX == SCHAR_MAX
#define ckd_int8_t  ckd_schar_t
#elif defined(INT8_MAX) && INT8_MAX == SHRT_MAX
#define ckd_int8_t  ckd_shrt_t
#elif defined(INT8_MAX) && INT8_MAX == INT_MAX
#define ckd_int8_t  ckd_int_t
#elif defined(INT8_MAX) && INT8_MAX == LONG_MAX
#define ckd_int8_t  ckd_long_t
#elif defined(INT8_MAX) && INT8_MAX == LLONG_MAX
#define ckd_int8_t  ckd_llong_t
#endif
/**
 * @define ckd_uint8_t
 * @brief Check integer type ckd_uint8_t is an alias to one of ckd_*_t basic types.
 */
#if defined(UINT8_MAX) && UINT8_MAX == UCHAR_MAX
#define ckd_uint8_t  ckd_uchar_t
#elif defined(UINT8_MAX) && UINT8_MAX == USHRT_MAX
#define ckd_uint8_t  ckd_ushrt_t
#elif defined(UINT8_MAX) && UINT8_MAX == UINT_MAX
#define ckd_uint8_t  ckd_uint_t
#elif defined(UINT8_MAX) && UINT8_MAX == ULONG_MAX
#define ckd_uint8_t  ckd_ulong_t
#elif defined(UINT8_MAX) && UINT8_MAX == ULLONG_MAX
#define ckd_uint8_t  ckd_ullong_t
#endif
/**
 * @define ckd_int_least8_t
 * @brief Check integer type ckd_int_least8_t is an alias to one of ckd_*_t basic types.
 */
#if defined(INT_LEAST8_MAX) && INT_LEAST8_MAX == SCHAR_MAX
#define ckd_int_least8_t  ckd_schar_t
#elif defined(INT_LEAST8_MAX) && INT_LEAST8_MAX == SHRT_MAX
#define ckd_int_least8_t  ckd_shrt_t
#elif defined(INT_LEAST8_MAX) && INT_LEAST8_MAX == INT_MAX
#define ckd_int_least8_t  ckd_int_t
#elif defined(INT_LEAST8_MAX) && INT_LEAST8_MAX == LONG_MAX
#define ckd_int_least8_t  ckd_long_t
#elif defined(INT_LEAST8_MAX) && INT_LEAST8_MAX == LLONG_MAX
#define ckd_int_least8_t  ckd_llong_t
#endif
/**
 * @define ckd_uint_least8_t
 * @brief Check integer type ckd_uint_least8_t is an alias to one of ckd_*_t basic types.
 */
#if defined(UINT_LEAST8_MAX) && UINT_LEAST8_MAX == UCHAR_MAX
#define ckd_uint_least8_t  ckd_uchar_t
#elif defined(UINT_LEAST8_MAX) && UINT_LEAST8_MAX == USHRT_MAX
#define ckd_uint_least8_t  ckd_ushrt_t
#elif defined(UINT_LEAST8_MAX) && UINT_LEAST8_MAX == UINT_MAX
#define ckd_uint_least8_t  ckd_uint_t
#elif defined(UINT_LEAST8_MAX) && UINT_LEAST8_MAX == ULONG_MAX
#define ckd_uint_least8_t  ckd_ulong_t
#elif defined(UINT_LEAST8_MAX) && UINT_LEAST8_MAX == ULLONG_MAX
#define ckd_uint_least8_t  ckd_ullong_t
#endif
/**
 * @define ckd_int_fast8_t
 * @brief Check integer type ckd_int_fast8_t is an alias to one of ckd_*_t basic types.
 */
#if defined(INT_FAST8_MAX) && INT_FAST8_MAX == SCHAR_MAX
#define ckd_int_fast8_t  ckd_schar_t
#elif defined(INT_FAST8_MAX) && INT_FAST8_MAX == SHRT_MAX
#define ckd_int_fast8_t  ckd_shrt_t
#elif defined(INT_FAST8_MAX) && INT_FAST8_MAX == INT_MAX
#define ckd_int_fast8_t  ckd_int_t
#elif defined(INT_FAST8_MAX) && INT_FAST8_MAX == LONG_MAX
#define ckd_int_fast8_t  ckd_long_t
#elif defined(INT_FAST8_MAX) && INT_FAST8_MAX == LLONG_MAX
#define ckd_int_fast8_t  ckd_llong_t
#endif
/**
 * @define ckd_uint_fast8_t
 * @brief Check integer type ckd_uint_fast8_t is an alias to one of ckd_*_t basic types.
 */
#if defined(UINT_FAST8_MAX) && UINT_FAST8_MAX == UCHAR_MAX
#define ckd_uint_fast8_t  ckd_uchar_t
#elif defined(UINT_FAST8_MAX) && UINT_FAST8_MAX == USHRT_MAX
#define ckd_uint_fast8_t  ckd_ushrt_t
#elif defined(UINT_FAST8_MAX) && UINT_FAST8_MAX == UINT_MAX
#define ckd_uint_fast8_t  ckd_uint_t
#elif defined(UINT_FAST8_MAX) && UINT_FAST8_MAX == ULONG_MAX
#define ckd_uint_fast8_t  ckd_ulong_t
#elif defined(UINT_FAST8_MAX) && UINT_FAST8_MAX == ULLONG_MAX
#define ckd_uint_fast8_t  ckd_ullong_t
#endif
/**
 * @define ckd_int16_t
 * @brief Check integer type ckd_int16_t is an alias to one of ckd_*_t basic types.
 */
#if defined(INT16_MAX) && INT16_MAX == SCHAR_MAX
#define ckd_int16_t  ckd_schar_t
#elif defined(INT16_MAX) && INT16_MAX == SHRT_MAX
#define ckd_int16_t  ckd_shrt_t
#elif defined(INT16_MAX) && INT16_MAX == INT_MAX
#define ckd_int16_t  ckd_int_t
#elif defined(INT16_MAX) && INT16_MAX == LONG_MAX
#define ckd_int16_t  ckd_long_t
#elif defined(INT16_MAX) && INT16_MAX == LLONG_MAX
#define ckd_int16_t  ckd_llong_t
#endif
/**
 * @define ckd_uint16_t
 * @brief Check integer type ckd_uint16_t is an alias to one of ckd_*_t basic types.
 */
#if defined(UINT16_MAX) && UINT16_MAX == UCHAR_MAX
#define ckd_uint16_t  ckd_uchar_t
#elif defined(UINT16_MAX) && UINT16_MAX == USHRT_MAX
#define ckd_uint16_t  ckd_ushrt_t
#elif defined(UINT16_MAX) && UINT16_MAX == UINT_MAX
#define ckd_uint16_t  ckd_uint_t
#elif defined(UINT16_MAX) && UINT16_MAX == ULONG_MAX
#define ckd_uint16_t  ckd_ulong_t
#elif defined(UINT16_MAX) && UINT16_MAX == ULLONG_MAX
#define ckd_uint16_t  ckd_ullong_t
#endif
/**
 * @define ckd_int_least16_t
 * @brief Check integer type ckd_int_least16_t is an alias to one of ckd_*_t basic types.
 */
#if defined(INT_LEAST16_MAX) && INT_LEAST16_MAX == SCHAR_MAX
#define ckd_int_least16_t  ckd_schar_t
#elif defined(INT_LEAST16_MAX) && INT_LEAST16_MAX == SHRT_MAX
#define ckd_int_least16_t  ckd_shrt_t
#elif defined(INT_LEAST16_MAX) && INT_LEAST16_MAX == INT_MAX
#define ckd_int_least16_t  ckd_int_t
#elif defined(INT_LEAST16_MAX) && INT_LEAST16_MAX == LONG_MAX
#define ckd_int_least16_t  ckd_long_t
#elif defined(INT_LEAST16_MAX) && INT_LEAST16_MAX == LLONG_MAX
#define ckd_int_least16_t  ckd_llong_t
#endif
/**
 * @define ckd_uint_least16_t
 * @brief Check integer type ckd_uint_least16_t is an alias to one of ckd_*_t basic types.
 */
#if defined(UINT_LEAST16_MAX) && UINT_LEAST16_MAX == UCHAR_MAX
#define ckd_uint_least16_t  ckd_uchar_t
#elif defined(UINT_LEAST16_MAX) && UINT_LEAST16_MAX == USHRT_MAX
#define ckd_uint_least16_t  ckd_ushrt_t
#elif defined(UINT_LEAST16_MAX) && UINT_LEAST16_MAX == UINT_MAX
#define ckd_uint_least16_t  ckd_uint_t
#elif defined(UINT_LEAST16_MAX) && UINT_LEAST16_MAX == ULONG_MAX
#define ckd_uint_least16_t  ckd_ulong_t
#elif defined(UINT_LEAST16_MAX) && UINT_LEAST16_MAX == ULLONG_MAX
#define ckd_uint_least16_t  ckd_ullong_t
#endif
/**
 * @define ckd_int_fast16_t
 * @brief Check integer type ckd_int_fast16_t is an alias to one of ckd_*_t basic types.
 */
#if defined(INT_FAST16_MAX) && INT_FAST16_MAX == SCHAR_MAX
#define ckd_int_fast16_t  ckd_schar_t
#elif defined(INT_FAST16_MAX) && INT_FAST16_MAX == SHRT_MAX
#define ckd_int_fast16_t  ckd_shrt_t
#elif defined(INT_FAST16_MAX) && INT_FAST16_MAX == INT_MAX
#define ckd_int_fast16_t  ckd_int_t
#elif defined(INT_FAST16_MAX) && INT_FAST16_MAX == LONG_MAX
#define ckd_int_fast16_t  ckd_long_t
#elif defined(INT_FAST16_MAX) && INT_FAST16_MAX == LLONG_MAX
#define ckd_int_fast16_t  ckd_llong_t
#endif
/**
 * @define ckd_uint_fast16_t
 * @brief Check integer type ckd_uint_fast16_t is an alias to one of ckd_*_t basic types.
 */
#if defined(UINT_FAST16_MAX) && UINT_FAST16_MAX == UCHAR_MAX
#define ckd_uint_fast16_t  ckd_uchar_t
#elif defined(UINT_FAST16_MAX) && UINT_FAST16_MAX == USHRT_MAX
#define ckd_uint_fast16_t  ckd_ushrt_t
#elif defined(UINT_FAST16_MAX) && UINT_FAST16_MAX == UINT_MAX
#define ckd_uint_fast16_t  ckd_uint_t
#elif defined(UINT_FAST16_MAX) && UINT_FAST16_MAX == ULONG_MAX
#define ckd_uint_fast16_t  ckd_ulong_t
#elif defined(UINT_FAST16_MAX) && UINT_FAST16_MAX == ULLONG_MAX
#define ckd_uint_fast16_t  ckd_ullong_t
#endif
/**
 * @define ckd_int32_t
 * @brief Check integer type ckd_int32_t is an alias to one of ckd_*_t basic types.
 */
#if defined(INT32_MAX) && INT32_MAX == SCHAR_MAX
#define ckd_int32_t  ckd_schar_t
#elif defined(INT32_MAX) && INT32_MAX == SHRT_MAX
#define ckd_int32_t  ckd_shrt_t
#elif defined(INT32_MAX) && INT32_MAX == INT_MAX
#define ckd_int32_t  ckd_int_t
#elif defined(INT32_MAX) && INT32_MAX == LONG_MAX
#define ckd_int32_t  ckd_long_t
#elif defined(INT32_MAX) && INT32_MAX == LLONG_MAX
#define ckd_int32_t  ckd_llong_t
#endif
/**
 * @define ckd_uint32_t
 * @brief Check integer type ckd_uint32_t is an alias to one of ckd_*_t basic types.
 */
#if defined(UINT32_MAX) && UINT32_MAX == UCHAR_MAX
#define ckd_uint32_t  ckd_uchar_t
#elif defined(UINT32_MAX) && UINT32_MAX == USHRT_MAX
#define ckd_uint32_t  ckd_ushrt_t
#elif defined(UINT32_MAX) && UINT32_MAX == UINT_MAX
#define ckd_uint32_t  ckd_uint_t
#elif defined(UINT32_MAX) && UINT32_MAX == ULONG_MAX
#define ckd_uint32_t  ckd_ulong_t
#elif defined(UINT32_MAX) && UINT32_MAX == ULLONG_MAX
#define ckd_uint32_t  ckd_ullong_t
#endif
/**
 * @define ckd_int_least32_t
 * @brief Check integer type ckd_int_least32_t is an alias to one of ckd_*_t basic types.
 */
#if defined(INT_LEAST32_MAX) && INT_LEAST32_MAX == SCHAR_MAX
#define ckd_int_least32_t  ckd_schar_t
#elif defined(INT_LEAST32_MAX) && INT_LEAST32_MAX == SHRT_MAX
#define ckd_int_least32_t  ckd_shrt_t
#elif defined(INT_LEAST32_MAX) && INT_LEAST32_MAX == INT_MAX
#define ckd_int_least32_t  ckd_int_t
#elif defined(INT_LEAST32_MAX) && INT_LEAST32_MAX == LONG_MAX
#define ckd_int_least32_t  ckd_long_t
#elif defined(INT_LEAST32_MAX) && INT_LEAST32_MAX == LLONG_MAX
#define ckd_int_least32_t  ckd_llong_t
#endif
/**
 * @define ckd_uint_least32_t
 * @brief Check integer type ckd_uint_least32_t is an alias to one of ckd_*_t basic types.
 */
#if defined(UINT_LEAST32_MAX) && UINT_LEAST32_MAX == UCHAR_MAX
#define ckd_uint_least32_t  ckd_uchar_t
#elif defined(UINT_LEAST32_MAX) && UINT_LEAST32_MAX == USHRT_MAX
#define ckd_uint_least32_t  ckd_ushrt_t
#elif defined(UINT_LEAST32_MAX) && UINT_LEAST32_MAX == UINT_MAX
#define ckd_uint_least32_t  ckd_uint_t
#elif defined(UINT_LEAST32_MAX) && UINT_LEAST32_MAX == ULONG_MAX
#define ckd_uint_least32_t  ckd_ulong_t
#elif defined(UINT_LEAST32_MAX) && UINT_LEAST32_MAX == ULLONG_MAX
#define ckd_uint_least32_t  ckd_ullong_t
#endif
/**
 * @define ckd_int_fast32_t
 * @brief Check integer type ckd_int_fast32_t is an alias to one of ckd_*_t basic types.
 */
#if defined(INT_FAST32_MAX) && INT_FAST32_MAX == SCHAR_MAX
#define ckd_int_fast32_t  ckd_schar_t
#elif defined(INT_FAST32_MAX) && INT_FAST32_MAX == SHRT_MAX
#define ckd_int_fast32_t  ckd_shrt_t
#elif defined(INT_FAST32_MAX) && INT_FAST32_MAX == INT_MAX
#define ckd_int_fast32_t  ckd_int_t
#elif defined(INT_FAST32_MAX) && INT_FAST32_MAX == LONG_MAX
#define ckd_int_fast32_t  ckd_long_t
#elif defined(INT_FAST32_MAX) && INT_FAST32_MAX == LLONG_MAX
#define ckd_int_fast32_t  ckd_llong_t
#endif
/**
 * @define ckd_uint_fast32_t
 * @brief Check integer type ckd_uint_fast32_t is an alias to one of ckd_*_t basic types.
 */
#if defined(UINT_FAST32_MAX) && UINT_FAST32_MAX == UCHAR_MAX
#define ckd_uint_fast32_t  ckd_uchar_t
#elif defined(UINT_FAST32_MAX) && UINT_FAST32_MAX == USHRT_MAX
#define ckd_uint_fast32_t  ckd_ushrt_t
#elif defined(UINT_FAST32_MAX) && UINT_FAST32_MAX == UINT_MAX
#define ckd_uint_fast32_t  ckd_uint_t
#elif defined(UINT_FAST32_MAX) && UINT_FAST32_MAX == ULONG_MAX
#define ckd_uint_fast32_t  ckd_ulong_t
#elif defined(UINT_FAST32_MAX) && UINT_FAST32_MAX == ULLONG_MAX
#define ckd_uint_fast32_t  ckd_ullong_t
#endif
/**
 * @define ckd_int64_t
 * @brief Check integer type ckd_int64_t is an alias to one of ckd_*_t basic types.
 */
#if defined(INT64_MAX) && INT64_MAX == SCHAR_MAX
#define ckd_int64_t  ckd_schar_t
#elif defined(INT64_MAX) && INT64_MAX == SHRT_MAX
#define ckd_int64_t  ckd_shrt_t
#elif defined(INT64_MAX) && INT64_MAX == INT_MAX
#define ckd_int64_t  ckd_int_t
#elif defined(INT64_MAX) && INT64_MAX == LONG_MAX
#define ckd_int64_t  ckd_long_t
#elif defined(INT64_MAX) && INT64_MAX == LLONG_MAX
#define ckd_int64_t  ckd_llong_t
#endif
/**
 * @define ckd_uint64_t
 * @brief Check integer type ckd_uint64_t is an alias to one of ckd_*_t basic types.
 */
#if defined(UINT64_MAX) && UINT64_MAX == UCHAR_MAX
#define ckd_uint64_t  ckd_uchar_t
#elif defined(UINT64_MAX) && UINT64_MAX == USHRT_MAX
#define ckd_uint64_t  ckd_ushrt_t
#elif defined(UINT64_MAX) && UINT64_MAX == UINT_MAX
#define ckd_uint64_t  ckd_uint_t
#elif defined(UINT64_MAX) && UINT64_MAX == ULONG_MAX
#define ckd_uint64_t  ckd_ulong_t
#elif defined(UINT64_MAX) && UINT64_MAX == ULLONG_MAX
#define ckd_uint64_t  ckd_ullong_t
#endif
/**
 * @define ckd_int_least64_t
 * @brief Check integer type ckd_int_least64_t is an alias to one of ckd_*_t basic types.
 */
#if defined(INT_LEAST64_MAX) && INT_LEAST64_MAX == SCHAR_MAX
#define ckd_int_least64_t  ckd_schar_t
#elif defined(INT_LEAST64_MAX) && INT_LEAST64_MAX == SHRT_MAX
#define ckd_int_least64_t  ckd_shrt_t
#elif defined(INT_LEAST64_MAX) && INT_LEAST64_MAX == INT_MAX
#define ckd_int_least64_t  ckd_int_t
#elif defined(INT_LEAST64_MAX) && INT_LEAST64_MAX == LONG_MAX
#define ckd_int_least64_t  ckd_long_t
#elif defined(INT_LEAST64_MAX) && INT_LEAST64_MAX == LLONG_MAX
#define ckd_int_least64_t  ckd_llong_t
#endif
/**
 * @define ckd_uint_least64_t
 * @brief Check integer type ckd_uint_least64_t is an alias to one of ckd_*_t basic types.
 */
#if defined(UINT_LEAST64_MAX) && UINT_LEAST64_MAX == UCHAR_MAX
#define ckd_uint_least64_t  ckd_uchar_t
#elif defined(UINT_LEAST64_MAX) && UINT_LEAST64_MAX == USHRT_MAX
#define ckd_uint_least64_t  ckd_ushrt_t
#elif defined(UINT_LEAST64_MAX) && UINT_LEAST64_MAX == UINT_MAX
#define ckd_uint_least64_t  ckd_uint_t
#elif defined(UINT_LEAST64_MAX) && UINT_LEAST64_MAX == ULONG_MAX
#define ckd_uint_least64_t  ckd_ulong_t
#elif defined(UINT_LEAST64_MAX) && UINT_LEAST64_MAX == ULLONG_MAX
#define ckd_uint_least64_t  ckd_ullong_t
#endif
/**
 * @define ckd_int_fast64_t
 * @brief Check integer type ckd_int_fast64_t is an alias to one of ckd_*_t basic types.
 */
#if defined(INT_FAST64_MAX) && INT_FAST64_MAX == SCHAR_MAX
#define ckd_int_fast64_t  ckd_schar_t
#elif defined(INT_FAST64_MAX) && INT_FAST64_MAX == SHRT_MAX
#define ckd_int_fast64_t  ckd_shrt_t
#elif defined(INT_FAST64_MAX) && INT_FAST64_MAX == INT_MAX
#define ckd_int_fast64_t  ckd_int_t
#elif defined(INT_FAST64_MAX) && INT_FAST64_MAX == LONG_MAX
#define ckd_int_fast64_t  ckd_long_t
#elif defined(INT_FAST64_MAX) && INT_FAST64_MAX == LLONG_MAX
#define ckd_int_fast64_t  ckd_llong_t
#endif
/**
 * @define ckd_uint_fast64_t
 * @brief Check integer type ckd_uint_fast64_t is an alias to one of ckd_*_t basic types.
 */
#if defined(UINT_FAST64_MAX) && UINT_FAST64_MAX == UCHAR_MAX
#define ckd_uint_fast64_t  ckd_uchar_t
#elif defined(UINT_FAST64_MAX) && UINT_FAST64_MAX == USHRT_MAX
#define ckd_uint_fast64_t  ckd_ushrt_t
#elif defined(UINT_FAST64_MAX) && UINT_FAST64_MAX == UINT_MAX
#define ckd_uint_fast64_t  ckd_uint_t
#elif defined(UINT_FAST64_MAX) && UINT_FAST64_MAX == ULONG_MAX
#define ckd_uint_fast64_t  ckd_ulong_t
#elif defined(UINT_FAST64_MAX) && UINT_FAST64_MAX == ULLONG_MAX
#define ckd_uint_fast64_t  ckd_ullong_t
#endif

// ]]]
// Check integer accessors [[[

/**
 * @define bool ckd_overflow(ckd_type_t x);
 * @brief If ckd_type is a checked integer type, the ckd_overflow macro indicates if x was computed
using an operation that overflowed or suffered truncation or misinterpretation of sign.
 * @param x One of checked integer types.
 * @return The ckd_overflow macro returns true if overflow, truncation, or misinterpretation of sign
 * occurred when x was computed and false otherwise.
 */
#define ckd_overflow(x)  ((x)._ckd_Overflow)

/**
 * @define type ckd_value(ckd_type x);
 * @brief If ckd_type is a checked integer type, the ckd_value macro indicates the value of x.
 * If the overflow flag is set to false, the value correctly represents the mathematical value of whatever
 * operation(s) produced x. Otherwise, the value of x is converted as if by assignment to the type of x.
 * @param x One of checked integer types.
 * @return The ckd_value macro returns the value of x.
 */
#define ckd_value(x)     ((x)._ckd_Value)

// ]]]
// ckd_mk_* functions [[[
/**
 * @brief This function constructs a checked integer type ckd_char_t
 * given an unchecked integer of type char and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_char_t ckd_mk_char_t(char _ckd_value, bool _ckd_overflow) {
	const ckd_char_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_schar_t
 * given an unchecked integer of type signed char and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_schar_t ckd_mk_schar_t(signed char _ckd_value, bool _ckd_overflow) {
	const ckd_schar_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_uchar_t
 * given an unchecked integer of type unsigned char and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_uchar_t ckd_mk_uchar_t(unsigned char _ckd_value, bool _ckd_overflow) {
	const ckd_uchar_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_shrt_t
 * given an unchecked integer of type short and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_shrt_t ckd_mk_shrt_t(short _ckd_value, bool _ckd_overflow) {
	const ckd_shrt_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_ushrt_t
 * given an unchecked integer of type unsigned short and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_ushrt_t ckd_mk_ushrt_t(unsigned short _ckd_value, bool _ckd_overflow) {
	const ckd_ushrt_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_int_t
 * given an unchecked integer of type int and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_int_t ckd_mk_int_t(int _ckd_value, bool _ckd_overflow) {
	const ckd_int_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_uint_t
 * given an unchecked integer of type unsigned int and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_uint_t ckd_mk_uint_t(unsigned int _ckd_value, bool _ckd_overflow) {
	const ckd_uint_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_long_t
 * given an unchecked integer of type long and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_long_t ckd_mk_long_t(long _ckd_value, bool _ckd_overflow) {
	const ckd_long_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_ulong_t
 * given an unchecked integer of type unsigned long and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_ulong_t ckd_mk_ulong_t(unsigned long _ckd_value, bool _ckd_overflow) {
	const ckd_ulong_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_llong_t
 * given an unchecked integer of type long long and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_llong_t ckd_mk_llong_t(long long _ckd_value, bool _ckd_overflow) {
	const ckd_llong_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_ullong_t
 * given an unchecked integer of type unsigned long long and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_ullong_t ckd_mk_ullong_t(unsigned long long _ckd_value, bool _ckd_overflow) {
	const ckd_ullong_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_int128_t
 * given an unchecked integer of type __int128 and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_int128_t ckd_mk_int128_t(__int128 _ckd_value, bool _ckd_overflow) {
	const ckd_int128_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_uint128_t
 * given an unchecked integer of type unsigned __int128 and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_uint128_t ckd_mk_uint128_t(unsigned __int128 _ckd_value, bool _ckd_overflow) {
	const ckd_uint128_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_intmax_t
 * given an unchecked integer of type intmax_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_intmax_t ckd_mk_intmax_t(intmax_t _ckd_value, bool _ckd_overflow) {
	const ckd_intmax_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_uintmax_t
 * given an unchecked integer of type uintmax_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_uintmax_t ckd_mk_uintmax_t(uintmax_t _ckd_value, bool _ckd_overflow) {
	const ckd_uintmax_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_size_t
 * given an unchecked integer of type size_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_size_t ckd_mk_size_t(size_t _ckd_value, bool _ckd_overflow) {
	const ckd_size_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_ptrdiff_t
 * given an unchecked integer of type ptrdiff_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_ptrdiff_t ckd_mk_ptrdiff_t(ptrdiff_t _ckd_value, bool _ckd_overflow) {
	const ckd_ptrdiff_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_intptr_t
 * given an unchecked integer of type intptr_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_intptr_t ckd_mk_intptr_t(intptr_t _ckd_value, bool _ckd_overflow) {
	const ckd_intptr_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_uintptr_t
 * given an unchecked integer of type uintptr_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_uintptr_t ckd_mk_uintptr_t(uintptr_t _ckd_value, bool _ckd_overflow) {
	const ckd_uintptr_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_int8_t
 * given an unchecked integer of type int8_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_int8_t ckd_mk_int8_t(int8_t _ckd_value, bool _ckd_overflow) {
	const ckd_int8_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_uint8_t
 * given an unchecked integer of type uint8_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_uint8_t ckd_mk_uint8_t(uint8_t _ckd_value, bool _ckd_overflow) {
	const ckd_uint8_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_int_least8_t
 * given an unchecked integer of type int_least8_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_int_least8_t ckd_mk_int_least8_t(int_least8_t _ckd_value, bool _ckd_overflow) {
	const ckd_int_least8_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_uint_least8_t
 * given an unchecked integer of type uint_least8_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_uint_least8_t ckd_mk_uint_least8_t(uint_least8_t _ckd_value, bool _ckd_overflow) {
	const ckd_uint_least8_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_int_fast8_t
 * given an unchecked integer of type int_fast8_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_int_fast8_t ckd_mk_int_fast8_t(int_fast8_t _ckd_value, bool _ckd_overflow) {
	const ckd_int_fast8_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_uint_fast8_t
 * given an unchecked integer of type uint_fast8_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_uint_fast8_t ckd_mk_uint_fast8_t(uint_fast8_t _ckd_value, bool _ckd_overflow) {
	const ckd_uint_fast8_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_int16_t
 * given an unchecked integer of type int16_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_int16_t ckd_mk_int16_t(int16_t _ckd_value, bool _ckd_overflow) {
	const ckd_int16_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_uint16_t
 * given an unchecked integer of type uint16_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_uint16_t ckd_mk_uint16_t(uint16_t _ckd_value, bool _ckd_overflow) {
	const ckd_uint16_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_int_least16_t
 * given an unchecked integer of type int_least16_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_int_least16_t ckd_mk_int_least16_t(int_least16_t _ckd_value, bool _ckd_overflow) {
	const ckd_int_least16_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_uint_least16_t
 * given an unchecked integer of type uint_least16_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_uint_least16_t ckd_mk_uint_least16_t(uint_least16_t _ckd_value, bool _ckd_overflow) {
	const ckd_uint_least16_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_int_fast16_t
 * given an unchecked integer of type int_fast16_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_int_fast16_t ckd_mk_int_fast16_t(int_fast16_t _ckd_value, bool _ckd_overflow) {
	const ckd_int_fast16_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_uint_fast16_t
 * given an unchecked integer of type uint_fast16_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_uint_fast16_t ckd_mk_uint_fast16_t(uint_fast16_t _ckd_value, bool _ckd_overflow) {
	const ckd_uint_fast16_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_int32_t
 * given an unchecked integer of type int32_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_int32_t ckd_mk_int32_t(int32_t _ckd_value, bool _ckd_overflow) {
	const ckd_int32_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_uint32_t
 * given an unchecked integer of type uint32_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_uint32_t ckd_mk_uint32_t(uint32_t _ckd_value, bool _ckd_overflow) {
	const ckd_uint32_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_int_least32_t
 * given an unchecked integer of type int_least32_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_int_least32_t ckd_mk_int_least32_t(int_least32_t _ckd_value, bool _ckd_overflow) {
	const ckd_int_least32_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_uint_least32_t
 * given an unchecked integer of type uint_least32_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_uint_least32_t ckd_mk_uint_least32_t(uint_least32_t _ckd_value, bool _ckd_overflow) {
	const ckd_uint_least32_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_int_fast32_t
 * given an unchecked integer of type int_fast32_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_int_fast32_t ckd_mk_int_fast32_t(int_fast32_t _ckd_value, bool _ckd_overflow) {
	const ckd_int_fast32_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_uint_fast32_t
 * given an unchecked integer of type uint_fast32_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_uint_fast32_t ckd_mk_uint_fast32_t(uint_fast32_t _ckd_value, bool _ckd_overflow) {
	const ckd_uint_fast32_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_int64_t
 * given an unchecked integer of type int64_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_int64_t ckd_mk_int64_t(int64_t _ckd_value, bool _ckd_overflow) {
	const ckd_int64_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_uint64_t
 * given an unchecked integer of type uint64_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_uint64_t ckd_mk_uint64_t(uint64_t _ckd_value, bool _ckd_overflow) {
	const ckd_uint64_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_int_least64_t
 * given an unchecked integer of type int_least64_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_int_least64_t ckd_mk_int_least64_t(int_least64_t _ckd_value, bool _ckd_overflow) {
	const ckd_int_least64_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_uint_least64_t
 * given an unchecked integer of type uint_least64_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_uint_least64_t ckd_mk_uint_least64_t(uint_least64_t _ckd_value, bool _ckd_overflow) {
	const ckd_uint_least64_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_int_fast64_t
 * given an unchecked integer of type int_fast64_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_int_fast64_t ckd_mk_int_fast64_t(int_fast64_t _ckd_value, bool _ckd_overflow) {
	const ckd_int_fast64_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}
/**
 * @brief This function constructs a checked integer type ckd_uint_fast64_t
 * given an unchecked integer of type uint_fast64_t and an overflow flag.
 * If the overflow flag is true, the value is assumed to have involved overflow,
 * truncation, or  misinterpretation of sign.* Otherwise the value is assumed to
 * be mathematically correct.
 * @param value Unchecked integer.
 * @param oveflow Overflow flag.
 * @return Return a checked type that represents the value indicated by value and the exact
 * state indicated by overflow.
 */
_ckd_fconst ckd_uint_fast64_t ckd_mk_uint_fast64_t(uint_fast64_t _ckd_value, bool _ckd_overflow) {
	const ckd_uint_fast64_t _ckd_tmp = {_ckd_value, _ckd_overflow}; return _ckd_tmp;
}

#define ckd_mk(value, overflow) \
		_Generic((value) \
		,signed char: ckd_mk_schar_t \
		,unsigned char: ckd_mk_uchar_t \
		,short: ckd_mk_shrt_t \
		,unsigned short: ckd_mk_ushrt_t \
		,int: ckd_mk_int_t \
		,unsigned int: ckd_mk_uint_t \
		,long: ckd_mk_long_t \
		,unsigned long: ckd_mk_ulong_t \
		,long long: ckd_mk_llong_t \
		,unsigned long long: ckd_mk_ullong_t \
		,__int128: ckd_mk_int128_t \
		,unsigned __int128: ckd_mk_uint128_t \
		)(value, overflow)

// ]]]
// Macro helpers [[[
// ]]]
// Generic macros implementation [[[

// These two should provide _ckd_$OP_3 and _ckd_$OP_2
#if __GNUC__ >= 5 && !CKD_NOGNU_SOURCE
#include "ckdint/ckdint_gnu.h"
#else
#include "ckdint/ckdint_nognu.h"
#endif


/// @define _ckd_add_3
/// @brief ckd_add overflow for 3 arguments.
/// @see ckd_add

/// @define _ckd_add_2
/// @brief ckd_add overflow for 2 arguments.
/// @see ckd_add

/// @brief Macro overload on number of arguments for ckd_add
/// @see ckd_add
#define _ckd_add_N(_1, _2, _3, N, ...)  _ckd_add_##N(_1, _2, _3)

/**
 * @define ckd_add(...)
 * @brief `bool ckd_add(type1 *result, type2 a, type3 b);` or `ckd_type_t ckd_add(type1 a, type2 b);`
 * @param a Any checked or unchecked integer type other than plain char, bool, or an enumeration type.
 * @param b Any checked or unchecked integer type other than plain char, bool, or an enumeration type.
 * @param result Modifiable lvalue of any integer type.
 * @return In the first-form return false if type1 is sufficient to hold the mathematical result of
 * the computation, which is then stored in *result... Otherwise, these macros return true.. In this
 * case, *result is the mathematical result reduced by modular arithmetic on two’s-complement
 * representation with silent wrap-around on overflow. If *result is a checked integer type then its
 * overflow flag will equal the macro’s return value.
 * The macros of the second-form return a checked integer type that indicates the result of the
 * computation as well as an overflow flag.
 *
 * These macros perform operation add of the mathematical values of a and b.
 * In the first form, they store the result of the operation in *result, and in the second form, they return
 * the result as a checked integer.  Each operation is performed as if both operands were represented in a
 * signed integer type with infinite range, and the result was then converted from this integer type to a
 * particular type.  For the first form, this particular type is type1. For the second form, this type is the
 * type that would have been used had the operands undergone usual arithmetic conversion. (Section 6.3.1.8)
 */
#define ckd_add(...)  _ckd_add_N(__VA_ARGS__, 3, 2)


/// @define _ckd_sub_3
/// @brief ckd_sub overflow for 3 arguments.
/// @see ckd_sub

/// @define _ckd_sub_2
/// @brief ckd_sub overflow for 2 arguments.
/// @see ckd_sub

/// @brief Macro overload on number of arguments for ckd_sub
/// @see ckd_sub
#define _ckd_sub_N(_1, _2, _3, N, ...)  _ckd_sub_##N(_1, _2, _3)

/**
 * @define ckd_sub(...)
 * @brief `bool ckd_sub(type1 *result, type2 a, type3 b);` or `ckd_type_t ckd_sub(type1 a, type2 b);`
 * @param a Any checked or unchecked integer type other than plain char, bool, or an enumeration type.
 * @param b Any checked or unchecked integer type other than plain char, bool, or an enumeration type.
 * @param result Modifiable lvalue of any integer type.
 * @return In the first-form return false if type1 is sufficient to hold the mathematical result of
 * the computation, which is then stored in *result... Otherwise, these macros return true.. In this
 * case, *result is the mathematical result reduced by modular arithmetic on two’s-complement
 * representation with silent wrap-around on overflow. If *result is a checked integer type then its
 * overflow flag will equal the macro’s return value.
 * The macros of the second-form return a checked integer type that indicates the result of the
 * computation as well as an overflow flag.
 *
 * These macros perform operation sub of the mathematical values of a and b.
 * In the first form, they store the result of the operation in *result, and in the second form, they return
 * the result as a checked integer.  Each operation is performed as if both operands were represented in a
 * signed integer type with infinite range, and the result was then converted from this integer type to a
 * particular type.  For the first form, this particular type is type1. For the second form, this type is the
 * type that would have been used had the operands undergone usual arithmetic conversion. (Section 6.3.1.8)
 */
#define ckd_sub(...)  _ckd_sub_N(__VA_ARGS__, 3, 2)


/// @define _ckd_mul_3
/// @brief ckd_mul overflow for 3 arguments.
/// @see ckd_mul

/// @define _ckd_mul_2
/// @brief ckd_mul overflow for 2 arguments.
/// @see ckd_mul

/// @brief Macro overload on number of arguments for ckd_mul
/// @see ckd_mul
#define _ckd_mul_N(_1, _2, _3, N, ...)  _ckd_mul_##N(_1, _2, _3)

/**
 * @define ckd_mul(...)
 * @brief `bool ckd_mul(type1 *result, type2 a, type3 b);` or `ckd_type_t ckd_mul(type1 a, type2 b);`
 * @param a Any checked or unchecked integer type other than plain char, bool, or an enumeration type.
 * @param b Any checked or unchecked integer type other than plain char, bool, or an enumeration type.
 * @param result Modifiable lvalue of any integer type.
 * @return In the first-form return false if type1 is sufficient to hold the mathematical result of
 * the computation, which is then stored in *result... Otherwise, these macros return true.. In this
 * case, *result is the mathematical result reduced by modular arithmetic on two’s-complement
 * representation with silent wrap-around on overflow. If *result is a checked integer type then its
 * overflow flag will equal the macro’s return value.
 * The macros of the second-form return a checked integer type that indicates the result of the
 * computation as well as an overflow flag.
 *
 * These macros perform operation mul of the mathematical values of a and b.
 * In the first form, they store the result of the operation in *result, and in the second form, they return
 * the result as a checked integer.  Each operation is performed as if both operands were represented in a
 * signed integer type with infinite range, and the result was then converted from this integer type to a
 * particular type.  For the first form, this particular type is type1. For the second form, this type is the
 * type that would have been used had the operands undergone usual arithmetic conversion. (Section 6.3.1.8)
 */
#define ckd_mul(...)  _ckd_mul_N(__VA_ARGS__, 3, 2)

// ]]]
// Extensions [[[
#if defined(CKDINT_EXT_SOURCE) || defined(__GNU_SOURCE__)

/**
 * @define ckd_inc(...)
 * @brief ckd_inc(pnt) or ckd_inc(pnt, inc).
 * Increments value pointed to by pnt by 1 or by inc.
 * @param pnt Pointer to checked integer type or normal integer type.
 * Warning: it is evaulated twice!
 * @param inc The value to increment with. 1 by default.
 * @return overflow
 */
#define _ckd_inc_1(pnt, _)     ckd_add((pnt), *(pnt), 1)
#define _ckd_inc_2(pnt, inc)   ckd_add((pnt), *(pnt), (inc))
#define _ckd_inc_(pnt, inc, N, ...)  _ckd_inc_##N(pnt, inc)
#define ckd_inc(...)   _ckd_inc_(__VA_ARGS__, 2, 1)

/**
 * @define ckd_dec(...)
 * @brief ckd_dec(pnt) or ckd_dec(pnt, inc).
 * Decrements value pointed to by pnt by 1 or by inc.
 * @param pnt Pointer to checked integer type or normal integer type.
 * Warning: it is evaulated twice!
 * @param inc The value to increment with. 1 by default.
 * @return overflow
 */
#define _ckd_dec_1(pnt, _)     ckd_sub((pnt), *(pnt), 1)
#define _ckd_dec_2(pnt, inc)   ckd_sub((pnt), *(pnt), (inc))
#define _ckd_dec_(pnt, inc, N, ...)  _ckd_dec_##N(pnt, inc)
#define ckd_dec(...)   _ckd_dec_(__VA_ARGS__, 2, 1)

#endif
// ]]]
// EOF [[[

#endif  // CKDINT_H_

// ]]]
// vim: ft=c


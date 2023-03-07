/**
 * @file ckdint_gnu.h
 * @author Kamil Cukrowski <kamilcukrowski@gmail.com>
 * @date 2021-06-19
 * @copyright 2022 Kamil Cukrowski <kamilcukrowski@gmail.com>
 * SPDX-FileCopyrightText: 2022 Kamil Cukrowski <kamilcukrowski@gmail.com>
 * SPDX-License-Identifier: MIT
 */
#define CKDINT_GNU
#ifndef CKDINT_H_
#error  This is internal header
#include "../ckdint.h"
#endif
// Helper macros [[[

/**
 * @define ckd_ctypeof(x)
 * @brief For any basic type and checked type return a zero intialized
 * associated checked integer type. This is to be used in _Generic expressions.
 * @param X Any integer type or checked integer type.
 * @return A checked integer type the same type of integer type
 * or the type of the value of checked integer type.
 */
#define _ckd_ctypeof(X) \
		_Generic((X) \
		,char: (ckd_char_t){0} \
		,ckd_char_t: (ckd_char_t){0} \
		,signed char: (ckd_schar_t){0} \
		,ckd_schar_t: (ckd_schar_t){0} \
		,unsigned char: (ckd_uchar_t){0} \
		,ckd_uchar_t: (ckd_uchar_t){0} \
		,short: (ckd_shrt_t){0} \
		,ckd_shrt_t: (ckd_shrt_t){0} \
		,unsigned short: (ckd_ushrt_t){0} \
		,ckd_ushrt_t: (ckd_ushrt_t){0} \
		,int: (ckd_int_t){0} \
		,ckd_int_t: (ckd_int_t){0} \
		,unsigned int: (ckd_uint_t){0} \
		,ckd_uint_t: (ckd_uint_t){0} \
		,long: (ckd_long_t){0} \
		,ckd_long_t: (ckd_long_t){0} \
		,unsigned long: (ckd_ulong_t){0} \
		,ckd_ulong_t: (ckd_ulong_t){0} \
		,long long: (ckd_llong_t){0} \
		,ckd_llong_t: (ckd_llong_t){0} \
		,unsigned long long: (ckd_ullong_t){0} \
		,ckd_ullong_t: (ckd_ullong_t){0} \
		,__int128: (ckd_int128_t){0} \
		,ckd_int128_t: (ckd_int128_t){0} \
		,unsigned __int128: (ckd_uint128_t){0} \
		,ckd_uint128_t: (ckd_uint128_t){0} \
		)

_ckd_fconst ckd_char_t _ckd_toct_cchar(ckd_char_t _ckd_v, bool _ckd_ignore) { (void)_ckd_ignore; return _ckd_v; }
_ckd_fconst ckd_schar_t _ckd_toct_cschar(ckd_schar_t _ckd_v, bool _ckd_ignore) { (void)_ckd_ignore; return _ckd_v; }
_ckd_fconst ckd_uchar_t _ckd_toct_cuchar(ckd_uchar_t _ckd_v, bool _ckd_ignore) { (void)_ckd_ignore; return _ckd_v; }
_ckd_fconst ckd_shrt_t _ckd_toct_cshrt(ckd_shrt_t _ckd_v, bool _ckd_ignore) { (void)_ckd_ignore; return _ckd_v; }
_ckd_fconst ckd_ushrt_t _ckd_toct_cushrt(ckd_ushrt_t _ckd_v, bool _ckd_ignore) { (void)_ckd_ignore; return _ckd_v; }
_ckd_fconst ckd_int_t _ckd_toct_cint(ckd_int_t _ckd_v, bool _ckd_ignore) { (void)_ckd_ignore; return _ckd_v; }
_ckd_fconst ckd_uint_t _ckd_toct_cuint(ckd_uint_t _ckd_v, bool _ckd_ignore) { (void)_ckd_ignore; return _ckd_v; }
_ckd_fconst ckd_long_t _ckd_toct_clong(ckd_long_t _ckd_v, bool _ckd_ignore) { (void)_ckd_ignore; return _ckd_v; }
_ckd_fconst ckd_ulong_t _ckd_toct_culong(ckd_ulong_t _ckd_v, bool _ckd_ignore) { (void)_ckd_ignore; return _ckd_v; }
_ckd_fconst ckd_llong_t _ckd_toct_cllong(ckd_llong_t _ckd_v, bool _ckd_ignore) { (void)_ckd_ignore; return _ckd_v; }
_ckd_fconst ckd_ullong_t _ckd_toct_cullong(ckd_ullong_t _ckd_v, bool _ckd_ignore) { (void)_ckd_ignore; return _ckd_v; }
_ckd_fconst ckd_int128_t _ckd_toct_cint128(ckd_int128_t _ckd_v, bool _ckd_ignore) { (void)_ckd_ignore; return _ckd_v; }
_ckd_fconst ckd_uint128_t _ckd_toct_cuint128(ckd_uint128_t _ckd_v, bool _ckd_ignore) { (void)_ckd_ignore; return _ckd_v; }

/**
 * @define ckd_toct(x)
 * @brief For any basic type and checked type convert it to associated
 * checked integer type. Integers have overflow equal to 0.
 * @param X Any integer type or checked integer type.
 * @return A checked integer type the same type of integer type
 * or the value of checked integer type.
 */
#define _ckd_toct(X) \
		_Generic((X) \
		,char: ckd_mk_char_t \
		,ckd_char_t: _ckd_toct_cchar \
		,signed char: ckd_mk_schar_t \
		,ckd_schar_t: _ckd_toct_cschar \
		,unsigned char: ckd_mk_uchar_t \
		,ckd_uchar_t: _ckd_toct_cuchar \
		,short: ckd_mk_shrt_t \
		,ckd_shrt_t: _ckd_toct_cshrt \
		,unsigned short: ckd_mk_ushrt_t \
		,ckd_ushrt_t: _ckd_toct_cushrt \
		,int: ckd_mk_int_t \
		,ckd_int_t: _ckd_toct_cint \
		,unsigned int: ckd_mk_uint_t \
		,ckd_uint_t: _ckd_toct_cuint \
		,long: ckd_mk_long_t \
		,ckd_long_t: _ckd_toct_clong \
		,unsigned long: ckd_mk_ulong_t \
		,ckd_ulong_t: _ckd_toct_culong \
		,long long: ckd_mk_llong_t \
		,ckd_llong_t: _ckd_toct_cllong \
		,unsigned long long: ckd_mk_ullong_t \
		,ckd_ullong_t: _ckd_toct_cullong \
		,__int128: ckd_mk_int128_t \
		,ckd_int128_t: _ckd_toct_cint128 \
		,unsigned __int128: ckd_mk_uint128_t \
		,ckd_uint128_t: _ckd_toct_cuint128 \
		)(X, 0)


// Checked Type TO some other type.
_ckd_fconst char _ckd_cttochar(ckd_char_t _ckd_v) { return ckd_value(_ckd_v); }
_ckd_fconst ckd_char_t _ckd_cttocchar(ckd_char_t _ckd_v) { return _ckd_v; }
_ckd_fconst signed char _ckd_cttoschar(ckd_schar_t _ckd_v) { return ckd_value(_ckd_v); }
_ckd_fconst ckd_schar_t _ckd_cttocschar(ckd_schar_t _ckd_v) { return _ckd_v; }
_ckd_fconst unsigned char _ckd_cttouchar(ckd_uchar_t _ckd_v) { return ckd_value(_ckd_v); }
_ckd_fconst ckd_uchar_t _ckd_cttocuchar(ckd_uchar_t _ckd_v) { return _ckd_v; }
_ckd_fconst short _ckd_cttoshrt(ckd_shrt_t _ckd_v) { return ckd_value(_ckd_v); }
_ckd_fconst ckd_shrt_t _ckd_cttocshrt(ckd_shrt_t _ckd_v) { return _ckd_v; }
_ckd_fconst unsigned short _ckd_cttoushrt(ckd_ushrt_t _ckd_v) { return ckd_value(_ckd_v); }
_ckd_fconst ckd_ushrt_t _ckd_cttocushrt(ckd_ushrt_t _ckd_v) { return _ckd_v; }
_ckd_fconst int _ckd_cttoint(ckd_int_t _ckd_v) { return ckd_value(_ckd_v); }
_ckd_fconst ckd_int_t _ckd_cttocint(ckd_int_t _ckd_v) { return _ckd_v; }
_ckd_fconst unsigned int _ckd_cttouint(ckd_uint_t _ckd_v) { return ckd_value(_ckd_v); }
_ckd_fconst ckd_uint_t _ckd_cttocuint(ckd_uint_t _ckd_v) { return _ckd_v; }
_ckd_fconst long _ckd_cttolong(ckd_long_t _ckd_v) { return ckd_value(_ckd_v); }
_ckd_fconst ckd_long_t _ckd_cttoclong(ckd_long_t _ckd_v) { return _ckd_v; }
_ckd_fconst unsigned long _ckd_cttoulong(ckd_ulong_t _ckd_v) { return ckd_value(_ckd_v); }
_ckd_fconst ckd_ulong_t _ckd_cttoculong(ckd_ulong_t _ckd_v) { return _ckd_v; }
_ckd_fconst long long _ckd_cttollong(ckd_llong_t _ckd_v) { return ckd_value(_ckd_v); }
_ckd_fconst ckd_llong_t _ckd_cttocllong(ckd_llong_t _ckd_v) { return _ckd_v; }
_ckd_fconst unsigned long long _ckd_cttoullong(ckd_ullong_t _ckd_v) { return ckd_value(_ckd_v); }
_ckd_fconst ckd_ullong_t _ckd_cttocullong(ckd_ullong_t _ckd_v) { return _ckd_v; }
_ckd_fconst __int128 _ckd_cttoint128(ckd_int128_t _ckd_v) { return ckd_value(_ckd_v); }
_ckd_fconst ckd_int128_t _ckd_cttocint128(ckd_int128_t _ckd_v) { return _ckd_v; }
_ckd_fconst unsigned __int128 _ckd_cttouint128(ckd_uint128_t _ckd_v) { return ckd_value(_ckd_v); }
_ckd_fconst ckd_uint128_t _ckd_cttocuint128(ckd_uint128_t _ckd_v) { return _ckd_v; }

// ]]]
// Generic macros implementation for GNU compatible [[[

#define _ckd_add_2(a, b, _)  __extension__({ \
		__auto_type _ckd_a = (a); \
		__auto_type _ckd_b = (b); \
		__auto_type _ckd_ca = _ckd_toct(_ckd_a); \
		__auto_type _ckd_cb = _ckd_toct(_ckd_b); \
		__typeof__(_ckd_ctypeof(ckd_value(_ckd_ca) + ckd_value(_ckd_cb))) _ckd_tmp; \
		ckd_overflow(_ckd_tmp) = __builtin_add_overflow(ckd_value(_ckd_ca), ckd_value(_ckd_cb), &ckd_value(_ckd_tmp)) \
			|| ckd_overflow(_ckd_ca) || ckd_overflow(_ckd_cb); \
		_ckd_tmp; \
		})

#define _ckd_add_3(r, a, b)  __extension__({ \
		__auto_type _ckd_a = (a); \
		__auto_type _ckd_b = (b); \
		__auto_type _ckd_r = (r); \
		__auto_type _ckd_ca = _ckd_toct(_ckd_a); \
		__auto_type _ckd_cb = _ckd_toct(_ckd_b); \
		__typeof__(_ckd_ctypeof(*_ckd_r)) _ckd_tmp; \
		ckd_overflow(_ckd_tmp) = __builtin_add_overflow(ckd_value(_ckd_ca), ckd_value(_ckd_cb), &ckd_value(_ckd_tmp)) \
			|| ckd_overflow(_ckd_ca) || ckd_overflow(_ckd_cb); \
		*_ckd_r = _Generic(*_ckd_r \
			,char: _ckd_cttochar \
			,ckd_char_t: _ckd_cttocchar \
			,signed char: _ckd_cttoschar \
			,ckd_schar_t: _ckd_cttocschar \
			,unsigned char: _ckd_cttouchar \
			,ckd_uchar_t: _ckd_cttocuchar \
			,short: _ckd_cttoshrt \
			,ckd_shrt_t: _ckd_cttocshrt \
			,unsigned short: _ckd_cttoushrt \
			,ckd_ushrt_t: _ckd_cttocushrt \
			,int: _ckd_cttoint \
			,ckd_int_t: _ckd_cttocint \
			,unsigned int: _ckd_cttouint \
			,ckd_uint_t: _ckd_cttocuint \
			,long: _ckd_cttolong \
			,ckd_long_t: _ckd_cttoclong \
			,unsigned long: _ckd_cttoulong \
			,ckd_ulong_t: _ckd_cttoculong \
			,long long: _ckd_cttollong \
			,ckd_llong_t: _ckd_cttocllong \
			,unsigned long long: _ckd_cttoullong \
			,ckd_ullong_t: _ckd_cttocullong \
			,__int128: _ckd_cttoint128 \
			,ckd_int128_t: _ckd_cttocint128 \
			,unsigned __int128: _ckd_cttouint128 \
			,ckd_uint128_t: _ckd_cttocuint128 \
			)(_ckd_tmp); \
		ckd_overflow(_ckd_tmp); \
		})


#define _ckd_sub_2(a, b, _)  __extension__({ \
		__auto_type _ckd_a = (a); \
		__auto_type _ckd_b = (b); \
		__auto_type _ckd_ca = _ckd_toct(_ckd_a); \
		__auto_type _ckd_cb = _ckd_toct(_ckd_b); \
		__typeof__(_ckd_ctypeof(ckd_value(_ckd_ca) + ckd_value(_ckd_cb))) _ckd_tmp; \
		ckd_overflow(_ckd_tmp) = __builtin_sub_overflow(ckd_value(_ckd_ca), ckd_value(_ckd_cb), &ckd_value(_ckd_tmp)) \
			|| ckd_overflow(_ckd_ca) || ckd_overflow(_ckd_cb); \
		_ckd_tmp; \
		})

#define _ckd_sub_3(r, a, b)  __extension__({ \
		__auto_type _ckd_a = (a); \
		__auto_type _ckd_b = (b); \
		__auto_type _ckd_r = (r); \
		__auto_type _ckd_ca = _ckd_toct(_ckd_a); \
		__auto_type _ckd_cb = _ckd_toct(_ckd_b); \
		__typeof__(_ckd_ctypeof(*_ckd_r)) _ckd_tmp; \
		ckd_overflow(_ckd_tmp) = __builtin_sub_overflow(ckd_value(_ckd_ca), ckd_value(_ckd_cb), &ckd_value(_ckd_tmp)) \
			|| ckd_overflow(_ckd_ca) || ckd_overflow(_ckd_cb); \
		*_ckd_r = _Generic(*_ckd_r \
			,char: _ckd_cttochar \
			,ckd_char_t: _ckd_cttocchar \
			,signed char: _ckd_cttoschar \
			,ckd_schar_t: _ckd_cttocschar \
			,unsigned char: _ckd_cttouchar \
			,ckd_uchar_t: _ckd_cttocuchar \
			,short: _ckd_cttoshrt \
			,ckd_shrt_t: _ckd_cttocshrt \
			,unsigned short: _ckd_cttoushrt \
			,ckd_ushrt_t: _ckd_cttocushrt \
			,int: _ckd_cttoint \
			,ckd_int_t: _ckd_cttocint \
			,unsigned int: _ckd_cttouint \
			,ckd_uint_t: _ckd_cttocuint \
			,long: _ckd_cttolong \
			,ckd_long_t: _ckd_cttoclong \
			,unsigned long: _ckd_cttoulong \
			,ckd_ulong_t: _ckd_cttoculong \
			,long long: _ckd_cttollong \
			,ckd_llong_t: _ckd_cttocllong \
			,unsigned long long: _ckd_cttoullong \
			,ckd_ullong_t: _ckd_cttocullong \
			,__int128: _ckd_cttoint128 \
			,ckd_int128_t: _ckd_cttocint128 \
			,unsigned __int128: _ckd_cttouint128 \
			,ckd_uint128_t: _ckd_cttocuint128 \
			)(_ckd_tmp); \
		ckd_overflow(_ckd_tmp); \
		})


#define _ckd_mul_2(a, b, _)  __extension__({ \
		__auto_type _ckd_a = (a); \
		__auto_type _ckd_b = (b); \
		__auto_type _ckd_ca = _ckd_toct(_ckd_a); \
		__auto_type _ckd_cb = _ckd_toct(_ckd_b); \
		__typeof__(_ckd_ctypeof(ckd_value(_ckd_ca) + ckd_value(_ckd_cb))) _ckd_tmp; \
		ckd_overflow(_ckd_tmp) = __builtin_mul_overflow(ckd_value(_ckd_ca), ckd_value(_ckd_cb), &ckd_value(_ckd_tmp)) \
			|| ckd_overflow(_ckd_ca) || ckd_overflow(_ckd_cb); \
		_ckd_tmp; \
		})

#define _ckd_mul_3(r, a, b)  __extension__({ \
		__auto_type _ckd_a = (a); \
		__auto_type _ckd_b = (b); \
		__auto_type _ckd_r = (r); \
		__auto_type _ckd_ca = _ckd_toct(_ckd_a); \
		__auto_type _ckd_cb = _ckd_toct(_ckd_b); \
		__typeof__(_ckd_ctypeof(*_ckd_r)) _ckd_tmp; \
		ckd_overflow(_ckd_tmp) = __builtin_mul_overflow(ckd_value(_ckd_ca), ckd_value(_ckd_cb), &ckd_value(_ckd_tmp)) \
			|| ckd_overflow(_ckd_ca) || ckd_overflow(_ckd_cb); \
		*_ckd_r = _Generic(*_ckd_r \
			,char: _ckd_cttochar \
			,ckd_char_t: _ckd_cttocchar \
			,signed char: _ckd_cttoschar \
			,ckd_schar_t: _ckd_cttocschar \
			,unsigned char: _ckd_cttouchar \
			,ckd_uchar_t: _ckd_cttocuchar \
			,short: _ckd_cttoshrt \
			,ckd_shrt_t: _ckd_cttocshrt \
			,unsigned short: _ckd_cttoushrt \
			,ckd_ushrt_t: _ckd_cttocushrt \
			,int: _ckd_cttoint \
			,ckd_int_t: _ckd_cttocint \
			,unsigned int: _ckd_cttouint \
			,ckd_uint_t: _ckd_cttocuint \
			,long: _ckd_cttolong \
			,ckd_long_t: _ckd_cttoclong \
			,unsigned long: _ckd_cttoulong \
			,ckd_ulong_t: _ckd_cttoculong \
			,long long: _ckd_cttollong \
			,ckd_llong_t: _ckd_cttocllong \
			,unsigned long long: _ckd_cttoullong \
			,ckd_ullong_t: _ckd_cttocullong \
			,__int128: _ckd_cttoint128 \
			,ckd_int128_t: _ckd_cttocint128 \
			,unsigned __int128: _ckd_cttouint128 \
			,ckd_uint128_t: _ckd_cttocuint128 \
			)(_ckd_tmp); \
		ckd_overflow(_ckd_tmp); \
		})

// ]]]
// vim: ft=c


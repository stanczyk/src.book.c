/**
 * @file ckdint_nognu.h
 * @author Kamil Cukrowski <kamilcukrowski@gmail.com>
 * @date 2021-06-19
 * @copyright 2022 Kamil Cukrowski <kamilcukrowski@gmail.com>
 * SPDX-FileCopyrightText: 2022 Kamil Cukrowski <kamilcukrowski@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * While this file tries not to use any GNU extensions, it
 * strongly assumes that all types are twos-complement.
 * First everything is converted to unsigned types.
 */
// Header [[[
#define CKDINT_NOGNU
#ifndef CKDINT_H_
#error  This is internal header
#include "../ckdint.h"
#endif

#ifdef __SIZEOF_INT128__
#ifndef INT128_MAX
#define INT128_MAX   ((__int128)(((unsigned __int128) 1 << ((__SIZEOF_INT128__ * __CHAR_BIT__) - 1)) - 1))
#endif
#ifndef INT128_MIN
#define INT128_MIN   (-INT128_MAX - 1)
#endif
#ifndef UINT128_MAX
#define UINT128_MAX  ((2 * (unsigned __int128) INT128_MAX) + 1)
#endif
#endif  // __SIZEOF_INT128__


typedef struct {
	/// Represents the stored value.
	unsigned int _ckd_Value;
	/// Overflow?
	bool _ckd_Overflow;
	/// Was the original type signed?
	bool _ckd_Signed;
} _ckd_arg_uint;
typedef struct {
	/// Represents the stored value.
	unsigned long _ckd_Value;
	/// Overflow?
	bool _ckd_Overflow;
	/// Was the original type signed?
	bool _ckd_Signed;
} _ckd_arg_ulong;
typedef struct {
	/// Represents the stored value.
	unsigned long long _ckd_Value;
	/// Overflow?
	bool _ckd_Overflow;
	/// Was the original type signed?
	bool _ckd_Signed;
} _ckd_arg_ullong;
typedef struct {
	/// Represents the stored value.
	unsigned __int128 _ckd_Value;
	/// Overflow?
	bool _ckd_Overflow;
	/// Was the original type signed?
	bool _ckd_Signed;
} _ckd_arg_uint128;

// ]]]
// Init macros [[[
// Signed minimum and maximum!
#define _ckd_S    int
#define _ckd_U    unsigned int
#define _ckd_sign  ((_ckd_U)1 << (sizeof(_ckd_U) * CHAR_BIT - 1))
// ]]]
// Addition and substraction operations [[[

_ckd_fchpnt(3) bool _ckd_add_sss_int(_ckd_U _ckd_S1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 + _ckd_S2;
	return (_ckd_S)_ckd_S2 < 0 ? (_ckd_S)*_ckd_res > (_ckd_S)_ckd_S1 : (_ckd_S)*_ckd_res < (_ckd_S)_ckd_S1;
}

_ckd_fchpnt(3) bool _ckd_sub_sss_int(_ckd_U _ckd_S1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 - _ckd_S2;
	return (_ckd_S1 ^ _ckd_S2) & ~(*_ckd_res ^ _ckd_S2) & _ckd_sign;
}

_ckd_fchpnt(3) bool _ckd_add_uuu_int(_ckd_U _ckd_U1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_U1 + _ckd_U2;
	return *_ckd_res < _ckd_U1;
}

_ckd_fchpnt(3) bool _ckd_sub_uuu_int(_ckd_U _ckd_U1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_U1 - _ckd_U2;
	return *_ckd_res > _ckd_U1;
}

_ckd_fchpnt(3) bool _ckd_add_sus_int(_ckd_U _ckd_S1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 + _ckd_U2;
	return (*_ckd_res ^ _ckd_sign) < _ckd_U2;
}

_ckd_fchpnt(3) bool _ckd_add_suu_int(_ckd_U _ckd_S1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 + _ckd_U2;
	_ckd_S1 += _ckd_sign;
	return (*_ckd_res ^ _ckd_U2) & ~(_ckd_S1 ^ _ckd_U2) & _ckd_sign;
}

_ckd_fchpnt(3) bool _ckd_sub_sus_int(_ckd_U _ckd_S1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 - _ckd_U2;
	return _ckd_U2 > ((_ckd_U)_ckd_S1 ^ _ckd_sign);
}

_ckd_fchpnt(3) bool _ckd_sub_suu_int(_ckd_U _ckd_S1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 - _ckd_U2;
	return (_ckd_S)_ckd_S1 < 0 || _ckd_U2 > _ckd_S1;
}

_ckd_fchpnt(3) bool _ckd_sub_uss_int(_ckd_U _ckd_U1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_U1 - _ckd_S2;
	return _ckd_U1 >= (_ckd_S2 ^ _ckd_sign);
}

_ckd_fchpnt(3) bool _ckd_sub_usu_int(_ckd_U _ckd_U1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	const _ckd_U _T1 = _ckd_U1 ^ _ckd_sign;
	const _ckd_U _T2 = _T1 - _ckd_S2;
	*_ckd_res = _T2 ^ _ckd_sign;
	return (_ckd_S)_ckd_S2 < 0 ? (_ckd_S)_T2 < (_ckd_S)_T1 : (_ckd_S)_T2 > (_ckd_S)_T1;
}

_ckd_fchpnt(3) bool _ckd_add_ssu_int(_ckd_U _ckd_S1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 + _ckd_S2;
	return (_ckd_S)_ckd_S2 < 0 ? ((_ckd_S)(_ckd_S1 | *_ckd_res) < 0) : ((_ckd_S)(_ckd_S1 & *_ckd_res) < 0);
}

_ckd_fchpnt(3) bool _ckd_add_uus_int(_ckd_U _ckd_U1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_U1 + _ckd_U2;
	return *_ckd_res < _ckd_U2 || (_ckd_S)*_ckd_res < 0;
}

_ckd_fchpnt(3) bool _ckd_sub_uus_int(_ckd_U _ckd_U1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_U1 - _ckd_U2;
	return _ckd_U1 >= _ckd_U2 ? (_ckd_S)*_ckd_res < 0 : (_ckd_S)*_ckd_res >= 0;
}

_ckd_fchpnt(3) bool _ckd_sub_ssu_int(_ckd_U _ckd_S1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 - _ckd_S2;
	return (_ckd_S)_ckd_S2 >= 0 ? ((_ckd_S)(_ckd_S1 | *_ckd_res) < 0) : ((_ckd_S)(_ckd_S1 & *_ckd_res) < 0);
}

_ckd_fchpnt(3) bool _ckd_add_uss_int(_ckd_U _ckd_U1, _ckd_U _ckd_S1, _ckd_U *_ckd_res) {
	return _ckd_add_sus_int(_ckd_S1, _ckd_U1, _ckd_res);
}

_ckd_fchpnt(3) bool _ckd_add_usu_int(_ckd_U _ckd_U1, _ckd_U _ckd_S1, _ckd_U *_ckd_res) {
	return _ckd_add_suu_int(_ckd_S1, _ckd_U1, _ckd_res);
}

// ]]]
// Multiplication [[[

_ckd_fconst bool _ckd_ovf_signed_int(_ckd_S _ckd_a, _ckd_S _ckd_b) {
	return _ckd_a > 0 ?
			_ckd_b > 0 ?
				(_ckd_a > INT_MAX / _ckd_b) :
				(_ckd_b < INT_MIN / _ckd_a) :
			_ckd_b > 0 ?
				(_ckd_a < INT_MIN / _ckd_b) :
				(_ckd_a != 0 && _ckd_b < INT_MAX / _ckd_a);
}

_ckd_fconst bool _ckd_ovf_unsigned_int(_ckd_U _ckd_a, _ckd_U _ckd_b) {
	return _ckd_a != 0 && _ckd_b > UINT_MAX / _ckd_a;
}


_ckd_fchpnt(3) bool _ckd_mul_sss_int(_ckd_U _ckd_S1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 * _ckd_S2;
	return _ckd_ovf_signed_int(_ckd_S1, _ckd_S2);
}

_ckd_fchpnt(3) bool _ckd_mul_uuu_int(_ckd_U _ckd_U1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_U1 * _ckd_U2;
	return _ckd_ovf_unsigned_int(_ckd_U1, _ckd_U2);
}

_ckd_fchpnt(3) bool _ckd_mul_suu_int(_ckd_U _ckd_S1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 * _ckd_U2;
	return ((_ckd_S) _ckd_S1 < 0 && _ckd_U2) || _ckd_ovf_unsigned_int(_ckd_S1, _ckd_U2);
}

_ckd_fchpnt(3) bool _ckd_mul_uus_int(_ckd_U _ckd_U1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_U1 * _ckd_U2;
	return (_ckd_S)*_ckd_res < 0 || _ckd_ovf_unsigned_int(_ckd_U1, _ckd_U2);
}

_ckd_fchpnt(3) bool _ckd_mul_sus_int(_ckd_U _ckd_S1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 * _ckd_U2;
	return (_ckd_S)_ckd_U2 >= 0 ? _ckd_ovf_signed_int(_ckd_S1, _ckd_U2) : (_ckd_S1 && ((_ckd_S)_ckd_S1 != -1 || _ckd_U2 != *_ckd_res));
}

_ckd_fchpnt(3) bool _ckd_mul_ssu_int(_ckd_U _ckd_S1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	const _ckd_U _T1 = (_ckd_S)(_ckd_S1 & _ckd_S2) < 0 ? (-_ckd_S1) : _ckd_S1;
	const _ckd_U _T2 = (_ckd_S)(_ckd_S1 & _ckd_S2) < 0 ? (-_ckd_S2) : _ckd_S2;
	*_ckd_res = _T1 * _T2;
	return (_ckd_S)(_ckd_S1 ^ _ckd_S2) < 0 ? (_ckd_S1 && _ckd_S2) : _ckd_ovf_signed_int(_T1, _T2);
}

_ckd_fchpnt(3) bool _ckd_mul_uss_int(_ckd_U _ckd_U1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	return _ckd_mul_sus_int(_ckd_S2, _ckd_U1, _ckd_res);
}

_ckd_fchpnt(3) bool _ckd_mul_usu_int(_ckd_U _ckd_U1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	return _ckd_mul_suu_int(_ckd_S2, _ckd_U1, _ckd_res);
}

/* ------------------------------------------------------------------------- */


_ckd_fchpnt(5) bool _ckd_add_int_choose_s(bool _ckd_asigned, bool _ckd_bsigned,
		_ckd_U _ckd_a, _ckd_U _ckd_b, _ckd_U *_ckd_res) {
	if (_ckd_asigned) {
		if (_ckd_bsigned) {
			return _ckd_add_sss_int(_ckd_a, _ckd_b, _ckd_res);
		}
		return _ckd_add_sus_int(_ckd_a, _ckd_b, _ckd_res);
	} else if (_ckd_bsigned) {
		return _ckd_add_uss_int(_ckd_a, _ckd_b, _ckd_res);
	}
	return _ckd_add_uus_int(_ckd_a, _ckd_b, _ckd_res);
}

_ckd_fchpnt(5) bool _ckd_add_int_choose_u(bool _ckd_asigned, bool _ckd_bsigned,
		_ckd_U _ckd_a, _ckd_U _ckd_b, _ckd_U *_ckd_res) {
	if (_ckd_asigned) {
		if (_ckd_bsigned) {
			return _ckd_add_ssu_int(_ckd_a, _ckd_b, _ckd_res);
		}
		return _ckd_add_suu_int(_ckd_a, _ckd_b, _ckd_res);
	} else if (_ckd_bsigned) {
		return _ckd_add_usu_int(_ckd_a, _ckd_b, _ckd_res);
	}
	return _ckd_add_uuu_int(_ckd_a, _ckd_b, _ckd_res);
}

_ckd_fconst ckd_int_t _ckd_add_2_int(_ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	ckd_int_t _ckd_tmp;
	unsigned int _ckd_utmp;
	ckd_overflow(_ckd_tmp) = _ckd_add_int_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_utmp)
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	ckd_value(_ckd_tmp) = _ckd_utmp;
	return _ckd_tmp;
}

_ckd_fconst ckd_uint_t _ckd_add_2_uint(_ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	ckd_uint_t _ckd_tmp;
	ckd_overflow(_ckd_tmp) = _ckd_add_int_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &ckd_value(_ckd_tmp))
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	return _ckd_tmp;
}

_ckd_fchpnt(1) bool _ckd_add_3_uint_to_char(char *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	unsigned int _ckd_tmp;
	const bool _ckd_of =
#if CHAR_MAX == SCHAR_MAX
		_ckd_add_int_choose_s(
#else
		_ckd_add_int_choose_u(
#endif
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) CHAR_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_uint_to_schar(signed char *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	unsigned int _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_int_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) SCHAR_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (signed char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_uint_to_uchar(unsigned char *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	unsigned int _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_int_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if UINT_MAX > UCHAR_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) UCHAR_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_uint_to_shrt(short *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	unsigned int _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_int_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) SHRT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (short) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_uint_to_ushrt(unsigned short *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	unsigned int _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_int_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if UINT_MAX > USHRT_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) USHRT_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned short) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_uint_to_int(int *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	unsigned int _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_int_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) INT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (int) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_uint_to_uint(unsigned int *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	unsigned int _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_int_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if UINT_MAX > UINT_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) UINT_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned int) _ckd_tmp;
	return _ckd_of;
}


_ckd_fchpnt(5) bool _ckd_sub_int_choose_s(bool _ckd_asigned, bool _ckd_bsigned,
		_ckd_U _ckd_a, _ckd_U _ckd_b, _ckd_U *_ckd_res) {
	if (_ckd_asigned) {
		if (_ckd_bsigned) {
			return _ckd_sub_sss_int(_ckd_a, _ckd_b, _ckd_res);
		}
		return _ckd_sub_sus_int(_ckd_a, _ckd_b, _ckd_res);
	} else if (_ckd_bsigned) {
		return _ckd_sub_uss_int(_ckd_a, _ckd_b, _ckd_res);
	}
	return _ckd_sub_uus_int(_ckd_a, _ckd_b, _ckd_res);
}

_ckd_fchpnt(5) bool _ckd_sub_int_choose_u(bool _ckd_asigned, bool _ckd_bsigned,
		_ckd_U _ckd_a, _ckd_U _ckd_b, _ckd_U *_ckd_res) {
	if (_ckd_asigned) {
		if (_ckd_bsigned) {
			return _ckd_sub_ssu_int(_ckd_a, _ckd_b, _ckd_res);
		}
		return _ckd_sub_suu_int(_ckd_a, _ckd_b, _ckd_res);
	} else if (_ckd_bsigned) {
		return _ckd_sub_usu_int(_ckd_a, _ckd_b, _ckd_res);
	}
	return _ckd_sub_uuu_int(_ckd_a, _ckd_b, _ckd_res);
}

_ckd_fconst ckd_int_t _ckd_sub_2_int(_ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	ckd_int_t _ckd_tmp;
	unsigned int _ckd_utmp;
	ckd_overflow(_ckd_tmp) = _ckd_sub_int_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_utmp)
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	ckd_value(_ckd_tmp) = _ckd_utmp;
	return _ckd_tmp;
}

_ckd_fconst ckd_uint_t _ckd_sub_2_uint(_ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	ckd_uint_t _ckd_tmp;
	ckd_overflow(_ckd_tmp) = _ckd_sub_int_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &ckd_value(_ckd_tmp))
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	return _ckd_tmp;
}

_ckd_fchpnt(1) bool _ckd_sub_3_uint_to_char(char *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	unsigned int _ckd_tmp;
	const bool _ckd_of =
#if CHAR_MAX == SCHAR_MAX
		_ckd_sub_int_choose_s(
#else
		_ckd_sub_int_choose_u(
#endif
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) CHAR_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint_to_schar(signed char *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	unsigned int _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_int_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) SCHAR_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (signed char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint_to_uchar(unsigned char *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	unsigned int _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_int_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if UINT_MAX > UCHAR_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) UCHAR_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint_to_shrt(short *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	unsigned int _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_int_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) SHRT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (short) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint_to_ushrt(unsigned short *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	unsigned int _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_int_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if UINT_MAX > USHRT_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) USHRT_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned short) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint_to_int(int *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	unsigned int _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_int_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) INT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (int) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint_to_uint(unsigned int *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	unsigned int _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_int_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if UINT_MAX > UINT_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) UINT_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned int) _ckd_tmp;
	return _ckd_of;
}


_ckd_fchpnt(5) bool _ckd_mul_int_choose_s(bool _ckd_asigned, bool _ckd_bsigned,
		_ckd_U _ckd_a, _ckd_U _ckd_b, _ckd_U *_ckd_res) {
	if (_ckd_asigned) {
		if (_ckd_bsigned) {
			return _ckd_mul_sss_int(_ckd_a, _ckd_b, _ckd_res);
		}
		return _ckd_mul_sus_int(_ckd_a, _ckd_b, _ckd_res);
	} else if (_ckd_bsigned) {
		return _ckd_mul_uss_int(_ckd_a, _ckd_b, _ckd_res);
	}
	return _ckd_mul_uus_int(_ckd_a, _ckd_b, _ckd_res);
}

_ckd_fchpnt(5) bool _ckd_mul_int_choose_u(bool _ckd_asigned, bool _ckd_bsigned,
		_ckd_U _ckd_a, _ckd_U _ckd_b, _ckd_U *_ckd_res) {
	if (_ckd_asigned) {
		if (_ckd_bsigned) {
			return _ckd_mul_ssu_int(_ckd_a, _ckd_b, _ckd_res);
		}
		return _ckd_mul_suu_int(_ckd_a, _ckd_b, _ckd_res);
	} else if (_ckd_bsigned) {
		return _ckd_mul_usu_int(_ckd_a, _ckd_b, _ckd_res);
	}
	return _ckd_mul_uuu_int(_ckd_a, _ckd_b, _ckd_res);
}

_ckd_fconst ckd_int_t _ckd_mul_2_int(_ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	ckd_int_t _ckd_tmp;
	unsigned int _ckd_utmp;
	ckd_overflow(_ckd_tmp) = _ckd_mul_int_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_utmp)
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	ckd_value(_ckd_tmp) = _ckd_utmp;
	return _ckd_tmp;
}

_ckd_fconst ckd_uint_t _ckd_mul_2_uint(_ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	ckd_uint_t _ckd_tmp;
	ckd_overflow(_ckd_tmp) = _ckd_mul_int_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &ckd_value(_ckd_tmp))
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	return _ckd_tmp;
}

_ckd_fchpnt(1) bool _ckd_mul_3_uint_to_char(char *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	unsigned int _ckd_tmp;
	const bool _ckd_of =
#if CHAR_MAX == SCHAR_MAX
		_ckd_mul_int_choose_s(
#else
		_ckd_mul_int_choose_u(
#endif
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) CHAR_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint_to_schar(signed char *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	unsigned int _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_int_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) SCHAR_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (signed char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint_to_uchar(unsigned char *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	unsigned int _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_int_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if UINT_MAX > UCHAR_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) UCHAR_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint_to_shrt(short *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	unsigned int _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_int_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) SHRT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (short) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint_to_ushrt(unsigned short *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	unsigned int _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_int_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if UINT_MAX > USHRT_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) USHRT_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned short) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint_to_int(int *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	unsigned int _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_int_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) INT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (int) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint_to_uint(unsigned int *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	unsigned int _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_int_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if UINT_MAX > UINT_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) UINT_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned int) _ckd_tmp;
	return _ckd_of;
}


// ]]]
// Undef macros [[[
#undef _ckd_S
#undef _ckd_U
#undef _ckd_sign
// ]]]
// Init macros [[[
// Signed minimum and maximum!
#define _ckd_S    long
#define _ckd_U    unsigned long
#define _ckd_sign  ((_ckd_U)1 << (sizeof(_ckd_U) * CHAR_BIT - 1))
// ]]]
// Addition and substraction operations [[[

_ckd_fchpnt(3) bool _ckd_add_sss_long(_ckd_U _ckd_S1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 + _ckd_S2;
	return (_ckd_S)_ckd_S2 < 0 ? (_ckd_S)*_ckd_res > (_ckd_S)_ckd_S1 : (_ckd_S)*_ckd_res < (_ckd_S)_ckd_S1;
}

_ckd_fchpnt(3) bool _ckd_sub_sss_long(_ckd_U _ckd_S1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 - _ckd_S2;
	return (_ckd_S1 ^ _ckd_S2) & ~(*_ckd_res ^ _ckd_S2) & _ckd_sign;
}

_ckd_fchpnt(3) bool _ckd_add_uuu_long(_ckd_U _ckd_U1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_U1 + _ckd_U2;
	return *_ckd_res < _ckd_U1;
}

_ckd_fchpnt(3) bool _ckd_sub_uuu_long(_ckd_U _ckd_U1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_U1 - _ckd_U2;
	return *_ckd_res > _ckd_U1;
}

_ckd_fchpnt(3) bool _ckd_add_sus_long(_ckd_U _ckd_S1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 + _ckd_U2;
	return (*_ckd_res ^ _ckd_sign) < _ckd_U2;
}

_ckd_fchpnt(3) bool _ckd_add_suu_long(_ckd_U _ckd_S1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 + _ckd_U2;
	_ckd_S1 += _ckd_sign;
	return (*_ckd_res ^ _ckd_U2) & ~(_ckd_S1 ^ _ckd_U2) & _ckd_sign;
}

_ckd_fchpnt(3) bool _ckd_sub_sus_long(_ckd_U _ckd_S1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 - _ckd_U2;
	return _ckd_U2 > ((_ckd_U)_ckd_S1 ^ _ckd_sign);
}

_ckd_fchpnt(3) bool _ckd_sub_suu_long(_ckd_U _ckd_S1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 - _ckd_U2;
	return (_ckd_S)_ckd_S1 < 0 || _ckd_U2 > _ckd_S1;
}

_ckd_fchpnt(3) bool _ckd_sub_uss_long(_ckd_U _ckd_U1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_U1 - _ckd_S2;
	return _ckd_U1 >= (_ckd_S2 ^ _ckd_sign);
}

_ckd_fchpnt(3) bool _ckd_sub_usu_long(_ckd_U _ckd_U1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	const _ckd_U _T1 = _ckd_U1 ^ _ckd_sign;
	const _ckd_U _T2 = _T1 - _ckd_S2;
	*_ckd_res = _T2 ^ _ckd_sign;
	return (_ckd_S)_ckd_S2 < 0 ? (_ckd_S)_T2 < (_ckd_S)_T1 : (_ckd_S)_T2 > (_ckd_S)_T1;
}

_ckd_fchpnt(3) bool _ckd_add_ssu_long(_ckd_U _ckd_S1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 + _ckd_S2;
	return (_ckd_S)_ckd_S2 < 0 ? ((_ckd_S)(_ckd_S1 | *_ckd_res) < 0) : ((_ckd_S)(_ckd_S1 & *_ckd_res) < 0);
}

_ckd_fchpnt(3) bool _ckd_add_uus_long(_ckd_U _ckd_U1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_U1 + _ckd_U2;
	return *_ckd_res < _ckd_U2 || (_ckd_S)*_ckd_res < 0;
}

_ckd_fchpnt(3) bool _ckd_sub_uus_long(_ckd_U _ckd_U1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_U1 - _ckd_U2;
	return _ckd_U1 >= _ckd_U2 ? (_ckd_S)*_ckd_res < 0 : (_ckd_S)*_ckd_res >= 0;
}

_ckd_fchpnt(3) bool _ckd_sub_ssu_long(_ckd_U _ckd_S1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 - _ckd_S2;
	return (_ckd_S)_ckd_S2 >= 0 ? ((_ckd_S)(_ckd_S1 | *_ckd_res) < 0) : ((_ckd_S)(_ckd_S1 & *_ckd_res) < 0);
}

_ckd_fchpnt(3) bool _ckd_add_uss_long(_ckd_U _ckd_U1, _ckd_U _ckd_S1, _ckd_U *_ckd_res) {
	return _ckd_add_sus_long(_ckd_S1, _ckd_U1, _ckd_res);
}

_ckd_fchpnt(3) bool _ckd_add_usu_long(_ckd_U _ckd_U1, _ckd_U _ckd_S1, _ckd_U *_ckd_res) {
	return _ckd_add_suu_long(_ckd_S1, _ckd_U1, _ckd_res);
}

// ]]]
// Multiplication [[[

_ckd_fconst bool _ckd_ovf_signed_long(_ckd_S _ckd_a, _ckd_S _ckd_b) {
	return _ckd_a > 0 ?
			_ckd_b > 0 ?
				(_ckd_a > LONG_MAX / _ckd_b) :
				(_ckd_b < LONG_MIN / _ckd_a) :
			_ckd_b > 0 ?
				(_ckd_a < LONG_MIN / _ckd_b) :
				(_ckd_a != 0 && _ckd_b < LONG_MAX / _ckd_a);
}

_ckd_fconst bool _ckd_ovf_unsigned_long(_ckd_U _ckd_a, _ckd_U _ckd_b) {
	return _ckd_a != 0 && _ckd_b > ULONG_MAX / _ckd_a;
}


_ckd_fchpnt(3) bool _ckd_mul_sss_long(_ckd_U _ckd_S1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 * _ckd_S2;
	return _ckd_ovf_signed_long(_ckd_S1, _ckd_S2);
}

_ckd_fchpnt(3) bool _ckd_mul_uuu_long(_ckd_U _ckd_U1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_U1 * _ckd_U2;
	return _ckd_ovf_unsigned_long(_ckd_U1, _ckd_U2);
}

_ckd_fchpnt(3) bool _ckd_mul_suu_long(_ckd_U _ckd_S1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 * _ckd_U2;
	return ((_ckd_S) _ckd_S1 < 0 && _ckd_U2) || _ckd_ovf_unsigned_long(_ckd_S1, _ckd_U2);
}

_ckd_fchpnt(3) bool _ckd_mul_uus_long(_ckd_U _ckd_U1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_U1 * _ckd_U2;
	return (_ckd_S)*_ckd_res < 0 || _ckd_ovf_unsigned_long(_ckd_U1, _ckd_U2);
}

_ckd_fchpnt(3) bool _ckd_mul_sus_long(_ckd_U _ckd_S1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 * _ckd_U2;
	return (_ckd_S)_ckd_U2 >= 0 ? _ckd_ovf_signed_long(_ckd_S1, _ckd_U2) : (_ckd_S1 && ((_ckd_S)_ckd_S1 != -1 || _ckd_U2 != *_ckd_res));
}

_ckd_fchpnt(3) bool _ckd_mul_ssu_long(_ckd_U _ckd_S1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	const _ckd_U _T1 = (_ckd_S)(_ckd_S1 & _ckd_S2) < 0 ? (-_ckd_S1) : _ckd_S1;
	const _ckd_U _T2 = (_ckd_S)(_ckd_S1 & _ckd_S2) < 0 ? (-_ckd_S2) : _ckd_S2;
	*_ckd_res = _T1 * _T2;
	return (_ckd_S)(_ckd_S1 ^ _ckd_S2) < 0 ? (_ckd_S1 && _ckd_S2) : _ckd_ovf_signed_long(_T1, _T2);
}

_ckd_fchpnt(3) bool _ckd_mul_uss_long(_ckd_U _ckd_U1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	return _ckd_mul_sus_long(_ckd_S2, _ckd_U1, _ckd_res);
}

_ckd_fchpnt(3) bool _ckd_mul_usu_long(_ckd_U _ckd_U1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	return _ckd_mul_suu_long(_ckd_S2, _ckd_U1, _ckd_res);
}

/* ------------------------------------------------------------------------- */


_ckd_fchpnt(5) bool _ckd_add_long_choose_s(bool _ckd_asigned, bool _ckd_bsigned,
		_ckd_U _ckd_a, _ckd_U _ckd_b, _ckd_U *_ckd_res) {
	if (_ckd_asigned) {
		if (_ckd_bsigned) {
			return _ckd_add_sss_long(_ckd_a, _ckd_b, _ckd_res);
		}
		return _ckd_add_sus_long(_ckd_a, _ckd_b, _ckd_res);
	} else if (_ckd_bsigned) {
		return _ckd_add_uss_long(_ckd_a, _ckd_b, _ckd_res);
	}
	return _ckd_add_uus_long(_ckd_a, _ckd_b, _ckd_res);
}

_ckd_fchpnt(5) bool _ckd_add_long_choose_u(bool _ckd_asigned, bool _ckd_bsigned,
		_ckd_U _ckd_a, _ckd_U _ckd_b, _ckd_U *_ckd_res) {
	if (_ckd_asigned) {
		if (_ckd_bsigned) {
			return _ckd_add_ssu_long(_ckd_a, _ckd_b, _ckd_res);
		}
		return _ckd_add_suu_long(_ckd_a, _ckd_b, _ckd_res);
	} else if (_ckd_bsigned) {
		return _ckd_add_usu_long(_ckd_a, _ckd_b, _ckd_res);
	}
	return _ckd_add_uuu_long(_ckd_a, _ckd_b, _ckd_res);
}

_ckd_fconst ckd_long_t _ckd_add_2_long(_ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	ckd_long_t _ckd_tmp;
	unsigned long _ckd_utmp;
	ckd_overflow(_ckd_tmp) = _ckd_add_long_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_utmp)
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	ckd_value(_ckd_tmp) = _ckd_utmp;
	return _ckd_tmp;
}

_ckd_fconst ckd_ulong_t _ckd_add_2_ulong(_ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	ckd_ulong_t _ckd_tmp;
	ckd_overflow(_ckd_tmp) = _ckd_add_long_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &ckd_value(_ckd_tmp))
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	return _ckd_tmp;
}

_ckd_fchpnt(1) bool _ckd_add_3_ulong_to_char(char *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	unsigned long _ckd_tmp;
	const bool _ckd_of =
#if CHAR_MAX == SCHAR_MAX
		_ckd_add_long_choose_s(
#else
		_ckd_add_long_choose_u(
#endif
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) CHAR_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_ulong_to_schar(signed char *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	unsigned long _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_long_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) SCHAR_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (signed char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_ulong_to_uchar(unsigned char *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	unsigned long _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_long_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if ULONG_MAX > UCHAR_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) UCHAR_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_ulong_to_shrt(short *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	unsigned long _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_long_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) SHRT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (short) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_ulong_to_ushrt(unsigned short *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	unsigned long _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_long_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if ULONG_MAX > USHRT_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) USHRT_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned short) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_ulong_to_int(int *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	unsigned long _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_long_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) INT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (int) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_ulong_to_uint(unsigned int *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	unsigned long _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_long_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if ULONG_MAX > UINT_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) UINT_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned int) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_ulong_to_long(long *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	unsigned long _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_long_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) LONG_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (long) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_ulong_to_ulong(unsigned long *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	unsigned long _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_long_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if ULONG_MAX > ULONG_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) ULONG_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned long) _ckd_tmp;
	return _ckd_of;
}


_ckd_fchpnt(5) bool _ckd_sub_long_choose_s(bool _ckd_asigned, bool _ckd_bsigned,
		_ckd_U _ckd_a, _ckd_U _ckd_b, _ckd_U *_ckd_res) {
	if (_ckd_asigned) {
		if (_ckd_bsigned) {
			return _ckd_sub_sss_long(_ckd_a, _ckd_b, _ckd_res);
		}
		return _ckd_sub_sus_long(_ckd_a, _ckd_b, _ckd_res);
	} else if (_ckd_bsigned) {
		return _ckd_sub_uss_long(_ckd_a, _ckd_b, _ckd_res);
	}
	return _ckd_sub_uus_long(_ckd_a, _ckd_b, _ckd_res);
}

_ckd_fchpnt(5) bool _ckd_sub_long_choose_u(bool _ckd_asigned, bool _ckd_bsigned,
		_ckd_U _ckd_a, _ckd_U _ckd_b, _ckd_U *_ckd_res) {
	if (_ckd_asigned) {
		if (_ckd_bsigned) {
			return _ckd_sub_ssu_long(_ckd_a, _ckd_b, _ckd_res);
		}
		return _ckd_sub_suu_long(_ckd_a, _ckd_b, _ckd_res);
	} else if (_ckd_bsigned) {
		return _ckd_sub_usu_long(_ckd_a, _ckd_b, _ckd_res);
	}
	return _ckd_sub_uuu_long(_ckd_a, _ckd_b, _ckd_res);
}

_ckd_fconst ckd_long_t _ckd_sub_2_long(_ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	ckd_long_t _ckd_tmp;
	unsigned long _ckd_utmp;
	ckd_overflow(_ckd_tmp) = _ckd_sub_long_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_utmp)
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	ckd_value(_ckd_tmp) = _ckd_utmp;
	return _ckd_tmp;
}

_ckd_fconst ckd_ulong_t _ckd_sub_2_ulong(_ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	ckd_ulong_t _ckd_tmp;
	ckd_overflow(_ckd_tmp) = _ckd_sub_long_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &ckd_value(_ckd_tmp))
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	return _ckd_tmp;
}

_ckd_fchpnt(1) bool _ckd_sub_3_ulong_to_char(char *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	unsigned long _ckd_tmp;
	const bool _ckd_of =
#if CHAR_MAX == SCHAR_MAX
		_ckd_sub_long_choose_s(
#else
		_ckd_sub_long_choose_u(
#endif
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) CHAR_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_ulong_to_schar(signed char *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	unsigned long _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_long_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) SCHAR_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (signed char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_ulong_to_uchar(unsigned char *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	unsigned long _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_long_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if ULONG_MAX > UCHAR_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) UCHAR_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_ulong_to_shrt(short *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	unsigned long _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_long_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) SHRT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (short) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_ulong_to_ushrt(unsigned short *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	unsigned long _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_long_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if ULONG_MAX > USHRT_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) USHRT_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned short) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_ulong_to_int(int *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	unsigned long _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_long_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) INT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (int) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_ulong_to_uint(unsigned int *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	unsigned long _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_long_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if ULONG_MAX > UINT_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) UINT_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned int) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_ulong_to_long(long *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	unsigned long _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_long_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) LONG_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (long) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_ulong_to_ulong(unsigned long *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	unsigned long _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_long_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if ULONG_MAX > ULONG_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) ULONG_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned long) _ckd_tmp;
	return _ckd_of;
}


_ckd_fchpnt(5) bool _ckd_mul_long_choose_s(bool _ckd_asigned, bool _ckd_bsigned,
		_ckd_U _ckd_a, _ckd_U _ckd_b, _ckd_U *_ckd_res) {
	if (_ckd_asigned) {
		if (_ckd_bsigned) {
			return _ckd_mul_sss_long(_ckd_a, _ckd_b, _ckd_res);
		}
		return _ckd_mul_sus_long(_ckd_a, _ckd_b, _ckd_res);
	} else if (_ckd_bsigned) {
		return _ckd_mul_uss_long(_ckd_a, _ckd_b, _ckd_res);
	}
	return _ckd_mul_uus_long(_ckd_a, _ckd_b, _ckd_res);
}

_ckd_fchpnt(5) bool _ckd_mul_long_choose_u(bool _ckd_asigned, bool _ckd_bsigned,
		_ckd_U _ckd_a, _ckd_U _ckd_b, _ckd_U *_ckd_res) {
	if (_ckd_asigned) {
		if (_ckd_bsigned) {
			return _ckd_mul_ssu_long(_ckd_a, _ckd_b, _ckd_res);
		}
		return _ckd_mul_suu_long(_ckd_a, _ckd_b, _ckd_res);
	} else if (_ckd_bsigned) {
		return _ckd_mul_usu_long(_ckd_a, _ckd_b, _ckd_res);
	}
	return _ckd_mul_uuu_long(_ckd_a, _ckd_b, _ckd_res);
}

_ckd_fconst ckd_long_t _ckd_mul_2_long(_ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	ckd_long_t _ckd_tmp;
	unsigned long _ckd_utmp;
	ckd_overflow(_ckd_tmp) = _ckd_mul_long_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_utmp)
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	ckd_value(_ckd_tmp) = _ckd_utmp;
	return _ckd_tmp;
}

_ckd_fconst ckd_ulong_t _ckd_mul_2_ulong(_ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	ckd_ulong_t _ckd_tmp;
	ckd_overflow(_ckd_tmp) = _ckd_mul_long_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &ckd_value(_ckd_tmp))
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	return _ckd_tmp;
}

_ckd_fchpnt(1) bool _ckd_mul_3_ulong_to_char(char *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	unsigned long _ckd_tmp;
	const bool _ckd_of =
#if CHAR_MAX == SCHAR_MAX
		_ckd_mul_long_choose_s(
#else
		_ckd_mul_long_choose_u(
#endif
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) CHAR_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_ulong_to_schar(signed char *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	unsigned long _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_long_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) SCHAR_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (signed char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_ulong_to_uchar(unsigned char *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	unsigned long _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_long_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if ULONG_MAX > UCHAR_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) UCHAR_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_ulong_to_shrt(short *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	unsigned long _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_long_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) SHRT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (short) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_ulong_to_ushrt(unsigned short *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	unsigned long _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_long_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if ULONG_MAX > USHRT_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) USHRT_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned short) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_ulong_to_int(int *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	unsigned long _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_long_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) INT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (int) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_ulong_to_uint(unsigned int *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	unsigned long _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_long_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if ULONG_MAX > UINT_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) UINT_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned int) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_ulong_to_long(long *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	unsigned long _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_long_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) LONG_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (long) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_ulong_to_ulong(unsigned long *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	unsigned long _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_long_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if ULONG_MAX > ULONG_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) ULONG_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned long) _ckd_tmp;
	return _ckd_of;
}


// ]]]
// Undef macros [[[
#undef _ckd_S
#undef _ckd_U
#undef _ckd_sign
// ]]]
// Init macros [[[
// Signed minimum and maximum!
#define _ckd_S    long long
#define _ckd_U    unsigned long long
#define _ckd_sign  ((_ckd_U)1 << (sizeof(_ckd_U) * CHAR_BIT - 1))
// ]]]
// Addition and substraction operations [[[

_ckd_fchpnt(3) bool _ckd_add_sss_llong(_ckd_U _ckd_S1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 + _ckd_S2;
	return (_ckd_S)_ckd_S2 < 0 ? (_ckd_S)*_ckd_res > (_ckd_S)_ckd_S1 : (_ckd_S)*_ckd_res < (_ckd_S)_ckd_S1;
}

_ckd_fchpnt(3) bool _ckd_sub_sss_llong(_ckd_U _ckd_S1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 - _ckd_S2;
	return (_ckd_S1 ^ _ckd_S2) & ~(*_ckd_res ^ _ckd_S2) & _ckd_sign;
}

_ckd_fchpnt(3) bool _ckd_add_uuu_llong(_ckd_U _ckd_U1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_U1 + _ckd_U2;
	return *_ckd_res < _ckd_U1;
}

_ckd_fchpnt(3) bool _ckd_sub_uuu_llong(_ckd_U _ckd_U1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_U1 - _ckd_U2;
	return *_ckd_res > _ckd_U1;
}

_ckd_fchpnt(3) bool _ckd_add_sus_llong(_ckd_U _ckd_S1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 + _ckd_U2;
	return (*_ckd_res ^ _ckd_sign) < _ckd_U2;
}

_ckd_fchpnt(3) bool _ckd_add_suu_llong(_ckd_U _ckd_S1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 + _ckd_U2;
	_ckd_S1 += _ckd_sign;
	return (*_ckd_res ^ _ckd_U2) & ~(_ckd_S1 ^ _ckd_U2) & _ckd_sign;
}

_ckd_fchpnt(3) bool _ckd_sub_sus_llong(_ckd_U _ckd_S1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 - _ckd_U2;
	return _ckd_U2 > ((_ckd_U)_ckd_S1 ^ _ckd_sign);
}

_ckd_fchpnt(3) bool _ckd_sub_suu_llong(_ckd_U _ckd_S1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 - _ckd_U2;
	return (_ckd_S)_ckd_S1 < 0 || _ckd_U2 > _ckd_S1;
}

_ckd_fchpnt(3) bool _ckd_sub_uss_llong(_ckd_U _ckd_U1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_U1 - _ckd_S2;
	return _ckd_U1 >= (_ckd_S2 ^ _ckd_sign);
}

_ckd_fchpnt(3) bool _ckd_sub_usu_llong(_ckd_U _ckd_U1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	const _ckd_U _T1 = _ckd_U1 ^ _ckd_sign;
	const _ckd_U _T2 = _T1 - _ckd_S2;
	*_ckd_res = _T2 ^ _ckd_sign;
	return (_ckd_S)_ckd_S2 < 0 ? (_ckd_S)_T2 < (_ckd_S)_T1 : (_ckd_S)_T2 > (_ckd_S)_T1;
}

_ckd_fchpnt(3) bool _ckd_add_ssu_llong(_ckd_U _ckd_S1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 + _ckd_S2;
	return (_ckd_S)_ckd_S2 < 0 ? ((_ckd_S)(_ckd_S1 | *_ckd_res) < 0) : ((_ckd_S)(_ckd_S1 & *_ckd_res) < 0);
}

_ckd_fchpnt(3) bool _ckd_add_uus_llong(_ckd_U _ckd_U1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_U1 + _ckd_U2;
	return *_ckd_res < _ckd_U2 || (_ckd_S)*_ckd_res < 0;
}

_ckd_fchpnt(3) bool _ckd_sub_uus_llong(_ckd_U _ckd_U1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_U1 - _ckd_U2;
	return _ckd_U1 >= _ckd_U2 ? (_ckd_S)*_ckd_res < 0 : (_ckd_S)*_ckd_res >= 0;
}

_ckd_fchpnt(3) bool _ckd_sub_ssu_llong(_ckd_U _ckd_S1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 - _ckd_S2;
	return (_ckd_S)_ckd_S2 >= 0 ? ((_ckd_S)(_ckd_S1 | *_ckd_res) < 0) : ((_ckd_S)(_ckd_S1 & *_ckd_res) < 0);
}

_ckd_fchpnt(3) bool _ckd_add_uss_llong(_ckd_U _ckd_U1, _ckd_U _ckd_S1, _ckd_U *_ckd_res) {
	return _ckd_add_sus_llong(_ckd_S1, _ckd_U1, _ckd_res);
}

_ckd_fchpnt(3) bool _ckd_add_usu_llong(_ckd_U _ckd_U1, _ckd_U _ckd_S1, _ckd_U *_ckd_res) {
	return _ckd_add_suu_llong(_ckd_S1, _ckd_U1, _ckd_res);
}

// ]]]
// Multiplication [[[

_ckd_fconst bool _ckd_ovf_signed_llong(_ckd_S _ckd_a, _ckd_S _ckd_b) {
	return _ckd_a > 0 ?
			_ckd_b > 0 ?
				(_ckd_a > LLONG_MAX / _ckd_b) :
				(_ckd_b < LLONG_MIN / _ckd_a) :
			_ckd_b > 0 ?
				(_ckd_a < LLONG_MIN / _ckd_b) :
				(_ckd_a != 0 && _ckd_b < LLONG_MAX / _ckd_a);
}

_ckd_fconst bool _ckd_ovf_unsigned_llong(_ckd_U _ckd_a, _ckd_U _ckd_b) {
	return _ckd_a != 0 && _ckd_b > ULLONG_MAX / _ckd_a;
}


_ckd_fchpnt(3) bool _ckd_mul_sss_llong(_ckd_U _ckd_S1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 * _ckd_S2;
	return _ckd_ovf_signed_llong(_ckd_S1, _ckd_S2);
}

_ckd_fchpnt(3) bool _ckd_mul_uuu_llong(_ckd_U _ckd_U1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_U1 * _ckd_U2;
	return _ckd_ovf_unsigned_llong(_ckd_U1, _ckd_U2);
}

_ckd_fchpnt(3) bool _ckd_mul_suu_llong(_ckd_U _ckd_S1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 * _ckd_U2;
	return ((_ckd_S) _ckd_S1 < 0 && _ckd_U2) || _ckd_ovf_unsigned_llong(_ckd_S1, _ckd_U2);
}

_ckd_fchpnt(3) bool _ckd_mul_uus_llong(_ckd_U _ckd_U1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_U1 * _ckd_U2;
	return (_ckd_S)*_ckd_res < 0 || _ckd_ovf_unsigned_llong(_ckd_U1, _ckd_U2);
}

_ckd_fchpnt(3) bool _ckd_mul_sus_llong(_ckd_U _ckd_S1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 * _ckd_U2;
	return (_ckd_S)_ckd_U2 >= 0 ? _ckd_ovf_signed_llong(_ckd_S1, _ckd_U2) : (_ckd_S1 && ((_ckd_S)_ckd_S1 != -1 || _ckd_U2 != *_ckd_res));
}

_ckd_fchpnt(3) bool _ckd_mul_ssu_llong(_ckd_U _ckd_S1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	const _ckd_U _T1 = (_ckd_S)(_ckd_S1 & _ckd_S2) < 0 ? (-_ckd_S1) : _ckd_S1;
	const _ckd_U _T2 = (_ckd_S)(_ckd_S1 & _ckd_S2) < 0 ? (-_ckd_S2) : _ckd_S2;
	*_ckd_res = _T1 * _T2;
	return (_ckd_S)(_ckd_S1 ^ _ckd_S2) < 0 ? (_ckd_S1 && _ckd_S2) : _ckd_ovf_signed_llong(_T1, _T2);
}

_ckd_fchpnt(3) bool _ckd_mul_uss_llong(_ckd_U _ckd_U1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	return _ckd_mul_sus_llong(_ckd_S2, _ckd_U1, _ckd_res);
}

_ckd_fchpnt(3) bool _ckd_mul_usu_llong(_ckd_U _ckd_U1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	return _ckd_mul_suu_llong(_ckd_S2, _ckd_U1, _ckd_res);
}

/* ------------------------------------------------------------------------- */


_ckd_fchpnt(5) bool _ckd_add_llong_choose_s(bool _ckd_asigned, bool _ckd_bsigned,
		_ckd_U _ckd_a, _ckd_U _ckd_b, _ckd_U *_ckd_res) {
	if (_ckd_asigned) {
		if (_ckd_bsigned) {
			return _ckd_add_sss_llong(_ckd_a, _ckd_b, _ckd_res);
		}
		return _ckd_add_sus_llong(_ckd_a, _ckd_b, _ckd_res);
	} else if (_ckd_bsigned) {
		return _ckd_add_uss_llong(_ckd_a, _ckd_b, _ckd_res);
	}
	return _ckd_add_uus_llong(_ckd_a, _ckd_b, _ckd_res);
}

_ckd_fchpnt(5) bool _ckd_add_llong_choose_u(bool _ckd_asigned, bool _ckd_bsigned,
		_ckd_U _ckd_a, _ckd_U _ckd_b, _ckd_U *_ckd_res) {
	if (_ckd_asigned) {
		if (_ckd_bsigned) {
			return _ckd_add_ssu_llong(_ckd_a, _ckd_b, _ckd_res);
		}
		return _ckd_add_suu_llong(_ckd_a, _ckd_b, _ckd_res);
	} else if (_ckd_bsigned) {
		return _ckd_add_usu_llong(_ckd_a, _ckd_b, _ckd_res);
	}
	return _ckd_add_uuu_llong(_ckd_a, _ckd_b, _ckd_res);
}

_ckd_fconst ckd_llong_t _ckd_add_2_llong(_ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	ckd_llong_t _ckd_tmp;
	unsigned long long _ckd_utmp;
	ckd_overflow(_ckd_tmp) = _ckd_add_llong_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_utmp)
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	ckd_value(_ckd_tmp) = _ckd_utmp;
	return _ckd_tmp;
}

_ckd_fconst ckd_ullong_t _ckd_add_2_ullong(_ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	ckd_ullong_t _ckd_tmp;
	ckd_overflow(_ckd_tmp) = _ckd_add_llong_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &ckd_value(_ckd_tmp))
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	return _ckd_tmp;
}

_ckd_fchpnt(1) bool _ckd_add_3_ullong_to_char(char *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
#if CHAR_MAX == SCHAR_MAX
		_ckd_add_llong_choose_s(
#else
		_ckd_add_llong_choose_u(
#endif
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) CHAR_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_ullong_to_schar(signed char *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_llong_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) SCHAR_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (signed char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_ullong_to_uchar(unsigned char *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_llong_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if ULLONG_MAX > UCHAR_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) UCHAR_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_ullong_to_shrt(short *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_llong_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) SHRT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (short) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_ullong_to_ushrt(unsigned short *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_llong_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if ULLONG_MAX > USHRT_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) USHRT_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned short) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_ullong_to_int(int *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_llong_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) INT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (int) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_ullong_to_uint(unsigned int *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_llong_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if ULLONG_MAX > UINT_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) UINT_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned int) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_ullong_to_long(long *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_llong_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) LONG_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (long) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_ullong_to_ulong(unsigned long *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_llong_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if ULLONG_MAX > ULONG_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) ULONG_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned long) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_ullong_to_llong(long long *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_llong_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) LLONG_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (long long) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_ullong_to_ullong(unsigned long long *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_llong_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if ULLONG_MAX > ULLONG_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) ULLONG_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned long long) _ckd_tmp;
	return _ckd_of;
}


_ckd_fchpnt(5) bool _ckd_sub_llong_choose_s(bool _ckd_asigned, bool _ckd_bsigned,
		_ckd_U _ckd_a, _ckd_U _ckd_b, _ckd_U *_ckd_res) {
	if (_ckd_asigned) {
		if (_ckd_bsigned) {
			return _ckd_sub_sss_llong(_ckd_a, _ckd_b, _ckd_res);
		}
		return _ckd_sub_sus_llong(_ckd_a, _ckd_b, _ckd_res);
	} else if (_ckd_bsigned) {
		return _ckd_sub_uss_llong(_ckd_a, _ckd_b, _ckd_res);
	}
	return _ckd_sub_uus_llong(_ckd_a, _ckd_b, _ckd_res);
}

_ckd_fchpnt(5) bool _ckd_sub_llong_choose_u(bool _ckd_asigned, bool _ckd_bsigned,
		_ckd_U _ckd_a, _ckd_U _ckd_b, _ckd_U *_ckd_res) {
	if (_ckd_asigned) {
		if (_ckd_bsigned) {
			return _ckd_sub_ssu_llong(_ckd_a, _ckd_b, _ckd_res);
		}
		return _ckd_sub_suu_llong(_ckd_a, _ckd_b, _ckd_res);
	} else if (_ckd_bsigned) {
		return _ckd_sub_usu_llong(_ckd_a, _ckd_b, _ckd_res);
	}
	return _ckd_sub_uuu_llong(_ckd_a, _ckd_b, _ckd_res);
}

_ckd_fconst ckd_llong_t _ckd_sub_2_llong(_ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	ckd_llong_t _ckd_tmp;
	unsigned long long _ckd_utmp;
	ckd_overflow(_ckd_tmp) = _ckd_sub_llong_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_utmp)
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	ckd_value(_ckd_tmp) = _ckd_utmp;
	return _ckd_tmp;
}

_ckd_fconst ckd_ullong_t _ckd_sub_2_ullong(_ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	ckd_ullong_t _ckd_tmp;
	ckd_overflow(_ckd_tmp) = _ckd_sub_llong_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &ckd_value(_ckd_tmp))
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	return _ckd_tmp;
}

_ckd_fchpnt(1) bool _ckd_sub_3_ullong_to_char(char *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
#if CHAR_MAX == SCHAR_MAX
		_ckd_sub_llong_choose_s(
#else
		_ckd_sub_llong_choose_u(
#endif
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) CHAR_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_ullong_to_schar(signed char *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_llong_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) SCHAR_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (signed char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_ullong_to_uchar(unsigned char *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_llong_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if ULLONG_MAX > UCHAR_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) UCHAR_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_ullong_to_shrt(short *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_llong_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) SHRT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (short) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_ullong_to_ushrt(unsigned short *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_llong_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if ULLONG_MAX > USHRT_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) USHRT_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned short) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_ullong_to_int(int *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_llong_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) INT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (int) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_ullong_to_uint(unsigned int *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_llong_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if ULLONG_MAX > UINT_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) UINT_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned int) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_ullong_to_long(long *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_llong_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) LONG_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (long) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_ullong_to_ulong(unsigned long *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_llong_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if ULLONG_MAX > ULONG_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) ULONG_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned long) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_ullong_to_llong(long long *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_llong_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) LLONG_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (long long) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_ullong_to_ullong(unsigned long long *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_llong_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if ULLONG_MAX > ULLONG_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) ULLONG_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned long long) _ckd_tmp;
	return _ckd_of;
}


_ckd_fchpnt(5) bool _ckd_mul_llong_choose_s(bool _ckd_asigned, bool _ckd_bsigned,
		_ckd_U _ckd_a, _ckd_U _ckd_b, _ckd_U *_ckd_res) {
	if (_ckd_asigned) {
		if (_ckd_bsigned) {
			return _ckd_mul_sss_llong(_ckd_a, _ckd_b, _ckd_res);
		}
		return _ckd_mul_sus_llong(_ckd_a, _ckd_b, _ckd_res);
	} else if (_ckd_bsigned) {
		return _ckd_mul_uss_llong(_ckd_a, _ckd_b, _ckd_res);
	}
	return _ckd_mul_uus_llong(_ckd_a, _ckd_b, _ckd_res);
}

_ckd_fchpnt(5) bool _ckd_mul_llong_choose_u(bool _ckd_asigned, bool _ckd_bsigned,
		_ckd_U _ckd_a, _ckd_U _ckd_b, _ckd_U *_ckd_res) {
	if (_ckd_asigned) {
		if (_ckd_bsigned) {
			return _ckd_mul_ssu_llong(_ckd_a, _ckd_b, _ckd_res);
		}
		return _ckd_mul_suu_llong(_ckd_a, _ckd_b, _ckd_res);
	} else if (_ckd_bsigned) {
		return _ckd_mul_usu_llong(_ckd_a, _ckd_b, _ckd_res);
	}
	return _ckd_mul_uuu_llong(_ckd_a, _ckd_b, _ckd_res);
}

_ckd_fconst ckd_llong_t _ckd_mul_2_llong(_ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	ckd_llong_t _ckd_tmp;
	unsigned long long _ckd_utmp;
	ckd_overflow(_ckd_tmp) = _ckd_mul_llong_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_utmp)
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	ckd_value(_ckd_tmp) = _ckd_utmp;
	return _ckd_tmp;
}

_ckd_fconst ckd_ullong_t _ckd_mul_2_ullong(_ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	ckd_ullong_t _ckd_tmp;
	ckd_overflow(_ckd_tmp) = _ckd_mul_llong_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &ckd_value(_ckd_tmp))
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	return _ckd_tmp;
}

_ckd_fchpnt(1) bool _ckd_mul_3_ullong_to_char(char *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
#if CHAR_MAX == SCHAR_MAX
		_ckd_mul_llong_choose_s(
#else
		_ckd_mul_llong_choose_u(
#endif
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) CHAR_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_ullong_to_schar(signed char *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_llong_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) SCHAR_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (signed char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_ullong_to_uchar(unsigned char *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_llong_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if ULLONG_MAX > UCHAR_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) UCHAR_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_ullong_to_shrt(short *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_llong_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) SHRT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (short) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_ullong_to_ushrt(unsigned short *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_llong_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if ULLONG_MAX > USHRT_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) USHRT_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned short) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_ullong_to_int(int *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_llong_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) INT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (int) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_ullong_to_uint(unsigned int *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_llong_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if ULLONG_MAX > UINT_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) UINT_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned int) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_ullong_to_long(long *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_llong_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) LONG_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (long) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_ullong_to_ulong(unsigned long *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_llong_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if ULLONG_MAX > ULONG_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) ULONG_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned long) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_ullong_to_llong(long long *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_llong_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) LLONG_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (long long) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_ullong_to_ullong(unsigned long long *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	unsigned long long _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_llong_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
#if ULLONG_MAX > ULLONG_MAX
			|| (_ckd_U) _ckd_tmp > (_ckd_U) ULLONG_MAX
#endif
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned long long) _ckd_tmp;
	return _ckd_of;
}


// ]]]
// Undef macros [[[
#undef _ckd_S
#undef _ckd_U
#undef _ckd_sign
// ]]]
// Init macros [[[
// Signed minimum and maximum!
#define _ckd_S    __int128
#define _ckd_U    unsigned __int128
#define _ckd_sign  ((_ckd_U)1 << (sizeof(_ckd_U) * CHAR_BIT - 1))
// ]]]
// Addition and substraction operations [[[

_ckd_fchpnt(3) bool _ckd_add_sss_int128(_ckd_U _ckd_S1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 + _ckd_S2;
	return (_ckd_S)_ckd_S2 < 0 ? (_ckd_S)*_ckd_res > (_ckd_S)_ckd_S1 : (_ckd_S)*_ckd_res < (_ckd_S)_ckd_S1;
}

_ckd_fchpnt(3) bool _ckd_sub_sss_int128(_ckd_U _ckd_S1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 - _ckd_S2;
	return (_ckd_S1 ^ _ckd_S2) & ~(*_ckd_res ^ _ckd_S2) & _ckd_sign;
}

_ckd_fchpnt(3) bool _ckd_add_uuu_int128(_ckd_U _ckd_U1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_U1 + _ckd_U2;
	return *_ckd_res < _ckd_U1;
}

_ckd_fchpnt(3) bool _ckd_sub_uuu_int128(_ckd_U _ckd_U1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_U1 - _ckd_U2;
	return *_ckd_res > _ckd_U1;
}

_ckd_fchpnt(3) bool _ckd_add_sus_int128(_ckd_U _ckd_S1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 + _ckd_U2;
	return (*_ckd_res ^ _ckd_sign) < _ckd_U2;
}

_ckd_fchpnt(3) bool _ckd_add_suu_int128(_ckd_U _ckd_S1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 + _ckd_U2;
	_ckd_S1 += _ckd_sign;
	return (*_ckd_res ^ _ckd_U2) & ~(_ckd_S1 ^ _ckd_U2) & _ckd_sign;
}

_ckd_fchpnt(3) bool _ckd_sub_sus_int128(_ckd_U _ckd_S1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 - _ckd_U2;
	return _ckd_U2 > ((_ckd_U)_ckd_S1 ^ _ckd_sign);
}

_ckd_fchpnt(3) bool _ckd_sub_suu_int128(_ckd_U _ckd_S1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 - _ckd_U2;
	return (_ckd_S)_ckd_S1 < 0 || _ckd_U2 > _ckd_S1;
}

_ckd_fchpnt(3) bool _ckd_sub_uss_int128(_ckd_U _ckd_U1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_U1 - _ckd_S2;
	return _ckd_U1 >= (_ckd_S2 ^ _ckd_sign);
}

_ckd_fchpnt(3) bool _ckd_sub_usu_int128(_ckd_U _ckd_U1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	const _ckd_U _T1 = _ckd_U1 ^ _ckd_sign;
	const _ckd_U _T2 = _T1 - _ckd_S2;
	*_ckd_res = _T2 ^ _ckd_sign;
	return (_ckd_S)_ckd_S2 < 0 ? (_ckd_S)_T2 < (_ckd_S)_T1 : (_ckd_S)_T2 > (_ckd_S)_T1;
}

_ckd_fchpnt(3) bool _ckd_add_ssu_int128(_ckd_U _ckd_S1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 + _ckd_S2;
	return (_ckd_S)_ckd_S2 < 0 ? ((_ckd_S)(_ckd_S1 | *_ckd_res) < 0) : ((_ckd_S)(_ckd_S1 & *_ckd_res) < 0);
}

_ckd_fchpnt(3) bool _ckd_add_uus_int128(_ckd_U _ckd_U1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_U1 + _ckd_U2;
	return *_ckd_res < _ckd_U2 || (_ckd_S)*_ckd_res < 0;
}

_ckd_fchpnt(3) bool _ckd_sub_uus_int128(_ckd_U _ckd_U1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_U1 - _ckd_U2;
	return _ckd_U1 >= _ckd_U2 ? (_ckd_S)*_ckd_res < 0 : (_ckd_S)*_ckd_res >= 0;
}

_ckd_fchpnt(3) bool _ckd_sub_ssu_int128(_ckd_U _ckd_S1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 - _ckd_S2;
	return (_ckd_S)_ckd_S2 >= 0 ? ((_ckd_S)(_ckd_S1 | *_ckd_res) < 0) : ((_ckd_S)(_ckd_S1 & *_ckd_res) < 0);
}

_ckd_fchpnt(3) bool _ckd_add_uss_int128(_ckd_U _ckd_U1, _ckd_U _ckd_S1, _ckd_U *_ckd_res) {
	return _ckd_add_sus_int128(_ckd_S1, _ckd_U1, _ckd_res);
}

_ckd_fchpnt(3) bool _ckd_add_usu_int128(_ckd_U _ckd_U1, _ckd_U _ckd_S1, _ckd_U *_ckd_res) {
	return _ckd_add_suu_int128(_ckd_S1, _ckd_U1, _ckd_res);
}

// ]]]
// Multiplication [[[

_ckd_fconst bool _ckd_ovf_signed_int128(_ckd_S _ckd_a, _ckd_S _ckd_b) {
	return _ckd_a > 0 ?
			_ckd_b > 0 ?
				(_ckd_a > INT128_MAX / _ckd_b) :
				(_ckd_b < INT128_MIN / _ckd_a) :
			_ckd_b > 0 ?
				(_ckd_a < INT128_MIN / _ckd_b) :
				(_ckd_a != 0 && _ckd_b < INT128_MAX / _ckd_a);
}

_ckd_fconst bool _ckd_ovf_unsigned_int128(_ckd_U _ckd_a, _ckd_U _ckd_b) {
	return _ckd_a != 0 && _ckd_b > UINT128_MAX / _ckd_a;
}


_ckd_fchpnt(3) bool _ckd_mul_sss_int128(_ckd_U _ckd_S1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 * _ckd_S2;
	return _ckd_ovf_signed_int128(_ckd_S1, _ckd_S2);
}

_ckd_fchpnt(3) bool _ckd_mul_uuu_int128(_ckd_U _ckd_U1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_U1 * _ckd_U2;
	return _ckd_ovf_unsigned_int128(_ckd_U1, _ckd_U2);
}

_ckd_fchpnt(3) bool _ckd_mul_suu_int128(_ckd_U _ckd_S1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 * _ckd_U2;
	return ((_ckd_S) _ckd_S1 < 0 && _ckd_U2) || _ckd_ovf_unsigned_int128(_ckd_S1, _ckd_U2);
}

_ckd_fchpnt(3) bool _ckd_mul_uus_int128(_ckd_U _ckd_U1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_U1 * _ckd_U2;
	return (_ckd_S)*_ckd_res < 0 || _ckd_ovf_unsigned_int128(_ckd_U1, _ckd_U2);
}

_ckd_fchpnt(3) bool _ckd_mul_sus_int128(_ckd_U _ckd_S1, _ckd_U _ckd_U2, _ckd_U *_ckd_res) {
	*_ckd_res = _ckd_S1 * _ckd_U2;
	return (_ckd_S)_ckd_U2 >= 0 ? _ckd_ovf_signed_int128(_ckd_S1, _ckd_U2) : (_ckd_S1 && ((_ckd_S)_ckd_S1 != -1 || _ckd_U2 != *_ckd_res));
}

_ckd_fchpnt(3) bool _ckd_mul_ssu_int128(_ckd_U _ckd_S1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	const _ckd_U _T1 = (_ckd_S)(_ckd_S1 & _ckd_S2) < 0 ? (-_ckd_S1) : _ckd_S1;
	const _ckd_U _T2 = (_ckd_S)(_ckd_S1 & _ckd_S2) < 0 ? (-_ckd_S2) : _ckd_S2;
	*_ckd_res = _T1 * _T2;
	return (_ckd_S)(_ckd_S1 ^ _ckd_S2) < 0 ? (_ckd_S1 && _ckd_S2) : _ckd_ovf_signed_int128(_T1, _T2);
}

_ckd_fchpnt(3) bool _ckd_mul_uss_int128(_ckd_U _ckd_U1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	return _ckd_mul_sus_int128(_ckd_S2, _ckd_U1, _ckd_res);
}

_ckd_fchpnt(3) bool _ckd_mul_usu_int128(_ckd_U _ckd_U1, _ckd_U _ckd_S2, _ckd_U *_ckd_res) {
	return _ckd_mul_suu_int128(_ckd_S2, _ckd_U1, _ckd_res);
}

/* ------------------------------------------------------------------------- */


_ckd_fchpnt(5) bool _ckd_add_int128_choose_s(bool _ckd_asigned, bool _ckd_bsigned,
		_ckd_U _ckd_a, _ckd_U _ckd_b, _ckd_U *_ckd_res) {
	if (_ckd_asigned) {
		if (_ckd_bsigned) {
			return _ckd_add_sss_int128(_ckd_a, _ckd_b, _ckd_res);
		}
		return _ckd_add_sus_int128(_ckd_a, _ckd_b, _ckd_res);
	} else if (_ckd_bsigned) {
		return _ckd_add_uss_int128(_ckd_a, _ckd_b, _ckd_res);
	}
	return _ckd_add_uus_int128(_ckd_a, _ckd_b, _ckd_res);
}

_ckd_fchpnt(5) bool _ckd_add_int128_choose_u(bool _ckd_asigned, bool _ckd_bsigned,
		_ckd_U _ckd_a, _ckd_U _ckd_b, _ckd_U *_ckd_res) {
	if (_ckd_asigned) {
		if (_ckd_bsigned) {
			return _ckd_add_ssu_int128(_ckd_a, _ckd_b, _ckd_res);
		}
		return _ckd_add_suu_int128(_ckd_a, _ckd_b, _ckd_res);
	} else if (_ckd_bsigned) {
		return _ckd_add_usu_int128(_ckd_a, _ckd_b, _ckd_res);
	}
	return _ckd_add_uuu_int128(_ckd_a, _ckd_b, _ckd_res);
}

_ckd_fconst ckd_int128_t _ckd_add_2_int128(_ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	ckd_int128_t _ckd_tmp;
	unsigned __int128 _ckd_utmp;
	ckd_overflow(_ckd_tmp) = _ckd_add_int128_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_utmp)
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	ckd_value(_ckd_tmp) = _ckd_utmp;
	return _ckd_tmp;
}

_ckd_fconst ckd_uint128_t _ckd_add_2_uint128(_ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	ckd_uint128_t _ckd_tmp;
	ckd_overflow(_ckd_tmp) = _ckd_add_int128_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &ckd_value(_ckd_tmp))
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	return _ckd_tmp;
}

_ckd_fchpnt(1) bool _ckd_add_3_uint128_to_char(char *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
#if CHAR_MAX == SCHAR_MAX
		_ckd_add_int128_choose_s(
#else
		_ckd_add_int128_choose_u(
#endif
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) CHAR_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_uint128_to_schar(signed char *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_int128_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) SCHAR_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (signed char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_uint128_to_uchar(unsigned char *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_int128_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) UCHAR_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_uint128_to_shrt(short *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_int128_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) SHRT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (short) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_uint128_to_ushrt(unsigned short *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_int128_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) USHRT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned short) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_uint128_to_int(int *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_int128_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) INT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (int) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_uint128_to_uint(unsigned int *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_int128_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) UINT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned int) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_uint128_to_long(long *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_int128_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) LONG_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (long) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_uint128_to_ulong(unsigned long *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_int128_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) ULONG_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned long) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_uint128_to_llong(long long *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_int128_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) LLONG_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (long long) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_uint128_to_ullong(unsigned long long *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_int128_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) ULLONG_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned long long) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_uint128_to_int128(__int128 *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_int128_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) INT128_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (__int128) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_add_3_uint128_to_uint128(unsigned __int128 *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_add_int128_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) UINT128_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned __int128) _ckd_tmp;
	return _ckd_of;
}


_ckd_fchpnt(5) bool _ckd_sub_int128_choose_s(bool _ckd_asigned, bool _ckd_bsigned,
		_ckd_U _ckd_a, _ckd_U _ckd_b, _ckd_U *_ckd_res) {
	if (_ckd_asigned) {
		if (_ckd_bsigned) {
			return _ckd_sub_sss_int128(_ckd_a, _ckd_b, _ckd_res);
		}
		return _ckd_sub_sus_int128(_ckd_a, _ckd_b, _ckd_res);
	} else if (_ckd_bsigned) {
		return _ckd_sub_uss_int128(_ckd_a, _ckd_b, _ckd_res);
	}
	return _ckd_sub_uus_int128(_ckd_a, _ckd_b, _ckd_res);
}

_ckd_fchpnt(5) bool _ckd_sub_int128_choose_u(bool _ckd_asigned, bool _ckd_bsigned,
		_ckd_U _ckd_a, _ckd_U _ckd_b, _ckd_U *_ckd_res) {
	if (_ckd_asigned) {
		if (_ckd_bsigned) {
			return _ckd_sub_ssu_int128(_ckd_a, _ckd_b, _ckd_res);
		}
		return _ckd_sub_suu_int128(_ckd_a, _ckd_b, _ckd_res);
	} else if (_ckd_bsigned) {
		return _ckd_sub_usu_int128(_ckd_a, _ckd_b, _ckd_res);
	}
	return _ckd_sub_uuu_int128(_ckd_a, _ckd_b, _ckd_res);
}

_ckd_fconst ckd_int128_t _ckd_sub_2_int128(_ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	ckd_int128_t _ckd_tmp;
	unsigned __int128 _ckd_utmp;
	ckd_overflow(_ckd_tmp) = _ckd_sub_int128_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_utmp)
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	ckd_value(_ckd_tmp) = _ckd_utmp;
	return _ckd_tmp;
}

_ckd_fconst ckd_uint128_t _ckd_sub_2_uint128(_ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	ckd_uint128_t _ckd_tmp;
	ckd_overflow(_ckd_tmp) = _ckd_sub_int128_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &ckd_value(_ckd_tmp))
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	return _ckd_tmp;
}

_ckd_fchpnt(1) bool _ckd_sub_3_uint128_to_char(char *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
#if CHAR_MAX == SCHAR_MAX
		_ckd_sub_int128_choose_s(
#else
		_ckd_sub_int128_choose_u(
#endif
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) CHAR_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint128_to_schar(signed char *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_int128_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) SCHAR_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (signed char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint128_to_uchar(unsigned char *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_int128_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) UCHAR_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint128_to_shrt(short *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_int128_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) SHRT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (short) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint128_to_ushrt(unsigned short *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_int128_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) USHRT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned short) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint128_to_int(int *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_int128_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) INT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (int) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint128_to_uint(unsigned int *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_int128_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) UINT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned int) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint128_to_long(long *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_int128_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) LONG_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (long) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint128_to_ulong(unsigned long *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_int128_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) ULONG_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned long) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint128_to_llong(long long *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_int128_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) LLONG_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (long long) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint128_to_ullong(unsigned long long *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_int128_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) ULLONG_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned long long) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint128_to_int128(__int128 *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_int128_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) INT128_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (__int128) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint128_to_uint128(unsigned __int128 *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_sub_int128_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) UINT128_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned __int128) _ckd_tmp;
	return _ckd_of;
}


_ckd_fchpnt(5) bool _ckd_mul_int128_choose_s(bool _ckd_asigned, bool _ckd_bsigned,
		_ckd_U _ckd_a, _ckd_U _ckd_b, _ckd_U *_ckd_res) {
	if (_ckd_asigned) {
		if (_ckd_bsigned) {
			return _ckd_mul_sss_int128(_ckd_a, _ckd_b, _ckd_res);
		}
		return _ckd_mul_sus_int128(_ckd_a, _ckd_b, _ckd_res);
	} else if (_ckd_bsigned) {
		return _ckd_mul_uss_int128(_ckd_a, _ckd_b, _ckd_res);
	}
	return _ckd_mul_uus_int128(_ckd_a, _ckd_b, _ckd_res);
}

_ckd_fchpnt(5) bool _ckd_mul_int128_choose_u(bool _ckd_asigned, bool _ckd_bsigned,
		_ckd_U _ckd_a, _ckd_U _ckd_b, _ckd_U *_ckd_res) {
	if (_ckd_asigned) {
		if (_ckd_bsigned) {
			return _ckd_mul_ssu_int128(_ckd_a, _ckd_b, _ckd_res);
		}
		return _ckd_mul_suu_int128(_ckd_a, _ckd_b, _ckd_res);
	} else if (_ckd_bsigned) {
		return _ckd_mul_usu_int128(_ckd_a, _ckd_b, _ckd_res);
	}
	return _ckd_mul_uuu_int128(_ckd_a, _ckd_b, _ckd_res);
}

_ckd_fconst ckd_int128_t _ckd_mul_2_int128(_ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	ckd_int128_t _ckd_tmp;
	unsigned __int128 _ckd_utmp;
	ckd_overflow(_ckd_tmp) = _ckd_mul_int128_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_utmp)
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	ckd_value(_ckd_tmp) = _ckd_utmp;
	return _ckd_tmp;
}

_ckd_fconst ckd_uint128_t _ckd_mul_2_uint128(_ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	ckd_uint128_t _ckd_tmp;
	ckd_overflow(_ckd_tmp) = _ckd_mul_int128_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &ckd_value(_ckd_tmp))
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	return _ckd_tmp;
}

_ckd_fchpnt(1) bool _ckd_mul_3_uint128_to_char(char *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
#if CHAR_MAX == SCHAR_MAX
		_ckd_mul_int128_choose_s(
#else
		_ckd_mul_int128_choose_u(
#endif
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) CHAR_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint128_to_schar(signed char *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_int128_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) SCHAR_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (signed char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint128_to_uchar(unsigned char *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_int128_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) UCHAR_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned char) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint128_to_shrt(short *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_int128_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) SHRT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (short) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint128_to_ushrt(unsigned short *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_int128_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) USHRT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned short) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint128_to_int(int *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_int128_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) INT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (int) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint128_to_uint(unsigned int *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_int128_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) UINT_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned int) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint128_to_long(long *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_int128_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) LONG_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (long) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint128_to_ulong(unsigned long *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_int128_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) ULONG_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned long) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint128_to_llong(long long *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_int128_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) LLONG_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (long long) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint128_to_ullong(unsigned long long *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_int128_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) ULLONG_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned long long) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint128_to_int128(__int128 *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_int128_choose_s(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) INT128_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (__int128) _ckd_tmp;
	return _ckd_of;
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint128_to_uint128(unsigned __int128 *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	unsigned __int128 _ckd_tmp;
	const bool _ckd_of =
		_ckd_mul_int128_choose_u(
			_ckd_a._ckd_Signed, _ckd_b._ckd_Signed, _ckd_a._ckd_Value, _ckd_b._ckd_Value, &_ckd_tmp)
			|| (_ckd_U) _ckd_tmp > (_ckd_U) UINT128_MAX
			|| _ckd_a._ckd_Overflow || _ckd_b._ckd_Overflow;
	*_ckd_ret = (unsigned __int128) _ckd_tmp;
	return _ckd_of;
}


// ]]]
// Undef macros [[[
#undef _ckd_S
#undef _ckd_U
#undef _ckd_sign
// ]]]
// Additional 3 argument conversions [[[
_ckd_fchpnt(1) bool _ckd_add_3_uint_to_cchar(ckd_char_t *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_uint_to_char(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_uint_to_cschar(ckd_schar_t *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_uint_to_schar(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_uint_to_cuchar(ckd_uchar_t *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_uint_to_uchar(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_uint_to_cshrt(ckd_shrt_t *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_uint_to_shrt(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_uint_to_cushrt(ckd_ushrt_t *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_uint_to_ushrt(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_uint_to_cint(ckd_int_t *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_uint_to_int(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_uint_to_cuint(ckd_uint_t *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_uint_to_uint(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_ulong_to_cchar(ckd_char_t *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_ulong_to_char(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_ulong_to_cschar(ckd_schar_t *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_ulong_to_schar(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_ulong_to_cuchar(ckd_uchar_t *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_ulong_to_uchar(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_ulong_to_cshrt(ckd_shrt_t *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_ulong_to_shrt(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_ulong_to_cushrt(ckd_ushrt_t *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_ulong_to_ushrt(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_ulong_to_cint(ckd_int_t *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_ulong_to_int(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_ulong_to_cuint(ckd_uint_t *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_ulong_to_uint(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_ulong_to_clong(ckd_long_t *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_ulong_to_long(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_ulong_to_culong(ckd_ulong_t *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_ulong_to_ulong(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_ullong_to_cchar(ckd_char_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_ullong_to_char(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_ullong_to_cschar(ckd_schar_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_ullong_to_schar(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_ullong_to_cuchar(ckd_uchar_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_ullong_to_uchar(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_ullong_to_cshrt(ckd_shrt_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_ullong_to_shrt(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_ullong_to_cushrt(ckd_ushrt_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_ullong_to_ushrt(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_ullong_to_cint(ckd_int_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_ullong_to_int(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_ullong_to_cuint(ckd_uint_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_ullong_to_uint(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_ullong_to_clong(ckd_long_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_ullong_to_long(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_ullong_to_culong(ckd_ulong_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_ullong_to_ulong(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_ullong_to_cllong(ckd_llong_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_ullong_to_llong(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_ullong_to_cullong(ckd_ullong_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_ullong_to_ullong(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_uint128_to_cchar(ckd_char_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_uint128_to_char(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_uint128_to_cschar(ckd_schar_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_uint128_to_schar(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_uint128_to_cuchar(ckd_uchar_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_uint128_to_uchar(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_uint128_to_cshrt(ckd_shrt_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_uint128_to_shrt(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_uint128_to_cushrt(ckd_ushrt_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_uint128_to_ushrt(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_uint128_to_cint(ckd_int_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_uint128_to_int(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_uint128_to_cuint(ckd_uint_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_uint128_to_uint(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_uint128_to_clong(ckd_long_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_uint128_to_long(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_uint128_to_culong(ckd_ulong_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_uint128_to_ulong(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_uint128_to_cllong(ckd_llong_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_uint128_to_llong(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_uint128_to_cullong(ckd_ullong_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_uint128_to_ullong(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_uint128_to_cint128(ckd_int128_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_uint128_to_int128(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_add_3_uint128_to_cuint128(ckd_uint128_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_add_3_uint128_to_uint128(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint_to_cchar(ckd_char_t *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_uint_to_char(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint_to_cschar(ckd_schar_t *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_uint_to_schar(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint_to_cuchar(ckd_uchar_t *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_uint_to_uchar(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint_to_cshrt(ckd_shrt_t *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_uint_to_shrt(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint_to_cushrt(ckd_ushrt_t *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_uint_to_ushrt(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint_to_cint(ckd_int_t *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_uint_to_int(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint_to_cuint(ckd_uint_t *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_uint_to_uint(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_ulong_to_cchar(ckd_char_t *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_ulong_to_char(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_ulong_to_cschar(ckd_schar_t *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_ulong_to_schar(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_ulong_to_cuchar(ckd_uchar_t *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_ulong_to_uchar(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_ulong_to_cshrt(ckd_shrt_t *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_ulong_to_shrt(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_ulong_to_cushrt(ckd_ushrt_t *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_ulong_to_ushrt(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_ulong_to_cint(ckd_int_t *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_ulong_to_int(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_ulong_to_cuint(ckd_uint_t *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_ulong_to_uint(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_ulong_to_clong(ckd_long_t *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_ulong_to_long(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_ulong_to_culong(ckd_ulong_t *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_ulong_to_ulong(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_ullong_to_cchar(ckd_char_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_ullong_to_char(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_ullong_to_cschar(ckd_schar_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_ullong_to_schar(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_ullong_to_cuchar(ckd_uchar_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_ullong_to_uchar(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_ullong_to_cshrt(ckd_shrt_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_ullong_to_shrt(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_ullong_to_cushrt(ckd_ushrt_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_ullong_to_ushrt(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_ullong_to_cint(ckd_int_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_ullong_to_int(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_ullong_to_cuint(ckd_uint_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_ullong_to_uint(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_ullong_to_clong(ckd_long_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_ullong_to_long(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_ullong_to_culong(ckd_ulong_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_ullong_to_ulong(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_ullong_to_cllong(ckd_llong_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_ullong_to_llong(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_ullong_to_cullong(ckd_ullong_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_ullong_to_ullong(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint128_to_cchar(ckd_char_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_uint128_to_char(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint128_to_cschar(ckd_schar_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_uint128_to_schar(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint128_to_cuchar(ckd_uchar_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_uint128_to_uchar(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint128_to_cshrt(ckd_shrt_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_uint128_to_shrt(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint128_to_cushrt(ckd_ushrt_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_uint128_to_ushrt(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint128_to_cint(ckd_int_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_uint128_to_int(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint128_to_cuint(ckd_uint_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_uint128_to_uint(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint128_to_clong(ckd_long_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_uint128_to_long(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint128_to_culong(ckd_ulong_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_uint128_to_ulong(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint128_to_cllong(ckd_llong_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_uint128_to_llong(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint128_to_cullong(ckd_ullong_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_uint128_to_ullong(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint128_to_cint128(ckd_int128_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_uint128_to_int128(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_sub_3_uint128_to_cuint128(ckd_uint128_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_sub_3_uint128_to_uint128(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint_to_cchar(ckd_char_t *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_uint_to_char(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint_to_cschar(ckd_schar_t *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_uint_to_schar(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint_to_cuchar(ckd_uchar_t *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_uint_to_uchar(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint_to_cshrt(ckd_shrt_t *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_uint_to_shrt(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint_to_cushrt(ckd_ushrt_t *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_uint_to_ushrt(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint_to_cint(ckd_int_t *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_uint_to_int(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint_to_cuint(ckd_uint_t *_ckd_ret, _ckd_arg_uint _ckd_a, _ckd_arg_uint _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_uint_to_uint(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_ulong_to_cchar(ckd_char_t *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_ulong_to_char(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_ulong_to_cschar(ckd_schar_t *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_ulong_to_schar(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_ulong_to_cuchar(ckd_uchar_t *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_ulong_to_uchar(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_ulong_to_cshrt(ckd_shrt_t *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_ulong_to_shrt(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_ulong_to_cushrt(ckd_ushrt_t *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_ulong_to_ushrt(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_ulong_to_cint(ckd_int_t *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_ulong_to_int(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_ulong_to_cuint(ckd_uint_t *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_ulong_to_uint(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_ulong_to_clong(ckd_long_t *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_ulong_to_long(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_ulong_to_culong(ckd_ulong_t *_ckd_ret, _ckd_arg_ulong _ckd_a, _ckd_arg_ulong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_ulong_to_ulong(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_ullong_to_cchar(ckd_char_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_ullong_to_char(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_ullong_to_cschar(ckd_schar_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_ullong_to_schar(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_ullong_to_cuchar(ckd_uchar_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_ullong_to_uchar(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_ullong_to_cshrt(ckd_shrt_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_ullong_to_shrt(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_ullong_to_cushrt(ckd_ushrt_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_ullong_to_ushrt(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_ullong_to_cint(ckd_int_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_ullong_to_int(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_ullong_to_cuint(ckd_uint_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_ullong_to_uint(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_ullong_to_clong(ckd_long_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_ullong_to_long(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_ullong_to_culong(ckd_ulong_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_ullong_to_ulong(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_ullong_to_cllong(ckd_llong_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_ullong_to_llong(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_ullong_to_cullong(ckd_ullong_t *_ckd_ret, _ckd_arg_ullong _ckd_a, _ckd_arg_ullong _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_ullong_to_ullong(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint128_to_cchar(ckd_char_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_uint128_to_char(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint128_to_cschar(ckd_schar_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_uint128_to_schar(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint128_to_cuchar(ckd_uchar_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_uint128_to_uchar(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint128_to_cshrt(ckd_shrt_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_uint128_to_shrt(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint128_to_cushrt(ckd_ushrt_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_uint128_to_ushrt(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint128_to_cint(ckd_int_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_uint128_to_int(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint128_to_cuint(ckd_uint_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_uint128_to_uint(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint128_to_clong(ckd_long_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_uint128_to_long(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint128_to_culong(ckd_ulong_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_uint128_to_ulong(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint128_to_cllong(ckd_llong_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_uint128_to_llong(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint128_to_cullong(ckd_ullong_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_uint128_to_ullong(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint128_to_cint128(ckd_int128_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_uint128_to_int128(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
_ckd_fchpnt(1) bool _ckd_mul_3_uint128_to_cuint128(ckd_uint128_t *_ckd_ret, _ckd_arg_uint128 _ckd_a, _ckd_arg_uint128 _ckd_b) {
	return (ckd_overflow(*_ckd_ret) = _ckd_mul_3_uint128_to_uint128(&ckd_value(*_ckd_ret), _ckd_a, _ckd_b));
}
// ]]]]
// Helper macros [[[

/**
 * @define _ckd_toidx(X)
 * @param X Any checked integer type or normal integer type.
 * @return Unique number of that type.
 * @brief Imagine all checked integer types and normal integer types are numbered.
 * This returns the number. char has 0.
 */
#define _ckd_toidx(X) \
			_Generic((X) \
			,char: 0 \
			,ckd_char_t: 1 \
			,signed char: 2 \
			,ckd_schar_t: 3 \
			,unsigned char: 4 \
			,ckd_uchar_t: 5 \
			,short: 6 \
			,ckd_shrt_t: 7 \
			,unsigned short: 8 \
			,ckd_ushrt_t: 9 \
			,int: 10 \
			,ckd_int_t: 11 \
			,unsigned int: 12 \
			,ckd_uint_t: 13 \
			,long: 14 \
			,ckd_long_t: 15 \
			,unsigned long: 16 \
			,ckd_ulong_t: 17 \
			,long long: 18 \
			,ckd_llong_t: 19 \
			,unsigned long long: 20 \
			,ckd_ullong_t: 21 \
			,__int128: 22 \
			,ckd_int128_t: 23 \
			,unsigned __int128: 24 \
			,ckd_uint128_t: 25 \
			)

/**
 * @define _ckd_topidx(X)
 * @brief TO Promoted IDX.
 * @param X Any checked and unchecked integer type.
 * @return Number of type after integer promotions.
 * @see _ckd_toidx
 */
#define _ckd_topidx(X) \
			_Generic((X) \
			,char: 12-2*(CHAR_MAX == SCHAR_MAX) \
			,ckd_char_t: 1 \
			,signed char: 10 \
			,ckd_schar_t: 3 \
			,unsigned char: 12 \
			,ckd_uchar_t: 5 \
			,short: 10 \
			,ckd_shrt_t: 7 \
			,unsigned short: 12 \
			,ckd_ushrt_t: 9 \
			,int: 10 \
			,ckd_int_t: 11 \
			,unsigned int: 12 \
			,ckd_uint_t: 13 \
			,long: 14 \
			,ckd_long_t: 15 \
			,unsigned long: 16 \
			,ckd_ulong_t: 17 \
			,long long: 18 \
			,ckd_llong_t: 19 \
			,unsigned long long: 20 \
			,ckd_ullong_t: 21 \
			,__int128: 22 \
			,ckd_int128_t: 23 \
			,unsigned __int128: 24 \
			,ckd_uint128_t: 25 \
			)

/**
 * @define _ckd_putoidx(X)
 * @brief Promoted Unsigned TO IDX. Same as _ckd_toidx, but only promoted unsigned types.
 * @param X Any promoted unsigned integer type.
 * @return Index of that type.
 * @see _ckd_toidx
 */
#define _ckd_putoidx(X) \
			_Generic((X) \
			,unsigned int: 12 \
			,unsigned long: 16 \
			,unsigned long long: 20 \
			,unsigned __int128: 24 \
			)

/**
 * @define _ckd_topuntype(X)
 * @brief TO Promoted UNsigned TYPE
 * @param X Checked integer type or normal integer type.
 * @return Associated unsigned promoted integer type of the associated normal integer with value 0.
 */
#define _ckd_topuntype(X) \
			_Generic((X) \
			,ckd_int_t: (unsigned int)0 \
			,int: (unsigned int)0 \
			,ckd_uint_t: (unsigned int)0 \
			,unsigned int: (unsigned int)0 \
			,ckd_long_t: (unsigned long)0 \
			,long: (unsigned long)0 \
			,ckd_ulong_t: (unsigned long)0 \
			,unsigned long: (unsigned long)0 \
			,ckd_llong_t: (unsigned long long)0 \
			,long long: (unsigned long long)0 \
			,ckd_ullong_t: (unsigned long long)0 \
			,unsigned long long: (unsigned long long)0 \
			,ckd_int128_t: (unsigned __int128)0 \
			,__int128: (unsigned __int128)0 \
			,ckd_uint128_t: (unsigned __int128)0 \
			,unsigned __int128: (unsigned __int128)0 \
			,default: 0u \
			)

/**
 * @define _ckd_totype(X)
 * @param X Checked integer type or normal integer type.
 * @return Associated normal integer type with value 0.
 */
#define _ckd_totype(X) \
			_Generic((X) \
			,ckd_char_t: (char)0 \
			,char: (char)0 \
			,ckd_schar_t: (signed char)0 \
			,signed char: (signed char)0 \
			,ckd_uchar_t: (unsigned char)0 \
			,unsigned char: (unsigned char)0 \
			,ckd_shrt_t: (short)0 \
			,short: (short)0 \
			,ckd_ushrt_t: (unsigned short)0 \
			,unsigned short: (unsigned short)0 \
			,ckd_int_t: (int)0 \
			,int: (int)0 \
			,ckd_uint_t: (unsigned int)0 \
			,unsigned int: (unsigned int)0 \
			,ckd_long_t: (long)0 \
			,long: (long)0 \
			,ckd_ulong_t: (unsigned long)0 \
			,unsigned long: (unsigned long)0 \
			,ckd_llong_t: (long long)0 \
			,long long: (long long)0 \
			,ckd_ullong_t: (unsigned long long)0 \
			,unsigned long long: (unsigned long long)0 \
			,ckd_int128_t: (__int128)0 \
			,__int128: (__int128)0 \
			,ckd_uint128_t: (unsigned __int128)0 \
			,unsigned __int128: (unsigned __int128)0 \
			)

// ]]]]
// _ckd_arg creation [[[

_ckd_fconst _ckd_arg_uint _ckd_cchar_to_arg_uint(ckd_char_t _ckd_v) {
	const _ckd_arg_uint _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), CHAR_MAX == SCHAR_MAX }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_uint _ckd_cschar_to_arg_uint(ckd_schar_t _ckd_v) {
	const _ckd_arg_uint _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 1 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_uint _ckd_cuchar_to_arg_uint(ckd_uchar_t _ckd_v) {
	const _ckd_arg_uint _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 0 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_uint _ckd_cshrt_to_arg_uint(ckd_shrt_t _ckd_v) {
	const _ckd_arg_uint _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 1 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_uint _ckd_cushrt_to_arg_uint(ckd_ushrt_t _ckd_v) {
	const _ckd_arg_uint _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 0 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_uint _ckd_int_to_arg_uint(int _ckd_v) {
	const _ckd_arg_uint _ckd_ret = { _ckd_v, 0, 1 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_uint _ckd_cint_to_arg_uint(ckd_int_t _ckd_v) {
	const _ckd_arg_uint _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 1 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_uint _ckd_uint_to_arg_uint(unsigned int _ckd_v) {
	const _ckd_arg_uint _ckd_ret = { _ckd_v, 0, 0 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_uint _ckd_cuint_to_arg_uint(ckd_uint_t _ckd_v) {
	const _ckd_arg_uint _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 0 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_ulong _ckd_cchar_to_arg_ulong(ckd_char_t _ckd_v) {
	const _ckd_arg_ulong _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), CHAR_MAX == SCHAR_MAX }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_ulong _ckd_cschar_to_arg_ulong(ckd_schar_t _ckd_v) {
	const _ckd_arg_ulong _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 1 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_ulong _ckd_cuchar_to_arg_ulong(ckd_uchar_t _ckd_v) {
	const _ckd_arg_ulong _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 0 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_ulong _ckd_cshrt_to_arg_ulong(ckd_shrt_t _ckd_v) {
	const _ckd_arg_ulong _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 1 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_ulong _ckd_cushrt_to_arg_ulong(ckd_ushrt_t _ckd_v) {
	const _ckd_arg_ulong _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 0 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_ulong _ckd_cint_to_arg_ulong(ckd_int_t _ckd_v) {
	const _ckd_arg_ulong _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 1 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_ulong _ckd_cuint_to_arg_ulong(ckd_uint_t _ckd_v) {
	const _ckd_arg_ulong _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 0 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_ulong _ckd_long_to_arg_ulong(long _ckd_v) {
	const _ckd_arg_ulong _ckd_ret = { _ckd_v, 0, 1 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_ulong _ckd_clong_to_arg_ulong(ckd_long_t _ckd_v) {
	const _ckd_arg_ulong _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 1 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_ulong _ckd_ulong_to_arg_ulong(unsigned long _ckd_v) {
	const _ckd_arg_ulong _ckd_ret = { _ckd_v, 0, 0 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_ulong _ckd_culong_to_arg_ulong(ckd_ulong_t _ckd_v) {
	const _ckd_arg_ulong _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 0 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_ullong _ckd_cchar_to_arg_ullong(ckd_char_t _ckd_v) {
	const _ckd_arg_ullong _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), CHAR_MAX == SCHAR_MAX }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_ullong _ckd_cschar_to_arg_ullong(ckd_schar_t _ckd_v) {
	const _ckd_arg_ullong _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 1 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_ullong _ckd_cuchar_to_arg_ullong(ckd_uchar_t _ckd_v) {
	const _ckd_arg_ullong _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 0 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_ullong _ckd_cshrt_to_arg_ullong(ckd_shrt_t _ckd_v) {
	const _ckd_arg_ullong _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 1 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_ullong _ckd_cushrt_to_arg_ullong(ckd_ushrt_t _ckd_v) {
	const _ckd_arg_ullong _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 0 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_ullong _ckd_cint_to_arg_ullong(ckd_int_t _ckd_v) {
	const _ckd_arg_ullong _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 1 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_ullong _ckd_cuint_to_arg_ullong(ckd_uint_t _ckd_v) {
	const _ckd_arg_ullong _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 0 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_ullong _ckd_clong_to_arg_ullong(ckd_long_t _ckd_v) {
	const _ckd_arg_ullong _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 1 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_ullong _ckd_culong_to_arg_ullong(ckd_ulong_t _ckd_v) {
	const _ckd_arg_ullong _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 0 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_ullong _ckd_llong_to_arg_ullong(long long _ckd_v) {
	const _ckd_arg_ullong _ckd_ret = { _ckd_v, 0, 1 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_ullong _ckd_cllong_to_arg_ullong(ckd_llong_t _ckd_v) {
	const _ckd_arg_ullong _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 1 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_ullong _ckd_ullong_to_arg_ullong(unsigned long long _ckd_v) {
	const _ckd_arg_ullong _ckd_ret = { _ckd_v, 0, 0 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_ullong _ckd_cullong_to_arg_ullong(ckd_ullong_t _ckd_v) {
	const _ckd_arg_ullong _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 0 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_uint128 _ckd_cchar_to_arg_uint128(ckd_char_t _ckd_v) {
	const _ckd_arg_uint128 _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), CHAR_MAX == SCHAR_MAX }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_uint128 _ckd_cschar_to_arg_uint128(ckd_schar_t _ckd_v) {
	const _ckd_arg_uint128 _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 1 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_uint128 _ckd_cuchar_to_arg_uint128(ckd_uchar_t _ckd_v) {
	const _ckd_arg_uint128 _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 0 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_uint128 _ckd_cshrt_to_arg_uint128(ckd_shrt_t _ckd_v) {
	const _ckd_arg_uint128 _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 1 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_uint128 _ckd_cushrt_to_arg_uint128(ckd_ushrt_t _ckd_v) {
	const _ckd_arg_uint128 _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 0 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_uint128 _ckd_cint_to_arg_uint128(ckd_int_t _ckd_v) {
	const _ckd_arg_uint128 _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 1 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_uint128 _ckd_cuint_to_arg_uint128(ckd_uint_t _ckd_v) {
	const _ckd_arg_uint128 _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 0 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_uint128 _ckd_clong_to_arg_uint128(ckd_long_t _ckd_v) {
	const _ckd_arg_uint128 _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 1 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_uint128 _ckd_culong_to_arg_uint128(ckd_ulong_t _ckd_v) {
	const _ckd_arg_uint128 _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 0 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_uint128 _ckd_cllong_to_arg_uint128(ckd_llong_t _ckd_v) {
	const _ckd_arg_uint128 _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 1 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_uint128 _ckd_cullong_to_arg_uint128(ckd_ullong_t _ckd_v) {
	const _ckd_arg_uint128 _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 0 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_uint128 _ckd_int128_to_arg_uint128(__int128 _ckd_v) {
	const _ckd_arg_uint128 _ckd_ret = { _ckd_v, 0, 1 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_uint128 _ckd_cint128_to_arg_uint128(ckd_int128_t _ckd_v) {
	const _ckd_arg_uint128 _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 1 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_uint128 _ckd_uint128_to_arg_uint128(unsigned __int128 _ckd_v) {
	const _ckd_arg_uint128 _ckd_ret = { _ckd_v, 0, 0 }; return _ckd_ret;
}
_ckd_fconst _ckd_arg_uint128 _ckd_cuint128_to_arg_uint128(ckd_uint128_t _ckd_v) {
	const _ckd_arg_uint128 _ckd_ret = { ckd_value(_ckd_v), ckd_overflow(_ckd_v), 0 }; return _ckd_ret;
}

/**
 * @define _ckd_arg(TO, FROM)
 * @brief Converts any integer or checked integer type into an _ckd_arg of integer type TO.
 * @param TO Any integer type or checked integer type.
 * @param FROM Any integer type or checked integer type.
 * @return _ckd_arg structure that will be passed to other functions.
 */
#define _ckd_arg(TO, FROM) \
			_Generic((int(*)[100 * _ckd_putoidx(TO) + _ckd_topidx(FROM)])0 \
			,int(*)[1201]: _ckd_cchar_to_arg_uint \
			,int(*)[1203]: _ckd_cschar_to_arg_uint \
			,int(*)[1205]: _ckd_cuchar_to_arg_uint \
			,int(*)[1207]: _ckd_cshrt_to_arg_uint \
			,int(*)[1209]: _ckd_cushrt_to_arg_uint \
			,int(*)[1210]: _ckd_int_to_arg_uint \
			,int(*)[1211]: _ckd_cint_to_arg_uint \
			,int(*)[1212]: _ckd_uint_to_arg_uint \
			,int(*)[1213]: _ckd_cuint_to_arg_uint \
			,int(*)[1601]: _ckd_cchar_to_arg_ulong \
			,int(*)[1603]: _ckd_cschar_to_arg_ulong \
			,int(*)[1605]: _ckd_cuchar_to_arg_ulong \
			,int(*)[1607]: _ckd_cshrt_to_arg_ulong \
			,int(*)[1609]: _ckd_cushrt_to_arg_ulong \
			,int(*)[1610]: _ckd_long_to_arg_ulong \
			,int(*)[1611]: _ckd_cint_to_arg_ulong \
			,int(*)[1612]: _ckd_ulong_to_arg_ulong \
			,int(*)[1613]: _ckd_cuint_to_arg_ulong \
			,int(*)[1614]: _ckd_long_to_arg_ulong \
			,int(*)[1615]: _ckd_clong_to_arg_ulong \
			,int(*)[1616]: _ckd_ulong_to_arg_ulong \
			,int(*)[1617]: _ckd_culong_to_arg_ulong \
			,int(*)[2001]: _ckd_cchar_to_arg_ullong \
			,int(*)[2003]: _ckd_cschar_to_arg_ullong \
			,int(*)[2005]: _ckd_cuchar_to_arg_ullong \
			,int(*)[2007]: _ckd_cshrt_to_arg_ullong \
			,int(*)[2009]: _ckd_cushrt_to_arg_ullong \
			,int(*)[2010]: _ckd_llong_to_arg_ullong \
			,int(*)[2011]: _ckd_cint_to_arg_ullong \
			,int(*)[2012]: _ckd_ullong_to_arg_ullong \
			,int(*)[2013]: _ckd_cuint_to_arg_ullong \
			,int(*)[2014]: _ckd_llong_to_arg_ullong \
			,int(*)[2015]: _ckd_clong_to_arg_ullong \
			,int(*)[2016]: _ckd_ullong_to_arg_ullong \
			,int(*)[2017]: _ckd_culong_to_arg_ullong \
			,int(*)[2018]: _ckd_llong_to_arg_ullong \
			,int(*)[2019]: _ckd_cllong_to_arg_ullong \
			,int(*)[2020]: _ckd_ullong_to_arg_ullong \
			,int(*)[2021]: _ckd_cullong_to_arg_ullong \
			,int(*)[2401]: _ckd_cchar_to_arg_uint128 \
			,int(*)[2403]: _ckd_cschar_to_arg_uint128 \
			,int(*)[2405]: _ckd_cuchar_to_arg_uint128 \
			,int(*)[2407]: _ckd_cshrt_to_arg_uint128 \
			,int(*)[2409]: _ckd_cushrt_to_arg_uint128 \
			,int(*)[2410]: _ckd_int128_to_arg_uint128 \
			,int(*)[2411]: _ckd_cint_to_arg_uint128 \
			,int(*)[2412]: _ckd_uint128_to_arg_uint128 \
			,int(*)[2413]: _ckd_cuint_to_arg_uint128 \
			,int(*)[2414]: _ckd_int128_to_arg_uint128 \
			,int(*)[2415]: _ckd_clong_to_arg_uint128 \
			,int(*)[2416]: _ckd_uint128_to_arg_uint128 \
			,int(*)[2417]: _ckd_culong_to_arg_uint128 \
			,int(*)[2418]: _ckd_int128_to_arg_uint128 \
			,int(*)[2419]: _ckd_cllong_to_arg_uint128 \
			,int(*)[2420]: _ckd_uint128_to_arg_uint128 \
			,int(*)[2421]: _ckd_cullong_to_arg_uint128 \
			,int(*)[2422]: _ckd_int128_to_arg_uint128 \
			,int(*)[2423]: _ckd_cint128_to_arg_uint128 \
			,int(*)[2424]: _ckd_uint128_to_arg_uint128 \
			,int(*)[2425]: _ckd_cuint128_to_arg_uint128 \
			)(FROM)

// ]]]
// Macros [[[

#define _ckd_add_3_IN(TOTYPE, r, a, b) \
			_Generic((int(*)[100 * _ckd_putoidx(TOTYPE) + _ckd_toidx(*(r))])0 \
			,int(*)[1200]: _ckd_add_3_uint_to_char \
			,int(*)[1201]: _ckd_add_3_uint_to_cchar \
			,int(*)[1202]: _ckd_add_3_uint_to_schar \
			,int(*)[1203]: _ckd_add_3_uint_to_cschar \
			,int(*)[1204]: _ckd_add_3_uint_to_uchar \
			,int(*)[1205]: _ckd_add_3_uint_to_cuchar \
			,int(*)[1206]: _ckd_add_3_uint_to_shrt \
			,int(*)[1207]: _ckd_add_3_uint_to_cshrt \
			,int(*)[1208]: _ckd_add_3_uint_to_ushrt \
			,int(*)[1209]: _ckd_add_3_uint_to_cushrt \
			,int(*)[1210]: _ckd_add_3_uint_to_int \
			,int(*)[1211]: _ckd_add_3_uint_to_cint \
			,int(*)[1212]: _ckd_add_3_uint_to_uint \
			,int(*)[1213]: _ckd_add_3_uint_to_cuint \
			,int(*)[1600]: _ckd_add_3_ulong_to_char \
			,int(*)[1601]: _ckd_add_3_ulong_to_cchar \
			,int(*)[1602]: _ckd_add_3_ulong_to_schar \
			,int(*)[1603]: _ckd_add_3_ulong_to_cschar \
			,int(*)[1604]: _ckd_add_3_ulong_to_uchar \
			,int(*)[1605]: _ckd_add_3_ulong_to_cuchar \
			,int(*)[1606]: _ckd_add_3_ulong_to_shrt \
			,int(*)[1607]: _ckd_add_3_ulong_to_cshrt \
			,int(*)[1608]: _ckd_add_3_ulong_to_ushrt \
			,int(*)[1609]: _ckd_add_3_ulong_to_cushrt \
			,int(*)[1610]: _ckd_add_3_ulong_to_int \
			,int(*)[1611]: _ckd_add_3_ulong_to_cint \
			,int(*)[1612]: _ckd_add_3_ulong_to_uint \
			,int(*)[1613]: _ckd_add_3_ulong_to_cuint \
			,int(*)[1614]: _ckd_add_3_ulong_to_long \
			,int(*)[1615]: _ckd_add_3_ulong_to_clong \
			,int(*)[1616]: _ckd_add_3_ulong_to_ulong \
			,int(*)[1617]: _ckd_add_3_ulong_to_culong \
			,int(*)[2000]: _ckd_add_3_ullong_to_char \
			,int(*)[2001]: _ckd_add_3_ullong_to_cchar \
			,int(*)[2002]: _ckd_add_3_ullong_to_schar \
			,int(*)[2003]: _ckd_add_3_ullong_to_cschar \
			,int(*)[2004]: _ckd_add_3_ullong_to_uchar \
			,int(*)[2005]: _ckd_add_3_ullong_to_cuchar \
			,int(*)[2006]: _ckd_add_3_ullong_to_shrt \
			,int(*)[2007]: _ckd_add_3_ullong_to_cshrt \
			,int(*)[2008]: _ckd_add_3_ullong_to_ushrt \
			,int(*)[2009]: _ckd_add_3_ullong_to_cushrt \
			,int(*)[2010]: _ckd_add_3_ullong_to_int \
			,int(*)[2011]: _ckd_add_3_ullong_to_cint \
			,int(*)[2012]: _ckd_add_3_ullong_to_uint \
			,int(*)[2013]: _ckd_add_3_ullong_to_cuint \
			,int(*)[2014]: _ckd_add_3_ullong_to_long \
			,int(*)[2015]: _ckd_add_3_ullong_to_clong \
			,int(*)[2016]: _ckd_add_3_ullong_to_ulong \
			,int(*)[2017]: _ckd_add_3_ullong_to_culong \
			,int(*)[2018]: _ckd_add_3_ullong_to_llong \
			,int(*)[2019]: _ckd_add_3_ullong_to_cllong \
			,int(*)[2020]: _ckd_add_3_ullong_to_ullong \
			,int(*)[2021]: _ckd_add_3_ullong_to_cullong \
			,int(*)[2400]: _ckd_add_3_uint128_to_char \
			,int(*)[2401]: _ckd_add_3_uint128_to_cchar \
			,int(*)[2402]: _ckd_add_3_uint128_to_schar \
			,int(*)[2403]: _ckd_add_3_uint128_to_cschar \
			,int(*)[2404]: _ckd_add_3_uint128_to_uchar \
			,int(*)[2405]: _ckd_add_3_uint128_to_cuchar \
			,int(*)[2406]: _ckd_add_3_uint128_to_shrt \
			,int(*)[2407]: _ckd_add_3_uint128_to_cshrt \
			,int(*)[2408]: _ckd_add_3_uint128_to_ushrt \
			,int(*)[2409]: _ckd_add_3_uint128_to_cushrt \
			,int(*)[2410]: _ckd_add_3_uint128_to_int \
			,int(*)[2411]: _ckd_add_3_uint128_to_cint \
			,int(*)[2412]: _ckd_add_3_uint128_to_uint \
			,int(*)[2413]: _ckd_add_3_uint128_to_cuint \
			,int(*)[2414]: _ckd_add_3_uint128_to_long \
			,int(*)[2415]: _ckd_add_3_uint128_to_clong \
			,int(*)[2416]: _ckd_add_3_uint128_to_ulong \
			,int(*)[2417]: _ckd_add_3_uint128_to_culong \
			,int(*)[2418]: _ckd_add_3_uint128_to_llong \
			,int(*)[2419]: _ckd_add_3_uint128_to_cllong \
			,int(*)[2420]: _ckd_add_3_uint128_to_ullong \
			,int(*)[2421]: _ckd_add_3_uint128_to_cullong \
			,int(*)[2422]: _ckd_add_3_uint128_to_int128 \
			,int(*)[2423]: _ckd_add_3_uint128_to_cint128 \
			,int(*)[2424]: _ckd_add_3_uint128_to_uint128 \
			,int(*)[2425]: _ckd_add_3_uint128_to_cuint128 \
			)(r, \
			_ckd_arg(TOTYPE, a), \
			_ckd_arg(TOTYPE, b))

#define _ckd_add_3(r, a, b) \
		_ckd_add_3_IN(_ckd_topuntype(a) + _ckd_topuntype(b) + _ckd_topuntype(*(r)), r, a, b)

#define _ckd_add_2(a, b, _) \
			_Generic(_ckd_totype(a) + _ckd_totype(b) \
			,int: _ckd_add_2_int \
			,unsigned int: _ckd_add_2_uint \
			,long: _ckd_add_2_long \
			,unsigned long: _ckd_add_2_ulong \
			,long long: _ckd_add_2_llong \
			,unsigned long long: _ckd_add_2_ullong \
			,__int128: _ckd_add_2_int128 \
			,unsigned __int128: _ckd_add_2_uint128 \
			)( \
			_ckd_arg(_ckd_topuntype(a) + _ckd_topuntype(b), a), \
			_ckd_arg(_ckd_topuntype(a) + _ckd_topuntype(b), b))


#define _ckd_sub_3_IN(TOTYPE, r, a, b) \
			_Generic((int(*)[100 * _ckd_putoidx(TOTYPE) + _ckd_toidx(*(r))])0 \
			,int(*)[1200]: _ckd_sub_3_uint_to_char \
			,int(*)[1201]: _ckd_sub_3_uint_to_cchar \
			,int(*)[1202]: _ckd_sub_3_uint_to_schar \
			,int(*)[1203]: _ckd_sub_3_uint_to_cschar \
			,int(*)[1204]: _ckd_sub_3_uint_to_uchar \
			,int(*)[1205]: _ckd_sub_3_uint_to_cuchar \
			,int(*)[1206]: _ckd_sub_3_uint_to_shrt \
			,int(*)[1207]: _ckd_sub_3_uint_to_cshrt \
			,int(*)[1208]: _ckd_sub_3_uint_to_ushrt \
			,int(*)[1209]: _ckd_sub_3_uint_to_cushrt \
			,int(*)[1210]: _ckd_sub_3_uint_to_int \
			,int(*)[1211]: _ckd_sub_3_uint_to_cint \
			,int(*)[1212]: _ckd_sub_3_uint_to_uint \
			,int(*)[1213]: _ckd_sub_3_uint_to_cuint \
			,int(*)[1600]: _ckd_sub_3_ulong_to_char \
			,int(*)[1601]: _ckd_sub_3_ulong_to_cchar \
			,int(*)[1602]: _ckd_sub_3_ulong_to_schar \
			,int(*)[1603]: _ckd_sub_3_ulong_to_cschar \
			,int(*)[1604]: _ckd_sub_3_ulong_to_uchar \
			,int(*)[1605]: _ckd_sub_3_ulong_to_cuchar \
			,int(*)[1606]: _ckd_sub_3_ulong_to_shrt \
			,int(*)[1607]: _ckd_sub_3_ulong_to_cshrt \
			,int(*)[1608]: _ckd_sub_3_ulong_to_ushrt \
			,int(*)[1609]: _ckd_sub_3_ulong_to_cushrt \
			,int(*)[1610]: _ckd_sub_3_ulong_to_int \
			,int(*)[1611]: _ckd_sub_3_ulong_to_cint \
			,int(*)[1612]: _ckd_sub_3_ulong_to_uint \
			,int(*)[1613]: _ckd_sub_3_ulong_to_cuint \
			,int(*)[1614]: _ckd_sub_3_ulong_to_long \
			,int(*)[1615]: _ckd_sub_3_ulong_to_clong \
			,int(*)[1616]: _ckd_sub_3_ulong_to_ulong \
			,int(*)[1617]: _ckd_sub_3_ulong_to_culong \
			,int(*)[2000]: _ckd_sub_3_ullong_to_char \
			,int(*)[2001]: _ckd_sub_3_ullong_to_cchar \
			,int(*)[2002]: _ckd_sub_3_ullong_to_schar \
			,int(*)[2003]: _ckd_sub_3_ullong_to_cschar \
			,int(*)[2004]: _ckd_sub_3_ullong_to_uchar \
			,int(*)[2005]: _ckd_sub_3_ullong_to_cuchar \
			,int(*)[2006]: _ckd_sub_3_ullong_to_shrt \
			,int(*)[2007]: _ckd_sub_3_ullong_to_cshrt \
			,int(*)[2008]: _ckd_sub_3_ullong_to_ushrt \
			,int(*)[2009]: _ckd_sub_3_ullong_to_cushrt \
			,int(*)[2010]: _ckd_sub_3_ullong_to_int \
			,int(*)[2011]: _ckd_sub_3_ullong_to_cint \
			,int(*)[2012]: _ckd_sub_3_ullong_to_uint \
			,int(*)[2013]: _ckd_sub_3_ullong_to_cuint \
			,int(*)[2014]: _ckd_sub_3_ullong_to_long \
			,int(*)[2015]: _ckd_sub_3_ullong_to_clong \
			,int(*)[2016]: _ckd_sub_3_ullong_to_ulong \
			,int(*)[2017]: _ckd_sub_3_ullong_to_culong \
			,int(*)[2018]: _ckd_sub_3_ullong_to_llong \
			,int(*)[2019]: _ckd_sub_3_ullong_to_cllong \
			,int(*)[2020]: _ckd_sub_3_ullong_to_ullong \
			,int(*)[2021]: _ckd_sub_3_ullong_to_cullong \
			,int(*)[2400]: _ckd_sub_3_uint128_to_char \
			,int(*)[2401]: _ckd_sub_3_uint128_to_cchar \
			,int(*)[2402]: _ckd_sub_3_uint128_to_schar \
			,int(*)[2403]: _ckd_sub_3_uint128_to_cschar \
			,int(*)[2404]: _ckd_sub_3_uint128_to_uchar \
			,int(*)[2405]: _ckd_sub_3_uint128_to_cuchar \
			,int(*)[2406]: _ckd_sub_3_uint128_to_shrt \
			,int(*)[2407]: _ckd_sub_3_uint128_to_cshrt \
			,int(*)[2408]: _ckd_sub_3_uint128_to_ushrt \
			,int(*)[2409]: _ckd_sub_3_uint128_to_cushrt \
			,int(*)[2410]: _ckd_sub_3_uint128_to_int \
			,int(*)[2411]: _ckd_sub_3_uint128_to_cint \
			,int(*)[2412]: _ckd_sub_3_uint128_to_uint \
			,int(*)[2413]: _ckd_sub_3_uint128_to_cuint \
			,int(*)[2414]: _ckd_sub_3_uint128_to_long \
			,int(*)[2415]: _ckd_sub_3_uint128_to_clong \
			,int(*)[2416]: _ckd_sub_3_uint128_to_ulong \
			,int(*)[2417]: _ckd_sub_3_uint128_to_culong \
			,int(*)[2418]: _ckd_sub_3_uint128_to_llong \
			,int(*)[2419]: _ckd_sub_3_uint128_to_cllong \
			,int(*)[2420]: _ckd_sub_3_uint128_to_ullong \
			,int(*)[2421]: _ckd_sub_3_uint128_to_cullong \
			,int(*)[2422]: _ckd_sub_3_uint128_to_int128 \
			,int(*)[2423]: _ckd_sub_3_uint128_to_cint128 \
			,int(*)[2424]: _ckd_sub_3_uint128_to_uint128 \
			,int(*)[2425]: _ckd_sub_3_uint128_to_cuint128 \
			)(r, \
			_ckd_arg(TOTYPE, a), \
			_ckd_arg(TOTYPE, b))

#define _ckd_sub_3(r, a, b) \
		_ckd_sub_3_IN(_ckd_topuntype(a) + _ckd_topuntype(b) + _ckd_topuntype(*(r)), r, a, b)

#define _ckd_sub_2(a, b, _) \
			_Generic(_ckd_totype(a) + _ckd_totype(b) \
			,int: _ckd_sub_2_int \
			,unsigned int: _ckd_sub_2_uint \
			,long: _ckd_sub_2_long \
			,unsigned long: _ckd_sub_2_ulong \
			,long long: _ckd_sub_2_llong \
			,unsigned long long: _ckd_sub_2_ullong \
			,__int128: _ckd_sub_2_int128 \
			,unsigned __int128: _ckd_sub_2_uint128 \
			)( \
			_ckd_arg(_ckd_topuntype(a) + _ckd_topuntype(b), a), \
			_ckd_arg(_ckd_topuntype(a) + _ckd_topuntype(b), b))


#define _ckd_mul_3_IN(TOTYPE, r, a, b) \
			_Generic((int(*)[100 * _ckd_putoidx(TOTYPE) + _ckd_toidx(*(r))])0 \
			,int(*)[1200]: _ckd_mul_3_uint_to_char \
			,int(*)[1201]: _ckd_mul_3_uint_to_cchar \
			,int(*)[1202]: _ckd_mul_3_uint_to_schar \
			,int(*)[1203]: _ckd_mul_3_uint_to_cschar \
			,int(*)[1204]: _ckd_mul_3_uint_to_uchar \
			,int(*)[1205]: _ckd_mul_3_uint_to_cuchar \
			,int(*)[1206]: _ckd_mul_3_uint_to_shrt \
			,int(*)[1207]: _ckd_mul_3_uint_to_cshrt \
			,int(*)[1208]: _ckd_mul_3_uint_to_ushrt \
			,int(*)[1209]: _ckd_mul_3_uint_to_cushrt \
			,int(*)[1210]: _ckd_mul_3_uint_to_int \
			,int(*)[1211]: _ckd_mul_3_uint_to_cint \
			,int(*)[1212]: _ckd_mul_3_uint_to_uint \
			,int(*)[1213]: _ckd_mul_3_uint_to_cuint \
			,int(*)[1600]: _ckd_mul_3_ulong_to_char \
			,int(*)[1601]: _ckd_mul_3_ulong_to_cchar \
			,int(*)[1602]: _ckd_mul_3_ulong_to_schar \
			,int(*)[1603]: _ckd_mul_3_ulong_to_cschar \
			,int(*)[1604]: _ckd_mul_3_ulong_to_uchar \
			,int(*)[1605]: _ckd_mul_3_ulong_to_cuchar \
			,int(*)[1606]: _ckd_mul_3_ulong_to_shrt \
			,int(*)[1607]: _ckd_mul_3_ulong_to_cshrt \
			,int(*)[1608]: _ckd_mul_3_ulong_to_ushrt \
			,int(*)[1609]: _ckd_mul_3_ulong_to_cushrt \
			,int(*)[1610]: _ckd_mul_3_ulong_to_int \
			,int(*)[1611]: _ckd_mul_3_ulong_to_cint \
			,int(*)[1612]: _ckd_mul_3_ulong_to_uint \
			,int(*)[1613]: _ckd_mul_3_ulong_to_cuint \
			,int(*)[1614]: _ckd_mul_3_ulong_to_long \
			,int(*)[1615]: _ckd_mul_3_ulong_to_clong \
			,int(*)[1616]: _ckd_mul_3_ulong_to_ulong \
			,int(*)[1617]: _ckd_mul_3_ulong_to_culong \
			,int(*)[2000]: _ckd_mul_3_ullong_to_char \
			,int(*)[2001]: _ckd_mul_3_ullong_to_cchar \
			,int(*)[2002]: _ckd_mul_3_ullong_to_schar \
			,int(*)[2003]: _ckd_mul_3_ullong_to_cschar \
			,int(*)[2004]: _ckd_mul_3_ullong_to_uchar \
			,int(*)[2005]: _ckd_mul_3_ullong_to_cuchar \
			,int(*)[2006]: _ckd_mul_3_ullong_to_shrt \
			,int(*)[2007]: _ckd_mul_3_ullong_to_cshrt \
			,int(*)[2008]: _ckd_mul_3_ullong_to_ushrt \
			,int(*)[2009]: _ckd_mul_3_ullong_to_cushrt \
			,int(*)[2010]: _ckd_mul_3_ullong_to_int \
			,int(*)[2011]: _ckd_mul_3_ullong_to_cint \
			,int(*)[2012]: _ckd_mul_3_ullong_to_uint \
			,int(*)[2013]: _ckd_mul_3_ullong_to_cuint \
			,int(*)[2014]: _ckd_mul_3_ullong_to_long \
			,int(*)[2015]: _ckd_mul_3_ullong_to_clong \
			,int(*)[2016]: _ckd_mul_3_ullong_to_ulong \
			,int(*)[2017]: _ckd_mul_3_ullong_to_culong \
			,int(*)[2018]: _ckd_mul_3_ullong_to_llong \
			,int(*)[2019]: _ckd_mul_3_ullong_to_cllong \
			,int(*)[2020]: _ckd_mul_3_ullong_to_ullong \
			,int(*)[2021]: _ckd_mul_3_ullong_to_cullong \
			,int(*)[2400]: _ckd_mul_3_uint128_to_char \
			,int(*)[2401]: _ckd_mul_3_uint128_to_cchar \
			,int(*)[2402]: _ckd_mul_3_uint128_to_schar \
			,int(*)[2403]: _ckd_mul_3_uint128_to_cschar \
			,int(*)[2404]: _ckd_mul_3_uint128_to_uchar \
			,int(*)[2405]: _ckd_mul_3_uint128_to_cuchar \
			,int(*)[2406]: _ckd_mul_3_uint128_to_shrt \
			,int(*)[2407]: _ckd_mul_3_uint128_to_cshrt \
			,int(*)[2408]: _ckd_mul_3_uint128_to_ushrt \
			,int(*)[2409]: _ckd_mul_3_uint128_to_cushrt \
			,int(*)[2410]: _ckd_mul_3_uint128_to_int \
			,int(*)[2411]: _ckd_mul_3_uint128_to_cint \
			,int(*)[2412]: _ckd_mul_3_uint128_to_uint \
			,int(*)[2413]: _ckd_mul_3_uint128_to_cuint \
			,int(*)[2414]: _ckd_mul_3_uint128_to_long \
			,int(*)[2415]: _ckd_mul_3_uint128_to_clong \
			,int(*)[2416]: _ckd_mul_3_uint128_to_ulong \
			,int(*)[2417]: _ckd_mul_3_uint128_to_culong \
			,int(*)[2418]: _ckd_mul_3_uint128_to_llong \
			,int(*)[2419]: _ckd_mul_3_uint128_to_cllong \
			,int(*)[2420]: _ckd_mul_3_uint128_to_ullong \
			,int(*)[2421]: _ckd_mul_3_uint128_to_cullong \
			,int(*)[2422]: _ckd_mul_3_uint128_to_int128 \
			,int(*)[2423]: _ckd_mul_3_uint128_to_cint128 \
			,int(*)[2424]: _ckd_mul_3_uint128_to_uint128 \
			,int(*)[2425]: _ckd_mul_3_uint128_to_cuint128 \
			)(r, \
			_ckd_arg(TOTYPE, a), \
			_ckd_arg(TOTYPE, b))

#define _ckd_mul_3(r, a, b) \
		_ckd_mul_3_IN(_ckd_topuntype(a) + _ckd_topuntype(b) + _ckd_topuntype(*(r)), r, a, b)

#define _ckd_mul_2(a, b, _) \
			_Generic(_ckd_totype(a) + _ckd_totype(b) \
			,int: _ckd_mul_2_int \
			,unsigned int: _ckd_mul_2_uint \
			,long: _ckd_mul_2_long \
			,unsigned long: _ckd_mul_2_ulong \
			,long long: _ckd_mul_2_llong \
			,unsigned long long: _ckd_mul_2_ullong \
			,__int128: _ckd_mul_2_int128 \
			,unsigned __int128: _ckd_mul_2_uint128 \
			)( \
			_ckd_arg(_ckd_topuntype(a) + _ckd_topuntype(b), a), \
			_ckd_arg(_ckd_topuntype(a) + _ckd_topuntype(b), b))


// ]]]
// vim: ft=c


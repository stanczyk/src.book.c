/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg12-00.c
 * @brief stałe symboliczne dot.biblioteki standardowej
 */
#include <assert.h>
#include <complex.h>
// #include <ctype.h>
// #include <errno.h>
#include <fenv.h>
#include <float.h>
#include <inttypes.h>
// #include <iso646.h>
#include <limits.h>
// #include <locale.h>
#include <math.h>
#include <setjmp.h>
// #include <signal.h>
// #include <stdalign.h>
#include <stdarg.h>
#include <stdatomic.h>
// #include <stdbit.h> 		gcc 13.1.0 jeszcze nie zawiera tego pliku nagłówkowego
// #include <stdbool.h>
// #include <stdckdint.h> 	gcc 13.1.0 jeszcze nie zawiera tego pliku nagłówkowego
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
// #include <stdnoreturn.h>
#include <string.h>
#include <tgmath.h>
// #include <threads.h>
#include <time.h>
#include <uchar.h>
#include <wchar.h>
// #include <wctype.h>

#include "../00/head0-01.h"

int main (void)
{
	SHOW_DEFINE(__STDC_VERSION__);
	SHOW_DEFINE(__STDC_LIB_EXT1__);
	printf("\n" );

	printf("Wersje plików nagłówkowych\n");
	SHOW_DEFINE(__STDC_VERSION_ASSERT_H__);
	SHOW_DEFINE(__STDC_VERSION_COMPLEX_H__);
	// __STDC_VERSION_CTYPE_H__
	// __STDC_VERSION_ERRNO_H__
	SHOW_DEFINE(__STDC_VERSION_FENV_H__);
	SHOW_DEFINE(__STDC_VERSION_FLOAT_H__);
	SHOW_DEFINE(__STDC_VERSION_INTTYPES_H__);
	// __STDC_VERSION_ISO646_H__
	SHOW_DEFINE(__STDC_VERSION_LIMITS_H__);
	// __STDC_VERSION_LOCALE_H__
	SHOW_DEFINE(__STDC_VERSION_MATH_H__);
	SHOW_DEFINE(__STDC_VERSION_SETJMP_H__);
	// __STDC_VERSION_SIGNAL_H__
	// __STDC_VERSION_STDALIGN_H
	SHOW_DEFINE(__STDC_VERSION_STDARG_H__);
	SHOW_DEFINE(__STDC_VERSION_STDATOMIC_H__);
	SHOW_DEFINE(__STDC_VERSION_STDBIT_H__);
	// __STDC_VERSION_STDBOOL_H__
	SHOW_DEFINE(__STDC_VERSION_STDCKDINT_H__);
	SHOW_DEFINE(__STDC_VERSION_STDDEF_H__);
	SHOW_DEFINE(__STDC_VERSION_STDINT_H__);
	SHOW_DEFINE(__STDC_VERSION_STDIO_H__);
	SHOW_DEFINE(__STDC_VERSION_STDLIB_H__);
	// __STDC_VERSION_STDNORETURN_H__
	SHOW_DEFINE(__STDC_VERSION_STRING_H__);
	SHOW_DEFINE(__STDC_VERSION_TGMATH_H__);
	// __STDC_VERSION_THREADS_H__
	SHOW_DEFINE(__STDC_VERSION_TIME_H__);
	SHOW_DEFINE(__STDC_VERSION_UCHAR_H__);
	SHOW_DEFINE(__STDC_VERSION_WCHAR_H__);
	// __STDC_VERSION_WCTYPE_H__
}

/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg21-01.c
 * @brief <limits.h>: zakresy poszczególnych typów całkowitoliczbowych
 */
#include <limits.h>
#include <stdio.h>

int main (void)
{
	printf ("CHAR_BIT       = %d\n", CHAR_BIT);
	printf ("MB_LEN_MAX     = %d\n", MB_LEN_MAX);
	printf ("BITINT_MAXWIDTH= %d\n", BITINT_MAXWIDTH);

	printf ("bool\n");
	printf ("  BOOL_WIDTH   = %d\n", BOOL_WIDTH);
	printf ("  BOOL_MAX     = %+d\n", BOOL_MAX);

	printf ("char\n");
	printf ("  CHAR_WIDTH   = %d\n", CHAR_WIDTH);
	printf ("  CHAR_MIN     = %+d\n", CHAR_MIN);
	printf ("  CHAR_MAX     = %+d\n", CHAR_MAX);

	printf ("signed char\n");
	printf ("  SCHAR_WIDTH  = %d\n", SCHAR_WIDTH);
	printf ("  SCHAR_MIN    = %+d\n", SCHAR_MIN);
	printf ("  SCHAR_MAX    = %+d\n", SCHAR_MAX);

	printf ("unsigned char\n");
	printf ("  UCHAR_WIDTH  = %d\n", UCHAR_WIDTH);
	printf ("  UCHAR_MAX    = %u\n", UCHAR_MAX);

	printf ("short\n");
	printf ("  SHRT_WIDTH   = %d\n", SHRT_WIDTH);
	printf ("  SHRT_MIN     = %+d\n", SHRT_MIN);
	printf ("  SHRT_MAX     = %+d\n", SHRT_MAX);

	printf ("unsigned short\n");
	printf ("  USHRT_WIDTH  = %d\n", USHRT_WIDTH);
	printf ("  USHRT_MAX    = %u\n", USHRT_MAX);

	printf ("int\n");
	printf ("  INT_WIDTH    = %d\n", INT_WIDTH);
	printf ("  INT_MIN      = %+i\n", INT_MIN);
	printf ("  INT_MAX      = %+i\n", INT_MAX);

	printf ("unsigned int\n");
	printf ("  UINT_WIDTH   = %d\n", UINT_WIDTH);
	printf ("  UINT_MAX     = %u\n", UINT_MAX);

	printf ("long\n");
	printf ("  LONG_WIDTH   = %d\n", LONG_WIDTH);
	printf ("  LONG_MIN     = %+li\n", LONG_MIN);
	printf ("  LONG_MAX     = %+li\n", LONG_MAX);

	printf ("unsigned long\n");
	printf ("  ULONG_WIDTH  = %d\n", ULONG_WIDTH);
	printf ("  ULONG_MAX    = %lu\n", ULONG_MAX);

	printf ("long long\n");
	printf ("  LLONG_WIDTH  = %d\n", LLONG_WIDTH);
	printf ("  LLONG_MIN    = %+lli\n", LLONG_MIN);
	printf ("  LLONG_MAX    = %+lli\n", LLONG_MAX);

	printf ("unsigned long long\n");
	printf ("  ULLONG_WIDTH = %d\n", ULLONG_WIDTH);
	printf ("  ULLONG_MAX   = %llu\n", ULLONG_MAX);
}

/* eof. */

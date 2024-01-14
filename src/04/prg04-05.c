/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg04-05.c
 * @brief Zakresy liczb całkowitych
 */
#include <stdio.h>
#include <limits.h>

int main (void)
{
	printf ("__WORDSIZE = %i\n", __WORDSIZE);
	printf ("  CHAR_BIT = %i\n", CHAR_BIT);
	printf ("typ           (min, max), ilość bitów\n---------------------------\n");
	printf ("bool          (%d, %d), %d\n",             0,   BOOL_MAX,   BOOL_WIDTH);
	printf ("char          (%d, %d), %d\n",      CHAR_MIN,   CHAR_MAX,   CHAR_BIT);
	printf ("       signed (%d, %d), %d\n",     SCHAR_MIN,  SCHAR_MAX,  SCHAR_WIDTH);
	printf ("     unsigned (%d, %d), %d\n",             0,  UCHAR_MAX,  UCHAR_WIDTH);
	printf ("short int     (%d, %d), %d\n",      SHRT_MIN,   SHRT_MAX,   SHRT_WIDTH);
	printf ("     unsigned (%d, %d), %d\n",             0,  USHRT_MAX,  USHRT_WIDTH);
	printf ("int           (%i, %i), %d\n",       INT_MIN,    INT_MAX,    INT_WIDTH);
	printf ("     unsigned (%u, %u), %d\n",            0U,   UINT_MAX,   UINT_WIDTH);
	printf ("long int      (%li, %li), %d\n",    LONG_MIN,   LONG_MAX,   LONG_WIDTH);
	printf ("     unsigned (%lu, %lu), %d\n",         0UL,  ULONG_MAX,  ULONG_WIDTH);
	printf ("long long int (%lli, %lli), %d\n", LLONG_MIN,  LLONG_MAX,  LLONG_WIDTH);
	printf ("     unsigned (%llu, %llu), %d\n",      0ULL, ULLONG_MAX, ULLONG_WIDTH);
}

/* eof. */

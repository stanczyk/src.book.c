/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg41-00.c
 * @brief <uchar.h>: dostępne stałe symboliczne
 */
#include <stdio.h>

int main (void)
{
	puts("zdefiniowane makra:");
	#ifdef __STDC_UTF_8__
		puts("__STDC_UTF_8__");
	#endif
	#ifdef __STDC_UTF_16__
		puts("__STDC_UTF_16__");
	#endif
	#ifdef __STDC_UTF_32__
		puts("__STDC_UTF_32__");
	#endif
}

/* eof. */

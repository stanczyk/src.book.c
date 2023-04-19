/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg33-00.c
 * @brief <stdint.h>: dostępne stałe symboliczne
 */
#include <stdint.h>
#include <stdio.h>

int main (void)
{
	puts("zdefiniowane makra:");
	#ifdef __STDC_VERSION_STDINT_H__
		puts("__STDC_VERSION_STDINT_H__");
	#endif
	#ifdef __STDC_LIB_EXT1__
		puts("__STDC_LIB_EXT1__");
	#endif
}

/* eof. */

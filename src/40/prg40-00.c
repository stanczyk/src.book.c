/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg40-00.c
 * @brief <time.h>: dostępne stałe symboliczne
 */
#include <stdio.h>
#include <time.h>

int main (void)
{
	puts("zdefiniowane makra:");
	#ifdef __STDC_VERSION_TIME_H__
		puts("__STDC_VERSION_TIME_H__");
	#endif
	#ifdef __STDC_LIB_EXT1__
		puts("__STDC_LIB_EXT1__");
	#endif
}

/* eof. */

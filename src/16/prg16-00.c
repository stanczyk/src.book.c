/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg16-00.c
 * @brief <errno.h>: dostępne stałe symboliczne
 */
#include <errno.h>
#include <stdio.h>

int main (void)
{
	puts("zdefiniowane makra:");
	#ifdef __STDC_LIB_EXT1__
		puts("__STDC_LIB_EXT1__");
	#endif
}

/* eof. */

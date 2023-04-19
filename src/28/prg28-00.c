/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg28-00.c
 * @brief <stdatomic.h>: dostępne stałe symboliczne
 */
#include <stdatomic.h>
#include <stdio.h>

int main (void)
{
	puts("zdefiniowane makra:");
	#ifdef __STDC_NO_ATOMICS__
		puts("__STDC_NO_ATOMICS__");
	#endif
}

/* eof. */

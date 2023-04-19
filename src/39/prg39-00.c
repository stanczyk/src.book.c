/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg39-00.c
 * @brief <threads.h>: dostępne stałe symboliczne
 */
#include <stdio.h>
#include <threads.h>

int main (void)
{
	puts("zdefiniowane makra:");
	#ifdef __STDC_NO_THREADS__
		puts("__STDC_NO_THREADS__");
	#endif
}

/* eof. */

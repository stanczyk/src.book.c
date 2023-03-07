/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg18-00.c
 * @brief <float.h>: dostępne stałe symboliczne
 */
#include <float.h>
#include <stdio.h>

int main (void)
{
	puts("zdefiniowane makra:");
	#ifdef __STDC_IEC_60559_DFP__
		puts("__STDC_IEC_60559_DFP__");
	#endif
}

/* eof. */

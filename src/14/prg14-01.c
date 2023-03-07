/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg14-01.c
 * @brief <complex.h>: wsparcie liczb zespolonych
 */
#ifdef __STDC_NO_COMPLEX__
#error brak wsparcia dla liczb zespolonych
#endif

#include <stdio.h>

int main (void)
{
	#ifndef __STDC_NO_COMPLEX__
		printf("wspierany <complex.h> (brak __STDC_NO_COMPLEX__)\n");
	#endif
	#ifdef __STDC_IEC_559_COMPLEX__
		printf("wspierany __STDC_IEC_559_COMPLEX__\n");
	#endif
	#ifdef __STDC_IEC_60559_COMPLEX__
		printf("wspierany __STDC_IEC_60559_COMPLEX__\n");
	#endif
}

/* eof. */

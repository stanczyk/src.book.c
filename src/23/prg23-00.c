/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg23-00.c
 * @brief <math.h>: dostępne stałe symboliczne
 */
#include <math.h>
#include <stdio.h>

void show_STDC_VERSION_MATH_H (void)
{
	printf("__STDC_VERSION_MATH_H__ ");
	#ifdef __STDC_VERSION_MATH_H__
		printf("= %li\n", __STDC_VERSION_MATH_H__);
	#else
		printf("nie jest zdefiniowane\n");
	#endif
}

int main (void)
{
	puts("zdefiniowane makra:");
	show_STDC_VERSION_MATH_H ();

	#ifdef __STDC_IEC_559__
		puts("__STDC_IEC_559__");
	#endif

	#ifdef __STDC_IEC_60559_BFP__
		puts("__STDC_IEC_60559_BFP__");
	#endif
	#ifdef __STDC_IEC_60559_DFP__
		puts("__STDC_IEC_60559_DFP__");
	#endif
}

/* eof. */

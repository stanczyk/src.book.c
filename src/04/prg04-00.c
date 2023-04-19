/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg04-00.c
 * @brief stałe symboliczne
 */
#include <stdio.h>
int main (void)
{
	puts("zdefiniowane makra:");
	#ifdef __STDC_IEC_60559_BFP__
		printf("__STDC_IEC_60559_BFP__ %li\n", __STDC_IEC_60559_BFP__);
	#endif
	#ifdef __STDC_IEC_60559_DFP__
		printf("__STDC_IEC_60559_DFP__ %li\n", __STDC_IEC_60559_DFP__);
	#endif
	#ifdef __STDC_IEC_60559_COMPLEX__
		printf("__STDC_IEC_60559_COMPLEX__ %li\n", __STDC_IEC_60559_COMPLEX__);
	#endif
}

/* eof. */

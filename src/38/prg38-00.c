/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg38-00.c
 * @brief <tgmath.h>: dostępne stałe symboliczne
 */
#include <stdio.h>
#include <tgmath.h>

int main (void)
{
	puts("zdefiniowane makra:");
	#ifdef __STDC_VERSION_TGMATH_H__
		puts("__STDC_VERSION_TGMATH_H__");
	#endif
	#ifdef __STDC_NO_COMPLEX__
		puts("__STDC_NO_COMPLEX__");
	#endif
	#ifdef __STDC_IEC_60559_DFP__
		puts("__STDC_IEC_60559_DFP__");
	#endif
}

/* eof. */

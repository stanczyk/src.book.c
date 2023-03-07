/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg14-00.c
 * @brief <complex.h>: dostępne stałe symboliczne
 */
#include <complex.h>
#include <stdio.h>

int main (void)
{
	puts("zdefiniowane makra:");
	#ifdef __STDC_NO_COMPLEX__
		puts("__STDC_NO_COMPLEX__");
	#endif
	#ifdef __STDC_IEC_559_COMPLEX__
		puts("__STDC_IEC_559_COMPLEX__");
	#endif
	#ifdef __STDC_IEC_60559_COMPLEX__
		puts("__STDC_IEC_60559_COMPLEX__");
	#endif
	#ifdef complex
		puts("complex");
	#endif
	#ifdef _Complex_I
		puts("_Complex_I");
	#endif
	#ifdef imaginary
		puts("imaginary");
	#endif
	#ifdef _Imaginary_I
		puts("_Imaginary_I");
	#endif
}

/* eof. */

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
#include "../00/head0-01.h"

int main (void)
{
	SHOW_DEFINE(__STDC_VERSION__);
	SHOW_DEFINE(__STDC_VERSION_COMPLEX_H__);
	printf("\n" );

	printf("Obsługa liczb zmiennoprzecinkowych zespolonych\n");
	SHOW_DEFINE(__STDC_NO_COMPLEX__);
	SHOW_DEFINE(__STDC_IEC_559_COMPLEX__);
	SHOW_DEFINE(__STDC_IEC_60559_COMPLEX__);

	SHOW_DEFINE(complex);
	SHOW_DEFINE(imaginary);
	SHOW_DEFINE(I);
	SHOW_DEFINE(_Complex_I);
	SHOW_DEFINE(_Imaginary_I);
}

/* eof. */

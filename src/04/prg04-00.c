/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg04-00.c
 * @brief stałe symboliczne
 */
#include <complex.h>
#include <stdio.h>
#include "../00/head0-01.h"

int main (void)
{
	SHOW_DEFINE(__STDC_VERSION__);
	printf("\n" );

	printf("Obsługa UNICODE\n" );
	SHOW_DEFINE(__STDC_ISO_10646__);
	SHOW_DEFINE(__STDC_UTF_16__);
	SHOW_DEFINE(__STDC_UTF_32__);
	printf("\n" );

	printf("Obsługa liczb zmiennoprzecinkowych\n");
	SHOW_DEFINE(__STDC_IEC_559__);
	SHOW_DEFINE(__STDC_IEC_60559_BFP__);
	SHOW_DEFINE(__STDC_IEC_60559_DFP__);
	SHOW_DEFINE(__STDC_IEC_60559_TYPES__);
	printf("\n" );

	printf("Obsługa liczb zmiennoprzecinkowych zespolonych\n");
	SHOW_DEFINE(__STDC_NO_COMPLEX__);
	SHOW_DEFINE(__STDC_IEC_559_COMPLEX__);
	SHOW_DEFINE(__STDC_IEC_60559_COMPLEX__);
	SHOW_DEFINE(_Imaginary_I);
	printf("\n" );

	printf("Obsługa opcjonalnych rozszerzeń\n");
	SHOW_DEFINE(__STDC_LIB_EXT1__);
}

/* eof. */

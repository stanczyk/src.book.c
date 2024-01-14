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
#include "../00/head0-01.h"

int main (void)
{
	SHOW_DEFINE(__STDC_VERSION__);
	SHOW_DEFINE(__STDC_VERSION_MATH_H__);
	printf("\n" );

	printf("Obsługa liczb zmiennoprzecinkowych\n");
	SHOW_DEFINE(__STDC_IEC_559__);
	SHOW_DEFINE(__STDC_IEC_60559_BFP__);
	SHOW_DEFINE(__STDC_IEC_60559_DFP__);
	SHOW_DEFINE(__STDC_IEC_60559_TYPES__);
}

/* eof. */

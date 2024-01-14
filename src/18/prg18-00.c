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
#include "../00/head0-01.h"

int main (void)
{
	SHOW_DEFINE(__STDC_VERSION__);
	SHOW_DEFINE(__STDC_VERSION_FLOAT_H__);
	SHOW_DEFINE(__STDC_IEC_60559_DFP__);
}

/* eof. */

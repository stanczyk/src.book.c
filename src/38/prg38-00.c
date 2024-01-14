/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg38-00.c
 * @brief <tgmath.h>: dostępne stałe symboliczne
 */
#include <tgmath.h>
#include "../00/head0-01.h"

int main (void)
{
	SHOW_DEFINE(__STDC_VERSION__);
	SHOW_DEFINE(__STDC_VERSION_TGMATH_H__);
	SHOW_DEFINE(__STDC_NO_COMPLEX__);
	SHOW_DEFINE(__STDC_IEC_60559__);
}

/* eof. */

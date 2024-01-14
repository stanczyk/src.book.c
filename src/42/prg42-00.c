/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg42-00.c
 * @brief <wchar.h>: dostępne stałe symboliczne
 */
#include <wchar.h>
#include "../00/head0-01.h"

int main (void)
{
	SHOW_DEFINE(__STDC_VERSION__);
	SHOW_DEFINE(__STDC_VERSION_WCHAR_H__);
	SHOW_DEFINE(__STDC_IEC_60559_DFP__);
	SHOW_DEFINE(__STDC_LIB_EXT1__);
}

/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg32-00.c
 * @brief <stddef.h>: dostępne stałe symboliczne
 */
#include <stddef.h>
#include "../00/head0-01.h"

int main (void)
{
	SHOW_DEFINE(__STDC_VERSION__);
	SHOW_DEFINE(__STDC_VERSION_STDDEF_H__);
	SHOW_DEFINE(__STDC_LIB_EXT1__);
}

/* eof. */

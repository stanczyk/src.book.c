/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg34-00.c
 * @brief <stdio.h>: dostępne stałe symboliczne
 */
#include <stdio.h>
#include "../00/head0-01.h"

int main (void)
{
	SHOW_DEFINE(__STDC_VERSION__);
	SHOW_DEFINE(__STDC_VERSION_STDIO_H__);
	SHOW_DEFINE(__STDC_LIB_EXT1__);
}

/* eof. */

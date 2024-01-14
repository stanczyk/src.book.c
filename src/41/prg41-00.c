/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg41-00.c
 * @brief <uchar.h>: dostępne stałe symboliczne
 */
#include <uchar.h>
#include "../00/head0-01.h"

int main (void)
{
	SHOW_DEFINE(__STDC_VERSION__);
	SHOW_DEFINE(__STDC_VERSION_UCHAR_H__);
	SHOW_DEFINE(__STDC_UTF_16__);
	SHOW_DEFINE(__STDC_UTF_32__);
}

/* eof. */

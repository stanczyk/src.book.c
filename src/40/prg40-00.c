/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg40-00.c
 * @brief <time.h>: dostępne stałe symboliczne
 */
#include <time.h>
#include "../00/head0-01.h"

int main (void)
{
	SHOW_DEFINE(__STDC_VERSION__);
	SHOW_DEFINE(__STDC_VERSION_TIME_H__);
	SHOW_DEFINE(TIME_MONOTONIC);
	SHOW_DEFINE(TIME_ACTIVE);
	SHOW_DEFINE(TIME_THREAD_ACTIVE);
	SHOW_DEFINE(__STDC_LIB_EXT1__);
}

/* eof. */

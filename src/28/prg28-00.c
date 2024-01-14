/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg28-00.c
 * @brief <stdatomic.h>: dostępne stałe symboliczne
 */
#include <stdatomic.h>
#include "../00/head0-01.h"

int main (void)
{
	SHOW_DEFINE(__STDC_VERSION__);
	SHOW_DEFINE(__STDC_VERSION_STDATOMIC_H__);
	SHOW_DEFINE(__STDC_NO_ATOMICS__);
}

/* eof. */

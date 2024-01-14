/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg31-00.c
 * @brief <stdckdint.h>: dostępne stałe symboliczne
 */
// #include <stdckdint.h>  // gcc 12 i 13 (13.1.0, 13.2.0) jeszcze nie zawiera tego pliku nagłówkowego
#include "../00/head0-01.h"

int main (void)
{
	SHOW_DEFINE(__STDC_VERSION__);
	SHOW_DEFINE(__STDC_VERSION_STDCKDINT_H__);
}

/* eof. */

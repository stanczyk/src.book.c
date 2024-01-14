/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg29-00.c
 * @brief <stdbit.h>: dostępne stałe symboliczne
 */
// #include <stdbit.h> gcc 13.1.0 jeszcze nie zawiera tego pliku nagłówkowego
#include "../00/head0-01.h"

int main (void)
{
	SHOW_DEFINE(__STDC_VERSION__);
	SHOW_DEFINE(__STDC_VERSION_STDBIT_H__);
	SHOW_DEFINE(__STDC_ENDIAN_LITTLE__);
	SHOW_DEFINE(__STDC_ENDIAN_BIG__);
	SHOW_DEFINE(__STDC_ENDIAN_NATIVE__);
}

/* eof. */

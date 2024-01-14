/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-00.c
 * @brief stałe symboliczne
 */
#include "../00/head0-01.h"

int main (void)
{
	SHOW_DEFINE(__STDC_VERSION__);
	SHOW_DEFINE(__STDC_NO_VLA__);
	SHOW_DEFINE(__STDC_ISO_10646__);
	SHOW_DEFINE(__STDC_UTF_16__);
	SHOW_DEFINE(__STDC_UTF_32__);
}

/* eof. */

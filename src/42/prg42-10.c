/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg42-10.c
 * @brief <wchar.h>: konwersja znaku wielobajtowego na znak rozszerzony
 */
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#define EUR u8"\u20ac"
int main (void)
{
	setlocale (LC_ALL, "pl_PL.UTF-8");
	mbstate_t stan;
	memset (&stan, 0, sizeof stan);

	wchar_t wc;
	int dl = mbrtowc (&wc, EUR, 5, &stan);
	wprintf (L"znak %lc zajmuje %d bajty \n", wc, dl);
}

/* eof. */

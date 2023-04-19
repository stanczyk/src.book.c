/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg42-11.c
 * @brief <wchar.h>: konwersja łańcucha wielobajtowego UTF-8 na łańcuch znaków rozszerzonych
 */
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
int main (void)
{
	const char * msg = u8"źdźbła zbóź";
	// const char * msg = u8"\U0001f61d \xF0\x9F\x87\xB5 \xF0\x9F\x87\xB1";
	setlocale (LC_ALL, "pl_PL.UTF-8");
	mbstate_t stan;
	memset (&stan, 0, sizeof stan);
	size_t dl = 1 + mbsrtowcs(NULL, &msg, 0, &stan);
	wchar_t wyn[dl];
	mbsrtowcs(&wyn[0], &msg, dl, &stan);
	wprintf (L"łańcuch rozszerzony: %ls\n", wyn);
	wprintf (L"długość łańcucha (ze znakiem null): %zu\n", dl);
}

/* eof. */

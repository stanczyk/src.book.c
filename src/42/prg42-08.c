/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg42-08.c
 * @brief <wchar.h>: program sprawdzający, czy dane kodowanie jest zależne od stanu
 * i czy jest w stanie początkowym, na przykładzie kodowania pl_PL.UTF-8
 */
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

int main (void)
{
	wchar_t wc[8];

	setlocale (LC_ALL, "pl_PL.UTF-8");
	int zalezy_od_stanu = mbtowc (NULL, NULL, 0);
	wprintf (L"Kodowanie zależy od stanu? %s\n", zalezy_od_stanu ? "tak" : "nie");

	mbstate_t stan;
	memset (&stan, 0, sizeof stan);
	wprintf (L"kodowanie jest w stanie początkowym? %s\n", mbsinit (&stan) ? "tak" : "nie");

	mbrtowc (wc, "Ą", 8, &stan);
	wprintf (L"kodowanie jest w stanie początkowym? %s\n", mbsinit (&stan) ? "tak" : "nie");
}

/* eof. */

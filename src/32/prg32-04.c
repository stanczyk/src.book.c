/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg32-04.c
 * @brief <stddef.h>: użycie typu wchar_t
 */
#include <locale.h>
#include <stdint.h>
#include <wchar.h>

int main (void)
{
	setlocale (LC_ALL, "");
	wprintf (L"rozmiar typu wchar_t: %zu bajtów (%u bitów)\n", sizeof (wchar_t), WCHAR_WIDTH);
	wchar_t wc = L'\x3b2';  // beta
	wprintf (L"%lc\n", wc);
}

/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg43-03.c
 * @brief <wctype.h>: konwersja znaku
 */
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
int main (void)
{
	setlocale (LC_CTYPE, "pl_PL.UTF-8");
	wint_t wc = L'Ą';

	wprintf (L"znak: \'%lc\'\n", wc);
	wprintf (L"towlower = %lc\n", towlower (wc));
	wprintf (L"towupper = %lc\n", towupper (wc));

	wprintf (L"towlower = %lc\n", towctrans(wc, wctrans("tolower")));
	wprintf (L"towupper = %lc\n", towctrans(wc, wctrans("toupper")));
}

/* eof. */

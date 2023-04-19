/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg43-01.c
 * @brief <wctype.h>: klasyfikacja znaku rozszerzonego
 */
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
int main (void)
{
	setlocale (LC_CTYPE, "pl_PL.UTF-8");
	// setlocale (LC_CTYPE, "ja_JP.UTF-8");
	wint_t wc = L'Ą';
	// wint_t wc = L'六';

	wprintf (L"znak: L\'%lc\'\n", wc);
	wprintf (L" iswalnum: %s\n", iswalnum (wc) ? "prawda" : "fałsz");
	wprintf (L" iswalpha: %s\n", iswalpha (wc) ? "prawda" : "fałsz");
	wprintf (L" iswblank: %s\n", iswblank (wc) ? "prawda" : "fałsz");
	wprintf (L" iswcntrl: %s\n", iswcntrl (wc) ? "prawda" : "fałsz");
	wprintf (L" iswdigit: %s\n", iswdigit (wc) ? "prawda" : "fałsz");
	wprintf (L" iswgraph: %s\n", iswgraph (wc) ? "prawda" : "fałsz");
	wprintf (L" iswlower: %s\n", iswlower (wc) ? "prawda" : "fałsz");
	wprintf (L" iswprint: %s\n", iswprint (wc) ? "prawda" : "fałsz");
	wprintf (L" iswpunct: %s\n", iswpunct (wc) ? "prawda" : "fałsz");
	wprintf (L" iswspace: %s\n", iswspace (wc) ? "prawda" : "fałsz");
	wprintf (L" iswupper: %s\n", iswupper (wc) ? "prawda" : "fałsz");
	wprintf (L"iswxdigit: %s\n", iswxdigit (wc) ? "prawda" : "fałsz");
}

/* eof. */

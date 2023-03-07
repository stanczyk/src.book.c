/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg43-02.c
 * @brief <wctype.h>: lista wywołań funkcji iswctype równoważna wywołaniom z prg43-01
 */
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
int main (void)
{
	setlocale (LC_CTYPE, "pl_PL.UTF-8");
	wint_t wc = L'Ą';

	wprintf (L"znak: \'%lc\'\n", wc);
	wprintf (L"%d\n", iswctype (wc, wctype ("alnum")));	// iswalnum(wc)
	wprintf (L"%d\n", iswctype (wc, wctype ("alpha")));	// iswalpha(wc)
	wprintf (L"%d\n", iswctype (wc, wctype ("blank")));	// iswblank(wc)
	wprintf (L"%d\n", iswctype (wc, wctype ("cntrl")));	// iswcntrl(wc)
	wprintf (L"%d\n", iswctype (wc, wctype ("digit")));	// iswdigit(wc)
	wprintf (L"%d\n", iswctype (wc, wctype ("graph")));	// iswgraph(wc)
	wprintf (L"%d\n", iswctype (wc, wctype ("lower")));	// iswlower(wc)
	wprintf (L"%d\n", iswctype (wc, wctype ("print")));	// iswprint(wc)
	wprintf (L"%d\n", iswctype (wc, wctype ("punct")));	// iswpunct(wc)
	wprintf (L"%d\n", iswctype (wc, wctype ("space")));	// iswspace(wc)
	wprintf (L"%d\n", iswctype (wc, wctype ("upper")));	// iswupper(wc)
	wprintf (L"%d\n", iswctype (wc, wctype ("xdigit")));	// iswxdigit(wc)
}

/* eof. */

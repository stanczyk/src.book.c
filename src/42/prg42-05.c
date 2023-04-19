/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg42-05.c
 * @brief <wchar.h>: użycie funkcji fwscanf
 */
#include <locale.h>
#include <stdio.h>
#include <wchar.h>

int main (void)
{
	setlocale (LC_ALL, "pl_PL.UTF-8");

	int i;
	float x;
	double y;
	fwscanf(stdin, L"%2d%f%*d %lf", &i, &x, &y);

	wint_t wc;
	fwscanf(stdin, L"%lc", &wc);

	wprintf (L"i=%i\n", i);
	wprintf (L"x=%f\n", x);
	wprintf (L"y=%f\n", y);
	wprintf (L"wc=%lc\n", wc);
}

/* eof. */

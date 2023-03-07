/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg42-04.c
 * @brief <wchar.h>: użycie funkcji fwscanf
 */
#include <locale.h>
#include <stdio.h>
#include <wchar.h>

int main (void)
{
	setlocale (LC_ALL, "pl_PL.UTF-8");

	int n, i;
	float x;
	wchar_t name[50];

	n = fwscanf (stdin, L"%d%f%ls", &i, &x, name);

	wprintf (L"n=%i\n", n);
	wprintf (L"i=%i\n", i);
	wprintf (L"x=%f\n", x);
	wprintf (L"name=%ls\n", name);
}

/* eof. */

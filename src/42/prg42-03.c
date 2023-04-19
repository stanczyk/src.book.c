/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg42-03.c
 * @brief <wchar.h>: użycie funkcji vfwprintf w ogólnej procedurze raportowania błędów
 */
#include <locale.h>
#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>

void error(char *nazwa_funkcji, wchar_t *format, ...)
{
	va_list args;

	va_start(args, format);
	// wypisz nazwę funkcji powodującej błąd
	fwprintf(stderr, L"ERROR in %s: ", nazwa_funkcji);
	// wypisz pozostałą część komunikatu
	vfwprintf(stderr, format, args);
	va_end(args);
}

int main (void)
{
	setlocale (LC_ALL, "pl_PL.UTF-8");
	error("main", L"%ls\n", L"wystąpił jakiś błąd!");
}

/* eof. */

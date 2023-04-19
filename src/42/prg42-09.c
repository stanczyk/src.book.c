/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg42-09.c
 * @brief <wchar.h>: długość wybranych znaków na przykładzie kodowania pl_PL.UTF-8
 */
#include <locale.h>
#include <string.h>
#include <wchar.h>

int main (void)
{
	setlocale (LC_ALL, "pl_PL.UTF-8");
	mbstate_t stan;
	memset (&stan, 0, sizeof stan);
	wprintf (L"długość znaku 'A': %d\n", mbrlen ("A", 4, &stan));
	wprintf (L"długość znaku 'Ą': %d\n", mbrlen ("Ą", 4, &stan));
}

/* eof. */

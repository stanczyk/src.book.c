/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg42-02.c
 * @brief <wchar.h>: użycie fwprintf do wypisania na stdout daty i godziny,
 * a następnie wartości π do pięciu miejsc po przecinku
 */
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <wchar.h>

int main (void)
{
	setlocale (LC_ALL, "pl_PL.UTF-8");
	wchar_t *dzientyg = L"środa", *miesiac = L"maj";
	int dzien = 12, godz = 13, min = 14;

	fwprintf (stdout, L"%ls, %ls %d, %.2d:%.2d\n", dzientyg, miesiac, dzien, godz, min);
	fwprintf (stdout, L"pi = %.5f\n", 4 * atan (1.0));
}

/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg19-02.c
 * @brief <inttypes.h>: użycie makra specyfikatora formatu
 */
#include <inttypes.h>
#include <locale.h>
#include <wchar.h>

int main (void)
{
	setlocale (LC_ALL, "");
	uintmax_t i = UINTMAX_MAX;
	wprintf (L"Największa wartość całkowita 0x%020" PRIxMAX "\n", i);
}

/* eof. */

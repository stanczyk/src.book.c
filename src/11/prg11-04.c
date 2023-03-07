/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg11-04.c
 * @brief Makro __has_include
 *
 * Dołączenie pliku nagłówkowego jeśli istnieje
 */
#if __has_include("wersja-2.h")
#   include "wersja-2.h"
#   define WERSJA 2
#elif __has_include("wersja-1.h")
#   include "wersja-1.h"
#   define WERSJA 1
#endif
#ifndef WERSJA
#   define WERSJA 0
#endif

# include <stdio.h>

int main (void)
{
	printf("WERSJA = %d\n", WERSJA);
}

/* eof. */

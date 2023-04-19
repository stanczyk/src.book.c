/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg11-18.c
 * @brief Kompilacja warunkowa
 *
 * Dyrektywy #if, #elif, #else, #endif
 */
#include <stdio.h>
// #define INSTRUKCJA 1
int main (void)
{
	puts ("START");
#   if INSTRUKCJA == 1
		puts ("INSTRUKCJA == 1");
#   elif INSTRUKCJA == 2
		puts ("INSTRUKCJA == 2");
#   else
		puts ("INSTRUKCJA domyślna");
#   endif
	puts ("KONIEC");
}

/* eof. */

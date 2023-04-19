/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg35-12.c
 * @brief <stdlib.h>: odczyt zmiennych środowiska za pomocą funkcji getenv
 */
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	printf ("nazwa użytkownika: ");
	printf ("%s\n", getenv ("USER"));

	printf ("  katalog bieżący: ");
	printf ("%s\n", getenv ("PWD"));
}

/* eof. */

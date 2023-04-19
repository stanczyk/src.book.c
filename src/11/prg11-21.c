/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg11-21.c
 * @brief Kompilacja warunkowa
 */
#include <stdio.h>
// #define DEBUG

int main (void)
{
#ifdef DEBUG
	puts ("Wersja deweloperska z włączonym dodatkowym poziomem logowania");
	/*
	...
	*/
#else
	puts ("Wersja produkcyjna");
	/*
	...
	*/
#endif
	/*
	...
	*/
}

/* eof. */

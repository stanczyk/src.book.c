/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg11-01.c
 * @brief Dyrektywa podzielona na wiersze
 */
// Makrodefinicja zwracająca losową liczbę typu int z podanego zakresu
#define WYLOSUJ_INT(min, max) \
	((rand() % (int) (((max) + 1) - (min))) + (min))

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	srand (time (NULL));  // inicjowanie generatora liczb losowych
	printf ("Wylosowano: %i\n", WYLOSUJ_INT (10, 20));
}

/* eof. */

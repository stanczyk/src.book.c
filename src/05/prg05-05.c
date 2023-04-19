/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-05.c
 * @brief Użycie tablicy
 */
#include <stdio.h>
#define TABSIZE 4

int main (void)
{
	int tab[TABSIZE];
	// wprowadzanie elementów do tablicy
	for (int index = 0; index < TABSIZE; ++index)
	{
		printf ("podaj element tab[%i]: ", index);
		scanf ("%i", &tab[index]);
	}
	// wyświetlanie elementów tablicy
	for (int index = 0; index < TABSIZE; ++index)
		printf ("tab[%i] = %i  ", index, tab[index]);
	printf ("\n");
}

/* eof. */

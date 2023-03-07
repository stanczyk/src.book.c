/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg09-09.c
 * @brief Instrukcja continue
 */
#include <stdio.h>

int main (void)
{
	for (int i = 10; i ; i--)
	{
		if (i % 2)
			continue; 	// dla wartości nieparzystych pomiń dalszą część pętli
		printf ("%i ", i);
	}
	printf("\n");
}

/* eof. */

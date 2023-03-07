/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg04-06.c
 * @brief Przekroczenie zakresu dla typu int (integer overflow)
 */
#include <stdio.h>
#include <limits.h>

int main (void)
{
	int i = INT_MAX;
	printf ("%i %i\n", i, i + 1);
}

/* eof. */

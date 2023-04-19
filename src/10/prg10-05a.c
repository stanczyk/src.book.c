/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg10-05a.c
 * @brief Specyfikator inline
 */
#include <stdio.h>
static inline int max (int x, int y)
{
	return (x >= y ? x : y);
}

int main (void)
{
	int a = 10, b = 9;
	printf ("max = %d\n", max (a, b));
}

/* eof. */

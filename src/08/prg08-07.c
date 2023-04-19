/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg08-07.c
 * @brief Operatory inkrementacji i dekrementacji
 */
// #pragma GCC diagnostic ignored "-Wsequence-point"
#include <stdio.h>

int main (void)
{
	int a = 3, b, c;
	b = a--;    // po wykonaniu operacji b = 3, a = 2
	printf ("a = %i, b = %i\n", a, b);

	c = --b;    // po wykonaniu operacji b = 2, c = 2
	printf ("b = %i, c = %i\n", b, c);

	a = a++;
	printf ("a = %i\n", a);

	a = a++ + ++a;
	printf ("a = %i\n", a);
}

/* eof. */

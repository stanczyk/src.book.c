/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-28.c
 * @brief Unia
 *
 * Poniższa deklaracja tworzy typ unii o identyfikatorze liczba z dwoma składowymi li i ld
 */
#include <stdio.h>

int main (void)
{
	union liczba
	{
		int li;
		double ld;
	};

	printf ("%zu, %zu, %zu\n", sizeof (int), sizeof (double), sizeof (union liczba));

	union liczba ltab[10];
	ltab[0].ld = 1.234;
	printf ("ltab[0].ld=%f\n", ltab[0].ld);

	union liczba dlugosc = { 100 };
	printf ("dlugosc.li=%i\n", dlugosc.li);
}

/* eof. */

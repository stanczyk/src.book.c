/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg32-03.c
 * @brief <stddef.h>: użycie typu size_t
 */
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

int main (void)
{
	printf ("rozmiar typu size_t: %zu bajtów (%u bitów)\n", sizeof(size_t), SIZE_WIDTH);
	printf ("maksymalna możliwa do przechowania wartość: %zu\n", SIZE_MAX);

	size_t res = sizeof (int);
	printf ("rozmiar typu int: %zu bajty\n", res);
	int tab[1024];
	res = sizeof(tab);
	printf ("rozmiar tablicy int tab[1024]: %zu bajty\n", res);
}

/* eof. */

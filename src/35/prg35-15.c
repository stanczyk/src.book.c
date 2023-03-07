/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg35-15.c
 * @brief <stdlib.h>: przeszukiwanie tablicy za pomocą bsearch
 */
#include <stdio.h>
#include <stdlib.h>

int values[] = { 5, 20, 23, 29, 32 };

int compar (const void *a, const void *b)
{
	return (*(int *) a - *(int *) b);
}

int main (void)
{
	int *item;
	int key = 29;

	item = (int *) bsearch (&key, values, sizeof (values) / sizeof (int), sizeof (int), compar);

	if (item)
	{
		printf ("znaleziono wartość %d\n", *item);
	} else {
		printf ("nie znaleziono wartości %d\n", key);
	}
}

/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg35-14.c
 * @brief <stdlib.h>: sortowanie tablicy przy użyciu qsort
 */
#include <stdio.h>
#include <stdlib.h>

int tab[] = { 88, 56, 99, 2, 25 };

void wyswietl (void)
{
	int n, roz = sizeof (tab) / sizeof (int);
	for (n = 0; n < roz; n++)
		printf ("%2d ", tab[n]);
	printf ("\n");
}

int cmp (const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int main (void)
{
	printf ("przed sortowaniem: ");
	wyswietl ();

	int roz = sizeof (tab) / sizeof (int);
	qsort (tab, roz, sizeof (int), cmp);

	printf ("po sortowaniu:     ");
	wyswietl ();
}

/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-21.c
 * @brief Użycie arytmetyki wskaźników dla tablic o zmiennej długości
 */
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void tabPrint (int *tab, int x, int y)
{
	int i, j;

	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			printf ("%2i ", *((tab + i * y) + j));
		}
		printf ("\n");
	}
	printf ("\n");
}

void tabLoad (int *tab, int x, int y)
{
	for (int i = 0; i < x * y; i++)
	{
		*(tab + i) = i;
	}
}

void tablica(int n, int m)
{
	// int n = 4, m = 3;
	int a[n][m];
	tabLoad  ((int *) a, n, m);
	tabPrint ((int *) a, n, m);

	int (*p)[m] = a;  // p == &a[0]
	tabPrint ((int *) p, n, m);

	p += 1;           // p == &a[1]
	tabPrint ((int *) p, n-1, m);

	(*p)[2] = 99;     // a[1][2] == 99
	tabPrint ((int *) p, n-1, m);

	n = p - a;        // n == 1
	printf("%2i\n", n);
}

int main (void)
{
	/*
	int n = 4, m = 3;
	int a[n][m];
	int (*p)[m] = a;    // p = &a[0]
	p += 1;             // p = &a[1]
	(*p)[2] = 99;       // (*p)[2] = a[1][2] = 99
	n = p - a;          // n = p - a = 1
	*/
	srand(time(NULL));  // inicjowanie generatora liczb losowych
	                    // żeby wylosować rozmiar tablicy
	                    // i wypełnić ją losowymi wartościami
	int n = rand() % 10 + 1;  // liczba losowa z zakresu 1-10
	int m = rand() % 10 + 1;  // liczba losowa z zakresu 1-10
	printf("n = %i, m = %i\n", n, m);

	tablica(m, n);
}

/* eof. */

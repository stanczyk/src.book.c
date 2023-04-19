/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-27.c
 * @brief Struktura z elastyczną tablicą (musi być ostatnim elementem struktury)
 */
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct str
{
	double db;
	int tab[];  // str.tab jest tablicą o elastycznej długości
};

int main (void)
{
	printf ("rozmiar struktury: %zu bajt.\n", sizeof (struct str));
	printf ("offset  pola  tab: %zu bajt.\n", offsetof (struct str, tab));

	struct str t1 = { 0.9 };        // OK, ale t1.tab jest niezainicjowane
	printf ("t1.db = %f\n", t1.db);
	/*
	struct str t2 = { 1.2, { 1 } }; // błąd: inicjalizacja ignoruje elastyczną tablicę
	*/
	struct str *s1 = malloc(sizeof (struct str) + (4 * sizeof(int)));
									// s1->tab ma rozmiar 4
	s1->tab[3] = 3;
	int *wsk = &(s1->tab[2]);
	*wsk = 2;						//czyli s1->tab[2] = 2

	printf ("s1->tab[2] = %d\n", s1->tab[2]);
	printf ("s1->tab[3] = %d\n", s1->tab[3]);
}

/* eof. */

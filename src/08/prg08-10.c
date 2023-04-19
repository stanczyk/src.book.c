/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg08-10.c
 * @brief Działanie operatorów logicznych
 */
#include <stdio.h>

int main (void)
{
	int x = 18, y = 19;

	printf (" koniunkcja: %i && %i = %d\n", x, y, x && y);
	printf ("alternatywa: %i || %i = %d\n", x, y, x || y);
	printf ("    negacja:     ! %i = %d\n", x, !x);

	/*
	!x || y    // (nie x) lub y
	           // zwraca 1 (prawda) jeśli x == 0 lub y != 0
	 */
	printf ("   !x || y: !%i || %i = %d\n", x, y, !x || y);

	/*
	y < max && scanf("%d", &x) == 1
	 */
	int max = 10;

	if (y < max && scanf ("%d", &x) == 1)
		printf ("warunek spełniony\n");
	printf ("i to tyle\n");
}

/* eof. */

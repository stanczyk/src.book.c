/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg08-06.c
 * @brief Typ wyniku operacji
 */
// #pragma GCC diagnostic ignored "-Woverflow"
#include <stdio.h>
#include <limits.h>

int main (void)
{
	float a = 7 / 2;
	printf ("%f\n", a);
	// wynik 3.0 a nie 3.5, spróbujmy jeszcze raz:
	a = 7.0 / 2;
	printf ("%f\n", a);  // wynik 3.5

	float b = 10 * 1000 * 1000 * 1000;
	printf ("%f\n", b);
	// przepełnienie, spróbujmy jeszcze raz:
	b = (float) 10 * 1000 * 1000 * 1000;
	printf ("%f\n", b);

	int tmp = INT_MAX;
	float c = tmp + 13;
	printf ("%f\n", c);
}

/* eof. */

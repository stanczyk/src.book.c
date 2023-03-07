/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg08-13.c
 * @brief Operator warunkowy ?: w przykładach
 */
#include <stdio.h>

int main (void)
{
	char a = 1, b = 2, c = 3;
	double x = 1.0, y = 2.0, wynik;

	// zapis:
	if (a > b)
	{
		wynik = x;
	} else {
		wynik = y;
	}
	printf ("wynik = %.2f\n", wynik);
	// jest równoważny:
	wynik = a > b ? x : y;
	printf ("wynik = %.2f\n", wynik);

	// inne przykłady
	a = (b >= c) ? b : c; // jeśli b jest większe bądź równe c, to
	                      // a jest równe b, w przeciwnym wypadku
	                      // a jest równe c
	printf ("a = %d\n", a);

	// a = a < 0 ? -a : a;   // moduł z a
	printf ("a = %d\n", a = a < 0 ? -a : a);
	a = -5;
	printf ("a = %d\n", a = a < 0 ? -a : a);
}

/* eof. */

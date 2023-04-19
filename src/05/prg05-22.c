/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-22.c
 * @brief Użycie jednego wskaźnika do wywołania różnych funkcji
 */
#include <stdio.h>

int suma (int a, int b)
{
	return a + b;
}

int kwadrat (int a)
{
	return a * a;
}

int main (void)
{
	int (*wsk) ();

	wsk = suma;
	printf ("4 + 5 = %d\n", wsk (4, 5));

	wsk = kwadrat;
	printf ("4 * 4 = %d\n", wsk (4));
}

/* eof. */

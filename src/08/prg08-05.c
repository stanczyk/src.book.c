/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg08-05.c
 * @brief Problem nieokreślonej kolejności wyliczania argumentów
 *
 * Problem nieokreślonej kolejności wyliczania argumentów, w tym wypadku argumentów dodawania
 * podejście 1 - kolejność wywołań niezdefiniowana
 * podejście 2 - kolejność wymuszona fun(2), fun(1)
 */
#include <stdio.h>
// #define VER2

int fun (int a)
{
	printf ("%d ", a);
	return a;
}

int main (void)
{
#ifndef VER2
	// podejście 1:
	// kolejność wywołań niezdefiniowana
	return (fun (1) + fun (2));
#else
	// podejście 2:
	// wymuszona kolejność wywołań
	int tmp = fun (2);
	return (fun (1) + tmp);
#endif
}

/* eof. */

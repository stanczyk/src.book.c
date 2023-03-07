/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg09-11.c
 * @brief Instrukcja return
 */
#include <stdio.h>

int max (int a, int b)	// maksimum z a i b
{
	return (a > b ? a : b);
}

int main (void)
{
	int a = 3;
	int b = 8;

	return printf ("max(%i, %i) = %i\n", a, b, max (a, b));
}

/* eof. */

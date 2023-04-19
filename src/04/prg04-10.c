/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg04-10.c
 * @brief Błąd zaokrąglenia zmiennoprzecinkowego
 */
#include <stdio.h>

int main (void)
{
	float a, b;

	b = 2.0e20 + 1.0;
	a = b - 2.0e20;
	printf ("%g\n", a);
}

/* eof. */

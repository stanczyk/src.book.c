/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg14-05.c
 * @brief <complex.h>: pragma CX_LIMITED_RANGE
 *
 * Różnica w czasie obliczeń wartości bezwzględnej pomiędzy obliczeniami z włączonym i wyłączonym CX_LIMITED_RANGE
 */
#include <complex.h>
#include <stdio.h>
#include <time.h>
// prototypy
static void use_CX_LIMITED_RANGE (void);
// deklaracje
static void use_CX_LIMITED_RANGE (void)
{
	double complex z = 10.10 + 10.10 * (double complex) I;
	double d = 0.0;
	clock_t c1, c2;

#pragma STDC CX_LIMITED_RANGE ON

	c1 = clock ();
	for (int i = 0; i < 100000; ++i)
		d = cabs (z);
	c2 = clock ();

	printf ("CX_LIMITED_RANGE ON %lu cpu clock\n", c2 - c1);
	printf ("|z| = %f\n", d);

#pragma STDC CX_LIMITED_RANGE OFF

	c1 = clock ();
	for (int i = 0; i < 100000; ++i)
		d = cabs (z);
	c2 = clock ();

	printf ("CX_LIMITED_RANGE OFF %lu cpu clock\n", c2 - c1);
	printf ("|z| = %f\n", d);
}

int main (void)
{
	use_CX_LIMITED_RANGE ();
}

/* eof. */

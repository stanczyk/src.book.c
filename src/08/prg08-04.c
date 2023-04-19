/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg08-04.c
 * @brief Przykładowa implementacja ogólnego makra cbrt (pierwiastek sześcienny) przy użyciu _Generic
 */
#include <math.h>
#include <stdio.h>

#define mycbrt(X) _Generic((X), \
	long double: cbrtl, \
	float: cbrtf, \
	default: cbrt \
) (X)

int main (void )
{
	float a = 8.0;
	double b = 27.0;
	long double c = 64.0;

	printf ("pierwiastek sześcienny\n");
	printf ("z  8 = %.2f\n", mycbrt(a));
	printf ("z 27 = %.2f\n", mycbrt(b));
	printf ("z 64 = %.2Lf\n", mycbrt(c));
}


/* eof. */

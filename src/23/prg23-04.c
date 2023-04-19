/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg23-04.c
 * @brief <math.h>: użycie funkcji trygonometrycznych na przykładzie funkcji sin
 */
#include <errno.h>
#include <fenv.h>
#include <math.h>
#include <stdio.h>

#pragma STDC FENV_ACCESS ON
int main (void)
{
	double pi = acos (-1);

	printf ("typowe obliczenia\n");
	printf (" sin(pi/6)    = %+.2f\n", sin (pi / 6));
	printf (" sin(pi/2)    = %+.2f\n", sin (pi / 2));
	printf (" sin(-3*pi/4) = %+.2f\n", sin (-3 * pi / 4));

	printf ("wartości specjalne\n");
	printf (" sin(+0)      = %+.2f\n", sin (0.0));
	printf (" sin(-0)      = %+.2f\n", sin (-0.0));

	printf ("zgłaszanie błędów\n");
	feclearexcept (FE_ALL_EXCEPT);
	printf (" sin(INFINITY)= %f\n", sin ((double) INFINITY));
	if (fetestexcept (FE_INVALID))
		printf (" zgłoszono wyjątek: FE_INVALID\n");
}

/* eof. */

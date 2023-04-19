/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg38-01.c
 * @brief <tgmath.h>: wywołanie sqrt dla kilku wybranych typów
 */
#include <complex.h>
#include <stdio.h>
#include <tgmath.h>

int main (void)
{
	// obliczenia typu double
	double d = 11.1;
	double wynd = sqrt (d);
	printf ("double: %f\n", wynd);

	// obliczenia typu long double
	long double ld = 22.2;
	long double wynld = sqrt (ld);
	printf ("long double: %Lf\n", wynld);

	// obliczenia typu double complex
	double complex dc = CMPLX(1.1, 2.2);
	double complex wyndc = sqrt (dc);
	printf ("double complex: %f + %fi\n", creal(wyndc), cimag(wyndc));
}

/* eof. */

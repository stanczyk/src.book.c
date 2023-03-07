/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg14-02.c
 * @brief <complex.h>: konstrukcja liczb zespolonych przy użyciu _Complex_I
 */
#include <stdio.h>
#include <complex.h>

int main (void)
{
	double complex z1 = (double) 1 - _Complex_I * (double) 2;
	printf("z1 = % .2f%+.2fi\n", creal(z1), cimag(z1));

	double complex z2 = _Complex_I * _Complex_I;
	printf("z2 = % .2f%+.2fi\n", creal(z2), cimag(z2));
}

/* eof. */

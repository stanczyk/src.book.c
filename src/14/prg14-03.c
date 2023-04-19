/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg14-03.c
 * @brief <complex.h>: konstrukcja liczb urojonych przy użyciu _Imaginary_I
 */
#include <stdio.h>
#include <complex.h>

int main (void)
{
	#ifndef _Imaginary_I
		printf("_Imaginary_I niewspierany\n");
	#else
		printf("_Imaginary_I wspierany\n");

		double imaginary z = _Imaginary_I * (double) 3;
		printf("z = %+.2fi\n", cimag(z));
	#endif
}

/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg04-14.c
 * @brief Proste obliczenia na liczbach zespolonych
 */
#ifdef __STDC_NO_COMPLEX__
#error brak wsparcia dla liczb zespolonych
#endif

#include <stdio.h>
#include <complex.h>

int main (void)
{
	double complex z = 1 - 2*I;
	printf("z = %.2f%+.2fi\n", creal(z), cimag(z));

	z *= I; // obrót z o 90 stopni
			// w kierunku przeciwnym do ruchu wskazówek zegara
			// względem początku układu współrzędnych
	printf("z = %.2f%+.2fi\n", creal(z), cimag(z));
}

/* eof. */

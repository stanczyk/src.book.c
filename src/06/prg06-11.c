/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-11.c
 * @brief Kwalifikator const
 */
#include <stdio.h>

int main (void)
{
	const double pi = 3.14;
	printf("wartość pi = %.2f\n", pi);
	// pi += 1.0;   // operacja niedozwolona, powodująca błąd kompilacji

	// ale taka modyfikacja jest dopuszczalna:
	double *wsk = (double *) &pi;
	*wsk += 1.0;
	printf("zmodyfikowana wartość pi: %.2f \n", pi);
}

/* eof. */

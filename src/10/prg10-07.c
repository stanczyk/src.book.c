/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg10-07.c
 * @brief Przekazywanie parametrów funkcji poprzez adres
 */
#include <stdio.h>

void zamiana( double *px, double *py ) 	// zamiana wartości dwóch parametrów
{
	double z = *px;
	*px = *py;
	*py = z;
}

int main (void)
{
	double a = 1.0, b = 0.2;
	printf("przed zamianą: a=%.2f, b=%.2f\n", a, b);
	zamiana(&a, &b);
	printf("  po zamianie: a=%.2f, b=%.2f\n", a, b);
}


/* eof. */

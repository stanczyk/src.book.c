/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg13-01.c
 * @brief <assert.h>: użycie makra assert do sprawdzenia wartości x
 */
// #define NDEBUG  // wyłącza działanie assert()
#include <assert.h>
#include <stdio.h>
#include <math.h>

int main (void)
{
	double x = -1.0;

	assert (x >= 0.0);
	printf ("sqrt(x) = %f\n", sqrt (x));
}

/* eof. */

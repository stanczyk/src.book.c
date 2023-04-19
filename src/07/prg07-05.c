/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg07-05.c
 * @brief Przykładowe szesnastkowych stałe zmiennoprzecinkowe
 */
#include <stdio.h>
#include <math.h>

int main (void)
{
	printf ("reprezentacja szesnastkowa i wartość dziesiętna:\n");
	printf ("0x1.0p+1  = %f\n", 0x1.0p+1);  // bo 1.0 * 2^1 = 2
	printf ("0xa.fP-10 = %f == %f\n", 0xa.fP-10, (10.0 + (15.0 / 16.0)) * pow (2.0, -10));
	printf ("0x2.7P+3  = %f == %f\n", 0x2.7P+3, (2.0 + (7.0 / 16.0)) * pow (2.0, 3));
}

/* eof. */

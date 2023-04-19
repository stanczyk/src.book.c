/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg23-03.c
 * @brief <math.h>: porównywanie liczb zmiennoprzecinkowych.
 */
#include <math.h>
#include <stdio.h>

int main (void)
{
	printf("isgreater(2.0, 1.0)      = %d\n", isgreater(2.0, 1.0));
	printf("isgreater(1.0, 2.0)      = %d\n", isgreater(1.0, 2.0));
	printf("isgreater(INFINITY, 1.0) = %d\n", isgreater(INFINITY, 1.0));
	printf("isgreater(1.0, NAN)      = %d\n", isgreater(1.0, NAN));
}

/* eof. */

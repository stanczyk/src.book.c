/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg11-15.c
 * @brief Dyrektywy preprocesora
 *
 * Operator ##
 */
#include <stdio.h>

#define SHOW_DBL( var, num )  \
	printf( #var #num " = %.2f\n", var ## num )

int main (void)
{
	double x5 = 16.5;
	SHOW_DBL(x, 5);
}

/* eof. */

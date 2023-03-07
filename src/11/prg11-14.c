/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg11-14.c
 * @brief Dyrektywy preprocesora
 *
 * Operator #
 */
#include <stdio.h>

#define WYPISZ_INT(x) printf ("wartość %s = %i \n", #x, x)

int main (void)
{
	int x = 5, y = 3;

	WYPISZ_INT (x);
	WYPISZ_INT (x - y);
}

/* eof. */

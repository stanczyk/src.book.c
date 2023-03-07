/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg07-06.c
 * @brief Stałe zmiennoprzecinkowe spoza zakresu
 *
 * Przykład zaczerpnięty z https://en.cppreference.com/w/c/language/floating_constant
 */
#include <stdio.h>

int main (void)
{
	printf ("+2.0e+308 --> %g\n",  2.0e+308);
	printf ("-2.0e+308 --> %g\n", -2.0e+308);
	printf ("+1.0e-324 --> %g\n",  1.0e-324);
	printf ("-1.0e-324 --> %g\n", -1.0e-324);
}

/* eof. */

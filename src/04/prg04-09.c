/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg04-09.c
 * @brief Wybrane parametry typów zmiennoprzecinkowych
 */
#include <stdio.h>
#include <float.h>

int main (void)
{
	printf ("typ, rozmiar w bajach, wartość min i max, precyzja\n");
	printf ("--------------------------------------------------\n");
	printf ("float %zu %e %e %i\n", sizeof (float), FLT_MIN, FLT_MAX, FLT_DIG);
	printf ("double %zu %e %e %i\n", sizeof (double), DBL_MIN, DBL_MAX, DBL_DIG);
	printf ("long double %zu %Le %Le %i\n", sizeof (long double), LDBL_MIN, LDBL_MAX, LDBL_DIG);
}

/* eof. */

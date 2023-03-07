/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg17-01.c
 * @brief <fenv.h>: obsługa wyjątków zmiennoprzecinkowych z użyciem fetestexcept i feclearexcept
 */
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <fenv.h>
#pragma STDC FENV_ACCESS ON
#include "prg17-00.h"

int main (void)
{
	// FE_DIVBYZERO
	printf ("1.0/0.0 = %f\n", 1.0 / 0.0);
	fe_show_exeption ();
	feclearexcept (FE_ALL_EXCEPT);

	// FE_INVALID
	printf ("0.0/0.0 = %f\n", 0.0 / 0.0);
	fe_show_exeption ();
	feclearexcept (FE_ALL_EXCEPT);

	// FE_INEXACT, FE_OVERFLOW
	printf ("DBL_MAX * 2.0 = %f\n", DBL_MAX * 2.0);
	fe_show_exeption ();
	feclearexcept (FE_ALL_EXCEPT);

	// FE_INEXACT, FE_UNDERFLOW
	printf ("nextafter(DBL_MIN / pow(2.0, 52), 0.0) = %.1f\n", nextafter (DBL_MIN / pow (2.0, 52), 0.0));
	fe_show_exeption ();
	feclearexcept (FE_ALL_EXCEPT);
}

/* eof. */

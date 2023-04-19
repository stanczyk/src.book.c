/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg17-05.c
 * @brief <fenv.h>: pobierania i zapis środowiska zmiennoprzecinkowego
 */
#include <stdio.h>
#include <math.h>
#include <fenv.h>
#pragma STDC FENV_ACCESS ON
#include "prg17-00.h"

int main (void)
{
	fenv_t curr_env;
	double rezultat;

	// środowisko domyślne
	printf ("środowisko domyślne\n");
	fe_show_env ();

	// obliczenia w środowisku domyślnym
	printf ("...obliczenia...\n");
	rezultat = rint (+11.5);
	rezultat = rint (+12.5);
	fe_show_env ();

	// zapisz środowisko
	printf ("\nzapis stanu środowiska\n");
	fegetenv (&curr_env);

	// obliczenia z nową metodą zaokrąglania
	printf ("\nnowe środowisko\n");
	feclearexcept (FE_ALL_EXCEPT);
	fesetround (FE_DOWNWARD);
	printf ("...obliczenia...\n");
	rezultat = 1.0 / 0.0;
	rezultat = rint (+11.5);
	rezultat = rint (+12.5);
	fe_show_env ();

	// przywróć poprzednie środowisko
	printf ("\nodtworzenie środowiska zapisanego\n");
	fesetenv (&curr_env);
	fe_show_env ();
}

/* eof. */

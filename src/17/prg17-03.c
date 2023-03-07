/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg17-03.c
 * @brief <fenv.h>: obsługa wyjątków zmiennoprzecinkowych
 */
#include <fenv.h>
#include <stdio.h>
void fe_invalid (void)
{
	printf ("zgłoszono FE_INVALID\n");
}

void fe_overflow (void)
{
	printf ("zgłoszono FE_OVERFLOW\n");
}

/* ... */
int main (void)
{
	#pragma STDC FENV_ACCESS ON
	int set_excepts;
	feclearexcept (FE_INVALID | FE_OVERFLOW);
	/* ... */

	// sprawdzenie, czy zgłoszono wyjątki
	set_excepts = fetestexcept (FE_INVALID | FE_OVERFLOW);
	if (set_excepts & FE_INVALID) fe_invalid();
	if (set_excepts & FE_OVERFLOW) fe_overflow();
	/* ... */
}

/* eof. */

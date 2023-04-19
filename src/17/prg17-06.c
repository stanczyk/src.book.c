/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg17-06.c
 * @brief <fenv.h>: zapis i aktualizacja dynamicznego środowiska zmiennoprzecinkowego
 *
 * @warning
 * Fragment kodu
 */
#include <fenv.h>
#pragma STDC FENV_ACCESS ON

/* FRAGMENT KODU */
double f (double x)
{
	double result;
	fenv_t save_env;

	if (feholdexcept (&save_env))
		return /* wskazanie problemu środowiskowego */ ;

	/* ... obliczania ... */

	if ( /* testowanie wystąpienia FE_UNDERFLOW */ )
		if (feclearexcept (FE_UNDERFLOW))
			return /* wskazanie problemu środowiskowego */ ;

	if (feupdateenv (&save_env))
		return /* wskazanie problemu środowiskowego */ ;
	return result;
}

/* eof. */

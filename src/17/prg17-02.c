/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg17-02.c
 * @brief <fenv.h>: wyjątki zmiennoprzecinkowe z fegetexcept, fesetexcept i feraiseexcept
 */
#include <stdio.h>
#include <fenv.h>
#pragma STDC FENV_ACCESS ON
#include "prg17-00.h"

int main (void)
{
	fexcept_t excepts;

	// "bieżący" zestaw flag wyjątków
	feraiseexcept (FE_INVALID);
	fe_show_exeption ();

	// zapis aktualnych flag
	fegetexceptflag (&excepts, FE_ALL_EXCEPT);

	// zgłoszenie dwóch innych wyjątków (tymczasowo)
	feclearexcept (FE_ALL_EXCEPT);
	feraiseexcept (FE_OVERFLOW | FE_INEXACT);
	fe_show_exeption ();

	// przywrócenie poprzednich flag
	fesetexceptflag (&excepts, FE_ALL_EXCEPT);
	fe_show_exeption ();
}

/* eof. */

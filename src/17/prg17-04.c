/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg17-04.c
 * @brief <fenv.h>: kierunki zaokrąglania zmiennoprzecinkowego
 */
#include <stdio.h>
#include <math.h>
#include <fenv.h>
#pragma STDC FENV_ACCESS ON
#include "prg17-00.h"

int main (void)
{
	// ustawienia domyślne
	fe_show_round_direction ();
	printf ("+11.5 -> %+4.1f\n", rint (+11.5));
	printf ("+12.5 -> %+4.1f\n", rint (+12.5));

	// zapisz aktualny kierunek zaokrąglania
	int curr_direction = fegetround ();

	// zmiana kierunku zaokrąglania
	fesetround (FE_DOWNWARD);
	fe_show_round_direction ();
	printf ("+11.5 -> %+4.1f\n", rint (+11.5));
	printf ("+12.5 -> %+4.1f\n", rint (+12.5));

	// przywróć wartość domyślną
	fesetround (curr_direction);
	fe_show_round_direction ();
}

/* eof. */

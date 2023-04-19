/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg17-00.h
 * @brief <fenv.h>: wyjątki zmiennoprzecinkowe
 */
#ifndef PRG17_00_H
#define PRG17_00_H

#include <fenv.h>
#include <stdio.h>

void fe_show_exeption (void)
{
	if (fetestexcept (FE_ALL_EXCEPT) == 0)
		printf ("brak wyjątków\n");
	else
	{
		printf ("wystąpił wyjątek:");
		if (fetestexcept (FE_DIVBYZERO)) printf (" FE_DIVBYZERO");
		if (fetestexcept (FE_INEXACT))   printf (" FE_INEXACT");
		if (fetestexcept (FE_INVALID))   printf (" FE_INVALID");
		if (fetestexcept (FE_OVERFLOW))  printf (" FE_OVERFLOW");
		if (fetestexcept (FE_UNDERFLOW)) printf (" FE_UNDERFLOW");
		printf ("\n");
	}
}

void fe_show_round_direction (void)
{
	printf ("kierunek zaokrąglenia: ");
	switch (fegetround ())
	{
		case FE_TONEAREST:  printf ("FE_TONEAREST");  break;
		case FE_DOWNWARD:   printf ("FE_DOWNWARD");   break;
		case FE_UPWARD:     printf ("FE_UPWARD");     break;
		case FE_TOWARDZERO: printf ("FE_TOWARDZERO"); break;
		default:            printf ("nieznany");
	};
	printf ("\n");
}

void fe_show_env (void)
{
	fe_show_exeption ();
	fe_show_round_direction ();
}

#endif /* PRG17_00_H */

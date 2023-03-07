/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg35-04.c
 * @brief <stdlib.h>: konwersja łańcucha na liczbę zmiennoprzecinkową przy użyciu strtod
 */
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	char str[30] = "20.30300m3 cała objętość";
	char *wsk;
	double wynik = strtod (str, &wsk);
	printf (" wynik = %f\n", wynik);
	printf ("reszta = \"%s\"\n", wsk);
}

/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg15-01.c
 * @brief <ctype.h>: klasyfikacja znaku
 *
 * Program testuje czy wczytany znak jest cyfrą
 */
#include <ctype.h>
#include <stdio.h>

int main (void)
{
	int c = getchar ();	// odczytuję znak
	if (isdigit (c))	// czy odczytany znak jest cyfrą?
	{
		/*
		...
		 */
		printf ("znak \'%c\' jest cyfrą\n", c);
	}
	else
		printf ("znak \'%c\' nie jest cyfrą\n", c);
}

/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg09-02.c
 * @brief Instrukcje blokowe
 */
#include <stdio.h>

int main (void)
{
	{	// przykład bloku

		// deklaracje
		int i = 0;
		static long a;
		extern long max;

		// instrukcje
		++a;
		if (a >= max)
		{
			// blok zagnieżdżony
			// ...
			;
		}
		// ...
		;
	}
	//...
	;
	{
		// pusty blok
	}
}

/* eof. */

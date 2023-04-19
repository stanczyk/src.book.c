/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-07.c
 * @brief Specyfikator static
 *
 * Przykład użycia zmiennej static vs auto
 */
#include <stdio.h>

void auto_static (void)
{
			int intAuto = 0;
	static  int intStat = 0;

	printf ("auto = %i, static = %i\n", ++intAuto, ++intStat);
}

int main (void)
{
	for (int i = 0; i < 3; ++i)
		auto_static ();
}

/* eof. */

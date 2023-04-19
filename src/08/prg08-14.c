/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg08-14.c
 * @brief Kaskadowe łączenie operatorów warunkowych
 */
#include <stdio.h>
enum { AUTOBUS, TRAMWAJ, SAMOCHÓD, ROWER, PIESZO };
int main (void)
{
	char odp = 'T';
	int wybor;
	wybor = odp == 'A' ? AUTOBUS  :
			odp == 'T' ? TRAMWAJ  :
			odp == 'S' ? SAMOCHÓD :
			odp == 'R' ? ROWER    :
						 PIESZO;
	printf ("wybor = %i\n", wybor);
}

/* eof. */

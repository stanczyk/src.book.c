/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-17.c
 * @brief Poprawna sekwencja użycia wskaźnika
 *
 * Poprawna sekwencja użycia wskaźnika z prg05-16
 */
#include <stdio.h>

int main (void)
{
	int *p,   x;
		 p = &x;
		*p =  4;

	printf ("wartość wskazywana: %d\n", *p);
}

/* eof. */

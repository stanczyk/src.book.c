/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-16.c
 * @brief Błędne użycie wskaźnika, brak inicjalizacji
 *
 * Wartość wskaźnika nie wskazującego na nic. Błąd podczas wykonania! (Segmentation fault)
 * Poprawna sekwencja użycia -- patrz prg05-17.c
 */
#include <stdio.h>

int main (void)
{
	int *p;
		*p = 4;

	printf ("wartość wskazywana: %d\n", *p);
}

/* eof. */

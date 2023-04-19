/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-06.c
 * @brief Odwołanie do elementu spoza zakresu tablicy
 *
 * @warning
 * PRZYKŁAD NIEPOPRAWNY.
 * Zachowanie programu jest niezdefiniowane!
 *
 * Zwykle kończy się poprzez
 * 		 *** stack smashing detected ***: terminated
 * 		 Aborted (core dumped)
 */
#include <stdio.h>
#define SIZE_A 3
#define SIZE_B 2

int main (void)
{
	int tab_a[SIZE_A], tab_b[SIZE_B], idx;

	for (idx = 0; idx < SIZE_A + 2; ++idx)
		tab_a[idx] = 10 + idx;

	for (idx = 0; idx < SIZE_B + 3; ++idx)
		tab_b[idx] = idx;

	for (idx = 0; idx < SIZE_A + 2; ++idx)
		printf ("tab_a[%i] = %2i, ", idx, tab_a[idx]);
	printf ("\n");

	for (idx = 0; idx < SIZE_B + 3; ++idx)
		printf ("tab_b[%i] = %2i, ", idx, tab_b[idx]);
	printf ("\n");
}

/* eof. */

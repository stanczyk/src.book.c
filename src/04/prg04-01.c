/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg04-01.c
 * @brief Użycie typu _Bool
 */
#include <stdio.h>

_Bool czy_to_logiczne (void)
{
	return 0;	// 0 oznacza fałsz
}

int main (void)
{
	printf ("Czy logiczne? ");
	if (czy_to_logiczne ())
		printf ("tak.\n");
	else
		printf ("nie!\n");
}

/* eof. */

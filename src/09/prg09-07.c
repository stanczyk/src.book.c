/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg09-07.c
 * @brief Pętla for i jej równoważnik dla while
 */
#include <stdio.h>

#define DELAY 100

int main (void)
{
	for (int i = DELAY; i > 0; --i)
		;				// poczekaj chwilę

	// równoważna pętla while (inny jest zakresem zmiennej i):
	int i = DELAY;		// inicjalizacja
	while ( i > 0)		// test wyrażenia sterującego
		--i;			// aktualizacja zmiennej i
}

/* eof. */

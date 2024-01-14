/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg04-02.c
 * @brief Użycie typu bool
 */
#include <stdio.h>
#include <stdlib.h>
// #include <stdbool.h> w C23 dołączenie tego nagłówka nie jest konieczne, testowano z gcc 13.1.0

int main (void)
{
	bool kontynuuj = true;  // także poprawne: kontynuuj = 1;

	while (kontynuuj)
	{
		printf ("Pętla będzie działać, dopóki \"kontynuuj\" "
			"będzie prawdziwe.\n");
		kontynuuj = false;  // lub tożsame -> kontynuuj = 0;
	}
	printf ("Koniec!\n");
	return EXIT_SUCCESS;
}

/* eof. */

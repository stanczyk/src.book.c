/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-02.c
 * @brief Użycie typu wyliczeniowego bez znacznika
 */
#include <stdio.h>
enum { CZARNY, SZARY, NIEBIESKI, ZIELONY, CZERWONY };

int main (void)
{
	int kolor = CZARNY;

	printf ("kolor %i\n", kolor);
	printf ("kolor %i\n", NIEBIESKI);
}

/* eof. */

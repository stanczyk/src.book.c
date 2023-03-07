/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-08.c
 * @brief Tablica deklarowana niestatycznie (tablica o zmiennej długości)
 */
#include <stdio.h>

void deklaruj_tab (int a)
{
	int tab[a];
	printf ("ilość el.: %zi\n", sizeof tab / sizeof tab[0]);
}

int main (void)
{
	deklaruj_tab (5);
	deklaruj_tab (10);
}

/* eof. */

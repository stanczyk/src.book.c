/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg04-04.c
 * @brief Kod ASCII znaku podanego z klawiatury
 */
#include <stdio.h>

int main (void)
{
	char ch;

	printf ("Podaj znak: ");
	scanf ("%c", &ch);
	printf ("Kod ASCII dla \'%c\': %i\n", ch, ch);
}

/* eof. */

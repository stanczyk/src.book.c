/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-14.c
 * @brief Zmienna i jej adres
 */
#include <stdio.h>

int main (void)
{
	int x = 10;
	printf ("zmienna x = %d\n", x);
	printf ("adres   x = %p\n", (void *) &x);
}

/* eof. */

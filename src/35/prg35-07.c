/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg35-07.c
 * @brief <stdlib.h>: iloraz liczb całkowitych: funkcja div
 */
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int a = 5, b = 3;
	printf ("iloraz liczb całkowitych div(%d, %d)\n", a, b);
	div_t wynik = div (a, b);
	printf("wynik = %d, reszta = %d\n", wynik.quot, wynik.rem);
}

/* eof. */

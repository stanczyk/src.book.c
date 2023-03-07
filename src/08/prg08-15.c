/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg08-15.c
 * @brief Operator sekwencji (czyli operator przecinka)
 */
#include <stdio.h>

int main (void)
{
	int n = 1;
	int m = (++n, printf ("n = %i\n", n), ++n, 2 * n);
	printf ("m = %i\n", (++m, m));
}

/* eof. */

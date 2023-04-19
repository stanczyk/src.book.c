/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg08-21.c
 * @brief Operator sizeof dla typów i wyrażeń
 */
#include <stdio.h>

int main (void)
{
	// sizeof ( typ ) =====================================
	printf ("sizeof(char)     = %zu\n", sizeof (char));
	// printf("sizeof(char[])    = %zu\n", sizeof(char[]));	// BŁĄD: typ niekompletny
	printf ("sizeof(char[10]) = %zu\n", sizeof (char[10]));
	printf ("sizeof(double)   = %zu\n", sizeof (double));
	printf ("sizeof(void *)   = %zu\n", sizeof (void *));

	// sizeof wyrażenie ===================================
	printf ("sizeof 'a'       = %zu\n", sizeof 'a'); 		// typ 'a' to int
	printf ("sizeof \"hello\"   = %zu\n", sizeof "hello");	// inaczej rozmiar char[6]
	// printf("sizeof main       = %zu\n", sizeof main);	// BŁĄD: to funkcja

	short x;
	printf ("sizeof  x        = %zu\n", sizeof x);			// typ x to short
	printf ("sizeof(x + 1)    = %zu\n", sizeof (x + 1));	// typ wyrażenia x+1 to int
	printf ("sizeof(x + 1.0)  = %zu\n", sizeof (x + 1.0));	// typ wyrażenia x+1.0 to double

	// często przydatne: ilość elementów w tablicy:
	int tab[10];
	printf ("ilość el.tablicy = %zu\n", sizeof tab / sizeof(tab[0]));
}

/* eof. */

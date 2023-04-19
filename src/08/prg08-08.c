/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg08-08.c
 * @brief Operatory przypisania
 */
#include <stdio.h>

int main (void)
{
	int a, b;
	a = b = 100; 	// odpowiednik a = (b = 100);
					// wartość 100 jest przypisywana b i następnie do a.
	printf ("a = %i, b = %i\n", a, b);

	a += 5; 		// równoważne a = a + 5;
	printf ("a = %i\n", a);

	a *= b + 1; 	// a = a * (b + 1);
	printf ("a = %i, b = %i\n", a, b);
}

/* eof. */

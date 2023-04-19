/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg08-17.c
 * @brief Operatory dostępu do pamięci cz.2; tablice i wskaźniki
 */
#include <stdio.h>

int main (void)
{
	float a[10] = { 0.5, 1.5, 2.5, 3.5, 4.5 };
	for (int i = 0; i < 10; i++)
		printf ("a[%i] = %.2f ", i, a[i]);
	printf("\n\n");

	float * wsk;
	wsk = a;
	printf ("    a[3]   = %f\n", a[3]);
	printf ("  wsk[3]   = %f\n", wsk[3]);
	printf ("*(a + 3)   = %f\n", *(a + 3));
	printf ("      3[a] = %f\n", 3[a]);
}

/* eof. */

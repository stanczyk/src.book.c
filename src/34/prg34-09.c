/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg34-09.c
 * @brief <stdio.h>: różna precyzja dla Decimal32 użyta w printf
 */
#include <stdio.h>
int main (void)
{
	_Decimal32 x = 6543.00DF;
	printf ("%Ha\n", x);
	printf ("%.6Ha\n", x);
	printf ("%.5Ha\n", x);
	printf ("%.4Ha\n", x);
	printf ("%.3Ha\n", x);
	printf ("%.2Ha\n", x);
	printf ("%.1Ha\n", x);

	printf ("\n");
	printf ("%f\n", (float) x);
}

/* eof. */

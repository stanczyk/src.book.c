/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg07-04.c
 * @brief Przykładowe stałe zmiennoprzecinkowe typu double
 */
#include <stdio.h>

int main (void)
{
	printf ("reprezentacja dziesiętna, wykładnicza i szesnastkowa:\n");
	printf ("     .5 = %12.5f %e %a\n", .5, .5, .5);                 // czyli 0.5
	printf ("   567. = %12.5f %e %a\n", 567., 567., 567.);           // 567 bez kropki dziesiętnej jest stałą typu int
	printf ("   5.67 = %12.5f %e %a\n", 5.67, 5.67, 5.67);
	printf ("  567E0 = %12.5f %e %a\n", 567E0, 567E0, 567E0);        // 567  * 10^0 = 567
	printf (" 5.67E3 = %12.5f %e %a\n", 5.67E3, 5.67E3, 5.67E3);     // 5.67 * 10^3 = 5670
	printf ("5.67E+5 = %12.5f %e %a\n", 5.67E+5, 5.67E+5, 5.67E+5);  // 5.67 * 10^5 = 567000
	printf ("5.67E-3 = %12.5f %e %a\n", 5.67E-3, 5.67E-3, 5.67E-3);  // 5.67 * 10^(-3) = 0.00567
}

/* eof. */

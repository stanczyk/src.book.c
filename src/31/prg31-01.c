/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg31-01.c
 * @brief <stdckdint.h>: użycie makra z rodziny ckd_add
 *
 * W programie użyto "ckdint.h" z https://gitlab.com/Kamcuk/ckd/
 * zamiast <stdckdint.h> -- bo gcc jeszcze tego nie wspiera
 */
#include <limits.h>
#include "ckdint.h"
#include <stdio.h>
#include <stdbool.h>

int main (void)
{
	int i, a, b;
	bool wyn;

	a = b = 1;
	wyn = ckd_add (&i, a, b);
	printf ("%d + %d = %d (%s)\n", a, b, i, wyn != true ? "OK" : "błąd");

	a = b = INT_MAX;
	wyn = ckd_add (&i, a, b);
	printf ("%d + %d = %d (%s)\n", a, b, i, wyn != true ? "OK" : "błąd");
}

/* eof. */

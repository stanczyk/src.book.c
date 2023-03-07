/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg19-01.c
 * @brief <inttypes.h>: typ imaxdiv_t i funkcja imaxdiv w użyciu
 */
#include <stdio.h>
#include <inttypes.h>

int main (void)
{
	intmax_t a = 5, b = 3;
	printf ("iloraz liczb całkowitych imaxdiv(%" PRIiMAX ", %" PRIiMAX ")\n", a, b);

	imaxdiv_t wynik = imaxdiv (a, b);
	printf("wynik = %" PRIiMAX ", reszta = %" PRIiMAX "\n", wynik.quot, wynik.rem);
}

/* eof. */

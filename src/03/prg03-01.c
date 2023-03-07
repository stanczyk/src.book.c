/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg03-01.c
 * @brief Kod źródłowy z greckimi znakami w standardzie unicode (UTF-8).
 */
#include <stdio.h>
#define τρία 3

// funkcja άθροισμα oblicza sumę argumentów
int άθροισμα (int β, int ζ)
{
	return (β + ζ);
}

int main (void)
{
	int Δ = 1, δ = τρία;

	Δ = άθροισμα (Δ, δ);
	printf ("Δ = %d\n", Δ);
}

/* eof. */

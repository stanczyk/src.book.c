/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-23.c
 * @brief Atrybut noreturn
 */
#include <stdlib.h>

[[noreturn]] void funA (void)
{
	abort ();	// ok
}

[[noreturn]] void funB (int i)
{	// funkcja powoduje niezdefiniowane zachowanie, jeśli i <= 0
	if (i > 0)
		abort ();
}

int main (void)
{
	// funa ();
	// funb (-1);
}

/* eof. */

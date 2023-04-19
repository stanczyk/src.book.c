/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg04-03.c
 * @brief Konwersja typu float na bool i int
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main (void)
{
	float f;
	f = -0.1F;
	printf ("float = %4.1f, bool = %d, int = %d\n", f, (bool) f, (int) f);
	f = 0.0F;
	printf ("float = %4.1f, bool = %d, int = %d\n", f, (bool) f, (int) f);
	f = 0.5F;
	printf ("float = %4.1f, bool = %d, int = %d\n", f, (bool) f, (int) f);
	f = 1.1F;
	printf ("float = %4.1f, bool = %d, int = %d\n", f, (bool) f, (int) f);
}

/* eof. */

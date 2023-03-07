/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg04-08.c
 * @brief Typy całkowitoliczbowe o zadanej szerokości i ich najszybsze odpowiedniki
 */
#include <stdint.h>
#include <stdio.h>

int main (void)
{
	printf ("dokładne:\n");
	printf ("  8:  %zu bit.\n", sizeof (int8_t) * 8);
	printf (" 16: %zu bit.\n", sizeof (int16_t) * 8);
	printf (" 32: %zu bit.\n", sizeof (int32_t) * 8);
	printf (" 64: %zu bit.\n", sizeof (int64_t) * 8);

	printf ("najszybsze:\n");
	printf ("  8:  %zu bit.\n", sizeof (int_fast8_t) * 8);
	printf (" 16: %zu bit.\n", sizeof (int_fast16_t) * 8);
	printf (" 32: %zu bit.\n", sizeof (int_fast32_t) * 8);
	printf (" 64: %zu bit.\n", sizeof (int_fast64_t) * 8);
}

/* eof. */

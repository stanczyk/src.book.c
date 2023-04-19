/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg07-02.c
 * @brief Użycie makr dla N = 32 oraz INTMAX_C i UINTMAX_C
 */
#include <stdio.h>
#include <inttypes.h>

int main (void)
{
	int_least32_t i32 = INT32_C(0xFFF);
	uint_least32_t u32 = UINT32_C(0xFFF);
	printf (" i32: %+"PRId32", ui32: %+"PRId32"\n", i32, u32);

	intmax_t imax = INTMAX_C(0xFFF);
	uintmax_t umax = UINTMAX_C(0xFFF);
	printf ("imax: %+"PRIdMAX", umax: %+"PRIdMAX"\n", imax, umax);
}

/* eof. */

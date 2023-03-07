/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg33-02.c
 * @brief <stdint.h>: użycie makr INT8_C i INT64_C do określenia typu stałych całkowitoliczbowych
 */
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main (void)
{
	int_least8_t x = INT8_C(123);
	int_least64_t y = INT64_C(321);

	printf("int_least8_t  x = %" PRIdLEAST8  " rozmiar: %zu\n", x, sizeof(x));
	printf("int_least64_t y = %" PRIdLEAST64 " rozmiar: %zu\n", y, sizeof(y));
}

/* eof. */

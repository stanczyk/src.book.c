/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg33-01.c
 * @brief <stdint.h>: rozmiary i wartości typów int8_t, int_least8_t i int_fast8_t
 */
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main (void)
{
	printf ("rozmiar w bajtach (bitach):\n");
	printf ("          int8_t = %zu (%" PRId8      ")\n", sizeof (int8_t),       INT8_WIDTH);
	printf ("    int_least8_t = %zu (%" PRIdLEAST8 ")\n", sizeof (int_least8_t), INT_LEAST8_WIDTH);
	printf ("     int_fast8_t = %zu (%" PRIdFAST8  ")\n", sizeof (int_fast8_t),  INT_FAST8_WIDTH);

	printf ("wartość min / max:\n");
	printf ("          int8_t = %+" PRId8      "/%+" PRId8      "\n", INT8_MIN,       INT8_MAX);
	printf ("    int_least8_t = %+" PRIdLEAST8 "/%+" PRIdLEAST8 "\n", INT_LEAST8_MIN, INT_LEAST8_MAX);
	printf ("     int_fast8_t = %+" PRIdFAST8  "/%+" PRIdFAST8  "\n", INT_FAST8_MIN,  INT_FAST8_MAX);
}

/* eof. */

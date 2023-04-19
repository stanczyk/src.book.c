/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg32-01.c
 * @brief <stddef.h>: wartość maksymalnego podstawowego wyrównania
 */
#include <stdalign.h>
#include <stddef.h>
#include <stdio.h>

int main (void)
{
	printf ("Maksymalne podstawowe wyrównanie: %ld\n", alignof (max_align_t));
}

/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg11-13.c
 * @brief Dyrektywy #define i #undef
 */
#include <stdio.h>

int main (void)
{
#define INFO

#ifdef INFO
	printf ("INFO zdefiniowane\n");
#endif

#undef INFO

#ifndef INFO
	printf ("INFO niezdefiniowane\n");
#endif
}

/* eof. */

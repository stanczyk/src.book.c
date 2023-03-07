/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-05a.c
 * @brief Specyfikator extern
 *
 * Przykład kompilowany razem z prg06-05b.c -- patrz Makefile
 */
#include <stdio.h>
extern int i;

int main (void)
{
	printf("i = %i\n", i);
}

/* eof. */

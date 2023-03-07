/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg35-11.c
 * @brief <stdlib.h>: użycie funkcji atexit
 */
#include <stdio.h>
#include <stdlib.h>

void clean1 (void)
{
	printf ("sprzątam (1) ...\n");
}

void clean2 (void)
{
	printf ("sprzątam (2) ...\n");
}

int main (void)
{
	printf ("start\n");
	atexit (clean1);
	atexit (clean2);
	printf ("koniec\n");
	exit(EXIT_SUCCESS);
}

/* eof. */

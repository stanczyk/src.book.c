/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg35-13.c
 * @brief <stdlib.h>: użycie funkcji system
 */
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	if (!system (NULL))
	{
		printf("brak procesora poleceń\n");
		exit(EXIT_FAILURE);
	}
	system ("ls -1");
	exit(EXIT_SUCCESS);
}

/* eof. */

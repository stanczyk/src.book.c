/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg35-08.c
 * @brief <stdlib.h>: dynamiczny przydział pamięci poprzez calloc
 */
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int *wsk;
	// przydział pamięci dla 4 liczb typy int
	wsk = calloc (4, sizeof (int));
	if (wsk == NULL)
	{
		perror ("Błąd calloc()");
		exit (EXIT_FAILURE);
	}
	printf ("Pamięć gotowa\n");
	/* ... */
}

/* eof. */

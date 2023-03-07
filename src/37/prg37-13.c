/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg37-13.c
 * @brief <string.h>: użycie funkcji strerror
 */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	FILE *fp = fopen ("nieistniejący.plik", "r");

	if (!fp)
	{
		perror ("fopen");
		fprintf (stderr, "fopen: %s\n", strerror (errno));
		exit (EXIT_FAILURE);
	}
	printf ("a jednak istniejący?");
	exit (EXIT_SUCCESS);
}

/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg16-02.c
 * @brief <errno.h>: użycie makr EDOM, ERANGE i errno
 */
#include <math.h>
#include <stdio.h>
#include <errno.h>

int main (void)
{
	printf ("sqrt (-1.0) = %f\n", sqrt (-1.0));
	if (errno)  // errno == EDOM
		perror (NULL);

	printf ("log (0.0) = %f\n", log (0.0));
	if (errno)  // errno == ERANGE
		perror(NULL);
}

/* eof. */

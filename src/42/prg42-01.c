/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg42-01.c
 * @brief <wchar.h>: czytanie znaków rozszerzonych z pliku dane.dat, aż napotkany zostanie WEOF
 */
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

int main (void)
{
	FILE *plik;
	wint_t wc;

	if ((plik = fopen ("dane.dat", "r")) == NULL)
	{
		perror ("dane.dat");
		exit (EXIT_FAILURE);
	}
	while ((wc = fgetwc (plik)) != WEOF)
		printf ("wc=0x%X\n", wc);
	fclose (plik);
}

/* eof. */

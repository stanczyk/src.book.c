/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg34-03.c
 * @brief <stdio.h>: tworzenie, zmiana nazwy i usuwanie pliku
 */
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	FILE *fp = NULL;

	if (!(fp = fopen ("plik1.txt", "w")))
	{
		perror ("fopen: plik1.txt");
		return EXIT_FAILURE;
	}
	puts ("plik1.txt utworzony");
	fclose (fp);

	if (rename ("plik1.txt", "plik2.txt"))
	{
		perror ("rename: plik1.txt plik2.txt");
		return EXIT_FAILURE;
	}
	puts ("plik1.txt przemianowany na plik2.txt");

	if (remove ("plik2.txt"))
	{
		perror ("remove: plik2.txt");
		return EXIT_FAILURE;
	}
	puts ("plik2.txt usunięty");
}

/* eof. */

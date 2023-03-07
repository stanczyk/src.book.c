/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg10-03.c
 * @brief Rekurencyjnie obliczana silnia
 */
#include <stdio.h>
#include <stdlib.h>

int silnia (int liczba)
{
	if (liczba < 0)	// silnia z liczby ujemnej?
		return 0;
	if (liczba == 0 || liczba == 1)
		return 1;
	return liczba * silnia (liczba - 1);
}

int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		printf ("wywołanie: %s liczba-całkowita\n", argv[0]);
		return EXIT_FAILURE;
	}
	int n = atoi (argv[1]);
	printf ("silnia z %d wynosi: %d\n", n, silnia (n));
	return EXIT_SUCCESS;
}

/* eof. */

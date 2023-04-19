/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg10-01.c
 * @brief Przykład wywołania main z argumentami podanymi w linii poleceń
 */
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	puts ("argumenty wywołania:");
	for (int i = 0; i < argc; i++)
	{
		puts (argv[i]);
	}

	return EXIT_SUCCESS;
}

/* eof. */

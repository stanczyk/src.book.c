/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg37-11.c
 * @brief <string.h>: użycie funkcji strtok
 */
#include <stdio.h>
#include <string.h>

int main (void)
{
	char str[] = "https://www.helion.pl";
	char *token;

	if ((token = strtok (str, ".")) != NULL)
	{
		do {
			puts (token);
		} while ((token = strtok (NULL, ".")) != NULL);
	}
}

/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg37-10.c
 * @brief <string.h>: użycie funkcji strchr
 */
#include <stdio.h>
#include <string.h>

int main (void)
{
	char str[] = "https://www.helion.pl";
	char *res;

	puts (str);
	while ((res = strchr (str, '.')))
	{
		puts (res);
		strcpy (str, &res[1]);
	}
}

/* eof. */

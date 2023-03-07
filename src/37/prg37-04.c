/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg37-04.c
 * @brief <string.h>: użycie funkcji strdup
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{
	char str1[] = "Programowanie jest super!";
	char *str2 = strdup (str1);

	puts (str2);
	free (str2);
}

/* eof. */

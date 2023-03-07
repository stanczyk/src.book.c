/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg37-05.c
 * @brief <string.h>: użycie funkcji strcat
 */
#include <stdio.h>
#include <string.h>

int main (void)
{
	char str1[] = "Jest ";
	char str2[] = "programowanie";

	strcat(str1, str2);
	puts (str1);
}

/* eof. */

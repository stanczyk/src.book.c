/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg37-03.c
 * @brief <string.h>: użycie funkcji strncpy
 */
#include <stdio.h>
#include <string.h>

int main (void)
{
	char str1[30] = "Programowanie jest super!";
	char str2[30] = "";
	strncpy (str2, &str1[14], 4);
	puts (str2);
}

/* eof. */

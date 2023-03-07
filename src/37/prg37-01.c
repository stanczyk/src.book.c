/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg37-01.c
 * @brief <string.h>: użycie funkcji strcpy
 */
#include <stdio.h>
#include <string.h>

int main (void)
{
	char str1[30] = "Programowanie jest super!";
	char str2[30] = "";

	strcpy (str2, str1);
	puts (str2);
}

/* eof. */

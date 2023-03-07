/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg37-08.c
 * @brief <string.h>: użycie funkcji strcoll
 */
#include <locale.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
	setlocale (LC_ALL, "pl_PL.UTF-8");
	char str1[] = "ćma";
	char str2[] = "motyl";

	// porównania:
	printf ("strcmp:  %d\n", strcmp (str1, str2));  // strcmp: wartość dodatnia, czyli str1 > str2
	printf ("strcoll: %d\n", strcoll (str1, str2)); // strcoll: wartość ujemna,  czyli str1 < str2
}

/* eof. */

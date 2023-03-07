/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg37-07.c
 * @brief <string.h>: użycie funkcji strcmp
 */
#include <stdio.h>
#include <string.h>

int main (void)
{
	char str1[] = "Halo, Ala";
	char str2[] = "Halo, Ula";

	int wynik = strcmp (str1, str2);

	if (wynik > 0)
		puts ("str1 większy od str2");
	else if (wynik < 0)
		puts ("str1 mniejszy od str2");
	else
		puts ("str1 równy str2");
}

/* eof. */

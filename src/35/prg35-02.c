/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg35-02.c
 * @brief <stdlib.h>: konwersja łańcucha na liczbę przy użyciu atoi
 */
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	printf ("%i\n", atoi (" -12pln"));
	printf ("%i\n", atoi (" +34 pln"));
	printf ("%i\n", atoi (" 0 "));
	printf ("%i\n", atoi ("pln"));        // żadnej konwersji
	printf ("%i\n", atoi ("9999999999")); // liczba spoza zakresu
}

/* eof. */

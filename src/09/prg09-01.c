/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg09-01.c
 * @brief Przykłady instrukcji prostych
 */
#include <stdio.h>

int main (void)
{
	char str[] = "Ala ma Asa";
	int x = 5, y;

	y = x; 						// instrukcja przypisania
	printf("%d, %s\n", y, str);	// wywołanie funkcji

	for ( int i = 0; str[i] ; ++i )
	{
		;	// instrukcja pusta
	}

	int i;
	for ( i = 0; str[i] != '\0'; ++i )
		;	// instrukcja pusta
}

/* eof. */

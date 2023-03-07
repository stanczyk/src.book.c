/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-26.c
 * @brief Niejawna konwersja typu long na int i float na int
 */
#include <stdio.h>

int main (void)
{
	int i = 1L;
	int j = 1.1;

	printf("i = %d, j = %d\n", i, j);
}

/* eof. */

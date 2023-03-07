/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg09-10.c
 * @brief Instrukcja break
 */
#include <stdio.h>

int main (void)
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			if (j == 3)
				break;
			printf ("i = %i, j = %i\n", i, j);
		}
	}
}

/* eof. */

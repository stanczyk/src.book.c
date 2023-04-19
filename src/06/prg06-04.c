/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-04.c
 * @brief Specyfikator auto
 */
#include <stdio.h>

int main (void)
{
	auto int i = 1;
	{
		auto int i = 2;
		printf("i = %i\n", i);
	}
	printf("i = %i\n", i);
}

/* eof. */

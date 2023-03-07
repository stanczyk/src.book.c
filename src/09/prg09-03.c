/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg09-03.c
 * @brief Instrukcja if
 */
#include <stdio.h>
#include <stdbool.h>

void przyklad_1 (void)
{
	int x = 3;
	int y = 4;
	int max;

	if (x > y)
		max = x;	// Przypisz większe z x i y do
	else			// zmiennej max.
		max = y;

	printf("max(%i, %i) = %i\n", x, y, max);
}

void przyklad_2 (void)
{
	int n = 4;

	if (n > 0)
	{
		if (n % 2 == 0)
			puts ("n parzyste dodatnie");
	}
	else 			// else należy do pierwszego if
		puts ("n jest mniejsze od zera");
}

void przyklad_3 (void)
{
	bool zm1 = true;
	bool zm2 = true;

	if (zm1)
		if (zm2)
			puts ("zm1 & zm2");
		else
			puts ("zm1 & !zm2");
	else
		if (zm2)
			puts ("!zm1 & zm2");
		else
			puts ("!zm1 & !zm2");
	/*
	// ekwiwalent ?:
	printf ("%s & %s\n", (zm1 ? "zm1" : "!zm1"), (zm2 ? "zm2" : "!zm2"));
	*/
}

int main (void)
{
	przyklad_1();
	przyklad_2();
	przyklad_3();
}

/* eof. */

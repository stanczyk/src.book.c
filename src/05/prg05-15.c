/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-15.c
 * @brief Proste użycie wskaźnika
 */
#include <stdio.h>

int main (void)
{
	int x = 10, y = 0, *wsk;

	wsk = &x;  // wsk wskazuje x
	printf ("zmienna    x = %2d\n", x);
	printf ("wartość *wsk = %2d\n", *wsk);

	*wsk = 5;  // równoważny x = 5
	printf ("zmienna    x = %2d\n", x);
	printf ("wartość *wsk = %2d\n", *wsk);

	y = *wsk;  // równoważny y = x
	printf ("zmienna    y = %2d\n", y);
}

/* eof. */

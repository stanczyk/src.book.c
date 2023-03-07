/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg08-16.c
 * @brief Operatory dostępu do pamięci cz.1; operatory: & i *
 */
#include <stdio.h>

int main (void)
{
	int a = 10;    // zmienna typu int
	printf ("zmienna a = %i\n", a);
	printf ("  adres a = %p\n", (void *) &a);

	int * wsk;     // wskaźnik do int
	 wsk = &a;     // wsk wskazuje na a
	*wsk = 123;    // ekwiwalent: a = 123;
	printf ("        a = %i\n", a);
	printf ("     *wsk = %i\n", *wsk);
	printf ("      wsk = %p\n", (void *) wsk);
}

/* eof. */

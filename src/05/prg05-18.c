/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-18.c
 * @brief Odwoływanie się do niepustego wskaźnika
 */
#include <stdio.h>

int main (void)
{
	/*
	int *p;
	printf ("zawartość komórki: %d\n", *p);  // błąd!
	// podczas kompilacji pojawi sie tylko ostrzeżenie, ale
	// program zakończy sie poprzez segmentation fault
	*/

	/*
	int *p = NULL;
	printf ("zawartość komórki: %d\n", *p);  // błąd!
	// podczas kompilacji wszystko OK, ale
	// program zakończy sie poprzez segmentation fault
	*/

	// poprawne podejście:
	int *p = NULL;
	/*
	...
	*/
	if (p != NULL)  // jeśli wskaźnik nie jest pusty
					// można odwołać się do wskazania, np.:
		printf ("%d\n", *p);
	// albo krócej:
	if (p)
		printf ("%d\n", *p);
}

/* eof. */

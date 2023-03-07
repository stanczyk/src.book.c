/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg08-20.c
 * @brief Użycie literału złożonego dla tablic
 */
// #pragma GCC diagnostic ignored "-Wunused-variable"
#include <stdio.h>

int main (void)
{
	int *p1 = (int[]) { 2, 4, 6 };
	// tworzy nienazwaną tablicę statyczną typu int[3]
	// inicjuje tablicę wartościami {2, 4, 6}
	// tworzy wskaźnik p1 wskazujący na pierwszy element tablicy
	printf("%i %i %i\n", p1[0], p1[1], p1[2]);

	float f = 8.0, *p2 = &f;
	p2 = (float[2]) { *p2 };
	// tworzy nienazwaną automatyczną tablicę typu float[2]
	// inicjuje pierwszy element wartością przechowywaną w *p2
	// inicjuje drugi element jako zero
	// przechowuje adres pierwszego elementu w p2
	printf("%.2f %.2f\n", p2[0], p2[1]);

	const float * p3 = (const float []) { 1e0, 1e1, 1e2 };
	// literał złożony tylko do odczytu
}

/* eof. */

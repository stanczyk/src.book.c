/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-04.c
 * @brief Rozmiar i ilość elementów tablicy
 */
#include <stdio.h>

int main (void)
{
	size_t n;

	printf ("sizeof(char) = %zu\n", sizeof (char));
	char linia1[81];
	n = sizeof (linia1) / sizeof (char);
	printf ("char linia1[81]\n");
	printf ("sizeof(linia1) == %zu bajtów / sizeof(char) == %zu el.\n\n", sizeof (linia1), n);

	printf ("sizeof(long) = %zu\n", sizeof (long));
	long linia2[81];
	n = sizeof (linia2) / sizeof (long);
	printf ("long linia2[81]\n");
	printf ("sizeof(linia2) == %zu bajtów / sizeof(long) == %zu el.\n", sizeof (linia2), n);
}

/* eof. */

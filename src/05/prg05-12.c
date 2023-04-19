/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-12.c
 * @brief Łańcuch znaków, jego długość i wielkość zajmowanej pamięci
 */
#include <stdio.h>
#include <string.h>

int main (void)
{
	char napis[] = "abc";

	printf ("łańcuch: %s\n", napis);
	printf ("długość: %zu\n", strlen (napis));
	printf ("rozmiar bajtów: %zi\n", sizeof (napis));
}

/* eof. */

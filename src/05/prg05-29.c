/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-29.c
 * @brief Struktura z samymi polami bitowymi
 *
 * Przykład rozłożenia pól bitowych w strukturze.
 * Żeby zobaczyć rozkład elementów w strukturze, kompiluj z opcją -g a następnie uruchom pahole prg05-29
 */
#include <stdio.h>

struct upakowana
{
	unsigned int b0_2:3;
	signed   int b3_7:5;
	unsigned int b8_8:1;
	unsigned int     :0;
	unsigned int bnew:7;
} upStru;

int main (void)
{
	printf ("Rozmiar w bajtach\n");
	printf ("'int': %zu\n", sizeof (int));
	printf ("'upStru': %zu\n", sizeof (upStru));
}

/* eof. */

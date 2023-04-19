/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg42-06.c
 * @brief <wchar.h>: odczyt orientacji strumienia
 */
#include <stdio.h>
#include <wchar.h>

int main (void)
{
	printf ("wyświetlam tekst\n");
	int mode = fwide (stdout, 0);
	printf ("strumień stdout jest zorientowany: %s\n", mode < 0 ? "bajtowo" : mode > 0 ? "szeroko" : "oczekuje sugestii");
}

/* eof. */

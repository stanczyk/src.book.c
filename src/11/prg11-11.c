/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg11-11.c
 * @brief Makro __has_embed
 *
 * Kombinacja __FILE__ i __has_embed użyta do sprawdzenia obsługi określonych
 * rozszerzeń implementacji dla parametrów dyrektywy #embed
 */
#include <stdio.h>
#if __has_embed(__FILE__ ext::token(0xB055))
#define OPIS "Obsługuje rozszerzone osadzanie tokenów"
#else
#define OPIS "Nie obsługuje rozszerzonego osadzania tokenów"
#endif

int main (void)
{
	printf ("%s\n", OPIS);
}

/* eof. */

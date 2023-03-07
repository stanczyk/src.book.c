/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg11-09.c
 * @brief Dyrektywa #embed z parametrem suffix
 *
 * Ekstra element dodawany na koniec wczytanej tablicy
 */
#include <string.h>
#define DANE "tablica.bin"
extern char * null_term_data;
void fill_in_data ()
{
	const char internal_data[] = {
#embed DANE \
		suffix(, 0)
	};
	strcpy (null_term_data, internal_data);
}
/* eof. */

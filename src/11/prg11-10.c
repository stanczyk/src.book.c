/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg11-10.c
 * @brief Dyrektywa #embed z parametrem prefix
 *
 * Elementy dodawane na początek i koniec wczytanej tablicy
 */
#include <string.h>
#include <assert.h>
#define DANE "tablica.bin"
extern char * null_term_data;
void init_data (void)
{
	const char internal_data[] = {
#embed DANE \
		prefix(0xEF, 0xBB, 0xBF, ) /* UTF-8 BOM */ \
		suffix(, 0)
	};
	// tablica zawsze jest zakończona znakiem null
	// a jeśli wczytano dane, na początku zawiera UTF-8 BOM
	int jest_dobrze = (sizeof (internal_data) == 1 && whl[0] == '\0')
		|| (internal_data[0] == '\xEF' && internal_data[1] == '\xBB'
			&& internal_data[2] == '\xBF'
			&& internal_data[sizeof (internal_data) - 1] == '\0');
	assert (jest_dobrze);
	strcpy (null_term_data, internal_data);
}
/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg11-06.c
 * @brief Dyrektywa #embed
 *
 * Test równoważności sekwencji bitów i kolejności bitów
 * między odczytem w czasie translacji a odczytem w czasie wykonania pliku
 */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
int main (void)
{
	static const unsigned char embed_dane[] = {
#embed "dane.bin"
	};
	const size_t embed_rozmiar = sizeof (embed_dane);
	unsigned char plik_dane[embed_rozmiar];
	FILE * plik = fopen ("dane.bin", "rb");

	if (plik == NULL)
		return 1;
	char * plik_wsk = (char *) &plik_dane[0];

	if (fread (plik_wsk, 1, embed_rozmiar, plik) != embed_rozmiar)
	{
		fclose (plik);
		return 1;
	}
	fclose (plik);
	int takie_same = memcmp (&embed_dane[0], plik_wsk, embed_rozmiar);
	return takie_same == 0 ? 0 : 1;
}

/* eof. */

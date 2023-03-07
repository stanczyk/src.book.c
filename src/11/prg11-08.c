/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg11-08.c
 * @brief Dyrektywa #embed z parametrem limit
 *
 * Wczytanie i sprawdzenie sygnatury pliku, tzn. 4 pierwszych bajtów pliku
 */
#include <assert.h>
int main (void)
{
	static const char sound_signature[] = {
#embed <sdk/jump.wav> limit(4)
	};
	static_assert ((sizeof (sound_signature) / sizeof (*sound_signature)) == 4,
								"W tablicy powinny znajdować się tylko 4 elementy.");
	// weryfikacja PCM WAV
	assert (sound_signature[0] == 'R');
	assert (sound_signature[1] == 'I');
	assert (sound_signature[2] == 'F');
	assert (sound_signature[3] == 'F');
	assert (sizeof (sound_signature) == 4);
	return 0;
}

/* eof. */

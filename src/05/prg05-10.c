/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-10.c
 * @brief Inicjowanie tablic
 *
 * Przykład inicjowania dwuwymiarowej tablicy z pominiętym pierwszym wymiarem, tzn. liczbą wierszy
 */
#include <stdio.h>

int main (void)
{
	int i;
	char error_msg[][40] = {
		"Błąd podczas otwierania pliku!",
		"Błąd odczytu pliku!",
		"Błąd podczas zapisywania do pliku!"
	};

	for (i = 0; i < 3; i++)
		puts (error_msg[i]);
}

/* eof. */

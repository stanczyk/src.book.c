/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg11-05.c
 * @brief Dyrektywa #embed
 *
 * Dołączenie zasobu graficznego
 */
#include <stddef.h>
#include <stdio.h>

void pokaz_ikone(const unsigned char*, size_t);

int main (void)
{
	static const unsigned char ikona[] = {
#embed "czarna_owca.ico"
	};
	pokaz_ikone(ikona, sizeof(ikona));
}

void pokaz_ikone(const unsigned char* dane, size_t rozmiar)
{
	printf("rozmiar ikony:%zu\n", rozmiar);
}
/* eof. */

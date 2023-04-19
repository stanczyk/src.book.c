/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg35-03.c
 * @brief <stdlib.h>: konwersja liczby do łańcucha za pomocą strfromd
 */
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int rozmiar = 14, wyn;
	char str[rozmiar];

	wyn = strfromd(str, rozmiar, "%E", 12.345e19);
	printf("znaków=%d, str=%s\n", wyn, str);
	wyn = strfromd(str, rozmiar, "%.E", 12.345e19);
	printf("znaków=%d, str=%s\n", wyn, str);

	// i równoważne:
	wyn = snprintf(str, rozmiar, "%E", 12.345e19);
	printf("znaków=%d, str=%s\n", wyn, str);
	wyn = snprintf(str, rozmiar, "%.E", 12.345e19);
	printf("znaków=%d, str=%s\n", wyn, str);
}

/* eof. */

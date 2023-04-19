/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg07-07.c
 * @brief Stałe znakowe i ilość zajmowanej przez nie pamięci w zależności od typu
 */
#include <stdio.h>
#include <locale.h>
#include <wchar.h>

#define C1   'A'   // int
#define C2 u8'A'   // char8_t
#define C3  u'⻨'  // char16_t, znak U+2EE8
#define C4  U'⻨'  // char32_t, znak U+2EE8
#define C5  L'⻨'  // wchar_t,  znak U+2EE8

int main (void)
{
	setlocale (LC_ALL, "");
	// wyświetlanie znaków
	printf ("znak:    %c %c %lc %lc %lc\n", C1, C2, C3, C4, (wint_t) C5);
	// rozmiar pamięci zajmowany przez poszczególne znaki
	printf ("rozmiar: %zi %zi %zi %zi %zi\n", sizeof(C1), sizeof(C2), sizeof(C3), sizeof(C4), sizeof(C5));

	// dla porównania
	 int c1 = 'B';
	char c2 = 'B';
	// wyświetlenie tych zmiennych
	printf ("znak:    %c %c\n", c1, c2);
	// rozmiar pamięci
	printf ("rozmiar: %zi %zi\n", sizeof (c1), sizeof (c2));
}

/* eof. */

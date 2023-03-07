/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg42-07.c
 * @brief <wchar.h>: konwersja znaku jednobajtowego do znaku rozszerzonego i ponownie do znaku jednobajtowego
 */
#include <wchar.h>

int main (void)
{
	unsigned char c = 'A';
	wint_t wc = btowc (c);
	wprintf (L"znak rozszerzony:  %lc\n", wc);
	c = wctob (wc);
	wprintf (L"znak jednobajtowy: %c\n", c);
}

/* eof. */

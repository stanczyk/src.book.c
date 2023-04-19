/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-01.c
 * @brief Użycie typedef
 */
#include <stdio.h>

typedef unsigned char UCHAR;
typedef struct { double x, y; } PUNKT;

int main (void)
{
	UCHAR u1, u2, tab[100];
	PUNKT punkt, *wskPunkt;

	u1 = u2 = 97;
	printf("UCHAR: %c, %c\n", u1, u2 - 32);
	tab[12] = 0;
	printf("tab[12] = %d\n", tab[12]);

	punkt.x = 0.1;
	punkt.y = 0.2;
	printf("PUNKT: %.2f, %.2f\n", punkt.x, punkt.y);

	wskPunkt = &punkt;
	wskPunkt->x = 2 * wskPunkt->y;
	printf("PUNKT: %.2f, %.2f\n", punkt.x, punkt.y);
}

/* eof. */

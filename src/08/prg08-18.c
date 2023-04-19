/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg08-18.c
 * @brief Operatory dostępu do pamięci cz.3; struktury i unie
 */
#include <stdio.h>

typedef struct
{
	int x, y, z;
} punkt;

int main (void)
{
	punkt tab[] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}};

	for (int i =0; i < 3; i++)
		printf("  tab[%i] = %i, %i, %i\n", i, tab[i].x, tab[i].y, tab[i].z);

	punkt *wsk = &tab[1];
	printf("  wsk    = %i, %i, %i\n", wsk->x, wsk->y, wsk->z);
	printf("(*wsk)   = %i, %i, %i\n", (*wsk).x, (*wsk).y, (*wsk).z);
	++wsk->z;
	printf("  wsk    = %i, %i, %i\n", wsk->x, wsk->y, wsk->z);
	++(wsk->z);
	printf("  wsk    = %i, %i, %i\n", wsk->x, wsk->y, wsk->z);
	printf("(*wsk)   = %i, %i, %i\n", (*wsk).x, (*wsk).y, (*wsk).z);
}

/* eof. */

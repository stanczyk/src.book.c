/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg32-05.c
 * @brief <stddef.h>: testowanie wartości wskaźnika przekazanego do funkcji
 *
 * @warning
 * Fragment kodu
 */
#include <stddef.h>

void fun (void *wsk)
{
	if (wsk)
	{ /* kod dla wsk != NULL */ }
	else
	{ /* kod dla wsk == NULL */ }
}

/* eof. */

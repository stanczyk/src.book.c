/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg03-05.c
 * @brief Użycie identyfikatora predefiniowanego __func__
 */
#include <stdio.h>

int main (void)
{
	printf ("wywołanie funkcji %s\n", __func__);
}

/* eof. */

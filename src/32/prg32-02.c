/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg32-02.c
 * @brief <stddef.h>: ptrdiff_t w użyciu
 */
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

int main (void)
{
	printf ("rozmiar typu ptrdiff_t: %zu bajtów (%u bitów)\n", sizeof(ptrdiff_t), PTRDIFF_WIDTH);
	printf ("maksymalna możliwa do przechowania wartość: %tu\n", PTRDIFF_MAX);

	long long tab[123];
	long long *wsk1 = &tab[21];
	long long *wsk2 = &tab[12];
	ptrdiff_t diff = wsk2 - wsk1;
	printf ("wsk2 - wsk1 = %td\n", diff);
}

/* eof. */

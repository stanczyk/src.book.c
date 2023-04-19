/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg16-01.c
 * @brief <errno.h>: Użycie typu errno_t
 */
#ifdef __STDC_LIB_EXT1__
#define  __STDC_WANT_LIB_EXT1__ 1
#else
#error "brak wsparcia dla __STDC_LIB_EXT1__"
#endif

#include <stdio.h>
#include <errno.h>

int main (void)
{
	errno_t err;
	FILE* fp;
	const char* fname = "moj-plik.txt";

	err = fopen_s (fp, fname, "rt");
	if (err)
		printf ("plik %s nie został otwarty\n", fname);
	else
		printf ("plik %s został otwarty\n", fname);
}

/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg11-03.c
 * @brief Warunkowe dołączenie pliku nagłówkowego
 */
/*
#define WERSJA 1
*/
#if WERSJA == 1
	#define INCFILE "wersja-1.h"
#else
	#define INCFILE "wersja-2.h"
#endif

#include INCFILE

int main (void)
{
	display ();
}

/* eof. */

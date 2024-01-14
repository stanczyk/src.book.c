/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg22-01.c
 * @brief <locale.h>: odczyt ustawień regionalnych
 */
#include <locale.h>
#include <stdio.h>

int main (void)
{
	printf("LC_COLLATE  = %s\n", setlocale (LC_COLLATE, ""));
	printf("LC_CTYPE    = %s\n", setlocale (LC_CTYPE, ""));
	printf("LC_MONETARY = %s\n", setlocale (LC_MONETARY, ""));
	printf("LC_NUMERIC  = %s\n", setlocale (LC_NUMERIC, ""));
	printf("LC_TIME     = %s\n", setlocale (LC_TIME, ""));
	printf("LC_ALL      = %s\n", setlocale (LC_ALL, ""));
}

/* eof. */

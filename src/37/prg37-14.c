/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg37-14.c
 * @brief <string.h>: użycie funkcji strlen
 */
#include <stdio.h>
#include <string.h>

int main (void)
{
	char str[] = "https://www.helion.pl";
	printf("%s, długość = %zu\n", str, strlen(str));
}

/* eof. */

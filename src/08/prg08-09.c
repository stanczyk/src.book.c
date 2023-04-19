/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg08-07.c
 * @brief Niebezpieczeństwa porównywania liczb zmiennoprzecinkowych
 */
#include <stdio.h>

int main (void)
{
	float a = 1e10;   // duża liczba, np. 10 do potęgi 10
	float b = 1e-10;  // mała liczba, np. 10 do potęgi -10
	float c = b;      // niech c = b

	c = c + a;        // teoretycznie c = b + a
	c = c - a;        // teoretycznie c = b + a - a = b
	printf ("%d\n", c == b);
	                  // wypisze 0 czyli fałsz
}

/* eof. */

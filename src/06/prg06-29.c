/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-29.c
 * @brief Konwersja arytmetyczna: konwersja liczb całkowitych ze znakiem i bez znaku
 */
#include <limits.h>
#include <stdio.h>

int main (void)
{
	short s1 = USHRT_MAX;   // USHRT_MAX jest spoza zakresu short
	short s2 = s1 + 1;
	unsigned short s3 = -1; // -1 jest spoza zakresu unsigned short
	unsigned short s4 = -2;

	printf("s1: %d\n", s1);
	printf("s2: %d\n", s2);
	printf("s3: %d\n", s3);
	printf("s4: %d\n", s4);
}

/* eof. */

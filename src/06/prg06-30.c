/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-30.c
 * @brief Konwersja arytmetyczna: konwersja liczb całkowitych i zmiennoprzecinkowych
 */
#include <float.h>
#include <limits.h>
#include <stdio.h>

int main (void)
{
	int i1 = 3.01; 			// i1 == 3
	int i2 = 3.99; 			// i2 == 3
	int i3 = 1e10; 			// 1e10 spoza zakresu int, i3 == 2147483647

	float f1 = 3; 			// f1 == 3.0
	float f2 = 100000001; 	// f2 == 1e8, podczas konwersji zgubiono 1

	printf("i1: %d\n", i1);
	printf("i2: %d\n", i2);
	printf("i3: %d\n", i3);

	printf("f1: %f\n", f1);
	printf("f2: %f\n", f2);
}

/* eof. */

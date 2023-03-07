/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg35-06.c
 * @brief <stdlib.h>: wartość bezwzględna: funkcja abs
 */
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int val = 5;
	printf("abs(%+d) = %d\n",  val, abs(val));
	printf("abs(%+d) = %d\n", -val, abs(-val));
}
/* eof. */

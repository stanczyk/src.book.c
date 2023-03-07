/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg11-12.c
 * @brief Dyrektywa #define.
 *
 * Różne typy makrodefinicji
 */
#include <stdio.h>

#define INFO
#define PI 3.1416             // makro jako stała symboliczna
#define POLE(r) (PI*(r)*(r))  // makro: pole koła, zależne od promienia r

int main (void)
{
	double r = 3, pole;

	pole = POLE(r-2);
	printf ("pole wynosi %.2f\n", pole);
	pole = PI * r-2 * r-2;
	printf ("pole wynosi %.2f\n", pole);
}

/* eof. */

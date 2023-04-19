/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg04-12.c
 * @brief Parametry dziesiętnych typów zmiennoprzecinkowych
 */
#include <float.h>
#include <stdio.h>

int main (void)
{
	printf ("liczba cyfr podstawy potęgowania, minimalny i maksymalny wykładnik\n");
	printf ("------------------------------------------------------------------\n");
	printf ("_Decimal32:  %2d, %5d, %5d\n", DEC32_MANT_DIG,  DEC32_MIN_EXP,  DEC32_MAX_EXP);
	printf ("_Decimal64:  %2d, %5d, %5d\n", DEC64_MANT_DIG,  DEC64_MIN_EXP,  DEC64_MAX_EXP);
	printf ("_Decimal128: %2d, %5d, %5d\n", DEC128_MANT_DIG, DEC128_MIN_EXP, DEC128_MAX_EXP);
}

/* eof. */

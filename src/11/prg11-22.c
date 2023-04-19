/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg11-22.c
 * @brief Dyrektywa #line
 */
#include <stdio.h>

int main (void)
{
	printf ("podaj wartość funkcji ");
#line 500 "mój kod C"
		// dotąd kod jest poprawny
	printf ("w przedziale od 10 do 0\n );
		// w wierszu powyżej specjalnie nie domknięto cudzysłowów,
		// aby spowodować błąd kompilacji
}

/* eof. */

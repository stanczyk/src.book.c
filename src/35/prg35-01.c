/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg35-01.c
 * @brief <stdlib.h>: konwersja łańcucha na liczbę przy użyciu atof
 */
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	printf ("%.2f\n", atof ("12.34"));
	printf ("%.2f\n", atof ("10e2"));
	printf ("%.2f\n", atof ("0xFF"));
	printf ("%.2f\n", atof ("0x1.1b8p+9"));
	printf ("%.2f\n", atof ("-INF"));
	printf ("%.2f\n", atof ("Ala ma Asa")); // błąd: łańcuch nie jest liczbą
}

/* eof. */

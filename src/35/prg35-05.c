/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg35-05.c
 * @brief <stdlib.h>: generowanie liczby losowej z przedziału <0, 99>
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
	srand (time (NULL));  //zainicjowanie generatora liczb losowych aktualną wartością czasu
	int los = rand () % 100;
	printf ("wartość losowa <0, %d>: %d\n", 99, los);
}

/* eof. */

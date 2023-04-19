/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg10-06.c
 * @brief Specyfikator _Notreturn
 */
#include <stdio.h>
#include <stdlib.h>

_Noreturn void myExit (int exit_status)
{
	puts ("myExit...");
	exit (exit_status);
}

int main (void)
{
	myExit (12);
}

/* eof. */

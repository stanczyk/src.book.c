/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg40-07.c
 * @brief <time.h>: aktualny czas
 */
#include <time.h>
#include <stdio.h>

int main (void)
{
	time_t result = time (NULL);
	printf ("%s", ctime (&result));
}

/* eof. */

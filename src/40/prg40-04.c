/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg40-04.c
 * @brief <time.h>: czas początku epoki
 */
#include <locale.h>
#include <stdio.h>
#include <time.h>

int main (void)
{
	setlocale (LC_TIME, "pl_PL.UTF-8");
	char buf[50];
	time_t epoch = 0;

	strftime(buf, sizeof buf, "%c", gmtime (&epoch));
	printf ("początek epoki: %s\n", buf);
}

/* eof. */

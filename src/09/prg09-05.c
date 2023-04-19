/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg09-05.c
 * @brief Pętla while
 */
#include <stdio.h>

int main (void)
{
	char str[] = "Ala ma Asa";
	char *s;

	s = str;				// niech wskaźnik s
	while( *s != '\0')		// wskazuje koniec łańcucha str
		++s;
}

/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg34-06.c
 * @brief <stdio.h>: Użycie flush do opróżnienia bufora wejściowego
  */
#include <stdio.h>

int main (void)
{
	char str[10];
	int i, c;

	for (i = 0; i < 2; i++)
	{
		scanf ("%[^\n]s", str);
		printf ("Wczytano: %s\n", str);

		// czyszczenie bufora wejściowego
		// fflush (stdin);
		// rozwiązanie jeśli fflush nie działa
		while((c = getchar()) != '\n' && c != EOF) ;
	}
}

/* eof. */

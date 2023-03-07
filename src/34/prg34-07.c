/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg34-07.c
 * @brief <stdio.h>: użycie funkcji freopen do przekierowania standardowego wyjścia do pliku
  */
#include <stdio.h>

int main (void)
{
	printf ("tekst wyświetlany na standardowym wyjściu\n");
	FILE * fp = freopen ("plik-wy.txt", "w+", stdout);
	printf ("tekst przekierowany do pliku\n");
	fclose (fp);
	printf ("tekst końcowy\n");
}

/* eof. */

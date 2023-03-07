/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg25-01.c
 * @brief <signal.h>: wysyłanie sygnału SIGTERM do samego siebie
 */
#include <signal.h>
#include <stdio.h>

int main (void)
{
	printf ("Wysyłam sygnał %d (SIGTERM)\n", SIGTERM);
	raise (SIGTERM);
	printf ("Ten wiersz nie powinien się wyświetlić\n");
}

/* eof. */

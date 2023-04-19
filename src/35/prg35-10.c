/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg35-10.c
 * @brief <stdlib.h>: użycie funkcji abort i sprzątanie po jej wywołaniu
 */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

// funkcja obsługi sygnału, obsługująca SIGABRT
void sig_handler (int sig_nr)
{
	switch(sig_nr)
	{
		case SIGABRT:
			printf ("sprzątamy po abort() ...\n");
			break;
	}
}

int main (void)
{
	printf ("start\n");
	// rejestracja funkcji obsługi SIGABRT
	signal (SIGABRT, sig_handler);

	printf ("koniec przez abort()\n");
	abort();
}

/* eof. */

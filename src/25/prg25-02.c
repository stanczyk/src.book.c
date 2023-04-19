/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg25-02.c
 * @brief <signal.h>: obsługa sygnału SIGINT (Ctrl+C) przychodzącego z zewnątrz
 *
 * program trzykrotnie ignoruje nadejście sygnału, przy czwartym kończy działanie
 */
#include <stdio.h>
#include <signal.h>

// licznik odebranych sygnałów
volatile sig_atomic_t licznik = 0;

// funkcja obsługi sygnału
void sig_handler (int sig_nr)
{
	printf ("Przechwycono %d (SIGINT)\n", sig_nr);
	if (++licznik < 3)
		signal (sig_nr, sig_handler);
}

int main (void)
{
	printf ("Start\n");
	// rejestracja funkcji obsługi sygnału
	if (signal (SIGINT, sig_handler) == SIG_ERR)
	{
		perror ("Błąd signal()");
		return 1;
	}
	// niekończące się oczekiwanie na sygnały z zewnątrz
	while (1)
		;
}

/* eof. */

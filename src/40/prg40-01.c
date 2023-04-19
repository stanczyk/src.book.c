/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg40-01.c
 * @brief <time.h>: pomiar czasu wykonywania (w sek.)
 */
#include <stdio.h>
#include <time.h>

int main (void)
{
	clock_t start_pomiaru, koniec_pomiaru;
	double cpu_time_used;

	start_pomiaru = clock ();
	/*
	 * działania, których czas trwania chcemy mierzyć
	 */
	koniec_pomiaru = clock ();

	cpu_time_used = ((double) (koniec_pomiaru - start_pomiaru)) / CLOCKS_PER_SEC;
	printf ("Wykonanie trwało %f sek.\n", cpu_time_used);
}

/* eof. */

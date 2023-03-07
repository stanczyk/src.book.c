/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-09.c
 * @brief Specyfikator thread_local
 */
#include <stdio.h>
#include <threads.h>

#ifndef NUM_THREADS
#define NUM_THREADS 4
#endif

int watek (void *id)
{
	/* Funkcja wyświetla numer wątku przekazany z funkcji main
	 * oraz adres zmiennej lokalnej wątku i
	 *
	 * adres powinien być inny dla każdego wątku (odrębne instancje zmiennej) */
	static thread_local int i;  // lokalna zmienna wątku
	printf ("Wątek nr %i, adres i: %p\n", *(int*) id, (void*) &i);
	return thrd_success;
}

int main (void)
{
	int tab[NUM_THREADS];
	thrd_t id[NUM_THREADS];

	/* tworzenie wątków */
	for (int i = 0; i < NUM_THREADS; ++i)
	{
		tab[i] = i + 1;
		thrd_create (&id[i], watek, &tab[i]);
	}

	/* oczekiwanie na zakończenie wątków */
	for (int i = 0; i < NUM_THREADS; ++i)
	{
		thrd_join (id[i], NULL);
	}
}

/* eof. */

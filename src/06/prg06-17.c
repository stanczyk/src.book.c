/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-17.c
 * @brief Kwalifikator _Atomic
 *
 * Przykład zaczerpnięty z https://en.cppreference.com/w/c/language/atomic
 */
#include <stdio.h>
#include <threads.h>
#ifndef NUM_THREADS
#define NUM_THREADS 10
#endif

_Atomic int licznikA = 0;
int licznik = 0;

int fun (void *thr_data)
{
	(void) thr_data;
	for (int n = 0; n < 1000; ++n)
	{
		++licznik;
		++licznikA;
	}
	return thrd_success;
}

int main (void)
{
	thrd_t thr[NUM_THREADS];

	for (int n = 0; n < NUM_THREADS; ++n)
		thrd_create (&thr[n], fun, NULL);
	for (int n = 0; n < NUM_THREADS; ++n)
		thrd_join (thr[n], NULL);

	printf ("wskazanie licznika atomowego: %u\n", licznikA);
	printf ("              i nieatomowego: %u\n", licznik);
}

/* eof. */

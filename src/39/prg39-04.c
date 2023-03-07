/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg39-04.c
 * @brief <threads.h>: synchronizacja przy użyciu muteksów
 *
 * Użyto funkcji: mtx_init, mtx_destroy, mtx_lock i mtx_unlock
 */
#ifdef __STDC_NO_THREADS__
#error brak wsparcia dla wątków
#endif

#ifndef NUM_THREADS
#define NUM_THREADS 2
#endif

#include <stdio.h>
#include <threads.h>
#include <unistd.h>

mtx_t mutex;

void drukuj (char *a, char *b)
{
	mtx_lock (&mutex);
	puts (a);
	sleep (1);
	puts (b);
	mtx_unlock (&mutex);
}

int thr_fun (void * nr)
{
	char str[8];
	sprintf (str, "#%ld", (long) nr);
	drukuj ("wątek", str);
	thrd_exit (thrd_success);
}

int main (void)
{
	thrd_t threads[NUM_THREADS];
	long i;

	mtx_init (&mutex, mtx_plain);
	for (i = 0; i < NUM_THREADS; i++)
		thrd_create (&threads[i], thr_fun, (void *) i);
	for (i = 0; i < NUM_THREADS; i++)
		thrd_join (threads[i], NULL);
	mtx_destroy (&mutex);
}

/* eof. */

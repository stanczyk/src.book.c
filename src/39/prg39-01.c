/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg39-01.c
 * @brief <threads.h>: użycie thrd_create, thrd_current i thrd_join
 */
#ifdef __STDC_NO_THREADS__
#error brak wsparcia dla wątków
#endif

#ifndef NUM_THREADS
#define NUM_THREADS 4
#endif

#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

// funkcja uruchamiana jako wątek
int thr_fun (void * arg)
{
	printf ("wątek #%ld (ID %lu) działa\n", (long) arg, thrd_current());
	thrd_exit (thrd_success);
}

int main (void)
{
	thrd_t threads[NUM_THREADS];
	long t;
	int ret;

	// tworzymy wątki
	for (t = 0; t < NUM_THREADS; t++)
	{
		ret = thrd_create (&threads[t], thr_fun, (void *) t);
		if (ret != thrd_success)
		{
			printf ("BŁĄD thrd_create()\n");
			exit (ret);
		} else {
			printf ("wątek #%ld (ID %lu) utworzony\n", t, threads[t]);
		}
	}

	// czekamy na zakończenie każdego z wątków
	for (t = 0; t < NUM_THREADS; t++)
	{
		thrd_join (threads[t], NULL);
	}
}

/* eof. */

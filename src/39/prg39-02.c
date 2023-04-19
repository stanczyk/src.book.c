/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg39-02.c
 * @brief <threads.h>: użycie thrd_detach i thrd_sleep
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
#include <unistd.h>

int thr_fun (void *arg)
{
	long id = (long) arg;
	struct timespec ts;

	printf ("start  #%li\n", id);

	ts.tv_sec = 1;  // czekamy 1 sekundę
	ts.tv_nsec = 0L;
	thrd_sleep (&ts, &ts);

	printf ("koniec #%li\n", id);
	thrd_exit (thrd_success);
}

int main (void)
{
	thrd_t threads[NUM_THREADS];
	long i;
	int err;

	printf ("start  main\n");
	// uruchamiamy wątki
	for (i = 0; i < NUM_THREADS; i++)
	{
		err = thrd_create (&threads[i], thr_fun, (void *) i);
		if (err)
		{
			fprintf (stderr, "BŁĄD thrd_create()\n");
			return err;
		}
	}
	// uwalniamy wątki
	for (i = 0; i < NUM_THREADS; i++)
		thrd_detach (threads[i]);

	// czekamy dwie sekundy
	// ponieważ jeśli funkcja główna zakończy działanie,
	// uruchomione przez nią wątki zostaną automatycznie zakończone
	sleep (2);
	printf ("koniec main\n");
}

/* eof. */

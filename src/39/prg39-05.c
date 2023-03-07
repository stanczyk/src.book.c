/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg39-05.c
 * @brief <threads.h>: użycie zmiennej warunkowej i różnych metod sygnalizacji,
 * tzn. cnd_signal i cnd_broadcast
 */
#ifdef __STDC_NO_THREADS__
#error brak wsparcia dla wątków
#endif

#ifndef NUM_THREADS
#define NUM_THREADS 5
#endif

#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <unistd.h>

mtx_t mutex;
cnd_t condw;
int warunek = 0;

int watek (void *nr)
{
	printf ("wątek\t#%ld\n", (long) nr);
	mtx_lock (&mutex);
	do
	{
		if (warunek)
			break;
		else
		{
			printf ("\t#%ld oczekuje na sygnał...\n", (long) nr);
			cnd_wait (&condw, &mutex);
			printf ("\t#%ld jest sygnał!\n", (long) nr);
			++warunek;
		}
	} while (1);
	mtx_unlock (&mutex);
	printf ("\t#%ld koniec\n", (long) nr);
	return thrd_success;
}

int main (void)
{
	thrd_t threads[NUM_THREADS];
	long i;

	/* startujemy, inicjujemy muteksa i zmienną warunkową */
	puts ("START");
	mtx_init (&mutex, mtx_plain);
	cnd_init (&condw);

	/* tworzymy kilka wątków */
	for (i = 0; i < NUM_THREADS; i++)
		if (thrd_create (&threads[i], watek, (void *) i))
		{
			perror ("thrd_create");
			return EXIT_FAILURE;
		}

	/* nie czekamy na te wątki */
	for (i = 0; i < NUM_THREADS; i++)
		thrd_detach (threads[i]);
	sleep (1);

	/* wysyłamy sygnały na różne sposoby */
	puts ("cnd_signal()");
	cnd_signal (&condw);
	sleep (1);

	puts ("cnd_broadcast()");
	cnd_broadcast (&condw);
	sleep (1);

	/* usuwamy zmienną warunkową i mutex */
	cnd_destroy (&condw);
	mtx_destroy (&mutex);

	/* kończymy bez oglądania się na wątki */
	/* bo one powinny się zakończyć po rozesłaniu rozgłoszenia */
	puts ("KONIEC");
	return EXIT_SUCCESS;
}

/* eof. */

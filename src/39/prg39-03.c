/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg39-03.c
 * @brief <threads.h>: użycie call_once wywoływanej przez cztery wątki, a uruchomionej raz
 */
#ifdef __STDC_NO_THREADS__
#error brak wsparcia dla wątków
#endif

#ifndef NUM_THREADS
#define NUM_THREADS 4
#endif

#include <stdio.h>
#include <threads.h>

static once_flag flag = ONCE_FLAG_INIT;

void zrob_raz (void)
{
	puts ("wywołano raz");
}

int thr_fun (void *)
{
	call_once (&flag, zrob_raz);
	thrd_exit (thrd_success);
}

int main (void)
{
	long i;
	thrd_t threads[NUM_THREADS];

	for (i = 0; i < NUM_THREADS; i++)
		thrd_create (&threads[i], thr_fun, NULL);

	for (i = 0; i < NUM_THREADS; i++)
		thrd_join (threads[i], NULL);
}

/* eof. */

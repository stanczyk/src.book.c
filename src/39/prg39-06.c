/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg39-06.c
 * @brief <threads.h>: użycie pamięci lokalnej z jednym kluczem
 */
#ifdef __STDC_NO_THREADS__
#error brak wsparcia dla wątków
#endif

#ifndef NUM_THREADS
#define NUM_THREADS 5
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <threads.h>

tss_t tkey;

void destructor (void *data)
{
	free (data);
}

char *get_data (long nr)
{
	char *txt = (char *) malloc (10 * sizeof (char));
	if (txt == NULL)
		return NULL;
	sprintf (txt, "wątek #%ld", nr);
	return txt;
}

int add_data (long nr)
{
	char *data = get_data (nr);
	if (data == NULL)
		return EXIT_FAILURE;

	if (tss_set (tkey, (void *) data) != thrd_success)
	{
		perror ("tss_set()");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

void print_data (void)
{
	char *data = tss_get (tkey);
	if (data != NULL)
		puts (data);
}

int thr_fun (void *nr)
{
	// Dodajemy dane wątku do klucza
	if (add_data ((long) nr))
		thrd_exit (thrd_error);

	// Pobieramy i wyświetlamy dane wątku
	print_data ();
	thrd_exit (thrd_success);
}

int main (void)
{
	long i;
	thrd_t threads[NUM_THREADS];

	// Tworzymy klucz, zanim utworzymy wątki
	if (tss_create (&tkey, destructor) != thrd_success)
	{
		perror ("tss_create()");
		exit (EXIT_FAILURE);
	}

	// Tworzymy wątki
	for (i = 0; i < NUM_THREADS; i++)
		if (thrd_create (&threads[i], thr_fun, (void *) i)
			!= thrd_success)
		{
			perror ("thrd_create()");
			exit (EXIT_FAILURE);
		}

	// Czekamy na zakończenie wątków
	for (i = 0; i < NUM_THREADS; i++)
		if (thrd_join (threads[i], NULL) != thrd_success)
		{
			perror ("thrd_join()");
			exit (EXIT_FAILURE);
		}

	// Usuwamy klucz i koniec
	tss_delete (tkey);
	return EXIT_SUCCESS;
}

/* eof. */

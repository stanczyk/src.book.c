/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg40-02.c
 * @brief <time.h>: aktualny czas UTC oraz składowe timespec
 *
 * @code

struct timespec
{
	time_t tv_sec;   // sekundy >= 0
	long   tv_nsec;  // nanosekundy [0, 999999999]
}

 * @endcode
 */
#include <stdio.h>
#include <time.h>

int main (void)
{
	char buff[50];
	struct timespec ts;

	timespec_get (&ts, TIME_UTC);
	strftime (buff, sizeof buff, "%F %T", gmtime (&ts.tv_sec));
	printf ("%s.%li UTC\n", buff, ts.tv_nsec);
	printf ("czyli timespec.tv_sec:  %ji\n", ts.tv_sec);
	printf ("      timespec.tv_nsec: %li\n", ts.tv_nsec);
}

/* eof. */

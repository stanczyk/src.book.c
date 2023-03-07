/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg11-16.c
 * @brief Zmienna ilość argumentów w makrze
 *
 * __VA_ARGS__
 */
#include <stdio.h>

#define debug(...) fprintf (stderr, __VA_ARGS__)
#define showlist(...) puts (# __VA_ARGS__)
#define report(test, ...) ((test) ? puts (#test) : printf (__VA_ARGS__))

int main (void)
{
	int x = 3, y = 5;

	debug ("ustawiono flagi\n");
	debug ("X = %d\n", x);
	showlist (Element pierwszy, drugi, a nawet trzeci.);
	report (x > y, "x = %d ALE y = %d\n", x, y);

	/* powyższe wywołania są rozwijane w:
	fprintf (stderr, "ustawiono flagi\n");
	fprintf (stderr, "X = %d\n", x);
	puts ("Element pierwszy, drugi, a nawet trzeci.");
	((x > y) ? puts ("x > y") : printf ("x = %d ALE y = %d\n", x, y))
	*/
}

/* eof. */

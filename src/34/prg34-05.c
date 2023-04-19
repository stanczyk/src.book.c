/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg34-05.c
 * @brief <stdio.h>: generowanie tymczasowej nazwy pliku za pomocą tmpnam
 */
#include <stdio.h>

int main (void)
{
	char buf [L_tmpnam];
	if (!(tmpnam (buf)))
	{
		perror ("tmpnam 1");
		return 1;
	}
	printf ("nazwa 1: %s\n", buf);

	char *wsk;
	if (!(wsk = tmpnam (NULL)))
	{
		perror ("tmpnam 2");
		return 1;
	}
	printf ("nazwa 2: %s\n", wsk);
}

/* eof. */

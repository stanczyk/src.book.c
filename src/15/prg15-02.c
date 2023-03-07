/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg15-02.c
 * @brief <ctype.h>: działanie poszczególnych funkcji z <ctype.h> dla danego znaku
 */
#include <ctype.h>
#include <stdio.h>

const char *odp (int arg)
{
	if (arg)
		return "prawda";
	return "fałsz";
}

int main (void)
{
	int c = 'a';

	printf ("znak \'%c\':\n", c);
	printf (" isalnum: %s\n", odp (isalnum (c)));
	printf (" isalpha: %s\n", odp (isalpha (c)));
	printf (" isblank: %s\n", odp (isblank (c)));
	printf (" iscntrl: %s\n", odp (iscntrl (c)));
	printf (" isdigit: %s\n", odp (isdigit (c)));
	printf (" isgraph: %s\n", odp (isgraph (c)));
	printf (" islower: %s\n", odp (islower (c)));
	printf (" isprint: %s\n", odp (isprint (c)));
	printf (" ispunct: %s\n", odp (ispunct (c)));
	printf (" isspace: %s\n", odp (isspace (c)));
	printf (" isupper: %s\n", odp (isupper (c)));
	printf ("isxdigit: %s\n", odp (isxdigit (c)));

	printf (" tolower: %c\n", tolower (c));
	printf (" toupper: %c\n", toupper (c));
}

/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg34-04.c
 * @brief <stdio.h>: zapis i odczyt danych z pliku tymczasowego
 */
#include <stdio.h>
#define dane "dane do przechowania"

int main (void)
{
	// tworzenie pliku tymczasowego
	FILE *tmpf;
	if (!(tmpf = tmpfile ()))
	{
		perror ("tmfile");
		return 1;
	}

	// zapis
	fputs (dane, tmpf);

	// odczyt
	char buf[22] = "";
	rewind (tmpf);
	fgets (buf, sizeof buf, tmpf);
	printf ("odczytano '%s'\n", buf);
}

/* eof. */

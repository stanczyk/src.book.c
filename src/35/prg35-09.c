/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg35-09.c
 * @brief <stdlib.h>: dynamiczne zarządzanie pamięcią: użycie funkcji malloc, realloc i free
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	char *str;
	/* początkowa alokacja pamięci */
	str = (char *) malloc (20);
	strcpy (str, "https://github.com/");
	printf ("%p: %s\n", str, str);

	/* realokacja pamięci */
	str = (char *) realloc (str, 29);
	strcat (str, "stanczyk/");
	printf ("%p: %s\n", str, str);

	/* zwolnienie pamięci zajmowanej dynamicznie */
	free (str);
}

/* eof. */

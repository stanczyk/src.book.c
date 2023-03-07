/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg34-11.c
 * @brief <stdio.h>: użycie fscanf
 */
#include <stdio.h>
int main (void)
{
	int n, i;
	float x;
	char name[50];

	n = fscanf (stdin, "%d%f%s", &i, &x, name);

	printf ("n=%i\n", n);
	printf ("i=%i\n", i);
	printf ("x=%f\n", x);
	printf ("name=%s\n", name);
}

/* eof. */

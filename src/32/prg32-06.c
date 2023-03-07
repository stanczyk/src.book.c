/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg32-06.c
 * @brief <stddef.h>: użycie makra offsetof
 */
#include <stdio.h>
#include <stddef.h>

struct bar
{
	int a;
	char b[10];
};

struct foo
{
	int a;
	struct bar b;
};

int main (void)
{
	printf ("bar.a: %zu\n", offsetof (struct bar, a));
	printf ("bar.b: %zu\n", offsetof (struct bar, b));
	printf ("foo.b.b[5]: %zu\n", offsetof (struct foo, b.b[5]));
}

/* eof. */

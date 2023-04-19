/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg08-23.c
 * @brief Operatory alignof i sizeof w upakowaniu struktury
  */
#include <stdio.h>
#include <stdalign.h>

struct MiksDanych1
{
	char  dana1; 	// 1 bajt
	short dana2; 	// 2 bajty
	int   dana3; 	// 4 bajty
	char  dana4; 	// 1 bajt
} md1;

struct MiksDanych2
{
	char  dana1;
	char  dana4;
	short dana2;
	int   dana3;
} md2;

int main (void)
{
	// pomiary dla typów poszczególnych składowych struct MiksDanych1
	printf ("sizeof char %zu, short %zu, int %zu\n", sizeof (char), sizeof (short), sizeof (int));
	// pomiary dla struct MiksDanych1
	printf ("MiksDanych1  sizeof = %zu\n", sizeof (struct MiksDanych1));
	printf ("MiksDanych1 alignof = %zu\n", alignof (struct MiksDanych1));
	// pomiary dla struct MiksDanych2
	printf ("MiksDanych2  sizeof = %zu\n", sizeof (struct MiksDanych2));
	printf ("MiksDanych2 alignof = %zu\n", alignof (struct MiksDanych2));
}

/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg20-01.c
 * @brief <iso646.h>
 */
#include <iso646.h>
#include <stdbool.h>
#include <stdio.h>

char *boolToString (bool val)
{
	return val == 0 ? "fałsz" : "prawda";
}

void operatory_logiczne (void)
{
	int a = 0, b = 19;

	printf ("operatory logiczne:\n");
	printf ("  %d and %d %s\n", a, b, boolToString (a and b));
	printf ("  %d or  %d %s\n", a, b, boolToString (a or b));
	printf ("     not %d %s\n", a, boolToString (not a));
}

void operatory_bitowe (void)
{
	unsigned char x = 0B0101;  // dziesiętnie: 5
	unsigned char y = 0B0011;  // dziesiętnie: 3

	printf ("\noperatory bitowe:\n");
	printf ("           x = 0b%04b\n",   x);
	printf ("           y = 0b%04b\n\n", y);

	printf ("  x bitand y = 0b%04b\n", x bitand y);
	printf ("  x bitor  y = 0b%04b\n", x bitor y);
	printf ("  x xor    y = 0b%04b\n", x xor y);
	printf ("    compl  x = 0b%04b\n\n", compl x);

	printf ("  x and_eq y = 0b%04b\n", x and_eq y);
	printf ("  x or_eq  y = 0b%04b\n", x or_eq y);
	printf ("  x xor_eq y = 0b%04b\n", x xor_eq y);
	printf ("  x not_eq y = 0b%04b\n", x not_eq y);
}

int main (void)
{
	operatory_logiczne ();
	operatory_bitowe ();
}

/* eof. */

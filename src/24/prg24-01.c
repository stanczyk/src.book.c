/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg24-01.c
 * @brief <setjmp.h>: skoki odległe
 */
#include <stdio.h>
#include <setjmp.h>

// zmienne globalne
jmp_buf bufA, bufB;
int licznik_skokow = 0;

// deklaracje
void funA (void);
void funB (void);

int main (void)
{
	funA ();
}

void funA (void)
{
	printf ("start  A\n");
	int ret = setjmp (bufA);
	if (ret == 0)
		funB ();
	printf ("A po %d skoku\n", ret);
	if (ret == 1)
		longjmp (bufB, ++licznik_skokow);
	printf ("koniec A\n");
}

void funB (void)
{
	printf ("start  B\n");
	int ret = setjmp (bufB);
	if (ret == 0)
		longjmp (bufA, ++licznik_skokow);
	printf ("B po %d skoku\n", ret);
	longjmp (bufA, ++licznik_skokow);
	printf ("koniec B\n");
}
/* eof. */

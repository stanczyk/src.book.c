/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg09-08.c
 * @brief Przykład goto
 */
#include <stdio.h>
#include <stdbool.h>

#define ZROB_A true
#define ZROB_B true
#define ZROB_C false

bool zrobA(void)
{
	printf ("zrobA(): %s\n", ZROB_A ? "sukces" : "jest problem!");
	return ZROB_A;
}

bool zrobB(void)
{
	printf ("zrobB(): %s\n", ZROB_B ? "sukces" : "jest problem!");
	return ZROB_B;
}

bool zrobC(void)
{
	printf ("zrobC(): %s\n", ZROB_C ? "sukces" : "jest problem!");
	return ZROB_C;
}

void cofnijA (void)
{
	puts("cofnijA() poszło");
}

void cofnijB (void)
{
	puts("cofnijB() poszło");
}

void foo (void)
{
	if (!zrobA ())
		goto exit;
	if (!zrobB ())
		goto czyscA;
	if (!zrobC ())
		goto czyscB;

	/* wszytko przebiegło pomyślnie */
	puts("wszytko przebiegło pomyślnie");
	return;

 czyscB:
	cofnijB ();
 czyscA:
	cofnijA ();
 exit:
	return;
}

int main (void)
{
	foo();	// foo() jest jako przykład użycia goto.
}

/* eof. */

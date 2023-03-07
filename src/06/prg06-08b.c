/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-08b.c
 * @brief Specyfikator static
 *
 * Specyfikator static w funkcji
 */
#include "prg06-08b.h"

int f1 (int foo)
{
	return f2 (foo);	/* ok, f2 jest w tym samym pliku co f1 */
}

static int f2 (int foo)
{
	return 42 + foo;
}

/* eof. */

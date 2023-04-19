/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-08a.c
 * @brief Specyfikator static
 *
 * Specyfikator static w funkcji
 */
#include "prg06-08b.h"

int main (void)
{
	f1 (10);  /* ok, f1 widoczna dla linkera */
	f2 (12);  /* nope, :( */
}
/* eof. */

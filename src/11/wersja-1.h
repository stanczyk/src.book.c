/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file wersja-1.h
 * @brief Plik nagłówkowy używany w prg11-03.c i prg11-04.c
 */
#ifndef WERSJA_1_H
#define WERSJA_1_H
#include <stdio.h>

int display (void)
{
	return printf ("dołączono: %s\n", __FILE__);
}

#endif /* WERSJA_1_H */

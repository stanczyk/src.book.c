/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prj_head.h
 * @brief Plik nagłówkowy do prg11-02.c
 */
#ifndef PRJ_HEAD_H
#define PRJ_HEAD_H
#include <stdio.h>

int display (void)
{
	return printf ("dołączono: %s\n", __FILE__);
}

#endif /* PRJ_HEAD_H */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
/* SEKCJA DOKUMENTACYJNA     (CZĘŚĆ ZALECANA) */
/**
 * @file prg02.c
 * @brief Typowa struktura kodu w pliku źródłowym
 *
 * UWAGA: przez zamieszczone tu komentarze numeracja wierszy jest inna niż w książce
 */

/* WYKORZYSTYWANE BIBLIOTEKI (CZĘŚĆ WYMAGANA) */
/* pliki nagłówkowe */
#include <stdio.h>
#include <stdlib.h>

/* DEFINICJE                 (CZĘŚĆ OPCJONALNA) */
/* stałe, makra, typy */
#define MAX 5

/* DEKLARACJE                (CZĘŚĆ OPCJONALNA) */
/* zmienne globalne */
int x = 2, y = -7, z;
/* prototypy funkcji */
int fun (int a, int b, int c);

/* FUNKCJA GŁÓWNA            (CZĘŚĆ WYMAGANA) */
int main (void)
{
	int wynik;
	x = x + y * z - MAX;
	wynik = fun (x, abs (y), y + 2);   /* abs f.standardowa z stdlib.h */
	printf ("Rezultat: %d\n", wynik);  /* printf z stdio.h */
	return 0;
}

/* DEFINICJE FUNKCJI         (CZĘŚĆ OPCJONALNA) */
int fun (int a, int b, int c)
{
	int lokalna = 10;
	return (a + b - c + lokalna);
}

/* eof. */

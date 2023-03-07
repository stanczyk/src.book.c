/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg40-03.c
 * @brief <time.h>: struct tm i początek czasu dla tego typu
 *
 * @code
struct tm
{
	int tm_sec; 	// sekundy po minucie  [0, 60]
					// dodatkowa sekunda jest zarezerwowana dla sekundy przestępnej
	int tm_min; 	// minuty po godzinie  [0, 59]
	int tm_hour; 	// godziny od północy  [0, 23]
	int tm_mday; 	// dzień miesiąca      [1, 31]
	int tm_mon; 	// miesiąc od stycznia [0, 11]
	int tm_year; 	// rok od 1900
	int tm_wday; 	// dzień od niedzieli  [0, 6]
	int tm_yday; 	// liczba dni od początku roku [0, 365]
	int tm_isdst; 	// flaga czasu letniego przyjmująca wartość:
					//  - dodatnią, jeśli obowiązuje czas letni,
					//  - zero, jeśli nie,
					//  - ujemną, jeśli brak informacji
}
 * @endcode
 */
#include <stdio.h>
#include <time.h>

int main (void)
{
	struct tm start = {.tm_mday = 1 };
	mktime (&start);
	printf ("%s", asctime (&start));
}

/* eof. */

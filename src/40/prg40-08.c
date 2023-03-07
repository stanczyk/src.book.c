/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg40-08.c
 * @brief <time.h>: jaki dzień tygodnia był 14.08.2001?
 */
#include <stdio.h>
#include <time.h>
static const char *const wday[] = {
	"Niedziela", "Poniedziałek", "Wtorek", "Środa", "Czwartek", "Piątek", "Sobota"
};

int main (void)
{
	struct tm time_str;
	time_str.tm_year = 2001 - 1900;
	time_str.tm_mon = 8 - 1;
	time_str.tm_mday = 14;
	time_str.tm_hour = 0;
	time_str.tm_min = 0;
	time_str.tm_sec = 1;
	time_str.tm_isdst = -1;
	if (mktime(&time_str) == (time_t)(-1))
	time_str.tm_wday = 7;
	printf("%s\n", wday[time_str.tm_wday]);
}

/* eof. */

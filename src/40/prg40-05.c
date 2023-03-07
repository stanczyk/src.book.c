/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg40-05.c
 * @brief <time.h>: ilość sekund jaka upłynęła od początku roku
 */
#include <stdio.h>
#include <time.h>

int main (void)
{
	time_t teraz, wowczas;
	struct tm wowczas_tm;

	// na początek wypełnijmy wszystkie pola struktury aktualnym czasem
	time (&teraz);
	wowczas_tm = *localtime (&teraz);
	// następnie wyzerujmy część
	wowczas_tm.tm_sec = 0;
	wowczas_tm.tm_min = 0;
	wowczas_tm.tm_hour = 0;
	wowczas_tm.tm_mday = 0;
	wowczas_tm.tm_mon = 0;
	wowczas = mktime (&wowczas_tm);

	printf ("Od początku roku minęło już %.f sec.\n", difftime (teraz, wowczas));
}

/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg40-06.c
 * @brief <time.h>: aktualny czas wyświetlony zgodnie z ustawieniami regionalnymi, w tym wypadku de_DE.UTF-8
 */
#include <locale.h>
#include <time.h>
#include <wchar.h>

int main (void)
{
	wchar_t str[100];
	setlocale (LC_ALL, "de_DE.UTF-8");

	time_t t = time (NULL);
	wcsftime (str, 100, L"%c\n", localtime (&t));
	wprintf (str);
}

/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg22-02.c
 * @brief <locale.h>: użycie ustawień regionalnych
 */
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <wchar.h>

int main (void)
{
	wchar_t str[100];
	// wszystkie ustawienia regionalne dla US (utf8)
	char *loc = setlocale (LC_ALL, "en_US.UTF-8");
	if (!loc)
	{
		// błąd setlocale
		return EXIT_FAILURE;
	}
	wprintf(L"LC_ALL = %s\n", loc);

	// kropka dziesiętna po polsku
	loc = setlocale (LC_NUMERIC, "pl_PL.UTF-8");
	if (!loc)
		return EXIT_FAILURE;
	wprintf(L"LC_NUMERIC = %s\n", loc);
	wprintf (L"Liczba po polsku: %.2f\n", 12.34);

	// a czas formatowany po japońsku
	loc = setlocale (LC_TIME, "de_DE.UTF-8");
	if (!loc)
		return EXIT_FAILURE;
	wprintf(L"LC_TIME = %s\n", loc);
	time_t t = time (NULL);
	wcsftime (str, 100, L"%A %c", localtime (&t));
	wprintf (L"Data po niemiecku: %Ls\n", str);
}

/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg34-10.c
 * @brief <stdio.h>: użycie vfprintf
 */
#include <stdarg.h>
#include <stdio.h>

void logError (char *nazwa_funkcji, char *format, ...)
{
	va_list args;
	va_start (args, format);
	// wypisanie nazwy funkcji powodującej błąd
	fprintf (stderr, "BŁĄD w %s: ", nazwa_funkcji);
	// wypisanie pozostałych informacji
	vfprintf (stderr, format, args);
	va_end (args);
}

int main (void)
{
	logError("main", "%d, %d, %d\n", 1, 2, 3);
	logError("main", "%s %d\n", "informacja z wiersza", __LINE__);
}

/* eof. */

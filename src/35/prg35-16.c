/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg35-16.c
 * @brief <stdlib.h>: ustawienie ignorowania błędów, a następnie domyślnego przerwania wykonywania
 * programu w przypadku wystąpienia błędów bezpiecznych funkcji
 *
 * użyto biblioteki safeclib:
 * - 	sudo apt install libsafec-dev
 *
 * safec libc extension with all C11 AnnexK functions
 * - 	https://github.com/rurban/safeclib.git
 * - 	https://rurban.github.io/safeclib/
 */
#define __STDC_WANT_LIB_EXT1__ 1
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <safeclib/safe_str_lib.h>

int main (void)
{
	/*
#ifndef __STDC_LIB_EXT1__
	printf ("nie wspierane __STDC_LIB_EXT1__\n");
	exit(EXIT_FAILURE);
#endif
	*/

	char buf[2];
	int err;

	// set_constraint_handler_s(ignore_handler_s);
	set_str_constraint_handler_s (ignore_handler_s); // funkcja użyta zamiast set_constraint_handler_s
	err = strcpy_s (buf, sizeof buf, "Za długi łańcuch");
	printf ("buf = \"%s\", błąd = %d\n", buf, err);

	// set_constraint_handler_s(abort_handler_s);
	set_str_constraint_handler_s (abort_handler_s); // funkcja użyta zamiast set_constraint_handler_s
	err = strcpy_s (buf, sizeof buf, "Za długi łańcuch");
	printf ("buf = \"%s\", błąd = %d\n", buf, err);
}

/* eof. */

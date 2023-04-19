/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg07-09.c
 * @brief Stałe znakowe w zapisie ósemkowym, szesnastkowym i jako uniwersalna nazwa znaku
 */
#include <locale.h>
#include <stdio.h>

int main (void)
{
	setlocale (LC_ALL, "");
	printf ("Znak w zapisie:\n");
	printf ("    ósemkowym \\101       = %c\n", '\101'); // 'A'
	printf ("szesnastkowym \\x42       = %c\n", '\x42'); // 'B'
	printf ("nazwa:\n");
	printf ("  uniw.krótka \\u2663     = %lc\n", u'\u2663'); //trefl
	printf ("  uniwersalna \\U0001F0D1 = %lc\n", U'\U0001F0D1');//as
}

/* eof. */

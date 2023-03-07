/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg07-08.c
 * @brief Znaki sterujące i ich działanie w oknie terminala
 */
#include <stdio.h>

int main (void)
{
	printf ("1.       Zwykły znak: \'%c\'.\n", 'a' );
	printf ("2.             Alarm: \'%c\'.\n", '\a');
	printf ("3.  Znak nowej linii: \'%c\'.\n", '\n');
	printf ("4. Tabulator poziomy: \'%c\'.\n", '\t');
	printf ("5. Tabulator pionowy: \'%c\'.\n", '\v');
	printf ("6.         Backspace: \'%c\'.\n", '\b');
	printf ("7.    Powrót karetki: \'%c\'.\n", '\r');
}

/* eof. */

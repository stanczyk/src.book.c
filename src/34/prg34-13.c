/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg34-13.c
 * @brief <stdio.h>: użycie ungetc
 */
#include <stdio.h>
int main (void)
{
	ungetc ('\n', stdin);
	ungetc ('j', stdin);
	ungetc ('e', stdin);
	ungetc ('h', stdin);

	while (putchar (getchar ()) != '\n')
		;
}

/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg34-08.c
 * @brief <stdio.h>: użycie fprintf z różnymi flagami w łańcuchu formatującym
 */
#include <stdio.h>

int main (void)
{
	unsigned int i = 10;
	fprintf(stdout, " i = %4i,",  i);
	fprintf(stdout, " i = %+4i,", i);
	fprintf(stdout, " i = %-4i,", i);
	fprintf(stdout, " i = %04i,", i);
	fprintf(stdout, " i = %#b,",  i);
	fprintf(stdout, " i = %#o,",  i);
	fprintf(stdout, " i = %#x\n", i);
}

/* eof. */

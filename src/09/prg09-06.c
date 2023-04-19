/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg09-06.c
 * @brief Pętla do-while
 */
#include <stdio.h>

int main (void)
{
	char str1[] = "Ala ma Asa";
	char str2[11];
	int i;

	i = 0;
	do 						// kopiuj łańcuch str1
		str2[i] = str1[i]; 	// do str2
	while ( str1[i++] != '\0' );
	puts(str2);
}

/* eof. */

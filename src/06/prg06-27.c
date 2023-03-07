/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-27.c
 * @brief Konwersja arytmetyczna: promocja całkowitoliczbowa
 */
#include <stdio.h>

int main (void)
{
	char c1 = 30, c2 = 20, c3 = 10;
	char c4 = c1 * c2 / c3;
	printf ("%d\n", c4); 	// wynik: 60 choć mogłoby się wydawać,
							// że przy obliczaniu c4 nastąpi przepełnienie,
							// ponieważ wartość c1*c2 jest poza zakresem char
}

/* eof. */

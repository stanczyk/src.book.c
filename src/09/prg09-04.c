/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg09-04.c
 * @brief Instrukcja switch
 */
#include <stdio.h>

void akcja1 (void)
{
	printf ("akcja1\n");
}

void akcja2 (void)
{
	printf ("akcja2\n");
}

int main (void)
{
	char polecenie = 'a';

	switch (polecenie) 	// w zależności od wyniku polecenia
	{ 					// np. od wyboru użytkownika w menu
		case 'a':
		case 'A':		// jeśli wynikiem jest 'a' lub 'A'
			akcja1 (); 	// wykonaj akcja1(),
			break; 		// a następnie opuść blok switch

		case 'b':
		case 'B': 		// jeśli wynikiem jest 'b' lub 'B'
			akcja2 (); 	// wykonaj akcja2()
			break; 		// i opuść blok

		default: 		// dla każdego innego wyniku polecenia:
			putchar ('\a');  // wykonaj tę instrukcję
	}
}

/* eof. */

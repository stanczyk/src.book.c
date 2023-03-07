/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-01.c
 * @brief Proste użycie typu wyliczeniowego
 */
#include <stdio.h>
enum przełącznik 	// definicja typu wyliczeniowego
{
	OFF, 			// identyfikatory wyliczenia, jako int, zaczynając od 0
	ON,
	NO = 0, 		// identyfikator NO o wartości przypisanej jawnie
	YES
} przycisk = ON; 	// zmienna przycisk typu enum przełącznik
				 	// o wartości początkowej ON (1)

char * stan (int włącznik)
{
	switch (włącznik)
	{
		case OFF | NO: return "wyłączony";
		case ON | YES: return "włączony";
	}
	return "poza zakresem";
}

int main (void)
{
	printf ("enum przełącznik %i %i %i %i\n", OFF, ON, NO, YES);

	enum przełącznik p1 = 40;
				// wartość p1 jest poza zakresem, kompilator nie zareaguje
	p1 = 1.2;	// wartość p1 jest typu int,
				// zostanie dokonana konwersja p1 = (int) 1.2
	p1 -= 1;	// po tej operacji p1 = 0
	printf ("      p1: %s\n", stan(p1));
	printf ("przycisk: %s\n", stan(przycisk));
}

/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-28.c
 * @brief Konwersja na typ bool
 */
#include <complex.h>
#include <float.h>
#include <stdbool.h>
#include <stdio.h>

int main (void)
{
	bool b1 = 3; 				// b1 == 1, 3 nie jest równe 0, stąd b1 == 1
	bool b2 = 0.1; 				// b2 == 1, jak w przypadku b1
	bool b3 = +0.0; 			// b3 == 0, zero dodatnie to nadal zero
	bool b4 = 3.5 + 0.0 * I; 	// b4 == 1, liczba zespolona jest różna od zero
	bool b5 = 0.0 + 3.5 * I; 	// b5 == 1, jak w przypadku b4
	bool b6 = INFINITY; 		// b6 == 1, nieskończoność nie jest zerem
	bool b7 = NAN; 				// b7 == 1, NaN nie jest zerem

	printf("b1: %d\n", b1);
	printf("b2: %d\n", b2);
	printf("b3: %d\n", b3);
	printf("b4: %d\n", b4);
	printf("b5: %d\n", b5);
	printf("b6: %d\n", b6);
	printf("b7: %d\n", b7);
}

/* eof. */

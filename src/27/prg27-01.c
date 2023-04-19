/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg27-01.c
 * @brief <stdarg.h>: funkcja mymax przyjmująca zmienną liczbę argumentów
 *
 * mymax określa maksymalną wartość z podanych liczb naturalnych.
 * Parametry: zmienna liczba wartości naturalnych typu unsigned int, ostatni argument musi mieć wartość 0.
 * Wartość zwracana: maksymalna wartość spośród argumentów
 */

#include <stdio.h>
#include <stdarg.h>

unsigned int mymax (unsigned int first, ...)
{
	unsigned int maxarg, arg;
	va_list arglist;           // lista argumentów opcjonalnych

	va_start (arglist, first); // ustaw arglist tak, aby dostarczał pierwszy opcjonalny argument
	arg = maxarg = first;
	while (arg != 0)
	{
		arg = va_arg (arglist, unsigned);  // pobierz argument

		if (arg > maxarg)
			maxarg = arg;
	}
	va_end (arglist);          // koniec obróbki arglist
	return maxarg;
}

int main (void)
{
	printf ("%d\n", mymax (3, 0));
	printf ("%d\n", mymax (1, 2, 3, 0));
	printf ("%d\n", mymax (1, 2, 3, 4, 5, 0));
}

/* eof. */

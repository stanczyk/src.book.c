/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-15.c
 * @brief Kwalifikator restrict
 */
#include <stdio.h>

int fun (int * arg1, int * arg2)
{
	*arg1 = 5;
	*arg2 = 6;
	return *arg1 + *arg2;
}

int rfu (int * restrict arg1, int * restrict arg2)
{
	*arg1 = 5;
	*arg2 = 6;
	return *arg1 + *arg2;
}

int main (void)
{
	int a, b;

	printf("fun=%i\n", fun(&a, &a)); // OK, choć
									 // wynik inny niż oczekiwano
	printf("rfu=%i\n", rfu(&a, &a)); // operacja niedozwolona
									 // (gcc generuje ostrzeżenie)
	printf("rfu=%i\n", rfu(&a, &b)); // OK
}

/* eof. */

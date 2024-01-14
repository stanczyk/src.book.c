/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg04-07.c
 * @brief Użycie typu _BitInt
 *
 * @pre gcc w wersji 12.1.0, 12.2.0, 13.1.0, 13.2.0 nie wspiera _BitInt
 */
#include <limits.h>
#include <stdio.h>

int main (void)
{
	printf ("max.szerokość bitowa _BitInt: %d\n", BITINT_MAXWIDTH);

	_BitInt (2) a2 = 1;
	_BitInt (3) a3 = 2;
	_BitInt (33) a33 = 1;
	char c = 3;

	_BitInt (3) w1 =
		a2 * a3 ;  /* podczas mnożenia a2 jest konwertowane na _BitInt(3),
					  typem wyniku jest _BitInt(3). */
	printf("w1 = %i\n", (int) w1);

	int w2 =
		a2 * c ;   /* podczas mnożenia c jest promowane do int,
					  a2 jest konwertowane na int,
					  typem wyniku jest int. */
	printf("w2 = %i\n", (int) w2);

	_BitInt (33) w3 =
		a33 * c ;  /* podczas mnożenia c jest promowane do int,
					  a następnie konwertowane na _BitInt(33),
					  typem wyniku jest _BitInt(33). */
	printf("w3 = %li\n", (long) w3);
}

void func_iloczyn (_BitInt (8) a1, _BitInt (24) a2)
{
  /* Aby zagwarantować, że wynik mnożenia może zawierać wszystkie możliwe wartości,
	 należy rzutować jeden z operandów na typ o szerokości 32 bity */
	_BitInt (32) a3 = a1 * (_BitInt (32)) a2;
	printf("a3 = %li\n", (long) a3);
}

/* eof. */

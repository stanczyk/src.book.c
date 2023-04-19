/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-10.c
 * @brief Specyfikator constexpr
 */
#include <stdio.h>
#include <limits.h>

constexpr int A = 42;
constexpr int B = A + 1;

struct S {
	int x, y;
};
constexpr struct S s = {
	.x = INT_MAX,
	.y = 0,
};

int main(void)
{
	printf("A = %i\n", A);
	printf("B = %i\n", B);
	printf("S = {x=%i, y=%i}\n", s.x, s.y);
}

/* eof. */

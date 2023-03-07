/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg28-02.c
 * @brief <stdatomic.h>: sprawdzenie, czy struktura jest wolna od blokady
 */
#include <stdio.h>
#include <stdatomic.h>

int main(void)
{
	struct A { int x, y; };
	struct B { int x, y, z; };

	_Atomic struct A a;
	_Atomic struct B b;

	printf("czy zmienna jest wolna od blokady?\n");
	printf("_Atomic struct A ");
	printf("%s\n", atomic_is_lock_free(&a) ? "tak" : "nie");
	printf("_Atomic struct B ");
	printf("%s\n", atomic_is_lock_free(&b) ? "tak" : "nie");
}
/* eof. */

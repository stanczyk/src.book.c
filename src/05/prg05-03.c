/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-03.c
 * @brief Typy wyliczeniowe z wyspecyfikowanym typem wyliczenia
 */
#include <limits.h>
int main (void)
{
	enum E1: short;
	enum E2: short;

	enum E1 : short { m11, m12 };
	enum E1 x = m11;

	enum E2 : long { m21, m22 };  // Naruszenie ograniczeń: różne typy E2

	enum E3 : unsigned long long {
		m31 = sizeof(enum E3),
		m32 = ULLONG_MAX,
		m33 	// Naruszenie ograniczeń: wartość m33 jest spoza zakresu
				// (bo powinna mieć wartość ULLONG_MAX + 1
	};
}

/* eof. */

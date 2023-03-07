/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg13-02.c
 * @brief <assert.h>: użycie static_assert
 */
#include <assert.h>
enum Elementy { PIERWSZY, DRUGI, TRZECI, ILOSC_EL };

int main (void)
{
	// w wierszu poniżej nie ma błędu
	static_assert(2 + 2 == 4, "sprawdzam, czy działa");

	// testuje enum Elementy,
	// tzn. jeśli coś zostanie tam dopisane wygeneruje błąd:
	static_assert (ILOSC_EL == 3);
	// lub
	static_assert (ILOSC_EL == 3, "Spodziewana ilość elementów w enum Elementy wynosi 3");

	// kompilacja poprawna tylko w systemach,
	// w których długość int wynosi 2 bajty
	static_assert (sizeof (int) == 2);
	// lub
	static_assert (sizeof (int) == 2, "Spodziewany 16-bitowy int");
}

/* eof. */

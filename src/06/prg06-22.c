/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-22.c
 * @brief Atrybut nodiscard
 */
#include <stdbool.h>

void detonuj (void);

[[nodiscard ("uwaga na stan uzbrojenia")]] bool uzbrójDetonator (int);

void wysadzaj (void)
{
	uzbrójDetonator (3); // kompilator wygeneruje ostrzeżenie: "uwaga na stan uzbrojenia"
	detonuj ();
}

int main (void)
{
	wysadzaj ();
}

bool uzbrójDetonator (int) { return false; }
void detonuj (void) { ; }

/* eof. */

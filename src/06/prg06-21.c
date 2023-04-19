/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-21.c
 * @brief Atrybut maybe_unused
 */
void foo (int i)
{
	int k = 100;
	int j = k + 100;
}

[[maybe_unused]] void fun ([[maybe_unused]] int i)
{
	int k = 100;
	[[maybe_unused]] int j = k + 100;
}

int main (void) {}
/* eof. */

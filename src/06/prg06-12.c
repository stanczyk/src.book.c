/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-12.c
 * @brief Kwalifikator const
 *
 * const w strukturach i uniach
 */

// przypadek 1.
struct s { int i; const int ci; }
s1 = { .ci = 1 },
s2 = { .ci = 2 };
s1 = s2; // błąd przypisania nowej wartości zmiennej tylko do odczytu, bo s1.ci jest const

// przypadek 2.
const struct s cs;
cs = s1; // błąd przypisania nowej wartości zmiennej tylko do odczytu, bo całe cs jest tylko do odczytu}

int main (void) {}

/* eof. */

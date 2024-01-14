/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg04-13.c
 * @brief Przykład deklaracji i wyświetlenia zmiennej typu _Decimal32
 *
 * @pre Do kompilacji potrzebna jest biblioteka libdfp (ponieważ GLIBC 2.35 -- 2.38 nie wspiera tych typów)
 *  - pakiet dla ubuntu: sudo apt-get install -y libdfp-dev
 *  - lub kompilacja ze źródeł: https://github.com/libdfp/libdfp (configure; make; sudo make install)
 * Wersja glibc: ldd --version
 */
#include <stdio.h>

int main (void)
{
	_Decimal32 x = 6543.00df;
	printf ("%Hf\n", x);
	printf ("%f\n", (float) x);
}

/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg08-12.c
 * @brief Przesuwanie bitów w liczbach ze znakiem
 */
// #pragma GCC diagnostic ignored "-Woverflow"
#include <stdio.h>
#define HEX2(x) (0x000000FF & (x))

int main (void)
{
	signed char a = 0b01000011;
	signed char b = 0b11000011;
	signed char wynik;

	printf ("przesuwanie w prawo >>\n");
	printf ("a      = 0b%032b = 0x%02X = %4i\n", a, a, a);
	wynik = a >> 1;
	printf ("a >> 1 = 0b%032b = 0x%02X = %4i\n", wynik, wynik, wynik);
	wynik = a >> 2;
	printf ("a >> 2 = 0b%032b = 0x%02X = %4i\n", wynik, wynik, wynik);

	printf ("\n");
	printf ("b      = 0b%032b = 0x%02X = %4i\n", b, HEX2(b), b);
	wynik = b >> 1;
	printf ("b >> 1 = 0b%032b = 0x%02X = %4i\n", wynik, HEX2(wynik), wynik);
	wynik = b >> 2;
	printf ("b >> 2 = 0b%08b = 0x%02X = %4i\n", wynik, HEX2(wynik), wynik);

	printf ("\nprzesuwanie w lewo  <<\n");
	printf ("b      = 0b%032b = 0x%02X = %4i\n", b, HEX2(b), b);
	wynik = b << 1;
	printf ("b << 1 = 0b%032b = 0x%02X = %4i\n", wynik, HEX2(wynik), wynik);
	wynik = b << 2;
	printf ("b << 2 = 0b%032b = 0x%02X = %4i\n", wynik, HEX2(wynik), wynik);
}

/* eof. */

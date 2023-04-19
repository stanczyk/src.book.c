/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg08-11.c
 * @brief Działanie operatorów bitowych
 */
#include <stdio.h>

int main (void)
{
	unsigned char x = 0b1010;  // 10
	unsigned char y = 0b1100;  // 12

	printf ("     x = 0b%b\n", x);
	printf ("     y = 0b%b\n", y);

	// logiczne operatory bitowe
	// x & y   1 jeśli 1 zarówno w x jak i w y
	printf (" x & y = 0b%04b\n", x & y);
	// x | y   1 jeśli 1 w x lub w y
	printf (" x | y = 0b%04b\n", x | y);
	// x ^ y   1 jeśli 1 w x lub w y ale nie w obu
	printf (" x ^ y = 0b%04b\n", x ^ y);
	// ~x      1 jeśli 0 a 0 jeśli 1 w x
	printf ("    ~x = 0b%04b\n", ~x);
	printf ("\n");

	// operatory przesunięcia bitowego
	x = 0xF;
	printf ("     x = 0b%08b = 0x%02X = %3i\n", x, x, x);
	y = x << 4;    // daje 0xF0
	printf ("x << 4 = 0b%08b = 0x%02X = %3i\n", y, y, y);
	y = x >> 2;    // daje 0x3
	printf ("x >> 2 = 0b%08b = 0x%02X = %3i\n", y, y, y);
}

/* eof. */

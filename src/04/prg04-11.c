/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg04-11.c
 * @brief Zmiennoprzecinkowe ograniczenia związane z precyzją i zakresem
 */
#include <stdio.h>

int main (void)
{
	float x, y, z;

	x = 0.123456789;
	y = 123456789.0;
	z = 10E+10;

	printf("x = %f\n", x);
	printf("y = %f\n", y);
	printf("z = %f\n", z);

	float tmp = x;
	// x = (x * y) * z;  // nie jest równoważne x *= y * z;
	tmp *= y * z;
	printf("\n");
	printf("%f\n", (x * y) * z);
	printf("%f\n", tmp);

	// z = (x - y) + y;  // nie jest równoważne z = x;
	printf("\n");
	printf("%f\n", (x - y) + y);
	printf("%f\n", x);

	// z = x + x * y;    // nie jest równoważne z = x * (1.0 + y);
	printf("\n");
	printf("%f\n", x + x * y);
	printf("%f\n", x * (1.0 + y));

	// y = x / 5.0;      // nie jest równoważne y = x * 0.2;
	// akurat dla powyższych wartości jest OK
}

/* eof. */

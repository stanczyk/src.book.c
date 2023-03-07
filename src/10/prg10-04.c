/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg10-04.c
 * @brief Funkcja obliczająca objętość walca zadeklarowana w stylu K&R
 */
#include <stdio.h>
#include <stdlib.h>

double objetoscWalca (r, h)
		 double r;	// promień podstawy
		 double h;	// wysokość walca
{
	const double pi = 3.1415926536;

	return pi * r * r * h;
}

int main (void)
{
	double promien = 5.0;
	double wysokosc = 3.0;

	printf ("objętość walca o promieniu podstawy %.2f i wysokości %.2f wynosi %.2f\n",
		promien, wysokosc, objetoscWalca (promien, wysokosc));
}

/* eof. */

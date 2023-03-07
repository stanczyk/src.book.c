/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg34-12.c
 * @brief <stdio.h>: użycie sscanf
 */
#include <stdio.h>

int main (void)
{
	int i1, i2;
	double d;
	float f;
	char str1[11], str2[4];

	char input[] = "23 45.32E-1 Ala-ma-Asa 56789 0123   45zł";
	/*
	łańcuch input parsowany następująco:
	%d:   liczba typu integer (23)
	%lf:  liczba typu double  (45.32E-1)
	%10s: łańcuch 10 znaków   (bez białych znaków: Ala-ma-Asa)
	%2d:  dwie cyfry integer  (cyfra 5 i 6)
	%f:   liczba typu float   (cyfry 7, 8, 9)
	%*d:  liczba typu integer nieprzechowywana w żadnej zmiennej
	' ':  białe znaki         (w tym przypadku spacje)
	%3[0-9]: łańcuch max. 3 znaków z zakresu [0-9]
	                          (czyli cyfry 4 i 5)
	*/

	int ret = sscanf (input, "%d%lf%10s%2d%f%*d %3[0-9]", &i1, &d, str1, &i2, &f, str2);
	printf ("przekonwertowano pól: %d\n i1=%i\n i2=%i\n d=%f\n f=%f\n str1=%s\n str2=%s\n", ret, i1, i2, d, f, str1, str2);
}

/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-11.c
 * @brief Łańcuchy znaków różnych typów
 */
#include <stdio.h>
#include <uchar.h>
#include <wchar.h>

int main (void)
{
			 char s1[] =   "napis";
	unsigned char s2[] = u8"napis";
		 char16_t s3[] =  u"napis";
		 char32_t s4[] =  U"napis";
		  wchar_t s5[] =  L"napis";

	printf ("%s\n", s1);
	printf ("%s\n", s2);
	// printf ("%ls\n", s3);
	printf ("%ls\n", s4);
	printf ("%ls\n", s5);
}

/* eof. */

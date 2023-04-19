/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-18.c
 * @brief Użycie alignas do określenia wyrównania w strukturze
 */
#include <stdio.h>
#include <stdalign.h>

/* Struktura data1 będzie wyrównywana do 32 bajtów,
   ponieważ tyle wynosi wartość _Alignas
   i jest to największe wyrównanie jednej ze składowych */
typedef struct
{
	int i;	// pomiędzy i (sizeof = 4) a buforem wstawione zostanie
			// 28 bajtów dopełnienia do 32-bajtowego wyrównania
	alignas (32) char bufor[32];
} data1;

/* Struktura data2 będzie wyrównywana do 4 bajtów,
   ponieważ tyle wynosi największe wyrównanie jednej ze składowych*/
typedef struct
{
	int i;	// pomiędzy i a buforem nie będzie żadnego wypełnienia
	char bufor[32];
} data2;

int main (void)
{
	printf ("sizeof (data1): %zu, ", sizeof (data1));
	printf ("alignof (data1): %zu\n", alignof (data1));

	printf ("sizeof (data2): %zu, ", sizeof (data2));
	printf ("alignof (data2): %zu\n", alignof (data2));
}

/* eof. */

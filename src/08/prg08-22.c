/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg08-22.c
 * @brief Operator alignof
 *
 * _Alignof i makro alignof z <stdalign.h>
 */
#include <stdio.h>
#include <stddef.h>
#include <stdalign.h>
int main (void)
{
	printf ("wyrównanie dla:\n");
	printf (" char = %zu\n", alignof (char));
	printf (" max_align_t = %zu\n", alignof (max_align_t));
	printf (" float[10] = %zu\n", alignof (float[10]));
	printf (" struct {char c; int n;} = %zu\n", alignof (struct {char c; int n;}));
}

/* eof. */

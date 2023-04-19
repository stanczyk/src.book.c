/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg08-03.c
 * @brief Makro ze słowem kluczowym _Generic
 */
#include <stdio.h>

#define NAZWA_TYPU(X) _Generic( (X),    \
      int: "liczba całkowita",          \
     char: "litera",                    \
   double: "liczba zmiennoprzecinkowa", \
  default: "nieokreślony typ" )

#define format "%5s - %s\n"

int main (void)
{
	printf (format format format format,
		"111", NAZWA_TYPU(111),
		"1.1", NAZWA_TYPU(1.1),
		"a",   NAZWA_TYPU((char) 'a'),
		"aaa", NAZWA_TYPU("aaa")
	);
}

/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file head0-00.h
 * @brief wyświetlanie stałych symbolicznych
 * ostatnia aktualizacja: grudzień 2023
 */
#include <stdio.h>
#include <string.h>

#define STR(x) #x
#define SHOW_DEFINE(x)	printf("%s %s\n", #x, strcmp(STR(x), #x) != 0 ? STR(x) : "niezdefiniowane")

/* eof. */

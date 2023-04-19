/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg11-23.c
 * @brief Dyrektywa #error
 */
#if __has_include( <feature.h> )
#	include <feature.h>
#else
#	error "Obsługa <feature.h> jest niedostępna."
#endif

int main (void) {}

/* eof. */

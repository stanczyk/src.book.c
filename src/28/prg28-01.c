/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg28-01.c
 * @brief <stdatomic.h>: Makra z rodziny ATOMIC_typ_LOCK_FREE i ich wartość
 */
#include <stdatomic.h>
#include <stdio.h>

int main (void)
{
	printf("ATOMIC_BOOL_LOCK_FREE:    %d, ", ATOMIC_BOOL_LOCK_FREE);
	printf("ATOMIC_CHAR16_T_LOCK_FREE:%d\n", ATOMIC_CHAR16_T_LOCK_FREE);
	printf("ATOMIC_CHAR32_T_LOCK_FREE:%d, ", ATOMIC_CHAR32_T_LOCK_FREE);
	printf("ATOMIC_CHAR_LOCK_FREE:    %d\n", ATOMIC_CHAR_LOCK_FREE);
	printf("ATOMIC_INT_LOCK_FREE:     %d, ", ATOMIC_INT_LOCK_FREE);
	printf("ATOMIC_LLONG_LOCK_FREE:   %d\n", ATOMIC_LLONG_LOCK_FREE);
	printf("ATOMIC_LONG_LOCK_FREE:    %d, ", ATOMIC_LONG_LOCK_FREE);
	printf("ATOMIC_POINTER_LOCK_FREE: %d\n", ATOMIC_POINTER_LOCK_FREE);
	printf("ATOMIC_SHORT_LOCK_FREE:   %d, ", ATOMIC_SHORT_LOCK_FREE);
	printf("ATOMIC_WCHAR_T_LOCK_FREE: %d\n", ATOMIC_WCHAR_T_LOCK_FREE);
}

/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg07-03.c
 * @brief Separator cyfr w przykładach
 */
#include <stdio.h>

int main (void)
{
	int b = 0b11'10'11'01;
	printf("%b\n", b);
	/*
	0b11'10'11'01    // 0b11101101
	'1'2             // znak '1' po którym następuje stała całkowita 2,
	                 // a nie stała całkowitoliczbowa 12
	11'22            // 1122
	0x'FFFF'FFFF     // niepoprawna stała szesnastkowa
	                 // znak ' nie może pojawić się zaraz po 0x
	0xFFFF'FFFF      // poprawna stała szesnastkowa 0xFFFFFFFF
	0x1'2'3'4AB'C'D  // 0x1234ABCD
	*/
}

/* eof. */

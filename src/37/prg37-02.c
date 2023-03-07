/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg37-02.c
 * @brief <string.h>: użycie funkcji strcpy_s
 *
 * użyto biblioteki safeclib
 *  - sudo apt install libsafec-dev
 *
 * safec libc extension with all C11 AnnexK functions
 *  - https://github.com/rurban/safeclib.git
 *  - https://rurban.github.io/safeclib/
 */
#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <string.h>
#include <safeclib/safe_str_lib.h>
int main (void)
{
	char src1[100] = "hello";
	char src2[7] = { 'g', 'o', 'o', 'd', 'b', 'y', 'e' };
	char dst1[6], dst2[5], dst3[5];
	int r1, r2, r3;
	r1 = strncpy_s(dst1, 6, src1, 100);
	r2 = strncpy_s(dst2, 5, src2, 7);
	r3 = strncpy_s(dst3, 5, src2, 4);

	printf("%d, %s\n", r1, dst1);
	printf("%d, %s\n", r2, dst2);
	printf("%d, %s\n", r3, dst3);
}

/* eof. */

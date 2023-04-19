/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg37-06.c
 * @brief <string.h>: użycie funkcji strncat_s
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
	char s1[100] = "good";
	char s2[6] = "hello";
	char s3[6] = "hello";
	char s4[7] = "abc";
	char s5[1000] = "bye";
	int r1, r2, r3, r4;
	r1 = strncat_s(s1, 100, s5, 1000);
	r2 = strncat_s(s2, 6, "", 1);
	r3 = strncat_s(s3, 6, "X", 2);
	r4 = strncat_s(s4, 7, "defghijklmn", 3);

	printf("%d, %s\n", r1, s1);
	printf("%d, %s\n", r2, s2);
	printf("%d, %s\n", r3, s3);
	printf("%d, %s\n", r4, s4);
}

/* eof. */

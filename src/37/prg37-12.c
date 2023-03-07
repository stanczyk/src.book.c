/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg37-12.c
 * @brief <string.h>: użycie funkcji strncat_s
 *
 * użytko biblioteki safeclib
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
	static char str1[] = "?a???b,,,#c";
	static char str2[] = "\t \t";
	char *t, *ptr1, *ptr2;
	rsize_t max1 = sizeof (str1);
	rsize_t max2 = sizeof (str2);

	t = strtok_s(str1, &max1, "?", &ptr1); // t points to the token "a"
	if (t) puts(t); else puts("");
	t = strtok_s(NULL, &max1, ",", &ptr1); // t points to the token "??b"
	if (t) puts(t); else puts("");
	t = strtok_s(str2, &max2, " \t", &ptr2); // t is a null pointer
	if (t) puts(t); else puts("");
	t = strtok_s(NULL, &max1, "#,", &ptr1); // t points to the token "c"
	if (t) puts(t); else puts("");
	t = strtok_s(NULL, &max1, "?", &ptr1); // t is a null pointer
	if (t) puts(t); else puts("");
}

/* eof. */

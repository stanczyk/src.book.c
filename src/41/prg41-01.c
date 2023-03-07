/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg41-01.c
 * @brief <uchar.h>: konwersja UTF-32 na UTF-8
 */
#include <stdio.h>
#include <locale.h>
#include <uchar.h>
#include <stdlib.h>

mbstate_t state;

int main (void)
{
	setlocale (LC_ALL, "");

	// łańcuch znaków UTF-32: 0x47 0x72 \u00fc \u00df 0x65 0
	char32_t in[] = U"Grüße";
	size_t in_sz = sizeof in / sizeof *in;

	printf ("Konwersja %zu znaków UTF-32:\n[ ", in_sz);
	for (size_t n = 0; n < in_sz; ++n)
		printf ("%#x ", in[n]);
	printf ("]\n");

	// konwersja na UTF-8
	char out[MB_CUR_MAX * in_sz];
	char *p = out;

	for (size_t n = 0; n < in_sz; ++n)
	{
		size_t rc = c32rtomb (p, in[n], &state);
		if (rc == (size_t) -1)
			break;
		p += rc;
	}

	size_t out_sz = p - out;
	printf ("na %zu znaków UTF-8:\n[ ", out_sz);
	for (size_t x = 0; x < out_sz; ++x)
		printf ("%#x ", +(unsigned char) out[x]);
	printf ("]\n");
}

/* eof. */

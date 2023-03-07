/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg41-02.c
 * @brief <uchar.h>: konwersja UTF-8 na UTF-32
 */
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <uchar.h>

mbstate_t state;

int main (void)
{
	setlocale (LC_ALL, "");

	// łańcuch znaków UTF-8:
	char in[] = "\x47\x72\xc3\xbc\xc3\x9f\x65\x20\xf0\x9f\x98\x9b";
	size_t in_sz = sizeof in / sizeof *in;

	printf ("Konwersja %zu znaków UTF-8:\n[ ", in_sz);
	for (size_t n = 0; n < in_sz; ++n)
		printf ("%#x ", (unsigned char) in[n]);
	printf ("]\n");

	char32_t out[in_sz];
	char *p_in = in, *end = in + in_sz;
	char32_t *p_out = out;
	size_t rc;

	while ((rc = mbrtoc32 (p_out, p_in, end - p_in, &state)))
	{
		if (rc == (size_t) -1)
			break;
		if (rc == (size_t) -2)
			break;
		if (rc == (size_t) -3)
			break;
		p_in += rc;
		p_out += 1;
	}

	size_t out_sz = p_out - out + 1;
	printf ("na %zu znaków UTF-32:\n[ ", out_sz);
	for (size_t x = 0; x < out_sz; ++x)
		printf ("%#x ", out[x]);
	printf ("]\n");
}

/* eof. */

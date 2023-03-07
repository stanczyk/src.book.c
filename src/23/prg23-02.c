/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg23-02.c
 * @brief <math.h>: klasyfikacja liczb zmiennoprzecinkowych przy użyciu fpclassify
 */
#include <float.h>
#include <math.h>
#include <stdio.h>

const char *show_fp_classify (double x)
{
	switch (fpclassify (x))
	{
		case FP_INFINITE:	return "FP_INFINITE";
		case FP_NAN:		return "FP_NAN";
		case FP_ZERO:		return "FP_ZERO";
		case FP_NORMAL:		return "FP_NORMAL";
		case FP_SUBNORMAL:	return "FP_SUBNORMAL";
	}
	return "unknown";
}

int main (void)
{
	printf ("INFINITY - 1.0 - %s\n", show_fp_classify (INFINITY - 1.0));
	printf ("     0.0 / 0.0 - %s\n", show_fp_classify (0.0 / 0.0));
	printf ("          -0.0 - %s\n", show_fp_classify (-0.0));
	printf ("           1.0 - %s\n", show_fp_classify (1.0));
	printf (" DBL_MIN / 2.0 - %s\n", show_fp_classify (DBL_MIN / 2));
}

/* eof. */

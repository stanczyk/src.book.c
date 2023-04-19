/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg18-02.c
 * @brief <float.h>: charakterystyka dziesiętnych typów zmiennoprzecinkowych
 *
 * GNU C & libc:
 *  - GNU C (GCC) supports decimal floating types
 *
 * But:
 * - GCC does not provide the C library functionality associated with math.h, fenv.h, stdio.h, stdlib.h, and wchar.h
 */
#include <stdio.h>
#include <float.h>

#ifndef __STDC_IEC_60559_DFP__
#warning "__STDC_IEC_60559_DFP__ nie wspierane"
#endif

int main (void)
{
	printf ("DEC_EVAL_METHOD  = %d\n",  DEC_EVAL_METHOD);
	printf ("DEC_INFINITY     = %Hf\n", DEC_INFINITY);
	printf ("DEC_NAN          = %Hf\n", DEC_NAN);
	printf ("\n");
	printf ("               DEC32 \t\tDEC64 \t\tDEC128 \n");
	printf ("MANT_DIG     = %d  \t\t%d   \t\t%d\n",   DEC32_MANT_DIG, DEC64_MANT_DIG, DEC128_MANT_DIG);
	printf ("MIN_EXP      = %+d \t\t%+d  \t\t%+d\n",  DEC32_MIN_EXP,  DEC64_MIN_EXP,  DEC128_MIN_EXP);
	printf ("MAX_EXP      = %+d \t\t%+d  \t\t%+d\n",  DEC32_MAX_EXP,  DEC64_MAX_EXP,  DEC128_MAX_EXP);
	printf ("EPSILON      = %HE \t\t%DE  \t\t%DDE\n", DEC32_EPSILON,  DEC64_EPSILON,  DEC128_EPSILON);
	printf ("MAX          = %HE \t\t%DE  \t\t%DDE\n", DEC32_MAX,      DEC64_MAX,      DEC128_MAX);
	printf ("MIN          = %HE \t\t%DE  \t\t%DDE\n", DEC32_MIN,      DEC64_MIN,      DEC128_MIN);
	printf ("TRUE_MIN     = %HE \t\t%DE  \t\t%DDE\n", DEC32_TRUE_MIN, DEC64_TRUE_MIN, DEC128_TRUE_MIN);
	printf ("SNAN         = %Hf \t\t%Df  \t\t%DDf\n", DEC32_SNAN,     DEC64_SNAN,     DEC128_SNAN);
}

/* eof. */

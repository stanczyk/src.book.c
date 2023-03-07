/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg18-01.c
 * @brief <float.h>: charakterystyka typów zmiennoprzecinkowych
 */
#include <stdio.h>
#include <float.h>

int main (void)
{
	printf ("FLT_RADIX      = %d\n", FLT_RADIX);
	printf ("DECIMAL_DIG    = %d\n", DECIMAL_DIG);
	printf ("FLT_ROUNDS     = %d\n", FLT_ROUNDS);
	printf ("FLT_EVAL_METHOD= %d\n", FLT_EVAL_METHOD);
	printf ("INFINITY       = %f\n", INFINITY);
	printf ("NAN            = %f\n", NAN);
	printf ("\n");
	printf ("                 FLT \t\tDBL \t\tLDBL \n");
	printf ("IS_IEC_60559   = %d \t\t%d \t\t%d\n",  FLT_IS_IEC_60559, DBL_IS_IEC_60559, LDBL_IS_IEC_60559);
	printf ("DECIMAL_DIG    = %d \t\t%d \t\t%d\n",  FLT_DECIMAL_DIG,  DBL_DECIMAL_DIG,  LDBL_DECIMAL_DIG);
	printf ("MIN            = %E \t%E   %LE\n",     FLT_MIN,          DBL_MIN,          LDBL_MIN);
	printf ("TRUE_MIN       = %E \t%E   %LE\n",     FLT_TRUE_MIN,     DBL_TRUE_MIN,     LDBL_TRUE_MIN);
	printf ("MAX            = %E \t%E   %LE\n",     FLT_MAX,          DBL_MAX,          LDBL_MAX);
	printf ("NORM_MAX       = %E \t%E   %LE\n",     FLT_NORM_MAX,     DBL_NORM_MAX,     LDBL_NORM_MAX);
	printf ("EPSILON        = %E \t%E   \t%LE\n",   FLT_EPSILON,      DBL_EPSILON,      LDBL_EPSILON);
	printf ("DIG            = %d \t\t%d \t\t%d\n",  FLT_DIG,          DBL_DIG,          LDBL_DIG);
	printf ("MANT_DIG       = %d \t\t%d \t\t%d\n",  FLT_MANT_DIG,     DBL_MANT_DIG,     LDBL_MANT_DIG);
	printf ("MIN_EXP        = %d \t\t%d \t\t%d\n",  FLT_MIN_EXP,      DBL_MIN_EXP,      LDBL_MIN_EXP);
	printf ("MIN_10_EXP     = %d \t\t%d \t\t%d\n",  FLT_MIN_10_EXP,   DBL_MIN_10_EXP,   LDBL_MIN_10_EXP);
	printf ("MAX_EXP        = %d \t\t%d \t\t%d\n",  FLT_MAX_EXP,      DBL_MAX_EXP,      LDBL_MAX_EXP);
	printf ("MAX_10_EXP     = %d \t\t%d \t\t%d\n",  FLT_MAX_10_EXP,   DBL_MAX_10_EXP,   LDBL_MAX_10_EXP);
	printf ("HAS_SUBNORM    = %d \t\t%d \t\t%d\n",  FLT_HAS_SUBNORM,  DBL_HAS_SUBNORM,  LDBL_HAS_SUBNORM);
	printf ("SNAN           = %f \t\t%f \t\t%Lf\n", FLT_SNAN,         DBL_SNAN,         LDBL_SNAN);
}

/* eof. */

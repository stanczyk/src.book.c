/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg23-01.c
 * @brief <math.h>: rozmiary typów
 */
#include <float.h>
#include <math.h>
#include <stdio.h>

int main (void)
{
	printf("FLT_EVAL_METHOD = %d\n", FLT_EVAL_METHOD);

	// rozmiary typów w bajtach
	printf("       float = %zu,\t float_t = %zu\n",	sizeof(float), sizeof(float_t));
	printf("      double = %zu,\t double_t = %zu\n", sizeof(double), sizeof(double_t));
	printf(" long double = %zu\n", sizeof(long double));

	#ifdef __STDC_IEC_60559_DFP__
		printf("DEC_EVAL_METHOD = %d\n", DEC_EVAL_METHOD);
		printf(" _Decimal32  = %zu,\t _Decimal32_t = %zu\n", sizeof(_Decimal32), sizeof(_Decimal32_t));
		printf(" _Decimal64  = %zu,\t _Decimal64_t = %zu\n", sizeof(_Decimal64), sizeof(_Decimal64_t));
		printf(" _Decimal128 = %zu\n", sizeof(_Decimal128));
	#else
		printf("__STDC_IEC_60559_DFP__ nie jest wspierane\n");
	#endif
}

/* eof. */

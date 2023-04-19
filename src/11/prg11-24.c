/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg11-24.c
 * @brief Wartości poszczególnych makr predefiniowanych
 */
#include <stdio.h>

void makra_wymagane(void)
{
	printf ("makra wymagane przez normę:\n");
	printf ("  __DATE__ = %s\n", __DATE__);
	printf ("  __FILE__ = %s\n", __FILE__);
	printf ("  __LINE__ = %i\n", __LINE__);
	printf ("  __STDC__ = %i\n", __STDC__);
	printf ("  __STDC_HOSTED__ = %i\n", __STDC_HOSTED__);
#ifdef __STDC_UTF_16__
	printf ("  __STDC_UTF_16__ = %d\n", __STDC_UTF_16__);
#else
	printf ("  __STDC_UTF_16__ niezdefiniowane\n");
#endif
#ifdef __STDC_UTF_32__
	printf ("  __STDC_UTF_32__ = %d\n", __STDC_UTF_32__);
#else
	printf ("  __STDC_UTF_32__ niezdefiniowane\n");
#endif
	printf ("  __STDC_VERSION__ = %ld\n", __STDC_VERSION__);
	printf ("  __TIME__ = %s\n", __TIME__);
}

void makra_opcjonalne(void)
{
	printf ("makra opcjonalne:\n");
#ifdef __STDC_ISO_10646__
	printf ("  __STDC_ISO_10646__ = %ld\n", __STDC_ISO_10646__);
#else
	printf ("  __STDC_ISO_10646__ niezdefiniowane\n");
#endif
#ifdef __STDC_MB_MIGHT_NEQ_WC__
	printf ("  __STDC_MB_MIGHT_NEQ_WC__ = %d\n", __STDC_MB_MIGHT_NEQ_WC__);
#else
	printf ("  __STDC_MB_MIGHT_NEQ_WC__ niezdefiniowane\n");
#endif
#ifdef __STDC_ANALYZABLE__
	printf ("  __STDC_ANALYZABLE__ = %d\n", __STDC_ANALYZABLE__);
#else
	printf ("  __STDC_ANALYZABLE__ niezdefiniowane\n");
#endif
#ifdef __STDC_IEC_559__
	printf ("  __STDC_IEC_559__ = %d\n", __STDC_IEC_559__);
#else
	printf ("  __STDC_IEC_559__ niezdefiniowane\n");
#endif
#ifdef __STDC_IEC_559_COMPLEX__
	printf ("  __STDC_IEC_559_COMPLEX__ = %d\n", __STDC_IEC_559_COMPLEX__);
#else
	printf ("  __STDC_IEC_559_COMPLEX__ niezdefiniowane\n");
#endif
#ifdef __STDC_IEC_60559_BFP__
	printf ("  __STDC_IEC_60559_BFP__ = %ld\n", __STDC_IEC_60559_BFP__);
#else
	printf ("  __STDC_IEC_60559_BFP__ niezdefiniowane\n");
#endif
#ifdef __STDC_IEC_60559_DFP__
	printf ("  __STDC_IEC_60559_DFP__ = %ld\n", __STDC_IEC_60559_DFP__);
#else
	printf ("  __STDC_IEC_60559_DFP__ niezdefiniowane\n");
#endif
#ifdef __STDC_IEC_60559_COMPLEX__
	printf ("  __STDC_IEC_60559_COMPLEX__ = %ld\n", __STDC_IEC_60559_COMPLEX__);
#else
		printf ("  __STDC_IEC_60559_COMPLEX__ niezdefiniowane\n");
#endif
#ifdef __STDC_IEC_60559_TYPES__
	printf ("  __STDC_IEC_60559_TYPES__ = %ld\n", __STDC_IEC_60559_TYPES__);
#else
		printf ("  __STDC_IEC_60559_TYPES__ niezdefiniowane\n");
#endif
#ifdef __STDC_LIB_EXT1__
	printf ("  __STDC_LIB_EXT1__ = %ld\n", __STDC_LIB_EXT1__);
#else
	printf ("  __STDC_LIB_EXT1__ niezdefiniowane\n");
#endif
#ifdef __STDC_NO_ATOMICS__
	printf ("  __STDC_NO_ATOMICS__ = %d\n", __STDC_NO_ATOMICS__);
#else
	printf ("  __STDC_NO_ATOMICS__ niezdefiniowane\n");
#endif
#ifdef __STDC_NO_COMPLEX__
	printf ("  __STDC_NO_COMPLEX__ = %d\n", __STDC_NO_COMPLEX__);
#else
	printf ("  __STDC_NO_COMPLEX__ niezdefiniowane\n");
#endif
#ifdef __STDC_NO_THREADS__
	printf ("  __STDC_NO_THREADS__ = %d\n", __STDC_NO_THREADS__);
#else
	printf ("  __STDC_NO_THREADS__ niezdefiniowane\n");
#endif
#ifdef __STDC_NO_VLA__
	printf ("  __STDC_NO_VLA__ = %d\n", __STDC_NO_VLA__);
#else
	printf ("  __STDC_NO_VLA__ niezdefiniowane\n");
#endif
}

int main (void)
{
	makra_wymagane();
	makra_opcjonalne();
}

/* eof. */

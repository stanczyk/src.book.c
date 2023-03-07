/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg14-04.c
 * @brief <complex.h>: poszczególne funkcje z <complex.h> w działaniu
 *
 * Szczegóły patrz:
 * - https://pl.wikipedia.org/wiki/Liczby_zespolone
 * - C23 Annex G. IEC 60559-compatible complex arithmetic
 */
#ifdef __STDC_NO_COMPLEX__
#error brak wsparcia dla liczb zespolonych
#endif

#include <math.h>
#include <stdio.h>
#include <complex.h>

char buf[15];
const char *value (double complex z)
{
	snprintf (buf, 15, "%5.2f %+5.2fi", creal (z), cimag (z));
	return buf;
}

int main (void)
{
	double complex z1 = CMPLX (2.0, -3.0);
	double complex z2 = CMPLX (1.0, sqrt (3));

	printf ("            z1 = %s\n",  value (z1));
	printf ("            z2 = %s\n",  value (z2));

	printf ("proste działania\n");
	printf ("       z1 + z2 = %s\n",  value (z1 + z2));
	printf ("       z1 - z2 = %s\n",  value (z1 - z2));
	printf ("       z1 * z2 = %s\n",  value (z1 * z2));
	printf ("       z1 / z2 = %s\n",  value (z1 / z2));

	printf ("funkcje podstawowe\n");
	printf ("    creal (z1) = %5.2f\n",       creal (z1));
	printf ("    cimag (z1) =       %5.2fi\n",cimag (z1));
	printf ("     cabs (z1) = %5.2f\n",        cabs (z1));
	printf ("     carg (z1) = %5.2f\n",        carg (z1));
	printf ("     conj (z1) = %s\n",  value (  conj (z1)));
	printf ("    cproj (z1) = %s\n",  value ( cproj (z1)));

	printf ("funkcje ekspotencjalne\n");
	printf ("     cexp (z1) = %s\n",  value (  cexp (z1)));
	printf ("     clog (z1) = %s\n",  value (  clog (z1)));

	printf ("potęgowanie i pierwiastkowanie\n");
	printf (" cpow (z1, z2) = %s\n",  value (  cpow (z1, z2)));
	printf ("    csqrt (z1) = %s\n",  value ( csqrt (z1)));

	printf ("funkcje trygonometryczne\n");
	printf ("     csin (z1) = %s\n",  value (  csin (z1)));
	printf ("     ccos (z1) = %s\n",  value (  ccos (z1)));
	printf ("     ctan (z1) = %s\n",  value (  ctan (z1)));
	printf ("    casin (z1) = %s\n",  value ( casin (z1)));
	printf ("    cacos (z1) = %s\n",  value ( cacos (z1)));
	printf ("    catan (z1) = %s\n",  value ( catan (z1)));

	printf ("funkcje hiperboliczne\n");
	printf ("    csinh (z1) = %s\n",  value ( csinh (z1)));
	printf ("    ccosh (z1) = %s\n",  value ( ccosh (z1)));
	printf ("    ctanh (z1) = %s\n",  value ( ctanh (z1)));
	printf ("   casinh (z1) = %s\n",  value (casinh (z1)));
	printf ("   cacosh (z1) = %s\n",  value (cacosh (z1)));
	printf ("   catanh (z1) = %s\n",  value (catanh (z1)));
}

/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg07-01.c
 * @brief Przykładowe stałe całkowitoliczbowe
 */
#include <stdio.h>

int main (void)
{
	// reprezentacja liczb
	printf ("reprezentacja dziesiętna, ósemkowa, szesnastkowa i binarna:\n");
	printf (" 32767    = %5i 0%o 0x%X 0b%016b\n",          32767,    32767,    32767,    32767);
	printf (" 32767U   = %5i 0%o 0x%X 0b%016b\n",          32767U,   32767U,   32767U,   32767U);
	printf ("    16L   = %5li    0%lo   0x%lX 0b%016lb\n",    16L,      16L,      16L,      16L);
	printf ("    27UL  = %5li    0%lo   0x%lX 0b%016lb\n",    27UL,     27UL,     27UL,     27UL);
	printf ("   511LL  = %5lli   0%llo  0x%llX 0b%016llb\n", 511LL,    511LL,    511LL,    511LL);
	printf ("  2730LLU = %5lli  0%llo  0x%llX 0b%016llb\n", 2730LLU,  2730LLU,  2730LLU,  2730LLU);
	printf (" 0B101010 = %5i    0%o   0x%X 0b%016b\n",     0B101010, 0B101010, 0B101010, 0B101010);

	// dozwolony zapis
	int i;
	i = 0xa+2;   // 0xa+2 = 10 + 2 = 12
	// i = 0xE+2;   // błąd: nieprawidłowy przyrostek "+2" dla stałej całkowitej
	i = 0xE +2;  // 0xE +2 = 14 + 2 = 16
	i = (0xE)+2; // (0xE)+2 = 16
	printf ("i = %d\n", i);
}

/* eof. */

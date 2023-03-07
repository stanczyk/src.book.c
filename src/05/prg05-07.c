/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-07.c
 * @brief Inicjowanie tablicy
 */
#include <stdio.h>

void drukuj_tablice (int tab[], int size)
{
	printf ("tab = ");
	for (int idx = 0; idx < size; idx++)
		printf ("%i ", tab[idx]);
	printf ("\n");
}

int main (void)
{
	int tab1[3] = { 0, 5, 1 }; 	// tab1[0] = 0, tab1[1] = 5, tab1[2] = 1
	int tab2[]  = { 0, 5, 1 }; 	// tab2[0] = 0, tab2[1] = 5, tab2[2] = 1
	int tab3[5] = { 2 }; 		// tab3 = { 2, 0, 0, 0, 0 }
	int tab4[5] = { [4] = 5, [0] = 1, 2, 3, 4 };
								// tab4 = { 1, 2, 3, 4, 5 }
	int tab5[2] = { 1, 2, 3 };  // tab5 = { 1, 2 }

	drukuj_tablice (tab1, sizeof (tab1) / sizeof (int));
	drukuj_tablice (tab2, sizeof (tab2) / sizeof (int));
	drukuj_tablice (tab3, sizeof (tab3) / sizeof (int));
	drukuj_tablice (tab4, sizeof (tab4) / sizeof (int));
	drukuj_tablice (tab5, sizeof (tab5) / sizeof (int));
}

/* eof. */

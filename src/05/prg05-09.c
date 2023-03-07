/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-09.c
 * @brief Inicjalizacja tablic wielowymiarowych
 */
#include <stdio.h>

void wyswietlTab(int wiersze, int kol, int tab[wiersze][kol]);
// lub:
// void wyswietlTab(int wiersze, int kol, int tab[*][*]);
// void wyswietlTab(int wiersze, int kol, int tab[][*]);
// void wyswietlTab(int wiersze, int kol, int tab[][kol]);

int main (void)
{
	int tab1[4][3] = { 	// tablica zbudowana z 4 tablic
						// a każda po 3 elementy typu int
						// czyli macierz 4x3
		{ 1 },			// tab1[0][] = { 1, 0, 0 }
		{ 0, 1 },		// tab1[1][] = { 0, 1, 0 }
		{ [2] = 1 },	// tab1[2][] = { 0, 0, 1 }
	};					// tab1[3][] = { 0, 0, 0 }

	int tab2[4][3] = { 1, 2, 3, 4, 5, 6, 7 };
						// tab2[0][] = { 1, 2, 3 }
						// tab2[1][] = { 4, 5, 6 }
						// tab2[2][] = { 7, 0, 0 }
						// tab2[3][] = { 0, 0, 0 }

	int tab3[4][3] = { [0][0] = 1, [1][1] = 1, [2][0] = 1 };
						// tab3[0][] = { 1, 0, 0 }
						// tab3[1][] = { 0, 1, 0 }
						// tab3[2][] = { 1, 0, 0 }
						// tab3[3][] = { 0, 0, 0 }

	wyswietlTab(4, 3, tab1);
	wyswietlTab(4, 3, tab2);
	wyswietlTab(4, 3, tab3);
}

void wyswietlTab(int wiersze, int kol, int tab[wiersze][kol])
{
	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kol; j++)
			printf("[%d][%d] = %d  ", i, j, tab[i][j]);
		printf("\n");
	}
	printf("\n");
}

/* eof. */

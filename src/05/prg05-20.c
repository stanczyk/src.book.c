/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-20.c
 * @brief Wskaźnik do tablicy, tablica jako wskaźnik i wskaźnik jako tablica
 */
#include <stdio.h>
#include <stddef.h>

int main (void)
{
	int tab[] = { 20, 15, 10 };
	int *wtab;

	wtab = &tab[0];  // wtab wskazuje na tab[0]
	wtab = tab;      // zapis równoważny

	// wskaźnik do tablicy
	printf ("%d\n", *wtab);
	printf ("%d\n", *(wtab + 1));
	// tablica jako wskaźnik
	printf ("%d\n", *tab);
	printf ("%d\n", *(tab + 1));
	// wskaźnik jako tablica
	printf ("%d\n", *wtab);
	printf ("%d\n", wtab[1]);

	wtab = tab + 2;              // wtab wskazuje na tab[2]
	ptrdiff_t n = wtab - tab;    // n = 2
	printf ("różnica wynosi: %td\n", n);

	// użycie operatorów -- i += dla wskaźników
	int tmp1 = *(wtab--);
	int tmp2 = *(wtab--);
	printf("%i, %i\n", tmp1, tmp2);
	wtab += 2;
	printf("%i\n", *wtab);

	// poprawna jest również (dziwna) notacja:
	printf("%d\n", 1[tab]);  // równoważne tab[1]
	printf("%d\n", tab[1]);
}

/* eof. */

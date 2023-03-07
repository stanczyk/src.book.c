/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-23.c
 * @brief Deklaracja typu strukturalnego struct artykul
 */
#include <stdio.h>
#include <stddef.h>

struct artykul
{
	int ilosc;
	char nazwa[40];
	double cena;
};

int main (void)
{
	struct artykul art, *wskArt, tabArt[100];
	struct artykul art1 = { 1, "krokus", 2.49 },
				   art2 = { 2 },
				   art3 = { .cena=3.99 };
	tabArt[0] = art1;

	// rozmiar struktury i rozmieszczenie pól wewnątrz
	printf ("rozmiar struktury: %zu bajtów\n", sizeof(art));
	printf ("  offset pola nazwa: %zu bajtów\n", offsetof(struct artykul, nazwa));
	printf ("  offset pola ilosc: %zu bajtów\n", offsetof(struct artykul, ilosc));
	printf ("  offset pola  cena: %zu bajtów\n", offsetof(struct artykul, cena));

	// dostęp do poszczególnych zmiennych i składowych struktury
	printf ("nazwa: %s, cena: %.2f, ilość: %i\n", art1.nazwa, art1.cena, art1.ilosc);
	printf ("nazwa: %s, cena: %.2f, ilość: %i\n", art2.nazwa, art2.cena, art2.ilosc);
	printf ("nazwa: %s, cena: %.2f, ilość: %i\n", art3.nazwa, art3.cena, art3.ilosc);

	// dostęp do składowych dla wskaźnika
	wskArt = &tabArt[0];
	printf ("nazwa: %s, cena: %.2f\n", wskArt->nazwa, wskArt->cena);
	// co jest równoważne
	printf ("nazwa: %s, cena: %.2f\n", (*wskArt).nazwa, (*wskArt).cena);

	// inicjalizacja ciąg dalszy
	struct artykul art4 = { 0 };  // wszystkie składowe wyzerowane
	printf ("nazwa: %s, cena: %.2f, ilość: %i\n", art4.nazwa, art4.cena, art4.ilosc);
	struct artykul art5 = {};    // błąd: inicjalizacja nie może być pusta
	printf ("nazwa: %s, cena: %.2f, ilość: %i\n", art5.nazwa, art5.cena, art5.ilosc);

	// inny przykład inicjalizacji struktury
	struct {int rok, miesiac, dzien, godzina, minuta; }
		data0 = { 2020, 01, 21, 1, 0 },                // data0 = { 2020, 01, 21,  1,  0 }
		data1 = { .dzien=1, .miesiac=12, .rok=2021 },  // data1 = { 2021, 12,  1,  0,  0 }
		data2 = { .rok=2022, 1, 22, .godzina=17, 33 }; // data2 = { 2022,  1, 22, 17, 33 }

	printf (" data: %4i-%02i-%02i %02i:%02i\n", data0.rok, data0.miesiac, data0.dzien, data0.godzina, data0.minuta);
	printf (" data: %4i-%02i-%02i %02i:%02i\n", data1.rok, data1.miesiac, data1.dzien, data1.godzina, data1.minuta);
	printf ("data1: %4i-%02i-%02i %02i:%02i\n", data2.rok, data2.miesiac, data2.dzien, data2.godzina, data2.minuta);
}

/* eof. */

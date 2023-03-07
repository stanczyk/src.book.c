/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg22-04.c
 * @brief <locale.h>: odczyt szczegółów dot. symboli waluty dla pl_PL.UTF-8
 */
#include <stdio.h>
#include <locale.h>

int main (void)
{
	setlocale (LC_ALL, "pl_PL.UTF-8");
	struct lconv *lc = localeconv ();

	// Informacje dla wartości innych niż waluty:
	printf ("decimal_point: %s\n", lc->decimal_point);             // znak dziesiętny
	printf ("thousands_sep: \'%s\'\n", lc->thousands_sep);         // znak używany do grupowania cyfr po lewej stronie przecinka
	printf ("grouping: \'%d\'\n", lc->grouping[0]);                // liczba cyfr w każdej grupie

	// Informacje dot. waluty:
	// parametry formatowania liczb
	printf ("mon_decimal_point: %s\n", lc->mon_decimal_point);     // znak kropki dziesiętnej w łańcuchach walut
	printf ("mon_thousands_sep: \'%s\'\n", lc->mon_thousands_sep); // znak używany do grupowania cyfr po lewej stronie przecinka dziesiętnego
	printf ("mon_grouping: \'%d\'\n", lc->mon_grouping[0]);        // liczba cyfr w każdej grupie
	printf ("positive_sign: \'%s\'\n", lc->positive_sign);         // znak dla dodatnich ciągów walutowych
	printf ("negative_sign: \'%s\'\n", lc->negative_sign);         // znak ujemnych ciągów walutowych

	// lokalne parametry formatowania
	printf ("currency_symbol: %s\n", lc->currency_symbol);         // regionalny symbol waluty
	printf ("frac_digits: %d\n", lc->frac_digits);                 // liczba cyfr po przecinku w formacie lokalnym
	printf ("p_cs_precedes: %d\n", lc->p_cs_precedes);             // dla wartości nieujemnych: 1 = symbol waluty jest przed, 0 = po kwocie
	printf ("n_cs_precedes: %d\n", lc->n_cs_precedes);             // dla wartości ujemnych: 1 = symbol waluty jest przed, 0 = po kwocie
	printf ("p_sep_by_space: %d\n", lc->p_sep_by_space);           // dla wartości ujemnych: 1 = spacja, 0 = brak spacji, między symbolem waluty i kwota
	printf ("n_sep_by_space: %d\n", lc->n_sep_by_space);           // dla wartości ujemnych: 1 = spacja, 0 = brak spacji, między symbolem waluty i kwota
	printf ("p_sign_posn: %d\n", lc->p_sign_posn);                 // pozycja znaku dodatniego
	printf ("n_sign_posn: %d\n", lc->n_sign_posn);                 // pozycja znaku ujemnego

	// międzynarodowe parametry formatowania
	printf ("int_curr_symbol: \'%s\'\n", lc->int_curr_symbol);     // trzyliterowy symbol waluty lokalnej zgodnie z normą ISO 4217 ze znakiem separatora
	printf ("int_frac_digits: %d\n", lc->int_frac_digits);         // liczba cyfr po przecinku w formacie międzynarodowym
	printf ("int_p_cs_precedes: %d\n", lc->int_p_cs_precedes);     // jak p_cs_precedes dla ustawień międzynarodowych
	printf ("int_n_cs_precedes: %d\n", lc->int_n_cs_precedes);     // jak n_cs_precedes dla ustawień międzynarodowych
	printf ("int_p_sep_by_space: %d\n", lc->int_p_sep_by_space);   // jak p_sep_by_space dla ustawień międzynarodowych
	printf ("int_n_sep_by_space: %d\n", lc->int_n_sep_by_space);   // jak n_sep_by_space dla ustawień międzynarodowych
	printf ("int_p_sign_posn: %d\n", lc->int_p_sign_posn);         // pozycja znaku dodatniego dla wartości sformatowanych międzynarodowo
	printf ("int_n_sign_posn: %d\n", lc->int_n_sign_posn);         // pozycja znaku ujemnego dla wartości sformatowanych międzynarodowo
}

/* eof. */

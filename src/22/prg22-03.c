/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg22-03.c
 * @brief <locale.h>: odczyt szczegółów dot. symboli waluty dla tr_TR.UTF-8
 */
#include <locale.h>
#include <stdio.h>

int main (void)
{
	setlocale(LC_ALL, "tr_TR.UTF-8");
	struct lconv *lc = localeconv();
	printf("Symbol waluty tureckiej ( %s): %s\n", lc->int_curr_symbol, lc->currency_symbol);
}

/* eof. */

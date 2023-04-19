/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-16.c
 * @brief Kwalifikator restrict i tablice
 */

int main (void)
{
	typedef int * tab_wski[10];

	restrict tab_wski wski;	// typem wski jest int * restrict[10]
	void *wsk = &wski;		// do C23 OK; w C23 operacja nielegalna
							// (gcc generuje ostrzeżenie)
}

/* eof. */

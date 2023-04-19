/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg11-07.c
 * @brief Dyrektywa #embed z parametrem if-empty
 */
int main (void)
{
	return
#embed "dane.dat" limit(0) if_empty(123)
	;
}
/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-06.c
 * @brief Specyfikator register
 *
 * @warning
 * Niepoprawnego użycie zmiennej register, błąd kompilacji
 */

int main (void)
{
	register int i = 1;
	int *wsk = &i;  // błąd kompilacji: nie można uzyskać adresu zmiennej register
}

/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-14.c
 * @brief Kwalifikator const
 *
 * Wskaźnik, którego nie można przestawić na inny adres
 */
int main (void)
{
	int zmienna1 = 1, zmienna2 = 2;
	int *const wsk = &zmienna1;

	*wsk = 5;			// instrukcja poprawna
	wsk = &zmienna2;	// niedopuszczalne, błąd kompilacji
}

/* eof. */

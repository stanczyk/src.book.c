/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg08-02.c
 * @brief Przykłady l-wartości i nie-l-wartości (czyli r-wartości)
 */

int main (void)
{
	int i; 	// deklaracja zmiennej

	i = 1; 			// wyrażenie odnoszące się do obiektu typu int jako l-wartości
	int i2 = i; 	// l-wartość może pojawić się także po prawej stronie
	/*
	9 = i; 			// Błąd: próbuje się zmienić wartość z lewej strony
					// 		 niebędącą l-wartością
	i + 1 = i2; 	// Błąd: wyrażenie "i + 1" nie jest l-wartością
	*/

	int *wsk, *wsk1; 	// deklaracja wskaźnika wsk i wsk1

	*wsk = 1; 		// prawidłowe przypisanie l-wartości
	/*
	wsk + 2 = 9; 	// Błąd: nieprawidłowe przypisanie,
					// 		 "wsk + 2" nie jest l-wartością
	*/
	*(wsk + 1) = 9; // prawidłowe przypisanie, "*(wsk + 2)" jest l-wartością
}

/* eof. */

/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-13.c
 * @brief Kwalifikator const
 *
 * Wskaźnik, który nie możne zmienić wskazywanej wartości
 */

int main (void)
{
	int zmienna1 = 1, zmienna2 = 2, *wsk;
	const int constTab[2] = { 3, 4 };
	const int *wskDoConst;	  // wskaźnik "tylko do odczytu"

	// operacje dozwolone:
	wskDoConst = &constTab[0];
	++wskDoConst;			  // zmiana wartość zmiennej wskaźnikowej
	wskDoConst = &zmienna1;
	zmienna2 = *wskDoConst;	  // dostęp do danej „tylko do odczytu”
	wsk = (int *) wskDoConst; // const int* może być rzutowany do int*

	// operacje niedozwolone:
	wsk = wskDoConst;		  // wskaźnik „tylko do odczytu” nie może
							  // zostać skopiowany „do odczytu i zapisu”
							  // (w gcc pojawia się tylko ostrzeżenie)
	*wskDoConst = 5;		  // niedozwolony dostęp "do zapisu"
}

/* eof. */
